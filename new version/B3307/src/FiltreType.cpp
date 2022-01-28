#include "FiltreType.hpp"

FiltreType::FiltreType() {
    #if defined DEBUG
    cout << "Appel au constructeur de <FiltreType>" << endl;
    #endif
}

FiltreType::~FiltreType() {
    #if defined DEBUG
    cout << "Appel au destructeur de <FiltreType>" << endl;
    #endif
}

void FiltreType::SaisieUtilisateur() {
    cout << "Type de trajet :\n"
    << "\t- Trajet Simple (TS)\n"
    << "\t- Trajet Compose (TC)" << endl;

    cin >> typeTrajet;
}

bool FiltreType::Valide(Trajet* trajet) {
    return trajet->TypeTrajet() == typeTrajet;
}