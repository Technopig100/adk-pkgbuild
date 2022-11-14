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

#include <QCommandLineParser>

#include <cprime/capplication.h>

#include "coretime.h"


int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

	CPrime::CApplication app( "CoreTime", argc, argv );
	if ( app.isRunning() )
        return not app.sendMessage("App is already running. Using existing Instance.");


    // Set application info
	app.setOrganizationName("CuboCore");
	app.setApplicationName("CoreTime");
	app.setApplicationVersion(QStringLiteral(VERSION_TEXT));
	app.setDesktopFileName("org.cubocore.CoreTime.desktop");
	app.setQuitOnLastWindowClosed(false);

    QCommandLineParser parser;
    parser.addHelpOption();         // Help
    parser.addVersionOption();      // Version

    /* Optional: Path where the search begins */
    parser.addOption({ "tray", "Start the instance in system tray", "" });

    /* Process the CLI args */
	parser.process(app);

	coretime gui;

	QObject::connect(&app, &CPrime::CApplication::messageReceived, [&]() {
		gui.show();
		gui.activateWindow();
    });

    if (not parser.isSet("tray")) {
		gui.show();
    }

	return app.exec();
}
