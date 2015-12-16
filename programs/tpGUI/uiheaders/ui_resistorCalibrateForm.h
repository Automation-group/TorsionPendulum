/********************************************************************************
** Form generated from reading UI file 'resistorCalibrateForm.ui'
**
** Created: Fri Jul 13 17:15:01 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESISTORCALIBRATEFORM_H
#define UI_RESISTORCALIBRATEFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ResistorCalibrateForm
{
public:
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QPushButton *pbStart;
    QPushButton *pbStop;
    QPushButton *pbExit;
    QFrame *frame;
    QVBoxLayout *vboxLayout1;
    QHBoxLayout *hboxLayout1;
    QLabel *label;
    QSpinBox *sbResistor;
    QSpacerItem *spacerItem;
    QSlider *hsResistor;
    QFrame *frame_2;
    QVBoxLayout *vboxLayout2;
    QHBoxLayout *hboxLayout2;
    QLabel *label_2;
    QLCDNumber *lcdNumber;

    void setupUi(QDialog *ResistorCalibrateForm)
    {
        if (ResistorCalibrateForm->objectName().isEmpty())
            ResistorCalibrateForm->setObjectName(QString::fromUtf8("ResistorCalibrateForm"));
        ResistorCalibrateForm->setWindowModality(Qt::ApplicationModal);
        ResistorCalibrateForm->resize(400, 182);
        vboxLayout = new QVBoxLayout(ResistorCalibrateForm);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        pbStart = new QPushButton(ResistorCalibrateForm);
        pbStart->setObjectName(QString::fromUtf8("pbStart"));

        hboxLayout->addWidget(pbStart);

        pbStop = new QPushButton(ResistorCalibrateForm);
        pbStop->setObjectName(QString::fromUtf8("pbStop"));

        hboxLayout->addWidget(pbStop);

        pbExit = new QPushButton(ResistorCalibrateForm);
        pbExit->setObjectName(QString::fromUtf8("pbExit"));

        hboxLayout->addWidget(pbExit);


        vboxLayout->addLayout(hboxLayout);

        frame = new QFrame(ResistorCalibrateForm);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        vboxLayout1 = new QVBoxLayout(frame);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));

        hboxLayout1->addWidget(label);

        sbResistor = new QSpinBox(frame);
        sbResistor->setObjectName(QString::fromUtf8("sbResistor"));
        sbResistor->setMaximum(255);
        sbResistor->setValue(127);

        hboxLayout1->addWidget(sbResistor);

        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacerItem);


        vboxLayout1->addLayout(hboxLayout1);

        hsResistor = new QSlider(frame);
        hsResistor->setObjectName(QString::fromUtf8("hsResistor"));
        hsResistor->setMaximum(255);
        hsResistor->setValue(127);
        hsResistor->setOrientation(Qt::Horizontal);

        vboxLayout1->addWidget(hsResistor);


        vboxLayout->addWidget(frame);

        frame_2 = new QFrame(ResistorCalibrateForm);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        vboxLayout2 = new QVBoxLayout(frame_2);
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        hboxLayout2->addWidget(label_2);

        lcdNumber = new QLCDNumber(frame_2);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setFrameShape(QFrame::Box);
        lcdNumber->setFrameShadow(QFrame::Plain);
        lcdNumber->setSmallDecimalPoint(false);
        lcdNumber->setNumDigits(4);
        lcdNumber->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber->setProperty("intValue", QVariant(0));

        hboxLayout2->addWidget(lcdNumber);


        vboxLayout2->addLayout(hboxLayout2);


        vboxLayout->addWidget(frame_2);


        retranslateUi(ResistorCalibrateForm);
        QObject::connect(hsResistor, SIGNAL(valueChanged(int)), sbResistor, SLOT(setValue(int)));
        QObject::connect(sbResistor, SIGNAL(valueChanged(int)), hsResistor, SLOT(setValue(int)));
        QObject::connect(pbExit, SIGNAL(clicked()), ResistorCalibrateForm, SLOT(close()));
        QObject::connect(ResistorCalibrateForm, SIGNAL(rejected()), pbStop, SLOT(click()));

        QMetaObject::connectSlotsByName(ResistorCalibrateForm);
    } // setupUi

    void retranslateUi(QDialog *ResistorCalibrateForm)
    {
        ResistorCalibrateForm->setWindowTitle(QApplication::translate("ResistorCalibrateForm", "\320\272\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\272\320\260 \321\200\320\265\320\267\320\270\321\201\321\202\320\276\321\200\320\260", 0, QApplication::UnicodeUTF8));
        pbStart->setText(QApplication::translate("ResistorCalibrateForm", "\320\241\321\202\320\260\321\200\321\202", 0, QApplication::UnicodeUTF8));
        pbStop->setText(QApplication::translate("ResistorCalibrateForm", "\320\241\321\202\320\276\320\277", 0, QApplication::UnicodeUTF8));
        pbExit->setText(QApplication::translate("ResistorCalibrateForm", "\320\222\321\213\321\205\320\276\320\264", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ResistorCalibrateForm", "<b>\320\240\320\265\320\267\320\270\321\201\321\202\320\276\321\200", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ResistorCalibrateForm", "<b>\320\235\320\276\320\273\321\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ResistorCalibrateForm: public Ui_ResistorCalibrateForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESISTORCALIBRATEFORM_H
