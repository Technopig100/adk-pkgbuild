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

#include <QTimer>
#include <QTime>
#include <QFile>
#include <QMediaPlayer>

#include "currentschedule.h"
#include "ui_currentschedule.h"


currentschedule::currentschedule(QWidget *parent) :QDialog(parent),ui(new Ui::currentschedule)
{
    ui->setupUi(this);
    ui->currentTime->setText(QTime::currentTime().toString("hh:mm:ss AP"));

    QTimer *timer = new QTimer(this);
    timer->start(1000);

    connect(timer, &QTimer::timeout, [this]() {
        ui->currentTime->setText(QTime::currentTime().toString("hh:mm:ss AP"));
    });

    connect(this, &currentschedule::finished, [timer, this]() {
        audio->stop();
        timer->stop();
    });

    connect(ui->snooze, &QPushButton::clicked, this, &QDialog::accept);
    connect(ui->close, &QPushButton::clicked, this, &QDialog::reject);
}

currentschedule::~currentschedule()
{
    audio->deleteLater();
    delete ui;
}

void currentschedule::setProperty(QString windowTitle, QString scheduleTime, QString descText)
{
    setWindowTitle(windowTitle);
    setWindowIcon(QIcon::fromTheme("coretime"));
    ui->scheduleTime->setText(scheduleTime);
    ui->text->setText(descText);
}

void currentschedule::setAudio(QString filePath)
{
    audio = new QMediaPlayer(this);

    if (!QFile::exists(filePath)) {
        qDebug() << "func(CurrentSchedule::setAudio) : Error : Invalid audio file.";
        return;
    }

    audio->setMedia(QUrl::fromLocalFile(filePath));
    audio->setVolume(80);
    audio->setAudioRole(QAudio::AlarmRole);

    connect(audio, &QMediaPlayer::mediaStatusChanged, [filePath, this](QMediaPlayer::MediaStatus state) {
        if (state == QMediaPlayer::EndOfMedia) {
            audio->setMedia(QUrl::fromLocalFile(filePath));
            audio->play();
        }
    });
    audio->play();
}

void currentschedule::setIsAlarm(bool state)
{
    ui->snooze->setVisible(state);
}
