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

#pragma once

#include <QObject>
#include <QXmlStreamReader>

class LocationData;

typedef QVector<LocationData> Locations;

class LocationData
{
public:
	void setLocationName(const QString &locName);
	void setLocationClass(const QString &locClass);
    void setLatitude(float lat);
    void setLongitude(float lon);

    QString locationName();
    QString locationClass();
    QString latitude();
    QString longitude();

private:
    QString m_locName;
    QString m_locClass;
    QString m_lat;
    QString m_lon;
};

class locationInfo : public QObject
{
    Q_OBJECT
public:
	explicit locationInfo(const QString &filepath, QObject *parent = nullptr);

    Locations locations();
    void initializeParse();

signals:

private:
    QString m_filepath;
    Locations m_locations;

    void parseData(QXmlStreamReader &);
};
