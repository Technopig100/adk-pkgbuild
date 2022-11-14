/********************************************************************************
** Form generated from reading UI file 'weatherview.ui'
**
** Created by: Qt User Interface Compiler version 5.15.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEATHERVIEW_H
#define UI_WEATHERVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_weatherView
{
public:
    QVBoxLayout *verticalLayout;
    QStackedWidget *mainWid;
    QWidget *selectLocation;
    QVBoxLayout *verticalLayout_5;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLineEdit *searchStr;
    QToolButton *search;
    QTableWidget *result;
    QLabel *status;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *back;
    QSpacerItem *horizontalSpacer;
    QToolButton *select;
    QWidget *advanceView;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *location;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *editLoc;
    QLabel *wStatus;
    QGroupBox *grpMoreData;
    QGridLayout *gridLayout_5;
    QLabel *tHumd;
    QLabel *tPress;
    QLabel *tDewT;
    QLabel *tFog;
    QLabel *tPrec;
    QLabel *tCloud;
    QLabel *tWind;
    QGroupBox *grpAstroData;
    QGridLayout *gridLayout_4;
    QLabel *sunrise;
    QLabel *sunset;
    QLabel *moonrise;
    QLabel *moonset;
    QGroupBox *grpHourlyFc;
    QVBoxLayout *verticalLayout_3;
    QListWidget *hourly;
    QGroupBox *grpDailyFc;
    QVBoxLayout *verticalLayout_4;
    QListWidget *daily;

    void setupUi(QWidget *weatherView)
    {
        if (weatherView->objectName().isEmpty())
            weatherView->setObjectName(QString::fromUtf8("weatherView"));
        weatherView->resize(815, 563);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(weatherView->sizePolicy().hasHeightForWidth());
        weatherView->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(weatherView);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        mainWid = new QStackedWidget(weatherView);
        mainWid->setObjectName(QString::fromUtf8("mainWid"));
        sizePolicy.setHeightForWidth(mainWid->sizePolicy().hasHeightForWidth());
        mainWid->setSizePolicy(sizePolicy);
        selectLocation = new QWidget();
        selectLocation->setObjectName(QString::fromUtf8("selectLocation"));
        sizePolicy.setHeightForWidth(selectLocation->sizePolicy().hasHeightForWidth());
        selectLocation->setSizePolicy(sizePolicy);
        verticalLayout_5 = new QVBoxLayout(selectLocation);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label = new QLabel(selectLocation);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_5->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        searchStr = new QLineEdit(selectLocation);
        searchStr->setObjectName(QString::fromUtf8("searchStr"));
        searchStr->setClearButtonEnabled(true);

        horizontalLayout->addWidget(searchStr);

        search = new QToolButton(selectLocation);
        search->setObjectName(QString::fromUtf8("search"));

        horizontalLayout->addWidget(search);


        verticalLayout_5->addLayout(horizontalLayout);

        result = new QTableWidget(selectLocation);
        if (result->columnCount() < 2)
            result->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        result->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        result->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        result->setObjectName(QString::fromUtf8("result"));
        result->setEditTriggers(QAbstractItemView::NoEditTriggers);
        result->setTabKeyNavigation(false);
        result->setDragDropOverwriteMode(false);
        result->setSelectionMode(QAbstractItemView::SingleSelection);
        result->setSelectionBehavior(QAbstractItemView::SelectRows);
        result->setShowGrid(false);
        result->setCornerButtonEnabled(false);
        result->setColumnCount(2);
        result->horizontalHeader()->setVisible(false);
        result->horizontalHeader()->setHighlightSections(false);
        result->horizontalHeader()->setStretchLastSection(true);
        result->verticalHeader()->setVisible(false);
        result->verticalHeader()->setHighlightSections(false);

        verticalLayout_5->addWidget(result);

        status = new QLabel(selectLocation);
        status->setObjectName(QString::fromUtf8("status"));
        status->setEnabled(true);
        QFont font;
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        status->setFont(font);
        status->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(status);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        back = new QToolButton(selectLocation);
        back->setObjectName(QString::fromUtf8("back"));

        horizontalLayout_2->addWidget(back);

        horizontalSpacer = new QSpacerItem(715, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        select = new QToolButton(selectLocation);
        select->setObjectName(QString::fromUtf8("select"));
        select->setEnabled(false);

        horizontalLayout_2->addWidget(select);


        verticalLayout_5->addLayout(horizontalLayout_2);

        mainWid->addWidget(selectLocation);
        advanceView = new QWidget();
        advanceView->setObjectName(QString::fromUtf8("advanceView"));
        sizePolicy.setHeightForWidth(advanceView->sizePolicy().hasHeightForWidth());
        advanceView->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(advanceView);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(4, 4, 4, 4);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        location = new QLabel(advanceView);
        location->setObjectName(QString::fromUtf8("location"));

        horizontalLayout_3->addWidget(location);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        editLoc = new QToolButton(advanceView);
        editLoc->setObjectName(QString::fromUtf8("editLoc"));

        horizontalLayout_3->addWidget(editLoc);


        verticalLayout_2->addLayout(horizontalLayout_3);

        wStatus = new QLabel(advanceView);
        wStatus->setObjectName(QString::fromUtf8("wStatus"));

        verticalLayout_2->addWidget(wStatus);

        grpMoreData = new QGroupBox(advanceView);
        grpMoreData->setObjectName(QString::fromUtf8("grpMoreData"));
        grpMoreData->setFlat(true);
        grpMoreData->setCheckable(false);
        gridLayout_5 = new QGridLayout(grpMoreData);
        gridLayout_5->setSpacing(4);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(2, 2, 2, 2);
        tHumd = new QLabel(grpMoreData);
        tHumd->setObjectName(QString::fromUtf8("tHumd"));

        gridLayout_5->addWidget(tHumd, 0, 0, 1, 1);

        tPress = new QLabel(grpMoreData);
        tPress->setObjectName(QString::fromUtf8("tPress"));

        gridLayout_5->addWidget(tPress, 0, 1, 1, 1);

        tDewT = new QLabel(grpMoreData);
        tDewT->setObjectName(QString::fromUtf8("tDewT"));

        gridLayout_5->addWidget(tDewT, 1, 0, 1, 1);

        tFog = new QLabel(grpMoreData);
        tFog->setObjectName(QString::fromUtf8("tFog"));

        gridLayout_5->addWidget(tFog, 1, 1, 1, 1);

        tPrec = new QLabel(grpMoreData);
        tPrec->setObjectName(QString::fromUtf8("tPrec"));

        gridLayout_5->addWidget(tPrec, 2, 0, 1, 1);

        tCloud = new QLabel(grpMoreData);
        tCloud->setObjectName(QString::fromUtf8("tCloud"));

        gridLayout_5->addWidget(tCloud, 2, 1, 1, 1);

        tWind = new QLabel(grpMoreData);
        tWind->setObjectName(QString::fromUtf8("tWind"));

        gridLayout_5->addWidget(tWind, 3, 0, 1, 1);


        verticalLayout_2->addWidget(grpMoreData);

        grpAstroData = new QGroupBox(advanceView);
        grpAstroData->setObjectName(QString::fromUtf8("grpAstroData"));
        grpAstroData->setFlat(true);
        grpAstroData->setCheckable(false);
        gridLayout_4 = new QGridLayout(grpAstroData);
        gridLayout_4->setSpacing(4);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(2, 2, 2, 2);
        sunrise = new QLabel(grpAstroData);
        sunrise->setObjectName(QString::fromUtf8("sunrise"));
        sunrise->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_4->addWidget(sunrise, 0, 0, 1, 1);

        sunset = new QLabel(grpAstroData);
        sunset->setObjectName(QString::fromUtf8("sunset"));
        sunset->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_4->addWidget(sunset, 0, 1, 1, 1);

        moonrise = new QLabel(grpAstroData);
        moonrise->setObjectName(QString::fromUtf8("moonrise"));
        moonrise->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_4->addWidget(moonrise, 1, 0, 1, 1);

        moonset = new QLabel(grpAstroData);
        moonset->setObjectName(QString::fromUtf8("moonset"));
        moonset->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_4->addWidget(moonset, 1, 1, 1, 1);


        verticalLayout_2->addWidget(grpAstroData);

        grpHourlyFc = new QGroupBox(advanceView);
        grpHourlyFc->setObjectName(QString::fromUtf8("grpHourlyFc"));
        grpHourlyFc->setFlat(true);
        grpHourlyFc->setCheckable(false);
        verticalLayout_3 = new QVBoxLayout(grpHourlyFc);
        verticalLayout_3->setSpacing(4);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(2, 2, 2, 2);
        hourly = new QListWidget(grpHourlyFc);
        hourly->setObjectName(QString::fromUtf8("hourly"));
        sizePolicy.setHeightForWidth(hourly->sizePolicy().hasHeightForWidth());
        hourly->setSizePolicy(sizePolicy);
        hourly->setFrameShape(QFrame::NoFrame);
        hourly->setEditTriggers(QAbstractItemView::NoEditTriggers);
        hourly->setSelectionBehavior(QAbstractItemView::SelectRows);
        hourly->setMovement(QListView::Static);
        hourly->setFlow(QListView::LeftToRight);
        hourly->setViewMode(QListView::ListMode);

        verticalLayout_3->addWidget(hourly);


        verticalLayout_2->addWidget(grpHourlyFc);

        grpDailyFc = new QGroupBox(advanceView);
        grpDailyFc->setObjectName(QString::fromUtf8("grpDailyFc"));
        grpDailyFc->setFlat(true);
        grpDailyFc->setCheckable(false);
        verticalLayout_4 = new QVBoxLayout(grpDailyFc);
        verticalLayout_4->setSpacing(4);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(2, 2, 2, 2);
        daily = new QListWidget(grpDailyFc);
        daily->setObjectName(QString::fromUtf8("daily"));
        daily->setFrameShape(QFrame::NoFrame);
        daily->setEditTriggers(QAbstractItemView::NoEditTriggers);
        daily->setSelectionBehavior(QAbstractItemView::SelectRows);
        daily->setFlow(QListView::LeftToRight);

        verticalLayout_4->addWidget(daily);


        verticalLayout_2->addWidget(grpDailyFc);

        mainWid->addWidget(advanceView);

        verticalLayout->addWidget(mainWid);

        QWidget::setTabOrder(searchStr, select);
        QWidget::setTabOrder(select, result);

        retranslateUi(weatherView);

        mainWid->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(weatherView);
    } // setupUi

    void retranslateUi(QWidget *weatherView)
    {
        weatherView->setWindowTitle(QCoreApplication::translate("weatherView", "weatherView", nullptr));
        label->setText(QCoreApplication::translate("weatherView", "<html><head/><body><p align=\"center\">No Location selected.</p><p align=\"center\">Please select your location.</p></body></html>", nullptr));
        searchStr->setPlaceholderText(QCoreApplication::translate("weatherView", "Search your city or country", nullptr));
        search->setText(QCoreApplication::translate("weatherView", "Search", nullptr));
        QTableWidgetItem *___qtablewidgetitem = result->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("weatherView", "Category", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = result->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("weatherView", "Display name", nullptr));
        status->setText(QString());
        back->setText(QCoreApplication::translate("weatherView", "Back", nullptr));
        select->setText(QCoreApplication::translate("weatherView", "Select", nullptr));
        location->setText(QCoreApplication::translate("weatherView", "TextLabel", nullptr));
#if QT_CONFIG(tooltip)
        editLoc->setToolTip(QCoreApplication::translate("weatherView", "Change Location", nullptr));
#endif // QT_CONFIG(tooltip)
        editLoc->setText(QCoreApplication::translate("weatherView", "Change Location", nullptr));
        wStatus->setText(QCoreApplication::translate("weatherView", "Status", nullptr));
        grpMoreData->setTitle(QCoreApplication::translate("weatherView", "More Data", nullptr));
        tHumd->setText(QCoreApplication::translate("weatherView", "Humidity: %", nullptr));
        tPress->setText(QCoreApplication::translate("weatherView", "Pressure: hPa", nullptr));
        tDewT->setText(QCoreApplication::translate("weatherView", "Dew Point Temp: C", nullptr));
        tFog->setText(QCoreApplication::translate("weatherView", "Fog: %", nullptr));
        tPrec->setText(QCoreApplication::translate("weatherView", "Precipitation: %", nullptr));
        tCloud->setText(QCoreApplication::translate("weatherView", "Cloud: %", nullptr));
        tWind->setText(QCoreApplication::translate("weatherView", "Wind: speedm/s direction\302\260 S/N/E/W", nullptr));
        grpAstroData->setTitle(QCoreApplication::translate("weatherView", "Astronomical Data  ", nullptr));
        sunrise->setText(QCoreApplication::translate("weatherView", "Sunrise: hh:mm AP", nullptr));
        sunset->setText(QCoreApplication::translate("weatherView", "Sunset: hh:mm AP", nullptr));
        moonrise->setText(QCoreApplication::translate("weatherView", "Moonrise: hh:mm AP", nullptr));
        moonset->setText(QCoreApplication::translate("weatherView", "Moonset: hh:mm AP", nullptr));
        grpHourlyFc->setTitle(QCoreApplication::translate("weatherView", "Hourly forecasts  ", nullptr));
        grpDailyFc->setTitle(QCoreApplication::translate("weatherView", "Daily forecasts  ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class weatherView: public Ui_weatherView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEATHERVIEW_H
