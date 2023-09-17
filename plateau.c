#include <stdio.h>
#include <stdlib.h>

void Plateau(char plateau[][60])
{
    int c;                                ///colonne
    int l;                                ///ligne
    char coo='A';                         ///coordonnées lettres de A a E
    char co2='1';                         ///coordonnées  chifres de 1 a 5
    char mtg1, mtg2, mtg3;                ///les montagnes
    mtg1='M';
    mtg2='M';
    mtg3='M';

    for (l=0;l<39;l++)              ///boucle initialisation du tableau
    {
        for (c=0;c<59;c++)
        {
            plateau[l][c]=' ';
        }
    }
    for (c=7;c<26;c=c+4)            ///coordonnées de A à E
    {
        plateau[0][c]=co2;
        co2=co2+1;
    }

    for (l=3;l<13;l=l+2)             ///les coordonnées en lettre
    {
        plateau[l][1]=coo;
        coo=coo+1;
    }

    for (l=2;l<13;l=l+2)             ///boucle pour les tiret
    {
        for (c=5;c<26;c++)
        {
            plateau[l][c]=196;
        }
    }
    for (l=3;l<13;l=l+2)             ///boucle pour les colonnes
    {
        for (c=5;c<26;c=c+4)
        {
            plateau[l][c]='|';
        }
    }
     for(l=3;l<13;l=l+2)        ///Les Rhinoceros de la reserve
    {
        plateau[l][32]='R';
    }

    for (l=3;l<13;l=l+2)             ///boucle pour les colonnes
    {
        for (c=30;c<35;c=c+4)
        {
            plateau[l][c]='|';
        }
    }
     for (l=2;l<13;l=l+2)             ///boucle pour les tiret
    {
        for (c=30;c<35;c++)
        {
            plateau[l][c]=196;
        }
    }
       for(l=3;l<13;l=l+2)          ///Les Elephants de la réserve
    {
        plateau[l][41]='E';
    }

    for (l=3;l<13;l=l+2)             ///boucle pour les colonnes
    {
        for (c=39;c<44;c=c+4)
        {
            plateau[l][c]='|';
        }
    }
     for (l=2;l<13;l=l+2)             ///boucle pour les tiret
    {
        for (c=39;c<44;c++)
        {
            plateau[l][c]=196;
        }
    }
     for (l=4;l<11;l=l+2)             ///boucle pour les colonnes
    {
            plateau[l][5]=195;
            plateau[l][30]=195;
            plateau[l][39]=195;
    }
     for (l=4;l<11;l=l+2)             ///boucle pour les colonnes
    {
        plateau[l][25]=180;
        plateau[l][34]=180;
        plateau[l][43]=180;
    }

    for(c=9;c<23;c=c+4)             ///
    {
        plateau[2][c]=194;
        plateau[12][c]=193;
    }

    for(l=4;l<11;l=l+2)             ///les croix dans le plateau
    {
        for(c=9;c<23;c=c+4)
        {
            plateau[l][c]=197;
        }
    }

    plateau[2][5]=218;          ///Coins
    plateau[2][30]=218;
    plateau[2][39]=218;

    plateau[2][25]=191;         ///Coins
    plateau[2][34]=191;
    plateau[2][43]=191;

    plateau[12][5]=192;         ///Coins
    plateau[12][30]=192;
    plateau[12][39]=192;

    plateau[12][25]=217;        ///Coins
    plateau[12][34]=217;
    plateau[12][43]=217;

    plateau[5][15]=mtg1;         ///affichage des montagnes
    plateau[7][15]=mtg2;
    plateau[9][15]=mtg3;

    plateau[0][41]='E';
}
