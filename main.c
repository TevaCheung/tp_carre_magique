#include <stdio.h>
#include <stdlib.h>

/*
BUT : Creer un carre magique de 5 ou 7 de cote
ENTREE : -
SORTIE : Affichage du carre magique
*/

#define TAILLE 7

typedef struct casejeton{
    int ligne;
    int col;
}casejeton;

void init(int **carre);
void affiche(int **carre);

int main()
{
    int i,j;
    int **carre;
    carre=malloc(TAILLE*sizeof(int*));
    for (i=0;i<TAILLE;i++){
        carre[i]=malloc(TAILLE*sizeof(int));
    }

    casejeton jeton;

    init(carre);

    for (i=0;i<(TAILLE)*(TAILLE);i++){
        if (i==0){ //Si c'est le premier remplissage, on cherche la case au dessus du milieu...
            jeton.ligne=(TAILLE/2)-1;
            jeton.col=(TAILLE/2);
            carre[jeton.ligne][jeton.col]=i+1; //...et on y place 1
        }else{ //Si ce n'est pas le premier remplissage

            if (jeton.ligne-1<0){ //On cherche la ligne de la case adjacente en haut a droite (avec un saut si hors tableau)
                jeton.ligne=TAILLE-1;
            }else{
                jeton.ligne=jeton.ligne-1;
            }

            if (jeton.col+1==TAILLE){ //On cherche la colonne de la case adjacente en haut a droite (avec un saut si hors tableau)
                jeton.col=0;
            }else{
                jeton.col=jeton.col+1;
            }

            //la case est vide, on la remplit
            if (carre[jeton.ligne][jeton.col]==0){
                carre[jeton.ligne][jeton.col]=i+1;
            }else{
                //Sinon on cherche la premiere case en haut a gauche de libre...
                do{
                    if (jeton.ligne-1<0){ //si la val de la ligne du jeton est à l'exterieur du tableau on la repositionne
                        jeton.ligne=TAILLE-1;
                    }else{
                        jeton.ligne=jeton.ligne-1; //si la val est dans le tableau, on la garde
                    }

                    if (jeton.col-1<0){
                        jeton.col=TAILLE-1;
                    }else{
                        jeton.col=jeton.col-1;
                    }
                }while(carre[jeton.ligne][jeton.col]!=0);

                //... et on y met place la valeur
                carre[jeton.ligne][jeton.col]=i+1;

            }
        }

    }
    affiche(carre);

    free(carre);
    return 0;
}

void init(int **carre){
/*
BUT : Mettre a zero toutes les cases d'un tableau
ENTREE : Un tableau
SORTIE : Un tableau rempli par que des zéros
*/
    int i,j;

    for (i=0;i<TAILLE;i++){
        for(j=0;j<TAILLE;j++){
            carre[i][j]=0;
        }
    }
}

void affiche(int **carre){
/*
BUT : Afficher les valeurs du carre passe en parametre
ENTREE : Un tableau
SORTIE : L'affichage des valeurs du tableau

*/
    int i,j;
    for (i=0;i<TAILLE;i++){
        for(j=0;j<TAILLE;j++){
            if (carre[i][j]<10){
                printf("%d    ",carre[i][j]);
            }else{
                printf("%d   ",carre[i][j]);
            }
        }
        printf("\n");
    }
}
