#include <stdio.h>
#include <stdlib.h>
#include "siam.h"

void AffPlat(char plateau[][60])
{
    int l;      ///compteur ligne qui parcour le plateau
    int c;      ///compteur colonne qui parcour le plateau

    for (l=0;l<15;l++)                      ///boucle pour afficher le tableau
    {
        for (c=1;c<59;c++)
        {
            if ((plateau[l][c]=='b')||(plateau[l][c]=='h')||(plateau[l][c]=='g')||(plateau[l][c]=='d'))    ///colore en vert les directions
            {
                color(15,10);
            }
            else if(((plateau[l][c]=='E')&&(plateau[l][c+2]=='|'))||((plateau[l][c]=='E')&&(plateau[l][c+3]=='|')))  ///colore en bleu les elephants
            {
                color(15,1);
            }
            else if(((plateau[l][c]=='R')&&(plateau[l][c+2]=='|'))||((plateau[l][c]=='R')&&(plateau[l][c+3]=='|')))     ///colore en rouge les rhinoceros
            {
                color(15,4);
            }
            else if((plateau[l+11][c+2]=='|')&&(plateau[l][c]=='E')) ///colore en jaune l'affichage de tours  E
            {
                color(15,6);
            }
            else if((plateau[l+11][c+2]=='|')&&(plateau[l][c]=='R'))   ///colore en jaune l'affichage de tours  R
            {
                color(15,6);
            }
            else                           ///colore le reste en noir
            {
                color(15,0);
            }
            printf("%c",plateau[l][c]);
        }
        printf("\n");
    }
}
