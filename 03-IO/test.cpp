#include "Trajet.h"
#include "TrajetSimple.h"

#include <iostream>
#include <fstream>

int main() {

    ofstream fichier;
    fichier.open("test.txt");

    TrajetSimple trajetSimple = TrajetSimple("Lyon", "Paris", "TGV");
    Trajet* pT = &trajetSimple;
    *pT >> fichier;

    // TrajetCompose trajetCompose = TrajetCompose();
    // trajetCompose.AjouterTrajet(new TrajetSimple("Marseille", "Paris", "Voiture"));
    // trajetCompose.AjouterTrajet(new TrajetSimple("Paris", "Lyon", "Voiture"));
    // fichier << trajetCompose;

    fichier.close();
}