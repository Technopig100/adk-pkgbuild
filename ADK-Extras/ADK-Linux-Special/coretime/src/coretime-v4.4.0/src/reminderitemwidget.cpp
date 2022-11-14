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
#include <QSettings>

#include "reminderitemwidget.h"
#include "ui_reminderitemwidget.h"



reminderItemWidget::reminderItemWidget(QString id, QSettings *sett, QListWidgetItem *container, QWidget *parent) :
    AbstractScheduleItem(parent)
  , ui(new Ui::reminderItemWidget)
{
    ui->setupUi(this);

    m_container = container;
    m_id = id;
    setts = sett;

	settings smi;
	ui->editReminder->setIconSize(smi.getValue("CoreApps", "ListViewIconSize") - QSize(8,8));
	ui->removeReminder->setIconSize(smi.getValue("CoreApps", "ListViewIconSize") - QSize(8,8));

    connect(ui->editReminder, &QToolButton::clicked, [this]() {
        emit editOccurred(m_container);
    });

    connect(ui->removeReminder, &QToolButton::clicked, [this]() {
        emit removeOccurred(m_container);
    });

    connect(ui->reminder, &QCheckBox::toggled, [this](bool checked) {
        emit enableToggled(checked, m_container);
    });
}

reminderItemWidget::~reminderItemWidget()
{
    delete ui;
}

void reminderItemWidget::defaultValues()
{
    setItemEnable(true);
    setDateTime(QDateTime::currentDateTime());
    setDescription("Remind me");
    setIsRepeat(false);
    setIsSnooze(false);
    setRepeatType(RepeatType::None);
    setIsCustomSound(false);
    setCustomSoundFilePath("");
    setIsSnooze(false);
    setReminderIsAlarm(false);
    setReminderRepeatStatus("Repeat for none");
}

ItemType reminderItemWidget::getType()
{
    return ItemType::Reminder;
}

QString reminderItemWidget::getId()
{
    if (m_id.count()) {
        return m_id;
    }

    return QString();
}

/**
 * @brief If Alarm enabled then gives a specific time.
 * @example 25/09/2019 00:00 AM when alarm not enabled
 * @return Returns the reminder date time.
 */
QDateTime reminderItemWidget::getDateTime()
{
    return m_dateTime;
}

/**
 * @brief Sets the datetime.
 * @param Given date time specifically.
 */
void reminderItemWidget::setDateTime(QDateTime dt)
{
    m_dateTime = dt;
    ui->reminderDateTime->setText(dt.toString());
}

RepeatType reminderItemWidget::getRepeatType()
{
    return m_repeatType;
}

void reminderItemWidget::setRepeatType(RepeatType rt)
{
    m_repeatType = rt;
}

QString reminderItemWidget::getReminderRepeatStatus()
{
    return ui->reminderRepeat->text();
}

void reminderItemWidget::setReminderRepeatStatus(QString repeatText)
{
    ui->reminderRepeat->setText(repeatText);
}

bool reminderItemWidget::getIsRepeat()
{
    return m_isRepeat;
}

void reminderItemWidget::setIsRepeat(bool repeat)
{
    m_isRepeat = repeat;
}

bool reminderItemWidget::getIsItemEnabled()
{
    return m_itemEnabled;
}

void reminderItemWidget::setItemEnable(bool enable)
{
    m_itemEnabled = enable;
    ui->reminder->setChecked(enable);
}

bool reminderItemWidget::getIsSnooze()
{
    return m_isSnooze;
}

void reminderItemWidget::setIsSnooze(bool snooze)
{
    m_isSnooze = snooze;
}

bool reminderItemWidget::getIsWeekdayEnable(WeekDay week)
{
    return m_weekdays.value(week);
}

void reminderItemWidget::setWeekdayEnable(WeekDay week, bool enable)
{
    m_weekdays.insert(week, enable);
}

QString reminderItemWidget::getDescription()
{
    return m_description;
}

void reminderItemWidget::setDescription(QString str)
{
    m_description = str;
    ui->reminder->setText(str);
}

QString reminderItemWidget::getCustomSoundFilePath()
{
    return m_customSoundFilePath;
}

void reminderItemWidget::setCustomSoundFilePath(QString filePath)
{
    m_customSoundFilePath = filePath;
}

bool reminderItemWidget::getReminderIsAlarm()
{
    return m_isAlarm;
}

void reminderItemWidget::setReminderIsAlarm(bool addAlarm)
{
    m_isAlarm = addAlarm;
}

bool reminderItemWidget::getIsCustomSound()
{
    return m_isCustomSound;
}

void reminderItemWidget::setIsCustomSound(bool custom)
{
    m_isCustomSound = custom;
}

void reminderItemWidget::ring()
{
    emit ringReminderOccurred(m_container);
}

void reminderItemWidget::loadReminder()
{
    if (!m_id.count()) {
        qDebug() << "Can't load the reminder...";
        return;
    }

    setts->beginGroup("All");
    setts->beginGroup(m_id);
    setItemEnable(setts->value("ReminderEnable").toBool());
    setDateTime(setts->value("ReminderDateTime").toDateTime());
    setDescription(setts->value("ReminderDescription").toString());
    bool repeat = setts->value("Repeat").toBool();
    setIsRepeat(repeat);

    QString typeStr = "Repeat for ";
    RepeatType rt = static_cast<RepeatType>(setts->value("RepeatType").toInt());
    setRepeatType(rt);

    if (repeat) {
        if (rt == RepeatType::SpecificWeekDay) {
            for (int i = 0; i < 7; i++) {
                setWeekdayEnable(commonFunc::intToWeekday(i + 1), setts->value("Weekdays/" + QString::number(i)).toBool());
            }

            typeStr = weekdayToString();
        } else if (rt == Weekday) {
            typeStr += "every week this day";
        } else if (rt == Month) {
            typeStr += "every month this day";
        } else if (rt == Year) {
            typeStr += "every year this day";
        } else {
            typeStr += "once";
        }

    } else {
        typeStr += "none";
    }

    setReminderRepeatStatus(typeStr);

    bool isAlarm = setts->value("ReminderIsAlarm").toBool();
    setReminderIsAlarm(isAlarm);

    setIsCustomSound(setts->value("CustomSound").toBool());
    setCustomSoundFilePath(setts->value("CustomSoundFile").toString());
    setIsSnooze(false);
    setts->endGroup();
    setts->endGroup();
    setts->sync();
}

void reminderItemWidget::saveReminder()
{
    if (!m_id.count()) {
        qDebug() << "Can't save the reminder...";
        return;
    }

    setts->beginGroup("All");

    setts->beginGroup(m_id);
    setts->setValue("ReminderEnable", getIsItemEnabled());
    setts->setValue("ReminderDateTime", getDateTime());
    setts->setValue("ReminderDescription", getDescription());
    setts->setValue("Repeat", getIsRepeat());

    setts->setValue("ReminderIsAlarm", getReminderIsAlarm());

    if (getReminderIsAlarm()) {
        setts->setValue("CustomSound", getIsCustomSound());
        setts->setValue("CustomSoundFile", getCustomSoundFilePath());
    }

    if (getIsRepeat()) {
        RepeatType rt = getRepeatType();
        setts->setValue("RepeatType", rt);

        if (rt == SpecificWeekDay) {
            for (int i = 0; i < 7; i++) {
                setts->setValue("Weekdays/" + QString::number(i), getIsWeekdayEnable(commonFunc::intToWeekday(i + 1)));
            }
        }
    }

    setts->endGroup();
    setts->endGroup();
    setts->sync();
}

void reminderItemWidget::deleteReminder()
{
    if (!m_id.count()) {
        qDebug() << "Can't delete the reminder...";
        return;
    }

    int count = setts->value("ReminderCount").toInt();
    setts->setValue("ReminderCount", count - 1);
    setts->beginGroup("All");
    setts->remove(m_id);
    setts->endGroup();
    setts->sync();
}

QString reminderItemWidget::weekdayToString()
{
    return commonFunc::weekdaysToString(m_weekdays);
}
