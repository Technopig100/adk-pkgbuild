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

#include "weatherdata.h"

const float FLOAT_LOW = std::numeric_limits<float>::lowest();
const float FLOAT_MAX = std::numeric_limits<float>::max();

WeatherData::WeatherData() :
    m_temp(FLOAT_LOW),
    m_minTemp(FLOAT_MAX),
    m_maxTemp(FLOAT_LOW),
    m_precipitation(FLOAT_LOW),
	m_windDirection(0),
    m_windDirectionName(""),
    m_windSpeed(FLOAT_LOW),
    m_humidity(FLOAT_LOW),
    m_pressure(FLOAT_LOW),
	m_cloudiness(0),
	m_fog(0),
    m_dewPointTemp(FLOAT_LOW),
    m_weatherSymbol(0),
    m_range(0)
{
}

void WeatherData::setDT(QDateTime dt)
{
    m_datetime = dt;
}

QDateTime WeatherData::dt() const
{
	return m_datetime;
}

QDateTime WeatherData::localDateTime() const
{
	return m_datetime.toLocalTime();
}

void WeatherData::setTemperature(float temp)
{
    m_temp = temp;
}

float WeatherData::temperature() const
{
    return m_temp;
}

void WeatherData::setMinTemperature(float minTemp)
{
    m_minTemp = minTemp;
}

float WeatherData::minTemperature() const
{
    return m_minTemp;
}

void WeatherData::setMaxTemperature(float maxTemp)
{
    m_maxTemp = maxTemp;
}

float WeatherData::maxTemperature() const
{
    return m_maxTemp;
}

void WeatherData::setPrecipitation(float precipitation)
{
    m_precipitation = precipitation;
}

float WeatherData::precipitation() const
{
    return m_precipitation;
}

void WeatherData::setWindSpeed(float windSpeed)
{
    m_windSpeed = windSpeed;
}

float WeatherData::windSpeed() const
{
    return m_windSpeed;
}

void WeatherData::setWeatherSymbol(int symbol)
{
    m_weatherSymbol = symbol;
}

int WeatherData::weatherSymbol() const
{
    return m_weatherSymbol;
}

void WeatherData::setRange(int range)
{
    m_range = range;
}

int WeatherData::range() const
{
    return m_range;
}

QString WeatherData::windDirectionName() const
{
    return m_windDirectionName;
}

void WeatherData::setWindDirectionName(const QString &windDirectionName)
{
    m_windDirectionName = windDirectionName;
}

float WeatherData::windDirection() const
{
    return m_windDirection;
}

float WeatherData::humidity() const
{
    return m_humidity;
}

void WeatherData::setHumidity(float humidity)
{
    m_humidity = humidity;
}

float WeatherData::pressure() const
{
    return m_pressure;
}

void WeatherData::setPressure(float pressure)
{
    m_pressure = pressure;
}

float WeatherData::cloudiness() const
{
    return m_cloudiness;
}

void WeatherData::setCloudiness(float cloudiness)
{
    m_cloudiness = cloudiness;
}

float WeatherData::fog() const
{
    return m_fog;
}

void WeatherData::setFog(float fog)
{
    m_fog = fog;
}

float WeatherData::dewPointTemp() const
{
    return m_dewPointTemp;
}

void WeatherData::setDewPointTemp(float dewPointTemp)
{
    m_dewPointTemp = dewPointTemp;
}

void WeatherData::setWeatherStatus(QString status)
{
    if (status == "Sun") {
        status = "ClearSky";
    }
    m_weatherStatus = status;
}

QString WeatherData::weatherStatus()
{
    return m_weatherStatus;
}

void WeatherData::setWindDirection(float windDirection)
{
    m_windDirection = windDirection;
}

void WeatherData::mergeDay(WeatherData &other)
{
    m_minTemp = std::min(other.minTemperature(), m_minTemp);
    m_maxTemp = std::max(other.maxTemperature(), m_maxTemp);

    if (m_weatherSymbol == 0 || other.range() < m_range) {
        setWeatherSymbol(other.weatherSymbol());
    }

    if (m_weatherStatus == "" || other.range() <= m_range) {
        if (other.weatherStatus().count()) {
            m_weatherStatus = other.weatherStatus();
        }
    }
}

void WeatherData::mergeHour(WeatherData &other)
{
    if (m_temp == FLOAT_LOW || other.range() <= m_range) {
        m_temp = std::max(other.temperature(), m_temp);
    }

    if (m_minTemp == FLOAT_MAX || other.range() <= m_range) {
        m_minTemp = std::min(other.minTemperature(), m_minTemp);
    }

    if (m_maxTemp == FLOAT_LOW || other.range() <= m_range) {
        m_maxTemp = std::max(other.maxTemperature(), m_maxTemp);
    }

    if (m_precipitation < 0.0f || other.range() <= m_range) {
        m_precipitation = std::max(other.precipitation(), m_precipitation);
    }

    if (m_windDirection < 0.0f || other.range() <= m_range) {
        m_windDirection = std::max(other.windDirection(), m_windDirection);
    }

    if (m_windSpeed < 0.0f || other.range() <= m_range) {
        m_windSpeed = std::max(other.windSpeed(), m_windSpeed);
    }

    if (m_humidity < 0.0f || other.range() <= m_range) {
        m_humidity = std::max(other.humidity(), m_humidity);
    }

    if (m_pressure < 0.0f || other.range() <= m_range) {
        m_pressure = std::max(other.pressure(), m_pressure);
    }

    if (m_cloudiness < 0.0f || other.range() <= m_range) {
        m_cloudiness = std::max(other.cloudiness(), m_cloudiness);
    }

    if (m_fog < 0.0f || other.range() <= m_range) {
        m_fog = std::max(other.fog(), m_fog);
    }

    if (m_dewPointTemp == FLOAT_LOW || other.range() <= m_range) {
        m_dewPointTemp = std::max(other.dewPointTemp(), m_dewPointTemp);
    }

    if (m_weatherSymbol == 0 || other.range() < m_range) {
        setWeatherSymbol(other.weatherSymbol());
    }

    if (m_windDirectionName == "" || other.range() <= m_range) {
        if (other.windDirectionName().count())
            m_windDirectionName = other.windDirectionName();
    }

    if (m_weatherStatus == "" || other.range() <= m_range) {
        if (other.weatherStatus().count()) {
            m_weatherStatus = other.weatherStatus();
        }
    }
}
