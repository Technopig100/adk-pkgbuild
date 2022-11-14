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

#include "alarmitemwidget.h"
#include "ui_alarmitemwidget.h"


alarmItemWidget::alarmItemWidget(QString id, QSettings *sett, QListWidgetItem *container, QWidget *parent) :
    AbstractScheduleItem(parent)
  , ui(new Ui::alarmItemWidget)
{
    ui->setupUi(this);

    m_container = container;
    m_id = id;
    setts = sett;

	settings smi;
	ui->editAlarm->setIconSize(smi.getValue("CoreApps", "ListViewIconSize") - QSize(8,8));
	ui->removeAlarm->setIconSize(smi.getValue("CoreApps", "ListViewIconSize") - QSize(8,8));

    connect(ui->editAlarm, &QToolButton::clicked, [this]() {
        emit editOccurred(m_container);
    });

    connect(ui->removeAlarm, &QToolButton::clicked, [this]() {
        emit removeOccurred(m_container);
    });

    connect(ui->alarm, &QCheckBox::toggled, [this](bool state) {
        emit enableToggled(state, m_container);
    });
}

alarmItemWidget::~alarmItemWidget()
{
    m_weekdays.clear();
    delete ui;
}

void alarmItemWidget::defaultValues()
{
    setItemEnable(true);
    setDateTime(QDateTime::currentDateTime());
    setDescription("Alarm");
    setIsRepeat(false);
    setIsSnooze(false);
    setIsCustomSound(false);
    setCustomSoundFilePath("");
    setAlarmStatus("Alarm, Once");
    setRepeatType(RepeatType::None);
    setIsSnooze(false);
}

ItemType alarmItemWidget::getType()
{
    return Alarm;
}

QString alarmItemWidget::getId()
{
    return m_id;
}

QDateTime alarmItemWidget::getDateTime()
{
    return m_dateTime;
}

void alarmItemWidget::setDateTime(QDateTime dateTime)
{
    m_dateTime = dateTime;
    ui->alarm->setText(m_dateTime.toString("hh:mm AP"));
}

bool alarmItemWidget::getReminderIsAlarm()
{
    return false;
}

RepeatType alarmItemWidget::getRepeatType()
{
    return m_repeatType;
}

void alarmItemWidget::setRepeatType(RepeatType rt)
{
    m_repeatType = rt;
}

QString alarmItemWidget::getAlarmStatus()
{
    return ui->alarmStatus->text();
}

QString alarmItemWidget::getAlarmLabel()
{
    QString str = ui->alarmStatus->text();

    if (str.contains(", ")) {
        str = str.split(", ").at(0);
    }

    return str;
}

void alarmItemWidget::setAlarmStatus(QString text)
{
    ui->alarmStatus->setText(text);
    setDescription(getAlarmLabel());
}

bool alarmItemWidget::getIsRepeat()
{
    return m_isRepeat;
}

void alarmItemWidget::setIsRepeat(bool repeat)
{
    m_isRepeat = repeat;
}

bool alarmItemWidget::getIsItemEnabled()
{
    return m_itemEnabled;
}

void alarmItemWidget::setItemEnable(bool enable)
{
    m_itemEnabled = enable;
    ui->alarm->setChecked(enable);
}

bool alarmItemWidget::getIsSnooze()
{
    return m_isSnooze;
}

void alarmItemWidget::setIsSnooze(bool snooze)
{
    m_isSnooze = snooze;
}

bool alarmItemWidget::getIsWeekdayEnable(WeekDay week)
{
    return m_weekdays.value(week);
}

void alarmItemWidget::setWeekdayEnable(WeekDay week, bool enable)
{
    m_weekdays.insert(week, enable);
}

QString alarmItemWidget::getCustomSoundFilePath()
{
    return m_customSoundFilePath;
}

void alarmItemWidget::setCustomSoundFilePath(QString filePath)
{
    m_customSoundFilePath = filePath;
}

bool alarmItemWidget::getIsCustomSound()
{
    return m_isCustomSound;
}

void alarmItemWidget::setIsCustomSound(bool custom)
{
    m_isCustomSound = custom;
}

QString alarmItemWidget::getDescription()
{
    return m_description;
}

void alarmItemWidget::setDescription(QString descriptiton)
{
    m_description = descriptiton;
}

void alarmItemWidget::ring()
{
    emit ringAlarmOccured(m_container);
}

void alarmItemWidget::loadAlarm()
{
    if (!m_id.count()) {
        qDebug() << "Can't load the alarm...";
        return;
    }

    setts->beginGroup(m_id);
    setItemEnable(setts->value("AlarmEnable").toBool());
	setDateTime(setts->value("AlarmTime").toDateTime());
    QString alarmLabel = setts->value("AlarmLabel").toString();
    setAlarmStatus(alarmLabel);
    bool customSound = setts->value("CustomSound").toBool();
    setIsCustomSound(customSound);

    if (customSound) {
        setCustomSoundFilePath(setts->value("CustomSoundFile").toString());
    } else {
        setCustomSoundFilePath("");
    }

    bool repeat = setts->value("Repeat").toBool();
    setIsRepeat(repeat);

    setIsSnooze(false);

    QString typestr = "";
    RepeatType rt = static_cast<RepeatType>(setts->value("RepeatType").toInt());
    setRepeatType(rt);

    if (repeat) {
        for (int i = 0; i < 7; i++) {
            setWeekdayEnable(commonFunc::intToWeekday(i + 1), setts->value("Weekdays/" + QString::number(i)).toBool());
        }

        typestr = commonFunc::weekdaysToString(m_weekdays);
        qDebug() << "Type returned " << typestr;
    } else {
        typestr = "Once";
    }

    ui->alarmStatus->setText(alarmLabel + ", " + typestr);
    setts->endGroup();
    setts->sync();
}

void alarmItemWidget::saveAlarm()
{
    if (!m_id.count()) {
        qDebug() << "Can't save the alarm...";
        return;
    }

    setts->beginGroup(m_id);
    setts->setValue("AlarmEnable", getIsItemEnabled());
    setts->setValue("AlarmTime", getDateTime());
    setts->setValue("AlarmLabel", getDescription());
    setts->setValue("CustomSound", getIsCustomSound());
    setts->setValue("CustomSoundFile", getCustomSoundFilePath());
    setts->setValue("Repeat", getIsRepeat());
    setts->setValue("RepeatType", getRepeatType());

    if (getIsRepeat()) {
        for (int i = 0; i < 7; i++) {
            setts->setValue("Weekdays/" + QString::number(i), getIsWeekdayEnable(commonFunc::intToWeekday(i + 1)));
        }
    }

    setts->endGroup();
    setts->sync();
}

void alarmItemWidget::deleteAlarm()
{
    if (!m_id.count()) {
        qDebug() << "Can't delete the alarm...";
        return;
    }

    int count = setts->value("AlarmCount").toInt();
    setts->setValue("AlarmCount", count - 1);
    setts->remove(m_id);
    setts->sync();
}

QString alarmItemWidget::weekdayToString()
{
    return commonFunc::weekdaysToString(m_weekdays);
}
