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

#ifndef ALARMITEMWIDGET_H
#define ALARMITEMWIDGET_H

#include <QWidget>
#include <QListWidgetItem>

#include "schedulequeue.h"
#include "settings.h"


class QSettings;

namespace Ui {
    class alarmItemWidget;
}

class alarmItemWidget : public AbstractScheduleItem {

    Q_OBJECT

public:
    explicit alarmItemWidget(QString id, QSettings *sett, QListWidgetItem *container, QWidget *parent = nullptr);
    ~alarmItemWidget() override;

    // AbstractScheduleItem interface
    ItemType getType() override;
    QDateTime getDateTime() override;
    RepeatType getRepeatType() override;
    bool getReminderIsAlarm() override;
    bool getIsRepeat() override;
    bool getIsSnooze() override;
    bool getIsItemEnabled() override;
    bool getIsWeekdayEnable(WeekDay) override;
    void ring() override;

    QString getId();
    void setDateTime(QDateTime);
    void setRepeatType(RepeatType);
    void setIsRepeat(bool repeat);
    void setIsSnooze(bool snooze);
    void setItemEnable(bool);
    void setWeekdayEnable(WeekDay week, bool enable);

    QString getDescription();
    void setDescription(QString description);

    QString getCustomSoundFilePath();
    void setCustomSoundFilePath(QString filePath);

    bool getIsCustomSound();
    void setIsCustomSound(bool custom);

    QString getAlarmStatus();
    QString getAlarmLabel();
    void setAlarmStatus(QString text);

    void loadAlarm();
    void saveAlarm();
    void deleteAlarm();

    void defaultValues();
    QString weekdayToString();

Q_SIGNALS:
    void ringAlarmOccured(QListWidgetItem *item);
    void editOccurred(QListWidgetItem *item);
    void removeOccurred(QListWidgetItem *item);
    void enableToggled(bool state, QListWidgetItem *item);

private:
    Ui::alarmItemWidget *ui;
    QSettings *setts;
	QListWidgetItem *m_container;

    QString m_id, m_description, m_customSoundFilePath;
    bool m_itemEnabled, m_isRepeat, m_isSnooze, m_isCustomSound;
    QDateTime m_dateTime;
    RepeatType m_repeatType;

    QMap<WeekDay, bool> m_weekdays;
};

#endif // ALARMITEMWIDGET_H
