#pragma once
#include "piece.h"
#include "echiquier.h"

class pion : public piece
{
	
public:
	pion();
	
	pion(int pos, bool c);

	~pion();

	void afficher();

	bool mouvement_valide(echiquier& e, int x, int y);

	char categorie();
};

