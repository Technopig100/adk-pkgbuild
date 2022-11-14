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

#ifndef ALARMWIDGET_H
#define ALARMWIDGET_H

#include <QWidget>

#include "settings.h"
#include "schedulequeue.h"


class QSettings;
class alarmItemWidget;
class QListWidgetItem;

namespace Ui {
    class alarmWidget;
}

class alarmWidget : public QWidget {

    Q_OBJECT

public:
    explicit alarmWidget(QWidget *parent = nullptr);
    ~alarmWidget();
    static alarmWidget *instance(QWidget *parent);

private slots:
    void on_done_clicked();
    void on_cancel_clicked();
    void on_browseAlarmSound_clicked();

private:
    Ui::alarmWidget *ui;
    ScheduleQueue m_alarmQueue;
    QSettings *setts;
	bool newAlarm;

    bool checkConfig();
    void changeState(bool state);

    void addAlarmItem();
    void loadAlarmItems();

    void alarmToConfig(alarmItemWidget *item);
    void configToAlarm(alarmItemWidget *item);

    void ringAlarm(QListWidgetItem *item);
    void editAlarm(QListWidgetItem *item);
    void removeAlarm(QListWidgetItem *item);
    void alarmItemToggled(bool enable, QListWidgetItem *item);
};

#endif // ALARMWIDGET_H
