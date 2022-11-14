/*
    *
    * This file is a part of CoreTime.
    * A time related task manager for C Suite
    * Copyright 2019 CuboCore Group
    *

    *
    * This program is free software; you can redistribute it and/or modify
    * it under the terms of the GNU General Public License as published by
    * the Free Software Foundation; either version 3 of the License, or
    * (at your option) any later version.
    *

    *
    * This program is distributed in the hope that it will be useful,
    * but WITHOUT ANY WARRANTY; without even the implied warranty of
    * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    * GNU General Public License for more details.
    *

    *
    * You should have received a copy of the GNU General Public License
    * along with this program; if not, write to the Free Software
    * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
    * MA 02110-1301, USA.
    *
*/


#include <QFileInfo>
#include <QDir>
#include <QStandardPaths>
#include <QFontDatabase>

#include <cprime/variables.h>
#include <cprime/themefunc.h>
#include <cprime/filefunc.h>

#include <sys/types.h> // getpwuid()
#include <pwd.h>       // getpwuid()
#include <unistd.h>    // getuid()

#include "settings.h"

settings::settings()
{
    defaultSett = QDir(CPrime::Variables::CC_System_ConfigDir()).filePath("coreapps/coreapps.conf");

    // set some default settings that are user specific
    if (!CPrime::FileUtils::exists(defaultSett)) {
        cSetting = new QSettings("coreapps", "coreapps");
        qDebug() << "Settings file " << cSetting->fileName();

        CPrime::FileUtils::setupFolder(CPrime::FolderSetup::ConfigFolder);

        setDefaultSettings();
    } else {
        cSetting = new QSettings(defaultSett, QSettings::NativeFormat);
    }
}

settings::~settings()
{
    delete cSetting;
}

// As default settings not exist we should contain to set value for default
void settings::setDefaultSettings()
{
    // C Suite
    cSetting->setValue("CoreApps/KeepActivities", true);
    cSetting->setValue("CoreApps/EnableExperimental", false);
    cSetting->setValue("CoreApps/AutoDetect", true);

    if (autoUIMode() == 2) {
        cSetting->setValue("CoreApps/IconViewIconSize", QSize(56, 56));
        cSetting->setValue("CoreApps/ListViewIconSize", QSize(48, 48));
        cSetting->setValue("CoreApps/ToolsIconSize", QSize(48, 48));
        cSetting->setValue("CoreKeyboard/Type", true);
    } else {
        cSetting->setValue("CoreApps/IconViewIconSize", QSize(48, 48));
        cSetting->setValue("CoreApps/ListViewIconSize", QSize(32, 32));
        cSetting->setValue("CoreApps/ToolsIconSize", QSize(24, 24));
        cSetting->setValue("CoreKeyboard/Type", false);
    }


    // Add system font to CorePad, CoreTerminal
    QFont monoFont = QFontDatabase::systemFont(QFontDatabase::FixedFont);

    if ( not monoFont.family().count() )
        monoFont = QFont("monospace", 9);

    if (monoFont.styleHint() != QFont::Monospace) {
        monoFont = QFont("monospace", 9);
    }


	// CoreAction
	cSetting->setValue("CoreAction/PluginsFolders", {"/usr/lib/coreapps/plugins"});
	cSetting->setValue("CoreAction/SelectedPlugins",
					   QStringList() << "/usr/lib/coreapps/plugins/libbacklight.so"
									 << "/usr/lib/coreapps/plugins/libcalendar.so"
									 << "/usr/lib/coreapps/plugins/libnetwork.so"
									 << "/usr/lib/coreapps/plugins/libsystem.so");

    // CorePad
    cSetting->setValue("CorePad/Font", monoFont);


    // CoreFM
    cSetting->setValue("CoreFM/ViewMode", 1);
    cSetting->setValue("CoreFM/ShowHidden", false);
    cSetting->setValue("CoreFM/ShowThumb", true);


    // CoreKeyboard
    cSetting->setValue("CoreKeyboard/Mode", true);
    cSetting->setValue("CoreKeyboard/AutoSuggest", false);
    cSetting->setValue("CoreKeyboard/DaemonMode", false);
    cSetting->setValue("CoreKeyboard/KeymapNumber", 1);


    // CoreTerminall
    struct passwd *pwent;
    pwent = getpwuid(getuid());
    cSetting->setValue("CoreTerminal/Shell", pwent->pw_shell);
    cSetting->setValue("CoreTerminal/Font", monoFont);
    cSetting->setValue("CoreTerminal/Opacity", 100);
    cSetting->setValue("CoreTerminal/HistorySize", 500);
    cSetting->setValue("CoreTerminal/KeyTab", "default");
    cSetting->setValue("CoreTerminal/CursorShape", 0);
    cSetting->setValue("CoreTerminal/ColorScheme", "WhiteOnBlack");
    cSetting->setValue("CoreTerminal/TERM", "xterm-256color");
    cSetting->setValue("CoreTerminal/Rows", 30);
    cSetting->setValue("CoreTerminal/Columns", 120);


    // CorePDF
    cSetting->setValue("CorePDF/ZoomMode", 1);
    cSetting->setValue("CorePDF/PageMode", 0);


    // CoreShot
    cSetting->setValue("CoreShot/AfterShootTaken", 2);
    if (!cSetting->value("CoreShot/SaveLocation").toString().count()) {
        QDir().mkpath(QStandardPaths::writableLocation(QStandardPaths::PicturesLocation) + "/Screen Shots");
        cSetting->setValue("CoreShot/SaveLocation", QStandardPaths::writableLocation(QStandardPaths::PicturesLocation) + "/Screen Shots");
    }


    // CoreStuff
    QString s = "/usr/share/coreapps/background/default.svg";
    cSetting->setValue("CoreStuff/Background", s);
    cSetting->setValue("CoreStuff/WallpaperPositon", 1);


    cSetting->sync();
}

int settings::autoUIMode() const
{
    if (CPrime::ThemeFunc::getFormFactor() == CPrime::FormFactor::Mobile) {
        return 2; // Mobile
    } else if (CPrime::ThemeFunc::getFormFactor() == CPrime::FormFactor::Tablet &&  CPrime::ThemeFunc::getTouchMode() == true) {
        return 1; // Tablet
    } else {
        return 0; // Desktop
    }
}

settings::cProxy settings::getValue(const QString &appName, const QString &key,
                                    const QVariant &defaultValue)
{
    if (appName == "CoreApps" && key == "UIMode") { // Wants to get CoreApps/UIMode
        // Check whether CoreApps/AutoDetect is On
        bool isAutoDetect = cSetting->value("CoreApps/AutoDetect").toBool();

        if (isAutoDetect)
            return cProxy { cSetting, "Dummy", autoUIMode() };
    }

    return cProxy{ cSetting, appName + "/" + key, defaultValue };
}

void settings::setValue(const QString &appName, const QString &key, QVariant value)
{
    cSetting->setValue(appName + "/" + key, value);
}

QString settings::defaultSettingsFilePath() const
{
    return cSetting->fileName();
}
