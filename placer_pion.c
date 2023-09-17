#include <stdio.h>
#include <stdlib.h>
#include "Siam.h"

void placer_pion(char plateau[][60],char*p)
{
    int valide=0;       ///valeur booléen
    int l;              ///ligne
    int X;              ///colonne
    char Lettre;        ///Ligne entrée par le joueur en lettre convertie en nombre pour la colonne
    char ori;           ///orientation du pion
    int j=0;            ///compteur de pion
    int k;              ///traduis en ligne de la reserve

    for(l=0;l<39;l++)               ///compte les elephant/rhinoceros
    {
        for(X=2;X<30;X++)
        {
            if(plateau[l][X]==*p)
            {
                j=j+1;              ///ajoute 1 pour chaque pion
            }
        }
    }
    if(j<5)             ///S'il y a un nombre de pions inférieur à 5 sur le plateau alors on peut poser un pion sur le plateau
    {
    k=j*2;
        if(*p=='E')             ///détecte si c est un elephant pour enlever un pion dans la reserve
        {
            plateau[3+k][41]=' ';
            plateau[0][32]='R';    ///affiche en haut de la reserve le tour du joueur
            plateau[0][41]=' ';
        }
        else if(*p=='R')        ///détecte si c est un rhinoceros pour enlever un pion dans la reserve
        {
            plateau[3+k][32]=' ';
            plateau[0][41]='E';
            plateau[0][32]=' ';
        }

    do                          ///blindage des coordonnées de selection
    {
        valide=0;
        if(*p=='E')         ///demande les coordonnées/Blindage
        {
            printf("\ncoordonees ELEPHANT (LETTRE/NOMBRE):");
        }
        else if(*p=='R')
        {
            printf("\ncoordonees RHINOCEROS (LETTRE/NOMBRE):");
        }
        fflush(stdin);
        scanf("%c ",&Lettre);
        scanf("%d",&X);

        X=X*4+2;
        l=(Lettre-64)*2+1;

        if(l==3 && X>=6 && X<=22)       ///les coordonnées ou l on peut placer les pions
        {
            valide=1;
        }
        else if(l==11 && X>=6 && X<=22)     ///les coordonnées ou l on peut placer les pions
        {
            valide=1;
        }
        else if(l>=5 && l<=9 && X==6)       ///les coordonnées ou l on peut placer les pions
        {
            valide=1;
        }
        else if(l>=5 && l<=9 && X==22)      ///les coordonnées ou l on peut placer les pions
        {
            valide=1;
        }
        else    ///sinon la cases n est pas disponible
        {
            printf("Cette case est deja prise ou les coordonnees ne sont pas bonne.\n");
        }

    }while (plateau[l][X]!=' ' || valide!=1);

    plateau[l][X]=*p;
    printf("\nb:bas\nh:haut\nd:droite\ng:gauche\n");            ///Selection orientation
    printf("\nOrientation:");
    fflush(stdin);
    scanf("%c",&ori);

    while(ori!='g' && ori!='d' && ori!='h' && ori!='b')             ///Blindage Orientation
    {
        printf("!Erreur!\n");
        printf("\nb:bas\nh:haut\nd:droite\ng:gauche\n");
        printf("\nOrientation:");
        fflush(stdin);
        scanf("%c",&ori);
    }
    system("CLS");
    plateau[l][X+1]=ori;

    AffPlat(plateau);
    }
    else                ///sinon il est impossible de placer un pion
    {
        printf("\n!vous avez utilise tous vos pions!\n\n");
    }
}
