/*************************************************************************
                           Catalogue - Description
                             -------------------
    début                : 15/11/2021
    copyright            : (C) 2021 par Jules DUCANGE et Saad GUESSOUS
    e-mail               : Jules.Ducange@insa-lyon.fr
                           Saad.Guessous@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Catalogue::Afficher (void) const {
  cout << "----- Début du catalogue -----" << endl;
  listeTrajets.Afficher();
  cout << "----- Fin du catalogue -------" << endl << endl;
} //----- Fin de Afficher

void Catalogue::Rechercher ( const char* VilleDepart, const char* VilleArrivee) const {

  bool trajetTrouve = false;
  const Cellule* celluleCourante = listeTrajets.GetDebut();

  cout << "Résultats de votre recherche : " << endl;
  while ( celluleCourante != NULL ) {

    const Trajet* trajetCourant = celluleCourante->GetValeur();
    if (strcmp(VilleDepart, trajetCourant->GetVilleDepart()) == 0 && strcmp(VilleArrivee, trajetCourant->GetVilleArrivee()) == 0) {
      trajetTrouve = true;
      trajetCourant->Afficher();
    }

    celluleCourante = celluleCourante->GetSuivante();
  }

  if (trajetTrouve == false)
    cout << "Aucun trajet ne correspond à votre recherche." << endl;
}  //----- Fin de Rechercher

void Catalogue::rechercheAvancee( const char* VilleDepart, const char* VilleArrivee ) const
{
  bool trajetTrouve = false;
  // tableau de pointeurs sur trajet, contenant la combinaison de trajets pour la recherche demandée
  const Trajet** combinaison = new const Trajet* [listeTrajets.GetTaille()]; 

  for(unsigned int i = 0; i<listeTrajets.GetTaille(); i++)
  {
    combinaison[i] = 0;
  }
  parcoursEnProfondeur(combinaison, listeTrajets.GetTaille(), VilleDepart, VilleArrivee, trajetTrouve, 0);
  if(trajetTrouve == false)
  {
    cout << "Aucune combinaison ne permet de réaliser ce trajet " <<endl;
  }
  delete [] combinaison;
} //----- Fin de rechercheAvancee

void Catalogue::Ajouter( Trajet* trajet) {
  listeTrajets.AjouterOrdonne(new Cellule(trajet, NULL));
} //----- Fin de Ajouter

//-------------------------------------------- Constructeurs - destructeur

Catalogue::Catalogue ( void )
// Algorithme :
//
{
  #ifdef MAP
  cout << "Appel au constructeur de <Catalogue>" << endl;
  #endif

  ListeChainee listeTrajets;    
} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
// Algorithme :
//
{
  #ifdef MAP
  cout << "Appel au destructeur de <Catalogue>" << endl;
  #endif
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
// Algorithme :
// Parcours le catalogue en profondeur et construit une combinaison de trajets
// par appel récursif, jusqu'a arriver a la recherche de l'utilisateur
void Catalogue::parcoursEnProfondeur(const Trajet** combinaison, int profondeurMax,
                                    const char* VilleDepart, const char* VilleArrivee,
                                    bool& trajetTrouve, int profondeur ) const
{
  // verifier si on a atteint la fin du catalogue
  if(profondeur == profondeurMax)
  {
    return;
  }

  // parcours de chaque trajet du catalogue
  for(int i = 0; i<profondeurMax; i++)
  {
    const Cellule * trajetPotentiel = listeTrajets.GetAtIndex(i);
    //recherche des trajets dont la ville de depart correspond à VilleDepart
    if(strcmp(trajetPotentiel->GetValeur()->GetVilleDepart(), VilleDepart) != 0)
    {
      continue;
    }
    // Verification de si le trajet trouvé n'est pas déjà présent dans la combinaison
    bool present = false;
    for(int j = 0; j<profondeur; j++)
    {
      if(trajetPotentiel->GetValeur() == combinaison[j])
      {
        present = true;
        break;
      }
    }
    if(present == false)
    {
      combinaison[profondeur] = trajetPotentiel->GetValeur();

      // Verification de si la ville d'arrivée de ce trajet correspond à VilleArrivee
      if(strcmp(trajetPotentiel->GetValeur()->GetVilleArrivee(), VilleArrivee) == 0)
      {
        trajetTrouve = true;
        cout << "Combinaison trouvée : " << endl;
        //Affichage de la combinaison
        for(int j = 0; j<profondeur+1; j++)
        {
          combinaison[j]->Afficher();
        }
        cout << endl;
      }
      // si ce n'est pas le cas, appel recursif pour continuer le parcours en profondeur
      parcoursEnProfondeur(combinaison, profondeurMax, trajetPotentiel->GetValeur()->GetVilleArrivee(), VilleArrivee, trajetTrouve, profondeur + 1);
    }
  }
} //----- Fin de parcoursEnProfondeur
