/*
    *
    * This file is a part of CoreAction.
    * A side bar for showing widgets for C Suite.
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
    * along with this program; if not, vsit http://www.gnu.org/licenses/.
    *
*/

#include <QFile>
#include <QDir>
#include <QRegularExpression>
#include <QDebug>
#include <QDateTime>

#include "astroinfo.h"

const QString astroInfo::DateFormat = "yyyy-MM-dd";

astroInfo::astroInfo(const QString &filepath, QObject *parent) :
    QObject(parent),
    m_filepath(filepath)
{
}

QString astroInfo::sunrise()
{
    return m_sunrise;
}

QString astroInfo::sunset()
{
    return m_sunset;
}

QString astroInfo::moonrise()
{
    return m_moonrise;
}

QString astroInfo::moonset()
{
    return m_moonset;
}

void astroInfo::initializeParse()
{
    QFile file(m_filepath);
	if (file.open(QIODevice::ReadOnly)) {
		QXmlStreamReader reader(&file);
		parseData(reader);
		file.close();
	} else {
		qWarning() << "Can not open astro file '" << m_filepath.replace(QRegularExpression("^(" + QDir::homePath() + ")"), "~") << "' for parsing";
	}
}

void astroInfo::parseData(QXmlStreamReader &reader)
{
    QDateTime currdt = QDateTime::currentDateTime();

    while (!reader.atEnd()) {
        if (reader.tokenType() == QXmlStreamReader::StartElement) {
            if (reader.name() == "astrodata" || reader.name() == "location") {
                reader.readNext();
                continue;
            }

			if (reader.name() == "time" && reader.attributes().value("date") == currdt.toString(DateFormat)) {
                while (!reader.atEnd()) {
                    if (reader.tokenType() == QXmlStreamReader::StartElement) {
                        if (reader.name() == "sunrise") {
                            m_sunrise = reader.attributes().value("time").toString();
                            changeTimeFormat(m_sunrise);
                        } else if (reader.name() == "moonrise") {
                            m_moonrise = reader.attributes().value("time").toString();
                            changeTimeFormat(m_moonrise);
                        } else if (reader.name() == "sunset") {
                            m_sunset = reader.attributes().value("time").toString();
                            changeTimeFormat(m_sunset);
                        } else if (reader.name() == "moonset") {
                            m_moonset = reader.attributes().value("time").toString();
                            changeTimeFormat(m_moonset);
                        }
                    }

                    reader.readNext();
                }
            }

            reader.skipCurrentElement();
        } else {
            reader.readNext();
        }
    }
}

void astroInfo::changeTimeFormat(QString &time)
{
    if (time.count() == 25) {// yyyy-MM-ddThh:mm:ss+hh:mm
        time = time.mid(11, 8);
        time = QTime::fromString(time, "hh:mm:ss").toString("hh:mm AP");
    }
}
