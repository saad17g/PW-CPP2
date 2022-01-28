#include "FiltreVille.hpp"

FiltreVille::FiltreVille() {
    #if defined DEBUG
    cout << "Appel au constructeur de <FiltreVille>" << endl;
    #endif
}

FiltreVille::~FiltreVille() {
    #if defined DEBUG
    cout << "Appel au destructeur de <FiltreVille>" << endl;
    #endif
}

void FiltreVille::SaisieUtilisateur() {
    cout << "Filtrer sur :\n"
    << "\t- Ville de départ (0)\n"
    << "\t- Ville d'arrivée (1)\n"
    << "\t- Ville de départ et d'arrivée (2)" << endl;

    cin >> TypeVille;
    switch(TypeVille)
    {
        case 0 : {
            cout << "Nom de la ville de départ : ";
            cin >> VilleReferenceDepart;
            break;
        }
        case 1 : {
            cout << "Nom de la ville d'arrivée : ";
            cin >> VilleReferenceArrivee;
            break;
        }
        case 2 : {
            cout << "Nom de la ville de départ : ";
            cin >> VilleReferenceDepart;
            cout << "Nom de la ville d'arrivée : ";
            cin >> VilleReferenceArrivee;
            break;
        }
    }
}

bool FiltreVille::Valide(Trajet* trajet) {
    if (TypeVille == 0) {
        return VilleReferenceDepart == trajet->VilleDepart();
    } else if(TypeVille == 1) {
        return VilleReferenceArrivee == trajet->VilleArrivee();
    } else {
        return VilleReferenceDepart == trajet->VilleDepart() && VilleReferenceArrivee == trajet->VilleArrivee();
    }
}
