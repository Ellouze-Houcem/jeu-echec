#include "tour.h"


tour::tour(bool c, bool est_gauche)
{
	this->x = (est_gauche == gauche) ? 1 : 8;
	this->y = (c == blanc) ? 1 : 8;
	this->couleur = c;
}

tour::~tour()
{

}



void tour::afficher()
{
    cout << "Tour " << ((this->couleur == blanc) ? "Blanc" : "Noir") << " de coordonnes x=" << this->x << " y= " << this->y << endl;
}

bool tour::mouvement_valide(echiquier& e, int x, int y)
{
    bool est_valide = false;
    int x_depart = this->x;
    int y_depart = this->y;
    bool my_couleur = this->couleur;

    if (((x == x_depart) && ((y >= 1) && (y <= 8))) || ((y == y_depart) && ((x >= 1) && (x <= 8))))
        // sur meme colonne deplacement       //sur mm ligne deplacement
        // suivant l'axe des oordonnees        //suivant l'axe des abcisses
    {
        if ((x-x_depart) > 0)//deplacement a droite (x>this->x)
        {
            while (x != x_depart)
            {
                x_depart++;
                if (e.get_piece(x_depart, y) != NULL)//si on a une piece dans cette case
                {                                //on discute deux cas : si on a deja arriver a la
                                                 //position convenable et la piece de couleur != donc on enleve cette piece
                                                 //mais si on n'a pas deja arrivee a la position convenable ou bien la piece de mm couleur
                                                 //dans ce cas on est bloquee et rien a faire
                    if ((x == x_depart) && (e.get_piece(x_depart, y)->get_couleur() != my_couleur))
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
                else //s'il n'ya pas une piece
                {
                    if (x == x_depart)
                    {
                        est_valide = true;
                    }
                }
            }
        }
        else if ((x - x_depart) < 0)//depalcement a gauche (x<this->x)
        {
            while (x  != x_depart)
            {
                x_depart--;
                if (e.get_piece(x_depart, y) != NULL)//si on a une piece dans cette case
                {                                //on discute deux cas : si on a deja arriver a la
                                                 //position convenable et la piece de couleur != donc on enleve cette piece
                                                 //mais si on n'a pas deja arrivee a la position convenable ou bien la piece de mm couleur
                                                 //dans ce cas on est bloquee et rien a faire
                    if ((x == x_depart) && (e.get_piece(x_depart, y)->get_couleur() != my_couleur))
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
                else //s'il n'ya pas une piece
                {
                    if (x == x_depart)
                    {
                        est_valide = true;
                    }
                }
            }
        }
        else if ((y-y_depart) > 0) //deplacement vers haut (y>y_depart)
        {
            while (y != y_depart)
            {
                y_depart++;
                if (e.get_piece(x, y_depart) != NULL)//si on a une piece dans cette case
                {                                //on discute deux cas : si on a deja arriver a la
                                                 //position convenable et la piece de couleur != donc on enleve cette piece
                                                 //mais si on n'a pas deja arrivee a la position convenable ou bien la piece de mm couleur
                                                 //dans ce cas on est bloquee et rien a faire
                    if ((y == y_depart) && (e.get_piece(x, y_depart)->get_couleur() != my_couleur))
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
                else //s'il n'ya pas une piece
                {
                    if (y == y_depart)
                    {
                        est_valide = true;
                    }
                }
            }
        }
        else // deplacement vers la bas (y<y_depart)
        {
            while (y != y_depart)
            {
                y_depart--;
                if (e.get_piece(x, y_depart) != NULL)//si on a une piece dans cette case
                {                                //on discute deux cas : si on a deja arriver a la
                                                 //position convenable et la piece de couleur != donc on enleve cette piece
                                                 //mais si on n'a pas deja arrivee a la position convenable ou bien la piece de mm couleur
                                                 //dans ce cas on est bloquee et rien a faire
                    if ((y == y_depart) && (e.get_piece(x, y_depart)->get_couleur() != my_couleur))
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
                else //s'il n'ya pas une piece
                {
                    if (y == y_depart)
                    {
                        est_valide = true;
                    }
                }
            }
        }
    }
    return est_valide;
}


char tour::categorie()
{
    return (this->couleur == blanc) ? 'T' : 't';
}

