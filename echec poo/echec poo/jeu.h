#pragma once

#include"echiquier.h"
#include"roi.h"
#include"reine.h"
#include"fou.h"
#include"cavalier.h"
#include"tour.h"
#include"pion.h"
#include"piece.h"

class jeu
{
protected:
	echiquier e;
	bool joueur_actuel;
public:
    jeu();

    virtual ~jeu();

    void entrer_coordonnees(int& x, int& y);//recuperer les coordonnees de la piece qu'on veut l'avancer

    int echec();//retourner 0 si n'a pas d'echec , 1 si echec et 2 si mat.

    void partie();
};

