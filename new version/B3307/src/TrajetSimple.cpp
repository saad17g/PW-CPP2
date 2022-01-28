#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include "TrajetSimple.hpp"

TrajetSimple::TrajetSimple(const string& depart, const string& arrivee, const string& transport) {
    #if defined DEBUG
    cout << "Appel du constructeur de <TrajetSimple>" << endl;
    #endif

    villeDepart = depart;
    villeArrivee = arrivee;
    moyenTransport = transport;
}

TrajetSimple::TrajetSimple(const TrajetSimple& trajet) {
    #if defined DEBUG
    cout << "Appel du constructeur de copie de <TrajetSimple>" << endl;
    #endif

    villeDepart = trajet.villeDepart;
    villeArrivee = trajet.villeArrivee;
    moyenTransport = trajet.moyenTransport;
}

TrajetSimple::~TrajetSimple() {
    #if defined DEBUG
    cout << "Appel du destructeur de <TrajetSimple>" << endl;
    #endif
}

inline const string& TrajetSimple::VilleDepart() const {
    return villeDepart;
}

inline const string& TrajetSimple::VilleArrivee() const {
    return villeArrivee;
}

void TrajetSimple::Afficher() const {
    cout << "Trajet de " << villeDepart << " à " << villeArrivee << 
    " en " << moyenTransport << endl;
}

string TrajetSimple::Exporter() const {
    stringstream resultat_export;
    resultat_export << "TS\n"
    << villeDepart << "\n"
    << villeArrivee << "\n" 
    << moyenTransport << "\n";

    return resultat_export.str();
}

Trajet* TrajetSimple::Dupliquer() const {
    return new TrajetSimple(*this);
}

string TrajetSimple::TypeTrajet() const {
    return "TS";
}
