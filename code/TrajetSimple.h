/************************************************************************
                           TrajetSimple  -  Implémentation de Trajet
                             -------------------
    début                : 15/11/2021
    copyright            : (C) 2021 par Jules DUCANGE et Saad GUESSOUS
    e-mail               : Jules.Ducange@insa-lyon.fr
                           Saad.Guessous@insa-lyon.fr
*************************************************************************/

// ---- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ---
#if ! defined TRAJETSIMPLE_H_
#define TRAJETSIMPLE_H_

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
// 
// TrajetSimple est une classe fille de la classe Trajet
// un TrajetSimple étant un trajet, il possède naturellement une ville de 
// départ et une ville d'arrivée. 
// De plus TrajetSimple possède un attribut spécifique à lui, qui est 
// le moyen de transport.
//
//------------------------------------------------------------------------

class TrajetSimple : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    const char* GetVilleDepart( void ) const;
    const char* GetVilleArrivee( void ) const;
    virtual void Afficher( void ) const;

//-------------------------------------------- Constructeurs - destructeur
    TrajetSimple ( const char*, const char*, const char*);
    TrajetSimple ( const TrajetSimple& );
    virtual ~TrajetSimple ( );

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    char* villeDepart;
    char* villeArrivee;
    char* moyenTransport;
};

//----------------------- Autres définitions dépendantes de <TrajetSimple>

#endif // TRAJETSIMPLE_H_
