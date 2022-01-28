#if ! defined ( FILTRETYPE_H )
#define FILTRETYPE_H

#include "Filtre.hpp"
#include "Trajet.hpp"

class FiltreType : public Filtre {

    public:

        // Constructeur
        FiltreType();

        // Destructeur
        ~FiltreType();

        // Méthodes
        void SaisieUtilisateur();
        bool Valide(Trajet*);
    
    private:

        string typeTrajet;
};

#endif