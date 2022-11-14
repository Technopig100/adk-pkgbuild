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

#pragma once

#include <QObject>
#include <QMap>

// Type used to define two item
enum ItemType {
    Alarm = 0,
    Reminder
};

// Several repeated type used in reminder and alarm
enum RepeatType {
    Weekday = 0,
    Month,
    Year,
    SpecificWeekDay,
    None // Does Nothing
};

// List week days
enum WeekDay {
    Monday = 1, // For getting week number
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

enum Type {
    ReminderDate,
    HolidayDate
};

struct CalendarEvent {
    Type type;
    bool repeat;
    RepeatType rType;
    QMap < WeekDay, bool > wd;
    QString description;
};

typedef QMap < QDate, QList < CalendarEvent > > CalendarData;

// Stores common funtions between alarm and reminder
class commonFunc{

public:
    static WeekDay intToWeekday(int num);
    static QString defaultAudio();
    static QString createID();
    static QString weekdaysToString(QMap<WeekDay, bool> weekdays);
};

