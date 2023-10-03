#pragma once

#include "piece.h"

class echiquier
{
protected:
	piece* plateau[8][8];	//matrice qui presente l'echiquier

public:
	echiquier();	//contructeur par defaut && initilaisation du plateau

	virtual ~echiquier();	//destructeur

	bool verif_coordonnee(int x, int y);	//verifier les coordonne donnee en param

	piece* get_piece(int x, int y);		//return le pointeur sur la piece de la case (x,y) , null s'il n'ya pas unr piece

	bool placer_piece(piece* p);		//return true si le placement est valide , false sinon

	bool deplacer(piece* p, int x, int y);//return true si on a bien deplacer la piece p dans la case de coor. x,y ,,false sinon

	piece* enlever_piece(int x, int y);//return NULL s'il n'existe pas une  piece dans la case (x,y) sinon le pointeur de la piece enlevee

	void afficher();//afficher le plateau de l'echiquier
};

