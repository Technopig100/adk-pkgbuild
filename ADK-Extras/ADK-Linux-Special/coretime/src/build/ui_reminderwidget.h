/********************************************************************************
** Form generated from reading UI file 'reminderwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REMINDERWIDGET_H
#define UI_REMINDERWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_reminderWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QStackedWidget *pages;
    QWidget *welcome;
    QHBoxLayout *horizontalLayout;
    QLabel *welcomeString;
    QWidget *reminderItems;
    QVBoxLayout *verticalLayout;
    QListWidget *reminderList;
    QHBoxLayout *horizontalLayout_8;
    QToolButton *addReminder;
    QSpacerItem *horizontalSpacer_3;
    QWidget *configure;
    QGridLayout *gridLayout_3;
    QLabel *label_3;
    QDateEdit *reminderDate;
    QLabel *label_2;
    QGroupBox *reminderRepeat;
    QGridLayout *gridLayout;
    QRadioButton *r_weekday;
    QRadioButton *r_month;
    QRadioButton *r_year;
    QRadioButton *r_specific;
    QSpacerItem *horizontalSpacer_4;
    QWidget *weeks;
    QHBoxLayout *horizontalLayout_9;
    QToolButton *r_sun;
    QToolButton *r_mon;
    QToolButton *r_tue;
    QToolButton *r_wed;
    QToolButton *r_thu;
    QToolButton *r_fri;
    QToolButton *r_sat;
    QSpacerItem *horizontalSpacer_5;
    QGroupBox *reminderAlarm;
    QGridLayout *gridLayout_2;
    QLabel *label_4;
    QTimeEdit *reminderTime;
    QGroupBox *reminderSound;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QLineEdit *reminderSoundFile;
    QToolButton *browseReminderSound;
    QLineEdit *reminderDescription;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *cancel;
    QPushButton *done;

    void setupUi(QWidget *reminderWidget)
    {
        if (reminderWidget->objectName().isEmpty())
            reminderWidget->setObjectName(QString::fromUtf8("reminderWidget"));
        reminderWidget->resize(711, 417);
        verticalLayout_2 = new QVBoxLayout(reminderWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        pages = new QStackedWidget(reminderWidget);
        pages->setObjectName(QString::fromUtf8("pages"));
        welcome = new QWidget();
        welcome->setObjectName(QString::fromUtf8("welcome"));
        horizontalLayout = new QHBoxLayout(welcome);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        welcomeString = new QLabel(welcome);
        welcomeString->setObjectName(QString::fromUtf8("welcomeString"));
        QFont font;
        font.setPointSize(12);
        welcomeString->setFont(font);
        welcomeString->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(welcomeString);

        pages->addWidget(welcome);
        reminderItems = new QWidget();
        reminderItems->setObjectName(QString::fromUtf8("reminderItems"));
        verticalLayout = new QVBoxLayout(reminderItems);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        reminderList = new QListWidget(reminderItems);
        reminderList->setObjectName(QString::fromUtf8("reminderList"));
        reminderList->setFrameShape(QFrame::NoFrame);
        reminderList->setFrameShadow(QFrame::Plain);

        verticalLayout->addWidget(reminderList);

        pages->addWidget(reminderItems);

        verticalLayout_2->addWidget(pages);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, -1, -1, -1);
        addReminder = new QToolButton(reminderWidget);
        addReminder->setObjectName(QString::fromUtf8("addReminder"));
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("document-new");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        addReminder->setIcon(icon);

        horizontalLayout_8->addWidget(addReminder);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_8);

        configure = new QWidget(reminderWidget);
        configure->setObjectName(QString::fromUtf8("configure"));
        gridLayout_3 = new QGridLayout(configure);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(configure);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_3->addWidget(label_3, 0, 0, 1, 1);

        reminderDate = new QDateEdit(configure);
        reminderDate->setObjectName(QString::fromUtf8("reminderDate"));

        gridLayout_3->addWidget(reminderDate, 0, 2, 1, 1);

        label_2 = new QLabel(configure);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_3->addWidget(label_2, 1, 0, 2, 2);

        reminderRepeat = new QGroupBox(configure);
        reminderRepeat->setObjectName(QString::fromUtf8("reminderRepeat"));
        reminderRepeat->setFlat(true);
        reminderRepeat->setCheckable(true);
        reminderRepeat->setChecked(false);
        gridLayout = new QGridLayout(reminderRepeat);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        r_weekday = new QRadioButton(reminderRepeat);
        r_weekday->setObjectName(QString::fromUtf8("r_weekday"));
        r_weekday->setChecked(true);
        r_weekday->setAutoRepeat(false);

        gridLayout->addWidget(r_weekday, 0, 0, 1, 1);

        r_month = new QRadioButton(reminderRepeat);
        r_month->setObjectName(QString::fromUtf8("r_month"));
        r_month->setAutoRepeat(false);

        gridLayout->addWidget(r_month, 0, 1, 1, 1);

        r_year = new QRadioButton(reminderRepeat);
        r_year->setObjectName(QString::fromUtf8("r_year"));
        r_year->setAutoRepeat(false);

        gridLayout->addWidget(r_year, 0, 2, 1, 1);

        r_specific = new QRadioButton(reminderRepeat);
        r_specific->setObjectName(QString::fromUtf8("r_specific"));
        r_specific->setAutoRepeat(false);

        gridLayout->addWidget(r_specific, 0, 3, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(374, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 4, 1, 1);

        weeks = new QWidget(reminderRepeat);
        weeks->setObjectName(QString::fromUtf8("weeks"));
        horizontalLayout_9 = new QHBoxLayout(weeks);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(2, 2, 2, 2);
        r_sun = new QToolButton(weeks);
        r_sun->setObjectName(QString::fromUtf8("r_sun"));
        r_sun->setCheckable(true);
        r_sun->setChecked(true);

        horizontalLayout_9->addWidget(r_sun);

        r_mon = new QToolButton(weeks);
        r_mon->setObjectName(QString::fromUtf8("r_mon"));
        r_mon->setCheckable(true);

        horizontalLayout_9->addWidget(r_mon);

        r_tue = new QToolButton(weeks);
        r_tue->setObjectName(QString::fromUtf8("r_tue"));
        r_tue->setCheckable(true);

        horizontalLayout_9->addWidget(r_tue);

        r_wed = new QToolButton(weeks);
        r_wed->setObjectName(QString::fromUtf8("r_wed"));
        r_wed->setCheckable(true);

        horizontalLayout_9->addWidget(r_wed);

        r_thu = new QToolButton(weeks);
        r_thu->setObjectName(QString::fromUtf8("r_thu"));
        r_thu->setCheckable(true);

        horizontalLayout_9->addWidget(r_thu);

        r_fri = new QToolButton(weeks);
        r_fri->setObjectName(QString::fromUtf8("r_fri"));
        r_fri->setCheckable(true);

        horizontalLayout_9->addWidget(r_fri);

        r_sat = new QToolButton(weeks);
        r_sat->setObjectName(QString::fromUtf8("r_sat"));
        r_sat->setCheckable(true);

        horizontalLayout_9->addWidget(r_sat);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_5);


        gridLayout->addWidget(weeks, 1, 0, 1, 5);


        gridLayout_3->addWidget(reminderRepeat, 3, 0, 1, 3);

        reminderAlarm = new QGroupBox(configure);
        reminderAlarm->setObjectName(QString::fromUtf8("reminderAlarm"));
        reminderAlarm->setCheckable(true);
        reminderAlarm->setChecked(false);
        gridLayout_2 = new QGridLayout(reminderAlarm);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(reminderAlarm);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        reminderTime = new QTimeEdit(reminderAlarm);
        reminderTime->setObjectName(QString::fromUtf8("reminderTime"));

        gridLayout_2->addWidget(reminderTime, 0, 1, 1, 1);

        reminderSound = new QGroupBox(reminderAlarm);
        reminderSound->setObjectName(QString::fromUtf8("reminderSound"));
        reminderSound->setFlat(true);
        reminderSound->setCheckable(true);
        reminderSound->setChecked(false);
        horizontalLayout_5 = new QHBoxLayout(reminderSound);
        horizontalLayout_5->setSpacing(3);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(3, 3, 3, 3);
        label = new QLabel(reminderSound);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_5->addWidget(label);

        reminderSoundFile = new QLineEdit(reminderSound);
        reminderSoundFile->setObjectName(QString::fromUtf8("reminderSoundFile"));

        horizontalLayout_5->addWidget(reminderSoundFile);

        browseReminderSound = new QToolButton(reminderSound);
        browseReminderSound->setObjectName(QString::fromUtf8("browseReminderSound"));

        horizontalLayout_5->addWidget(browseReminderSound);


        gridLayout_2->addWidget(reminderSound, 1, 0, 1, 2);


        gridLayout_3->addWidget(reminderAlarm, 4, 0, 1, 3);

        reminderDescription = new QLineEdit(configure);
        reminderDescription->setObjectName(QString::fromUtf8("reminderDescription"));

        gridLayout_3->addWidget(reminderDescription, 2, 1, 1, 2);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_6);

        cancel = new QPushButton(configure);
        cancel->setObjectName(QString::fromUtf8("cancel"));

        horizontalLayout_11->addWidget(cancel);

        done = new QPushButton(configure);
        done->setObjectName(QString::fromUtf8("done"));

        horizontalLayout_11->addWidget(done);


        gridLayout_3->addLayout(horizontalLayout_11, 5, 0, 1, 3);


        verticalLayout_2->addWidget(configure);


        retranslateUi(reminderWidget);

        QMetaObject::connectSlotsByName(reminderWidget);
    } // setupUi

    void retranslateUi(QWidget *reminderWidget)
    {
        reminderWidget->setWindowTitle(QCoreApplication::translate("reminderWidget", "Form", nullptr));
        welcomeString->setText(QCoreApplication::translate("reminderWidget", "No reminders found.\n"
"Add some by clicking the \"Add\" button below.", nullptr));
        addReminder->setText(QString());
        label_3->setText(QCoreApplication::translate("reminderWidget", "Set date :", nullptr));
        reminderDate->setDisplayFormat(QCoreApplication::translate("reminderWidget", "MMMM dd, yyyy", nullptr));
        label_2->setText(QCoreApplication::translate("reminderWidget", "Description : ", nullptr));
        reminderRepeat->setTitle(QCoreApplication::translate("reminderWidget", "Repeat", nullptr));
        r_weekday->setText(QCoreApplication::translate("reminderWidget", "Days", nullptr));
        r_month->setText(QCoreApplication::translate("reminderWidget", "Month", nullptr));
        r_year->setText(QCoreApplication::translate("reminderWidget", "Year", nullptr));
        r_specific->setText(QCoreApplication::translate("reminderWidget", "Specific Weekday", nullptr));
        r_sun->setText(QCoreApplication::translate("reminderWidget", "Sun", nullptr));
        r_mon->setText(QCoreApplication::translate("reminderWidget", "Mon", nullptr));
        r_tue->setText(QCoreApplication::translate("reminderWidget", "Tue", nullptr));
        r_wed->setText(QCoreApplication::translate("reminderWidget", "Wed", nullptr));
        r_thu->setText(QCoreApplication::translate("reminderWidget", "Thu", nullptr));
        r_fri->setText(QCoreApplication::translate("reminderWidget", "Fri", nullptr));
        r_sat->setText(QCoreApplication::translate("reminderWidget", "Sat", nullptr));
        reminderAlarm->setTitle(QCoreApplication::translate("reminderWidget", "Alarm", nullptr));
        label_4->setText(QCoreApplication::translate("reminderWidget", "Set time :", nullptr));
        reminderSound->setTitle(QCoreApplication::translate("reminderWidget", "Custom Sound", nullptr));
        label->setText(QCoreApplication::translate("reminderWidget", "Sound File : ", nullptr));
        browseReminderSound->setText(QCoreApplication::translate("reminderWidget", "...", nullptr));
        cancel->setText(QCoreApplication::translate("reminderWidget", "Cancel", nullptr));
        done->setText(QCoreApplication::translate("reminderWidget", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class reminderWidget: public Ui_reminderWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REMINDERWIDGET_H
