/********************************************************************************
** Form generated from reading UI file 'alarmitemwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALARMITEMWIDGET_H
#define UI_ALARMITEMWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_alarmItemWidget
{
public:
    QGridLayout *gridLayout;
    QCheckBox *alarm;
    QLabel *alarmStatus;
    QToolButton *editAlarm;
    QToolButton *removeAlarm;

    void setupUi(QWidget *alarmItemWidget)
    {
        if (alarmItemWidget->objectName().isEmpty())
            alarmItemWidget->setObjectName(QString::fromUtf8("alarmItemWidget"));
        alarmItemWidget->resize(230, 44);
        gridLayout = new QGridLayout(alarmItemWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(6);
        gridLayout->setVerticalSpacing(2);
        gridLayout->setContentsMargins(2, 2, 2, 2);
        alarm = new QCheckBox(alarmItemWidget);
        alarm->setObjectName(QString::fromUtf8("alarm"));
        alarm->setMinimumSize(QSize(0, 0));
        alarm->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setPointSize(11);
        alarm->setFont(font);

        gridLayout->addWidget(alarm, 0, 0, 1, 2);

        alarmStatus = new QLabel(alarmItemWidget);
        alarmStatus->setObjectName(QString::fromUtf8("alarmStatus"));
        QFont font1;
        font1.setPointSize(10);
        alarmStatus->setFont(font1);
        alarmStatus->setIndent(16);

        gridLayout->addWidget(alarmStatus, 1, 0, 1, 2);

        editAlarm = new QToolButton(alarmItemWidget);
        editAlarm->setObjectName(QString::fromUtf8("editAlarm"));
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("document-edit");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        editAlarm->setIcon(icon);

        gridLayout->addWidget(editAlarm, 0, 2, 2, 1);

        removeAlarm = new QToolButton(alarmItemWidget);
        removeAlarm->setObjectName(QString::fromUtf8("removeAlarm"));
        QIcon icon1;
        iconThemeName = QString::fromUtf8("edit-delete");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon1 = QIcon::fromTheme(iconThemeName);
        } else {
            icon1.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        removeAlarm->setIcon(icon1);

        gridLayout->addWidget(removeAlarm, 0, 3, 2, 1);


        retranslateUi(alarmItemWidget);

        QMetaObject::connectSlotsByName(alarmItemWidget);
    } // setupUi

    void retranslateUi(QWidget *alarmItemWidget)
    {
        alarmItemWidget->setWindowTitle(QCoreApplication::translate("alarmItemWidget", "Form", nullptr));
        alarm->setText(QCoreApplication::translate("alarmItemWidget", "<AlarmName>", nullptr));
        alarmStatus->setText(QCoreApplication::translate("alarmItemWidget", "<Label, Repeat, Once>", nullptr));
        editAlarm->setText(QString());
        removeAlarm->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class alarmItemWidget: public Ui_alarmItemWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALARMITEMWIDGET_H
