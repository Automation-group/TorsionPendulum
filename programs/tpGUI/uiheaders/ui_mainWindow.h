/********************************************************************************
** Form generated from reading UI file 'mainWindow.ui'
**
** Created: Fri Jul 13 17:15:01 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "qwt_plot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QToolButton *tbSettings;
    QPushButton *pbOscillograph;
    QToolButton *tbPendulumView;
    QToolButton *bPause;
    QToolButton *bStart;
    QToolButton *bStop;
    QToolButton *bExit;
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QGridLayout *gridLayout;
    QwtPlot *qwtpMainData;
    QLabel *lCorell;
    QSlider *vsCorell;
    QWidget *tab_4;
    QVBoxLayout *vboxLayout1;
    QwtPlot *qwtpTemperature;
    QHBoxLayout *hboxLayout1;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout1;
    QLabel *label_20;
    QLabel *lPatternLenght;
    QLabel *label_21;
    QLabel *lPatternWidth;
    QLabel *label_22;
    QLabel *lPatternThickness;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_25;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout2;
    QLabel *label_26;
    QLabel *lPendulumM1;
    QLabel *label_27;
    QLabel *label_28;
    QLabel *lPendulumM2;
    QLabel *label_29;
    QLabel *label_30;
    QLabel *lPendulumR;
    QLabel *label_31;
    QLabel *label_32;
    QLabel *lPendulumKb;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout3;
    QLabel *label_33;
    QLabel *lTemperature;
    QLabel *label_34;
    QLabel *label_35;
    QLabel *lMetakonPower;
    QLabel *label_36;
    QLabel *label_37;
    QLabel *label_38;
    QLabel *lHeatingSpeed;
    QSpacerItem *spacerItem;
    QGroupBox *groupBox;
    QVBoxLayout *vboxLayout2;
    QCheckBox *cbCooling;
    QSpacerItem *spacerItem1;

    void setupUi(QDialog *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(699, 643);
        vboxLayout = new QVBoxLayout(MainWindow);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        tbSettings = new QToolButton(MainWindow);
        tbSettings->setObjectName(QString::fromUtf8("tbSettings"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tbSettings->sizePolicy().hasHeightForWidth());
        tbSettings->setSizePolicy(sizePolicy);

        hboxLayout->addWidget(tbSettings);

        pbOscillograph = new QPushButton(MainWindow);
        pbOscillograph->setObjectName(QString::fromUtf8("pbOscillograph"));

        hboxLayout->addWidget(pbOscillograph);

        tbPendulumView = new QToolButton(MainWindow);
        tbPendulumView->setObjectName(QString::fromUtf8("tbPendulumView"));
        sizePolicy.setHeightForWidth(tbPendulumView->sizePolicy().hasHeightForWidth());
        tbPendulumView->setSizePolicy(sizePolicy);

        hboxLayout->addWidget(tbPendulumView);

        bPause = new QToolButton(MainWindow);
        bPause->setObjectName(QString::fromUtf8("bPause"));
        bPause->setEnabled(true);
        sizePolicy.setHeightForWidth(bPause->sizePolicy().hasHeightForWidth());
        bPause->setSizePolicy(sizePolicy);
        bPause->setCheckable(true);

        hboxLayout->addWidget(bPause);

        bStart = new QToolButton(MainWindow);
        bStart->setObjectName(QString::fromUtf8("bStart"));
        sizePolicy.setHeightForWidth(bStart->sizePolicy().hasHeightForWidth());
        bStart->setSizePolicy(sizePolicy);

        hboxLayout->addWidget(bStart);

        bStop = new QToolButton(MainWindow);
        bStop->setObjectName(QString::fromUtf8("bStop"));
        bStop->setEnabled(false);
        sizePolicy.setHeightForWidth(bStop->sizePolicy().hasHeightForWidth());
        bStop->setSizePolicy(sizePolicy);

        hboxLayout->addWidget(bStop);

        bExit = new QToolButton(MainWindow);
        bExit->setObjectName(QString::fromUtf8("bExit"));
        sizePolicy.setHeightForWidth(bExit->sizePolicy().hasHeightForWidth());
        bExit->setSizePolicy(sizePolicy);

        hboxLayout->addWidget(bExit);


        vboxLayout->addLayout(hboxLayout);

        tabWidget = new QTabWidget(MainWindow);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayout = new QGridLayout(tab_3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        qwtpMainData = new QwtPlot(tab_3);
        qwtpMainData->setObjectName(QString::fromUtf8("qwtpMainData"));

        gridLayout->addWidget(qwtpMainData, 0, 0, 2, 1);

        lCorell = new QLabel(tab_3);
        lCorell->setObjectName(QString::fromUtf8("lCorell"));

        gridLayout->addWidget(lCorell, 0, 1, 1, 1);

        vsCorell = new QSlider(tab_3);
        vsCorell->setObjectName(QString::fromUtf8("vsCorell"));
        vsCorell->setMinimum(50);
        vsCorell->setMaximum(100);
        vsCorell->setValue(95);
        vsCorell->setOrientation(Qt::Vertical);

        gridLayout->addWidget(vsCorell, 1, 1, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        vboxLayout1 = new QVBoxLayout(tab_4);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        qwtpTemperature = new QwtPlot(tab_4);
        qwtpTemperature->setObjectName(QString::fromUtf8("qwtpTemperature"));

        vboxLayout1->addWidget(qwtpTemperature);

        tabWidget->addTab(tab_4, QString());

        vboxLayout->addWidget(tabWidget);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        groupBox_4 = new QGroupBox(MainWindow);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout1 = new QGridLayout(groupBox_4);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        label_20 = new QLabel(groupBox_4);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        gridLayout1->addWidget(label_20, 0, 0, 1, 1);

        lPatternLenght = new QLabel(groupBox_4);
        lPatternLenght->setObjectName(QString::fromUtf8("lPatternLenght"));

        gridLayout1->addWidget(lPatternLenght, 0, 1, 1, 1);

        label_21 = new QLabel(groupBox_4);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        gridLayout1->addWidget(label_21, 1, 0, 1, 1);

        lPatternWidth = new QLabel(groupBox_4);
        lPatternWidth->setObjectName(QString::fromUtf8("lPatternWidth"));

        gridLayout1->addWidget(lPatternWidth, 1, 1, 1, 1);

        label_22 = new QLabel(groupBox_4);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        gridLayout1->addWidget(label_22, 2, 0, 1, 1);

        lPatternThickness = new QLabel(groupBox_4);
        lPatternThickness->setObjectName(QString::fromUtf8("lPatternThickness"));

        gridLayout1->addWidget(lPatternThickness, 2, 1, 1, 1);

        label_23 = new QLabel(groupBox_4);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        gridLayout1->addWidget(label_23, 0, 2, 1, 1);

        label_24 = new QLabel(groupBox_4);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        gridLayout1->addWidget(label_24, 1, 2, 1, 1);

        label_25 = new QLabel(groupBox_4);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        gridLayout1->addWidget(label_25, 2, 2, 1, 1);


        hboxLayout1->addWidget(groupBox_4);

        groupBox_5 = new QGroupBox(MainWindow);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        gridLayout2 = new QGridLayout(groupBox_5);
        gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
        label_26 = new QLabel(groupBox_5);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        gridLayout2->addWidget(label_26, 0, 0, 1, 1);

        lPendulumM1 = new QLabel(groupBox_5);
        lPendulumM1->setObjectName(QString::fromUtf8("lPendulumM1"));

        gridLayout2->addWidget(lPendulumM1, 0, 1, 1, 1);

        label_27 = new QLabel(groupBox_5);
        label_27->setObjectName(QString::fromUtf8("label_27"));

        gridLayout2->addWidget(label_27, 0, 2, 1, 1);

        label_28 = new QLabel(groupBox_5);
        label_28->setObjectName(QString::fromUtf8("label_28"));

        gridLayout2->addWidget(label_28, 1, 0, 1, 1);

        lPendulumM2 = new QLabel(groupBox_5);
        lPendulumM2->setObjectName(QString::fromUtf8("lPendulumM2"));

        gridLayout2->addWidget(lPendulumM2, 1, 1, 1, 1);

        label_29 = new QLabel(groupBox_5);
        label_29->setObjectName(QString::fromUtf8("label_29"));

        gridLayout2->addWidget(label_29, 1, 2, 1, 1);

        label_30 = new QLabel(groupBox_5);
        label_30->setObjectName(QString::fromUtf8("label_30"));

        gridLayout2->addWidget(label_30, 2, 0, 1, 1);

        lPendulumR = new QLabel(groupBox_5);
        lPendulumR->setObjectName(QString::fromUtf8("lPendulumR"));

        gridLayout2->addWidget(lPendulumR, 2, 1, 1, 1);

        label_31 = new QLabel(groupBox_5);
        label_31->setObjectName(QString::fromUtf8("label_31"));

        gridLayout2->addWidget(label_31, 2, 2, 1, 1);

        label_32 = new QLabel(groupBox_5);
        label_32->setObjectName(QString::fromUtf8("label_32"));

        gridLayout2->addWidget(label_32, 3, 0, 1, 1);

        lPendulumKb = new QLabel(groupBox_5);
        lPendulumKb->setObjectName(QString::fromUtf8("lPendulumKb"));

        gridLayout2->addWidget(lPendulumKb, 3, 1, 1, 1);


        hboxLayout1->addWidget(groupBox_5);

        groupBox_6 = new QGroupBox(MainWindow);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        gridLayout3 = new QGridLayout(groupBox_6);
        gridLayout3->setObjectName(QString::fromUtf8("gridLayout3"));
        label_33 = new QLabel(groupBox_6);
        label_33->setObjectName(QString::fromUtf8("label_33"));

        gridLayout3->addWidget(label_33, 0, 0, 1, 1);

        lTemperature = new QLabel(groupBox_6);
        lTemperature->setObjectName(QString::fromUtf8("lTemperature"));

        gridLayout3->addWidget(lTemperature, 0, 1, 1, 1);

        label_34 = new QLabel(groupBox_6);
        label_34->setObjectName(QString::fromUtf8("label_34"));

        gridLayout3->addWidget(label_34, 0, 2, 1, 1);

        label_35 = new QLabel(groupBox_6);
        label_35->setObjectName(QString::fromUtf8("label_35"));

        gridLayout3->addWidget(label_35, 2, 0, 1, 1);

        lMetakonPower = new QLabel(groupBox_6);
        lMetakonPower->setObjectName(QString::fromUtf8("lMetakonPower"));

        gridLayout3->addWidget(lMetakonPower, 2, 1, 1, 1);

        label_36 = new QLabel(groupBox_6);
        label_36->setObjectName(QString::fromUtf8("label_36"));

        gridLayout3->addWidget(label_36, 2, 2, 1, 1);

        label_37 = new QLabel(groupBox_6);
        label_37->setObjectName(QString::fromUtf8("label_37"));

        gridLayout3->addWidget(label_37, 1, 0, 1, 1);

        label_38 = new QLabel(groupBox_6);
        label_38->setObjectName(QString::fromUtf8("label_38"));

        gridLayout3->addWidget(label_38, 1, 2, 1, 1);

        lHeatingSpeed = new QLabel(groupBox_6);
        lHeatingSpeed->setObjectName(QString::fromUtf8("lHeatingSpeed"));

        gridLayout3->addWidget(lHeatingSpeed, 1, 1, 1, 1);


        hboxLayout1->addWidget(groupBox_6);

        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacerItem);

        groupBox = new QGroupBox(MainWindow);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        vboxLayout2 = new QVBoxLayout(groupBox);
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        cbCooling = new QCheckBox(groupBox);
        cbCooling->setObjectName(QString::fromUtf8("cbCooling"));

        vboxLayout2->addWidget(cbCooling);

        spacerItem1 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        vboxLayout2->addItem(spacerItem1);


        hboxLayout1->addWidget(groupBox);


        vboxLayout->addLayout(hboxLayout1);


        retranslateUi(MainWindow);
        QObject::connect(bExit, SIGNAL(clicked()), bStop, SLOT(click()));
        QObject::connect(bExit, SIGNAL(clicked()), MainWindow, SLOT(close()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QDialog *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\232\321\200\321\203\321\202\320\270\320\273\321\214\320\275\321\213\320\271 \320\274\320\260\321\217\321\202\320\275\320\270\320\272", 0, QApplication::UnicodeUTF8));
        tbSettings->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", 0, QApplication::UnicodeUTF8));
        pbOscillograph->setText(QApplication::translate("MainWindow", "\320\236\321\201\321\206\320\270\320\273\320\273\320\276\320\263\321\200\320\260\321\204", 0, QApplication::UnicodeUTF8));
        tbPendulumView->setText(QApplication::translate("MainWindow", "\320\234\320\260\321\217\321\202\320\275\320\270\320\272", 0, QApplication::UnicodeUTF8));
        bPause->setText(QApplication::translate("MainWindow", "\320\237\320\260\321\203\320\267\320\260", 0, QApplication::UnicodeUTF8));
        bStart->setText(QApplication::translate("MainWindow", "\320\241\321\202\320\260\321\200\321\202", 0, QApplication::UnicodeUTF8));
        bStop->setText(QApplication::translate("MainWindow", "\320\241\321\202\320\276\320\277", 0, QApplication::UnicodeUTF8));
        bExit->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", 0, QApplication::UnicodeUTF8));
        lCorell->setText(QApplication::translate("MainWindow", "0.95", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "\320\234\320\276\320\264\321\203\320\273\321\214 \321\201\320\264\320\262\320\270\320\263\320\260 \320\270 Q\302\257\302\271", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "\320\242\320\265\320\274\320\277\320\265\321\200\320\260\321\202\321\203\321\200\320\260", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\320\236\320\261\321\200\320\260\320\267\320\265\321\206", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("MainWindow", "<b>\320\224\320\273\320\270\320\275\320\260", 0, QApplication::UnicodeUTF8));
        lPatternLenght->setText(QApplication::translate("MainWindow", "?", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("MainWindow", "<b>\320\250\320\270\321\200\320\270\320\275\320\260", 0, QApplication::UnicodeUTF8));
        lPatternWidth->setText(QApplication::translate("MainWindow", "?", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("MainWindow", "<b>\320\242\320\276\320\273\321\211\320\270\320\275\320\260", 0, QApplication::UnicodeUTF8));
        lPatternThickness->setText(QApplication::translate("MainWindow", "?", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("MainWindow", "\320\274\320\274", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("MainWindow", "\320\274\320\274", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("MainWindow", "\320\274\320\274", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "\320\234\320\260\321\217\321\202\320\275\320\270\320\272", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("MainWindow", "<b>\320\234\320\260\321\201\321\201\320\260 m1", 0, QApplication::UnicodeUTF8));
        lPendulumM1->setText(QApplication::translate("MainWindow", "?", 0, QApplication::UnicodeUTF8));
        label_27->setText(QApplication::translate("MainWindow", "\320\263", 0, QApplication::UnicodeUTF8));
        label_28->setText(QApplication::translate("MainWindow", "<b>\320\234\320\260\321\201\321\201\320\260 m2", 0, QApplication::UnicodeUTF8));
        lPendulumM2->setText(QApplication::translate("MainWindow", "?", 0, QApplication::UnicodeUTF8));
        label_29->setText(QApplication::translate("MainWindow", "\320\263", 0, QApplication::UnicodeUTF8));
        label_30->setText(QApplication::translate("MainWindow", "<b>\320\240\320\260\320\264\320\270\321\203\321\201", 0, QApplication::UnicodeUTF8));
        lPendulumR->setText(QApplication::translate("MainWindow", "?", 0, QApplication::UnicodeUTF8));
        label_31->setText(QApplication::translate("MainWindow", "\320\274\320\274", 0, QApplication::UnicodeUTF8));
        label_32->setText(QApplication::translate("MainWindow", "<b>\320\226\320\265\321\201\321\202\320\272\320\276\321\201\321\202\321\214", 0, QApplication::UnicodeUTF8));
        lPendulumKb->setText(QApplication::translate("MainWindow", "?", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "\320\242\320\265\321\200\320\274\320\276\320\272\320\260\320\274\320\265\321\200\320\260", 0, QApplication::UnicodeUTF8));
        label_33->setText(QApplication::translate("MainWindow", "<b>\320\242\320\265\320\274\320\277\320\265\321\200\320\260\321\202\321\203\321\200\320\260", 0, QApplication::UnicodeUTF8));
        lTemperature->setText(QApplication::translate("MainWindow", "?", 0, QApplication::UnicodeUTF8));
        label_34->setText(QApplication::translate("MainWindow", "\302\260C", 0, QApplication::UnicodeUTF8));
        label_35->setText(QApplication::translate("MainWindow", "<b>\320\234\320\276\321\211\320\275\320\276\321\201\321\202\321\214", 0, QApplication::UnicodeUTF8));
        lMetakonPower->setText(QApplication::translate("MainWindow", "?", 0, QApplication::UnicodeUTF8));
        label_36->setText(QApplication::translate("MainWindow", "%", 0, QApplication::UnicodeUTF8));
        label_37->setText(QApplication::translate("MainWindow", "<b>\320\241\320\272\320\276\321\200\320\276\321\201\321\202\321\214", 0, QApplication::UnicodeUTF8));
        label_38->setText(QApplication::translate("MainWindow", "\302\260C/\320\274\320\270\320\275", 0, QApplication::UnicodeUTF8));
        lHeatingSpeed->setText(QApplication::translate("MainWindow", "?", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\222\320\270\320\264", 0, QApplication::UnicodeUTF8));
        cbCooling->setText(QApplication::translate("MainWindow", "\320\236\321\205\320\273\320\260\320\266\320\264\320\265\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
