/********************************************************************************
** Form generated from reading UI file 'metakoncfg.ui'
**
** Created: Fri Jul 13 17:15:01 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_METAKONCFG_H
#define UI_METAKONCFG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MetakonCfgForm
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *leSerialPortName;
    QLabel *label_2;
    QComboBox *cbBaudRate;
    QLabel *label_3;
    QSpinBox *sbDevAddress;
    QLabel *label_4;
    QSpinBox *sbChannel;
    QLabel *label_5;
    QSpinBox *sbIntegr;
    QLabel *label_6;
    QSpinBox *sbDiff;
    QLabel *label_7;
    QSpinBox *sbPb;

    void setupUi(QWidget *MetakonCfgForm)
    {
        if (MetakonCfgForm->objectName().isEmpty())
            MetakonCfgForm->setObjectName(QString::fromUtf8("MetakonCfgForm"));
        MetakonCfgForm->resize(317, 220);
        gridLayout = new QGridLayout(MetakonCfgForm);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(MetakonCfgForm);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        leSerialPortName = new QLineEdit(MetakonCfgForm);
        leSerialPortName->setObjectName(QString::fromUtf8("leSerialPortName"));

        gridLayout->addWidget(leSerialPortName, 0, 1, 1, 1);

        label_2 = new QLabel(MetakonCfgForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        cbBaudRate = new QComboBox(MetakonCfgForm);
        cbBaudRate->setObjectName(QString::fromUtf8("cbBaudRate"));
        cbBaudRate->setEditable(false);

        gridLayout->addWidget(cbBaudRate, 1, 1, 1, 1);

        label_3 = new QLabel(MetakonCfgForm);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        sbDevAddress = new QSpinBox(MetakonCfgForm);
        sbDevAddress->setObjectName(QString::fromUtf8("sbDevAddress"));
        sbDevAddress->setMaximum(255);

        gridLayout->addWidget(sbDevAddress, 2, 1, 1, 1);

        label_4 = new QLabel(MetakonCfgForm);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        sbChannel = new QSpinBox(MetakonCfgForm);
        sbChannel->setObjectName(QString::fromUtf8("sbChannel"));
        sbChannel->setMaximum(2);

        gridLayout->addWidget(sbChannel, 3, 1, 1, 1);

        label_5 = new QLabel(MetakonCfgForm);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        sbIntegr = new QSpinBox(MetakonCfgForm);
        sbIntegr->setObjectName(QString::fromUtf8("sbIntegr"));
        sbIntegr->setMinimum(1);
        sbIntegr->setMaximum(30000);
        sbIntegr->setSingleStep(1000);

        gridLayout->addWidget(sbIntegr, 4, 1, 1, 1);

        label_6 = new QLabel(MetakonCfgForm);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        sbDiff = new QSpinBox(MetakonCfgForm);
        sbDiff->setObjectName(QString::fromUtf8("sbDiff"));
        sbDiff->setMaximum(255);
        sbDiff->setSingleStep(10);

        gridLayout->addWidget(sbDiff, 5, 1, 1, 1);

        label_7 = new QLabel(MetakonCfgForm);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 6, 0, 1, 1);

        sbPb = new QSpinBox(MetakonCfgForm);
        sbPb->setObjectName(QString::fromUtf8("sbPb"));
        sbPb->setMinimum(1);
        sbPb->setMaximum(9999);

        gridLayout->addWidget(sbPb, 6, 1, 1, 1);


        retranslateUi(MetakonCfgForm);

        cbBaudRate->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MetakonCfgForm);
    } // setupUi

    void retranslateUi(QWidget *MetakonCfgForm)
    {
        MetakonCfgForm->setWindowTitle(QApplication::translate("MetakonCfgForm", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MetakonCfgForm", "\320\237\320\276\321\201\320\273\320\265\320\264\320\276\320\262\320\260\321\202\320\265\320\273\321\214\320\275\321\213\320\271 \320\277\320\276\321\200\321\202", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MetakonCfgForm", "\320\241\320\272\320\276\321\200\320\276\321\201\321\202\321\214  \320\277\320\265\321\200\320\265\320\264\320\260\321\207\320\270", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MetakonCfgForm", "\320\220\320\264\321\200\320\265\321\201 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\260", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MetakonCfgForm", "\320\243\320\277\321\200\320\260\320\262\320\273\321\217\321\216\321\211\320\270\320\271 \320\272\320\260\320\275\320\260\320\273", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MetakonCfgForm", "\320\237\320\276\321\201\321\202\320\276\321\217\320\275\320\275\320\260\321\217 \320\270\320\275\321\202\320\265\320\263\321\200.", 0, QApplication::UnicodeUTF8));
        sbIntegr->setSuffix(QApplication::translate("MetakonCfgForm", "\321\201\320\265\320\272", 0, QApplication::UnicodeUTF8));
        sbIntegr->setPrefix(QString());
        label_6->setText(QApplication::translate("MetakonCfgForm", "\320\237\320\276\321\201\321\202\320\276\321\217\320\275\320\275\320\260\321\217 \320\264\320\270\321\204\321\204\320\265\321\200.", 0, QApplication::UnicodeUTF8));
        sbDiff->setSuffix(QApplication::translate("MetakonCfgForm", "\321\201\320\265\320\272", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MetakonCfgForm", "\320\227\320\276\320\275\320\260 \320\277\321\200\320\276\320\277\320\276\321\200\321\206\320\270\320\276\320\275\320\260\320\273\321\214\320\275\320\276\321\201\321\202\320\270", 0, QApplication::UnicodeUTF8));
        sbPb->setSuffix(QApplication::translate("MetakonCfgForm", "\302\260C", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MetakonCfgForm: public Ui_MetakonCfgForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_METAKONCFG_H
