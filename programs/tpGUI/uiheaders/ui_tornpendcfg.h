/********************************************************************************
** Form generated from reading UI file 'tornpendcfg.ui'
**
** Created: Fri Jul 13 17:15:01 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TORNPENDCFG_H
#define UI_TORNPENDCFG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TornPendCfgForm
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *leSerialPortName;
    QLabel *label_2;
    QDoubleSpinBox *dsbKb;
    QLabel *label_3;
    QDoubleSpinBox *dsbJp;
    QLabel *label_4;
    QDoubleSpinBox *dsbQp;

    void setupUi(QWidget *TornPendCfgForm)
    {
        if (TornPendCfgForm->objectName().isEmpty())
            TornPendCfgForm->setObjectName(QString::fromUtf8("TornPendCfgForm"));
        TornPendCfgForm->resize(299, 124);
        gridLayout = new QGridLayout(TornPendCfgForm);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(TornPendCfgForm);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        leSerialPortName = new QLineEdit(TornPendCfgForm);
        leSerialPortName->setObjectName(QString::fromUtf8("leSerialPortName"));

        gridLayout->addWidget(leSerialPortName, 0, 1, 1, 1);

        label_2 = new QLabel(TornPendCfgForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        dsbKb = new QDoubleSpinBox(TornPendCfgForm);
        dsbKb->setObjectName(QString::fromUtf8("dsbKb"));
        dsbKb->setDecimals(4);
        dsbKb->setMaximum(4);

        gridLayout->addWidget(dsbKb, 1, 1, 1, 1);

        label_3 = new QLabel(TornPendCfgForm);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        dsbJp = new QDoubleSpinBox(TornPendCfgForm);
        dsbJp->setObjectName(QString::fromUtf8("dsbJp"));
        dsbJp->setMaximum(500000);

        gridLayout->addWidget(dsbJp, 2, 1, 1, 1);

        label_4 = new QLabel(TornPendCfgForm);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        dsbQp = new QDoubleSpinBox(TornPendCfgForm);
        dsbQp->setObjectName(QString::fromUtf8("dsbQp"));
        dsbQp->setDecimals(3);

        gridLayout->addWidget(dsbQp, 3, 1, 1, 1);


        retranslateUi(TornPendCfgForm);

        QMetaObject::connectSlotsByName(TornPendCfgForm);
    } // setupUi

    void retranslateUi(QWidget *TornPendCfgForm)
    {
        TornPendCfgForm->setWindowTitle(QApplication::translate("TornPendCfgForm", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("TornPendCfgForm", "\320\237\320\276\321\201\320\273\320\265\320\264\320\276\320\262\320\260\321\202\321\214\320\275\321\213\320\271 \320\277\320\276\321\200\321\202", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("TornPendCfgForm", "\320\226\320\265\321\201\321\202\320\272\320\276\321\201\321\202\321\214 \320\277\320\276\320\264\320\262\320\265\321\201\320\260", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("TornPendCfgForm", "\320\234\320\276\320\274\320\265\320\275\321\202 \320\270\320\275\320\265\321\200\321\206\320\270\320\270 J<sub>0</sub>", 0, QApplication::UnicodeUTF8));
        dsbJp->setSuffix(QApplication::translate("TornPendCfgForm", "E-6", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("TornPendCfgForm", "\320\222\320\275\321\203\321\202\321\200\320\265\320\275\320\275\320\265 \321\202\321\200\320\265\320\275\320\270\320\265 \320\262 \320\277\320\276\320\264\320\262\320\265\321\201\320\265", 0, QApplication::UnicodeUTF8));
        dsbQp->setSuffix(QApplication::translate("TornPendCfgForm", "E-3", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TornPendCfgForm: public Ui_TornPendCfgForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TORNPENDCFG_H
