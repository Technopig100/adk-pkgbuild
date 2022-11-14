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
#include <QNetworkAccessManager>

class QNetworkReply;

class apiRequest : public QObject
{
    Q_OBJECT

public:
    enum Reason {
        AstroData,
        WeatherData,
        LocationData
    };

	explicit apiRequest(QObject *parent = nullptr);
	~apiRequest();

    bool requestData(QString url, QString filepath, Reason r);

signals:
    void fileDownloaded(Reason r);

private:
	QNetworkAccessManager *nam;
	int m_reties;
};
