#include <stdio.h>
#include <stdlib.h>
#include "Siam.h"

void orienter_pion(char plateau[][60],char*p)
{
    int l;          ///Ligne entrée par le joueur
    int X;          ///colonne du plateau
    char Lettre;    ///Ligne entrée par le joueur en lettre convertie en nombre pour la colonne
    char ori;       ///orientation du pion

    printf("Entrez les coordonnees du pion que vous voulez orienter:");     ///Lis les coordonées
    fflush(stdin);
    scanf("%c",&Lettre);
    scanf("%d",&X);

    X=X*4+2;
    l=(Lettre-64)*2+1;

    while(plateau[l][X]!=*p)                                  ///Blindage selection du pion
    {
        printf("les coordonnees sont mauvaises\n");
        printf("Entrez les coordonnees du pion que vous voulez orienter:");
        fflush(stdin);
        scanf("%c",&Lettre);
        scanf("%d",&X);

        X=X*4+2;            ///convertie les coordonnées
        l=(Lettre-64)*2+1;
    }

    printf("\nb:bas\nh:haut\nd:droite\ng:gauche\n");                ///Orientation
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
     if(*p=='E')                        ///Affichage tour Elephant
        {
            plateau[0][32]='R';
            plateau[0][41]=' ';
        }
    else if(*p=='R')                    ///Affichage tour Rhinoceros
        {
            plateau[0][41]='E';
            plateau[0][32]=' ';
        }

    plateau[l][X+1]=ori;
    system("CLS");                  ///raffraichis l'image
    AffPlat(plateau);

}
