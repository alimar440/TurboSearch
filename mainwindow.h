#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "table_hachage.h"
#include<QtSql>
#include "qcustomplot.h"
#include <QTimer>
#include <QVector>




namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_racAffiche_clicked();

    void on_racTaille_clicked();

    void on_insererDelbtn_clicked();

    void on_suppressiondelbtn_clicked();

    void on_recherchedelbtn_clicked();

    void on_insererbtn_clicked();

    void on_suppressionbtn_clicked();

    void on_recherchebtn_clicked();

    void on_actionCharger_triggered();

    void on_actionTaille_triggered();

    void on_actionInsertion_triggered();

    void on_actionSuppression_triggered();

    void on_actionRecherche_triggered();

    void on_actionSauvegarder_triggered();

    void on_actionQuitter_triggered();

    void on_pushButton_8_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_actionAffichage_triggered();

    void on_racCharger_clicked();

    void on_actionSanshach_triggered();

    void on_rachach_activated(const QString &arg1);

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_29_clicked();

    void on_sortTaille_linkActivated(const QString &link);

    void on_actionF1_triggered();

    void on_actionActuell_hash_triggered();

    void on_actionF2_triggered();

    void on_actionF3_triggered();

    void on_rachach_activated(int index);

    void on_actionf1_vs_f4_triggered();

    void on_pushButton_22_clicked();

    void on_actionf2_vs_f4_triggered();

    void on_actionf1_vs_f2_triggered();

    void on_actionf1_vs_f3_triggered();

    void on_actionf2_vs_f3_triggered();

private:
    table_hachage tab ;
    Ui::MainWindow *ui;
    QSqlDatabase mysdb;
    // QCustomPlot *customPlot;
    // QTimer *timer;
    // int currentX;
    // QVector<double> xValues, yValues1, yValues2; // Vecteurs pour stocker les données
    // void makePlot(double xStart, double xEnd);
};

#endif // MAINWINDOW_H
