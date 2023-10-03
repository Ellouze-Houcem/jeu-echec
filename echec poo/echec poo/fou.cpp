#include "fou.h"

fou::fou(bool c, bool est_gauche)
{
	this->x = (est_gauche == gauche) ? 3 : 6;
	this->y = (c == blanc) ? 1 : 8;
	this->couleur = c;
}

fou::~fou()
{
	
}


void fou::afficher()
{
	cout << "Fou " << ((this->couleur == blanc) ? "Blanche" : "Noire") << " de coordonnes x=" << this->x << " y= " << this->y << endl;
}



bool fou::mouvement_valide(echiquier& e, int x, int y)
{
    int x_depart = this->get_x();
    int y_depart = this->get_y();
    bool est_valide = false;
    bool my_couleur = this->get_couleur();
    if (((x - x_depart) == (y - y_depart)) || ((x - x_depart) == -(y - y_depart))) //pour deplacer au diagonale
    {
        if (((x - x_depart) > 0 )&& ((y - y_depart) > 0))//depl en haut a droite
        {
            while ((x!= x_depart) && (y != y_depart))
            {
                x_depart++;
                y_depart++;
                if (e.get_piece(x_depart, y_depart) != NULL)//si on a une piece dans cette case
                {                                           //on discute deux cas : si on est deja arriver a la
                                                            //position convenable et la piece de couleur != donc on enleve cette piece
                                                            //mais si on n'est pas deja arrivee a la position convenable ou bien la piece de mm couleur
                                                            //dans ce cas on est bloquee et rien a faire
                    if ((x_depart == x) && (y_depart == y) && e.get_piece(x, y)->get_couleur() != my_couleur)
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
                else  //s'il n'ya pas une piece
                {
                    if ((x_depart == x) && (y_depart == y)) //si on a arrivee a la case convenable le mvt est valide sinon rien a faire
                    {
                        est_valide = true;
                    }
                }
            }
        }
        else if ((x - x_depart) > 0 && (y - y_depart) < 0)//depl en bas a droite
        {
            while ((x != x_depart) && (y != y_depart))
            {
                x_depart++;
                y_depart--;
                if (e.get_piece(x_depart, y_depart) != NULL)//si on a une piece dans cette case
                {                                       //on discute deux cas : si on a deja arriver a la
                                                        //position convenable et la piece de couleur != donc on enleve cette piece
                                                        //mais si on n'a pas deja arrivee a la position convenable ou bien la piece de mm couleur
                                                        //dans ce cas on est bloquee et rien a faire
                    if ((x_depart == x) && (y_depart == y) && e.get_piece(x, y)->get_couleur() != my_couleur)
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
                else  //s'il n'ya pas une piece
                {
                    if ((x_depart == x) && (y_depart == y)) //si on a arrivee a la case convenable le mvt est valide sinon rien a faire
                    {
                        est_valide = true;
                    }
                }
            }

        }
        else if ((x - x_depart) < 0 && (y - y_depart) >0)//depl en haut a gauche
        {
            while ((x != x_depart) && (y != y_depart))
            {
                x_depart--;
                y_depart++;
                if (e.get_piece(x_depart, y_depart) != NULL)//si on a une piece dans cette case
                {                                       //on discute deux cas : si on a deja arriver a la
                                                        //position convenable et la piece de couleur != donc on enleve cette piece
                                                        //mais si on n'a pas deja arrivee a la position convenable ou bien la piece de mm couleur
                                                        //dans ce cas on est bloquee et rien a faire
                    if ((x_depart == x) && (y_depart == y) && e.get_piece(x, y)->get_couleur() != my_couleur)
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
                else  //s'il n'ya pas une piece
                {
                    if ((x_depart == x) && (y_depart == y) )//si on a arrivee a la case convenable le mvt est valide sinon rien a faire
                    {
                        est_valide = true;
                    }
                }
            }

        }
        else//depl en bas a gauche
        {
            while ((x != x_depart) && (y != y_depart))
            {
                x_depart--;
                y_depart--;
                if (e.get_piece(x_depart, y_depart) != NULL)//si on a une piece dans cette case
                {                                       //on discute deux cas : si on a deja arriver a la
                                                        //position convenable et la piece de couleur != donc on enleve cette piece
                                                        //mais si on n'a pas deja arrivee a la position convenable ou bien la piece de mm couleur
                                                        //dans ce cas on est bloquee et rien a faire
                    if ((x_depart == x) && (y_depart == y )&& e.get_piece(x, y)->get_couleur() != my_couleur)
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
                else  //s'il n'ya pas une piece
                {
                    if ((x_depart == x) && (y_depart == y)) //si on a arrivee a la case convenable le mvt est valide sinon rien a faire
                    {
                        est_valide = true;
                    }
                }
            }

        }
    }
    return est_valide;
}

char fou::categorie()
{
    return (this->couleur == blanc) ? 'F' : 'f';

}

