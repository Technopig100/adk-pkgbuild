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

#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QTime>
#include <QElapsedTimer>
#include <QTimerEvent>


class StopWatch : public QObject {

    Q_OBJECT

public:
    // Refresh time
    enum class RefreshRate : int {
        Milliseconds = 1, // Stopwatch refreshed every msec
        Hundredths = 10,  // Stopwatch refreshed every 10 msec
        Tenths = 100,     // Stopwatch refreshed every 100 msec
        Seconds = 1000    // Stopwatch refreshed every sec
    };

    explicit StopWatch(QObject *parent = nullptr);

    // Set the stopwatch refresh rate
    void setRefreshRate(RefreshRate r);

    // Check if the stopwatch is running
    bool isRunning() const;

    // Check if the stopwatch is paused
    bool isPaused() const;

    // Check if the stopwatch is inactive
    bool isInactive() const;

    // Stopwatch underlying data
    int rawData() const;

    // Initialize the stopwatch with given raw milliseconds counter
    // Returns true if stopwatch was inactive
    bool initialize(int msRawData);

    // Start the stopwatch, if inactive or paused
    void start();

    // Pause the stopwatch, if running
    void pause();

    // Reset the stopwatch to the inactive state
    void reset();

    // Tells the stopwatch to compute a new lap time
    void storeLap();

signals:
    // The stopwatch has been started
    void running();

    // The stopwatch has been paused
    void paused();

    // The stopwatch has been reset
    void inactive();

    // Emits a signal with the last lap *absolute* time
    // This class does not compute *relatives* lap times
    // You can compute them simply by the difference between consecutives absolute times
    // @param lapTime The absolute time of the last lap
    void lap(const QTime &lapTime);

    // Emits a signal with the current stopwatch time
    // @param t Current stopwatch time
    void time(qint64 t);

protected:
    void timerEvent(QTimerEvent *event) override;

private:
    // Stopwatch state
    enum class State {
        Inactive, // Inactive stopwatch
        Running,  // Running stopwatch
        Paused    // Paused stopwatch
    };

    // Refresh rate of the stopwatch
    int refreshRate() const;

    // ID for the QObject timer
    int m_timerId;

    // Milliseconds internal counter
    int m_accumulator;

    // Stopwatch current state
    State m_state;

    // Stopwatch current refresh rate
    RefreshRate m_refreshRate;

    // Stopwatch core class
    QElapsedTimer m_elapsedTimer;

    Q_DISABLE_COPY(StopWatch)

};

#endif // STOPWATCH_H
