/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLabel *label;
    QSpinBox *spinBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(317, 98);
        label = new QLabel(Dialog);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 20, 161, 21));
        spinBox = new QSpinBox(Dialog);
        spinBox->setObjectName("spinBox");
        spinBox->setGeometry(QRect(190, 20, 111, 25));
        spinBox->setCursor(QCursor(Qt::IBeamCursor));
        spinBox->setMinimum(1);
        spinBox->setMaximum(999999999);
        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(80, 60, 166, 24));
        buttonBox->setCursor(QCursor(Qt::PointingHandCursor));
        buttonBox->setMouseTracking(false);
        buttonBox->setLocale(QLocale(QLocale::Czech, QLocale::Czechia));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(false);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Nastaven\303\255", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "Po\304\215et opakov\303\241n\303\255 (do 100 000)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
