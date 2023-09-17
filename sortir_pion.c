#include <stdio.h>
#include <stdlib.h>
#include "Siam.h"

void sortir_pion(char plateau[][60],char*p)
{
    int valide=0;       ///bool�en
    int l;              ///ligne
    int X;              ///colonne
    char Lettre;        ///les coordonn�es ou l on peut placer les pions
    int j=0;            ///compteur de pions
    int k;              ///coordonn�e ligne de la reserve du plateau

     for(l=3;l<39;l++)                      ///boucle qui compte les pions (�l�phant ou rhino)
    {
        for(X=2;X<30;X++)
        {
            if(plateau[l][X]==*p)
            {
                j++;
            }
        }
    }


    if(j>0)
    {
    k=j*2;

    if(*p=='E')
        {
            plateau[1+k][41]='E';       ///place les pions dans la reserve
            plateau[0][32]='R';         ///affiche en haut de la reserve le tour du joueur
            plateau[0][41]=' ';

        }
    else if(*p=='R')
        {
            plateau[1+k][32]='R';       ///place les pions dans la reserve
            plateau[0][41]='E';         ///affiche en haut de la reserve le tour du joueur
            plateau[0][32]=' ';
        }

    do          ///v�rifie si c'est une case ext�rieur et que la case ne soit pas occup�e
    {
        valide=0;

        printf("\ncoordonees Elephant (LETTRE/NOMBRE):");
        fflush(stdin);
        scanf("%c ",&Lettre);
        scanf("%d",&X);

        X=X*4+2;                ///convertion des coordon�es donn�es en ligne et colonne du plateau
        l=(Lettre-64)*2+1;

        if(l==3 && X>=6 && X<=22)
        {
            valide=1;
        }
        else if(l==11 && X>=6 && X<=22)
        {
            valide=1;
        }
        else if(l>=5 && l<=9 && X==6)
        {
            valide=1;
        }
        else if(l>=5 && l<=9 && X==22)
        {
            valide=1;
        }

        if(plateau[l][X]!=*p)
        {
            printf("\n!Les coordonnees ne sont pas bonne!\n");
        }

    }while (plateau[l][X]!=*p || valide!=1);

    plateau[l][X]=' ';
    plateau[l][X+1]=' ';

    system("CLS");                  ///raffraichis l'image
    AffPlat(plateau);
    }
    else
    {
        printf("!vous ne pouvez sortir aucun pion!\n\n");
    }
}
