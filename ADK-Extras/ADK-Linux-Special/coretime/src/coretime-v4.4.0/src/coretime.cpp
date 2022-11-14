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


#include <QMenu>
#include <QDir>
#include <QScreen>

#include <cprime/themefunc.h>
#include <cprime/messageengine.h>

#include "calendarmanage.h"
#include "alarmwidget.h"
#include "reminderwidget.h"
#include "stopwatch.h"
#include "weatherview.h"
#include "weathericon.h"

#include "coretime.h"
#include "ui_coretime.h"


coretime::coretime(QWidget *parent) : QWidget(parent)
  , ui(new Ui::coretime)
  , smi(new settings)
{
    ui->setupUi(this);

    ui->sw->setStyleSheet("QLabel {background-color: transparent;}");
    ui->lapText->setStyleSheet("QPlainTextEdit {background-color: transparent;}");
    ui->setTimer->setStyleSheet("QTimeEdit {background-color: transparent;}");

    loadSettings();
    startSetup();
    setupIcons();

    initializeClock();
    initializeAlrRemd(); // Initialize both alarm and reminder
    initializeStopwatch();
    initializeTimer();
    initializeTray();

    // TODO Add filesystemwatcher for reminder file whenever an event updated update the calendar

    // Calendar
	QString t1 = QDir::home().filePath(".config/coreapps/international.txt"); // International
	QString t2 = QDir::home().filePath(".config/coreapps/country.txt"); // Country

    if (QFile(t1).exists()) {
        loadHolidayEvents(t1);
    }

    if (QFile(t2).exists()) {
        loadHolidayEvents(t2);
    }

    loadReminderEvents();

    QDate d = QDate::currentDate();
    on_calendarWid_clicked(d);
    on_calendarWid_currentPageChanged(d.year(), d.month());

	wv = new weatherView(this);
	connect(wv, &weatherView::updateTodayWeather, this, &coretime::updateWeather);
	wv->initializeWeather();
    ui->weatherlayout->addWidget(wv);

	bool showWeather = wv->isWeatherLocationAvailable();
	ui->weatherBox->setVisible(showWeather);
	ui->noWeatherInfo->setVisible(not showWeather);


	int displayHeight = qApp->primaryScreen()->geometry().height();
	QFont font = ui->tTemp->font();

	font.setPointSize(displayHeight * .020); // 2% of the display
	ui->tTemp->setFont(font);

	font = ui->clockText->font();
	font.setPointSize(displayHeight * .025);
	ui->clockText->setFont(font);

	font = ui->noWeatherInfo->font();
	font.setPointSize(displayHeight * .015);
	ui->noWeatherInfo->setFont(font);

	on_now_clicked();
}

coretime::~coretime()
{
	delete smi;
	delete wv;
	delete ui;
}

/**
 * @brief Setup ui elements
 */
void coretime::startSetup()
{
    ui->menu->setVisible(false);
    ui->appTitle->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->appTitle->setFocusPolicy(Qt::NoFocus);
    this->resize(800, 500);

    if (uiMode != 0) {
        this->setWindowState(Qt::WindowMaximized);

        if (uiMode == 2){
            ui->menu->setIconSize(toolsIconSize);

            connect(ui->menu, &QToolButton::clicked, this, &coretime::showSideView);
            connect(ui->appTitle, &QToolButton::clicked, this, &coretime::showSideView);

            ui->sideView->setVisible(0);
            ui->menu->setVisible(1);
        }
    }

    // all toolbuttons icon size in sideView
    QList<QToolButton *> toolBtns = ui->sideView->findChildren<QToolButton *>();
    for (QToolButton *b: toolBtns) {
        if (b) {
            b->setIconSize(toolsIconSize);
        }
    }

}

void coretime::setupIcons(){
    ui->now->setIcon(CPrime::ThemeFunc::themeIcon( "dialog-information-symbolic", "dialog-information", "dialog-information" ));
    ui->calendar->setIcon(CPrime::ThemeFunc::themeIcon( "x-office-calendar-symbolic", "x-office-calendar", "x-office-calendar" ));
    ui->weather->setIcon(CPrime::ThemeFunc::themeIcon( "weather-overcast-symbolic", "weather-overcast", "weather-overcast" ));
    ui->reminders->setIcon(CPrime::ThemeFunc::themeIcon("go-previous-symbolic", "go-previous", "go-previous" ));
    ui->stopwatch->setIcon(CPrime::ThemeFunc::themeIcon("go-next-symbolic", "go-next", "go-next" ));
    ui->alarm->setIcon(CPrime::ThemeFunc::themeIcon( "multimedia-volume-control-symbolic", "multimedia-volume-control", "multimedia-volume-control" ));
    ui->timer->setIcon(CPrime::ThemeFunc::themeIcon( "preferences-system-time-symbolic", "preferences-system-time", "preferences-system-time" ));
    ui->menu->setIcon(CPrime::ThemeFunc::themeIcon( "open-menu-symbolic", "application-menu", "open-menu" ));
}


/**
 * @brief Loads application settings
 */
void coretime::loadSettings()
{
    toolsIconSize = smi->getValue("CoreApps", "ToolsIconSize");
    useSystemNotification = smi->getValue("CoreApps", "UseSystemNotification");
    uiMode = smi->getValue("CoreApps", "UIMode");
}

void coretime::showSideView()
{
    if (ui->sideView->isVisible())
        ui->sideView->setVisible(0);
    else
        ui->sideView->setVisible(1);
}

void coretime::reminderAdded(QDate d, CalendarEvent &event)
{
    appendDate(m_events, d, event);
    on_calendarWid_currentPageChanged(QDate::currentDate().year(), QDate::currentDate().month());
}

void coretime::reminderEdited(QDate oldD, QDate newD, CalendarEvent &event)
{
    QList<CalendarEvent> *list = &m_events[oldD];
    for (int i = 0; i < list->size(); i++) {
        if (list->at(i).type == ReminderDate) {
            list->removeAt(i);
        }
    }

    appendDate(m_events, newD, event);
    on_calendarWid_currentPageChanged(QDate::currentDate().year(), QDate::currentDate().month());
}

void coretime::reminderDeleted(QDate d)
{
    QList<CalendarEvent> *list = &m_events[d];
    for (int i = 0; i < list->size(); i++) {
        if (list->at(i).type == ReminderDate) {
            list->removeAt(i);
        }
    }

    on_calendarWid_currentPageChanged(QDate::currentDate().year(), QDate::currentDate().month());
}

void coretime::loadHolidayEvents(QString eventFile)
{
    QFile file(eventFile);

    if (!file.open(QIODevice::ReadOnly)) {
        //Error code
        qDebug() << "No event file...";
    }

    QTextStream out(&file);

    QList<QString> wordList;

    QDate date;
    QString name;

    while (!out.atEnd()) {
        QString line = out.readLine();
        wordList = line.split(',');

        date = QDate::fromString(wordList.first(), "dd/MM/yyyy");
        date = QDate(QDate::currentDate().year(), date.month(), date.day());
        name = wordList.last();

        CalendarEvent e;
        e.type = HolidayDate;
        e.repeat = true;
        e.description = name;

//        if (m_events[date].count()) {
//            m_events[date].append(e);
//        } else {
//            QList<CalendarEvent> list;
//            list.append(e);
//            m_events[date] = list;
//        }

        appendDate(m_events, date, e);

//        m_events[date] = name;
    }

    file.close();
}

void coretime::loadReminderEvents()
{
    QSettings *settings = new QSettings("coreapps", "reminder");
    int count = settings->value("ReminderCount").toInt();
    settings->beginGroup("All");
    QStringList list = settings->childGroups();

    std::sort(list.begin(), list.end());

    int currYear = QDate::currentDate().year();

    for (int i = 0; i < count; i++) {
        settings->beginGroup(list[i]);
        QDate d = settings->value("ReminderDateTime").toDateTime().date();
        bool repeat = settings->value("Repeat").toBool();
        QString desc = settings->value("ReminderDescription").toString();

        // Populate the events list
        CalendarEvent e;
        e.type = ReminderDate;
        e.repeat = repeat;
        e.description = desc;

        // Get the repeated dates
        if (repeat) {
            RepeatType rType = static_cast<RepeatType>(settings->value("RepeatType").toInt());

            if (rType == RepeatType::Year) {
                appendDate(m_events, QDate(currYear, d.month(), d.day()), e);
            } else if (rType == RepeatType::Month) {
                for (int month = 1; month <= 12; month++) {
                    appendDate(m_events, QDate(currYear, month, d.day()), e);
                }
            } else if (rType == RepeatType::Weekday) {
                int cdow = d.dayOfWeek();

                for (int month = 1; month <= 12; month++) {
                    int mdow = QDate(currYear, month, 1).dayOfWeek();
					delete smi;
                    int temp = (7 + ((cdow - mdow) % 7)) % 7;
                    int monthLen = QDate(currYear, month, 1).daysInMonth();

                    for (int day = temp + 1; day <= monthLen; day += 7) {
                        appendDate(m_events, QDate(currYear, month, day), e);
                    }
                }
            } else if (rType == RepeatType::SpecificWeekDay) {
                // For each 7 days
                for (int i = 1; i <= 7; i++) {
                    bool enable = settings->value("Weekdays/" + QString::number(i - 1)).toBool();

                    if (enable) {
                        for (int month = 1; month <= 12; month++) {
                            int cdow = i;
                            int mdow = QDate(currYear, month, 1).dayOfWeek();
                            int temp = (7 + ((cdow - mdow) % 7)) % 7;
                            int monthLen = QDate(currYear, month, 1).daysInMonth();

                            for (int day = temp + 1; day <= monthLen; day += 7) {
                                appendDate(m_events, QDate(currYear, month, day), e);
                            }
                        }
                    }
                }
            }
        } else {
            e.rType = RepeatType::None;
            appendDate(m_events, d, e);
        }

        settings->endGroup();
    }

    settings->endGroup();
}

void coretime::initializeClock()
{
    ui->clockText->setText(QDateTime::currentDateTime().toString("hh:mm AP\n dddd\n dd MMMM yyyy"));
    ui->calendarWid->showToday();
    clockTimer = new QTimer(this);
    connect(clockTimer, &QTimer::timeout, this, [&]() {
        ui->clockText->setText(QDateTime::currentDateTime().toString("hh:mm AP\n dddd\n dd MMMM yyyy"));
    });
    clockTimer->start(60000);
}

void coretime::initializeAlrRemd()
{
    // Initialize alarm and reminder widget
    ui->alarmLayout->addWidget(alarmWidget::instance(this));
    reminderWidget *wid = reminderWidget::instance(this);
    connect(wid, &reminderWidget::reminderAdded, this, &coretime::reminderAdded);
    connect(wid, &reminderWidget::reminderEdited, this, &coretime::reminderEdited);
    connect(wid, &reminderWidget::reminderDeleted, this, &coretime::reminderDeleted);
    ui->reminderLayout->addWidget(wid);
}

void coretime::initializeStopwatch()
{
    ui->lapText->clear();
    ui->startandpause->setChecked(false);
    st = new StopWatch(this);
    connect(st, &StopWatch::time, this, &coretime::updateStopwatchTime);
}

void coretime::initializeTimer()
{
    ui->timerDuration->setVisible(false);
    forTimer = new QTimer(this);
    connect(forTimer, &QTimer::timeout, this, &coretime::updateTimer);
}

//======================Stopwatch=====================Start==================================

void coretime::on_startandpause_clicked(bool checked)
{
    if (checked) {
        st->start();
        ui->startandpause->setText("Pause");
        ui->lapandreset->setText("Lap");
    } else {
        st->pause();
        ui->startandpause->setText("Resume");
        ui->lapandreset->setText("Reset");
    }
}

void coretime::on_lapandreset_clicked()
{
    if (ui->lapandreset->text() == "Reset") {
        st->reset();
        ui->startandpause->setText("Start");
        ui->sw->setText("00:00:00.000");
        ui->lapText->clear();
    } else {
        int count = 1;

        if (ui->lapText->document()->toPlainText().count()) {
            count += ui->lapText->document()->lineCount();
        }

        ui->lapText->appendPlainText("#" + QString::number(count) + "\t\t" + ui->sw->text());
    }
}

void coretime::updateStopwatchTime(int time)
{
    QTime t;
    t.setHMS(time / MSECS_PER_HOUR,
             (time % MSECS_PER_HOUR) / MSECS_PER_MIN,
             (time / MSECS_PER_SEC) % 60,
             time % MSECS_PER_SEC);
    ui->sw->setText(/*st->currTime.getSTime()*//*st->sTime*/ t.toString("hh:mm:ss:zzz"));
}

//======================Stopwatch=====================End==================================

//======================Timer=======================Start==================================

void coretime::updateTimer()
{
    if (!(ui->timerText->text() == "00:00:00")) {
        QTime time = QTime::fromString(ui->timerText->text(), "hh:mm:ss");
        qint64 total = ((time.hour() * 60) * 60) + (time.minute() * 60) + (time.second() - 1);
        int h = static_cast<int>(total / 60 / 60);
        int m = static_cast<int>((total / 60) - (h * 60));
        int s = static_cast<int>(total - ((m + (h * 60)) * 60));
        time.setHMS(h, m, s);
        ui->timerText->setText(time.toString("hh:mm:ss"));
    } else {
        forTimer->stop();
        on_resetTimer_clicked();
		CPrime::MessageEngine::showMessage("org.cubocore.CoreTime", "CoreTime", "Timer Finished.", "Selected timer finished.");
    }
}

void coretime::on_addTimer_clicked()
{
    if (ui->setTimer->text() == "00:00:00") {
        return;
    }

    ui->timerText->setText(ui->setTimer->text());
    ui->timerDuration->setVisible(true);
    ui->timerSet->setVisible(false);
    ui->startstopTimer->setChecked(true);
    ui->startstopTimer->clicked(true);
}

void coretime::on_startstopTimer_clicked(bool checked)
{
    if (ui->timerText->text() == "00:00:00") {
        return;
    }

    if (checked) {
        ui->startstopTimer->setText("Pause");
        forTimer->start(1000);
    } else {
        ui->startstopTimer->setText("Start");
        forTimer->stop();
    }
}

void coretime::on_resetTimer_clicked()
{
    forTimer->stop();

    ui->timerText->setText("00:00:00");
    ui->startstopTimer->setChecked(false);
    ui->startstopTimer->setText("Start");
    ui->timerSet->setVisible(true);
    ui->timerDuration->setVisible(false);
}
//======================Timer=======================End===================================

void coretime::pageClick(QToolButton *btn, int i, QString title)
{
    // first do this to get all the space for contents
    if (uiMode == 2){
        ui->sideView->setVisible(0);
    }

    // all toolbuttons icon size in sideView
    QList<QToolButton *> toolBtns = ui->sideView->findChildren<QToolButton *>();
    for (QToolButton *b: toolBtns) {
        b->setChecked(false);
    }

    btn->setChecked(true);
    ui->selectedsection->setText(title);
    ui->pages->setCurrentIndex(i);
}

void coretime::on_now_clicked()
{
    pageClick(ui->now, 0, tr("Now"));

    this->setWindowTitle("Clock - CoreTime");
}

void coretime::on_calendar_clicked()
{
    pageClick(ui->calendar, 1, tr("Calendar"));

    this->setWindowTitle("Calendar - CoreTime");
}

void coretime::on_weather_clicked()
{
    pageClick(ui->weather, 2, tr("Weather"));

    this->setWindowTitle("Weather - CoreTime");
}

void coretime::on_alarm_clicked()
{
    pageClick(ui->alarm, 3, tr("Alarm"));

    this->setWindowTitle("Alarm - CoreTime");
}

void coretime::on_reminders_clicked()
{
    pageClick(ui->reminders, 4, tr("Reminder"));

    this->setWindowTitle("Reminder - CoreTime");
}

void coretime::on_stopwatch_clicked()
{
    pageClick(ui->stopwatch, 5, tr("Stopwatch"));

    this->setWindowTitle("Stopwatch - CoreTime");
}

void coretime::on_timer_clicked()
{
    pageClick(ui->timer, 6, tr("Timer"));

    this->setWindowTitle("Timer - CoreTime");
}

void coretime::initializeTray()
{
	QSystemTrayIcon *trayIcon = new QSystemTrayIcon(QIcon::fromTheme("org.cubocore.CoreTime"));
    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(toggleShowHide(QSystemTrayIcon::ActivationReason)));

    QMenu *trayIconMenu = new QMenu( this );
    trayIconMenu->addAction( QIcon::fromTheme( "org.cubocore.CoreTime" ), "&CoreTime", this, SLOT( show() ) );
    trayIconMenu->addAction( QIcon::fromTheme( "application-quit" ), "&Quit", QCoreApplication::instance(), SLOT( quit() ) );

    trayIcon->setContextMenu( trayIconMenu );
    trayIcon->show();
}

void coretime::toggleShowHide(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason) {
        case QSystemTrayIcon::Trigger : {
            if (isVisible()) {
                hide();
            } else {
                show();
                activateWindow();
            }

            break;
        }
        default: {
            break;
        }
    }
}

void coretime::on_calendarWid_clicked(const QDate &date)
{
    ui->eventDetails->clear();

    QDate currD;
    QString reminder = "";
    QString holiday = "";
    bool found = false;

    Q_FOREACH (QDate d, m_events.keys()) {
        Q_FOREACH (CalendarEvent e, m_events[d]) {
            if (date.month() == d.month() && date.day() == d.day()) {
                found = true;

                if (e.repeat) {
                    currD = QDate(QDate::currentDate().year(), date.month(), date.day());
                    setEventText(currD, reminder, holiday);
                }

                if (!e.repeat) {
                    currD = d;
                    setEventText(currD, reminder, holiday);
                }

                break;
            }
        }
    }

    if (!found) {
        ui->eventDetails->setText("There is no Holiday/Event or Reminders for today!!!");
		ui->events->setText(ui->eventDetails->toPlainText());
        return;
    }

    if (holiday.count()) {
        ui->eventDetails->append("Holidays:");
        ui->eventDetails->append(holiday);
    }

    ui->eventDetails->append("Reminders:");
	if (reminder.count()) {
        ui->eventDetails->append(reminder);
	} else {
        ui->eventDetails->append("Nothing for today");
	}

	ui->events->setText(ui->eventDetails->toPlainText());
}

void coretime::on_calendarWid_currentPageChanged(int year, int month) {
    Q_UNUSED(year)
	ui->calendarWid->clearEvents();

    Q_FOREACH (QDate d, m_events.keys()) {
        if (d.month() == month) {
            QList<CalendarEvent> list = m_events[d];

            Q_FOREACH (CalendarEvent e, list) {
                if ( e.type == ReminderDate )
					ui->calendarWid->addEvent( d, 0 );

				else
					ui->calendarWid->addEvent( d, 1 );
            }
        }
    }
}

void coretime::setEventText(QDate date, QString &reminder, QString &holiday)
{
    QList<CalendarEvent> list = m_events[date];

    Q_FOREACH (CalendarEvent e, list) {
        if (e.type == HolidayDate) {
            holiday = holiday + e.description + "\n";
        }

        if (e.type == Type::ReminderDate) {
            reminder = reminder + e.description + "\n";
        }
	}
}

void coretime::updateWeather(WeatherData wd)
{
	qDebug() << "Updating at coretime...";

	bool night = (wd.dt().time().hour() >= 18);
	QIcon weatherIco = weatherIcon::getWeatherIcon(wd.weatherSymbol(), night);
	QPixmap pix = weatherIco.pixmap(128, 128);

	ui->tTemp->setText(QString("%1°C").arg(wd.temperature()));
	ui->tMinTemp->setText(QString("%1°C  ").arg(wd.minTemperature()));
	ui->tMaxTemp->setText(QString("  %1°C").arg(wd.maxTemperature()));
	ui->tWstat->setText(wd.weatherStatus());
	ui->tIcon->setPixmap(pix);
}

void coretime::appendDate(CalendarData &events, QDate date, CalendarEvent &e)
{
    if (events[date].count()) {
        events[date].append(e);
    } else {
        QList< CalendarEvent > list;
        list.append(e);
        events[date] = list;
    }
}
