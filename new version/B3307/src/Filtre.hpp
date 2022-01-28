#if ! defined ( FILTRE_H )
#define FILTRE_H

#include <iostream>
using namespace std;

#include "Trajet.hpp"

class Filtre {

    public:

        // Constructeurs
        Filtre();

        // Destructeur
        virtual ~Filtre();

        // Méthodes
        virtual void SaisieUtilisateur();
        virtual bool Valide(Trajet*);
};

#endif