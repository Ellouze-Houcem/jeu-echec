#pragma once
#include "piece.h"
#include "echiquier.h"
class fou :virtual public piece
{
public:
	fou(bool c, bool est_gauche);

	virtual ~fou();

	void afficher();

	bool mouvement_valide(echiquier& e, int x, int y);

	char categorie();
};

