#if ! defined ( TRAJET_H )
#define TRAJET_H

#include <string>
using namespace std;


class Trajet {

    public:

        // Constructeurs
        Trajet ( );
        Trajet ( const Trajet& trajet );

        // Destructeur
        virtual ~Trajet ( );

        // Méthodes
        virtual const string& VilleDepart() const = 0;
        virtual const string& VilleArrivee() const = 0;
        virtual void Afficher() const = 0;
        virtual string Exporter() const = 0;
        virtual Trajet* Dupliquer() const = 0;

        virtual string TypeTrajet() const = 0;
};

#endif
