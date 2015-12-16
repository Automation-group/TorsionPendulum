/********************************************************************************
** Form generated from reading UI file 'startDialog.ui'
**
** Created: Fri Jul 13 17:15:01 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTDIALOG_H
#define UI_STARTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_StartDialog
{
public:
    QVBoxLayout *vboxLayout;
    QGroupBox *groupBox_3;
    QVBoxLayout *vboxLayout1;
    QGridLayout *gridLayout;
    QLabel *label_7;
    QLineEdit *leFileName;
    QToolButton *tbSelectFile;
    QHBoxLayout *hboxLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout1;
    QLabel *label;
    QDoubleSpinBox *dsbLenght;
    QLabel *label_2;
    QDoubleSpinBox *dsbWidth;
    QLabel *label_3;
    QDoubleSpinBox *dsbThickness;
    QSpacerItem *spacerItem;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout2;
    QLabel *label_4;
    QDoubleSpinBox *dsbM1;
    QLabel *label_5;
    QDoubleSpinBox *dsbM2;
    QLabel *label_6;
    QDoubleSpinBox *dsbRadius;
    QCheckBox *cbSoftBracket;
    QHBoxLayout *hboxLayout1;
    QSpacerItem *spacerItem1;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *StartDialog)
    {
        if (StartDialog->objectName().isEmpty())
            StartDialog->setObjectName(QString::fromUtf8("StartDialog"));
        StartDialog->setWindowModality(Qt::ApplicationModal);
        StartDialog->resize(502, 339);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(StartDialog->sizePolicy().hasHeightForWidth());
        StartDialog->setSizePolicy(sizePolicy);
        StartDialog->setMinimumSize(QSize(0, 339));
        StartDialog->setMaximumSize(QSize(16777215, 339));
        StartDialog->setModal(true);
        vboxLayout = new QVBoxLayout(StartDialog);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        groupBox_3 = new QGroupBox(StartDialog);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy1);
        vboxLayout1 = new QVBoxLayout(groupBox_3);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(label_7, 0, 0, 1, 1);

        leFileName = new QLineEdit(groupBox_3);
        leFileName->setObjectName(QString::fromUtf8("leFileName"));

        gridLayout->addWidget(leFileName, 1, 0, 1, 1);

        tbSelectFile = new QToolButton(groupBox_3);
        tbSelectFile->setObjectName(QString::fromUtf8("tbSelectFile"));

        gridLayout->addWidget(tbSelectFile, 1, 1, 1, 1);


        vboxLayout1->addLayout(gridLayout);


        vboxLayout->addWidget(groupBox_3);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        groupBox = new QGroupBox(StartDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout1 = new QGridLayout(groupBox);
        gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout1->addWidget(label, 0, 0, 1, 1);

        dsbLenght = new QDoubleSpinBox(groupBox);
        dsbLenght->setObjectName(QString::fromUtf8("dsbLenght"));
        sizePolicy.setHeightForWidth(dsbLenght->sizePolicy().hasHeightForWidth());
        dsbLenght->setSizePolicy(sizePolicy);
        dsbLenght->setDecimals(3);

        gridLayout1->addWidget(dsbLenght, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy3);

        gridLayout1->addWidget(label_2, 1, 0, 1, 1);

        dsbWidth = new QDoubleSpinBox(groupBox);
        dsbWidth->setObjectName(QString::fromUtf8("dsbWidth"));
        sizePolicy.setHeightForWidth(dsbWidth->sizePolicy().hasHeightForWidth());
        dsbWidth->setSizePolicy(sizePolicy);
        dsbWidth->setDecimals(3);

        gridLayout1->addWidget(dsbWidth, 1, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy3.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy3);

        gridLayout1->addWidget(label_3, 2, 0, 1, 1);

        dsbThickness = new QDoubleSpinBox(groupBox);
        dsbThickness->setObjectName(QString::fromUtf8("dsbThickness"));
        sizePolicy.setHeightForWidth(dsbThickness->sizePolicy().hasHeightForWidth());
        dsbThickness->setSizePolicy(sizePolicy);
        dsbThickness->setDecimals(3);

        gridLayout1->addWidget(dsbThickness, 2, 1, 1, 1);

        spacerItem = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout1->addItem(spacerItem, 3, 1, 1, 1);


        hboxLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(StartDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout2 = new QGridLayout(groupBox_2);
        gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy3.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy3);

        gridLayout2->addWidget(label_4, 0, 0, 1, 1);

        dsbM1 = new QDoubleSpinBox(groupBox_2);
        dsbM1->setObjectName(QString::fromUtf8("dsbM1"));
        dsbM1->setMaximum(999.99);

        gridLayout2->addWidget(dsbM1, 0, 1, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy3.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy3);

        gridLayout2->addWidget(label_5, 1, 0, 1, 1);

        dsbM2 = new QDoubleSpinBox(groupBox_2);
        dsbM2->setObjectName(QString::fromUtf8("dsbM2"));
        dsbM2->setMaximum(999.99);

        gridLayout2->addWidget(dsbM2, 1, 1, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy3.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy3);

        gridLayout2->addWidget(label_6, 2, 0, 1, 1);

        dsbRadius = new QDoubleSpinBox(groupBox_2);
        dsbRadius->setObjectName(QString::fromUtf8("dsbRadius"));
        dsbRadius->setMaximum(999.99);

        gridLayout2->addWidget(dsbRadius, 2, 1, 1, 1);

        cbSoftBracket = new QCheckBox(groupBox_2);
        cbSoftBracket->setObjectName(QString::fromUtf8("cbSoftBracket"));

        gridLayout2->addWidget(cbSoftBracket, 3, 1, 1, 1);


        hboxLayout->addWidget(groupBox_2);


        vboxLayout->addLayout(hboxLayout);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        spacerItem1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacerItem1);

        buttonBox = new QDialogButtonBox(StartDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setEnabled(true);
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy4);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::NoButton|QDialogButtonBox::Ok);

        hboxLayout1->addWidget(buttonBox);


        vboxLayout->addLayout(hboxLayout1);


        retranslateUi(StartDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), StartDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), StartDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(StartDialog);
    } // setupUi

    void retranslateUi(QDialog *StartDialog)
    {
        StartDialog->setWindowTitle(QApplication::translate("StartDialog", "\320\235\320\276\320\262\321\213\320\271 \321\215\320\272\321\201\320\277\320\265\321\200\320\270\320\274\320\265\320\275\321\202", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("StartDialog", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \321\215\320\272\321\201\320\277\320\265\321\200\320\270\320\274\320\265\320\275\321\202\320\260", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("StartDialog", "\320\244\320\260\320\271\320\273 \321\215\320\272\321\201\320\277\320\265\321\200\320\270\320\274\320\265\320\275\321\202\320\260", 0, QApplication::UnicodeUTF8));
        tbSelectFile->setText(QApplication::translate("StartDialog", "...", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("StartDialog", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\276\320\261\321\200\320\260\320\267\321\206\320\260", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("StartDialog", "\320\224\320\273\320\270\320\275\320\260", 0, QApplication::UnicodeUTF8));
        dsbLenght->setSuffix(QApplication::translate("StartDialog", "\320\274\320\274", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("StartDialog", "\320\250\320\270\321\200\320\270\320\275\320\260", 0, QApplication::UnicodeUTF8));
        dsbWidth->setSuffix(QApplication::translate("StartDialog", "\320\274\320\274", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("StartDialog", "\320\242\320\276\320\273\321\211\320\270\320\275\320\260", 0, QApplication::UnicodeUTF8));
        dsbThickness->setSuffix(QApplication::translate("StartDialog", "\320\274\320\274", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("StartDialog", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\274\320\260\321\217\321\202\320\275\320\270\320\272\320\260", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("StartDialog", "\320\234\320\260\321\201\321\201\320\260 m1", 0, QApplication::UnicodeUTF8));
        dsbM1->setSuffix(QApplication::translate("StartDialog", "\320\263", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("StartDialog", "\320\234\320\260\321\201\321\201\320\260 m2", 0, QApplication::UnicodeUTF8));
        dsbM2->setSuffix(QApplication::translate("StartDialog", "\320\263", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("StartDialog", "\320\240\320\260\320\264\320\270\321\203\321\201 R", 0, QApplication::UnicodeUTF8));
        dsbRadius->setSuffix(QApplication::translate("StartDialog", "\320\274\320\274", 0, QApplication::UnicodeUTF8));
        cbSoftBracket->setText(QApplication::translate("StartDialog", "\320\234\321\217\320\263\320\272\320\270\320\271 \320\277\320\276\320\264\320\262\320\265\321\201", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class StartDialog: public Ui_StartDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTDIALOG_H
