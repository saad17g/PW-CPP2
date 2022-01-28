#include "FiltreIntervalle.hpp"

FiltreIntervalle::FiltreIntervalle() {
    #if defined DEBUG
    cout << "Appel au constructeur de <FiltreIntervalle>" << endl;
    #endif

    nbTrajets = 0;
}

FiltreIntervalle::~FiltreIntervalle() {
    #if defined DEBUG
    cout << "Appel au destructeur de <FiltreIntervalle>" << endl;
    #endif
}

void FiltreIntervalle::SaisieUtilisateur() {
    cout << "Début de l'intervalle : ";
    cin >> debut;

    cout << "Fin de l'intervalle : ";
    cin >> fin;
}

bool FiltreIntervalle::Valide(Trajet* trajet) {
    nbTrajets++;
    return (nbTrajets >= debut && nbTrajets <= fin);
}