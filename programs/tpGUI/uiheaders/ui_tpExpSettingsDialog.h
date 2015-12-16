/********************************************************************************
** Form generated from reading UI file 'tpExpSettingsDialog.ui'
**
** Created: Fri Jul 13 17:15:01 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TPEXPSETTINGSDIALOG_H
#define UI_TPEXPSETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_ExpSettingsDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QSpinBox *sbFluctCount;
    QLabel *label_6;
    QSpinBox *sbSkipFluctCount;
    QLabel *label_2;
    QDoubleSpinBox *dsbFluctMinAmpl;
    QLabel *label_3;
    QSpinBox *sbDeviationTime;
    QLabel *label_4;
    QSpinBox *sbHeatingSpeed;
    QLabel *label_5;
    QCheckBox *cbZeroControl;
    QPushButton *pbOk;
    QPushButton *pbCancel;
    QLabel *label_7;
    QSpinBox *sbMaxTemperature;

    void setupUi(QDialog *ExpSettingsDialog)
    {
        if (ExpSettingsDialog->objectName().isEmpty())
            ExpSettingsDialog->setObjectName(QString::fromUtf8("ExpSettingsDialog"));
        ExpSettingsDialog->setWindowModality(Qt::ApplicationModal);
        ExpSettingsDialog->resize(289, 256);
        gridLayout = new QGridLayout(ExpSettingsDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(ExpSettingsDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        sbFluctCount = new QSpinBox(ExpSettingsDialog);
        sbFluctCount->setObjectName(QString::fromUtf8("sbFluctCount"));
        sbFluctCount->setMinimum(1);
        sbFluctCount->setMaximum(6000);
        sbFluctCount->setSingleStep(5);
        sbFluctCount->setValue(60);

        gridLayout->addWidget(sbFluctCount, 1, 1, 1, 1);

        label_6 = new QLabel(ExpSettingsDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 2, 0, 1, 1);

        sbSkipFluctCount = new QSpinBox(ExpSettingsDialog);
        sbSkipFluctCount->setObjectName(QString::fromUtf8("sbSkipFluctCount"));
        sbSkipFluctCount->setMinimum(1);
        sbSkipFluctCount->setMaximum(6000);
        sbSkipFluctCount->setSingleStep(5);
        sbSkipFluctCount->setValue(5);

        gridLayout->addWidget(sbSkipFluctCount, 2, 1, 1, 1);

        label_2 = new QLabel(ExpSettingsDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        dsbFluctMinAmpl = new QDoubleSpinBox(ExpSettingsDialog);
        dsbFluctMinAmpl->setObjectName(QString::fromUtf8("dsbFluctMinAmpl"));
        dsbFluctMinAmpl->setMaximum(10);
        dsbFluctMinAmpl->setValue(2);

        gridLayout->addWidget(dsbFluctMinAmpl, 3, 1, 1, 1);

        label_3 = new QLabel(ExpSettingsDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        sbDeviationTime = new QSpinBox(ExpSettingsDialog);
        sbDeviationTime->setObjectName(QString::fromUtf8("sbDeviationTime"));
        sbDeviationTime->setMinimum(500);
        sbDeviationTime->setMaximum(60000);
        sbDeviationTime->setSingleStep(500);
        sbDeviationTime->setValue(2000);

        gridLayout->addWidget(sbDeviationTime, 4, 1, 1, 1);

        label_4 = new QLabel(ExpSettingsDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 5, 0, 1, 1);

        sbHeatingSpeed = new QSpinBox(ExpSettingsDialog);
        sbHeatingSpeed->setObjectName(QString::fromUtf8("sbHeatingSpeed"));
        sbHeatingSpeed->setMinimum(-10);
        sbHeatingSpeed->setMaximum(10);
        sbHeatingSpeed->setValue(4);

        gridLayout->addWidget(sbHeatingSpeed, 5, 1, 1, 1);

        label_5 = new QLabel(ExpSettingsDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 6, 0, 1, 1);

        cbZeroControl = new QCheckBox(ExpSettingsDialog);
        cbZeroControl->setObjectName(QString::fromUtf8("cbZeroControl"));

        gridLayout->addWidget(cbZeroControl, 6, 1, 1, 1);

        pbOk = new QPushButton(ExpSettingsDialog);
        pbOk->setObjectName(QString::fromUtf8("pbOk"));

        gridLayout->addWidget(pbOk, 7, 0, 1, 1);

        pbCancel = new QPushButton(ExpSettingsDialog);
        pbCancel->setObjectName(QString::fromUtf8("pbCancel"));

        gridLayout->addWidget(pbCancel, 7, 1, 1, 1);

        label_7 = new QLabel(ExpSettingsDialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 0, 0, 1, 1);

        sbMaxTemperature = new QSpinBox(ExpSettingsDialog);
        sbMaxTemperature->setObjectName(QString::fromUtf8("sbMaxTemperature"));
        sbMaxTemperature->setMaximum(1000);

        gridLayout->addWidget(sbMaxTemperature, 0, 1, 1, 1);


        retranslateUi(ExpSettingsDialog);
        QObject::connect(pbCancel, SIGNAL(clicked()), ExpSettingsDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(ExpSettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *ExpSettingsDialog)
    {
        ExpSettingsDialog->setWindowTitle(QApplication::translate("ExpSettingsDialog", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ExpSettingsDialog", "\320\232\320\276\320\273-\320\262\320\276 \320\272\320\276\320\273\320\265\320\261\320\260\320\275\320\270\320\271", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("ExpSettingsDialog", "\320\237\321\200\320\276\320\277\321\203\321\201\320\272\320\260\321\202\321\214 \320\272\320\276\320\273\320\265\320\261\320\260\320\275\320\270\320\271", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ExpSettingsDialog", "\320\234\320\270\320\275. \320\260\320\274\320\277\320\273\320\270\321\202\321\203\320\264\320\260", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ExpSettingsDialog", "\320\222\321\200\320\265\320\274\321\217 \320\276\321\202\320\272\320\273\320\276\320\275\320\265\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
        sbDeviationTime->setSuffix(QApplication::translate("ExpSettingsDialog", "\320\274\321\201", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ExpSettingsDialog", "\320\241\320\272\320\276\321\200\320\276\321\201\321\202\321\214 \320\275\320\260\320\263\321\200\320\265\320\262\320\260", 0, QApplication::UnicodeUTF8));
        sbHeatingSpeed->setSuffix(QApplication::translate("ExpSettingsDialog", "\302\260C/\320\274\320\270\320\275", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("ExpSettingsDialog", "\320\220\320\262\321\202. \320\277\320\276\320\264\321\201\321\202\321\200\320\276\320\271\320\272\320\260 \320\275\321\203\320\273\321\217", 0, QApplication::UnicodeUTF8));
        cbZeroControl->setText(QApplication::translate("ExpSettingsDialog", "\320\262\320\272\320\273\321\216\321\207\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        pbOk->setText(QApplication::translate("ExpSettingsDialog", "\320\237\321\200\320\270\320\275\321\217\321\202\321\214", 0, QApplication::UnicodeUTF8));
        pbCancel->setText(QApplication::translate("ExpSettingsDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("ExpSettingsDialog", "\320\242\320\265\320\274\320\277\320\265\321\200\320\260\321\202\321\203\321\200\320\260 \320\276\321\205\320\273\320\260\320\266\320\264\320\265\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ExpSettingsDialog: public Ui_ExpSettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TPEXPSETTINGSDIALOG_H
