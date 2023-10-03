#include "echiquier.h"

echiquier::echiquier()
{
	for (int i = 0; i < 8;i++)
	{
		for (int j = 0; j < 8; j++)
		{
			this->plateau[i][j] = NULL;
		}
	}
}

echiquier::~echiquier()
{

}


bool echiquier::verif_coordonnee(int x, int y)
{
	if ((x >= 1) && (x <= 8) && (y >= 1) && (y <= 8)) {
		return true;
	}
	else {
		return false;
	}
}

piece* echiquier::get_piece(int x, int y)
{
	if (verif_coordonnee(x, y) == true)
	{
		return this->plateau[x - 1][y - 1];
	}
	else {
		return NULL;
	}
}


bool echiquier::placer_piece(piece* p)
{
	if (p == NULL) {
		return false;//pointeur null il n'ya pas de piece
	}
	int x = p->get_x();
	int y = p->get_y();
	if (((verif_coordonnee(x, y) == true) && (this->plateau[x - 1][y - 1] == NULL))) {
		this->plateau[x - 1][y - 1] = p;
		return true;//si les coordonnes sont valides et il n'ya pas de piece dans cette case
	}
	else {
		return false;////si les coordonnes ne sont pas valides ou bien case occupee
	}
}



bool echiquier::deplacer(piece* p, int x, int y)
{
	int x_depart = p->get_x();
	int y_depart = p->get_y();
	if (p->mouvement_valide(*this, x, y)) { //le mouvement est valide selon le deplacement de chaque piece (chaque categorie)
		enlever_piece(x_depart, y_depart);//enlever la piece de la position de depart
		p->deplacer(x, y);//changer les coordonne de la piece
		placer_piece(p);//placer la piece dans les nouveaux coordonnes
		return true;
	}
	else {
		return false;//si le mouvement est invalide
	}
}



piece* echiquier::enlever_piece(int x, int y)
{
	if ((verif_coordonnee(x, y) == true) && (this->get_piece(x, y) != NULL))//si les coordonnes sont valides et il ya une piece dans cette case
	{
		piece* p_tmp = this->plateau[x - 1][y - 1];//pointeur temporel qui recupere l'@ de la piece enlevee
		this->plateau[x - 1][y - 1] = NULL;//enlever la piece
		return p_tmp;//retourner l'@ de la piece enlevee
	}
	else {
		return NULL;//si les coordonnes sont invalides ou il n'ya pas de piece a enlevee
	}
}



void echiquier::afficher()
{
	cout << endl;
	cout << "    : 1 : 2 : 3 : 4 : 5 : 6 : 7 : 8 :   " << endl;
	cout << "---------------------------------------" << endl;
	for (int i = 8; i > 0; i--) {
		cout << ": " << i << " :";
		for (int j = 1; j <= 8; j++) {
			char c;
			piece* p = get_piece(j, i);
			if (p == NULL) {
				c = (((i + j) % 2) == 0) ? '#' : '.';//si les deux coordonnes sont impaires(somme paire) ==> case noire sinon case blanche
			}
			else {
				c = p->categorie();
			}
			cout << " " << c << " :";
		}
		cout << " " << i << " :" << endl << endl;
	}
	cout << "---------------------------------------" << endl;
	cout << "    : 1 : 2 : 3 : 4 : 5 : 6 : 7 : 8 :   " << endl;


}
