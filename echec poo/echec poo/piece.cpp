#include "piece.h"

int piece::piece_enlevee_blanche = 0;
int piece::piece_enlevee_noire = 0;



/*****************constructeur  par defaut**************/

piece::piece() :x(0), y(0), couleur(blanc)
{

}

/*****************constructeur parametree***************/

piece::piece(int x, int y, bool c)
{
	this->x = x;
	this->y = y;
	this->couleur = c;
}

/*************constructeur de recopie******************/

piece::piece(const piece& autre)
{
	this->x = autre.x;
	this->y = autre.y;
	this->couleur = autre.couleur;
}

/**************************get_x**********************/

int piece::get_x() const
{
	return x;
}

/**************************get_y**********************/

int piece::get_y() const
{
	return y;
}


/**************************get_couleur**********************/

bool piece::get_couleur() const
{
	return couleur;
}

/*************************init**************************/

void piece::initialiser(int x, int y, bool c)
{
	this->x=x;
	this->y=y;
	this->couleur = c;

}

/*************************deplacer**************************/

void piece::deplacer(int x, int y)
{
	this->x = x;
	this->y = y;

}

/*************************afficher**************************/

void piece::afficher()
{
	cout << "Piece " << ((this->couleur == blanc) ? "Blanche" : "Noire") << " de coordonnees x= " << this->x << " y= " << this->y << endl;
}

/*******************mouvement_valide*************************/

bool piece::mouvement_valide(echiquier& e, int x, int y)
{
	
	return true;
}
/************************categorie*****************************/

char piece::categorie()
{
	return (this->couleur == blanc) ? 'B' : 'n';
}

/************************destructeur****************************/
piece::~piece()
{
	
}

/***********************operateur = **********************/

piece& piece::operator=(const piece& autre)
{
	this->x = autre.x;
	this->y = autre.y;
	this->couleur = autre.couleur;

	return *this;
}


int piece::get_static_blanc() 
{
	return piece_enlevee_blanche;
}

int piece::get_static_noir() 
{
	return piece_enlevee_noire;
}