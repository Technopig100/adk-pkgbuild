/********************************************************************************
** Form generated from reading UI file 'reminderitemwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REMINDERITEMWIDGET_H
#define UI_REMINDERITEMWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_reminderItemWidget
{
public:
    QGridLayout *gridLayout;
    QCheckBox *reminder;
    QToolButton *editReminder;
    QToolButton *removeReminder;
    QLabel *reminderDateTime;
    QLabel *reminderRepeat;

    void setupUi(QWidget *reminderItemWidget)
    {
        if (reminderItemWidget->objectName().isEmpty())
            reminderItemWidget->setObjectName(QString::fromUtf8("reminderItemWidget"));
        reminderItemWidget->resize(317, 44);
        gridLayout = new QGridLayout(reminderItemWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(6);
        gridLayout->setVerticalSpacing(2);
        gridLayout->setContentsMargins(2, 2, 2, 2);
        reminder = new QCheckBox(reminderItemWidget);
        reminder->setObjectName(QString::fromUtf8("reminder"));
        QFont font;
        font.setPointSize(11);
        reminder->setFont(font);
        reminder->setTristate(false);

        gridLayout->addWidget(reminder, 0, 0, 1, 2);

        editReminder = new QToolButton(reminderItemWidget);
        editReminder->setObjectName(QString::fromUtf8("editReminder"));
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("document-edit");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        editReminder->setIcon(icon);

        gridLayout->addWidget(editReminder, 0, 2, 2, 1);

        removeReminder = new QToolButton(reminderItemWidget);
        removeReminder->setObjectName(QString::fromUtf8("removeReminder"));
        QIcon icon1;
        iconThemeName = QString::fromUtf8("edit-delete");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon1 = QIcon::fromTheme(iconThemeName);
        } else {
            icon1.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        removeReminder->setIcon(icon1);

        gridLayout->addWidget(removeReminder, 0, 3, 2, 1);

        reminderDateTime = new QLabel(reminderItemWidget);
        reminderDateTime->setObjectName(QString::fromUtf8("reminderDateTime"));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setWeight(50);
        reminderDateTime->setFont(font1);
        reminderDateTime->setIndent(16);

        gridLayout->addWidget(reminderDateTime, 1, 0, 1, 1);

        reminderRepeat = new QLabel(reminderItemWidget);
        reminderRepeat->setObjectName(QString::fromUtf8("reminderRepeat"));
        reminderRepeat->setFont(font1);

        gridLayout->addWidget(reminderRepeat, 1, 1, 1, 1);


        retranslateUi(reminderItemWidget);

        QMetaObject::connectSlotsByName(reminderItemWidget);
    } // setupUi

    void retranslateUi(QWidget *reminderItemWidget)
    {
        reminderItemWidget->setWindowTitle(QCoreApplication::translate("reminderItemWidget", "Form", nullptr));
        reminder->setText(QCoreApplication::translate("reminderItemWidget", "<ReminderText>", nullptr));
        editReminder->setText(QString());
        removeReminder->setText(QString());
        reminderDateTime->setText(QCoreApplication::translate("reminderItemWidget", "<DateTime>", nullptr));
        reminderRepeat->setText(QCoreApplication::translate("reminderItemWidget", "<Repeat>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class reminderItemWidget: public Ui_reminderItemWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REMINDERITEMWIDGET_H
