/********************************************************************************
** Form generated from reading UI file 'f1_f3.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_F1_F3_H
#define UI_F1_F3_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_f1_f3
{
public:
    QCustomPlot *widget;

    void setupUi(QWidget *f1_f3)
    {
        if (f1_f3->objectName().isEmpty())
            f1_f3->setObjectName("f1_f3");
        f1_f3->resize(613, 317);
        widget = new QCustomPlot(f1_f3);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(29, 9, 571, 291));

        retranslateUi(f1_f3);

        QMetaObject::connectSlotsByName(f1_f3);
    } // setupUi

    void retranslateUi(QWidget *f1_f3)
    {
        f1_f3->setWindowTitle(QCoreApplication::translate("f1_f3", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class f1_f3: public Ui_f1_f3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_F1_F3_H
