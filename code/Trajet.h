/*************************************************************************
                           Trajet  -  Classe abstraite
                             -------------------
    début                : 15/11/2021
    copyright            : (C) 2021 par Jules DUCANGE et Saad GUESSOUS
    e-mail               : Jules.Ducange@insa-lyon.fr
                           Saad.Guessous@insa-lyon.fr
*************************************************************************/

//--------- Interface de la classe <Trajet> (fichier Trajet.h) -----------
#if ! defined ( TRAJET_H )
#define TRAJET_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
// La classe Trajet est une classe abstraite ancêtre des deux classes
// TrajetSimple et TrajetCompose, elle permet de représenter la signification
// d'un trajet, en le représentant par une ville de départ et une ville d'arrivée
// L'avantage d'utiliser une classe abstraite est bien évidemment de pouvoir
// manipuler les classes filles (TrajetSimple et TrajetCompose) sans distinction
// dans les collections qu'on aura à manipuler plus tard
//------------------------------------------------------------------------

class Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    // Retourne un pointeur sur villeDepart.
    virtual const char* GetVilleDepart( void ) const = 0;

    // Retourne un pointeur sur villeArrivee.
    virtual const char* GetVilleArrivee( void ) const = 0;

    // Affiche les informations du trajet.
    virtual void Afficher( void ) const = 0;

//-------------------------------------------- Constructeurs - destructeur
    Trajet ( );

    Trajet ( const Trajet& trajet );

    virtual ~Trajet ( );

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//----------------------------- Autres définitions dépendantes de <Trajet>

#endif // TRAJET_H_
