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

#include "weathericon.h"

/******************************************************************
 * From https://api.met.no/weatherapi/weathericon/1.1/documentation
 ******************************************************************
    1 Sun
    2 LightCloud
    3 PartlyCloud
    4 Cloud
    5 LightRainSun
    6 LightRainThunderSun
    7 SleetSun
    8 SnowSun
    9 LightRain
    10 Rain
    11 RainThunder
    12 Sleet
    13 Snow
    14 SnowThunder
    15 Fog
    20 SleetSunThunder
    21 SnowSunThunder
    22 LightRainThunder
    23 SleetThunder
    24 DrizzleThunderSun
    25 RainThunderSun
    26 LightSleetThunderSun
    27 HeavySleetThunderSun
    28 LightSnowThunderSun
    29 HeavySnowThunderSun
    30 DrizzleThunder
    31 LightSleetThunder
    32 HeavySleetThunder
    33 LightSnowThunder
    34 HeavySnowThunder
    40 DrizzleSun
    41 RainSun
    42 LightSleetSun
    43 HeavySleetSun
    44 LightSnowSun
    45 HeavysnowSun
    46 Drizzle
    47 LightSleet
    48 HeavySleet
    49 LightSnow
    50 HeavySnow
 ******************************************************************
 */

/**
 * Symbol, { Day, night }
 */
const QMap<int, QPair<QString, QString>> weatherIcon::m_iconMap = {
	{  1, { "weather-clear", "weather-clear-night" } },
	{  2, { "weather-few-clouds", "weather-few-clouds-night" } },
	{  3, { "weather-clouds", "weather-clouds-night" } },
	{  4, { "weather-many-clouds", "weather-many-clouds" } },
	{  5, { "weather-showers-scattered-day", "weather-showers-scattered-night" } },
	{  6, { "weather-showers-scattered", "weather-showers-scattered" } },
	{  7, { "weather-hail", "weather-hail" } },
	{  8, { "weather-snow", "weather-snow" } },
	{  9, { "weather-showers-scattered", "weather-showers-scattered" } },
	{ 10, { "weather-showers", "weather-showers" } },
	{ 11, { "weather-storm", "weather-storm" } },
	{ 12, { "weather-hail", "weather-hail" } },
	{ 13, { "weather-snow", "weather-snow" } },
	{ 14, { "weather-storm", "weather-storm" } },
	{ 15, { "weather-fog", "weather-fog" } },
	{ 20, { "weather-hail", "weather-hail" } },
	{ 21, { "weather-storm", "weather-storm" } },
	{ 22, { "weather-storm", "weather-storm" } },
	{ 23, { "weather-hail", "weather-hail" } },
	{ 24, { "weather-storm", "weather-storm" } },
	{ 25, { "weather-storm", "weather-storm" } },
	{ 26, { "weather-hail", "weather-hail" } },
	{ 27, { "weather-hail", "weather-hail" } },
	{ 28, { "weather-storm", "weather-storm" } },
	{ 29, { "weather-storm", "weather-storm" } },
	{ 30, { "weather-storm", "weather-storm" } },
	{ 31, { "weather-hail", "weather-hail" } },
	{ 32, { "weather-hail", "weather-hail" } },
	{ 33, { "weather-storm", "weather-storm" } },
	{ 34, { "weather-snow", "weather-snow" } },
	{ 40, { "weather-showers-scattered-day", "weather-showers-scattered-night" } },
	{ 41, { "weather-showers-day", "weather-showers-night" } },
	{ 42, { "weather-hail", "weather-hail" } },
	{ 43, { "weather-hail", "weather-hail" } },
	{ 44, { "weather-snow-scattered-day", "weather-snow-scattered-night" } },
	{ 45, { "weather-snow", "weather-snow" } },
	{ 46, { "weather-snow-scattered", "weather-snow-scattered" } },
	{ 47, { "weather-hail", "weather-hail" } },
	{ 48, { "weather-hail", "weather-hail" } },
	{ 49, { "weather-snow-scattered", "weather-snow-scattered" } },
	{ 50, { "weather-snow", "weather-snow" } }
};

//static const iconMap m_iconMap[] = {
//};

QIcon weatherIcon::getWeatherIcon(int symbol, bool night)
{
	if (m_iconMap.count(symbol)) {
		if (night) {
			return QIcon::fromTheme(m_iconMap[symbol].second);
		}

		return QIcon::fromTheme(m_iconMap[symbol].first);
	}

	return QIcon::fromTheme("weather-none");
}
