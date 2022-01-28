#include <iostream>
#include <list>
#include <fstream>
#include <string>
using namespace std;

#include "Catalogue.hpp"
#include "TrajetSimple.hpp"
#include "TrajetCompose.hpp"
#include "Filtre.hpp"

Catalogue::Catalogue() {
    #if defined DEBUG
    cout << "Appel du constructeur de <Catalgue>" << endl;
    #endif
}

Catalogue::Catalogue(const Catalogue& catalogue) {
    #if defined DEBUG
    cout << "Appel du constructeur de copie de <Catalgue>" << endl;
    #endif

    for (auto& trajet : catalogue.trajets) {
        trajets.push_back(trajet->Dupliquer());
    }
}

Catalogue::~Catalogue() {
    #if defined DEBUG
    cout << "Appel du destructeur de <Catalogue>" << endl;
    #endif

    for (auto& trajet : trajets) {
        delete trajet;
    }
}

void Catalogue::Ajouter(Trajet* nouveauTrajet) {

    // Vérifie que le trajet n'est pas null
    if (nouveauTrajet == NULL) return;

    // Vérifie que le trajet n'est pas déjà en liste
    for (auto& trajet : trajets) {
        if (trajet == nouveauTrajet) return;
    }

    trajets.push_back(nouveauTrajet);
}

void Catalogue::Afficher() const {

    cout << "Catalogue courant : " << endl;
    for (auto& trajet : trajets) {
        trajet->Afficher();
    }
    cout << endl;
}

void Catalogue::ImporterFichier(string& nomFichier, Filtre* filtre) {
    ifstream fichier(nomFichier);
    string typeTrajet;
    Trajet* tmp = nullptr;

    filtre->SaisieUtilisateur();

    // Vérifie que le fichier est accessible
    if (!fichier) {
        cout << "Une erreur s'est produite à l'ouverture du fichier." << endl;
        return;
    }

    while(!fichier.eof()){

        getline(fichier, typeTrajet);
        if (typeTrajet == "TS") {
            tmp = importerTrajetSimple(fichier);
        } else if (typeTrajet == "TC") {
            tmp = importerTrajetCompose(fichier);
        } else {
            continue;
        }

        if (filtre->Valide(tmp)) {
            Ajouter(tmp);
        } else {
            delete tmp;
        }
    }

    fichier.close();
}

TrajetSimple* Catalogue::importerTrajetSimple(istream& fichier) {
    string depart;
    getline(fichier, depart);

    string arrivee;
    getline(fichier, arrivee);

    string transport;
    getline(fichier, transport);

    return new TrajetSimple(depart, arrivee, transport);
}

TrajetCompose* Catalogue::importerTrajetCompose(istream& fichier) {
    int nbTrajets;
    string typeTrajet;

    fichier >> nbTrajets;
    getline(fichier, typeTrajet); // Passe à une nouvelle ligne

    TrajetCompose* trajet = new TrajetCompose();
    for (auto i = 0; i < nbTrajets; i++) {

        getline(fichier, typeTrajet);
        if (typeTrajet == "TS") {
            trajet->Ajouter(importerTrajetSimple(fichier));
        } else if (typeTrajet == "TC") {
            trajet->Ajouter(importerTrajetCompose(fichier));
        }
    }
    return trajet;
}

void Catalogue::ExporterFichier(string& nomFichier, Filtre* filtre) {
    ofstream fichier(nomFichier);
    filtre->SaisieUtilisateur();

    for (auto& trajet : trajets) {

        if (filtre->Valide(trajet))
            fichier << trajet->Exporter();
    }
    fichier.close();
}


list<Trajet*> Catalogue::Recherche(const string& VilleDepart, const string& VilleArrivee) const {

    list<Trajet*> resultats;
    for (auto& trajet : trajets) {

        if (trajet->VilleDepart() == VilleDepart && trajet->VilleArrivee() == VilleArrivee)
            resultats.push_back(trajet);
    }

    return resultats;
}
