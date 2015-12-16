/********************************************************************************
** Form generated from reading UI file 'calibrateFurnace.ui'
**
** Created: Fri Jul 13 17:15:01 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALIBRATEFURNACE_H
#define UI_CALIBRATEFURNACE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include "qwt_plot.h"

QT_BEGIN_NAMESPACE

class Ui_CalibrateFurnaceDialog
{
public:
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QLabel *label;
    QSpinBox *sbSetPoint;
    QSpacerItem *spacerItem;
    QPushButton *pbStart;
    QPushButton *pbStop;
    QFrame *line;
    QPushButton *pbExit;
    QwtPlot *qwtpData;
    QHBoxLayout *hboxLayout1;
    QLabel *label_2;
    QLabel *lTIntegr;
    QLabel *label_3;
    QLabel *lTDiff;
    QLabel *label_4;
    QLabel *lPb;
    QSpacerItem *spacerItem1;
    QPushButton *pbSave;

    void setupUi(QDialog *CalibrateFurnaceDialog)
    {
        if (CalibrateFurnaceDialog->objectName().isEmpty())
            CalibrateFurnaceDialog->setObjectName(QString::fromUtf8("CalibrateFurnaceDialog"));
        CalibrateFurnaceDialog->setWindowModality(Qt::ApplicationModal);
        CalibrateFurnaceDialog->resize(617, 430);
        vboxLayout = new QVBoxLayout(CalibrateFurnaceDialog);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        label = new QLabel(CalibrateFurnaceDialog);
        label->setObjectName(QString::fromUtf8("label"));

        hboxLayout->addWidget(label);

        sbSetPoint = new QSpinBox(CalibrateFurnaceDialog);
        sbSetPoint->setObjectName(QString::fromUtf8("sbSetPoint"));
        sbSetPoint->setMaximum(1000);
        sbSetPoint->setSingleStep(50);

        hboxLayout->addWidget(sbSetPoint);

        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        pbStart = new QPushButton(CalibrateFurnaceDialog);
        pbStart->setObjectName(QString::fromUtf8("pbStart"));

        hboxLayout->addWidget(pbStart);

        pbStop = new QPushButton(CalibrateFurnaceDialog);
        pbStop->setObjectName(QString::fromUtf8("pbStop"));

        hboxLayout->addWidget(pbStop);

        line = new QFrame(CalibrateFurnaceDialog);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        hboxLayout->addWidget(line);

        pbExit = new QPushButton(CalibrateFurnaceDialog);
        pbExit->setObjectName(QString::fromUtf8("pbExit"));

        hboxLayout->addWidget(pbExit);


        vboxLayout->addLayout(hboxLayout);

        qwtpData = new QwtPlot(CalibrateFurnaceDialog);
        qwtpData->setObjectName(QString::fromUtf8("qwtpData"));

        vboxLayout->addWidget(qwtpData);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        label_2 = new QLabel(CalibrateFurnaceDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        hboxLayout1->addWidget(label_2);

        lTIntegr = new QLabel(CalibrateFurnaceDialog);
        lTIntegr->setObjectName(QString::fromUtf8("lTIntegr"));

        hboxLayout1->addWidget(lTIntegr);

        label_3 = new QLabel(CalibrateFurnaceDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        hboxLayout1->addWidget(label_3);

        lTDiff = new QLabel(CalibrateFurnaceDialog);
        lTDiff->setObjectName(QString::fromUtf8("lTDiff"));

        hboxLayout1->addWidget(lTDiff);

        label_4 = new QLabel(CalibrateFurnaceDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        hboxLayout1->addWidget(label_4);

        lPb = new QLabel(CalibrateFurnaceDialog);
        lPb->setObjectName(QString::fromUtf8("lPb"));

        hboxLayout1->addWidget(lPb);

        spacerItem1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacerItem1);

        pbSave = new QPushButton(CalibrateFurnaceDialog);
        pbSave->setObjectName(QString::fromUtf8("pbSave"));
        pbSave->setEnabled(false);

        hboxLayout1->addWidget(pbSave);


        vboxLayout->addLayout(hboxLayout1);


        retranslateUi(CalibrateFurnaceDialog);
        QObject::connect(pbExit, SIGNAL(clicked()), CalibrateFurnaceDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(CalibrateFurnaceDialog);
    } // setupUi

    void retranslateUi(QDialog *CalibrateFurnaceDialog)
    {
        CalibrateFurnaceDialog->setWindowTitle(QApplication::translate("CalibrateFurnaceDialog", "\320\235\320\260\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260 \321\200\320\265\320\266\320\270\320\274\320\260 \321\200\320\260\320\261\320\276\321\202\321\213 \321\202\320\265\321\200\320\274\320\276\320\272\320\260\320\274\320\265\321\200\321\213", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CalibrateFurnaceDialog", "\320\243\321\201\321\202\320\260\320\262\320\272\320\260", 0, QApplication::UnicodeUTF8));
        sbSetPoint->setSuffix(QApplication::translate("CalibrateFurnaceDialog", "\302\260C", 0, QApplication::UnicodeUTF8));
        pbStart->setText(QApplication::translate("CalibrateFurnaceDialog", "\320\241\321\202\320\260\321\200\321\202", 0, QApplication::UnicodeUTF8));
        pbStop->setText(QApplication::translate("CalibrateFurnaceDialog", "\320\241\321\202\320\276\320\277", 0, QApplication::UnicodeUTF8));
        pbExit->setText(QApplication::translate("CalibrateFurnaceDialog", "\320\222\321\213\321\205\320\276\320\264", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("CalibrateFurnaceDialog", "<b>\320\237\320\276\321\201\321\202. \320\270\320\275\321\202\320\265\320\263\321\200.", 0, QApplication::UnicodeUTF8));
        lTIntegr->setText(QApplication::translate("CalibrateFurnaceDialog", "?", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("CalibrateFurnaceDialog", "<b>\320\237\320\276\321\201\321\202. \320\264\320\270\321\204\321\204.", 0, QApplication::UnicodeUTF8));
        lTDiff->setText(QApplication::translate("CalibrateFurnaceDialog", "?", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("CalibrateFurnaceDialog", "<b>\320\227\320\276\320\275\320\260 \320\277\321\200\320\276\320\277.", 0, QApplication::UnicodeUTF8));
        lPb->setText(QApplication::translate("CalibrateFurnaceDialog", "?", 0, QApplication::UnicodeUTF8));
        pbSave->setText(QApplication::translate("CalibrateFurnaceDialog", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CalibrateFurnaceDialog: public Ui_CalibrateFurnaceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALIBRATEFURNACE_H
