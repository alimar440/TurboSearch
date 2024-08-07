#ifndef TABLE_HACHAGE_INCLUDED
#define TABLE_HACHAGE_INCLUDED

#include <iostream>
#include <QString>
#include "qcustomplot.h"
#define Nmax 1000

using namespace std;


struct VALEUR
{
    QString marque;
    QString gamme;
    int annee;
    QString modele;
    QString photo;
    QString description;
};


struct VOITURE
{
    QString cle;
    VALEUR valeur;
    VOITURE *suivant;
};


class table_hachage
{
private:
    int nbr_voitures;
    int hachage_actuelle;
    VOITURE** voitures;
public:
    table_hachage();

    ~table_hachage();

    void inserer(QString cle, VALEUR val);

    VALEUR get(QString cle);

    void supprimer(QString cle);

    bool contient(QString cle);

    int size();

    bool Est_vide();

    int f1(QString);
    unsigned long f2(QString& str) ;
    unsigned long f3(QString);
    int f4();

    void charger();
    void sauvegarder();

    void affiche();
    void setHachage_actuelle (int ) ;
    int getHachage_actuelle () ;
    void vider() ;
};


VOITURE* Inserer_dans_une_liste(VOITURE* liste_voiture, QString cle, VALEUR val);

VOITURE* Est_dans_la_liste(VOITURE* liste_voiture, QString cle);

VOITURE* Supprimer_dans_une_liste(VOITURE* liste_voiture, QString cle);

VALEUR creerVal(QString,QString,int,QString,QString,QString);
#endif
