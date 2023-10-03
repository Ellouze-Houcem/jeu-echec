#include "jeu.h"

jeu::jeu() 
{
    
}

jeu::~jeu()
{

}


void jeu::entrer_coordonnees(int& x, int& y)
{
    while (true)
    {
        cout << "X = ";
        cin >> x;
        cout << endl;
        cout << "Y = ";
        cin >> y;

        if (e.verif_coordonnee(x, y) == true)
        {
            break;
        }
        else
        {
            cout << " Les coordonnes sont incorrectes . Ressaissez d'autres valeurs : " << endl;
        }
    }
}


int jeu::echec()//retourner 0 si n'a pas d'echec , 1 si echec et 2 si mat.
{
    int ech = 0;
    int x_rb, x_rn, y_rb, y_rn; //les positions des rois


    for (int i = 1; i <= 8; i++) //recuperer les coordonnes des 2 rois
    {
        for (int j = 1; j <= 8; j++)
        {
            if (e.get_piece(i, j) != NULL)
            {
                if (e.get_piece(i, j)->categorie() == 'R')//si la piece est un 'R'oi blanc
                {
                    x_rb = i;
                    y_rb = j;
                }
                else if (e.get_piece(i, j)->categorie() == 'r')//si la piece est un 'R'oi noir
                {
                    x_rn = i;
                    y_rn = j;
                }
            }
        }
    }

    //verifier si la piece du joueur actuel peut se deplacer sur le roi adverse
    for (int i = 1; i <= 8; i++)
    {
        for (int j = 1; j <= 8; j++)
        {
            if (e.get_piece(i, j) != NULL)
            {
                if (joueur_actuel == blanc)
                {
                    if (e.get_piece(i, j)->get_couleur() == blanc)
                    {
                        if (e.get_piece(i, j)->mouvement_valide(e, x_rn, y_rn) == true)//deplacement vers la case du roi noir est valide
                        {
                            //echec
                            ech = 2;
                            //verifier si roi adverse peut de deplacer
                            for (int k = x_rn - 1; k <= (x_rn + 1) && k != x_rn; k++)
                            {
                                for (int l = y_rn - 1; l <= (y_rn + 1) && l != y_rn; l++)
                                {
                                    if (e.get_piece(x_rn, y_rn)->mouvement_valide(e, k, l) == true)
                                    {
                                        ech = 1;
                                    }
                                }
                            }
                        }
                    }
                }
                else if (joueur_actuel == noir)
                {
                    if (e.get_piece(i, j)->get_couleur() == noir)
                    {
                        if (e.get_piece(i, j)->mouvement_valide(e, x_rb, y_rb) == true)//deplacement vers la case du roi noir est valide
                        {
                            //echec
                            ech = 2;
                            //verifier si roi adverse peut de deplacer
                            for (int k = x_rb - 1; k <= (x_rb + 1) && k != x_rb; k++)
                            {
                                for (int l = y_rb - 1; l <= (y_rb + 1) && l != y_rb; l++)
                                {
                                    if (e.get_piece(x_rb, y_rb)->mouvement_valide(e, k, l) == true)
                                    {
                                        ech = 1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return ech;
}



void jeu::partie()
{
    bool joueur_actuel = blanc;
    bool mouvement_valide = false;
    bool game_over = false;
    int x_depart = 0;
    int y_depart = 0;
    int x_arrivee = 0;
    int y_arrivee = 0;
    int ech = 0;

    //creation des pieces

    roi rb(blanc);
    roi rn(noir);

    reine db(blanc);
    reine dn(noir);

    tour tb1(blanc, gauche);
    tour tb2(blanc, droite);
    tour tn1(noir, gauche);
    tour tn2(noir, droite);

    fou fb1(blanc, gauche);
    fou fb2(blanc, droite);
    fou fn1(noir, gauche);
    fou fn2(noir, droite);

    cavalier cb1(blanc, gauche);
    cavalier cb2(blanc, droite);
    cavalier cn1(noir, gauche);
    cavalier cn2(noir, droite);

    pion pb1(1, blanc);
    pion pn1(1, noir);
    pion pb2(2, blanc);
    pion pn2(2, noir);
    pion pb3(3, blanc);
    pion pn3(3, noir);
    pion pb4(4, blanc);
    pion pn4(4, noir);
    pion pb5(5, blanc);
    pion pn5(5, noir);
    pion pb6(6, blanc);
    pion pn6(6, noir);
    pion pb7(7, blanc);
    pion pn7(7, noir);
    pion pb8(8, blanc);
    pion pn8(8, noir);

    //placement des pieces

    //roi
    e.enlever_piece(5, 1);
    e.placer_piece(&rb);
    e.enlever_piece(5, 8);
    e.placer_piece(&rn);

    //reine
    e.enlever_piece(4, 1);
    e.placer_piece(&db);
    e.enlever_piece(4, 8);
    e.placer_piece(&dn);

    //tours
    e.enlever_piece(1, 1);
    e.placer_piece(&tb1);
    e.enlever_piece(1, 8);
    e.placer_piece(&tn1);
    e.enlever_piece(8, 1);
    e.placer_piece(&tb2);
    e.enlever_piece(8, 8);
    e.placer_piece(&tn2);

    //fou
    e.enlever_piece(3, 1);
    e.placer_piece(&fb1);
    e.enlever_piece(3, 8);
    e.placer_piece(&fn1);
    e.enlever_piece(6, 1);
    e.placer_piece(&fb2);
    e.enlever_piece(6, 8);
    e.placer_piece(&fn2);

    //cavalier
    e.enlever_piece(2, 1);
    e.placer_piece(&cb1);
    e.enlever_piece(2, 8);
    e.placer_piece(&cn1);
    e.enlever_piece(7, 1);
    e.placer_piece(&cb2);
    e.enlever_piece(7, 8);
    e.placer_piece(&cn2);

    //pions
    e.enlever_piece(1, 2);
    e.placer_piece(&pb1);
    e.enlever_piece(1, 7);
    e.placer_piece(&pn1);
    e.enlever_piece(2, 2);
    e.placer_piece(&pb2);
    e.enlever_piece(2, 7);
    e.placer_piece(&pn2);
    e.enlever_piece(3, 2);
    e.placer_piece(&pb3);
    e.enlever_piece(3, 7);
    e.placer_piece(&pn3);
    e.enlever_piece(4, 2);
    e.placer_piece(&pb4);
    e.enlever_piece(4, 7);
    e.placer_piece(&pn4);
    e.enlever_piece(5, 2);
    e.placer_piece(&pb5);
    e.enlever_piece(5, 7);
    e.placer_piece(&pn5);
    e.enlever_piece(6, 2);
    e.placer_piece(&pb6);
    e.enlever_piece(6, 7);
    e.placer_piece(&pn6);
    e.enlever_piece(7, 2);
    e.placer_piece(&pb7);
    e.enlever_piece(7, 7);
    e.placer_piece(&pn7);
    e.enlever_piece(8, 2);
    e.placer_piece(&pb8);
    e.enlever_piece(8, 7);
    e.placer_piece(&pn8);

    while (game_over == false)
    {
        mouvement_valide = false;
        ech = 0;
        e.afficher();

        if (joueur_actuel == blanc)
        {
            cout << "Le tour du joueur blanc" << endl;
        }
        else
        {
            cout << "Le tour du joueur noir" << endl;
        }

        cout << "choisissez les coordonnes de la piece a deplacer " << endl;
        entrer_coordonnees(x_depart, y_depart);

        while (mouvement_valide == false)
        {
            cout << "Choisissez les coordonnes de la case d'arrivee " << endl;
            entrer_coordonnees(x_arrivee, y_arrivee);

            if (e.get_piece(x_depart, y_depart)->mouvement_valide(e, x_arrivee, y_arrivee) == true)
            {
                mouvement_valide = true;
                e.deplacer(e.get_piece(x_depart, y_depart), x_arrivee, y_arrivee);

            }

            ech = echec();

            if (ech == 1)
            {
                cout << "Echec !!!" << endl;
            }

            else if (ech == 2)
            {
                cout << "Echec et MAT!!!!!" << endl;
                if (joueur_actuel == blanc)
                {
                    cout << "Le Blanc a gagne la partie" << endl;
                    cout << "Le Blanc a enlevee " << piece::get_static_noir() << "pieces noires" << endl;
                }
                else
                {
                    cout << "Le Noir a gagne la partie" << endl;
                    cout << "Le Noir a enlevee " << piece::get_static_blanc() << "pieces blanches" << endl;
                }
                game_over = true;
            }
            joueur_actuel = (joueur_actuel == blanc) ? noir : blanc;
        }
    }

}

