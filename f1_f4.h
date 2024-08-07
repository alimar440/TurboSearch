#ifndef F1_F4_H
#define F1_F4_H

#include <QWidget>

#include <QTimer>
#include <functional>
#include <QSql>
#include <QSqlDatabase>
#include <QVector>
#include "qcustomplot.h"
#include "table_hachage.h"
#include <QSqlQuery>

using namespace std;
using namespace std::chrono;
namespace Ui {
class f1_f4;
}

class f1_f4 : public QWidget
{
    Q_OBJECT

public:
    explicit f1_f4(QWidget *parent = nullptr);
    ~f1_f4();

private slots:
    //void on_widget_customContextMenuRequested(const QPoint &pos);
    void comparaison_f1_f4();
private:
    Ui::f1_f4 *ui;

    QCustomPlot *customPlot;


};

#endif // F1_F4_H
