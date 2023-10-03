#include "reine.h"

reine::reine(bool c) :fou(c, gauche), tour(c, gauche)
{
	this->x = 4;
	this->y = (c == blanc) ? 1 : 8;
	this->couleur = c;
}


reine::~reine()
{
    
}

void reine::afficher()
{
    cout << "Reine " << ((this->couleur == blanc) ? "Blanche" : "Noire") << " de coordonnes x=" << this->x << " y= " << this->y << endl;
}


bool reine::mouvement_valide(echiquier& e, int x, int y)
{
    bool est_valide = false;

    if (tour::mouvement_valide(e, x, y) || fou::mouvement_valide(e, x, y))
    {
        est_valide = true;
    }
    return est_valide;
}


char reine::categorie()
{
    return (this->couleur == blanc) ? 'D' : 'd';
}



