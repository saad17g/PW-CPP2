#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

#include <list>
using namespace std;

#include "Trajet.hpp"
#include "TrajetSimple.hpp"
#include "TrajetCompose.hpp"
#include "Filtre.hpp"

class Catalogue {

    public:

        // Constructeurs
        Catalogue();
        Catalogue(const Catalogue&);

        // Destructeur
        ~Catalogue();

        // Méthodes
        void Ajouter(Trajet*);
        void Afficher() const;
        void ImporterFichier(string&, Filtre*);
        void ExporterFichier(string&, Filtre*);
        list<Trajet*> Recherche(const string& VilleDepart, const string& VilleArrive) const;

    private:

        list<Trajet*> trajets;

        TrajetSimple* importerTrajetSimple(istream&);
        TrajetCompose* importerTrajetCompose(istream&);
};

#endif
