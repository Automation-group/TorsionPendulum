/********************************************************************************
** Form generated from reading UI file 'pendulumViewer.ui'
**
** Created: Fri Jul 13 17:15:01 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PENDULUMVIEWER_H
#define UI_PENDULUMVIEWER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "qwt_plot.h"

QT_BEGIN_NAMESPACE

class Ui_PendViewerForm
{
public:
    QVBoxLayout *vboxLayout;
    QwtPlot *qwtpShowPend;
    QHBoxLayout *hboxLayout;
    QLabel *label_2;
    QLabel *lNumber;
    QLabel *label_3;
    QLabel *lPeriod;
    QLabel *label_5;
    QLabel *lAmpl;
    QSpacerItem *spacerItem;
    QHBoxLayout *hboxLayout1;
    QLabel *label_7;
    QLabel *lZero;
    QLabel *label;
    QLabel *lCoeffCorrel;
    QSpacerItem *spacerItem1;
    QToolButton *tbPause;

    void setupUi(QWidget *PendViewerForm)
    {
        if (PendViewerForm->objectName().isEmpty())
            PendViewerForm->setObjectName(QString::fromUtf8("PendViewerForm"));
        PendViewerForm->resize(376, 311);
        vboxLayout = new QVBoxLayout(PendViewerForm);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        qwtpShowPend = new QwtPlot(PendViewerForm);
        qwtpShowPend->setObjectName(QString::fromUtf8("qwtpShowPend"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(qwtpShowPend->sizePolicy().hasHeightForWidth());
        qwtpShowPend->setSizePolicy(sizePolicy);

        vboxLayout->addWidget(qwtpShowPend);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        label_2 = new QLabel(PendViewerForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        hboxLayout->addWidget(label_2);

        lNumber = new QLabel(PendViewerForm);
        lNumber->setObjectName(QString::fromUtf8("lNumber"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lNumber->sizePolicy().hasHeightForWidth());
        lNumber->setSizePolicy(sizePolicy1);
        lNumber->setMinimumSize(QSize(50, 0));

        hboxLayout->addWidget(lNumber);

        label_3 = new QLabel(PendViewerForm);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        hboxLayout->addWidget(label_3);

        lPeriod = new QLabel(PendViewerForm);
        lPeriod->setObjectName(QString::fromUtf8("lPeriod"));
        sizePolicy1.setHeightForWidth(lPeriod->sizePolicy().hasHeightForWidth());
        lPeriod->setSizePolicy(sizePolicy1);
        lPeriod->setMinimumSize(QSize(50, 0));

        hboxLayout->addWidget(lPeriod);

        label_5 = new QLabel(PendViewerForm);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        hboxLayout->addWidget(label_5);

        lAmpl = new QLabel(PendViewerForm);
        lAmpl->setObjectName(QString::fromUtf8("lAmpl"));
        sizePolicy1.setHeightForWidth(lAmpl->sizePolicy().hasHeightForWidth());
        lAmpl->setSizePolicy(sizePolicy1);
        lAmpl->setMinimumSize(QSize(50, 0));

        hboxLayout->addWidget(lAmpl);

        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);


        vboxLayout->addLayout(hboxLayout);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        label_7 = new QLabel(PendViewerForm);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        hboxLayout1->addWidget(label_7);

        lZero = new QLabel(PendViewerForm);
        lZero->setObjectName(QString::fromUtf8("lZero"));
        sizePolicy1.setHeightForWidth(lZero->sizePolicy().hasHeightForWidth());
        lZero->setSizePolicy(sizePolicy1);
        lZero->setMinimumSize(QSize(50, 0));

        hboxLayout1->addWidget(lZero);

        label = new QLabel(PendViewerForm);
        label->setObjectName(QString::fromUtf8("label"));

        hboxLayout1->addWidget(label);

        lCoeffCorrel = new QLabel(PendViewerForm);
        lCoeffCorrel->setObjectName(QString::fromUtf8("lCoeffCorrel"));
        sizePolicy1.setHeightForWidth(lCoeffCorrel->sizePolicy().hasHeightForWidth());
        lCoeffCorrel->setSizePolicy(sizePolicy1);
        lCoeffCorrel->setMinimumSize(QSize(50, 0));

        hboxLayout1->addWidget(lCoeffCorrel);

        spacerItem1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacerItem1);

        tbPause = new QToolButton(PendViewerForm);
        tbPause->setObjectName(QString::fromUtf8("tbPause"));
        tbPause->setEnabled(true);
        tbPause->setCheckable(true);

        hboxLayout1->addWidget(tbPause);


        vboxLayout->addLayout(hboxLayout1);


        retranslateUi(PendViewerForm);

        QMetaObject::connectSlotsByName(PendViewerForm);
    } // setupUi

    void retranslateUi(QWidget *PendViewerForm)
    {
        PendViewerForm->setWindowTitle(QApplication::translate("PendViewerForm", "\320\234\320\260\321\217\321\202\320\275\320\270\320\272", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("PendViewerForm", "<b>\342\204\226", 0, QApplication::UnicodeUTF8));
        lNumber->setText(QApplication::translate("PendViewerForm", "0", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("PendViewerForm", "<b>\320\237\320\265\321\200\320\270\320\276\320\264,\320\274\321\201", 0, QApplication::UnicodeUTF8));
        lPeriod->setText(QApplication::translate("PendViewerForm", "0", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("PendViewerForm", "<b>\320\220\320\274\320\277\320\273\320\270\321\202\321\203\320\264\320\260", 0, QApplication::UnicodeUTF8));
        lAmpl->setText(QApplication::translate("PendViewerForm", "0", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("PendViewerForm", "<b>\320\235\320\276\320\273\321\214", 0, QApplication::UnicodeUTF8));
        lZero->setText(QApplication::translate("PendViewerForm", "0", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("PendViewerForm", "<b>\320\232\320\276\321\215\321\204. \320\272\320\276\321\200\321\200\320\265\320\273.", 0, QApplication::UnicodeUTF8));
        lCoeffCorrel->setText(QApplication::translate("PendViewerForm", "?", 0, QApplication::UnicodeUTF8));
        tbPause->setText(QApplication::translate("PendViewerForm", "\320\277\320\260\321\203\320\267\320\260", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PendViewerForm: public Ui_PendViewerForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PENDULUMVIEWER_H
