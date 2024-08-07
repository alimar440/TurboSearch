#include "db.h"
#include "ui_db.h"
#include <QMessageBox>
#include <QSqlTableModel>

DB::DB(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DB)
{
    ui->setupUi(this);
    getConnexion();


    QSqlTableModel *model = new QSqlTableModel(this, mysdb);
    model->setTable("voiture");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);


    if (!model->select()) {
        QMessageBox::critical(this, "Query Error", "Failed to execute query: " + model->lastError().text());
    } else {

        ui->tableView->setModel(model);
        ui->tableView->resizeColumnsToContents();
    }
}

DB::~DB()
{
    delete ui;
    if (mysdb.isOpen()) {
        mysdb.close();
    }
}


void DB::getConnexion()
{
    mysdb = QSqlDatabase::addDatabase("QPSQL");
    mysdb.setHostName("localhost");
    mysdb.setDatabaseName("gestion_voiture");
    mysdb.setUserName("postgres");
    mysdb.setPassword("mbarfall22");
    mysdb.setPort(5432);

    if (!mysdb.open()) {
        QMessageBox::critical(this, "Database Connection Error", mysdb.lastError().text());
    } else {
        QMessageBox::information(this, "Database Connection", "Connected successfully!");
    }
}

bool DB::executeMAJ(QString sql)
{
    QSqlQuery query;
    if (!query.exec(sql)) {
        QMessageBox::critical(this, "Query Error", query.lastError().text());
        return false;
    }
    return true;
}

QSqlQuery DB::executeSelect(QString sql)
{
    QSqlQuery query;
    if (!query.exec(sql)) {
        QMessageBox::critical(this, "Query Error", query.lastError().text());
    }
    return query;
}
