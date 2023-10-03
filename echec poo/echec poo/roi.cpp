#include "roi.h"

roi::roi(bool c)
{
	this->x = 5;
	this->y = (c == blanc) ? 1 : 8;
	this->couleur = c;
}

roi::~roi()
{

}


void roi::afficher()
{
    cout << "Roi " << ((this->couleur == blanc) ? "Blanc" : "Noir") << " de coordonnes x=" << this->x << " y= " << this->y << endl;
}

bool roi::mouvement_valide(echiquier& e, int x, int y)
{
    bool est_valide = false;
    int x_depart = this->x;
    int y_depart = this->y;
    int ecart_x = x - x_depart;
    int ecart_y = y - y_depart;
    bool my_couleur = this->couleur;

    if ((((ecart_x <= 1) && (ecart_x >= -1))) && ((ecart_y <= 1 )&& (ecart_y >= -1)))//car il peut deplacer que d'une seule case
          //    -1 ou 1 ou 0                                                 //dans toutes les directions
    {
        if (e.get_piece(x, y) != NULL)//si on a une piece dans cette case
        {
            if (e.get_piece(x, y)->get_couleur() != my_couleur)//de couleur !=
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
        else // si il n'existe pas une piece dans cette case
        {
            est_valide = true;
        }

    }

    return est_valide;
}


char roi::categorie()
{
    return (this->couleur == blanc) ? 'R' : 'r';
}



