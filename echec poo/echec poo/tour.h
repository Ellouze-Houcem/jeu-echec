#pragma once
#include "piece.h"
#include "echiquier.h"

class tour :virtual public piece
{
public:
    tour(bool c, bool est_gauche);

    ~tour();

    void afficher();

    bool mouvement_valide(echiquier& e, int x, int y);

    char categorie();
};

