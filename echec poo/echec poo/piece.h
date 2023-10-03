#pragma once

#include <iostream>
#include "couleur.h"
using namespace std;

class echiquier;

class piece
{
protected:
	int x;	//abcisse
	int y;	//ordonne
	bool  couleur;	//couleur
	static int  piece_enlevee_blanche;		//conteur pour les pieces blanches eliminees 
	static int piece_enlevee_noire;			//conteur pour les pieces noires eliminees 
public:
	piece();	//constructeur par defaut

	piece(int x, int y, bool c);		//constructeur parametree

	piece(const piece& autre);			//constructeur de copie

	int get_x() const;		//return abcisse x

	int get_y() const;		//return ordonee y

	bool get_couleur() const;		//return couleur

	static int get_static_blanc() ;	//return l'attirbut piece_enlevee_blanche

	static int get_static_noir() ;	//return l'attirbut piece_enlevee_noire

	void initialiser(int x, int y, bool c);	//initialiser la piece 

	void deplacer(int x, int y);		//deplacer la piece a la case donnee en parametre (x,y)

	virtual void afficher();		//afficher les coordonnee de la piece et sa couleur

	virtual bool mouvement_valide(echiquier& e, int x, int y);	//verifier le deplacement valide ou non

	virtual char categorie();		//donner la categorie de la piece

	virtual ~piece();		//detructeur

	piece& operator = (const piece& autre);		//operateur =



};

