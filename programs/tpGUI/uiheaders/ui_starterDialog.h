/********************************************************************************
** Form generated from reading UI file 'starterDialog.ui'
**
** Created: Fri Jul 13 17:15:00 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTERDIALOG_H
#define UI_STARTERDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_starterDialog
{
public:
    QVBoxLayout *vboxLayout;
    QPushButton *pbStart;
    QSpacerItem *spacerItem;
    QPushButton *pbSettings;
    QPushButton *pbCalibrateFurnace;
    QPushButton *pbExit;

    void setupUi(QDialog *starterDialog)
    {
        if (starterDialog->objectName().isEmpty())
            starterDialog->setObjectName(QString::fromUtf8("starterDialog"));
        starterDialog->resize(302, 200);
        vboxLayout = new QVBoxLayout(starterDialog);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        pbStart = new QPushButton(starterDialog);
        pbStart->setObjectName(QString::fromUtf8("pbStart"));

        vboxLayout->addWidget(pbStart);

        spacerItem = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout->addItem(spacerItem);

        pbSettings = new QPushButton(starterDialog);
        pbSettings->setObjectName(QString::fromUtf8("pbSettings"));

        vboxLayout->addWidget(pbSettings);

        pbCalibrateFurnace = new QPushButton(starterDialog);
        pbCalibrateFurnace->setObjectName(QString::fromUtf8("pbCalibrateFurnace"));

        vboxLayout->addWidget(pbCalibrateFurnace);

        pbExit = new QPushButton(starterDialog);
        pbExit->setObjectName(QString::fromUtf8("pbExit"));

        vboxLayout->addWidget(pbExit);


        retranslateUi(starterDialog);
        QObject::connect(pbExit, SIGNAL(clicked()), starterDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(starterDialog);
    } // setupUi

    void retranslateUi(QDialog *starterDialog)
    {
        starterDialog->setWindowTitle(QApplication::translate("starterDialog", "\320\232\321\200\321\203\321\202\320\270\320\273\321\214\320\275\320\260\320\271 \320\274\320\260\321\217\321\202\320\275\320\270\320\272", 0, QApplication::UnicodeUTF8));
        pbStart->setText(QApplication::translate("starterDialog", "\320\235\320\260\321\207\320\260\321\202\321\214 \321\215\320\272\321\201\320\277\320\265\321\200\320\270\320\274\320\265\320\275\321\202", 0, QApplication::UnicodeUTF8));
        pbSettings->setText(QApplication::translate("starterDialog", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260", 0, QApplication::UnicodeUTF8));
        pbCalibrateFurnace->setText(QApplication::translate("starterDialog", "\320\236\320\277\321\200\320\265\320\264\320\265\320\273\320\265\320\275\320\270\320\265 \320\237\320\230\320\224 \320\234\320\265\321\202\320\260\320\272\320\276\320\275\320\260", 0, QApplication::UnicodeUTF8));
        pbExit->setText(QApplication::translate("starterDialog", "\320\222\321\213\321\205\320\276\320\264", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class starterDialog: public Ui_starterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTERDIALOG_H
