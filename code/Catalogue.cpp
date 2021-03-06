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

TrajetSimple* Catalogue::importTrajetSimple(istream& inFile)
{
  string villeDepart;
  string villeArrivee;
  string Transport;
  getline(inFile, villeDepart);
  getline(inFile, villeArrivee);
  getline(inFile, Transport);
  TrajetSimple* trajet = new TrajetSimple(villeDepart.c_str(), villeArrivee.c_str(), Transport.c_str());
  return trajet;
}

TrajetCompose* Catalogue::importTrajetCompose(istream &inFile)
{
  string courant;
  int nbTrajets; 
  inFile >> nbTrajets;
  getline(inFile, courant);
  TrajetCompose* trajet = new TrajetCompose();
  for(int i = 0 ; i<nbTrajets; i++)
  {
    getline(inFile, courant);
    if(courant == "TS")
    {
      trajet->AjouterTrajet(importTrajetSimple(inFile));
    } else if (courant == "TC")
    {
      trajet->AjouterTrajet(importTrajetCompose(inFile));
    }
  }
  return trajet;
}

void Catalogue::ExportFile(const char* fileName, int option, string villeDepart, string villeArrivee, unsigned int debut, unsigned int fin)
{
  ofstream outFile;
  outFile.open(fileName);
  for(unsigned int i = 0 ; i< listeTrajets.GetTaille(); i++)
  {
    // sauvegarde tous les trajets
    if(option == 1)
    {
      outFile << listeTrajets.GetAtIndex(i)->GetValeur()->Formatage();
    } 
    // sauvegarde des trajets simples uniquement: 
    else if(option == 12)
    {
      if(listeTrajets.GetAtIndex(i)->GetValeur()->Formatage()[1] == 'S')
      {
        outFile << listeTrajets.GetAtIndex(i)->GetValeur()->Formatage();
      }
    }
    // sauvegarde des trajets composés uniquement:
    else if(option == 22)
    {
      if(listeTrajets.GetAtIndex(i)->GetValeur()->Formatage()[1] == 'C')
      {
        outFile << listeTrajets.GetAtIndex(i)->GetValeur()->Formatage();
      }
    }
    // sauvegarde selon ville de départ 
    else if (option == 13)
    {
      if(strcmp(listeTrajets.GetAtIndex(i)->GetValeur()->GetVilleDepart(), villeDepart.c_str()) == 0)
      {
        outFile << listeTrajets.GetAtIndex(i)->GetValeur()->Formatage();
      }
    }
    // sauvegarde selon ville d'arrivée 
    else if (option == 23)
    {
      if(strcmp(listeTrajets.GetAtIndex(i)->GetValeur()->GetVilleArrivee(), villeArrivee.c_str())== 0)
      {
        outFile << listeTrajets.GetAtIndex(i)->GetValeur()->Formatage();
      }
    }
    // sauvegarde selon les deux villes
    else if (option == 33)
    {
      if(strcmp(listeTrajets.GetAtIndex(i)->GetValeur()->GetVilleDepart(), villeDepart.c_str()) == 0 
      && strcmp(listeTrajets.GetAtIndex(i)->GetValeur()->GetVilleArrivee(), villeArrivee.c_str()) == 0)
      {
        outFile << listeTrajets.GetAtIndex(i)->GetValeur()->Formatage();
      }
    }
    // sauvegarde d'intervalle
    else if (option == 4)
    {
      if(i>= debut && i <= fin)
      {
        outFile << listeTrajets.GetAtIndex(i)->GetValeur()->Formatage();
      }
    }
  }
  outFile.close();
}

void Catalogue::ImportFile(const char* fileName, int option, string villeDepart, string villeArrivee, unsigned int debut, unsigned int fin)
{
  ifstream inFile;
  inFile.open(fileName);
  string courant;
  unsigned int indiceTrajet = 0;
  while(inFile && inFile.eof() != 1)
  {
    getline(inFile, courant);
    if (courant == "TS")
    {
      TrajetSimple* trajetS = importTrajetSimple(inFile);
      if(option == 1 || option == 12)
      {
        Ajouter(trajetS);
      } else if (option == 13 && strcmp(trajetS->GetVilleDepart(), villeDepart.c_str()) == 0)
      {
        Ajouter(trajetS);
      } else if( option == 23 && strcmp(trajetS->GetVilleArrivee(), villeArrivee.c_str())== 0)
      {
        Ajouter(trajetS);
      } else if (option == 33 && strcmp(trajetS->GetVilleDepart(), villeDepart.c_str()) == 0 && strcmp(trajetS->GetVilleArrivee(), villeArrivee.c_str()) == 0)
      {
        Ajouter(trajetS);
      } else if(option == 4 && indiceTrajet >= debut && indiceTrajet <= fin)
      {
        Ajouter(trajetS);
      }
      indiceTrajet++;
    } else if ( courant == "TC") 
    {
      TrajetCompose* trajetC = importTrajetCompose(inFile);
      if(option == 1 || option == 22)
      {
        Ajouter(trajetC);
      }else if (option == 13 && strcmp(trajetC->GetVilleDepart(), villeDepart.c_str()) == 0)
      {
        Ajouter(trajetC);
      } else if( option == 23 && strcmp(trajetC->GetVilleArrivee(), villeArrivee.c_str())== 0)
      {
        Ajouter(trajetC);
      } else if (option == 33 && strcmp(trajetC->GetVilleDepart(), villeDepart.c_str()) == 0 && strcmp(trajetC->GetVilleArrivee(), villeArrivee.c_str()) == 0)
      {
        Ajouter(trajetC);
      } else if(option == 4 && indiceTrajet >= debut && indiceTrajet <= fin)
      {
        Ajouter(trajetC);
      }
      indiceTrajet++;
    }
  }
  inFile.close();
}

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

unsigned int Catalogue::GetNbTrajets( void ){
  return listeTrajets.GetTaille();
} //----- Fin de GetNbTrajets()

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
