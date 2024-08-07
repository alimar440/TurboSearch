#include "table_hachage.h"
#include<QMessageBox>
#include<QtSql>
#include "db.h"
#include<QDebug>
#include<QSqlQuery>

table_hachage::table_hachage()
{
    voitures = new VOITURE *[Nmax];
    nbr_voitures = 0;
    hachage_actuelle = 3;
    for (int i = 0; i < Nmax; i++) {
        voitures[i] = nullptr;
    }
}

table_hachage::~table_hachage()
{
    if (voitures) {
        for (int i = 0; i < Nmax; i++) {
            if (voitures[i]) {
                VOITURE *tmp = voitures[i];
                while (tmp) {
                    voitures[i] = voitures[i]->suivant;
                    delete tmp;
                    tmp = voitures[i];
                }
            }
        }
        delete voitures;
    }
}

void table_hachage::charger()
{

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
    query.exec();
    while(query.next())
    {
        if(!contient(query.value(0).toString()))
        {
            VALEUR V = creerVal(query.value(1).toString(),
                                query.value(4).toString(),
                                query.value(3).toInt(),
                                query.value(2).toString(),
                                query.value(6).toString(),
                                query.value(5).toString());
            qDebug() << "cle :" << query.value(0).toString();
            inserer(query.value(0).toString(),V);
        }

    }
    mysdb1.close();

}


void table_hachage::sauvegarder()
{
    {
        //QMessageBox::information(this,"Succes","La base de donnees est Sauvegardée a succes");
        // Vérifier si la base de données est déjà connectée, sinon la connecter
        if (QSqlDatabase::contains("gestion_voiture")) {
            QSqlDatabase::removeDatabase("gestion_voiture");
        }
        QSqlDatabase mysdb1 = QSqlDatabase::addDatabase("QPSQL");
        mysdb1.setHostName("localhost");
        mysdb1.setDatabaseName("gestion_voiture");
        mysdb1.setUserName("postgres");
        mysdb1.setPassword("mbarfall22");
        mysdb1.setPort(5432);

        // Ouvrir la base de données
        if (!mysdb1.open()) {
            // Afficher un message d'erreur si la connexion échoue
            QMessageBox::critical(nullptr, "Database Connection Error", mysdb1.lastError().text());
            return;
        }

        QSqlQuery query(mysdb1);

        // Supprimer toutes les données de la table "voiture"
        if (!query.exec("DELETE FROM voiture")) {
            // Afficher un message d'erreur si la suppression échoue
            QMessageBox::critical(nullptr, "Query Execution Error", query.lastError().text());
            mysdb1.close();
            return;
        }

        query.prepare("INSERT INTO voiture (matricule, marque, gamme, annee, modele, photo, presentation) VALUES (:matricule, :marque, :gamme, :annee, :modele, :photo, :presentation)");

        // Récupérer les données de la table de hachage
        for (int i=0; i<Nmax; i++) {
            VOITURE *current=voitures[i];
            while(current)
            {
                const QString& matricule = current->cle;
                const VALEUR& valeur = current->valeur;

                query.bindValue(":matricule", matricule);
                query.bindValue(":marque", valeur.marque);
                query.bindValue(":gamme", valeur.gamme);
                query.bindValue(":annee", valeur.annee);
                query.bindValue(":modele", valeur.modele);
                query.bindValue(":photo", valeur.photo);
                query.bindValue(":presentation", valeur.description);
                if (!query.exec()) {
                    QMessageBox::critical(nullptr, "Query Execution Error", query.lastError().text());
                    mysdb1.close();
                    return;
                }
                current=current->suivant;
            }


        }
        mysdb1.close();


    }
}

void table_hachage::inserer(QString cle, VALEUR val)
{
    switch (hachage_actuelle) {
        int valeur_hachage;
    case 1:
        valeur_hachage = f1(cle);
        if (!contient(cle)) {
            voitures[valeur_hachage] = Inserer_dans_une_liste(voitures[valeur_hachage], cle, val);
        }

        break;
    case 2:
        valeur_hachage = f2(cle);
        if (!contient(cle)) {
            voitures[valeur_hachage] = Inserer_dans_une_liste(voitures[valeur_hachage], cle, val);
        }
        break;
    case 3:
        valeur_hachage = f3(cle);
        if (!contient(cle)) {
            voitures[valeur_hachage] = Inserer_dans_une_liste(voitures[valeur_hachage], cle, val);
        }
        break;
    default:
        valeur_hachage = f4();
        if (!contient(cle)) {
            voitures[valeur_hachage] = Inserer_dans_une_liste(voitures[valeur_hachage], cle, val);
        }
        break;
    }
    nbr_voitures++;
}

VALEUR table_hachage::get(QString cle)
{
    VOITURE *pvoit = nullptr;

    switch (hachage_actuelle) {
        int valeur_hachage;
    case 1:
        valeur_hachage = f1(cle);
        pvoit = Est_dans_la_liste(voitures[valeur_hachage], cle);
        break;
    case 2:
        valeur_hachage = f2(cle);
        pvoit = Est_dans_la_liste(voitures[valeur_hachage], cle);
        break;
    case 3:
        valeur_hachage = f3(cle);
        pvoit = Est_dans_la_liste(voitures[valeur_hachage], cle);
        break;

    default:
        for (int i = 0; i < Nmax; i++) {

            if(voitures[i])
            {
                if(voitures[i]->cle==cle)
                {
                    return voitures[i]->valeur;
                }
            }
        }
        break;
    }
    return pvoit->valeur;
}

void table_hachage::supprimer(QString cle)
{

    int a = contient(cle);
    switch (hachage_actuelle) {
        int valeur_hachage;
    case 1:
        valeur_hachage = f1(cle);

        voitures[valeur_hachage] = Supprimer_dans_une_liste(voitures[valeur_hachage], cle);
        break;
    case 2:
        valeur_hachage = f2(cle);
        voitures[valeur_hachage] = Supprimer_dans_une_liste(voitures[valeur_hachage], cle);
        break;
    case 3:
        valeur_hachage = f3(cle);
        voitures[valeur_hachage] = Supprimer_dans_une_liste(voitures[valeur_hachage], cle);
        break;

    default:
        valeur_hachage = f4();
        voitures[valeur_hachage] = Supprimer_dans_une_liste(voitures[valeur_hachage], cle);
        break;
    }
    if (a)
        nbr_voitures--;
}

bool table_hachage::contient(QString cle)
{
    int valeur_hachage=0;
    switch (hachage_actuelle) {
    case 1:
        valeur_hachage = f1(cle);
        return Est_dans_la_liste(voitures[valeur_hachage], cle) != nullptr;
        break;
    case 2:
        valeur_hachage = f2(cle);
        return Est_dans_la_liste(voitures[valeur_hachage], cle) != nullptr;
        break;
    case 3:
        valeur_hachage = f3(cle);
        return Est_dans_la_liste(voitures[valeur_hachage], cle) != nullptr;
        break;
    default:
        for (int i = 0; i < Nmax; i++) {
            if(voitures[i])
            {
                if(voitures[i]->cle==cle)
                {
                    return true;
                }
            }
        }
        return false;
        break;
    }


}

int table_hachage::size()
{
    return nbr_voitures;
}

bool table_hachage::Est_vide()
{
    int i = 0;
    while (i < Nmax) {
        if (voitures[i]) {
            break;
        }
        i++;
    }
    if (i == Nmax) {
        return true;
    } else
        return false;
}

int table_hachage::f1(QString str)
{
    unsigned long hash = 5381;
    for (QChar c : str) {
        hash = ((hash << 5) + hash) + c.unicode();
    }
    return hash % Nmax;
}

unsigned long table_hachage::f2(QString &str)
{
    unsigned long hash = 0;
    for (int i = 0; i < str.length(); ++i) {
        QChar c = str[i];
        hash = (hash * 131) + c.unicode();
    }
    return hash%Nmax;
}

unsigned long table_hachage::f3(QString str)
{
    unsigned long hash = 0;
    for (QChar c : str) {
        hash = c.unicode() + (hash << 6) + (hash << 16) - hash;
    }
    return hash % Nmax;
}
int table_hachage::f4()
{
    for (int i = 0; i < Nmax; i++) {
        if (voitures[i] == nullptr) {
            return i;
        }
    }
    return -1;
}

VALEUR creerVal(QString m, QString mo, int an, QString gm, QString desc, QString ph)
{
    VALEUR v;
    v.marque = m;
    v.modele = mo;
    v.annee = an;
    v.gamme = gm;
    v.description = desc;
    v.photo = ph;
    return v;
}
VOITURE *Inserer_dans_une_liste(VOITURE *liste_voiture, QString cle, VALEUR val)
{
    VOITURE *nouvelle_voiture = new VOITURE;
    nouvelle_voiture->cle = cle;
    nouvelle_voiture->valeur.description = val.description;
    nouvelle_voiture->valeur.annee = val.annee;
    nouvelle_voiture->valeur.gamme = val.gamme;
    nouvelle_voiture->valeur.marque = val.marque;
    nouvelle_voiture->valeur.modele = val.modele;
    nouvelle_voiture->valeur.photo = val.photo;
    nouvelle_voiture->suivant = nullptr;


    if (!liste_voiture) {
        liste_voiture = nouvelle_voiture;
    } else {
        if (!Est_dans_la_liste(liste_voiture, cle)) {
            nouvelle_voiture->suivant = liste_voiture;
            liste_voiture = nouvelle_voiture;
        } else {
            //message d'erreur:voiture déjà présent
        }
    }
    return liste_voiture;
}

VOITURE *Est_dans_la_liste(VOITURE *liste_voiture, QString cle)
{
    VOITURE *tmp = liste_voiture;
    while (tmp) {
        if (tmp->cle == cle) {
            return tmp;
        }
        tmp = tmp->suivant;
    }
    return nullptr; // Retourne nullptr si la clé n'est pas trouvée
}

VOITURE *Supprimer_dans_une_liste(VOITURE *liste_voiture, QString cle)
{
    if (liste_voiture) {
        if (liste_voiture->cle == cle) {
            VOITURE *tmp = liste_voiture;
            liste_voiture = liste_voiture->suivant;
            delete tmp;
        } else {
            VOITURE *precedent = liste_voiture, *courant = liste_voiture;
            while (courant && cle != courant->cle) {
                precedent = courant;
                courant = courant->suivant;
            }
            if (courant) {
                precedent->suivant = courant->suivant;
                delete courant;
            }
        }
    }
    return liste_voiture;
}

void table_hachage::setHachage_actuelle (int hash){

    hachage_actuelle = hash ;

}

int table_hachage::getHachage_actuelle () {
    return hachage_actuelle ;
}

void table_hachage::vider() {
    if (voitures) {
        for (int i = 0; i < Nmax; i++) {
            if (voitures[i]) {
                VOITURE *tmp = voitures[i];
                VOITURE *suiv = voitures[i];
                while (suiv) {
                    tmp=suiv;
                    suiv=suiv->suivant;
                    delete tmp;
                }
                voitures[i]=nullptr;
            }
        }
        delete voitures;
    }
    voitures = new VOITURE *[Nmax];
    nbr_voitures = 0;
    hachage_actuelle = 0 ;
    for (int i = 0; i < Nmax; i++) {
        voitures[i] = nullptr;
    }
}
