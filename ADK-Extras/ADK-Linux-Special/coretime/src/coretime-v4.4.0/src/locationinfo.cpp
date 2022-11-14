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
#include <QDebug>
#include <QRegularExpression>
#include <QDir>
#include "locationinfo.h"

locationInfo::locationInfo(const QString &filepath, QObject *parent) :
    QObject(parent),
    m_filepath(filepath)
{
}

Locations locationInfo::locations()
{
    return m_locations;
}

void locationInfo::initializeParse()
{
    QFile file(m_filepath);
	if (file.open(QIODevice::ReadOnly)) {
		QXmlStreamReader reader(&file);
		parseData(reader);
		file.close();
		file.remove();
	} else {
		qWarning() << "Can not open '" << m_filepath.replace(QRegularExpression("^(" + QDir::homePath() + ")"), "~") << "' for parsing...";
	}
}

void locationInfo::parseData(QXmlStreamReader &reader)
{
    m_locations.clear();

    while (!reader.atEnd()) {
        if (reader.tokenType() == QXmlStreamReader::StartElement) {
            if (reader.name() == "searchresults") {
                reader.readNext();
                continue;
            }

            if (reader.name() == "place") {
                LocationData ld;
                ld.setLatitude(reader.attributes().value("lat").toFloat());
                ld.setLongitude(reader.attributes().value("lon").toFloat());
                ld.setLocationName(reader.attributes().value("display_name").toString());
                ld.setLocationClass(reader.attributes().value("class").toString());
                m_locations.push_back(ld);
            }

            reader.skipCurrentElement();
        } else {
            reader.readNext();
        }
    }
}

void LocationData::setLocationName(const QString &locName)
{
    m_locName = locName;
}

void LocationData::setLocationClass(const QString &locClass)
{
    m_locClass = locClass;
}

void LocationData::setLatitude(float lat)
{
    m_lat = QString::number(lat);
}

void LocationData::setLongitude(float lon)
{
    m_lon = QString::number(lon);
}

QString LocationData::locationName()
{
    return m_locName;
}

QString LocationData::locationClass()
{
    return m_locClass;
}

QString LocationData::latitude()
{
    return m_lat;
}

QString LocationData::longitude()
{
    return m_lon;
}
