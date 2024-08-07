/********************************************************************************
** Form generated from reading UI file 'f2_f3.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_F2_F3_H
#define UI_F2_F3_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_f2_f3
{
public:
    QCustomPlot *widget;

    void setupUi(QWidget *f2_f3)
    {
        if (f2_f3->objectName().isEmpty())
            f2_f3->setObjectName("f2_f3");
        f2_f3->resize(400, 300);
        widget = new QCustomPlot(f2_f3);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 9, 371, 271));

        retranslateUi(f2_f3);

        QMetaObject::connectSlotsByName(f2_f3);
    } // setupUi

    void retranslateUi(QWidget *f2_f3)
    {
        f2_f3->setWindowTitle(QCoreApplication::translate("f2_f3", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class f2_f3: public Ui_f2_f3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_F2_F3_H
