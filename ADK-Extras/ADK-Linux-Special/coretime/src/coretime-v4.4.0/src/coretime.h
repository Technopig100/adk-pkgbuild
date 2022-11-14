/*
    *
    * This file is a part of CoreTime.
    * A time related task manager for C Suite
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
    * along with this program; if not, write to the Free Software
    * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
    * MA 02110-1301, USA.
    *
*/

#pragma  once

#include <QWidget>
#include <QToolButton>
#include <QSystemTrayIcon>
#include <QDateTime>

#include "settings.h"
#include "commonfunc.h"
#include "weatherdata.h"

class QPushButton;
class QTimer;
class StopWatch;
class weatherView;

namespace Ui {
    class coretime;
}

class coretime : public QWidget {

    Q_OBJECT

public:
    explicit coretime(QWidget *parent = nullptr);
    ~coretime();

private slots:
    void updateTimer();
    void on_startandpause_clicked(bool checked);
    void on_lapandreset_clicked();
    void on_addTimer_clicked();
    void on_startstopTimer_clicked(bool checked);
    void on_resetTimer_clicked();
    void pageClick(QToolButton *btn, int i, QString title);
    void on_alarm_clicked();
    void on_now_clicked();
    void on_stopwatch_clicked();
    void on_timer_clicked();
    void on_reminders_clicked();
    void toggleShowHide(QSystemTrayIcon::ActivationReason reason);
    void on_calendarWid_clicked(const QDate &date);
    void on_calendarWid_currentPageChanged(int year, int month);
    void showSideView();
    void reminderAdded(QDate d, CalendarEvent &event);
    void reminderEdited(QDate oldD, QDate newD, CalendarEvent &event);
    void reminderDeleted(QDate d);

    void on_weather_clicked();
    void on_calendar_clicked();

private:
    Ui::coretime   *ui;
    settings       *smi;
    QTimer         *clockTimer{};
    StopWatch      *st{};
    qint64          mSessionTime{};
    int             uiMode{};
    bool            useSystemNotification{};
    QSize           toolsIconSize, listViewIconSize;
    QTimer         *forTimer{};
    CalendarData    m_events;
	weatherView *wv;

    void loadHolidayEvents(QString eventFile);
    void loadReminderEvents();
    void startSetup();
    void setupIcons();
    void loadSettings();
    void initializeTray();
    void initializeClock();
    void initializeAlrRemd();
    void initializeStopwatch();
    void initializeTimer();
    void updateStopwatchTime(int time);
    void appendDate(CalendarData &events, QDate date, CalendarEvent &e);
    void setEventText(QDate date, QString &reminder, QString &holiday);

	void updateWeather(WeatherData wd);

    static constexpr int MSECS_PER_HOUR = 3600000;
    static constexpr int MSECS_PER_MIN = 60000;
    static constexpr int MSECS_PER_SEC = 1000;
    static constexpr int SECS_PER_MIN = 60;
};
