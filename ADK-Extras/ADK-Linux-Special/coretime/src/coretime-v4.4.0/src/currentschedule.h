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

#ifndef CURRENTSCHEDULE_H
#define CURRENTSCHEDULE_H

#include <QDialog>

class QMediaPlayer;

namespace Ui {
    class currentschedule;
}

class currentschedule : public QDialog {

    Q_OBJECT

public:
    explicit currentschedule(QWidget *parent = nullptr);
    ~currentschedule();

    void setProperty(QString windowTitle, QString scheduleTime, QString descText);
    void setAudio(QString filePath);
    void setIsAlarm(bool state);

private:
    Ui::currentschedule *ui;
    QMediaPlayer *audio;
};

#endif // CURRENTSCHEDULE_H
