#ifndef DB1_H
#define DB1_H

#include<QDialog>
#include<QtSql>

namespace Ui {
class DB;
}

class DB : public QDialog
{
    Q_OBJECT

public:
    explicit DB(QWidget *parent = nullptr);
    ~DB();
    void getConnexion();
    bool executeMAJ(QString sql);
    QSqlQuery executeSelect(QString sql);
    QSqlDatabase mysdb;

private:
    Ui::DB *ui;
};

#endif // DB_H
