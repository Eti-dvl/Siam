#include <stdio.h>
#include <stdlib.h>
#include "Siam.h"


void pousser_pion(char plateau[][60],char*p)
{
    float score=1;          ///rapport de force
    int l;                  ///ligne
    int X;                  ///colonne
    char Lettre;            ///Lettre de la coordonnee transmise par le joueur
    int v=2;                ///multiplicateur ligne
    int w=4;                ///multiplicateur colonne
    int j=0,k,i,h;          ///compteurs boucles
    int m=0;                ///nombre de montagne
    int yb=11;              ///coordonnees maximales horizontales
    int yh=3;               ///coordonnees minimales horizontales
    int xd=22;              ///coordonnees maximales verticales
    int xg=6;               ///coordonnees minimales verticales

    printf("Entrez les coordonnees du pion que vous voulez deplacer:");
    fflush(stdin);
    scanf("%c",&Lettre);
    scanf("%d",&X);

    X=X*4+2;                                ///coordonnees donnee converties dans le plateau(colonne)
    l=(Lettre-64)*2+1;                      ///coordonnees donnee converties dans le plateau(ligne)

    while(plateau[l][X]!=*p)                ///blindage coordonee
    {
        printf("!les coordonnees sont mauvaises!\n");
        printf("Entrez les coordonnees du pion que vous voulez deplacer:");
        fflush(stdin);
        scanf("%c",&Lettre);
        scanf("%d",&X);

        X=X*4+2;
        l=(Lettre-64)*2+1;
    }

    if(plateau[l][X+1]=='b')                    ///deplacer vers le bas
    {
        if((plateau[l+2][X+1]==' '))            ///Quand la case est libre
        {
        plateau[l][X]=' ';
        plateau[l][X+1]=' ';
        plateau[l+2][X]=*p;
        plateau[l+2][X+1]='b';
        }
        else                                    ///Quand la case n est pas libre
        {
             while(plateau[l+v][X+1]!=' ')          ///tant que la case d'apres n'est pas un espace
             {
                 if (plateau[l+v][X+1]=='M')       ///Cas de la montagne
                 {
                     score=score-0.9;       /// On enlève 0,9 de force
                 }
                 else if (plateau[l+v][X+1]=='h')       ///Cas quand le pion a une direction opposée
                 {
                     score=score-1;         ///On enlève 1 de force
                 }
                 else if ((plateau[l+v][X+1]=='d')|| (plateau[l+v][X+1]=='g'))      ///cas quand le pion est orienté de profil
                 {
                     score=score+0;         ///On ne rajoute rien
                 }
                 else if ((plateau[l+v][X+1]=='b')&&(plateau[l+v-2][X+1]=='b'))       ///cas quand la direction est la meme et ca vérifie si le pion d'avant est dans la meme direction
                 {
                     score=score+1;         ///On rajoute 1 de force
                 }
                 v=v+2;         ///On ajoute une case a chaque tour
             }

            if (score>0)        ///Si la force est supérieur à 0
            {
                while(v>=2)     ///
                {
                    plateau[l+v][X]=plateau[l+v-2][X];          ///La case vide prend la valeur de la derniere et la derniere case prend la vaveur de l'avant dernier etc... pour le type de pion
                    plateau[l+v][X+1]=plateau[l+v-2][X+1];      ///pareil qu'avant mais pour l'orentation
                    v=v-2;
                }
                plateau[l][X]=' ';      ///remplace la premiere case par un espace (type)
                plateau[l][X+1]=' ';        ///remplace la premiere case par un espace (orientaion)
            }
            else if(score<=0)                   ///si la force est négative alors on ne peut pas pousser
            {
                printf("\n!vous ne pouvez pas pousser!\n");
                menu(plateau,p);
            }
        }
    }
    else if(plateau[l][X+1]=='h')               ///deplacer vers le haut, meme principe que vers le bas
    {
        if(plateau[l-2][X+1]==' ')
        {
        plateau[l][X]=' ';
        plateau[l][X+1]=' ';
        plateau[l-2][X]=*p;
        plateau[l-2][X+1]='h';
        }
        else
        {
             while(plateau[l-v][X+1]!=' ')
             {
                 if (plateau[l-v][X+1]=='M')
                 {
                     score=score-0.9;
                 }
                 else if (plateau[l-v][X+1]=='b')
                 {
                     score=score-1;
                 }
                 else if ((plateau[l-v][X+1]=='d')|| (plateau[l-v][X+1]=='g'))
                 {
                     score=score+0;
                 }
                 else if ((plateau[l-v][X+1]=='h')&&(plateau[l-v+2][X+1]=='h'))
                 {
                     score=score+1;
                 }
                 v=v+2;
             }

            if (score>0)
            {
                while(v>=2)
                {
                    plateau[l-v][X]=plateau[l-v+2][X];
                    plateau[l-v][X+1]=plateau[l-v+2][X+1];
                    v=v-2;
                }
                plateau[l][X]=' ';
                plateau[l][X+1]=' ';
            }
            else if(score<=0)               ///si la force est négative alors on ne peut pas pousser
            {
                printf("\n!vous ne pouvez pas pousser!\n");
                menu(plateau,p);
            }
        }
    }
    else if(plateau[l][X+1]=='d')               ///deplacer vers la droite
    {
        if(plateau[l][X+5]==' ')
        {
        plateau[l][X]=' ';
        plateau[l][X+1]=' ';
        plateau[l][X+4]=*p;
        plateau[l][X+5]='d';
        }
        else
        {
             while(plateau[l][X+w+1]!=' ')
             {
                 if (plateau[l][X+w+1]=='M')
                 {
                     score=score-0.9;
                 }
                 else if (plateau[l][X+w+1]=='g')
                 {
                     score=score-1;
                 }
                 else if ((plateau[l][X+w+1]=='b')|| (plateau[l][X+w+1]=='h'))
                 {
                     score=score+0;
                 }
                 else if ((plateau[l][X+w+1]=='d')&&(plateau[l][X+w-3]=='d'))
                 {
                     score=score+1;
                 }
                 w=w+4;
             }

            if (score>0)
            {
                while(w>=4)
                {
                    plateau[l][X+w]=plateau[l][X+w-4];
                    plateau[l][X+w+1]=plateau[l][X+w-3];
                    w=w-4;
                }
                plateau[l][X]=' ';
                plateau[l][X+1]=' ';
            }
            if(score<=0)
            {
                printf("\n!vous ne pouvez pas pousser!\n");
                menu(plateau,p);
            }
        }
    }
    else if(plateau[l][X+1]=='g')               ///deplacer vers la gauche
    {
        if(plateau[l][X-3]==' ')
        {
        plateau[l][X]=' ';
        plateau[l][X+1]=' ';
        plateau[l][X-4]=*p;
        plateau[l][X-3]='g';
        }
        else
        {
             while(plateau[l][X-w+1]!=' ')
             {
                 if (plateau[l][X-w+1]=='M')
                 {
                     score=score-0.9;
                 }
                 else if (plateau[l][X-w+1]=='d')
                 {
                     score=score-1;
                 }
                 else if ((plateau[l][X-w+1]=='h')|| (plateau[l][X-w+1]=='b'))
                 {
                     score=score+0;
                 }
                 else if ((plateau[l][X-w+1]=='g')&&(plateau[l][X-w+5]))
                 {
                     score=score+1;
                 }
                 w=w+4;
             }

            if (score>0)
            {
                while(w>=4)
                {
                    plateau[l][X-w]=plateau[l][X-w+4];
                    plateau[l][X-w+1]=plateau[l][X-w+5];
                    w=w-4;
                }
                plateau[l][X]=' ';
                plateau[l][X+1]=' ';
            }
            if(score<=0)        ///si la force est négative alors on ne peut pas pousser
            {
                printf("\n!vous ne pouvez pas pousser!\n");
                menu(plateau,p);
            }
        }
    }

    for(i=0;i<39;i++)                           ///remplace par des espaces quand le pion depasse du plateau(colonne)
    {
        plateau[i][3]=' ';
        plateau[i][2]=' ';
        plateau[i][27]=' ';
        plateau[i][26]=' ';
    }
    for(h=0;h<50;h++)                           ///remplace par des espaces quand le pion depasse du plateau(ligne)
    {
        plateau[1][h]=' ';
        plateau[13][h]=' ';
    }
    for(i=3;i<39;i++)                           ///boucle qui compte les pions (éléphant ou rhino)
    {
        for(h=2;h<30;h++)
        {
            if(plateau[i][h]==*p)
            {
                j++;
            }
        }
    }

    k=j*2;

    if(*p=='E')                         ///place les elephants dans la reserve
        {
            plateau[3+k][41]='E';
            plateau[13][41]=' ';
            plateau[0][32]='R';         ///affiche en haut de la reserve le tour du joueur
            plateau[0][41]=' ';
        }
    else if(*p=='R')
        {
            plateau[3+k][32]='R';
            plateau[13][32]=' ';
            plateau[0][41]='E';         ///affiche en haut de la reserve le tour du joueur
            plateau[0][32]=' ';
        }

    system("CLS");                  ///raffraichis l'image
    AffPlat(plateau);

    for(i=0;i<39;i++)                           ///boucle qui compte les montagnes
    {
        for(j=2;j<30;j++)
        {
            if(plateau[i][j]=='M')           ///s'il détecte une montagne alors on ajoute 1 au compteur
            {
                m++;
            }
        }
    }


    if (m<3)            ///Si le nombre de montagne est inferieur a 3
    {
        if(plateau[l+2][X+1]=='b')      ///Si la direction du pion déplacé est bas
        {
            while(plateau[yb][X+1]!='b')        ///on part de la case la plus proche de l extérieur vers le pion qui déplace
            {
                yb=yb-2;
            }
            if(plateau[yb][X]=='E')         ///Si le pion détecté est un éléphant alors les Elephants ont gagnés
            {
                printf("BRAVO!\nLes Elephants ont gagne!\n");
            }
            else if(plateau[yb][X]=='R')        ///sinon ce sont les rhinoceros
            {
                printf("BRAVO!\nLes Rhinoceros ont gagne!");
            }
        }
        else if(plateau[l-2][X+1]=='h')         ///Si la direction du pion déplacé est haut
        {
            while(plateau[yh][X+1]!='h')        ///on part de la case la plus proche de l extérieur vers le pion qui déplace
            {
                yh=yh+2;
            }
            if(plateau[yh][X]=='E')         ///Si le pion détecté est un éléphant alors les Elephants ont gagnés
            {
                printf("BRAVO!\nLes Elephants ont gagne!\n");
            }
            else if (plateau[yb][X]=='R')       ///sinon ce sont les rhinoceros
            {
                printf("BRAVO!\nLes Rhinoceros ont gagne!");
            }
        }
        else if(plateau[l][X+5]=='d')       ///Si la direction du pion déplacé est droite
        {
            while(plateau[l][xd+1]!='d')        ///on part de la case la plus proche de l extérieur vers le pion qui déplace
            {
                xd=xd-4;
            }
            if(plateau[l][xd]=='E')         ///Si le pion détecté est un éléphant alors les Elephants ont gagnés
            {
                printf("BRAVO!\nLes Elephants ont gagne!\n");
            }
            else if (plateau[yb][X]=='R')       ///sinon ce sont les rhinoceros
            {
                printf("BRAVO!\nLes Rhinoceros ont gagne!\n");
            }
        }
        else if(plateau[l][X-3]=='g')       ///Si la direction du pion déplacé est gauche
        {
            while(plateau[l][xg+1]!='g')        ///on part de la case la plus proche de l extérieur vers le pion qui déplace
            {
                xg=xg+4;
            }
            if(plateau[l][xg]=='E')         ///Si le pion détecté est un éléphant alors les Elephants ont gagnés
            {
                printf("BRAVO!\nLes Elephants ont gagne!\n");
            }
            else if(plateau[yb][X]=='R')        ///sinon ce sont les rhinoceros
            {
                printf("BRAVO!\nLes Rhinoceros ont gagne!\n");
            }
        }
    }
}
