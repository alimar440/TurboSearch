#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qmessagebox.h"
#include "table_hachage.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include <QPixmap>
#include "f1_f4.h"
#include "f2_f4.h"
#include "f1_f2.h"
#include "f1_f3.h"
#include "f2_f3.h"
// #include "qcustomplot.h"




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mysdb = QSqlDatabase::addDatabase("QPSQL");
    mysdb.setHostName("localhost");
    mysdb.setDatabaseName("gestion_voiture");
    mysdb.setUserName("postgres");
    mysdb.setPassword("your password");
    mysdb.setPort(5432);

    if (!mysdb.open()) {
        QMessageBox::critical(this, "Database Connection Error", mysdb.lastError().text());
    } else {
        QMessageBox::information(this, "Database Connection", "Connected successfully!");
    }
    this->setWindowTitle("TurboSearch");
    int actu=tab.getHachage_actuelle();
    QString actuStr = QString::number(actu);
    ui->actu->setText(actuStr);
    QString cheminPhoto = "C:/Users/DELL/OneDrive/Documents/TURBO/images/icon3.PNG";
    QPixmap image(cheminPhoto);
    ui->logo->setPixmap(image);
    ui->logo->setScaledContents(true);

}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_racAffiche_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    QSqlTableModel *model = new QSqlTableModel(this, mysdb);
    model->setTable("voiture");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    if (!model->select()) {
        QMessageBox::critical(this, "Query Error", "Failed to execute query: " + model->lastError().text());
    } else {

        ui->base->setModel(model);
        ui->base->resizeColumnsToContents();
    }
}

void MainWindow::on_racTaille_clicked()
{
    int resultat = tab.size() ;
    QString resultatStr = QString::number(resultat);
    QMessageBox::information(this, "Information", "La taille de votre base de données est de " + resultatStr);
}


void MainWindow::on_insererDelbtn_clicked()
{
    ui->insererGamme->setText("");
    ui->insererModel->setText("");
    ui->insererMarque->setText("");
    ui->insererPhoto->setText("");
    ui->insererAnnee->setText("");
    ui->insererPresentation->setText("");
}

void MainWindow::on_suppressiondelbtn_clicked()
{
    ui->suppressionMatricile->setText("");
}

void MainWindow::on_recherchedelbtn_clicked()
{
    ui->rechercheMatricule->setText("");
}


void MainWindow::on_insererbtn_clicked()
{
    QString Matricule = ui->insererMatricule->text();
    int Annee = ui->insererAnnee->text().toInt();
    QString Gamme = ui->insererGamme->text();
    QString Model = ui->insererModel->text();
    QString Marque = ui->insererMarque->text();
    QString Photo = ui->insererPhoto->text();
    QString Presentation = ui->insererPresentation->toPlainText();


    if( Gamme=="" || Model=="" || Marque=="" || Photo=="" || Presentation=="")
        QMessageBox::information(this, "Erreur", "Tous les champs sont obligatoires");
    else
        if(tab.contient(Matricule))
            QMessageBox::information(this, "Erreur", "La base de donnees contient deja " + Matricule);
        else
        {     VALEUR val = creerVal(Marque, Model, Annee, Gamme, Presentation, Photo);
            tab.inserer(Matricule,val);
            QMessageBox::information(this, "Success", Matricule + " a été ajouté avec succes");
            ui->insererModel->setText("");
            ui->insererMarque->setText("");
            ui->insererPhoto->setText("");
            ui->insererAnnee->setText("");
            ui->insererGamme->setText("");
            ui->insererPresentation->setText("");
            ui->insererMatricule->setText("");

        }
}


void MainWindow::on_suppressionbtn_clicked()
{
    QString Matricule = ui->suppressionMatricile->text();

    if( Matricule == "" )
        QMessageBox::information(this, "Erreur", "Le champ matricule est obligatoires");
    else
        if(! tab.contient(Matricule))
            QMessageBox::information(this, "Erreur", "La base de donnees ne contient pas " + Matricule);
        else
        {
            tab.supprimer(Matricule) ;
            QMessageBox::information(this,"Succes","Suppression reussi avec succes");
            ui->insererMatricule->setText("");
        }

}

void MainWindow::on_recherchebtn_clicked()
{
    QString Matricule = ui->rechercheMatricule->text();

    if( Matricule == "" )
        QMessageBox::information(this, "Erreur", "Le champ matricule est obligatoires");
    else
        if(! tab.contient(Matricule))
            QMessageBox::information(this, "Erreur", "La base de donnees ne contient pas  " + Matricule);
        else
        {
            VALEUR val = tab.get(Matricule) ;


            int annee = val.annee;
            QString anneeStr = QString::number(annee);
            ui->displayAnnee->setText(anneeStr);

            ui->displayGamme->setText(val.gamme);
            ui->displayModel->setText(val.modele);
            ui->displayMarque->setText(val.marque);
            ui->displayPresentation->setText(val.description);
            QString cheminPhoto = val.photo;

            QPixmap image(cheminPhoto);


            if (image.isNull()) {
                QMessageBox::warning(this, "Erreur", "Impossible de charger l'image: " + cheminPhoto);
            } else {

                ui->displayPhoto->setPixmap(image);
                ui->displayPhoto->setScaledContents(true);
            }
            ui->stackedWidget->setCurrentIndex(6);
            ui->insererMatricule->setText("");
        }
}

void MainWindow::on_actionCharger_triggered()
{
    QMessageBox::information(this,"Succes","La base de donnees est chargé a succes");

}

void MainWindow::on_actionTaille_triggered()
{
    int resultat = tab.size() ;
    QString resultatStr = QString::number(resultat);
    QMessageBox::information(this, "Information", "La taille de votre base de données est de " + resultatStr);
}

void MainWindow::on_actionInsertion_triggered()
{
    ui->stackedWidget->setCurrentIndex(1) ;
}

void MainWindow::on_actionSuppression_triggered()
{
    ui->stackedWidget->setCurrentIndex(2) ;
}

void MainWindow::on_actionRecherche_triggered()
{
    ui->stackedWidget->setCurrentIndex(3) ;
}

void MainWindow::on_actionSauvegarder_triggered()
{
    tab.sauvegarder();

}

void MainWindow::on_actionQuitter_triggered()
{
    close();
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(0) ;
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0) ;
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(0) ;
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0) ;
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(1) ;
}

void MainWindow::on_actionAffichage_triggered()
{
    ui->stackedWidget->setCurrentIndex(4) ;
}

void MainWindow::on_racCharger_clicked()
{
    tab.charger();
    QMessageBox::information(this,"Succes","La base de donnees est chargé a succes");

}

void MainWindow::on_actionSanshach_triggered()
{
    if(tab.getHachage_actuelle()!=4)
    {
        tab.vider();
        qDebug() <<" premier" ;
        tab.setHachage_actuelle(4);
        qDebug() <<" deux" ;
        tab.charger();
        qDebug() <<" trois" ;
        int actu=tab.getHachage_actuelle();
        qDebug() <<" quatre";
        QString actuStr = QString::number(actu);
        ui->actu->setText(actuStr);
    }
}


void MainWindow::on_pushButton_16_clicked()
{
    ui->stackedWidget->setCurrentIndex(0) ;
}

void MainWindow::on_pushButton_17_clicked()
{
    ui->stackedWidget->setCurrentIndex(1) ;
}

void MainWindow::on_pushButton_14_clicked()
{
    ui->stackedWidget->setCurrentIndex(2) ;
}

void MainWindow::on_pushButton_15_clicked()
{
    ui->stackedWidget->setCurrentIndex(3) ;
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0) ;
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(2) ;
}

void MainWindow::on_pushButton_12_clicked()
{
    ui->stackedWidget->setCurrentIndex(3) ;
}

void MainWindow::on_pushButton_13_clicked()
{
    ui->stackedWidget->setCurrentIndex(4) ;
    QSqlTableModel *model = new QSqlTableModel(this, mysdb);
    model->setTable("voiture");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);


    if (!model->select()) {
        QMessageBox::critical(this, "Query Error", "Failed to execute query: " + model->lastError().text());
    } else {

        ui->base->setModel(model);
        ui->base->resizeColumnsToContents();
    }
}

void MainWindow::on_pushButton_18_clicked()
{
    ui->stackedWidget->setCurrentIndex(0) ;
}

void MainWindow::on_pushButton_19_clicked()
{
    ui->stackedWidget->setCurrentIndex(1) ;
}

void MainWindow::on_pushButton_20_clicked()
{
    ui->stackedWidget->setCurrentIndex(2) ;
}

void MainWindow::on_pushButton_21_clicked()
{
    ui->stackedWidget->setCurrentIndex(3) ;
    QSqlTableModel *model = new QSqlTableModel(this, mysdb);
    model->setTable("voiture");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);


    if (!model->select()) {
        QMessageBox::critical(this, "Query Error", "Failed to execute query: " + model->lastError().text());
    } else {

        ui->base->setModel(model);
        ui->base->resizeColumnsToContents();
    }
}

void MainWindow::on_pushButton_24_clicked()
{
    ui->stackedWidget->setCurrentIndex(4) ;

    QSqlTableModel *model = new QSqlTableModel(this, mysdb);
    model->setTable("voiture");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);


    if (!model->select()) {
        QMessageBox::critical(this, "Query Error", "Failed to execute query: " + model->lastError().text());
    } else {

        ui->base->setModel(model);
        ui->base->resizeColumnsToContents();
    }
}

void MainWindow::on_pushButton_25_clicked()
{
    ui->stackedWidget->setCurrentIndex(0) ;
}

void MainWindow::on_pushButton_26_clicked()
{
    ui->stackedWidget->setCurrentIndex(1) ;
}

void MainWindow::on_pushButton_27_clicked()
{
    ui->stackedWidget->setCurrentIndex(2) ;
}

void MainWindow::on_pushButton_28_clicked()
{
    ui->stackedWidget->setCurrentIndex(3) ;
}

void MainWindow::on_pushButton_29_clicked()
{
    ui->stackedWidget->setCurrentIndex(4) ;
    QSqlTableModel *model = new QSqlTableModel(this, mysdb);
    model->setTable("voiture");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);


    if (!model->select()) {
        QMessageBox::critical(this, "Query Error", "Failed to execute query: " + model->lastError().text());
    } else {

        ui->base->setModel(model);
        ui->base->resizeColumnsToContents();
    }

}

void MainWindow::on_sortTaille_linkActivated(const QString &link)
{
    int resultat = tab.size() ;
    QString resultatStr = QString::number(resultat);
    QMessageBox::information(this, "Information", "La taille de votre base de données est de " + resultatStr);

}

// void MainWindow::on_pushButton_22_clicked()
// {
//     ui->stackedWidget->setCurrentIndex(4) ;
//     QSqlTableModel *model = new QSqlTableModel(this, mysdb);
//     model->setTable("voiture");
//     model->setEditStrategy(QSqlTableModel::OnManualSubmit);


//     if (!model->select()) {
//         QMessageBox::critical(this, "Query Error", "Failed to execute query: " + model->lastError().text());
//     } else {

//         ui->base->setModel(model);
//         ui->base->resizeColumnsToContents();
//     }
// }

void MainWindow::on_actionF1_triggered()
{
    if(tab.getHachage_actuelle()!=1)
    {
        tab.vider();
        tab.setHachage_actuelle(1);
        tab.charger();
        int actu=tab.getHachage_actuelle();
        QString actuStr = QString::number(actu);
        ui->actu->setText(actuStr);
    }
}


void MainWindow::on_actionF2_triggered()
{
    if(tab.getHachage_actuelle()!=2)
    {
        tab.vider();
        tab.setHachage_actuelle(2);
        tab.charger();
        int actu=tab.getHachage_actuelle();
        QString actuStr = QString::number(actu);
        ui->actu->setText(actuStr);
    }
}


void MainWindow::on_actionF3_triggered()
{
    if(tab.getHachage_actuelle()!=3)
    {
        tab.vider();
        tab.setHachage_actuelle(3);
        tab.charger();
        int actu=tab.getHachage_actuelle();
        QString actuStr = QString::number(actu);
        ui->actu->setText(actuStr);
    }
}


void MainWindow::on_actionActuell_hash_triggered()
{
    int hachageActuel = tab.getHachage_actuelle();


    QString hachageActuelStr = QString::number(hachageActuel);

    QMessageBox::information(this, "Hachage",
                             "La fonction de hachage actuellement utilisée est la numéro :" + hachageActuelStr);
}


void MainWindow::on_rachach_activated(int index)
{
    int choix=ui->rachach->currentIndex();
    if(choix==1)
    {
        on_actionF1_triggered();
    }
    if(choix==2)
    {
        on_actionF2_triggered();
    }
    if(choix==3)
    {
        on_actionF3_triggered();
    }
    if(choix==4)
    {
        on_actionSanshach_triggered();
    }
}


void MainWindow::on_actionf1_vs_f4_triggered()
{
    f1_f4 *w=new f1_f4();
    w->setAttribute(Qt::WA_DeleteOnClose);
    w->showMaximized();

}


void MainWindow::on_pushButton_22_clicked()
{
    ui->stackedWidget->setCurrentIndex(4) ;
}


void MainWindow::on_actionf2_vs_f4_triggered()
{
    f2_f4 *w=new f2_f4();
    w->setAttribute(Qt::WA_DeleteOnClose);
    w->showMaximized();

}


void MainWindow::on_actionf1_vs_f2_triggered()
{
    f1_f2 *w=new f1_f2();
    w->setAttribute(Qt::WA_DeleteOnClose);
    w->showMaximized();
}


void MainWindow::on_actionf1_vs_f3_triggered()
{
    f1_f3 *w=new f1_f3();
    w->setAttribute(Qt::WA_DeleteOnClose);
    w->showMaximized();
}


void MainWindow::on_actionf2_vs_f3_triggered()
{
    f2_f3 *w=new f2_f3();
    w->setAttribute(Qt::WA_DeleteOnClose);
    w->showMaximized();
}

