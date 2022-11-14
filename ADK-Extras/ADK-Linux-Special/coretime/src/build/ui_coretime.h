/********************************************************************************
** Form generated from reading UI file 'coretime.ui'
**
** Created by: Qt User Interface Compiler version 5.15.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CORETIME_H
#define UI_CORETIME_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <calendarmanage.h>

QT_BEGIN_NAMESPACE

class Ui_coretime
{
public:
    QGridLayout *gridLayout_2;
    QWidget *sideView;
    QVBoxLayout *verticalLayout_3;
    QToolButton *appTitle;
    QSpacerItem *verticalSpacer_2;
    QToolButton *now;
    QToolButton *calendar;
    QToolButton *weather;
    QToolButton *alarm;
    QToolButton *reminders;
    QToolButton *stopwatch;
    QToolButton *timer;
    QSpacerItem *verticalSpacer_3;
    QFrame *nameBar;
    QHBoxLayout *horizontalLayout_4;
    QToolButton *menu;
    QLabel *selectedsection;
    QSpacerItem *horizontalSpacer_5;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout;
    QStackedWidget *pages;
    QWidget *pclock;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *clockText;
    QLabel *events;
    QSpacerItem *verticalSpacer_4;
    QFrame *weatherBox;
    QGridLayout *gridLayout_4;
    QLabel *tIcon;
    QLabel *tTemp;
    QLabel *tWstat;
    QLabel *tMaxTemp;
    QLabel *tMinTemp;
    QSpacerItem *verticalSpacer_6;
    QLabel *noWeatherInfo;
    QWidget *pCalendar;
    QVBoxLayout *verticalLayout_7;
    calendarmanage *calendarWid;
    QTextBrowser *eventDetails;
    QWidget *pweather;
    QVBoxLayout *weatherlayout;
    QWidget *palarm;
    QVBoxLayout *alarmLayout;
    QWidget *preminder;
    QVBoxLayout *reminderLayout;
    QWidget *pstopwatch;
    QVBoxLayout *verticalLayout_5;
    QFrame *lapF;
    QGridLayout *gridLayout;
    QPushButton *startandpause;
    QPushButton *lapandreset;
    QLabel *sw;
    QFrame *watchF;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_3;
    QPlainTextEdit *lapText;
    QWidget *ptimer;
    QVBoxLayout *verticalLayout_2;
    QFrame *timerSet;
    QVBoxLayout *verticalLayout_4;
    QTimeEdit *setTimer;
    QPushButton *addTimer;
    QFrame *timerDuration;
    QGridLayout *gridLayout_3;
    QPushButton *resetTimer;
    QLabel *timerText;
    QPushButton *startstopTimer;
    QSpacerItem *verticalSpacer_5;

    void setupUi(QWidget *coretime)
    {
        if (coretime->objectName().isEmpty())
            coretime->setObjectName(QString::fromUtf8("coretime"));
        coretime->resize(900, 600);
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("org.cubocore.CoreTime");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        coretime->setWindowIcon(icon);
        gridLayout_2 = new QGridLayout(coretime);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        sideView = new QWidget(coretime);
        sideView->setObjectName(QString::fromUtf8("sideView"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(sideView->sizePolicy().hasHeightForWidth());
        sideView->setSizePolicy(sizePolicy);
        sideView->setMinimumSize(QSize(180, 0));
        sideView->setMaximumSize(QSize(230, 16777215));
        sideView->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"    background-color: transparent;\n"
"    color: palette(Text);\n"
"    border: none;\n"
"    Text-align:left;\n"
"    padding: 3px 3px 3px 3px;\n"
"}\n"
"\n"
"QToolButton:checked{\n"
"    background-color: palette(Highlight);\n"
"    color: palette(HighlightedText);\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"    background-color: palette(Highlight);\n"
"    color: palette(HighlightedText);\n"
"}\n"
""));
        verticalLayout_3 = new QVBoxLayout(sideView);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 10, 0, 5);
        appTitle = new QToolButton(sideView);
        appTitle->setObjectName(QString::fromUtf8("appTitle"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(appTitle->sizePolicy().hasHeightForWidth());
        appTitle->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(16);
        appTitle->setFont(font);
        appTitle->setFocusPolicy(Qt::NoFocus);
        appTitle->setLayoutDirection(Qt::LeftToRight);
        appTitle->setText(QString::fromUtf8("CoreTime"));
        appTitle->setIcon(icon);
        appTitle->setIconSize(QSize(24, 24));
        appTitle->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        appTitle->setAutoRaise(true);

        verticalLayout_3->addWidget(appTitle);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_2);

        now = new QToolButton(sideView);
        now->setObjectName(QString::fromUtf8("now"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(now->sizePolicy().hasHeightForWidth());
        now->setSizePolicy(sizePolicy2);
        QFont font1;
        font1.setPointSize(11);
        now->setFont(font1);
        now->setFocusPolicy(Qt::NoFocus);
        now->setIconSize(QSize(22, 22));
        now->setCheckable(true);
        now->setChecked(true);
        now->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        now->setAutoRaise(true);

        verticalLayout_3->addWidget(now);

        calendar = new QToolButton(sideView);
        calendar->setObjectName(QString::fromUtf8("calendar"));
        sizePolicy2.setHeightForWidth(calendar->sizePolicy().hasHeightForWidth());
        calendar->setSizePolicy(sizePolicy2);
        calendar->setFont(font1);
        calendar->setFocusPolicy(Qt::NoFocus);
        calendar->setIconSize(QSize(22, 22));
        calendar->setCheckable(true);
        calendar->setChecked(false);
        calendar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        calendar->setAutoRaise(true);

        verticalLayout_3->addWidget(calendar);

        weather = new QToolButton(sideView);
        weather->setObjectName(QString::fromUtf8("weather"));
        sizePolicy2.setHeightForWidth(weather->sizePolicy().hasHeightForWidth());
        weather->setSizePolicy(sizePolicy2);
        weather->setFont(font1);
        weather->setFocusPolicy(Qt::NoFocus);
        weather->setStyleSheet(QString::fromUtf8(""));
        weather->setIconSize(QSize(22, 22));
        weather->setCheckable(true);
        weather->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        weather->setAutoRaise(true);

        verticalLayout_3->addWidget(weather);

        alarm = new QToolButton(sideView);
        alarm->setObjectName(QString::fromUtf8("alarm"));
        sizePolicy2.setHeightForWidth(alarm->sizePolicy().hasHeightForWidth());
        alarm->setSizePolicy(sizePolicy2);
        alarm->setFont(font1);
        alarm->setFocusPolicy(Qt::NoFocus);
        alarm->setStyleSheet(QString::fromUtf8(""));
        alarm->setIconSize(QSize(22, 22));
        alarm->setCheckable(true);
        alarm->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        alarm->setAutoRaise(true);

        verticalLayout_3->addWidget(alarm);

        reminders = new QToolButton(sideView);
        reminders->setObjectName(QString::fromUtf8("reminders"));
        sizePolicy2.setHeightForWidth(reminders->sizePolicy().hasHeightForWidth());
        reminders->setSizePolicy(sizePolicy2);
        reminders->setFont(font1);
        reminders->setFocusPolicy(Qt::NoFocus);
        reminders->setStyleSheet(QString::fromUtf8(""));
        reminders->setIconSize(QSize(22, 22));
        reminders->setCheckable(true);
        reminders->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        reminders->setAutoRaise(true);

        verticalLayout_3->addWidget(reminders);

        stopwatch = new QToolButton(sideView);
        stopwatch->setObjectName(QString::fromUtf8("stopwatch"));
        sizePolicy2.setHeightForWidth(stopwatch->sizePolicy().hasHeightForWidth());
        stopwatch->setSizePolicy(sizePolicy2);
        stopwatch->setFont(font1);
        stopwatch->setFocusPolicy(Qt::NoFocus);
        stopwatch->setIconSize(QSize(22, 22));
        stopwatch->setCheckable(true);
        stopwatch->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        stopwatch->setAutoRaise(true);

        verticalLayout_3->addWidget(stopwatch);

        timer = new QToolButton(sideView);
        timer->setObjectName(QString::fromUtf8("timer"));
        sizePolicy2.setHeightForWidth(timer->sizePolicy().hasHeightForWidth());
        timer->setSizePolicy(sizePolicy2);
        timer->setFont(font1);
        timer->setFocusPolicy(Qt::NoFocus);
        timer->setIconSize(QSize(22, 22));
        timer->setCheckable(true);
        timer->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        timer->setAutoRaise(true);

        verticalLayout_3->addWidget(timer);

        verticalSpacer_3 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);


        gridLayout_2->addWidget(sideView, 0, 0, 2, 1);

        nameBar = new QFrame(coretime);
        nameBar->setObjectName(QString::fromUtf8("nameBar"));
        nameBar->setMinimumSize(QSize(0, 0));
        nameBar->setMaximumSize(QSize(16777215, 16777215));
        nameBar->setFrameShape(QFrame::NoFrame);
        nameBar->setFrameShadow(QFrame::Plain);
        nameBar->setLineWidth(0);
        horizontalLayout_4 = new QHBoxLayout(nameBar);
        horizontalLayout_4->setSpacing(4);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(5, 0, 2, 0);
        menu = new QToolButton(nameBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        QIcon icon1;
        iconThemeName = QString::fromUtf8("open-menu");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon1 = QIcon::fromTheme(iconThemeName);
        } else {
            icon1.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        menu->setIcon(icon1);

        horizontalLayout_4->addWidget(menu);

        selectedsection = new QLabel(nameBar);
        selectedsection->setObjectName(QString::fromUtf8("selectedsection"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(selectedsection->sizePolicy().hasHeightForWidth());
        selectedsection->setSizePolicy(sizePolicy3);
        selectedsection->setMinimumSize(QSize(0, 0));
        selectedsection->setMaximumSize(QSize(200, 16777215));
        QFont font2;
        font2.setPointSize(14);
        font2.setBold(false);
        selectedsection->setFont(font2);

        horizontalLayout_4->addWidget(selectedsection);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);


        gridLayout_2->addWidget(nameBar, 0, 1, 1, 1);

        scrollArea = new QScrollArea(coretime);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 670, 574));
        horizontalLayout = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pages = new QStackedWidget(scrollAreaWidgetContents);
        pages->setObjectName(QString::fromUtf8("pages"));
        pages->setMinimumSize(QSize(0, 0));
        pages->setStyleSheet(QString::fromUtf8(""));
        pclock = new QWidget();
        pclock->setObjectName(QString::fromUtf8("pclock"));
        verticalLayout = new QVBoxLayout(pclock);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(20);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        clockText = new QLabel(pclock);
        clockText->setObjectName(QString::fromUtf8("clockText"));
        sizePolicy.setHeightForWidth(clockText->sizePolicy().hasHeightForWidth());
        clockText->setSizePolicy(sizePolicy);
        clockText->setMinimumSize(QSize(0, 0));
        clockText->setMaximumSize(QSize(56468, 16777215));
        QFont font3;
        font3.setBold(true);
        clockText->setFont(font3);
        clockText->setFrameShadow(QFrame::Sunken);
        clockText->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(clockText);

        events = new QLabel(pclock);
        events->setObjectName(QString::fromUtf8("events"));
        sizePolicy.setHeightForWidth(events->sizePolicy().hasHeightForWidth());
        events->setSizePolicy(sizePolicy);
        events->setFont(font1);
        events->setAlignment(Qt::AlignCenter);
        events->setWordWrap(true);

        horizontalLayout_2->addWidget(events);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        weatherBox = new QFrame(pclock);
        weatherBox->setObjectName(QString::fromUtf8("weatherBox"));
        weatherBox->setFrameShape(QFrame::NoFrame);
        weatherBox->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(weatherBox);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        tIcon = new QLabel(weatherBox);
        tIcon->setObjectName(QString::fromUtf8("tIcon"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(tIcon->sizePolicy().hasHeightForWidth());
        tIcon->setSizePolicy(sizePolicy4);
        tIcon->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(tIcon, 1, 0, 1, 2);

        tTemp = new QLabel(weatherBox);
        tTemp->setObjectName(QString::fromUtf8("tTemp"));
        sizePolicy4.setHeightForWidth(tTemp->sizePolicy().hasHeightForWidth());
        tTemp->setSizePolicy(sizePolicy4);
        tTemp->setFont(font3);
        tTemp->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(tTemp, 1, 3, 1, 2);

        tWstat = new QLabel(weatherBox);
        tWstat->setObjectName(QString::fromUtf8("tWstat"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(tWstat->sizePolicy().hasHeightForWidth());
        tWstat->setSizePolicy(sizePolicy5);
        QFont font4;
        font4.setPointSize(12);
        tWstat->setFont(font4);
        tWstat->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        gridLayout_4->addWidget(tWstat, 2, 0, 1, 2);

        tMaxTemp = new QLabel(weatherBox);
        tMaxTemp->setObjectName(QString::fromUtf8("tMaxTemp"));
        QFont font5;
        font5.setPointSize(14);
        tMaxTemp->setFont(font5);
        tMaxTemp->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        gridLayout_4->addWidget(tMaxTemp, 2, 4, 1, 1);

        tMinTemp = new QLabel(weatherBox);
        tMinTemp->setObjectName(QString::fromUtf8("tMinTemp"));
        tMinTemp->setFont(font5);
        tMinTemp->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);

        gridLayout_4->addWidget(tMinTemp, 2, 3, 1, 1);


        verticalLayout->addWidget(weatherBox);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_6);

        noWeatherInfo = new QLabel(pclock);
        noWeatherInfo->setObjectName(QString::fromUtf8("noWeatherInfo"));
        noWeatherInfo->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(noWeatherInfo);

        pages->addWidget(pclock);
        pCalendar = new QWidget();
        pCalendar->setObjectName(QString::fromUtf8("pCalendar"));
        verticalLayout_7 = new QVBoxLayout(pCalendar);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        calendarWid = new calendarmanage(pCalendar);
        calendarWid->setObjectName(QString::fromUtf8("calendarWid"));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(calendarWid->sizePolicy().hasHeightForWidth());
        calendarWid->setSizePolicy(sizePolicy6);
        calendarWid->setMinimumDate(QDate(1912, 9, 14));
        calendarWid->setGridVisible(true);
        calendarWid->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
        calendarWid->setNavigationBarVisible(true);
        calendarWid->setDateEditEnabled(true);

        verticalLayout_7->addWidget(calendarWid);

        eventDetails = new QTextBrowser(pCalendar);
        eventDetails->setObjectName(QString::fromUtf8("eventDetails"));
        sizePolicy5.setHeightForWidth(eventDetails->sizePolicy().hasHeightForWidth());
        eventDetails->setSizePolicy(sizePolicy5);
        eventDetails->setFont(font1);
        eventDetails->setFrameShape(QFrame::NoFrame);
        eventDetails->setFrameShadow(QFrame::Plain);

        verticalLayout_7->addWidget(eventDetails);

        pages->addWidget(pCalendar);
        pweather = new QWidget();
        pweather->setObjectName(QString::fromUtf8("pweather"));
        sizePolicy.setHeightForWidth(pweather->sizePolicy().hasHeightForWidth());
        pweather->setSizePolicy(sizePolicy);
        weatherlayout = new QVBoxLayout(pweather);
        weatherlayout->setSpacing(0);
        weatherlayout->setContentsMargins(11, 11, 11, 11);
        weatherlayout->setObjectName(QString::fromUtf8("weatherlayout"));
        weatherlayout->setContentsMargins(0, 0, 0, 0);
        pages->addWidget(pweather);
        palarm = new QWidget();
        palarm->setObjectName(QString::fromUtf8("palarm"));
        alarmLayout = new QVBoxLayout(palarm);
        alarmLayout->setSpacing(6);
        alarmLayout->setContentsMargins(11, 11, 11, 11);
        alarmLayout->setObjectName(QString::fromUtf8("alarmLayout"));
        pages->addWidget(palarm);
        preminder = new QWidget();
        preminder->setObjectName(QString::fromUtf8("preminder"));
        reminderLayout = new QVBoxLayout(preminder);
        reminderLayout->setSpacing(6);
        reminderLayout->setContentsMargins(11, 11, 11, 11);
        reminderLayout->setObjectName(QString::fromUtf8("reminderLayout"));
        pages->addWidget(preminder);
        pstopwatch = new QWidget();
        pstopwatch->setObjectName(QString::fromUtf8("pstopwatch"));
        pstopwatch->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_5 = new QVBoxLayout(pstopwatch);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        lapF = new QFrame(pstopwatch);
        lapF->setObjectName(QString::fromUtf8("lapF"));
        sizePolicy1.setHeightForWidth(lapF->sizePolicy().hasHeightForWidth());
        lapF->setSizePolicy(sizePolicy1);
        lapF->setFrameShape(QFrame::NoFrame);
        lapF->setFrameShadow(QFrame::Plain);
        lapF->setLineWidth(0);
        gridLayout = new QGridLayout(lapF);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, -1, 0, -1);
        startandpause = new QPushButton(lapF);
        startandpause->setObjectName(QString::fromUtf8("startandpause"));
        startandpause->setMinimumSize(QSize(0, 0));
        startandpause->setMaximumSize(QSize(16777215, 40));
        QFont font6;
        font6.setPointSize(12);
        font6.setBold(true);
        startandpause->setFont(font6);
        startandpause->setFocusPolicy(Qt::NoFocus);
        startandpause->setCheckable(true);

        gridLayout->addWidget(startandpause, 1, 0, 1, 1);

        lapandreset = new QPushButton(lapF);
        lapandreset->setObjectName(QString::fromUtf8("lapandreset"));
        QSizePolicy sizePolicy7(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(lapandreset->sizePolicy().hasHeightForWidth());
        lapandreset->setSizePolicy(sizePolicy7);
        lapandreset->setMinimumSize(QSize(0, 0));
        lapandreset->setMaximumSize(QSize(16777215, 40));
        lapandreset->setFont(font6);
        lapandreset->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(lapandreset, 1, 1, 1, 1);

        sw = new QLabel(lapF);
        sw->setObjectName(QString::fromUtf8("sw"));
        sizePolicy4.setHeightForWidth(sw->sizePolicy().hasHeightForWidth());
        sw->setSizePolicy(sizePolicy4);
        sw->setMinimumSize(QSize(0, 0));
        sw->setMaximumSize(QSize(16777215, 100));
        QFont font7;
        font7.setPointSize(40);
        sw->setFont(font7);
        sw->setAutoFillBackground(true);
        sw->setAlignment(Qt::AlignCenter);
        sw->setMargin(0);
        sw->setIndent(5);

        gridLayout->addWidget(sw, 0, 0, 1, 2);


        verticalLayout_5->addWidget(lapF);

        watchF = new QFrame(pstopwatch);
        watchF->setObjectName(QString::fromUtf8("watchF"));
        sizePolicy4.setHeightForWidth(watchF->sizePolicy().hasHeightForWidth());
        watchF->setSizePolicy(sizePolicy4);
        watchF->setFrameShape(QFrame::NoFrame);
        watchF->setFrameShadow(QFrame::Plain);
        watchF->setLineWidth(0);
        verticalLayout_6 = new QVBoxLayout(watchF);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, -1, 0, -1);
        label_3 = new QLabel(watchF);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font8;
        font8.setPointSize(16);
        font8.setBold(true);
        label_3->setFont(font8);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_3);

        lapText = new QPlainTextEdit(watchF);
        lapText->setObjectName(QString::fromUtf8("lapText"));
        sizePolicy.setHeightForWidth(lapText->sizePolicy().hasHeightForWidth());
        lapText->setSizePolicy(sizePolicy);
        lapText->setFrameShape(QFrame::NoFrame);
        lapText->setFrameShadow(QFrame::Plain);
        lapText->setReadOnly(true);

        verticalLayout_6->addWidget(lapText);


        verticalLayout_5->addWidget(watchF);

        pages->addWidget(pstopwatch);
        ptimer = new QWidget();
        ptimer->setObjectName(QString::fromUtf8("ptimer"));
        verticalLayout_2 = new QVBoxLayout(ptimer);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        timerSet = new QFrame(ptimer);
        timerSet->setObjectName(QString::fromUtf8("timerSet"));
        sizePolicy1.setHeightForWidth(timerSet->sizePolicy().hasHeightForWidth());
        timerSet->setSizePolicy(sizePolicy1);
        timerSet->setStyleSheet(QString::fromUtf8(""));
        timerSet->setFrameShape(QFrame::NoFrame);
        timerSet->setFrameShadow(QFrame::Plain);
        verticalLayout_4 = new QVBoxLayout(timerSet);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, -1, 0, -1);
        setTimer = new QTimeEdit(timerSet);
        setTimer->setObjectName(QString::fromUtf8("setTimer"));
        sizePolicy7.setHeightForWidth(setTimer->sizePolicy().hasHeightForWidth());
        setTimer->setSizePolicy(sizePolicy7);
        setTimer->setMinimumSize(QSize(273, 72));
        QFont font9;
        font9.setPointSize(36);
        font9.setBold(true);
        setTimer->setFont(font9);
        setTimer->setAutoFillBackground(true);
        setTimer->setWrapping(false);
        setTimer->setFrame(false);
        setTimer->setAlignment(Qt::AlignCenter);
        setTimer->setReadOnly(false);
        setTimer->setButtonSymbols(QAbstractSpinBox::NoButtons);
        setTimer->setCurrentSection(QDateTimeEdit::HourSection);

        verticalLayout_4->addWidget(setTimer);

        addTimer = new QPushButton(timerSet);
        addTimer->setObjectName(QString::fromUtf8("addTimer"));
        QSizePolicy sizePolicy8(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(addTimer->sizePolicy().hasHeightForWidth());
        addTimer->setSizePolicy(sizePolicy8);
        addTimer->setMinimumSize(QSize(0, 0));
        QFont font10;
        font10.setPointSize(14);
        font10.setBold(true);
        addTimer->setFont(font10);

        verticalLayout_4->addWidget(addTimer);


        verticalLayout_2->addWidget(timerSet);

        timerDuration = new QFrame(ptimer);
        timerDuration->setObjectName(QString::fromUtf8("timerDuration"));
        sizePolicy1.setHeightForWidth(timerDuration->sizePolicy().hasHeightForWidth());
        timerDuration->setSizePolicy(sizePolicy1);
        timerDuration->setFrameShape(QFrame::NoFrame);
        timerDuration->setFrameShadow(QFrame::Plain);
        gridLayout_3 = new QGridLayout(timerDuration);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, -1, 0, -1);
        resetTimer = new QPushButton(timerDuration);
        resetTimer->setObjectName(QString::fromUtf8("resetTimer"));
        sizePolicy8.setHeightForWidth(resetTimer->sizePolicy().hasHeightForWidth());
        resetTimer->setSizePolicy(sizePolicy8);
        resetTimer->setMinimumSize(QSize(0, 0));
        resetTimer->setFont(font6);

        gridLayout_3->addWidget(resetTimer, 1, 1, 1, 1);

        timerText = new QLabel(timerDuration);
        timerText->setObjectName(QString::fromUtf8("timerText"));
        sizePolicy4.setHeightForWidth(timerText->sizePolicy().hasHeightForWidth());
        timerText->setSizePolicy(sizePolicy4);
        timerText->setMinimumSize(QSize(0, 0));
        QFont font11;
        font11.setPointSize(48);
        font11.setBold(true);
        timerText->setFont(font11);
        timerText->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout_3->addWidget(timerText, 0, 0, 1, 2);

        startstopTimer = new QPushButton(timerDuration);
        startstopTimer->setObjectName(QString::fromUtf8("startstopTimer"));
        sizePolicy8.setHeightForWidth(startstopTimer->sizePolicy().hasHeightForWidth());
        startstopTimer->setSizePolicy(sizePolicy8);
        startstopTimer->setMinimumSize(QSize(0, 0));
        startstopTimer->setFont(font6);
        startstopTimer->setCheckable(true);

        gridLayout_3->addWidget(startstopTimer, 1, 0, 1, 1);


        verticalLayout_2->addWidget(timerDuration);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_5);

        pages->addWidget(ptimer);

        horizontalLayout->addWidget(pages);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_2->addWidget(scrollArea, 1, 1, 1, 1);


        retranslateUi(coretime);

        pages->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(coretime);
    } // setupUi

    void retranslateUi(QWidget *coretime)
    {
        coretime->setWindowTitle(QCoreApplication::translate("coretime", "CoreTime", nullptr));
#if QT_CONFIG(accessibility)
        sideView->setAccessibleName(QCoreApplication::translate("coretime", "shortcut", nullptr));
#endif // QT_CONFIG(accessibility)
        now->setText(QCoreApplication::translate("coretime", "Now", nullptr));
        calendar->setText(QCoreApplication::translate("coretime", "Calendar", nullptr));
        weather->setText(QCoreApplication::translate("coretime", "Weather", nullptr));
        alarm->setText(QCoreApplication::translate("coretime", "Alarm", nullptr));
        reminders->setText(QCoreApplication::translate("coretime", "Reminders", nullptr));
        stopwatch->setText(QCoreApplication::translate("coretime", "StopWatch", nullptr));
        timer->setText(QCoreApplication::translate("coretime", "Timer", nullptr));
#if QT_CONFIG(accessibility)
        nameBar->setAccessibleName(QCoreApplication::translate("coretime", "nameBar", nullptr));
#endif // QT_CONFIG(accessibility)
        menu->setText(QCoreApplication::translate("coretime", "...", nullptr));
#if QT_CONFIG(accessibility)
        selectedsection->setAccessibleName(QCoreApplication::translate("coretime", "nameBar", nullptr));
#endif // QT_CONFIG(accessibility)
        selectedsection->setText(QCoreApplication::translate("coretime", "Clock", nullptr));
#if QT_CONFIG(accessibility)
        pclock->setAccessibleName(QCoreApplication::translate("coretime", "pages", nullptr));
#endif // QT_CONFIG(accessibility)
        clockText->setText(QCoreApplication::translate("coretime", "Clock", nullptr));
        events->setText(QCoreApplication::translate("coretime", "Holidays:\n"
"Towel Day\n"
"\n"
"Reminders:\n"
"Nothing for today\n"
"\n"
"Alarms:\n"
"Nothing for today", nullptr));
        tIcon->setText(QCoreApplication::translate("coretime", "ICON", nullptr));
        tTemp->setText(QCoreApplication::translate("coretime", "Current Temp", nullptr));
        tWstat->setText(QCoreApplication::translate("coretime", "Weather Status", nullptr));
#if QT_CONFIG(tooltip)
        tMaxTemp->setToolTip(QCoreApplication::translate("coretime", "Maximum Temparature", nullptr));
#endif // QT_CONFIG(tooltip)
        tMaxTemp->setText(QCoreApplication::translate("coretime", "Max Temp  ", nullptr));
#if QT_CONFIG(tooltip)
        tMinTemp->setToolTip(QCoreApplication::translate("coretime", "Minimum Temparature", nullptr));
#endif // QT_CONFIG(tooltip)
        tMinTemp->setText(QCoreApplication::translate("coretime", "  Min Temp", nullptr));
        noWeatherInfo->setText(QCoreApplication::translate("coretime", "Select location from\n"
"weather page to see\n"
"weather info here", nullptr));
#if QT_CONFIG(accessibility)
        palarm->setAccessibleName(QCoreApplication::translate("coretime", "pages", nullptr));
#endif // QT_CONFIG(accessibility)
#if QT_CONFIG(accessibility)
        pstopwatch->setAccessibleName(QCoreApplication::translate("coretime", "pages", nullptr));
#endif // QT_CONFIG(accessibility)
        startandpause->setText(QCoreApplication::translate("coretime", "Start", nullptr));
        lapandreset->setText(QCoreApplication::translate("coretime", "Reset", nullptr));
        sw->setText(QCoreApplication::translate("coretime", "00:00:00.000", nullptr));
        label_3->setText(QCoreApplication::translate("coretime", "Lap List", nullptr));
#if QT_CONFIG(accessibility)
        ptimer->setAccessibleName(QCoreApplication::translate("coretime", "pages", nullptr));
#endif // QT_CONFIG(accessibility)
        setTimer->setDisplayFormat(QCoreApplication::translate("coretime", "hh:mm:ss", nullptr));
        addTimer->setText(QCoreApplication::translate("coretime", "Set Timer", nullptr));
        resetTimer->setText(QCoreApplication::translate("coretime", "Reset", nullptr));
        timerText->setText(QCoreApplication::translate("coretime", "00:00:00", nullptr));
        startstopTimer->setText(QCoreApplication::translate("coretime", "Start", nullptr));
    } // retranslateUi

};

namespace Ui {
    class coretime: public Ui_coretime {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CORETIME_H
