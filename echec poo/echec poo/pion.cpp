#include "pion.h"



pion::pion()
{

}

pion::pion(int pos, bool c)
{
	this->x = pos;
	this->y = (c == blanc) ? 2 : 7;
	this->couleur = c;

}



pion::~pion()
{
    
}


void pion::afficher()
{
    cout << "Pion " << ((this->couleur == blanc) ? "Blanc" : "Noir") << " de coordonnes x=" << this->x << " y= " << this->y << endl;
}


bool pion::mouvement_valide(echiquier& e, int x, int y)
{
    bool est_valide = false;
    bool my_couleur = this->couleur;

    if (((this->y == 2) && this->couleur == blanc ) ||            ((this->y == 7) && this->couleur == noir ))// position de depart 
        //si pion est blanche , ds la position de depart        si le pion est noir , ds la position de depart 

        // le pion peut avancer de 1 ou 2 cases
    {
        if (((x == this->x) && (y == (this->y + 2)) && my_couleur == blanc) || ((x == this->x) && (y == (this->y - 2)) && my_couleur == noir))//cas d'avancement de 2 cases
        {
            if ((my_couleur == blanc) && (e.get_piece(x, this->y + 1) == NULL) && (e.get_piece(x, this->y + 2) == NULL))//pas de piece devant le pion
            {
                est_valide = true;
            }
            else //couleur noir
            {
                if ((my_couleur == noir) && (e.get_piece(x, this->y - 1) == NULL) && (e.get_piece(x, this->y - 2) == NULL))//pas de piece devant le pion
                {
                    est_valide = true;
                }
            }
        }
        else if ((x == this->x && (y == (this->y + 1)) && my_couleur == blanc) || (x == this->x && (y == (this->y - 1)) && (my_couleur == noir)))//cas d'avancement d'une seule case
        {
            if (e.get_piece(x, y) == NULL)
            {
                est_valide = true;
            }
        }
        else if ((((x - this->x) == 1 || ((x - this->x) == -1)) && (y == (this->y + 1)) && my_couleur == blanc) || (((x - this->x) == 1 || ((x - this->x) == -1)) && (y == (this->y - 1)) && my_couleur == noir)) //cas d'attaque
        {
            if ((e.get_piece(x, y) != NULL) && (e.get_piece(x, y)->get_couleur() != my_couleur))//s'il y a une piece de couleur !=
            {
                piece* p=e.enlever_piece(x, y);
                if (p->get_couleur() == blanc)
                {
                    piece::piece_enlevee_blanche++;
                }
                else
                {
                    piece::piece_enlevee_noire++;
                }
                est_valide = true;
                
            }

        }

    }
    
    //position qq
    else if (((x == this->x) && (y == (this->y + 1)) && my_couleur == blanc) || ((x == this->x) && (y == (this->y - 1)) && my_couleur == noir)) //avancer 1 case
    {
        if (e.get_piece(x, y) == NULL)
        {
            est_valide = true;
        }
        else//attaquer
        {
            if (((((x - this->x) == 1) || ((x - this->x) == -1)) && (y == (this->y + 1)) && my_couleur == blanc) || ((((x - this->x) == 1) || ((x - this->x) == -1)) && (y == (this->y - 1)) && my_couleur == noir)) //cas d'attaque
            {
                if ((e.get_piece(x, y) != NULL )&& (e.get_piece(x, y)->get_couleur() != my_couleur))//s'il y a une piece de couleur !=
                {
                    piece* p = e.enlever_piece(x, y);
                    if (p->get_couleur() == blanc)
                    {
                        piece::piece_enlevee_blanche++;
                    }
                    else
                    {
                        piece::piece_enlevee_noire++;
                    }
                    est_valide = true;
                }
            }
        }
    }
    return est_valide;
}


char pion::categorie()
{
    return (this->couleur == blanc) ? 'P' : 'p';
}


