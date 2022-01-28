#if ! defined ( FILTREINTERVALLE_H )
#define FILTREINTERVALLE_H

#include "FiltreType.hpp"
#include "Trajet.hpp"

class FiltreIntervalle : public Filtre {

    public:

        // Constructeurs
        FiltreIntervalle();

        // Destructeur
        ~FiltreIntervalle();

        // Méthodes
        void SaisieUtilisateur();
        bool Valide(Trajet*);
    
    private:

        int debut, fin;
        int nbTrajets;
};

#endif