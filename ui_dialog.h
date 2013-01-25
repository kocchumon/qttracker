/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created: Fri Jan 25 06:36:47 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *btnPauseOrResume;
    QPlainTextEdit *boxConsole;
    QLabel *lblOriginal;
    QLabel *lblProcessed;
    QPushButton *btnAdd;
    QPushButton *btnExit;
    QPushButton *btnAdd_2;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(886, 566);
        btnPauseOrResume = new QPushButton(Dialog);
        btnPauseOrResume->setObjectName(QString::fromUtf8("btnPauseOrResume"));
        btnPauseOrResume->setGeometry(QRect(70, 390, 101, 41));
        QFont font;
        font.setPointSize(12);
        btnPauseOrResume->setFont(font);
        boxConsole = new QPlainTextEdit(Dialog);
        boxConsole->setObjectName(QString::fromUtf8("boxConsole"));
        boxConsole->setGeometry(QRect(410, 390, 393, 145));
        boxConsole->setReadOnly(true);
        lblOriginal = new QLabel(Dialog);
        lblOriginal->setObjectName(QString::fromUtf8("lblOriginal"));
        lblOriginal->setGeometry(QRect(36, 36, 384, 288));
        lblOriginal->setAutoFillBackground(true);
        lblOriginal->setFrameShape(QFrame::Box);
        lblOriginal->setAlignment(Qt::AlignCenter);
        lblProcessed = new QLabel(Dialog);
        lblProcessed->setObjectName(QString::fromUtf8("lblProcessed"));
        lblProcessed->setGeometry(QRect(460, 36, 384, 288));
        lblProcessed->setAutoFillBackground(true);
        lblProcessed->setFrameShape(QFrame::Box);
        lblProcessed->setAlignment(Qt::AlignCenter);
        btnAdd = new QPushButton(Dialog);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));
        btnAdd->setGeometry(QRect(210, 390, 101, 41));
        btnAdd->setFont(font);
        btnExit = new QPushButton(Dialog);
        btnExit->setObjectName(QString::fromUtf8("btnExit"));
        btnExit->setGeometry(QRect(70, 460, 101, 41));
        btnExit->setFont(font);
        btnAdd_2 = new QPushButton(Dialog);
        btnAdd_2->setObjectName(QString::fromUtf8("btnAdd_2"));
        btnAdd_2->setGeometry(QRect(210, 460, 101, 41));
        btnAdd_2->setFont(font);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "VDE", 0, QApplication::UnicodeUTF8));
        btnPauseOrResume->setText(QApplication::translate("Dialog", "Pause", 0, QApplication::UnicodeUTF8));
        lblOriginal->setText(QString());
        lblProcessed->setText(QString());
        btnAdd->setText(QApplication::translate("Dialog", "Add", 0, QApplication::UnicodeUTF8));
        btnExit->setText(QApplication::translate("Dialog", "EXIT", 0, QApplication::UnicodeUTF8));
        btnAdd_2->setText(QApplication::translate("Dialog", "Train", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
