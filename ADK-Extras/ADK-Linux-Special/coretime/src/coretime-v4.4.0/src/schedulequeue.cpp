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

#include <QDebug>

#include "schedulequeue.h"

ScheduleQueue::ScheduleQueue(QObject *parent) : QObject(parent)
{
    m_queue.clear();
    m_timer.start(1000);
    connect(&m_timer, &QTimer::timeout, this, &ScheduleQueue::updateQueue);
}

ScheduleQueue::~ScheduleQueue()
{
    m_timer.stop();
    m_queue.clear();
}

void ScheduleQueue::addScheduleItem(AbstractScheduleItem *item)
{
//    qDebug() << "func(addScheduleItem) : Info : Type : " << item->getType();
//    qDebug() << "func(addScheduleItem) : Info : Datetime before finding next " << item->getDateTime();

    // Get actual date time for the item
    QDateTime dt = findNext(item);

//    qDebug() << "func(addScheduleItem) : Info : Datetime after finding next " << dt;
//    qDebug() << "func(addScheduleItem) : Info : Item isRepeat : " << item->getIsRepeat() << " Item isSnooze : " << item->getIsSnooze();

    if (dt.isNull() || !dt.isValid()) {
		qWarning() << "func(addScheduleItem) : Error : Invalid date time, schedule not added.";
        return;
    }

    m_queue.insert(item, dt);
}

void ScheduleQueue::removeScheduleItem(AbstractScheduleItem *item)
{
    m_queue.remove(item);
}

/*
 *  Find the next schedule date time based on the repeat type
*/
QDateTime ScheduleQueue::findNext(AbstractScheduleItem *item)
{
    QDateTime curr(QDateTime::currentDateTime());
    QDateTime next(item->getDateTime());

    // Edit the date to be current for alarm
    if (item->getType() == Alarm) {
        QTime t = item->getDateTime().time(); // Take the time
		next = QDateTime(item->getDateTime().date(), QTime(t.hour(), t.minute())); // Add current date with the time
    }

    // Add the snooze time
    if (item->getIsSnooze()) {
        // TODO Add snooze time as variable to alarm if customized
        QTime snoozeTime(0, 5, 0); // Default snooze time 5 minutes
        next = next.addSecs(snoozeTime.minute() * 60);

        // Add snooze time until it's greater then current time
        while (next < curr) {
            if (next == curr) {
                break;
            }

            next = next.addSecs(snoozeTime.minute() * 60);
        }

        return next;
    }

    // Check several repeat type for the date time if item is repeated
    if (item->getIsRepeat()) {
        RepeatType rt = item->getRepeatType();

        if (rt == Weekday) {
            for (int i = 0; i < 7; i++) {
                int dayOfWeek = next.addDays(i).date().dayOfWeek(); // Get the week day integer

                // Find which weekday is enabled
                if (item->getIsWeekdayEnable(commonFunc::intToWeekday(dayOfWeek))) {
                    qDebug() << "func(findNext) : Info : WeekDay repeated :" << dayOfWeek;
                    next = next.addDays(i);

                    // Return the weekday if it's greater than current date time
                    if (next > curr) {
                        return next;
                    }
                }
            }
        } else if (rt == SpecificWeekDay) {
            next = next.addDays(7); // Skip 7 days for repeating

            while (next < curr) {
                if (next == curr) {
                    break;
                }

                next = next.addDays(7);
            }
        } else if (rt == Year) {
            next = next.addYears(1); // Skip one year for repeating

            while (next < curr) {
                if (next == curr) {
                    break;
                }

                next = next.addYears(1);
            }
        } else if (rt == Month) {
            next = next.addMonths(1); // Skip one month for repeating

            while (next < curr) {
                if (next == curr) {
                    break;
                }

                next = next.addMonths(1);
            }
        } else if (rt == None) {
            // Does Nothing
			qWarning() << "func(findNext) : Warning : 'None' Type at item. A worst case scenario.";
        }
    } else {
        if (next > curr) {
            return next;
        }
    }

    return next;
}

void ScheduleQueue::updateQueue()
{
    QDateTime curr(QDateTime::currentDateTime());

    // List of current activated item
    QMap<AbstractScheduleItem *, QDateTime> activated;
    QMapIterator<AbstractScheduleItem *, QDateTime> it(m_queue);

    // Iterate the current queue for upcoming schedule date time
    while (it.hasNext()) {
        it.next();

        AbstractScheduleItem *item(it.key());
        QDateTime dt(it.value());

        // If item is reminder and don't have alarm then match the date only
        if (!item->getReminderIsAlarm() && item->getType() == Reminder) {
            if (dt.date() == curr.date()) {
                activated.insert(item, dt);
			}

            continue;
        }

        // Check for minute except (QDateTime == QDateTime) seconds
        if (dt.date() == curr.date() && dt.time().hour() == curr.time().hour() &&
                dt.time().minute() == curr.time().minute()) {
            activated.insert(item, dt);
			continue;
		}

		// Not working fully for repeated alarms
		if (item->getIsRepeat()) {
			if (dt.date() == curr.date() &&
				(dt.time().hour() < curr.time().hour() ||
				dt.time().minute() < curr.time().minute())) { // Missed event
				activated.insert(item, dt);
			}
		} else {
			if (dt.date() < curr.date() &&
				(dt.time().hour() < curr.time().hour() ||
				dt.time().minute() < curr.time().minute())) { // Missed event
				activated.insert(item, dt);
			}
		}
    }

    // Iterate and ring the upcoming queue items
    it = QMapIterator<AbstractScheduleItem *, QDateTime>(activated);

    while (it.hasNext()) {
        it.next();

        AbstractScheduleItem *item(it.key());

        if (item->getIsItemEnabled()) {
            item->ring();
        }
    }
}
