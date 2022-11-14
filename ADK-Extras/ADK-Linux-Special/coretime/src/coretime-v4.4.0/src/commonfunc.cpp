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

#include <QDir>
#include <QDateTime>
#include "commonfunc.h"

WeekDay commonFunc::intToWeekday(int num)
{
    return static_cast<WeekDay>(num);
}

QString commonFunc::defaultAudio()
{
	QString defaultAudioPath = QDir(QString(AUDIO_RESOURCE_FOLDER)).filePath("sound.ogg");
	if (defaultAudioPath.count()) {
        //QFile::copy(":/resource/sound.ogg", defaultAudioPath);
        return defaultAudioPath;
    }

    return QString();
}

QString commonFunc::createID()
{
    int id = static_cast<int>(QDateTime::currentMSecsSinceEpoch() / 1000);
    return QString::number(id);
}

QString commonFunc::weekdaysToString(QMap<WeekDay, bool> weekdays)
{
    QString str = "";
    bool all = true;
    QMap<WeekDay, QString> allDays = { { Monday, "Mon" },
                                       { Tuesday, "Tue" },
                                       { Wednesday, "Wed" },
                                       { Thursday, "Thu" },
                                       { Friday, "Fri" },
                                       { Saturday, "Sat" },
                                       { Sunday, "Sun" } };

    for (int i = 0; i < 7; i++) {
        WeekDay d = allDays.keys().at(i);
        if (weekdays.value(d)) {
            str.append(allDays.value(d) + " ");
        } else {
            all = false;
        }
    }

    if (all) {
        return "Every Day";
    }

    return str;
}

