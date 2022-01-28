#include "Filtre.hpp"

Filtre::Filtre() {
    #if defined DEBUG
    cout << "Appel au constructeur de <Filtre>" << endl;
    #endif
}

Filtre::~Filtre() {
    #if defined DEBUG
    cout << "Appel au destructeur de <Filtre>" << endl;
    #endif
}

void Filtre::SaisieUtilisateur() {}
bool Filtre::Valide(Trajet*) {return true;}