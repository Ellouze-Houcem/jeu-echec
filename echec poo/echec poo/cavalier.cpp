#include "cavalier.h"

cavalier::cavalier(bool c, bool est_gauche)
{
	this->x = (est_gauche == gauche) ? 2 : 7;
	this->y = (c == blanc) ? 1 : 8;
	this->couleur = c;
}

cavalier::~cavalier()
{

}



void cavalier::afficher()
{
	cout << "Cavalier " << ((this->couleur == blanc) ? "Blanche" : "Noire") << " de coordonnes x=" << this->x << " y= " << this->y << endl;
}



bool cavalier::mouvement_valide(echiquier& e, int x, int y)
{
    bool est_valide = false;
    int x_depart = this->x;
    int y_depart = this->y;
    int ecart_x = x - x_depart;
    int ecart_y = y - y_depart;
    bool my_couleur = this->couleur;

    if (((ecart_x == 2 || ecart_x == -2) && (ecart_y == 1 || ecart_y == -1)) || ((ecart_x == 1 || ecart_x == -1) && (ecart_y == 2 || ecart_y == -2)))
        // le deplacement de cavalier toujours decrit la lettre L
        // dans toutes les directions possibles

    {
        if (e.get_piece(x, y) != NULL)//si on a une piece
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
        else  // s'il n'ya pas une piece
        {
            est_valide = true;
        }
    }
    return est_valide;
}



char cavalier::categorie()
{
    return (this->couleur == blanc) ? 'C' : 'c';
}
