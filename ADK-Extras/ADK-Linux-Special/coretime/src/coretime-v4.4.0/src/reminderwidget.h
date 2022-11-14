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

#ifndef REMINDERWIDGET_H
#define REMINDERWIDGET_H

#include <QWidget>

#include "settings.h"
#include "schedulequeue.h"


class QLabel;
class QSettings;
class QListWidgetItem;
class reminderItemWidget;
class categoryCard;

namespace Ui {
class reminderWidget;
}

class reminderWidget : public QWidget
{
    Q_OBJECT

public:
    explicit reminderWidget(QWidget *parent = nullptr);
    ~reminderWidget();
    static reminderWidget *instance(QWidget *parent);

signals:
    void reminderAdded(QDate d, CalendarEvent &event);
    void reminderEdited(QDate oldD, QDate newD, CalendarEvent &event);
    void reminderDeleted(QDate d);

private slots:
    void on_done_clicked();
    void on_cancel_clicked();
    void on_browseReminderSound_clicked();
    void on_r_specific_toggled(bool checked);

private:
    Ui::reminderWidget *ui;
    ScheduleQueue m_reminderQueue;
	QSettings *setts;
    bool newReminder;
    settings    *smi;

    bool checkConfig();
    void changeState(bool state);

    void addReminderItem();
    void loadReminderItems();

    void reminderToConfig(reminderItemWidget *itemWidget);
    void configToReminder(reminderItemWidget *itemWidget);

    void ringReminder(QListWidgetItem *item);
    void editReminder(QListWidgetItem *item);
    void removeReminder(QListWidgetItem *item);
    void reminderEnableToggled(bool state, QListWidgetItem *item);
};

#endif // REMINDERWIDGET_H
