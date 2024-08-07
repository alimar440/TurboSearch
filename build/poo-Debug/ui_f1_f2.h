/********************************************************************************
** Form generated from reading UI file 'f1_f2.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_F1_F2_H
#define UI_F1_F2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_f1_f2
{
public:
    QCustomPlot *widget;

    void setupUi(QWidget *f1_f2)
    {
        if (f1_f2->objectName().isEmpty())
            f1_f2->setObjectName("f1_f2");
        f1_f2->resize(615, 391);
        widget = new QCustomPlot(f1_f2);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, -61, 581, 381));

        retranslateUi(f1_f2);

        QMetaObject::connectSlotsByName(f1_f2);
    } // setupUi

    void retranslateUi(QWidget *f1_f2)
    {
        f1_f2->setWindowTitle(QCoreApplication::translate("f1_f2", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class f1_f2: public Ui_f1_f2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_F1_F2_H
