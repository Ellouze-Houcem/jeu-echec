#pragma once
#include "piece.h"
#include "echiquier.h"

class cavalier :public piece
{
public:
	cavalier(bool c, bool est_gauche);//est_gauche pour indiquer que la piece est a gauche ou non puisqu'il existe deux piece de mm categorie

	~cavalier();

	void afficher();

	bool mouvement_valide(echiquier& e, int x, int y);


	char categorie();

};

