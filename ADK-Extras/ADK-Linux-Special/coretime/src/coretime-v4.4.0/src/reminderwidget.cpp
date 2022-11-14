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
#include <QFileDialog>
#include <QMessageBox>
#include <QListWidgetItem>
#include <QScroller>

#include <cprime/messageengine.h>

#include "currentschedule.h"
#include "reminderitemwidget.h"
#include "reminderwidget.h"
#include "ui_reminderwidget.h"


static reminderWidget *reminderInstance = nullptr;

reminderWidget::reminderWidget(QWidget *parent) : QWidget(parent)
  , ui(new Ui::reminderWidget)
{
    ui->setupUi(this);

    newReminder = false;
    setts = new QSettings("coreapps", "reminder");

    ui->reminderList->setStyleSheet("QListView {background-color: transparent;}");
    ui->weeks->setVisible(false);
    ui->configure->setVisible(false);

    QScroller::grabGesture(ui->reminderList, QScroller::LeftMouseButtonGesture);

	settings smi;
	ui->addReminder->setIconSize(smi.getValue("CoreApps", "ToolBarIconSize"));

    int count = setts->value("ReminderCount").toInt();

    if (count) {
        // Load all the reminders
        loadReminderItems();
        ui->pages->setCurrentIndex(1);
    } else {
        // Show the welcome page
        ui->pages->setCurrentIndex(0);
    }

    ui->addReminder->setIconSize(smi.getValue("CoreApps", "ToolsIconSize"));

    connect(ui->addReminder, &QToolButton::clicked, this, &reminderWidget::addReminderItem);
}

reminderWidget::~reminderWidget()
{
	delete setts;
    delete ui;
}

reminderWidget *reminderWidget::instance(QWidget *parent)
{
    if (!reminderInstance) {
        reminderInstance = new reminderWidget(parent);
    }

    return reminderInstance;
}

void reminderWidget::changeState(bool state)
{
    ui->addReminder->setVisible(!state);
    ui->configure->setVisible(state);
    ui->reminderList->setEnabled(!state);
    ui->configure->setFocus();
}

bool reminderWidget::checkConfig()
{
    QString errorMsg;
    QWidget *errorWidget = nullptr;

    if (ui->reminderSound->isChecked() && (ui->reminderSoundFile->text().count() == 0)) {
        errorMsg = "Please specify a sound file path";
        errorWidget = ui->reminderSoundFile;
    } else if (ui->reminderRepeat->isChecked() && ui->r_specific->isChecked()) {
        bool anyChecked = false;
        QObjectList objL = ui->weeks->children();

        Q_FOREACH (QObject *obj, objL) {
            QToolButton *c = static_cast<QToolButton *>(obj);

            if (c->isChecked()) {
                anyChecked = true;
            }
        }

        if (!anyChecked) {
            errorMsg = "Please select any weekday for repeat";
            errorWidget = ui->weeks;
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

void reminderWidget::addReminderItem()
{
    newReminder = true;

    // Create a temporary reminderItemWidget
    reminderItemWidget *temp = new reminderItemWidget(commonFunc::createID(), setts, nullptr);
    temp->defaultValues();

    // Load the reminderItemWidget to configure
    reminderToConfig(temp);
}

void reminderWidget::loadReminderItems()
{
    int count = setts->value("ReminderCount").toInt();

    setts->beginGroup("All");
    QStringList list = setts->childGroups();
    setts->endGroup();

    for (int i = 0; i < count; i++) {
        QListWidgetItem *item = new QListWidgetItem;
        reminderItemWidget *itemWidget = new reminderItemWidget(list.at(i), setts, item, this);
        itemWidget->loadReminder();
        item->setSizeHint(QSize(itemWidget->sizeHint()));

        ui->reminderList->addItem(item);
        ui->reminderList->setItemWidget(item, itemWidget);

        if (!itemWidget->getIsRepeat() && !itemWidget->getIsItemEnabled()) {
            itemWidget->setItemEnable(false);
        } else {
            m_reminderQueue.addScheduleItem(itemWidget);
        }

        connect(itemWidget, &reminderItemWidget::editOccurred, this, &reminderWidget::editReminder);
        connect(itemWidget, &reminderItemWidget::removeOccurred, this, &reminderWidget::removeReminder);
        connect(itemWidget, &reminderItemWidget::enableToggled, this, &reminderWidget::reminderEnableToggled);
        connect(itemWidget, &reminderItemWidget::ringReminderOccurred, this, &reminderWidget::ringReminder);
    }
}

void reminderWidget::reminderToConfig(reminderItemWidget *itemWidget)
{
    changeState(true);

    QDateTime dt = itemWidget->getDateTime();
    ui->reminderDate->setDate(dt.date());
    ui->reminderDescription->setText(itemWidget->getDescription());

    bool repeat = itemWidget->getIsRepeat();
    ui->reminderRepeat->setChecked(repeat);

    if (repeat) {
        RepeatType rt = itemWidget->getRepeatType();

        if (rt == Year) {
            ui->r_year->setChecked(true);
        } else if (rt == Month) {
            ui->r_month->setChecked(true);
        } else if (rt == Weekday) {
            ui->r_weekday->setChecked(true);
        } else if (rt == SpecificWeekDay) {
            ui->r_specific->setChecked(true);
            ui->r_fri->setChecked(itemWidget->getIsWeekdayEnable(Friday));
            ui->r_sat->setChecked(itemWidget->getIsWeekdayEnable(Saturday));
            ui->r_sun->setChecked(itemWidget->getIsWeekdayEnable(Sunday));
            ui->r_mon->setChecked(itemWidget->getIsWeekdayEnable(Monday));
            ui->r_tue->setChecked(itemWidget->getIsWeekdayEnable(Tuesday));
            ui->r_wed->setChecked(itemWidget->getIsWeekdayEnable(Wednesday));
            ui->r_thu->setChecked(itemWidget->getIsWeekdayEnable(Thursday));
        }
    }

    // Alarm part
    ui->reminderAlarm->setChecked(itemWidget->getReminderIsAlarm());
    ui->reminderSound->setChecked(itemWidget->getIsCustomSound());
    ui->reminderSoundFile->setText(itemWidget->getCustomSoundFilePath());
    ui->reminderTime->setTime(dt.time());
}

void reminderWidget::configToReminder(reminderItemWidget *itemWidget)
{
    itemWidget->setItemEnable(true);
    bool isAlarm = ui->reminderAlarm->isChecked();

    QDateTime dt;

    if (isAlarm) {
        dt = QDateTime(ui->reminderDate->date(), ui->reminderTime->time());
    } else {
        dt = QDateTime(ui->reminderDate->date(), QTime(0, 0, 0));
    }

    itemWidget->setDateTime(dt);
    itemWidget->setDescription(ui->reminderDescription->text());
    itemWidget->setIsRepeat(ui->reminderRepeat->isChecked());

    // Repeat stuff
    QString typeStr = "Repeat for ";

    if (ui->reminderRepeat->isChecked()) {
        if (ui->r_year->isChecked()) {
            itemWidget->setRepeatType(Year);
            typeStr += "every year this day";
        } else if (ui->r_month->isChecked()) {
            itemWidget->setRepeatType(Month);
            typeStr += "every month this day";
        } else if (ui->r_weekday->isChecked()) {
            itemWidget->setRepeatType(Weekday);
            typeStr += "every week this day";
        } else if (ui->r_specific->isChecked()) {
            itemWidget->setRepeatType(SpecificWeekDay);
            itemWidget->setWeekdayEnable(Monday, ui->r_mon->isChecked());
            itemWidget->setWeekdayEnable(Tuesday, ui->r_tue->isChecked());
            itemWidget->setWeekdayEnable(Wednesday, ui->r_wed->isChecked());
            itemWidget->setWeekdayEnable(Thursday, ui->r_thu->isChecked());
            itemWidget->setWeekdayEnable(Friday, ui->r_fri->isChecked());
            itemWidget->setWeekdayEnable(Saturday, ui->r_sat->isChecked());
            itemWidget->setWeekdayEnable(Sunday, ui->r_sun->isChecked());
            typeStr += itemWidget->weekdayToString();
        }
    } else {
        typeStr += "None";
    }

    itemWidget->setReminderRepeatStatus(typeStr);

    // Alarm stuff
    itemWidget->setReminderIsAlarm(isAlarm);
    itemWidget->setIsCustomSound(ui->reminderSound->isChecked());
    itemWidget->setCustomSoundFilePath(ui->reminderSoundFile->text());
}

void reminderWidget::ringReminder(QListWidgetItem *item)
{
    reminderItemWidget *reminder = static_cast<reminderItemWidget *>(ui->reminderList->itemWidget(item));

    if (!reminder) {
        qDebug() << "ScheduleQueue : Error : Invalid casting to 'alarmItemWidget'.";
        return;
    }

    // TODO If reminder not have alarm then don't use any sound
    QString soundFilePath = commonFunc::defaultAudio();

    if (reminder->getIsCustomSound()) {
        soundFilePath = reminder->getCustomSoundFilePath();
    }

    currentschedule *sche = new currentschedule;

    if (soundFilePath.count()) {
        sche->setAudio(soundFilePath);
    } else {
        qDebug() << "No valid sound file found.";
    }

    if (reminder->getReminderIsAlarm()) {
        sche->setIsAlarm(true);
    } else {
        sche->setIsAlarm(false);
    }

    sche->setProperty("Reminder", reminder->getDateTime().toString(), reminder->getDescription());
    int exitCode = sche->exec();
    qDebug() << "Schedule exit code " << exitCode;

    if (!exitCode) { // Close Schedule normally
        if (!reminder->getIsRepeat()) {
            reminder->setItemEnable(false);
        }

        if (reminder->getIsSnooze()) {
            reminder->setReminderRepeatStatus(reminder->getReminderRepeatStatus().remove(" Snoozed"));
            reminder->setIsSnooze(false);
        }

        m_reminderQueue.removeScheduleItem(reminder);
    } else { // Snooze happens
        reminder->setIsSnooze(true);
        m_reminderQueue.addScheduleItem(reminder);
        reminder->setReminderRepeatStatus(reminder->getReminderRepeatStatus().remove(" Snoozed") + " Snoozed");
    }
}

void reminderWidget::editReminder(QListWidgetItem *item)
{
    reminderItemWidget *itemWidget = static_cast<reminderItemWidget *>(ui->reminderList->itemWidget(item));

    if (!itemWidget) {
        return;
    }

    reminderToConfig(itemWidget);
    ui->reminderList->setCurrentItem(item);
}

void reminderWidget::removeReminder(QListWidgetItem *item)
{
    reminderItemWidget *itemWidget = static_cast<reminderItemWidget *>(ui->reminderList->itemWidget(item));

    if (!itemWidget) {
        return;
    }

    emit reminderDeleted(itemWidget->getDateTime().date());

    m_reminderQueue.removeScheduleItem(itemWidget);

    itemWidget->deleteReminder();
    itemWidget->deleteLater();
    delete item;
}

void reminderWidget::reminderEnableToggled(bool state, QListWidgetItem *item)
{
    reminderItemWidget *itemWidget = static_cast<reminderItemWidget *>(ui->reminderList->itemWidget(item));

    if (!itemWidget) {
        return;
    }

    QString id = itemWidget->getId();

    if (!id.count()) {
        qDebug() << "Can't enable. NO ID FOUND.";
        return;
    }

    setts->setValue("All/" + id + "/ReminderEnable", state);
    setts->sync();

    if (state) {
        m_reminderQueue.addScheduleItem(itemWidget);
    } else {
        m_reminderQueue.removeScheduleItem(itemWidget);
    }
}

void reminderWidget::on_r_specific_toggled(bool checked)
{
    ui->weeks->setVisible(checked);
}

void reminderWidget::on_done_clicked()
{
    bool check = checkConfig();

    if (!check) {
        qDebug() << "Problem at config...";
        return;
    }

    int count = setts->value("ReminderCount").toInt();

    reminderItemWidget *itemWidget;
    QDate temp;
    bool newOne = false;

    if (newReminder) {
        QListWidgetItem *item = new QListWidgetItem;
        itemWidget = new reminderItemWidget(commonFunc::createID(), setts, item, this);

        configToReminder(itemWidget);

        itemWidget->saveReminder(/*id*/);

        setts->setValue("ReminderCount", count + 1);

        item->setSizeHint(itemWidget->sizeHint());

        ui->reminderList->addItem(item);
        ui->reminderList->setItemWidget(item, itemWidget);

        m_reminderQueue.addScheduleItem(itemWidget);

        connect(itemWidget, &reminderItemWidget::editOccurred, this, &reminderWidget::editReminder);
        connect(itemWidget, &reminderItemWidget::removeOccurred, this, &reminderWidget::removeReminder);
        connect(itemWidget, &reminderItemWidget::enableToggled, this, &reminderWidget::reminderEnableToggled);
        connect(itemWidget, &reminderItemWidget::ringReminderOccurred, this, &reminderWidget::ringReminder);

        newReminder = false;
        newOne = true;
    } else {
        itemWidget = static_cast<reminderItemWidget *>(ui->reminderList->itemWidget(ui->reminderList->currentItem()));
        itemWidget->setIsSnooze(false);
        temp = itemWidget->getDateTime().date();
        configToReminder(itemWidget);

        itemWidget->saveReminder();
        m_reminderQueue.addScheduleItem(itemWidget);
    }

    QDate d = itemWidget->getDateTime().date();
    CalendarEvent ce;
    ce.type = ReminderDate;
    ce.repeat = itemWidget->getIsRepeat();
    ce.rType = itemWidget->getRepeatType();
    QMap <WeekDay, bool> wd;
    wd[Sunday] = itemWidget->getIsWeekdayEnable(Sunday);
    wd[Monday] = itemWidget->getIsWeekdayEnable(Monday);
    wd[Tuesday] = itemWidget->getIsWeekdayEnable(Tuesday);
    wd[Wednesday] = itemWidget->getIsWeekdayEnable(Wednesday);
    wd[Thursday] = itemWidget->getIsWeekdayEnable(Thursday);
    wd[Friday] = itemWidget->getIsWeekdayEnable(Friday);
    wd[Saturday] = itemWidget->getIsWeekdayEnable(Saturday);
    ce.wd = wd;
    ce.description = itemWidget->getDescription();

    if (newOne) {
        emit reminderAdded(d, ce);
    } else {
        emit reminderEdited(temp, d, ce);
    }

    changeState(false);
    ui->pages->setCurrentIndex(1);
	CPrime::MessageEngine::showMessage("org.cubocore.CoreTime", "CoreTime", "Reminder Added", "A new reminder added");
}

void reminderWidget::on_cancel_clicked()
{
    changeState(false);
}

void reminderWidget::on_browseReminderSound_clicked()
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
        ui->reminderSoundFile->setText(soundFile);
    }
}
