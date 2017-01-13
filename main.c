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

void init(int **carre, casejeton* jeton);
void affiche(int **carre);
int caseremplie(int **carre,casejeton jeton);
void coordjeton(casejeton* jeton);
void case_hd(casejeton* jeton);
int case_hg(int** carre, casejeton* jeton);
void remplircase(int **carre,casejeton *jeton,int i);

int main()
{
    int i,j;
    int **carre;
    carre=malloc(TAILLE*sizeof(int*));
    for (i=0;i<TAILLE;i++){
        carre[i]=malloc(TAILLE*sizeof(int));
    }

    casejeton jeton;
    casejeton *pjeton=&jeton;

    init(carre,pjeton);

    for (i=0;i<(TAILLE)*(TAILLE);i++){
        if (i==0){ //Si c'est le premier remplissage, on cherche la case au dessus du milieu...
            remplircase(carre,pjeton,i); //...et on y place 1
        }else{ //Si ce n'est pas le premier remplissage...
            case_hd(pjeton);

            //la case est vide, on la remplit
            if (casevide(carre,pjeton)){
                remplircase(carre,pjeton,i);
            }else{
                //Sinon on cherche la premiere case en haut a gauche de libre...
                case_hg(carre,pjeton);
                //... et on y met place la valeur
                remplircase(carre,pjeton,i);
            }
        }
    }
    affiche(carre);

    free(carre);
    free(pjeton);
    return 0;
}

void init(int **carre, casejeton* jeton){
/*
BUT : Mettre a zero toutes les cases d'un tableau, place au bon endroit le jeton
ENTREE : Un tableau, le jeton
SORTIE : Un tableau rempli par que des zéros et le jeton avec les coordonnes de la case en haut du milieu
*/
    int i,j;

    for (i=0;i<TAILLE;i++){
        for(j=0;j<TAILLE;j++){
            carre[i][j]=0;
        }
    }

    jeton->ligne=(TAILLE/2)-1;
    jeton->col=(TAILLE/2);
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



int casevide(int **carre,casejeton* jeton){
/*
BUT : Dit si une case est déjà remplie ou non
ENTREE : Le carré, les coordonnees actuelles du jeton
SORTIE : Renvoie 1 si la case est vide, 0 sinon
*/
    if (carre[jeton->ligne][jeton->col]==0){
        return 1;
    }else{
        return 0;
    }

}

int case_hg(int** carre, casejeton* jeton){
/*
BUT : Permet d'avoir les bonnes coordonnees de la case en haut a gauche
ENTREE : Les coordonnees du jeton avant son deplacement
SORTIE : Les coordonnees du jeton apres son deplacement
*/
    do{
        if (jeton->ligne-1<0){ //si la val de la ligne du jeton est à l'exterieur du tableau on la repositionne
            jeton->ligne=TAILLE-1;
        }else{
            jeton->ligne=jeton->ligne-1; //si la val est dans le tableau, on la garde
        }

        if (jeton->col-1<0){
            jeton->col=TAILLE-1;
        }else{
            jeton->col=jeton->col-1;
        }
    }while(carre[jeton->ligne][jeton->col]!=0);
}

void case_hd(casejeton* jeton){
/*
BUT : Permet d'avoir les bonnes coordonnees de la case en haut a droite
ENTREE : Les coordonnees du jeton avant son deplacement
SORTIE : Les coordonnees du jeton apres son deplacement
*/
    if (jeton->ligne-1<0){ //On cherche la ligne de la case adjacente en haut a droite (avec un saut si hors tableau)
        jeton->ligne=TAILLE-1;
    }else{
        jeton->ligne=jeton->ligne-1;
    }

    if (jeton->col+1==TAILLE){ //On cherche la colonne de la case adjacente en haut a droite (avec un saut si hors tableau)
        jeton->col=0;
    }else{
        jeton->col=jeton->col+1;
    }
}

void remplircase(int **carre,casejeton *jeton,int i){
/*
BUT : Remplir la case d un tableau avec le bon nombre
ENTREE : Le tableau, la case actuelle
SORTIE : La case remplie

*/
    carre[jeton->ligne][jeton->col]=i+1;
}
