/*************************************************************************
                           Catalogue - Description
                             -------------------
    début                : 15/11/2021
    copyright            : (C) 2021 par Jules DUCANGE et Saad GUESSOUS
    e-mail               : Jules.Ducange@insa-lyon.fr
                           Saad.Guessous@insa-lyon.fr
*************************************************************************/

//---- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------
#if !defined(CATALOGUE_H)
#define CATALOGUE_H

//--------------------------------------------------- Interfaces utilisées
#include "ListeChainee.h"
#include "TrajetCompose.h"
#include "TrajetSimple.h"

#include <cstring>
#include <string>
#include <istream>
#include <fstream>

#include <iostream>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
// Creation d'un catalogue de trajets ordonnés par ordre alphabétique
// Le catalogue est interactif avec l'utilisateur, ce qui veut dire 
// que ce dernier peut Afficher le catalogue, y Ajouter des trajets 
// et rechercher des trajets dans le catalogue
// En terme d'implémentation, le catalogue est une liste de trajets
// pouvant être simples ou complexes
//------------------------------------------------------------------------

class Catalogue
{
  //----------------------------------------------------------------- PUBLIC

public:
  //----------------------------------------------------- Méthodes publiques

  void Afficher( void ) const;

  void ExportFile(const char* fileName, int option = 1, string villeDepart = "", string villeArrivee = "", unsigned int debut = 0, unsigned int fin = 0);

  void ImportFile(const char* fileName, int option = 1, string villeDepart = "", string villeArrivee = "", unsigned int debut = 0, unsigned int fin = 0);

  void Rechercher ( const char* VilleDepart, const char* VilleArrivee) const;

  void rechercheAvancee(const char* VilleDepart, const char* VilleArrivee) const;
  
  void Ajouter ( Trajet* );

  unsigned int GetNbTrajets ( void );


  //-------------------------------------------- Constructeurs - destructeur
  Catalogue( void );
  // Mode d'emploi :
  // Construction du catalogue

  virtual ~Catalogue( void );
  // Mode d'emploi :
  // Destruction du catalogue

  //------------------------------------------------------------------ PRIVE

protected:
  //----------------------------------------------------- Méthodes protégées
  void parcoursEnProfondeur(const Trajet** combinaison, int profondeurMax,
                                    const char* VilleDepart, const char* VilleArrivee,
                                    bool& troue, int niveau ) const;
                                  
  TrajetCompose* importTrajetCompose(istream&);

  TrajetSimple* importTrajetSimple(istream&);
  //----------------------------------------------------- Attributs protégés
  ListeChainee listeTrajets;
};

//-------------------------------- Autres définitions dépendantes de <Catalogue>
#endif // CATALOGUE_H
