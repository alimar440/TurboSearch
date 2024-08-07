#include "f2_f4.h"
#include "ui_f2_f4.h"

f2_f4::f2_f4(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::f2_f4)
{
    //ui->setupUi(this);

    comparaison_f2_f4();
}

f2_f4::~f2_f4()
{
    delete ui;
}


void f2_f4::comparaison_f2_f4()
{

    table_hachage table_f2,table_f4;
    table_f2.setHachage_actuelle(2);
    table_f4.setHachage_actuelle(4);

    QVector<double> x1(500), y1(500), x2(500), y2(500);


    if (QSqlDatabase::contains("gestion_voiture")) {
        QSqlDatabase::removeDatabase("gestion_voiture");
    }
    QSqlDatabase mysdb1;
    mysdb1 = QSqlDatabase::addDatabase("QPSQL");
    mysdb1.setHostName("localhost");
    mysdb1.setDatabaseName("gestion_voiture");
    mysdb1.setUserName("postgres");
    mysdb1.setPassword("mbarfall22");
    mysdb1.setPort(5432);

    if (!mysdb1.open()) {
        //     QMessageBox::critical(this, "Database Connection Error", mysdb.lastError().text());
        return ;
    }
    // QMessageBox::information(this, "Database Connection", "Connected successfully!");
    QSqlQuery query(mysdb1);
    query.prepare("select * from voiture");
    int i=0;
    query.exec();
    while(query.next() && i<500)
    {
        VALEUR V = creerVal(query.value(1).toString(),
                            query.value(4).toString(),
                            query.value(3).toInt(),
                            query.value(2).toString(),
                            query.value(6).toString(),
                            query.value(5).toString());

        table_f2.inserer(query.value(0).toString(),V);

        table_f4.inserer(query.value(0).toString(),V);

        i++;
    }

    query.clear();

    i=0;
    query.prepare("select * from voiture");
    query.exec();
    while(query.next() && i<500)
    {
        std::chrono::steady_clock::time_point debut1 = std::chrono::steady_clock::now();

        table_f2.get(query.value(0).toString());

        std::chrono::steady_clock::time_point fin1 = std::chrono::steady_clock::now();

        auto duration1 =duration_cast<nanoseconds>(fin1 - debut1);

        x1[i]=i;
        y1[i]=duration1.count();
        qDebug()<<x1[i] <<y1[i] <<"  1\n";


        std::chrono::steady_clock::time_point debut2 = std::chrono::steady_clock::now();
        qDebug()<<x1[i]<<y1[i] <<"  1\n";
        table_f4.get(query.value(0).toString());
        qDebug()<<i<<y1[i] <<"  1\n";
        std::chrono::steady_clock::time_point fin2 = std::chrono::steady_clock::now();
        qDebug()<<x1[i]<<y1[i] <<"  1\n";
        auto duration2 = duration_cast<nanoseconds>(fin2 - debut2);
        qDebug()<<x1[i]<<y1[i] <<"  1\n";
        x2[i]=i;
        y2[i]=duration2.count();
        qDebug()<<x2[i] <<y2[i] <<"  2\n";

        i++;
    }

    customPlot=new QCustomPlot(this);
    customPlot->addGraph();
    customPlot->setFixedSize(800, 600);

    customPlot->graph(0)->setData(x1, y1);
    customPlot->graph(0)->setPen(QPen(Qt::blue)); // Couleur de la première courbe
    customPlot->graph(0)->setName("f2");
    customPlot->addGraph();
    customPlot->graph(1)->setData(x2, y2);
    customPlot->graph(1)->setPen(QPen(Qt::red)); // Couleur de la deuxième courbe
    customPlot->graph(1)->setName("f4");

    customPlot->xAxis->setLabel("indice");
    customPlot->yAxis->setLabel("temps");


    customPlot->xAxis->setRange(1, 500);
    customPlot->yAxis->setRange(0, 175000);


    customPlot->legend->setVisible(true);


    customPlot->legend->setFont(QFont("Helvetica", 9));
    customPlot->legend->setBrush(QBrush(QColor(255,255,255,230)));


    customPlot->setBackground(QBrush(QColor(230, 230, 230)));
    customPlot->axisRect()->setBackground(QBrush(Qt::white));


    customPlot->replot();

    mysdb1.close();

}



