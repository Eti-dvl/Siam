#ifndef SIAM_H_INCLUDED
#define SIAM_H_INCLUDED

void Plateau(char plateau[][60]);                          ///cree le plateau
void AffPlat(char plateau[][60]);                          ///affiche le plateau
void placer_pion(char plateau[][60],char*p);               ///Entrer un pion dans le plateau
void orienter_pion(char plateau[][60],char*p);             ///Changer l'orientation d'un pion
void menu(char plateau[][60],char*p);                      ///Choisir entre les 4 options
void sortir_pion(char plateau[][60],char*p);               ///Sortir un pion du plateau
void pousser_pion(char plateau[][60],char*p);              ///deplacer/pousser un pion
void color( int a , int b);

#endif // SIAM_H_INCLUDED
