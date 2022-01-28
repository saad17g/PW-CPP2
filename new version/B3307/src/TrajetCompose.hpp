#if ! defined ( TRAJETCOMPOSE_H )
#define TRAJETCOMPOSE_H

#include <string>
#include <list>
using namespace std;

#include "Trajet.hpp"

class TrajetCompose : public Trajet
{
    public:

        // Constructeurs
        TrajetCompose();
        TrajetCompose(const TrajetCompose&);

        //Destructeur
        ~TrajetCompose();

        // Méthodes
        const string& VilleDepart() const;
        const string& VilleArrivee() const;
        void Afficher() const;
        string Exporter() const;
        Trajet* Dupliquer() const;
        string TypeTrajet() const;


        void Ajouter(Trajet*);
    
    private:

        list<Trajet*> trajets;
};

#endif
