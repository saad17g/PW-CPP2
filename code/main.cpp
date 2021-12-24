#include "Catalogue.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include <cstring>

#include <iostream>
using namespace std;

// Menu d'utilisation de l'application
void AfficherMenu()
{
  cout << "Voici le menu du projet, veuillez choisir un numéro : " << endl; 
  cout << "\t1. Afficher le catalogue " << endl \
    << "\t2. Ajouter un trajet simple " << endl \
    << "\t3. Ajouter un trajet composé " << endl\
    << "\t4. Recherche simple d'un trajet " << endl\
    << "\t5. Recherche avancée d'un trajet" << endl\
    << "\t6. Quitter le menu" << endl;
}

// récupération d'un input de l'utilisateur
// allocation dynamique + utilisation d'uun buffer
char* InputString ( void ) {
  char* buffer = new char[2048];
  cin >> buffer;

  char* str = new char[strlen(buffer) + 1];
  strcpy(str, buffer);

  delete [] buffer;
  return str;
}

// récupération d'un trajet rentré par l'utilisateur
TrajetSimple* RecupererTrajet()
{
  char* villeDepart = NULL;
  char* villeArrivee = NULL;
  char* transport = NULL;

  cout << "Ville de départ : ";
  villeDepart = InputString();

  cout << "Ville d'arrivée : ";
  villeArrivee = InputString();

  cout << "Moyen de transport : ";
  transport = InputString();

  TrajetSimple* trajet = new TrajetSimple(villeDepart, villeArrivee, transport);

  delete [] villeDepart;
  delete [] villeArrivee;
  delete [] transport;

  return trajet;
}

void Rechercher(Catalogue& catalogue) {
  const char* VilleDepart = NULL;
  const char* VilleArrivee = NULL;

  cout << "Ville de départ : ";
  VilleDepart = InputString();

  cout << "Ville d'arrivée : ";
  VilleArrivee = InputString();
  
  cout <<endl;
  catalogue.Rechercher(VilleDepart, VilleArrivee);

  delete [] VilleArrivee;
  delete [] VilleDepart;
}

void RechercheAvancee( Catalogue& catalogue)
{
  const char* VilleDepart = NULL;
  const char* VilleArrivee = NULL;

  cout << "Ville de départ : ";
  VilleDepart = InputString();

  cout << "Ville d'arrivée : ";
  VilleArrivee = InputString();
  cout <<endl;
  catalogue.rechercheAvancee(VilleDepart, VilleArrivee);

  delete [] VilleArrivee;
  delete [] VilleDepart;
}

int main()
{
  cout << "//////////////////////////////////////////////////////////////////////////" << endl \
      << "// Bienvenue au projet POO2 réalisé par Jules DUCANGE et Saad GUESSOUS  //" << endl \
      << "// Ce projet consiste à pouvoir gérer un catalogue de trajets.          //" << endl \
      << "// Le projet inclue la méthode de recherche avancée.                    //" <<endl \
      << "//////////////////////////////////////////////////////////////////////////" << endl;
  cout << endl;

  Catalogue catalogue ;
  int nbTrajets;
  while(1)
  {
    cout <<endl;
    AfficherMenu();
    int choix;
    cin >> choix;
    switch(choix)
    {
      case 1 : {
        catalogue.Afficher();
        break;
      }
      case 2 : {
        TrajetSimple* trajet = RecupererTrajet();
        catalogue.Ajouter(trajet);
        break;
      }
      case 3: {
        cout << "Veuillez rentrer le nombre de trajets dans votre trajet composé" <<endl;
        cin >> nbTrajets;
        TrajetCompose* trajetCompose = new TrajetCompose();
        for( int i = 0; i < nbTrajets; i++)
        {
          trajetCompose->AjouterTrajet(RecupererTrajet());
        }
        catalogue.Ajouter(trajetCompose);
        break;
      }
      case 4: {
        Rechercher(catalogue);
        break;
      }
      case 5: {
        RechercheAvancee(catalogue);
        break;
      }
      case 6: {
        cout << " Bon voyage ! " <<endl;
        return 0;
      }
      default: {
        cout << "Choix incorrect." <<endl;
        break;
      }
    }
  }

  return 0;
}
