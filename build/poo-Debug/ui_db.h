/********************************************************************************
** Form generated from reading UI file 'db.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DB_H
#define UI_DB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_DB
{
public:
    QTableView *tableView;

    void setupUi(QDialog *DB)
    {
        if (DB->objectName().isEmpty())
            DB->setObjectName("DB");
        DB->resize(781, 420);
        tableView = new QTableView(DB);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(60, 40, 681, 351));

        retranslateUi(DB);

        QMetaObject::connectSlotsByName(DB);
    } // setupUi

    void retranslateUi(QDialog *DB)
    {
        DB->setWindowTitle(QCoreApplication::translate("DB", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DB: public Ui_DB {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DB_H
