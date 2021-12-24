/************************************************************************
                           Liste Chaînée  -  Composant TrajetCompose
                             -------------------
    début                : 15/11/2021
    copyright            : (C) 2021 par Jules DUCANGE et Saad GUESSOUS
    e-mail               : Jules.Ducange@insa-lyon.fr
                           Saad.Guessous@insa-lyon.fr
*************************************************************************/

//---- Interface de la classe <ListeChainee> (fichier ListeChainee.h) ----
#if ! defined LISTECHAINEE_H_
#define LISTECHAINEE_H_

//--------------------------------------------------- Interfaces utilisées
#include "Cellule.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <ListeChainee>
// 
// La ListeChainee est une succession simple de chainons (Cellules) qui possèdent
// chacun un pointeur vers leur Trajet.
// Le role de la classe est de permettre l'implémentation d'une liste ordonnée de trajets
// La classe ListeChainee est utile pour deux situations dans notre application : 
// 1- Implémentation de TrajetCompose : 
//      Un trajet composé est une liste ordonnée de trajets simples ou composés insérés
//      par l'utilisateur, l'ordre de cette liste est le même que celui des inputs
//      de l'utilisateur.
// 2- Implémentation du Catalogue : 
//      Le Catalogue est une liste ordonnée alphabétiquement de trajets
//      pouvant être simples ou composés
// Cette ListeChainee permet de :
//      - Ajouter un trajet
//      - Retirer un trajet
//      - Accéder au premier trajet de la liste
//      - Accéder au dernier trajet de la liste
//      - Accéder à un trajet via un index
//      - Récupérer la taille de la liste 
//------------------------------------------------------------------------

class ListeChainee
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void Ajouter ( Cellule* );
    // Mode d'emploi :
    // Ajout d'une Cellule à la liste

    void AjouterOrdonne ( Cellule* );
    // Mode d'emploi :
    // Ajout d'une Cellule à la liste, en respectant le tri alphabétique

    void Retirer ( void );
    // Mode d'emploi :
    // Retirer une cellule de la liste

    const Cellule* GetDebut ( void ) const;
    // Mode d'emploi :
    // Retourne un pointeur sur le debut de la liste

    const Cellule* GetFin ( void ) const;
    // Mode d'emploi :
    // Retourne un pointeur sur la fin de la liste

    unsigned int GetTaille( void ) const;
    // Mode d'emploi :
    // Retourne la taille (le nombre de cellules) de la liste

    const Cellule* GetAtIndex( unsigned int index ) const;
    // Mode d'emploi :
    // Retourne un pointeur sur la Cellule située à l'index rentré 
    // par l'utilisateur
    // Contrat :
    // l'index est positif, il y a une gestion d'erreur au cas où 
    // l'index est plus grand que la taille de la liste.

    void Afficher ( void ) const;
    // Mode d'emploi : 
    // Affichage de la liste
    
//-------------------------------------------- Constructeurs - destructeur
    ListeChainee ( void );

    virtual ~ListeChainee ( void );

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    bool compareAlphabetique ( const Trajet* t1, const Trajet* t2 ) const;
    
//----------------------------------------------------- Attributs protégés
    Cellule* debut;
    Cellule* fin;
    unsigned int taille;
};

//----------------------- Autres définitions dépendantes de <ListeChainee>

#endif // LISTECHAINEE_H_
