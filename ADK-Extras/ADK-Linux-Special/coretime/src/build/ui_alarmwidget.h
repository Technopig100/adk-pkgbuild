/********************************************************************************
** Form generated from reading UI file 'alarmwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALARMWIDGET_H
#define UI_ALARMWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_alarmWidget
{
public:
    QVBoxLayout *verticalLayout;
    QStackedWidget *pages;
    QWidget *welcome;
    QVBoxLayout *verticalLayout_2;
    QLabel *welcomeString;
    QWidget *alarmItems;
    QVBoxLayout *verticalLayout_4;
    QListWidget *alarmList;
    QHBoxLayout *horizontalLayout_5;
    QToolButton *addAlarm;
    QSpacerItem *horizontalSpacer_3;
    QWidget *configure;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QGroupBox *alarmRepeat;
    QHBoxLayout *horizontalLayout;
    QToolButton *r_sun;
    QToolButton *r_mon;
    QToolButton *r_tue;
    QToolButton *r_wed;
    QToolButton *r_thu;
    QToolButton *r_fri;
    QToolButton *r_sat;
    QSpacerItem *horizontalSpacer_4;
    QGroupBox *alarmSound;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *alarmSoundFile;
    QToolButton *browseAlarmSound;
    QPushButton *cancel;
    QLineEdit *alarmLabel;
    QPushButton *done;
    QSpacerItem *horizontalSpacer_5;
    QTimeEdit *alarmDateTime;
    QLabel *label;

    void setupUi(QWidget *alarmWidget)
    {
        if (alarmWidget->objectName().isEmpty())
            alarmWidget->setObjectName(QString::fromUtf8("alarmWidget"));
        alarmWidget->resize(474, 332);
        verticalLayout = new QVBoxLayout(alarmWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pages = new QStackedWidget(alarmWidget);
        pages->setObjectName(QString::fromUtf8("pages"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pages->sizePolicy().hasHeightForWidth());
        pages->setSizePolicy(sizePolicy);
        welcome = new QWidget();
        welcome->setObjectName(QString::fromUtf8("welcome"));
        sizePolicy.setHeightForWidth(welcome->sizePolicy().hasHeightForWidth());
        welcome->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(welcome);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        welcomeString = new QLabel(welcome);
        welcomeString->setObjectName(QString::fromUtf8("welcomeString"));
        QFont font;
        font.setPointSize(12);
        welcomeString->setFont(font);
        welcomeString->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(welcomeString);

        pages->addWidget(welcome);
        alarmItems = new QWidget();
        alarmItems->setObjectName(QString::fromUtf8("alarmItems"));
        verticalLayout_4 = new QVBoxLayout(alarmItems);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        alarmList = new QListWidget(alarmItems);
        alarmList->setObjectName(QString::fromUtf8("alarmList"));
        alarmList->setFrameShape(QFrame::NoFrame);
        alarmList->setFrameShadow(QFrame::Plain);

        verticalLayout_4->addWidget(alarmList);

        pages->addWidget(alarmItems);

        verticalLayout->addWidget(pages);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        addAlarm = new QToolButton(alarmWidget);
        addAlarm->setObjectName(QString::fromUtf8("addAlarm"));
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("document-new");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        addAlarm->setIcon(icon);

        horizontalLayout_5->addWidget(addAlarm);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_5);

        configure = new QWidget(alarmWidget);
        configure->setObjectName(QString::fromUtf8("configure"));
        gridLayout = new QGridLayout(configure);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(configure);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        alarmRepeat = new QGroupBox(configure);
        alarmRepeat->setObjectName(QString::fromUtf8("alarmRepeat"));
        alarmRepeat->setFlat(true);
        alarmRepeat->setCheckable(true);
        alarmRepeat->setChecked(false);
        horizontalLayout = new QHBoxLayout(alarmRepeat);
        horizontalLayout->setSpacing(4);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(4, 0, 4, 0);
        r_sun = new QToolButton(alarmRepeat);
        r_sun->setObjectName(QString::fromUtf8("r_sun"));
        r_sun->setCheckable(true);
        r_sun->setChecked(true);

        horizontalLayout->addWidget(r_sun);

        r_mon = new QToolButton(alarmRepeat);
        r_mon->setObjectName(QString::fromUtf8("r_mon"));
        r_mon->setCheckable(true);

        horizontalLayout->addWidget(r_mon);

        r_tue = new QToolButton(alarmRepeat);
        r_tue->setObjectName(QString::fromUtf8("r_tue"));
        r_tue->setCheckable(true);

        horizontalLayout->addWidget(r_tue);

        r_wed = new QToolButton(alarmRepeat);
        r_wed->setObjectName(QString::fromUtf8("r_wed"));
        r_wed->setCheckable(true);

        horizontalLayout->addWidget(r_wed);

        r_thu = new QToolButton(alarmRepeat);
        r_thu->setObjectName(QString::fromUtf8("r_thu"));
        r_thu->setCheckable(true);

        horizontalLayout->addWidget(r_thu);

        r_fri = new QToolButton(alarmRepeat);
        r_fri->setObjectName(QString::fromUtf8("r_fri"));
        r_fri->setCheckable(true);

        horizontalLayout->addWidget(r_fri);

        r_sat = new QToolButton(alarmRepeat);
        r_sat->setObjectName(QString::fromUtf8("r_sat"));
        r_sat->setCheckable(true);

        horizontalLayout->addWidget(r_sat);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        gridLayout->addWidget(alarmRepeat, 5, 0, 1, 4);

        alarmSound = new QGroupBox(configure);
        alarmSound->setObjectName(QString::fromUtf8("alarmSound"));
        alarmSound->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        alarmSound->setFlat(true);
        alarmSound->setCheckable(true);
        alarmSound->setChecked(false);
        horizontalLayout_2 = new QHBoxLayout(alarmSound);
        horizontalLayout_2->setSpacing(4);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(4, 0, 4, 0);
        label_2 = new QLabel(alarmSound);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        alarmSoundFile = new QLineEdit(alarmSound);
        alarmSoundFile->setObjectName(QString::fromUtf8("alarmSoundFile"));

        horizontalLayout_2->addWidget(alarmSoundFile);

        browseAlarmSound = new QToolButton(alarmSound);
        browseAlarmSound->setObjectName(QString::fromUtf8("browseAlarmSound"));

        horizontalLayout_2->addWidget(browseAlarmSound);


        gridLayout->addWidget(alarmSound, 6, 0, 1, 4);

        cancel = new QPushButton(configure);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(cancel->sizePolicy().hasHeightForWidth());
        cancel->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(cancel, 7, 2, 1, 1);

        alarmLabel = new QLineEdit(configure);
        alarmLabel->setObjectName(QString::fromUtf8("alarmLabel"));

        gridLayout->addWidget(alarmLabel, 4, 1, 1, 3);

        done = new QPushButton(configure);
        done->setObjectName(QString::fromUtf8("done"));
        sizePolicy1.setHeightForWidth(done->sizePolicy().hasHeightForWidth());
        done->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(done, 7, 3, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(283, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 7, 0, 1, 2);

        alarmDateTime = new QTimeEdit(configure);
        alarmDateTime->setObjectName(QString::fromUtf8("alarmDateTime"));
        alarmDateTime->setMinimumSize(QSize(155, 32));
        alarmDateTime->setFont(font);

        gridLayout->addWidget(alarmDateTime, 3, 2, 1, 2);

        label = new QLabel(configure);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 3, 0, 1, 2);


        verticalLayout->addWidget(configure);


        retranslateUi(alarmWidget);

        pages->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(alarmWidget);
    } // setupUi

    void retranslateUi(QWidget *alarmWidget)
    {
        alarmWidget->setWindowTitle(QCoreApplication::translate("alarmWidget", "Form", nullptr));
        welcomeString->setText(QCoreApplication::translate("alarmWidget", "<html><head/><body><p>No Alarm found.</p><p>Click the &quot;Add&quot; button to create a alarm.</p></body></html>", nullptr));
        addAlarm->setText(QString());
        label_3->setText(QCoreApplication::translate("alarmWidget", "Alarm Label (optional): ", nullptr));
        alarmRepeat->setTitle(QCoreApplication::translate("alarmWidget", "Repeat", nullptr));
        r_sun->setText(QCoreApplication::translate("alarmWidget", "Sun", nullptr));
        r_mon->setText(QCoreApplication::translate("alarmWidget", "Mon", nullptr));
        r_tue->setText(QCoreApplication::translate("alarmWidget", "Tue", nullptr));
        r_wed->setText(QCoreApplication::translate("alarmWidget", "Wed", nullptr));
        r_thu->setText(QCoreApplication::translate("alarmWidget", "Thu", nullptr));
        r_fri->setText(QCoreApplication::translate("alarmWidget", "Fri", nullptr));
        r_sat->setText(QCoreApplication::translate("alarmWidget", "Sat", nullptr));
        alarmSound->setTitle(QCoreApplication::translate("alarmWidget", "Custom Sound", nullptr));
        label_2->setText(QCoreApplication::translate("alarmWidget", "Sound File : ", nullptr));
        browseAlarmSound->setText(QCoreApplication::translate("alarmWidget", "...", nullptr));
        cancel->setText(QCoreApplication::translate("alarmWidget", "Cancel", nullptr));
        done->setText(QCoreApplication::translate("alarmWidget", "OK", nullptr));
        label->setText(QCoreApplication::translate("alarmWidget", "Set time :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class alarmWidget: public Ui_alarmWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALARMWIDGET_H
