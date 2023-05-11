#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE 10

void affichertab(int** tab, int col, int lig){
  int i,j;
  int temp;
  printf("     A B C D E F G H I J \n");
  printf("     _ _ _ _ _ _ _ _ _ _ \n");
  for (i=0;i<lig;i++){
    printf("%2d | ",i+1);
    for(j=0;j<col; j++){
      temp=tab[i][j];
      
      switch (temp) {
        case 0 :
          printf("\x1B[38;2;255;0;0m");
          printf("X ");
          printf("\x1B[0m");
        break;
        
        case 1 :
          printf("\x1B[38;2;0;255;0m");
          printf("E ");
          printf("\x1B[0m");
        break;
        
        case 2 :
          printf("\x1B[38;2;0;0;255m");
          printf("M ");
          printf("\x1B[0m");
        break;
        
        case 3 :
          printf("\x1B[38;2;255;0;255m");
          printf("G ");
          printf("\x1B[0m");
        break;
        
        case 4 :
          printf("\x1B[38;2;255;255;0m");
          printf("S ");
          printf("\x1B[0m");
        break;
      
      }
    }
    printf("\n");
  }
}


int grilleValide(int** tab, int col, int lig){
  int val=1;
  int i,j;

  for (i=0;i<lig-1;i++){
    for(j=0;j<col-1;j++){
      if (i==0){
        if(j!=0 && j!=col-1){
          if(tab[i][j]==tab[i][j-1]){
            if(tab[i][j]==tab[i][j+1]){
              val=0;
            }
          }
        }
      }
      else if(j==0){
        if(tab[i][j]==tab[i-1][j]){
          if(tab[i][j]==tab[i+1][j]){
            val=0;
          }
        }
      }
      else {
        if(tab[i][j]==tab[i-1][j]){
          if(tab[i][j]==tab[i+1][j]){
            val=0;
          }
        }
        if(tab[i][j]==tab[i][j-1]){
          if(tab[i][j]==tab[i][j+1]){
            val=0;
          }
        }
        if(tab[i][j]==tab[i-1][j-1]){
          if(tab[i][j]==tab[i+1][j+1]){
            val=0;
          }
        }
        if(tab[i][j]==tab[i-1][j+1]){
          if(tab[i][j]==tab[i+1][j-1]){
            val=0;
          }
        }
      }
    }
  }
  return val;
}


int main(void) {
  srand(time(NULL));
  
  int **tab=NULL;
  tab=malloc(TAILLE*sizeof(int*));
  int i,j;
  int temp;
  for (i=0;i<TAILLE;i++){
    *(tab+i)=malloc(TAILLE*sizeof(int));
    for(j=0;j<TAILLE;j++){
      *(*(tab+i)+j)=rand()%5;
      
    }
  }
  affichertab(tab ,TAILLE, TAILLE);


  int valide=grilleValide( tab,TAILLE ,TAILLE);

  if(valide==1){
    printf("la grille est bonne\n");
  }else{
    printf("la grille n'est pas valide\n");
  }
  return 0;
}