#include <stdio.h>
#include <stdlib.h>
#include "Siam.h"

void menu(char plateau[][60],char*p)
{
    int choix=0;        ///choix de l'action
    int V=0;            ///Compteur de pion
    int l;              /// compteur pour parcourir le tableau
    int c;              /// compteur pour parcourir le tableau



    for (l=0;l<15;l++)
    {
        for (c=3;c<23;c++)
        {
            if(plateau[l][c]==*p)
            {
                V++;
            }                                                                                                                                                                                            ///second tour
            else if (plateau[l][c]==*p)
            {
                V++;
            }
        }
    }
    if (V==0)
        {
            printf("Veuillez placer un pion:\n");
            placer_pion(plateau,p);
        }
    if (V>=1)
    {

        printf("=== Menu ===\n\n");                                      ///Affiche les differentes possibilitées
        printf("1. Entrer un de ses animaux sur le plateau \n");
        printf("2. Se deplacer/pousser pion\n");
        printf("3. Changer d'orientation\n");
        printf("4. Sortir un de ses animaux\n");
        printf("\nVotre choix ? ");
        scanf("%d",&choix);

        switch(choix)                                                   ///Appel des fonctions
        {
        case 1:
            placer_pion(plateau,p);
            break;
        case 2:
            pousser_pion(plateau,p);
            break;
        case 3:
            orienter_pion(plateau,p);
            break;
        case 4:
            sortir_pion(plateau,p);
            break;
        }
    }
}
