#if ! defined ( TRAJETSIMPLE_H )
#define TRAJETSIMPLE_H

#include <string>
using namespace std;

#include "Trajet.hpp"

class TrajetSimple : public Trajet
{
    public:

        // Constructeurs
        TrajetSimple(const string& VilleDepart, const string& VilleArrivee, const string& MoyenTransport);
        TrajetSimple(const TrajetSimple&);

        // Destructeur
        ~TrajetSimple();

        // Méthodes
        const string& VilleDepart() const;
        const string& VilleArrivee() const;
        void Afficher() const;
        string Exporter() const;
        Trajet* Dupliquer() const;

        string TypeTrajet() const;

    private:

        string villeDepart;
        string villeArrivee;
        string moyenTransport;
};

#endif
