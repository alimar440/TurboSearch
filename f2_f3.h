#ifndef F2_F3_H
#define F2_F3_H

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
class f2_f3;
}

class f2_f3 : public QWidget
{
    Q_OBJECT

public:
    explicit f2_f3(QWidget *parent = nullptr);
    ~f2_f3();

private slots:
    //void on_widget_customContextMenuRequested(const QPoint &pos);
    void comparaison_f2_f3();
private:
    Ui::f2_f3 *ui;

    QCustomPlot *customPlot;


};

#endif // F2_F3_H
