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
#include <QDateTime>

class WeatherData
{

public:
    WeatherData();

    void setDT(QDateTime dt);
    QDateTime dt() const;

	QDateTime localDateTime() const;

    void setTemperature(float temp);
    float temperature() const;

    void setMinTemperature(float minTemp);
    float minTemperature() const;

    void setMaxTemperature(float maxTemp);
    float maxTemperature() const;

    void setPrecipitation(float precipitation);
    float precipitation() const;

    void setWindSpeed(float windSpeed);
    float windSpeed() const;

    QString windDirectionName() const;
	void setWindDirectionName(const QString &windDirectionName);

    float windDirection() const;
    void setWindDirection(float windDirection);

    float humidity() const;
    void setHumidity(float humidity);

    float pressure() const;
    void setPressure(float pressure);

    float cloudiness() const;
    void setCloudiness(float cloudiness);

    float fog() const;
    void setFog(float fog);

    float dewPointTemp() const;
    void setDewPointTemp(float dewPointTemp);

    void setWeatherStatus(QString status);
    QString weatherStatus();

    void setWeatherSymbol(int symbol);
    int weatherSymbol() const;

    void setRange(int range);
    int range() const;

    void mergeHour(WeatherData &other);
    void mergeDay(WeatherData &other);

private:
    QDateTime m_datetime;
    float m_temp;
    float m_minTemp;
    float m_maxTemp;    
    float m_precipitation;
    float m_windDirection;
    QString m_windDirectionName;
    float m_windSpeed;
    float m_humidity;
    float m_pressure;
    float m_cloudiness;
    float m_fog;
    float m_dewPointTemp;
    QString m_weatherStatus;
    int m_weatherSymbol;
    int m_range;
};
