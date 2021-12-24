/*************************************************************************
                           Trajet  -  Classe abstraite
                             -------------------
    début                : 15/11/2021
    copyright            : (C) 2021 par Jules DUCANGE et Saad GUESSOUS
    e-mail               : Jules.Ducange@insa-lyon.fr
                           Saad.Guessous@insa-lyon.fr
*************************************************************************/

//------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ---------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

//-------------------------------------------- Constructeurs - destructeur
Trajet::Trajet ( )
{
    #ifdef MAP
    cout << "Appel au constructeur de <Trajet>" << endl;
    #endif
} //----- Fin de Trajet

Trajet::Trajet ( const Trajet& trajet )
{
    #ifdef MAP
    cout << "Appel au constructeur de copie de <Trajet>" << endl;
    #endif
} //----- Fin de Trajet

Trajet::~Trajet ( )
{
    #ifdef MAP
    cout << "Appel au destructeur de <Trajet>" << endl;
    #endif
} //----- Fin de ~Trajet


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
