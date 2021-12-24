/************************************************************************
                           Cellule  -  Composant ListeChainée
                             -------------------
    début                : 15/11/2021
    copyright            : (C) 2021 par Jules DUCANGE et Saad GUESSOUS
    e-mail               : Jules.Ducange@insa-lyon.fr
                           Saad.Guessous@insa-lyon.fr
*************************************************************************/

//------- Interface de la classe <Cellule> (fichier Cellule.h) ----------
#if ! defined CELLULE_H_
#define CELLULE_H_

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Cellule>
// Base de l'implémentatio de la liste chaînée sous forme de cellules
// une cellule contient une valeur, qui est un pointeur de Trajet
// et un pointeur sur la cellule qui la suit
// La classe Celulle est en mode `friend` avec la classe ListeChainee
// Cela permet à la classe ListeChainee d'accéder à tous les attributs 
// de Cellule, ce qui est cohérent avec notre idée d'implémentation
//------------------------------------------------------------------------

class Cellule
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    const Trajet* GetValeur ( void ) const;
    // Mode d'emploi :
    // Retourne la valeur contenue dans la Cellule appelant la méthode

    const Cellule* GetSuivante ( void ) const;
    // Mode d'emploi :
    // Retourne la Cellule qui suit la Cellule appelant la méthode

//-------------------------------------------- Constructeurs - destructeur
    Cellule ( Trajet*, Cellule* );
    // Mode d'emploi :
    // Construit une Cellule à partir d'un pointeur sur un trajet et d'une 
    // Cellule suivante

    Cellule ( const Cellule& );
    // Mode d'emploi :
    // Constructeur de copie de Cellule

    virtual ~Cellule ( );
    // Mode d'emploi :
    // Destructeur de Cellule

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    Trajet *valeur;
    Cellule *suivante;

    friend class ListeChainee; // ListeChainee a donc accès aux attributs de la classe Cellule
};

//-------------------------------- Autres définitions dépendantes de <Cellule>

#endif // CELLULE_H_
