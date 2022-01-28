#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include "TrajetCompose.hpp"

TrajetCompose::TrajetCompose() {
    #if defined DEBUG
    cout << "Appel du constructeur de <TrajetCompose>" << endl;
    #endif
}

TrajetCompose::TrajetCompose(const TrajetCompose& trajet) {
    #if defined DEBUG
    cout << "Appel du constructeur de copie de <TrajetCompose>" << endl;
    #endif

    for (auto& trajet : trajet.trajets) {
        trajets.push_back(trajet->Dupliquer());
    }
}

TrajetCompose::~TrajetCompose() {
    #if defined DEBUG
    cout << "Appel du destructeur de <TrajetCompose>" << endl;
    #endif

    for (auto& trajet : trajets) {
        delete trajet;
    }
}

inline const string& TrajetCompose::VilleDepart() const {
    return trajets.front()->VilleDepart();
}

inline const string& TrajetCompose::VilleArrivee() const {
    return trajets.back()->VilleArrivee();
}

void TrajetCompose::Afficher() const {
    cout << "Trajet Composée: " << endl;
    for (auto& trajet : trajets) {
        cout << "\t";
        trajet->Afficher();
    }
}

string TrajetCompose::Exporter() const {
    stringstream resultat_export;

    resultat_export << "TC\n"
    << trajets.size() << "\n";

    for (auto& trajet : trajets) {
        resultat_export << trajet->Exporter();
    }

    return resultat_export.str();
}

Trajet* TrajetCompose::Dupliquer() const {
    return new TrajetCompose(*this);
}

void TrajetCompose::Ajouter(Trajet* nouveauTrajet) {

    // Vérifie que le trajet n'est pas null
    if (nouveauTrajet == NULL) return;

    // Vérifie que le trajet n'est pas déjà en liste
    for (auto& trajet : trajets) {
        if (trajet == nouveauTrajet) return;
    }

    trajets.push_back(nouveauTrajet);
}

string TrajetCompose::TypeTrajet() const {
    return "TC";
}
