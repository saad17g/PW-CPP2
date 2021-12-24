/*************************************************************************
                           TrajetSimple  -  Implémentation de Trajet
                             -------------------
    début                : 15/11/2021
    copyright            : (C) 2021 par Jules DUCANGE et Saad GUESSOUS
    e-mail               : Jules.Ducange@insa-lyon.fr
                           Saad.Guessous@insa-lyon.fr
*************************************************************************/

//-- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


const char* TrajetSimple::GetVilleDepart( void ) const {
   return villeDepart;
} // ----- Fin de GetVilleDepart

const char* TrajetSimple::GetVilleArrivee( void ) const {
   return villeArrivee;
} // ----- Fin de GetVilleArrivee

void TrajetSimple::Afficher( void ) const {
    cout << "Trajet de " << villeDepart << " à " << villeArrivee << " en "
        << moyenTransport << endl;
}

//-------------------------------------------- Constructeurs - destructeur

TrajetSimple::TrajetSimple ( const char* VilleDepart, 
    const char* VilleArrivee, const char* MoyenTransport)
{
    #ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
    #endif

    /* Allocation de la mémoire */
    villeDepart = new char [ strlen(VilleDepart) + 1 ];
    villeArrivee = new char [ strlen(VilleArrivee) + 1 ];
    moyenTransport = new char [ strlen(MoyenTransport) + 1 ];

    /* Copie des valeurs */
    strcpy(villeDepart, VilleDepart);
    strcpy(villeArrivee, VilleArrivee);
    strcpy(moyenTransport, MoyenTransport);
} //----- Fin de TrajetSimple

TrajetSimple::TrajetSimple ( const TrajetSimple& trajet )
{
    #ifdef MAP
    cout << "Appel au constructeur de copie de <TrajetSimple>" << endl;
    #endif

    /* Allocation de la mémoire */
    villeDepart = new char [ strlen(trajet.villeDepart) + 1 ];
    villeArrivee = new char [ strlen(trajet.villeArrivee) + 1 ];
    moyenTransport = new char [ strlen(trajet.moyenTransport) + 1 ];

    /* Copie des valeurs */
    strcpy(villeDepart, trajet.villeDepart);
    strcpy(villeArrivee, trajet.villeArrivee);
    strcpy(moyenTransport, trajet.moyenTransport);
} //----- Fin de Trajet

TrajetSimple::~TrajetSimple ( void )
{
    #ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
    #endif

    /* Libération de la mémoire */
    delete [] villeDepart;
    delete [] villeArrivee;
    delete [] moyenTransport;
} //----- Fin de ~TrajetSimple

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
