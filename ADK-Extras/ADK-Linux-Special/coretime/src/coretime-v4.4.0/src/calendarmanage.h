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
    * along with this program; if not, vsit http://www.gnu.org/licenses/.
    *
*/

#ifndef CALENDARMANAGE_H
#define CALENDARMANAGE_H

#include <QCalendarWidget>
#include <QBrush>
#include <QColor>
#include <QDate>
#include <QMap>

class calendarmanage: public QCalendarWidget
{
    Q_OBJECT

public:
    calendarmanage(QWidget *parent = nullptr);
    ~calendarmanage();

	/* Add a reminder or a holiday: type == 1 is holiday, type == 0 is reminder */
    void addEvent( QDate date, int type );

    /* Clear all the events */
    void clearEvents();

protected:
    virtual void paintCell(QPainter *painter, const QRect &rect, const QDate &date) const;

private:
    QList<QDate> reminders;
	QList<QDate> holidays;
};

#endif // CALENDARMANAGE_H
