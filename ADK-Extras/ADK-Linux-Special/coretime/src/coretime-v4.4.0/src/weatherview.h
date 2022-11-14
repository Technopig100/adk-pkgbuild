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

#include <QWidget>
#include <QSettings>
#include <QTimerEvent>
#include <QBasicTimer>
#include <QTableWidgetItem>

#include <cprime/cplugininterface.h>

#include "locationinfo.h"
#include "apirequest.h"
#include "weatherdata.h"

QT_BEGIN_NAMESPACE
namespace Ui { class weatherView; }
QT_END_NAMESPACE

class weatherView : public QWidget
{
    Q_OBJECT

public:
    weatherView(QWidget *parent = nullptr);
    ~weatherView();

	void initializeWeather();
	bool isWeatherLocationAvailable();

signals:
	void updateTodayWeather(WeatherData wd);

protected:
    void timerEvent(QTimerEvent *event);

private slots:
    void loadLocations(Locations locs);
    void on_selectLocBtn_clicked();
    void on_search_clicked();
    void on_select_clicked();
    void on_searchStr_returnPressed();
    void on_result_itemDoubleClicked(QTableWidgetItem *item);
    void on_editLoc_clicked();

    void on_back_clicked();

	void on_mainWid_currentChanged(int index);

private:
	static const QString domain;
    Ui::weatherView *ui;
	apiRequest *request;
    QSettings *settings;
	QBasicTimer *timer;

    QString m_locName;
    QStringList m_loc;
    QString m_astroFile;
    QString m_weatherFile;
    QString m_locFile;
    QString m_settingsFile;
    QSize m_listViewIconSize;

    QString timeOffset() const;
    QString astroURL(const QString &lat, const QString &lon) const;
    QString weatherURL(const QString &lat, const QString &lon) const;

    bool isWeatherFileOld();
    bool isAstroFileOld();

    void initializeFilePaths();
    void loadSettings();
    void startSetup();

    void fetchRequest(apiRequest::Reason r);
    void showInfo(bool newLoc);

    void clearWeatherView();
};

class WeatherItem : public QWidget
{
    Q_OBJECT

public:
    WeatherItem(QString dt, float minTemp, float maxTemp, QString wStatus, QPixmap pix);
};
