/********************************************************************************
** Form generated from reading UI file 'trainer_dialog.ui'
**
** Created: Fri Jan 25 06:36:47 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAINER_DIALOG_H
#define UI_TRAINER_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>

QT_BEGIN_NAMESPACE

class Ui_trainer_Dialog
{
public:
    QLabel *trainerDisp;
    QPlainTextEdit *trainer_box;
    QPushButton *trainer_btnOK;
    QPushButton *trainer_btnpr;
    QLabel *trainerDisp_2;
    QSlider *horizontalSlider;
    QSlider *horizontalSlider_2;
    QLabel *label;
    QLabel *label_2;
    QLCDNumber *lcdNumber;
    QLCDNumber *lcdNumber_2;
    QSlider *horizontalSlider_3;
    QSlider *horizontalSlider_4;
    QLCDNumber *lcdNumber_3;
    QLCDNumber *lcdNumber_4;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *trainer_Dialog)
    {
        if (trainer_Dialog->objectName().isEmpty())
            trainer_Dialog->setObjectName(QString::fromUtf8("trainer_Dialog"));
        trainer_Dialog->resize(671, 417);
        trainerDisp = new QLabel(trainer_Dialog);
        trainerDisp->setObjectName(QString::fromUtf8("trainerDisp"));
        trainerDisp->setGeometry(QRect(20, 120, 384, 280));
        trainerDisp->setAutoFillBackground(true);
        trainerDisp->setFrameShape(QFrame::Box);
        trainer_box = new QPlainTextEdit(trainer_Dialog);
        trainer_box->setObjectName(QString::fromUtf8("trainer_box"));
        trainer_box->setGeometry(QRect(450, 310, 200, 91));
        trainer_box->setAutoFillBackground(true);
        trainer_box->setReadOnly(true);
        trainer_btnOK = new QPushButton(trainer_Dialog);
        trainer_btnOK->setObjectName(QString::fromUtf8("trainer_btnOK"));
        trainer_btnOK->setGeometry(QRect(450, 120, 91, 41));
        trainer_btnpr = new QPushButton(trainer_Dialog);
        trainer_btnpr->setObjectName(QString::fromUtf8("trainer_btnpr"));
        trainer_btnpr->setGeometry(QRect(560, 120, 91, 41));
        trainerDisp_2 = new QLabel(trainer_Dialog);
        trainerDisp_2->setObjectName(QString::fromUtf8("trainerDisp_2"));
        trainerDisp_2->setGeometry(QRect(450, 190, 200, 91));
        trainerDisp_2->setAutoFillBackground(true);
        trainerDisp_2->setFrameShape(QFrame::Box);
        horizontalSlider = new QSlider(trainer_Dialog);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(40, 30, 160, 19));
        horizontalSlider->setMaximum(256);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider_2 = new QSlider(trainer_Dialog);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(360, 30, 160, 19));
        horizontalSlider_2->setMaximum(256);
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        label = new QLabel(trainer_Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 10, 46, 13));
        label_2 = new QLabel(trainer_Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(360, 10, 46, 13));
        lcdNumber = new QLCDNumber(trainer_Dialog);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(230, 20, 64, 23));
        lcdNumber->setAutoFillBackground(true);
        lcdNumber->setFrameShape(QFrame::Box);
        lcdNumber_2 = new QLCDNumber(trainer_Dialog);
        lcdNumber_2->setObjectName(QString::fromUtf8("lcdNumber_2"));
        lcdNumber_2->setGeometry(QRect(550, 20, 64, 23));
        lcdNumber_2->setAutoFillBackground(true);
        lcdNumber_2->setFrameShape(QFrame::Box);
        horizontalSlider_3 = new QSlider(trainer_Dialog);
        horizontalSlider_3->setObjectName(QString::fromUtf8("horizontalSlider_3"));
        horizontalSlider_3->setGeometry(QRect(40, 80, 160, 19));
        horizontalSlider_3->setMaximum(256);
        horizontalSlider_3->setOrientation(Qt::Horizontal);
        horizontalSlider_4 = new QSlider(trainer_Dialog);
        horizontalSlider_4->setObjectName(QString::fromUtf8("horizontalSlider_4"));
        horizontalSlider_4->setGeometry(QRect(360, 80, 160, 19));
        horizontalSlider_4->setMaximum(256);
        horizontalSlider_4->setOrientation(Qt::Horizontal);
        lcdNumber_3 = new QLCDNumber(trainer_Dialog);
        lcdNumber_3->setObjectName(QString::fromUtf8("lcdNumber_3"));
        lcdNumber_3->setGeometry(QRect(550, 70, 64, 23));
        lcdNumber_3->setAutoFillBackground(true);
        lcdNumber_3->setFrameShape(QFrame::Box);
        lcdNumber_4 = new QLCDNumber(trainer_Dialog);
        lcdNumber_4->setObjectName(QString::fromUtf8("lcdNumber_4"));
        lcdNumber_4->setGeometry(QRect(230, 70, 64, 23));
        lcdNumber_4->setAutoFillBackground(true);
        lcdNumber_4->setFrameShape(QFrame::Box);
        label_3 = new QLabel(trainer_Dialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 60, 46, 13));
        label_4 = new QLabel(trainer_Dialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(360, 60, 46, 13));

        retranslateUi(trainer_Dialog);
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), lcdNumber, SLOT(display(int)));
        QObject::connect(horizontalSlider_2, SIGNAL(valueChanged(int)), lcdNumber_2, SLOT(display(int)));
        QObject::connect(horizontalSlider_3, SIGNAL(valueChanged(int)), lcdNumber_4, SLOT(display(int)));
        QObject::connect(horizontalSlider_4, SIGNAL(valueChanged(int)), lcdNumber_3, SLOT(display(int)));

        QMetaObject::connectSlotsByName(trainer_Dialog);
    } // setupUi

    void retranslateUi(QDialog *trainer_Dialog)
    {
        trainer_Dialog->setWindowTitle(QApplication::translate("trainer_Dialog", "Training", 0, QApplication::UnicodeUTF8));
        trainerDisp->setText(QString());
        trainer_btnOK->setText(QApplication::translate("trainer_Dialog", "EXIT", 0, QApplication::UnicodeUTF8));
        trainer_btnpr->setText(QApplication::translate("trainer_Dialog", "START", 0, QApplication::UnicodeUTF8));
        trainerDisp_2->setText(QString());
        label->setText(QApplication::translate("trainer_Dialog", "SMIN", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("trainer_Dialog", "VMIN", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("trainer_Dialog", "SMAX", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("trainer_Dialog", "VMAX", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class trainer_Dialog: public Ui_trainer_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAINER_DIALOG_H
