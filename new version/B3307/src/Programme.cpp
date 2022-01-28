#include <iostream>
using namespace std;

#include "TrajetSimple.hpp"
#include "TrajetCompose.hpp"
#include "Catalogue.hpp"
#include "Filtre.hpp"
#include "FiltreVille.hpp"
#include "FiltreType.hpp"
#include "FiltreIntervalle.hpp"

static int Menu();

static Trajet* SaisirTrajet();
static TrajetSimple* SaisirTrajetSimple();
static TrajetCompose* SaisirTrajetCompose();

static Filtre* MenuFiltre();

int main(){

    int choix;
    Catalogue catalogue;
    string nomFichier;

    string depart, arrivee;
    Filtre* filtre;

    do {
        choix = Menu();
        switch (choix)
        {
            case 0: // Quitter le programme
                cout << "À plus tard !" << endl;
                break;

            case 1: // Afficher le catalogue
                catalogue.Afficher();
                break;
            
            case 2: // Ajouter un trajet 
                catalogue.Ajouter(SaisirTrajet());
                break;
            
            case 3: // Importer depuis un fichier
                cout << "Nom du fichier: ";
                cin >> nomFichier;

                filtre = MenuFiltre();
                catalogue.ImporterFichier(nomFichier, filtre);
                delete filtre;
                break;
            
            case 4: // Exporter vers un fichier
                cout << "Nom du fichier: ";
                cin >> nomFichier;

                filtre = MenuFiltre();
                catalogue.ExporterFichier(nomFichier, filtre);
                delete filtre;
                break;
            
            case 5: // Recherche un trajet
                cout << "Ville de départ: ";
                cin >> depart;

                cout << "Ville d'arrivée: ";
                cin >> arrivee;

                cout << "\nRésultat de la recherche: " << endl;
                for (auto& resultat : catalogue.Recherche(depart, arrivee))
                    resultat->Afficher();
                break;
        
            default:
                cout << "Commande inconnue" << endl;
                break;
        }

        cout << endl;      
    } while(choix != 0);
    return 0;
}

static int Menu() {
    cout << "Menu de sélection :"
    << "\n 1. Afficher le catalogue"
    << "\n 2. Ajouter un trajet" 
    << "\n 3. Importer depuis un fichier" 
    << "\n 4. Exporter vers un fichier" 
    << "\n 5. Rechercher"
    << "\n 0. Quitter le logiciel" 
    << endl;

    int choix;
    cin >> choix;

    return choix;
}

static TrajetSimple* SaisirTrajetSimple() {
    string depart;
    cout << "Ville de départ: ";
    cin >> depart;

    string arrivee;
    cout << "Ville d'arrivée: ";
    cin >> arrivee;

    string transport;
    cout << "Moyen de transport: ";
    cin >> transport;

    return new TrajetSimple(depart, arrivee, transport);
}

static TrajetCompose* SaisirTrajetCompose() {

    size_t nbTrajets;
    cout << "Nombre de sous trajet ? " << endl;
    cin >> nbTrajets;

    TrajetCompose* trajet = new TrajetCompose();
    for (auto i = 0; i < nbTrajets; i++) {
        trajet->Ajouter(SaisirTrajet());
    }

    return trajet;
}

static Trajet* SaisirTrajet() {

    size_t typeTrajet; // TODO: Utiliser un enum
    cout << "Type de trajet ? (1: Simple, 2: Composé) ";
    cin >> typeTrajet;

    Trajet* trajet = NULL;

    switch (typeTrajet)
    {
        case 1: // Trajet Simple
            trajet = SaisirTrajetSimple();
            break;
        
        case 2: // Trajet Composé
            trajet = SaisirTrajetCompose();
            break;

        default:
            cout << "Type non reconnu." << endl;
            break;
    }

    return trajet;
}

static Filtre* MenuFiltre() {
    int choix;

    cout << "Quelle filtre utiliser :"
    << "\n 1. Par type"
    << "\n 2. Par ville"
    << "\n 3. Par intervalle"
    << "\n 0. Aucun" 
    << endl;  

    cin >> choix;
    switch (choix)
    {
        case 1:
            return new FiltreType();
            break;

        case 2:
            return new FiltreVille();
            break;
        
        case 3:
            return new FiltreIntervalle();
            break;

        default:
            return new Filtre();
            break;
    }
}
