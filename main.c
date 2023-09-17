#include <stdio.h>
#include <stdlib.h>
#include "Siam.h"


int main()
{
    system("color f0");                 ///noir sur fond blanc
    char j1[20], j2[20];                ///joueurs
    char plateau[40][60];               ///plateau de jeu
    int i=0;                            ///compteur boucle
    char p;                             ///pion (Elephant ou rhinoceros)
    int m=3;                            ///compteur de montagnes
    int l,X;                            ///compteurs boucle
    int D;

    printf("*********         **               **              *****      *****\n");
    printf("***                               ****             *** **   **  ***\n");
    printf("*********         **             ******            ***  ** **   ***\n");
    printf("      ***         **            ********           ***    *     ***\n");
    printf("*********         **           ***    ***          ***          ***\n\n");
    printf("----Bienvenu sur le jeu du SIAM----\n\n");                      ///Entrer le nom des joueurs
    printf("Veuillez rentrer le nom des joueurs\n\n");
    printf("Joueur 1: ");
    scanf("%s",j1);
    printf("\nJoueur 2: ");
    scanf("%s",j2);
    printf("\n%s vous jouerez les ELEPHANTS \n%s vous jouerez les RHINOCEROS\n\n",j1, j2);
    printf("Voulez vous un rapide recapitulatif  des regles? 0:NON 1:OUI\n");
    scanf("%d",&D);

    switch(D)                           ///les regles
    {
    case 0:
        break;

    case 1:
        printf("\nREGLES \nBUT DU JEU : sortir une montagne du plateau.\n Comment ? \n Chaque  joueur  choisit  son  animal.  Les  joueurs  joueront  a  tour  de  role. \n Au debut du jeu les animaux sont disposes a l'exterieur du plateau et les blocs de rochers au centre du plateau .\n Les elephants bleus commenceront a jouer. 5 actions sont possibles \n-     Entrer un de ses animaux sur le plateau \n-     Se deplacer sur une case libre \n-     Changer l'orientation de son animal sans changer de case \n-     Sortir un de ses animaux disposes sur une case exterieure \n-     Pousser d'autres pieces disposees sur le plateau \n\n! On ne peut pas faire entrer un pion sur la partie centrale du tabeau !\n! La puissance d'un animal vaut 1 !\n! La resistance d'une montagne vaut 0.9 !\n! La resistance d'un animal oriente face a l'animal pousseur vaut 1 !\n! Un animal oriente du meme sens que l'animal pousseur augmente la force de 1 !\n! Un animal oriente perpendiculairement a la poussee n'a pas de resistance !\n\n\n");
        system("PAUSE");
        break;

    default: printf("vous n' avez pas seletionne d'option\n\n");
    }

    Plateau(plateau);
    system("CLS");      ///rafraichis l'image
    AffPlat(plateau);

    while(m==3)
    {
        if(i%2==0)                      ///si i est divisible par 2 alors ce sont les Elephants qui jouent
        {
            p='E';
            printf("c'est au tour de %s de jouer\n\n",j1);
            menu(plateau,&p);
        }
        else                            ///si i est divisible par 2 alors ce sont les Elephants qui jouent
        {
            p='R';
            printf("c'est au tour de %s de jouer\n\n",j2);
            menu(plateau,&p);
        }
        i++;
        m=0;

    for(l=0;l<39;l++)                           ///boucle qui compte les montagnes
    {
        for(X=2;X<30;X++)
        {
            if(plateau[l][X]=='M')
            {
                m++;            ///ajoute Un s'il y a une montagne
            }
        }
    }
    }
}
