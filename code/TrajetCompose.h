/************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : 15/11/2021
    copyright            : (C) 2021 par Jules DUCANGE et Saad GUESSOUS
    e-mail               : Jules.Ducange@insa-lyon.fr
                           Saad.Guessous@insa-lyon.fr
*************************************************************************/

//--- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ---
#if ! defined TRAJETCOMPOSE_H_
#define TRAJETCOMPOSE_H_

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "ListeChainee.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
// Classe fille de la classe Trajet
// Un trajet composé est une collection ordonnée de trajets
// Un trajet composé étant lui même un trajet, il possède naturellement
// une ville de départ et une ville d'arrivée
// Toutefois, ces informations ne sont pas directement des attributs de la classe
// mais sont accessibles à travers deux méthodes (getters)
// La condition de validation d'un trajet composé est que la ville d'arrivée
// de chaque trajet soit la ville de départ du trajet qui suit.
// Cette condition doit être assurée par l'utilisateur qui insère les trajets.
//------------------------------------------------------------------------

class TrajetCompose : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    const char* GetVilleDepart( void ) const;

    const char* GetVilleArrivee( void ) const;

    void Afficher( void ) const;

    void AjouterTrajet ( Trajet* );
    // Mode d'emploi :
    // Permet l'ajout d'un trajet composé
    // Contrat :
    // la ville d'arrivée de chaque trajet est la ville de départ du trajet
    // qui suit
    void RetirerTrajet ( void );
    // Mode d'emploi :
    // Retirer un trajet
    // Contrat :
    // le trajet existe parmis les trajets du trajet composé

//-------------------------------------------- Constructeurs - destructeur
    TrajetCompose ( void );

    virtual ~TrajetCompose ( void );

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    ListeChainee listeTrajets;
};

//-------------------------------- Autres définitions dépendantes de <TrajetCompose>

#endif // TRAJETCOMPOSE_H_
