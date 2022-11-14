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

#ifndef SCHEDULEQUEUE_H
#define SCHEDULEQUEUE_H

#include <QWidget>
#include <QTimer>
#include <QMap>
#include <QDateTime>

#include "commonfunc.h"

class AbstractScheduleItem;

class ScheduleQueue : public QObject {

    Q_OBJECT

public:
    explicit ScheduleQueue(QObject *parent = nullptr);
    ~ScheduleQueue();

    void addScheduleItem(AbstractScheduleItem *);
    void removeScheduleItem(AbstractScheduleItem *);

private:
    QTimer m_timer;
    QMap<AbstractScheduleItem *, QDateTime> m_queue;

    QDateTime findNext(AbstractScheduleItem *);
    void updateQueue();
};

class AbstractScheduleItem : public QWidget {

    Q_OBJECT

public:
    explicit AbstractScheduleItem(QWidget *parent = nullptr) : QWidget(parent) { }
    virtual ~AbstractScheduleItem() { }

    virtual ItemType getType() = 0;
    virtual QDateTime getDateTime() = 0;
    virtual RepeatType getRepeatType() = 0;
    virtual bool getReminderIsAlarm() = 0;
    virtual bool getIsSnooze() = 0;
    virtual bool getIsRepeat() = 0;
	virtual bool getIsItemEnabled() = 0;
    virtual bool getIsWeekdayEnable(WeekDay) = 0;
    virtual void ring() = 0;
};

#endif // SCHEDULEQUEUE_H
