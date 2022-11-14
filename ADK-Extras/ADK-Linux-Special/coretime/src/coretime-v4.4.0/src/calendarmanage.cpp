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

#include <QPainter>

#include "calendarmanage.h"


calendarmanage::calendarmanage(QWidget *parent): QCalendarWidget(parent) {

	setGridVisible( true );
}

calendarmanage::~calendarmanage() {

    reminders.clear();
    holidays.clear();
}

void calendarmanage::addEvent(QDate date, int type) {

	if ( type )
		holidays << date;

	else
		reminders << date;
}

void calendarmanage::clearEvents() {

    reminders.clear();
    holidays.clear();
}

void calendarmanage::paintCell(QPainter *painter, const QRect &rect, const QDate &date) const
{
    QCalendarWidget::paintCell(painter, rect, date);

    int x = rect.x() + 3;
    int y = rect.y() + 0.9 * rect.height();
    int w = rect.width() * 0.1;

	if ( holidays.contains( date ) ) {
		painter->save();
		painter->setPen( QPen( QColor( 204, 37, 41 ), 2 ) );
		painter->drawLine( QPoint( x, y ), QPoint( x + w, y ) );
		painter->restore();

		x += ( w + 5 );
	}

	if ( reminders.contains( date ) ) {
		painter->save();
		painter->setPen( QPen( QColor( 62, 180, 81 ), 2 ) );
		painter->drawLine( QPoint( x, y ), QPoint( x + w, y ) );
		painter->restore();
	}
}
