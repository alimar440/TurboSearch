/********************************************************************************
** Form generated from reading UI file 'f2_f4.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_F2_F4_H
#define UI_F2_F4_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_f2_f4
{
public:
    QCustomPlot *widget;

    void setupUi(QWidget *f2_f4)
    {
        if (f2_f4->objectName().isEmpty())
            f2_f4->setObjectName("f2_f4");
        f2_f4->resize(619, 353);
        widget = new QCustomPlot(f2_f4);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(270, 130, 120, 80));

        retranslateUi(f2_f4);

        QMetaObject::connectSlotsByName(f2_f4);
    } // setupUi

    void retranslateUi(QWidget *f2_f4)
    {
        f2_f4->setWindowTitle(QCoreApplication::translate("f2_f4", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class f2_f4: public Ui_f2_f4 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_F2_F4_H
