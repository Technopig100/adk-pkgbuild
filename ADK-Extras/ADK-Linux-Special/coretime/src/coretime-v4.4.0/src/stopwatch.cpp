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
#include <QCoreApplication>

#include "stopwatch.h"


// Used for timerId initialization
static constexpr int INACTIVE_TIMER_ID = -1;

StopWatch::StopWatch(QObject *parent) : QObject(parent)
{
    m_timerId = INACTIVE_TIMER_ID;
    m_accumulator = 0;
    m_state = State::Inactive;
    m_refreshRate = RefreshRate::Hundredths;
}

void StopWatch::setRefreshRate(RefreshRate r)
{
    m_refreshRate = r;
}

bool StopWatch::isRunning() const
{
    return m_state == State::Running;
}

bool StopWatch::isPaused() const
{
    return m_state == State::Paused;
}

bool StopWatch::isInactive() const
{
    return m_state == State::Inactive;
}

int StopWatch::rawData() const
{
    return m_accumulator;
}

bool StopWatch::initialize(int msRawData)
{
    if (!isInactive() || msRawData <= 0) {
        return false;
    }

    m_accumulator = msRawData;
    m_state = State::Paused;
    emit time(m_accumulator);  // it signals that has been deserialized and can be resumed

    return true;
}

void StopWatch::start()
{
    if (isInactive()) {
        m_accumulator = 0;
        m_elapsedTimer.start();

        if (m_timerId == INACTIVE_TIMER_ID) {
            m_timerId = startTimer(refreshRate());
        }
    } else if (isPaused()) {
        m_elapsedTimer.restart();
        m_timerId = startTimer(refreshRate());
    }

    m_state = State::Running;
    emit running();
}

void StopWatch::pause()
{
    if (m_elapsedTimer.isValid()) {
        m_accumulator += m_elapsedTimer.elapsed();
    }

    m_elapsedTimer.invalidate();
    m_state = State::Paused;
    emit paused();
}

void StopWatch::reset()
{
    m_elapsedTimer.invalidate();          // if state is running, it will emit a zero time at next timerEvent() call
    QCoreApplication::processEvents();
    emit time(0);
    m_state = State::Inactive;
    emit inactive();
}

void StopWatch::storeLap()
{
    auto lapTime = m_accumulator;

    if (m_elapsedTimer.isValid()) {
        lapTime += m_elapsedTimer.elapsed();
    }

    const auto zero = QTime {0, 0};
    emit lap(zero.addMSecs(lapTime));
}

void StopWatch::timerEvent(QTimerEvent *event)
{
    if (event->timerId() != m_timerId) {      // forward undesired events
        QObject::timerEvent(event);
        return;
    }

    if (m_elapsedTimer.isValid()) {
        emit time(m_accumulator + m_elapsedTimer.elapsed());
    } else {
        killTimer(m_timerId);
        m_timerId = INACTIVE_TIMER_ID;
    }
}

int StopWatch::refreshRate() const
{
    return static_cast<int>(m_refreshRate);
}
