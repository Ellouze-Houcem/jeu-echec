#pragma once
#include "fou.h"
#include "tour.h"

class reine : public fou , public tour
{
public:
    reine(bool c);

    ~reine();

    void afficher();

    bool mouvement_valide(echiquier& e, int x, int y);

    char categorie();
};

