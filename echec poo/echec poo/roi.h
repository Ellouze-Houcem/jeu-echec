#pragma once
#include "piece.h"
#include "echiquier.h"

class roi : public piece
{
public:
	roi(bool c);

	~roi();

	void afficher();

	bool mouvement_valide(echiquier& e, int x, int y);

	char categorie();
};

