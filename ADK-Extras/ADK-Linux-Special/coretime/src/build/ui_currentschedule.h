/********************************************************************************
** Form generated from reading UI file 'currentschedule.ui'
**
** Created by: Qt User Interface Compiler version 5.15.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CURRENTSCHEDULE_H
#define UI_CURRENTSCHEDULE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_currentschedule
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *scheduleTime;
    QLabel *currentTime;
    QLabel *text;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *snooze;
    QPushButton *close;

    void setupUi(QDialog *currentschedule)
    {
        if (currentschedule->objectName().isEmpty())
            currentschedule->setObjectName(QString::fromUtf8("currentschedule"));
        currentschedule->resize(306, 111);
        verticalLayout = new QVBoxLayout(currentschedule);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        scheduleTime = new QLabel(currentschedule);
        scheduleTime->setObjectName(QString::fromUtf8("scheduleTime"));
        scheduleTime->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(scheduleTime);

        currentTime = new QLabel(currentschedule);
        currentTime->setObjectName(QString::fromUtf8("currentTime"));
        currentTime->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(currentTime);

        text = new QLabel(currentschedule);
        text->setObjectName(QString::fromUtf8("text"));
        text->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(text);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        snooze = new QPushButton(currentschedule);
        snooze->setObjectName(QString::fromUtf8("snooze"));

        horizontalLayout->addWidget(snooze);

        close = new QPushButton(currentschedule);
        close->setObjectName(QString::fromUtf8("close"));

        horizontalLayout->addWidget(close);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(currentschedule);

        QMetaObject::connectSlotsByName(currentschedule);
    } // setupUi

    void retranslateUi(QDialog *currentschedule)
    {
        currentschedule->setWindowTitle(QCoreApplication::translate("currentschedule", "Dialog", nullptr));
        scheduleTime->setText(QCoreApplication::translate("currentschedule", "<View Text>", nullptr));
        currentTime->setText(QCoreApplication::translate("currentschedule", "<Current Time>", nullptr));
        text->setText(QCoreApplication::translate("currentschedule", "<Schedule Time>", nullptr));
        snooze->setText(QCoreApplication::translate("currentschedule", "Snooze", nullptr));
        close->setText(QCoreApplication::translate("currentschedule", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class currentschedule: public Ui_currentschedule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CURRENTSCHEDULE_H
