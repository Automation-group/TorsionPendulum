/********************************************************************************
** Form generated from reading UI file 'tposcillographDialog.ui'
**
** Created: Fri Jul 13 17:15:01 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TPOSCILLOGRAPHDIALOG_H
#define UI_TPOSCILLOGRAPHDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include "qwt_plot.h"

QT_BEGIN_NAMESPACE

class Ui_TPOscillographDialog
{
public:
    QVBoxLayout *vboxLayout;
    QwtPlot *qwtpOscillograph;
    QHBoxLayout *hboxLayout;
    QPushButton *pbStart;
    QPushButton *pbStop;
    QFrame *line;
    QPushButton *pbClearResistor;
    QSpacerItem *spacerItem;
    QPushButton *pbExit;

    void setupUi(QDialog *TPOscillographDialog)
    {
        if (TPOscillographDialog->objectName().isEmpty())
            TPOscillographDialog->setObjectName(QString::fromUtf8("TPOscillographDialog"));
        TPOscillographDialog->resize(567, 466);
        vboxLayout = new QVBoxLayout(TPOscillographDialog);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        qwtpOscillograph = new QwtPlot(TPOscillographDialog);
        qwtpOscillograph->setObjectName(QString::fromUtf8("qwtpOscillograph"));

        vboxLayout->addWidget(qwtpOscillograph);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        pbStart = new QPushButton(TPOscillographDialog);
        pbStart->setObjectName(QString::fromUtf8("pbStart"));

        hboxLayout->addWidget(pbStart);

        pbStop = new QPushButton(TPOscillographDialog);
        pbStop->setObjectName(QString::fromUtf8("pbStop"));

        hboxLayout->addWidget(pbStop);

        line = new QFrame(TPOscillographDialog);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        hboxLayout->addWidget(line);

        pbClearResistor = new QPushButton(TPOscillographDialog);
        pbClearResistor->setObjectName(QString::fromUtf8("pbClearResistor"));

        hboxLayout->addWidget(pbClearResistor);

        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        pbExit = new QPushButton(TPOscillographDialog);
        pbExit->setObjectName(QString::fromUtf8("pbExit"));

        hboxLayout->addWidget(pbExit);


        vboxLayout->addLayout(hboxLayout);


        retranslateUi(TPOscillographDialog);
        QObject::connect(pbExit, SIGNAL(clicked()), TPOscillographDialog, SLOT(close()));
        QObject::connect(pbExit, SIGNAL(clicked()), pbStop, SLOT(click()));

        QMetaObject::connectSlotsByName(TPOscillographDialog);
    } // setupUi

    void retranslateUi(QDialog *TPOscillographDialog)
    {
        TPOscillographDialog->setWindowTitle(QApplication::translate("TPOscillographDialog", "\320\236\321\201\321\206\320\270\320\273\320\273\320\276\320\263\321\200\320\260\321\204", 0, QApplication::UnicodeUTF8));
        pbStart->setText(QApplication::translate("TPOscillographDialog", "\320\241\321\202\320\260\321\200\321\202", 0, QApplication::UnicodeUTF8));
        pbStop->setText(QApplication::translate("TPOscillographDialog", "\320\241\321\202\320\276\320\277", 0, QApplication::UnicodeUTF8));
        pbClearResistor->setText(QApplication::translate("TPOscillographDialog", "\320\241\320\261\321\200\320\276\321\201\320\270\321\202\321\214 \321\200\320\265\320\267\320\270\321\201\321\202\320\276\321\200", 0, QApplication::UnicodeUTF8));
        pbExit->setText(QApplication::translate("TPOscillographDialog", "\320\222\321\213\321\205\320\276\320\264", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TPOscillographDialog: public Ui_TPOscillographDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TPOSCILLOGRAPHDIALOG_H
