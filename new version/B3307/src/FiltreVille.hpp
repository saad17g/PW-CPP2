#if ! defined ( FILTREVILLE_H )
#define FILTREVILLE_H

#include "Filtre.hpp"
#include "Trajet.hpp"

class FiltreVille : public Filtre {

    public:

        // Constructeurs
        FiltreVille();

        // Destructeur
        ~FiltreVille();

        // Méthodes
        void SaisieUtilisateur();
        bool Valide(Trajet*);

    private:

        int TypeVille;
        string VilleReferenceDepart;
        string VilleReferenceArrivee;
};

#endif