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

#include <QSettings>
#include <QMessageBox>
#include <QFileDialog>
#include <QListWidgetItem>
#include <QScroller>

#include <cprime/messageengine.h>

#include "currentschedule.h"
#include "alarmitemwidget.h"
#include "alarmwidget.h"
#include "ui_alarmwidget.h"


static alarmWidget *alarmInstance = nullptr;

alarmWidget::alarmWidget(QWidget *parent) :QWidget(parent)
  , ui(new Ui::alarmWidget)
{
    ui->setupUi(this);

    newAlarm = false;
    setts = new QSettings("coreapps", "alarm");

    ui->alarmList->setStyleSheet("QListView {background-color: transparent;}");
    ui->configure->setVisible(false);

    QScroller::grabGesture(ui->alarmList, QScroller::LeftMouseButtonGesture);

	settings smi;
	ui->addAlarm->setIconSize(smi.getValue("CoreApps", "ToolBarIconSize"));

    int count = setts->value("AlarmCount").toInt();

    if (count) {
        loadAlarmItems();
        ui->pages->setCurrentIndex(1);
    } else {
        ui->pages->setCurrentIndex(0);
    }


    ui->addAlarm->setIconSize(smi.getValue("CoreApps", "ToolsIconSize"));

    connect(ui->addAlarm, &QToolButton::clicked, this, &alarmWidget::addAlarmItem);
}

alarmWidget::~alarmWidget()
{
	delete setts;
    delete ui;
}

alarmWidget *alarmWidget::instance(QWidget *parent)
{
    if (!alarmInstance) {
        alarmInstance = new alarmWidget(parent);
    }

    return alarmInstance;
}

void alarmWidget::changeState(bool state)
{
    ui->addAlarm->setVisible(!state);
    ui->configure->setVisible(state);
    ui->alarmList->setEnabled(!state);
    ui->configure->setFocus();
}

bool alarmWidget::checkConfig()
{
    QString errorMsg;
    QWidget *errorWidget = nullptr;

    if (ui->alarmSound->isChecked() && (ui->alarmSoundFile->text().count() == 0)) {
        errorMsg = "Please specify a sound file path";
        errorWidget = ui->alarmSoundFile;
    } else if (ui->alarmRepeat->isChecked()) {
        bool anyChecked = false;
        QObjectList objL = ui->alarmRepeat->children();

        Q_FOREACH (QObject *obj, objL) {
            QToolButton *c = static_cast<QToolButton *>(obj);

            if (c->isChecked()) {
                anyChecked = true;
            }
        }

        if (!anyChecked) {
            errorMsg = "Please select any weekday for repeat";
            errorWidget = ui->alarmRepeat;
        }
    }

    if (errorWidget) {
        QMessageBox msgBox;
        msgBox.setText(errorMsg);
        msgBox.exec();

        errorWidget->setFocus();

        return false;
    }

    return true;
}

void alarmWidget::addAlarmItem()
{
    newAlarm = true;
    // Create a temporary alarmItemWidget
    alarmItemWidget *temp = new alarmItemWidget(commonFunc::createID(), setts, nullptr);
    temp->defaultValues();

    // Load the alarmItemWidget to configure
    alarmToConfig(temp);
}

void alarmWidget::loadAlarmItems()
{
    int count = setts->value("AlarmCount").toInt();

    QStringList list = setts->childGroups();

    // Remove the general group
    list.removeOne("General");

    for (int i = 0; i < count; i++) {
        QListWidgetItem *item = new QListWidgetItem;
        alarmItemWidget *itemWidget = new alarmItemWidget(list.at(i), setts, item, this);
        itemWidget->loadAlarm(/*i*/);

        item->setSizeHint(QSize(itemWidget->sizeHint()));

        ui->alarmList->addItem(item);
        ui->alarmList->setItemWidget(item, itemWidget);

        if (!itemWidget->getIsRepeat() && !itemWidget->getIsItemEnabled()/*itemWidget->getAlarmType() == alarmItemWidget::Once*/) {
            itemWidget->setItemEnable(false);
        } else {
            m_alarmQueue.addScheduleItem(itemWidget);
        }

        connect(itemWidget, &alarmItemWidget::editOccurred, this, &alarmWidget::editAlarm);
        connect(itemWidget, &alarmItemWidget::removeOccurred, this, &alarmWidget::removeAlarm);
        connect(itemWidget, &alarmItemWidget::enableToggled, this, &alarmWidget::alarmItemToggled);
        connect(itemWidget, &alarmItemWidget::ringAlarmOccured, this, &alarmWidget::ringAlarm);
    }
}

void alarmWidget::alarmToConfig(alarmItemWidget *itemWidget)
{
    changeState(true);

    ui->alarmLabel->setText(itemWidget->getAlarmLabel());
    ui->alarmDateTime->setTime(itemWidget->getDateTime().time());
    ui->alarmSound->setChecked(itemWidget->getIsCustomSound());
    ui->alarmSoundFile->setText(itemWidget->getCustomSoundFilePath());
    bool repeat = itemWidget->getIsRepeat();
    ui->alarmRepeat->setChecked(repeat);

    if (repeat) {
        ui->r_fri->setChecked(itemWidget->getIsWeekdayEnable(Friday));
        ui->r_sat->setChecked(itemWidget->getIsWeekdayEnable(Saturday));
        ui->r_sun->setChecked(itemWidget->getIsWeekdayEnable(Sunday));
        ui->r_mon->setChecked(itemWidget->getIsWeekdayEnable(Monday));
        ui->r_tue->setChecked(itemWidget->getIsWeekdayEnable(Tuesday));
        ui->r_wed->setChecked(itemWidget->getIsWeekdayEnable(Wednesday));
        ui->r_thu->setChecked(itemWidget->getIsWeekdayEnable(Thursday));
    }
}

void alarmWidget::configToAlarm(alarmItemWidget *itemWidget)
{
	itemWidget->setItemEnable(true);

	QDateTime dt = QDateTime(QDate::currentDate(), ui->alarmDateTime->dateTime().time());
	if (dt.time() < QTime::currentTime())
		dt = dt.addDays(1);

	itemWidget->setDateTime(dt);
    itemWidget->setIsCustomSound(ui->alarmSound->isChecked());
    itemWidget->setCustomSoundFilePath(ui->alarmSoundFile->text());
    bool repeat = ui->alarmRepeat->isChecked();
    itemWidget->setIsRepeat(repeat);
    itemWidget->setRepeatType(repeat ? RepeatType::Weekday : RepeatType::None);
    QString typestr = "";

    if (repeat) {
        itemWidget->setWeekdayEnable(Monday, ui->r_mon->isChecked());
        itemWidget->setWeekdayEnable(Tuesday, ui->r_tue->isChecked());
        itemWidget->setWeekdayEnable(Wednesday, ui->r_wed->isChecked());
        itemWidget->setWeekdayEnable(Thursday, ui->r_thu->isChecked());
        itemWidget->setWeekdayEnable(Friday, ui->r_fri->isChecked());
        itemWidget->setWeekdayEnable(Saturday, ui->r_sat->isChecked());
        itemWidget->setWeekdayEnable(Sunday, ui->r_sun->isChecked());
        typestr = itemWidget->weekdayToString();
    } else {
        typestr = "Once";
    }

    QString status = ui->alarmLabel->text() + ", " + typestr;

    itemWidget->setAlarmStatus(status);
}

void alarmWidget::ringAlarm(QListWidgetItem *item)
{
    alarmItemWidget *alarm = static_cast<alarmItemWidget *>(ui->alarmList->itemWidget(item));

    if (!alarm) {
        qDebug() << "ScheduleQueue : Error : Invalid casting to 'alarmItemWidget'.";
        return;
    }

    QString soundFilePath = commonFunc::defaultAudio();

    if (alarm->getIsCustomSound()) {
        soundFilePath = alarm->getCustomSoundFilePath();
    }

    currentschedule *sche = new currentschedule;

    if (soundFilePath.count()) {
        sche->setAudio(soundFilePath);
    } else {
        qDebug() << "No valid sound file found.";
    }

    sche->setIsAlarm(true);
    sche->setProperty("Alarm", alarm->getDateTime().toString("hh:mm AP"), alarm->getDescription());
    int code = sche->exec();
    int c = code;

    if (!c) { // Close schedule normally
        qDebug() << "Info " << alarm->getIsRepeat() << alarm->getIsSnooze() << alarm->getAlarmStatus();

        if (!alarm->getIsRepeat()) {
            alarm->setItemEnable(false);
        }

        if (alarm->getIsSnooze()) {
            alarm->setAlarmStatus(alarm->getAlarmStatus().remove(" Snoozed"));
            alarm->setIsSnooze(false);
        }

        m_alarmQueue.removeScheduleItem(alarm);
    } else { // Snooze the schedule(alarm)
        alarm->setIsSnooze(true);
        m_alarmQueue.addScheduleItem(alarm);
        alarm->setAlarmStatus(alarm->getAlarmStatus().remove(" Snoozed") + " Snoozed");
    }
}

void alarmWidget::editAlarm(QListWidgetItem *item)
{
    alarmItemWidget *itemWidget = static_cast<alarmItemWidget *>(ui->alarmList->itemWidget(item));

    if (!itemWidget) {
        return;
    }

    alarmToConfig(itemWidget);
    ui->alarmList->setCurrentItem(item);
}

void alarmWidget::removeAlarm(QListWidgetItem *item)
{
    alarmItemWidget *itemWidget = static_cast<alarmItemWidget *>(ui->alarmList->itemWidget(item));

    if (!itemWidget) {
        return;
    }

    m_alarmQueue.removeScheduleItem(itemWidget);

    itemWidget->deleteAlarm();
    itemWidget->deleteLater();
    delete item;
}

void alarmWidget::alarmItemToggled(bool enable, QListWidgetItem *item)
{
    alarmItemWidget *itemWidget = static_cast<alarmItemWidget *>(ui->alarmList->itemWidget(item));

    if (!itemWidget) {
        return;
    }

    QString id = itemWidget->getId();

    if (!id.count()) {
        qDebug() << "Can't enable. NO ID FOUND.";
        return;
    }

    setts->setValue(id + "/AlarmEnable", enable);
    setts->sync();

    if (enable) {
        m_alarmQueue.addScheduleItem(itemWidget);
    } else {
        m_alarmQueue.removeScheduleItem(itemWidget);
    }
}

void alarmWidget::on_browseAlarmSound_clicked()
{
    QStringList filters;
    filters << ("MP3 files (*.mp3)");
    filters << ("OGG files (*.ogg");
    filters << ("WAV files (*.wav)");
    filters << ("All files (*)");

    QFileDialog fileDlg(this);
    fileDlg.setNameFilters(filters);

    if (fileDlg.exec() == QDialog::Accepted) {
        QString soundFile(QDir::toNativeSeparators(fileDlg.selectedFiles().first()));
        ui->alarmSoundFile->setText(soundFile);
    }
}

void alarmWidget::on_done_clicked()
{
    bool check = checkConfig();

    if (!check) {
        qDebug() << "Problem at config...";
        return;
    }

    int count = setts->value("AlarmCount").toInt();

    if (newAlarm) {
        QListWidgetItem *item = new QListWidgetItem;
        alarmItemWidget *itemWidget = new alarmItemWidget(commonFunc::createID(), setts, item, this);

        configToAlarm(itemWidget);

        itemWidget->saveAlarm();

        setts->setValue("AlarmCount", count + 1);

        item->setSizeHint(QSize(itemWidget->sizeHint()));

        ui->alarmList->addItem(item);
        ui->alarmList->setItemWidget(item, itemWidget);

        m_alarmQueue.addScheduleItem(itemWidget);

        connect(itemWidget, &alarmItemWidget::editOccurred, this, &alarmWidget::editAlarm);
        connect(itemWidget, &alarmItemWidget::removeOccurred, this, &alarmWidget::removeAlarm);
        connect(itemWidget, &alarmItemWidget::enableToggled, this, &alarmWidget::alarmItemToggled);
        connect(itemWidget, &alarmItemWidget::ringAlarmOccured, this, &alarmWidget::ringAlarm);

        newAlarm = false;
    } else {
        alarmItemWidget *itemWidget = static_cast<alarmItemWidget *>(ui->alarmList->itemWidget(ui->alarmList->currentItem()));
        itemWidget->setIsSnooze(false);
        configToAlarm(itemWidget);
        itemWidget->saveAlarm();
        m_alarmQueue.addScheduleItem(itemWidget);
    }

    changeState(false);
    ui->pages->setCurrentIndex(1);
	CPrime::MessageEngine::showMessage("org.cubocore.CoreTime", "CoreTime", "Alarm Added", "A new alarm added");
}

void alarmWidget::on_cancel_clicked()
{
    changeState(false);
}
