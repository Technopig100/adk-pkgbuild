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
#include <QRegularExpression>
#include <QDir>
#include <QDebug>

#include "weatherinfo.h"

static void toHour(QDateTime &dt)
{
    dt.setTime(QTime(dt.time().hour(), 0));
}

weatherInfo::weatherInfo(const QString &filepath, QObject *parent) :
    QObject(parent),
    m_filepath(filepath)
{
}

DailyForecasts weatherInfo::dailyForecasts()
{
    return m_df;
}

HourlyForecasts weatherInfo::hourlyForecasts()
{
    return m_hf;
}

void weatherInfo::initializeParse()
{
    QFile file(m_filepath);
	if (file.open(QIODevice::ReadOnly)) {
		QXmlStreamReader reader(&file);
		parseData(reader);
		file.close();
	} else {
		// TODO : Remove user path from any path text (Create function in libcprime)
		qWarning() << "Can not open weather info file '" << m_filepath.replace(QRegularExpression("^(" + QDir::homePath() + ")"), "~") << "' to parse";
	}
}

void weatherInfo::parseData(QXmlStreamReader &reader)
{
    m_hf.clear();
    m_df.clear();

    HourlyForecasts result;

    QDateTime begint = QDateTime::currentDateTime();
    toHour(begint);
    QDateTime endt = begint.addSecs(6 * 3600);

    QDate begindt = begint.date();
    QDate enddt = begint.addDays(8).date();

    qDebug() << "BeginT:" << begint << " EndT:" << endt;
    qDebug() << "BeginDT:" << begindt << " EndDT:" << enddt;

    while (!reader.atEnd()) {
        if (reader.tokenType() == QXmlStreamReader::StartElement) {
            if (reader.name() == "weatherdata" || reader.name() == "product") {
                reader.readNext();
                continue;
            }

            if (reader.name() == "time" && reader.attributes().value("datatype") == "forecast") {
                QDateTime from = QDateTime::fromString(reader.attributes().value("from").toString(), "yyyy-MM-ddThh:mm:ssZ"/*Qt::ISODate*/);
                QDateTime to = QDateTime::fromString(reader.attributes().value("to").toString(), "yyyy-MM-ddThh:mm:ssZ"/*Qt::ISODate*/);

                toHour(from);
                toHour(to);

                if (!from.isValid() || !to.isValid() || to < from || to < begint || to.date() > enddt) {
                    reader.skipCurrentElement();
                    continue;
                }

                int range = from.secsTo(to) / 3600;
                if (range == 0) {
                    range = 1;
                }
                WeatherData wd = parseLocation(reader);
                wd.setRange(range);
                wd.setDT(to);
                result[to].push_back(wd);
                continue;
            }

            reader.skipCurrentElement();
        } else {
            reader.readNext();
        }
    }

    qDebug() << "Result Items:" << result.size();
    auto keys = result.keys();
    for (QDateTime &key : keys) {
        if (key <= endt) {
            m_hf[key] = result[key];
        }

        if (key.daysTo(endt) <= 7) {
            m_df[key.date()].append(result[key]);
        }
    }
    result.clear();
    keys.clear();

    for (auto &f : m_hf) {
        mergeForecasts(f, false);
    }

    for (auto &f : m_df) {
        mergeForecasts(f, true);
    }

    qDebug() << "HF Items:" << m_hf.size();
    qDebug() << "DF Items:" << m_df.size();

}

WeatherData weatherInfo::parseLocation(QXmlStreamReader &reader)
{
    WeatherData wd;

    while (!reader.atEnd()) {
        switch (reader.tokenType()) {
            case QXmlStreamReader::StartElement: {
                if (reader.name() == "temperature") {
                    float temp = reader.attributes().value("value").toFloat();
                    wd.setTemperature(temp);
                } else if (reader.name() == "minTemperature") {
                    wd.setMinTemperature(reader.attributes().value("value").toFloat());
                } else if (reader.name() == "maxTemperature") {
                    wd.setMaxTemperature(reader.attributes().value("value").toFloat());
                } else if (reader.name() == "windDirection") {
                    wd.setWindDirection(reader.attributes().value("deg").toFloat());
                    wd.setWindDirectionName(reader.attributes().value("name").toString());
                } else if (reader.name() == "windSpeed") {
                    wd.setWindSpeed(reader.attributes().value("mps").toFloat());
                } else if (reader.name() == "humidity") {
                    wd.setHumidity(reader.attributes().value("value").toFloat());
                } else if (reader.name() == "pressure") {
                    wd.setPressure(reader.attributes().value("value").toFloat());
                } else if (reader.name() == "cloudiness") {
                    wd.setCloudiness(reader.attributes().value("percent").toFloat());
                } else if (reader.name() == "fog") {
                    wd.setFog(reader.attributes().value("percent").toFloat());
                } else if (reader.name() == "dewpointTemperature") {
                    wd.setDewPointTemp(reader.attributes().value("value").toFloat());
                } else if (reader.name() == "symbol") {
                    wd.setWeatherSymbol(reader.attributes().value("number").toInt());
                    wd.setWeatherStatus(reader.attributes().value("id").toString());
                } else if (reader.name() == "precipitation") {
                    wd.setPrecipitation(reader.attributes().value("value").toFloat());
                }

                break;
            }

            case QXmlStreamReader::EndElement: {
                if (reader.name() == "time") {
                    return wd;
                }

                break;
            }

            default:
                break;
        }

        reader.readNext();
    }

    return wd;
}

void weatherInfo::mergeForecasts(WeatherForecasts &forecasts, bool daily)
{
    // Sort the forecasts by time and range
    std::sort(forecasts.begin(), forecasts.end(), [&daily](const WeatherData & l, const WeatherData & r) {
        if (l.dt() == r.dt()) {
            return l.range() < r.range();
        }

        if (daily) {
            return l.dt() < r.dt();
        }

        return l.dt() > r.dt();
    });

    auto temp = forecasts.begin();

    for (auto it = forecasts.begin(); it != forecasts.end();) {
        *temp = *it;
        auto merge = it;

        // Find the duplicated one
        for (; merge != forecasts.end(); ++merge) {
            if ((*it).dt() == (*merge).dt()) {
                if (daily) {
                    (*temp).mergeDay(*merge);
                } else {
                    (*temp).mergeHour(*merge);
                }
            } else {
                (*merge).setRange(1);
            }
        }

        ++temp;
        it = merge;
    }

    forecasts.erase(temp, forecasts.end());
}
