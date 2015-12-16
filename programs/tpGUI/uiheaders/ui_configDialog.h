/********************************************************************************
** Form generated from reading UI file 'configDialog.ui'
**
** Created: Fri Jul 13 17:15:01 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGDIALOG_H
#define UI_CONFIGDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStackedWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConfigDialog
{
public:
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QListWidget *contentWidget;
    QStackedWidget *stackedWidget;
    QWidget *page_2;
    QHBoxLayout *hboxLayout1;
    QSpacerItem *spacerItem;
    QPushButton *pbApplay;
    QPushButton *pbCancel;

    void setupUi(QDialog *ConfigDialog)
    {
        if (ConfigDialog->objectName().isEmpty())
            ConfigDialog->setObjectName(QString::fromUtf8("ConfigDialog"));
        ConfigDialog->setWindowModality(Qt::ApplicationModal);
        ConfigDialog->resize(465, 315);
        vboxLayout = new QVBoxLayout(ConfigDialog);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        contentWidget = new QListWidget(ConfigDialog);
        contentWidget->setObjectName(QString::fromUtf8("contentWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(contentWidget->sizePolicy().hasHeightForWidth());
        contentWidget->setSizePolicy(sizePolicy);
        contentWidget->setMaximumSize(QSize(150, 16777215));

        hboxLayout->addWidget(contentWidget);

        stackedWidget = new QStackedWidget(ConfigDialog);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget->addWidget(page_2);

        hboxLayout->addWidget(stackedWidget);


        vboxLayout->addLayout(hboxLayout);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacerItem);

        pbApplay = new QPushButton(ConfigDialog);
        pbApplay->setObjectName(QString::fromUtf8("pbApplay"));

        hboxLayout1->addWidget(pbApplay);

        pbCancel = new QPushButton(ConfigDialog);
        pbCancel->setObjectName(QString::fromUtf8("pbCancel"));

        hboxLayout1->addWidget(pbCancel);


        vboxLayout->addLayout(hboxLayout1);


        retranslateUi(ConfigDialog);
        QObject::connect(pbCancel, SIGNAL(clicked()), ConfigDialog, SLOT(close()));

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ConfigDialog);
    } // setupUi

    void retranslateUi(QDialog *ConfigDialog)
    {
        ConfigDialog->setWindowTitle(QApplication::translate("ConfigDialog", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", 0, QApplication::UnicodeUTF8));
        pbApplay->setText(QApplication::translate("ConfigDialog", "\320\237\321\200\320\270\320\275\321\217\321\202\321\214", 0, QApplication::UnicodeUTF8));
        pbCancel->setText(QApplication::translate("ConfigDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ConfigDialog: public Ui_ConfigDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGDIALOG_H
