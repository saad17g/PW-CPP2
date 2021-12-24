/************************************************************************
                           Liste Chaînée  -  Composant TrajetCompose
                             -------------------
    début                : 15/11/2021
    copyright            : (C) 2021 par Jules DUCANGE et Saad GUESSOUS
    e-mail               : Jules.Ducange@insa-lyon.fr
                           Saad.Guessous@insa-lyon.fr
*************************************************************************/

//-- Réalisation de la classe <ListeChainee> (fichier ListeChainee.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <cstring>
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Trajet.h"
#include "ListeChainee.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void ListeChainee::Ajouter ( Cellule* nouvelleCellule)
{
    nouvelleCellule->suivante = NULL;

    /* Liste vide */
    if (debut == NULL) {
        fin = debut = nouvelleCellule;
        return;
    }

    /* Vérifie que la valeur n'existe pas déjà dans la liste */
    Cellule* courante = debut;
    while (courante != NULL) {
        if (courante == nouvelleCellule) return;
        courante = courante->suivante;
    }

    /* Ajoute la cellule en fin de liste */
    fin->suivante = nouvelleCellule ;
    fin = nouvelleCellule;
    taille++;
} //----- Fin de Ajouter

void ListeChainee::AjouterOrdonne ( Cellule* nouvelleCellule)
{
    nouvelleCellule->suivante = NULL;

    /* Liste vide */
    if (debut == NULL) {
        fin = debut = nouvelleCellule;
        taille++;
        return;
    }

    /* Vérifie que la valeur n'existe pas déjà dans la liste */
    Cellule* parcours = debut;
    while (parcours != NULL) {
        if (parcours == nouvelleCellule) return;
        parcours = parcours->suivante;
    }

    parcours = debut;
    /* cas d'insertion en début de liste avec un nouveau trajet inférieur à celui qui existe */
    if(!compareAlphabetique(debut->GetValeur(),nouvelleCellule->GetValeur()))
    {
        nouvelleCellule->suivante = debut;
        debut = nouvelleCellule;
    } 
    /* la liste a un seul élement */
    else if( debut->suivante == NULL)
    {
        debut->suivante = nouvelleCellule;
    }
    /* cas général */
    else 
    {
        const Trajet* t1 = parcours->suivante->GetValeur();
        const Trajet* t2 = nouvelleCellule->GetValeur();
        while(parcours->suivante && compareAlphabetique(t1,t2))
        {
            parcours = parcours->suivante;
            if(parcours->suivante)
            {
                t1 = parcours->suivante->GetValeur();
            }
        }
        nouvelleCellule->suivante = parcours->suivante;
        parcours->suivante = nouvelleCellule;
    }
    taille++;
} //----- Fin de Ajouter

void ListeChainee::Retirer ( void )
{
    /* Liste vide */
    if (debut == NULL || fin == NULL) return;

    Cellule* precedente = NULL;
    Cellule* parcours = debut;

    while (parcours->suivante != NULL) {
        precedente = parcours;
        parcours = parcours->suivante;
    }
    
    /* Suppression de la tête de liste */
    if (precedente != NULL)
        precedente->suivante = NULL;

    if (debut == fin)
        debut = NULL;

    delete fin;
    fin = precedente;
} //----- Fin de Retirer

const Cellule* ListeChainee::GetDebut ( void ) const{
    return debut;
} //----- Fin de GetDebut

const Cellule* ListeChainee::GetFin ( void ) const{
    return fin;
} //----- Fin de GetFin

const Cellule* ListeChainee::GetAtIndex( unsigned int index ) const{
    if(index >= taille)
    {
        return 0;
    }
    Cellule* parcours = debut;
    for (unsigned int i = 0; i < index; i++)
    {
        parcours = parcours->suivante;
    }
    return parcours;
} //----- Fin de GetAtIndex

unsigned int ListeChainee::GetTaille( void ) const {
    return taille;
} //----- Fin de GetTaille

void ListeChainee::Afficher ( void ) const {

    Cellule* parcours = debut;
    while (parcours != NULL) {
        parcours->valeur->Afficher();
        parcours = parcours->suivante;
    }

} //----- Fin de Afficher

//-------------------------------------------- Constructeurs - destructeur

ListeChainee::ListeChainee ( void )
    : debut (NULL), fin (NULL), taille(0)
{
    #ifdef MAP
    cout << "Appel au constructeur de <ListeChainee>" << endl;
    #endif
} //----- Fin de ListeChainee


ListeChainee::~ListeChainee ( void )
{
    #ifdef MAP
    cout << "Appel au destructeur de <ListeChainee>" << endl;
    #endif

    Cellule* precedente = NULL;
    Cellule* parcours = debut;

    while (parcours != NULL) {
        precedente = parcours;
        parcours = parcours->suivante;
        delete precedente;
    }

} //----- Fin de ~ListeChainee

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
//----------------------------------------------------- Méthodes protégées
bool ListeChainee::compareAlphabetique ( const Trajet* trajet1, const Trajet* trajet2 ) const
// Algorithme :
// Compare par ordre alphabétique les villes de départs entre elles, puis les villes d'arrivée pour chaque ville de départ 
// en utilisant la fonction strcmp() de la librairie <cstring>
{
    // compareVilleDepart < 0 si le premier caractère différent a une valeur plus petite dans trajet1->GetVilleDepart() que dans trajet2->GetVilleDepart()
    int compareVilleDepart = strcmp(trajet1->GetVilleDepart(), trajet2->GetVilleDepart());
    // pareil
    int compareVilleArrivee = strcmp(trajet1->GetVilleArrivee(), trajet2->GetVilleArrivee());
    // result vaut 1 si VilleDepart de trajet 1 est inférieur à VilleDepart de trajet 2 
    // ou les deux trajets ont la même ville de départ, et VilleArrivee de trajet 1 est inférieur à VilleArrivee de trajet 2
    if( compareVilleDepart < 0 || (compareVilleDepart == 0 && compareVilleArrivee < 0) )
    {
        return true;
    }
    return false;
} //----- Fin de compareAlphabetique
