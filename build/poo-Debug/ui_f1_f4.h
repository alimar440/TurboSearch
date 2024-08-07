/********************************************************************************
** Form generated from reading UI file 'f1_f4.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_F1_F4_H
#define UI_F1_F4_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_f1_f4
{
public:
    QCustomPlot *widget;

    void setupUi(QDialog *f1_f4)
    {
        if (f1_f4->objectName().isEmpty())
            f1_f4->setObjectName("f1_f4");
        f1_f4->resize(616, 449);
        widget = new QCustomPlot(f1_f4);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(-201, -70, 1071, 591));

        retranslateUi(f1_f4);

        QMetaObject::connectSlotsByName(f1_f4);
    } // setupUi

    void retranslateUi(QDialog *f1_f4)
    {
        f1_f4->setWindowTitle(QCoreApplication::translate("f1_f4", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class f1_f4: public Ui_f1_f4 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_F1_F4_H
