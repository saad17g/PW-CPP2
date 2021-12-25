#include "Catalogue.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

#include <cstring>
#include <string>
#include <istream>
#include <fstream>

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
    << "\t6. Import un fichier de trajets" << endl\
    << "\t7. Export le catalogue dans un fichier" << endl\
    << "\t8. Quitter le menu" << endl;
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
  string File;
  int option;
  int optionType;
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
        cout << "Veuillez rentrer le nom du fichier, avec son extension" <<endl;
        cin >> File;
        cout << "Quelle option de restitution souhaitez-vous utiliser ? " << endl; 
        cout << "\t1 : Sans critère de selection" << endl;
        cout << "\t2 : Selon le type de trajet" << endl;
        cout << "\t3 : Selon la ville de départ ou d'arrivée" << endl;
        cout << "\t4 : Selon une sélection de trajets" << endl;
        cin >> option;
        switch(option)
        {
          case 1 : {
            catalogue.ImportFile(File.c_str(), option);
            break;
          }
          case 2 : {
            int optionType;
            cout << "Quelle type de trajet souhaitez-vous restituer ?" <<endl;
            cout << "\t1 : simple" <<endl;
            cout << "\t2 : composé" <<endl;
            cin >> optionType;
            option += 10 * optionType;
            catalogue.ImportFile(File.c_str(), option);
            break;
          }
        }
        break;
      }
      case 7: {
        cout << "Veuillez rentrer le nom du fichier, avec son extension" <<endl;
        cin >> File;
        cout << "Quelle option de sauvegarde souhaitez-vous utiliser ? " << endl; 
        cout << "\t1 : Sans critère de selection" << endl;
        cout << "\t2 : Selon le type de trajet" << endl;
        cout << "\t3 : Selon la ville de départ et/ou d'arrivée" << endl;
        cout << "\t4 : Selon une sélection de trajets" << endl;
        cin >> option;
        switch (option)
        {
          case 1 : {
            catalogue.ExportFile(File.c_str(), option);
            break;
          }
          case 2 : {
            cout << "Quelle type de trajet souhaitez-vous sauvegarder ?" <<endl;
            cout << "\t1 : simple" <<endl;
            cout << "\t2 : composé" <<endl;
            cin >> optionType;
            option += 10 * optionType;
            catalogue.ExportFile(File.c_str(), option);
            break;
          }
          case 3 : {
            string VilleDepartRecherchee;
            string VilleArriveeRecherchee;
            cout <<"Veuillez choisir une des options suivante : " <<endl;
            cout <<"\t1 : Selon la ville de départ" <<endl;
            cout <<"\t2 : Selon la ville d'arrivée" <<endl;
            cout <<"\t3 : Selon la ville de départ et d'arrivée " <<endl;
            cin >> optionType;
            option += 10*optionType;
            switch(optionType)
            {
              case 1 : {
                cout << "Veuillez rentrer le nom de la ville de départ : ";
                cin >> VilleDepartRecherchee;
                catalogue.ExportFile(File.c_str(), option, VilleDepartRecherchee);
                break;
              }
              case 2 : {
                cout << "Veuillez rentrer le nom de la ville d'arrivée : ";
                cin >> VilleArriveeRecherchee;
                catalogue.ExportFile(File.c_str(), option, NULL, VilleArriveeRecherchee);
                break;
              }
              case 3 : {
                cout << "Veuillez rentrer le nom de la ville de départ : ";
                cin >> VilleDepartRecherchee;
                cout << endl << "Veuillez rentrer le nom de la ville d'arrivée : ";
                cin >> VilleArriveeRecherchee;
                catalogue.ExportFile(File.c_str(), option, VilleDepartRecherchee, VilleArriveeRecherchee);
                break;
              }
            }
            break;
          }
        }
        break;
      }
      case 8: {
        cout << "Bon voyage ! " <<endl;
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
