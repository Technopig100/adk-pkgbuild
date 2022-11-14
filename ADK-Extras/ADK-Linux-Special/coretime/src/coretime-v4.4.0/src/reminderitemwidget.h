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

#ifndef REMINDERITEMWIDGET_H
#define REMINDERITEMWIDGET_H

#include <QWidget>
#include <QListWidgetItem>

#include "settings.h"
#include "schedulequeue.h"

class QSettings;

namespace Ui {
    class reminderItemWidget;
}

class reminderItemWidget : public AbstractScheduleItem {

    Q_OBJECT

public:
    explicit reminderItemWidget(QString id, QSettings *sett, QListWidgetItem *container, QWidget *parent = nullptr);
    ~reminderItemWidget() override;

    // AbstractScheduleItem interface
    ItemType getType() override;
    QDateTime getDateTime() override;
    RepeatType getRepeatType() override;
    bool getReminderIsAlarm() override;
    bool getIsSnooze() override;
    bool getIsRepeat() override;
    bool getIsItemEnabled() override;
    bool getIsWeekdayEnable(WeekDay week) override;
    void ring() override;

    QString getId();
    void setDateTime(QDateTime dt);
    void setRepeatType(RepeatType);
    void setReminderIsAlarm(bool addAlarm);
    void setIsSnooze(bool snooze);
    void setIsRepeat(bool repeat);
    void setItemEnable(bool);
    void setWeekdayEnable(WeekDay week, bool enable);

    QString getDescription();
    void setDescription(QString str);

    QString getCustomSoundFilePath();
    void setCustomSoundFilePath(QString filePath);

    bool getIsCustomSound();
    void setIsCustomSound(bool custom);

    QString getReminderRepeatStatus();
    void setReminderRepeatStatus(QString repeatText);

    void loadReminder();
    void saveReminder();
    void deleteReminder();

    void defaultValues();
    QString weekdayToString();

Q_SIGNALS:
    void ringReminderOccurred(QListWidgetItem *item);
    void editOccurred(QListWidgetItem *item);
    void removeOccurred(QListWidgetItem *item);
    void enableToggled(bool state, QListWidgetItem *item);

private:
    Ui::reminderItemWidget *ui;
    QSettings *setts;
	QListWidgetItem *m_container;

    QDateTime m_dateTime;
    bool m_isAlarm, m_isRepeat, m_isSnooze, m_isCustomSound, m_itemEnabled;
    RepeatType m_repeatType;
    QString m_description, m_customSoundFilePath, m_id;
    QMap<WeekDay, bool> m_weekdays;

};

#endif // REMINDERITEMWIDGET_H
