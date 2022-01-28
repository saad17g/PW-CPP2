#include <iostream>
#include <string>
using namespace std;

#include "Trajet.hpp"


Trajet::Trajet() {
    #if defined DEBUG
    cout << "Appel du constructeur de <Trajet>" << endl;
    #endif
}

Trajet::Trajet(const Trajet& trajet) {
    #if defined DEBUG
    cout << "Appel du constructeur de copie de <Trajet>" << endl;
    #endif
}

Trajet::~Trajet() {
    #if defined DEBUG
    cout << "Appel du destructeur de <Trajet>" << endl;
    #endif
}
