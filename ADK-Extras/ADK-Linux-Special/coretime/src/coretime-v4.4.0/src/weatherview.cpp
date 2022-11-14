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

#include <QDir>
#include <QDebug>
#include <QLabel>
#include <QDateTime>
#include <QMessageBox>

#include <cprime/variables.h>
#include <cprime/themefunc.h>

#include "astroinfo.h"
#include "weatherinfo.h"
#include "weathericon.h"

#include "weatherview.h"
#include "ui_weatherview.h"

const QString weatherView::domain = "https://api.met.no";


weatherView::weatherView(QWidget *parent): QWidget(parent), ui(new Ui::weatherView)
{
    ui->setupUi(this);

    initializeFilePaths();

    timer = new QBasicTimer;
	request = new apiRequest(this);
    settings = new QSettings(m_settingsFile, QSettings::IniFormat);

    loadSettings();
    startSetup();
}

weatherView::~weatherView()
{
	timer->stop();
	delete timer;
	delete settings;
	delete request;
    delete ui;
}

void weatherView::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == timer->timerId()) {
		if (QTime::currentTime().minute() == 0) {
            showInfo(false);
		}
    }
}

QString weatherView::timeOffset() const
{
    QDateTime dt = QDateTime::currentDateTime();
    int offsetSec = dt.offsetFromUtc();
    QTime time(0, 0);
    time = time.addSecs(offsetSec);
    return "+" + time.toString("hh:mm");
}

QString weatherView::astroURL(const QString &lat, const QString &lon) const
{
    return QString("%1/weatherapi/sunrise/2.0/?lat=%2&lon=%3&date=%4&offset=%5")
           .arg(domain, lat, lon, QDate::currentDate().toString("yyyy-MM-dd"), timeOffset());
}

QString weatherView::weatherURL(const QString &lat, const QString &lon) const
{
	return QString("%1/weatherapi/locationforecast/2.0/classic?lat=%2&lon=%3").arg(domain, lat, lon);
}

bool weatherView::isWeatherFileOld()
{
    QFileInfo info(m_weatherFile);

    if (info.exists()) {
        QDateTime currdt = QDateTime::currentDateTime();
        currdt.setTime(QTime(currdt.time().hour(), 0));
        QDateTime filedt = info.lastModified();

		filedt.setTime(QTime(filedt.time().hour(), 0));
        filedt = filedt.addSecs(3600);

		if (filedt <= currdt) {
            return true;
        }

        return false;
    }

    return true;// File not found
}

bool weatherView::isAstroFileOld()
{
    QFileInfo info(m_astroFile);

    if (info.exists()) {
        QDateTime currdt = QDateTime::currentDateTime();
        QDateTime filedt = info.lastModified();

		if (filedt.date() != currdt.date()) {
            return true;
        }

        return false;
    }

    return true;// File not found
}

void weatherView::initializeFilePaths()
{
    QDir tempDir(CPrime::Variables::CC_Library_ConfigDir());

    if (!tempDir.exists("plugins")) {
		tempDir.mkdir("plugins");
    }

	if (tempDir.cd("plugins")) {
		if (!tempDir.exists("weather")) {
			tempDir.mkdir("weather");
		}

		if (tempDir.cd("weather")) {
			QString defaultFilepath = tempDir.path();
			m_weatherFile = defaultFilepath + "/weather-forecast-cubocore.xml";
			m_astroFile = defaultFilepath + "/astro-data-cubocore.xml";
			m_settingsFile = defaultFilepath + "/weather.conf";
		} else {
			qWarning() << "Can not call directory 'weather'";
		}
	} else {
		qWarning() << "Can not call directory 'plugins'";
	}
}

void weatherView::loadSettings()
{
    m_listViewIconSize = QSize(24,24);

    m_loc = settings->value("Weather/Location").toStringList();
    m_locName = settings->value("Weather/CityName").toString();
}

bool weatherView::isWeatherLocationAvailable() {
	return (m_loc.count() && m_locName.count());
}

void weatherView::initializeWeather() {
	if (isWeatherLocationAvailable()) {
		ui->mainWid->setCurrentIndex(2);
		showInfo(false);
	} else {
		ui->mainWid->setCurrentIndex(0);
	}

	timer->start(60 * 1000, this);
}

void weatherView::startSetup()
{
	connect(request, &apiRequest::fileDownloaded, this, &weatherView::fetchRequest);

	ui->wStatus->setVisible(false);
	ui->editLoc->setIcon(CPrime::ThemeFunc::themeIcon( "edit-find-symbolic", "edit-find", "edit-find" ));
	ui->search->setIcon(CPrime::ThemeFunc::themeIcon( "edit-find-symbolic", "edit-find", "edit-find" ));
}

void weatherView::fetchRequest(apiRequest::Reason r)
{
    if (r == apiRequest::WeatherData) {
		weatherInfo *wi = new weatherInfo(m_weatherFile);
        wi->initializeParse();
        HourlyForecasts hf = wi->hourlyForecasts();
        DailyForecasts df = wi->dailyForecasts();
		delete wi;

		if (not (df.count() && hf.count())) {
		   QMessageBox::warning(this, "No data found!!!", "Invalid timezone for the selected location.");
		   return;
		}

        WeatherData today;

        ui->hourly->clear();
        ui->daily->clear();
        QListWidgetItem *item;
        bool night;

        for (auto f : df) {
            for (int i = 0; i < f.size(); i++) {
                WeatherData wd = f[i];

				if (wd.localDateTime() < QDateTime::currentDateTime()) {
                    continue;
                }

//                item = new QListWidgetItem(QString("%1\t%2°C/%3°C  %4")
//                                           .arg(wd.dt().toString("dddd"))
//                                           .arg(wd.minTemperature())
//                                           .arg(wd.maxTemperature())
//                                           .arg(wd.weatherStatus()));
				item = new QListWidgetItem;

				night = (wd.localDateTime().time().hour() >= 18) ? true : false;
				QPixmap pix = weatherIcon::getWeatherIcon(wd.weatherSymbol(), night).pixmap(48, 48);

				WeatherItem *itemWid = new WeatherItem(wd.localDateTime().toString("dddd"),
													   wd.minTemperature(), wd.maxTemperature(),
													   wd.weatherStatus(), pix);

				item->setSizeHint(itemWid->sizeHint() + QSize(15, 15));

//                item->setIcon(weatherIcon::getWeatherIcon(wd.weatherSymbol(), night));
                ui->daily->addItem(item);
				ui->daily->setItemWidget(item, itemWid);
            }
        }

        for (auto f : hf) {
            for (int i = 0; i < f.size(); i++) {
				WeatherData wd = f[i];

				if (wd.localDateTime() < QDateTime::currentDateTime()) {
                    continue;
                }

				if (wd.localDateTime().time() == QTime((QTime::currentTime().hour() + 1) % 24, 0)) {
                    today = wd;
                    continue;
                }

                item = new QListWidgetItem();

				night = (wd.localDateTime().time().hour() >= 18) ? true : false;
				QPixmap pix = weatherIcon::getWeatherIcon(wd.weatherSymbol(), night).pixmap(48, 48);

				WeatherItem *itemWid = new WeatherItem(wd.localDateTime().addSecs(-3600).toString("hh:mm AP"),
                                                       wd.minTemperature(), wd.maxTemperature(),
                                                       wd.weatherStatus(), pix);
				item->setSizeHint(itemWid->sizeHint() + QSize(15, 15));
                ui->hourly->addItem(item);
                ui->hourly->setItemWidget(item, itemWid);
            }
        }

        hf.clear();
        df.clear();

		if (!today.localDateTime().isValid()) {
            return;
        }

		night = (today.localDateTime().time().hour() >= 18) ? true : false;
        QPixmap pix = weatherIcon::getWeatherIcon(today.weatherSymbol(), night).pixmap(64, 64);

//        ui->tTemp->setText(QString("%1°C (%2°C / %3°C)").arg(today.temperature()).arg(today.minTemperature()).arg(today.maxTemperature()));

//		ui->tTemp->setText(QString("%1°C").arg(today.temperature()));
//		ui->tMinTemp->setText(QString("%1°C").arg(today.minTemperature()));
//		ui->tMaxTemp->setText(QString("%1°C").arg(today.maxTemperature()));
//        ui->tWstat->setText(today.weatherStatus());
//        ui->tIcon->setPixmap(pix);
        ui->tWind->setText(QString("Wind: %1m/s %2° %3").arg(today.windSpeed()).arg(today.windDirection()).arg(today.windDirectionName()));
        ui->tPress->setText(QString("Pressure: %1hPa").arg(today.pressure()));
        ui->tHumd->setText(QString("Humidity: %1%").arg(today.humidity()));
        ui->tDewT->setText(QString("Dew Temp: %1°C").arg(today.dewPointTemp()));
        ui->tPrec->setText(QString("Precipitation: %1%").arg(today.precipitation()));
        ui->tCloud->setText(QString("Cloud: %1%").arg(today.cloudiness()));
        ui->tFog->setText(QString("Fog: %1%").arg(today.fog()));

		emit updateTodayWeather(today);
    } else if (r == apiRequest::AstroData) {
		astroInfo ai(m_astroFile);
		ai.initializeParse();
		ui->sunrise->setText("Sunrise: " + ai.sunrise());
		ui->sunset->setText("Sunset: " + ai.sunset());
		ui->moonrise->setText("Moonrise: " + ai.moonrise());
		ui->moonset->setText("Moonset: " + ai.moonset());
    } else if (r == apiRequest::LocationData) {
		locationInfo li(m_locFile);
		li.initializeParse();
		loadLocations(li.locations());
    }
}

void weatherView::showInfo(bool newLoc)
{
    if (!m_locName.count() || m_loc.size() != 2) {
        return;
    }

    QString lat = m_loc[0];
    QString lon = m_loc[1];

    if (!lat.count() || !lon.count()) {
        return;
    }

    bool isWDone = true;
    bool isADone = true;

	if (newLoc) {
		isWDone = request->requestData(weatherURL(lat, lon), m_weatherFile, apiRequest::WeatherData);
        isADone = request->requestData(astroURL(lat, lon), m_astroFile, apiRequest::AstroData);
    } else {
		if (isWeatherFileOld()) {
			isWDone = request->requestData(weatherURL(lat, lon), m_weatherFile, apiRequest::WeatherData);

            if (!isWDone) {
                QFileInfo file(m_weatherFile);

                if (file.exists()) {
                    fetchRequest(apiRequest::WeatherData);
                }
            }
		} else {
            fetchRequest(apiRequest::WeatherData);
        }

		if (isAstroFileOld()) {
            isADone = request->requestData(astroURL(lat, lon), m_astroFile, apiRequest::AstroData);
		} else {
            fetchRequest(apiRequest::AstroData);
        }
    }

    if (!isWDone || !isADone) {
        ui->wStatus->setVisible(true);
        ui->wStatus->setText("<p style=\"color: red;\">No Internet Connection. Data is old.</p>");
    }

    ui->location->setText(m_locName.split(",")[0]);
}

void weatherView::clearWeatherView()
{
    ui->sunrise->setText("hh:mm AP");
    ui->sunset->setText("hh:mm AP");
    ui->moonrise->setText("hh:mm AP");
    ui->moonset->setText("hh:mm AP");

    ui->location->clear();
//    ui->tIcon->setText("ICON");
//    ui->tIcon->setPixmap(QPixmap());
//    ui->tWstat->setText("Weather Status");
//	ui->tTemp->setText("Current Temp");
//	ui->tMinTemp->setText("Min Temp");
//	ui->tMaxTemp->setText("Max Temp");
    ui->tWind->setText("Wind: speedm/s direction° S/N/E/W");
    ui->tPress->setText("Pressure: hPa");
    ui->tHumd->setText("Humidity: %");
    ui->tDewT->setText("Dew Point Temp: °C");
    ui->tPrec->setText("Precipitation: %");
    ui->tCloud->setText("Cloud: %");
    ui->tFog->setText("Fog: %");
    ui->hourly->clear();
    ui->daily->clear();
}

/************************ Location search ************************/
void weatherView::loadLocations(Locations locs)
{
	ui->result->setColumnCount(2);
    ui->result->setRowCount(locs.size());

	int i = 0;
    for (auto &loc : locs) {
		auto item = new QTableWidgetItem(loc.locationName());
        item->setData(Qt::UserRole, QStringList( { loc.latitude(), loc.longitude() } ));
        ui->result->setItem(i, 0, new QTableWidgetItem(loc.locationClass()));
        ui->result->setItem(i, 1, item);
        i++;
    }
}

void weatherView::on_selectLocBtn_clicked()
{
    ui->status->clear();
    ui->status->setVisible(false);
    ui->mainWid->setCurrentIndex(1);
    ui->searchStr->clear();
    ui->searchStr->setFocus();
    ui->result->clear();
}

void weatherView::on_searchStr_returnPressed()
{
    on_search_clicked();
}

void weatherView::on_search_clicked()
{
    QString locStr = ui->searchStr->text();

    if (locStr.count()) {
        QString locUrl = QString("https://nominatim.openstreetmap.org/search?format=xml&q=%1").arg(locStr);
        m_locFile = "/tmp/Locations-" + QDateTime::currentDateTime().toString("dd-MM-yyyyThh-mm-ss") + ".xml";
        bool isDone = request->requestData(locUrl, m_locFile, apiRequest::LocationData);

        if (isDone) {
            ui->select->setEnabled(true);
        } else {
            ui->status->setVisible(true);
            ui->status->setText("<p style=\"color: red;\">Cannot search location because there is no internet connection.</p>");
        }
    }
}

void weatherView::on_select_clicked()
{
    int sel = ui->result->currentRow();
    QTableWidgetItem *item = ui->result->currentItem();

    if (!item || sel < 0) {
        return;
    }

    item = ui->result->item(sel, 1);
    on_result_itemDoubleClicked(item);
}

void weatherView::on_result_itemDoubleClicked(QTableWidgetItem *item)
{
    item = ui->result->item(item->row(), 1);

    QString locName = item->text();
    QStringList loc = item->data(Qt::UserRole).toStringList();

	if ((!m_locName.count() || m_loc.count() != 2) || (locName != m_locName && loc.at(0) != m_loc.at(0) && loc.at(1) != m_loc.at(1))) {
        // New location
		settings->setValue("Weather/Location", loc);
        settings->setValue("Weather/CityName", locName);
        settings->sync();

        m_loc = loc;
        m_locName = locName;

        showInfo(true);
    } else {
        showInfo(false);
    }

	ui->mainWid->setCurrentIndex(1);
}
/**************************************************************/

void weatherView::on_editLoc_clicked()
{
    ui->searchStr->clear();
    ui->result->clear();
    clearWeatherView();
	ui->mainWid->setCurrentIndex(0);
    ui->searchStr->setFocus();
}

void weatherView::on_back_clicked()
{
	if (isWeatherLocationAvailable()) {
		ui->mainWid->setCurrentIndex(1);
		showInfo(false);
	} else {
		ui->mainWid->setCurrentIndex(0);
	}
}

void weatherView::on_mainWid_currentChanged(int index)
{
	setMaximumHeight(ui->mainWid->widget(index)->sizeHint().height());
}

WeatherItem::WeatherItem(QString dt, float minTemp, float maxTemp, QString wStatus, QPixmap pix)
{
	QLabel *ldt = new QLabel(dt, this);
	QLabel *lico = new QLabel(this);
    lico->setPixmap(pix);
	QLabel *lstat = new QLabel(wStatus, this);
	QLabel *ltemp = new QLabel(QString("%1 / %2").arg(minTemp).arg(maxTemp), this);

    ldt->setAlignment(Qt::AlignCenter);
    lico->setAlignment(Qt::AlignCenter);
    lstat->setAlignment(Qt::AlignCenter);
    ltemp->setAlignment(Qt::AlignCenter);

	QFont font = ldt->font();
	font.setPointSize(12);
	ldt->setFont(font);

    QVBoxLayout *lay = new QVBoxLayout;
    lay->setAlignment(Qt::AlignCenter);
	lay->setContentsMargins(7,0,7,0);
    lay->setSpacing(0);
    lay->addWidget(ldt);
	lay->addSpacing(10);
    lay->addWidget(lico);
	lay->addSpacing(10);
    lay->addWidget(lstat);
    lay->addWidget(ltemp);
    setLayout(lay);
}
