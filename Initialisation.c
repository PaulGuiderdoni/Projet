#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE 3

void Poubelle(){
  char c='0';
  while(c!='\n'){
    scanf("%c",&c);
  }
}

int** CreerGrille(int** tab, int col, int lig, int symb){

  int i,j;
  int val;
  for (i=0;i<lig;i++){
    for(j=0;j<col;j++){
      do{
        val=1;
        *(*(tab+i)+j)=rand()%symb;
        if((i==0||i==1) &&(j==0 || j==1)){
        
        }else if(i==1 ||i==0){
          if((*(*(tab+i)+j)==*(*(tab+i)+j-1))&&(*(*(tab+i)+j)==*(*(tab+i)+j-2))){//verifie si 3 symboles sont alignés en ligne vers la gauche"
            val=0;
          }
        }else if(j==1 ||j==0){
          if((*(*(tab+i)+j)==*(*(tab+i-1)+j))&&(*(*(tab+i)+j)==*(*(tab+i-2)+j))){//verifie si 3 symboles sont alignés en colonne vers le haut"
            val=0;
          }
          else if((*(*(tab+i)+j)==*(*(tab+i-1)+j+1))&&(*(*(tab+i)+j)==*(*(tab+i-2)+j+2))){//verifie si 3 symboles sont alignés en diagonale vers le haut droit"
            val=0;
          }
        }else if(j==col-1 ||j==col-2){
          if((*(*(tab+i)+j)==*(*(tab+i)+j-1))&&(*(*(tab+i)+j)==*(*(tab+i)+j-2))){//verifie si 3 symboles sont alignés en ligne vers la gauche"
            val=0;
          }else if((*(*(tab+i)+j)==*(*(tab+i-1)+j))&&(*(*(tab+i)+j)==*(*(tab+i-2)+j))){//verifie si 3 symboles sont alignés en colonne vers le haut"
            val=0;
          }else if((*(*(tab+i)+j)==*(*(tab+i-1)+j-1))&&(*(*(tab+i)+j)==*(*(tab+i-2)+j-2))){//verifie si 3 symboles sont alignés en diagonale vers le haut gauche"
            val=0;
          }
        }else{
          if((*(*(tab+i)+j)==*(*(tab+i)+j-1))&&(*(*(tab+i)+j)==*(*(tab+i)+j-2))){ //verifie si 3 symboles sont alignés en ligne vers la gauche"
            val=0;
          }else if((*(*(tab+i)+j)==*(*(tab+i-1)+j))&&(*(*(tab+i)+j)==*(*(tab+i-2)+j))){//verifie si 3 symboles sont alignés en colonne vers le haut"
            val=0;
          }else if((*(*(tab+i)+j)==*(*(tab+i-1)+j-1))&&(*(*(tab+i)+j)==*(*(tab+i-2)+j-2))){//verifie si 3 symboles sont alignés en diagonale vers le haut gauche"
            val=0;
          }else if((*(*(tab+i)+j)==*(*(tab+i-1)+j+1))&&(*(*(tab+i)+j)==*(*(tab+i-2)+j+2))){//verifie si 3 symboles sont alignés en diagonale vers le haut droit"
            val=0;
          }
          
        }
        
      }while(val==0);
    }
  }
  return tab;
}


void affichertab(int** tab, int col, int lig){
  int i,j;
  int temp;
  char c='A';
  printf("     ");
  for(i=0;i<col;i++){
  printf("%c ",c+i);
  }
  printf("\n");
  printf("     ");
  for(i=0;i<col;i++){
  printf("_ ");
  }
  printf("\n");
  
  for (i=0;i<lig;i++){
    printf("%2d | ",i+1);
    for(j=0;j<col; j++){
      temp=tab[i][j];
      
      switch (temp) {
        case 0 :
          printf("\x1B[38;2;255;0;0m"); //ROUGE
          printf("X ");
          printf("\x1B[0m");
        break;
        
        case 1 :
          printf("\x1B[38;2;0;255;0m"); //VERT
          printf("E ");
          printf("\x1B[0m");
        break;
        
        case 2 :
          printf("\x1B[38;2;0;0;255m"); //BLEU
          printf("M ");
          printf("\x1B[0m");
        break;
        
        case 3 :
          printf("\x1B[38;2;255;0;255m"); //ROSE
          printf("G ");
          printf("\x1B[0m");
        break;
        
        case 4 :
          printf("\x1B[38;2;255;255;0m"); //JAUNE
          printf("S ");
          printf("\x1B[0m");
        break;
        
        case 5 :
          printf("\x1B[38;2;0;255;255m"); //CYAN
          printf("W ");
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
  int grille[3];
  int val=0;
  int ret;
  do{
    do{
      printf("Avec combien de symboles voulez vous jouer(Ce nombre doit être entre 4 et 6 compris) ?\n");
      ret=scanf("%d",&grille[0]);
      Poubelle();
    }while((grille[0]<4 || grille[0]>6) || ret!=1);
  
    do{
      printf("Avec combien de ligne voulez vous jouer(Ce nombre doit être entre 3 et 20) ?\n");
      ret=scanf("%d",&grille[1]);
      Poubelle();
    }while((grille[1]<3 || grille[1]>20) || ret!=1);
  
    do{
      printf("Avec combien de colonne voulez vous jouer(Ce nombre doit être entre 3 et 20) ?\n");
      ret=scanf("%d",&grille[2]);
      Poubelle();
    }while((grille[2]<3 || grille[2]>20) || ret!=1);

    do{
      printf("Vous venez de choisir une grille %dx%d avec %d symboles. Tapez 1 si vous êtes sûr et 2 sinon ?\n",grille[1],grille[2],grille[0]);
      ret=scanf("%d",&val);
      Poubelle();
    }while((val!=1 && val!=2)|| ret!=1);
  }while(val==2);


    
  int **tab=NULL;
  tab=malloc(grille[1]*sizeof(int*));//création d'un tableau 2D
  int i,j;
  int temp;
  for (i=0;i<grille[1];i++){
    *(tab+i)=malloc(grille[2]*sizeof(int));
  }
  tab=CreerGrille(tab,grille[2], grille[1],grille[0]); //Ajout aléatoire des symboles
  affichertab(tab ,grille[2], grille[1]);


  int valide=grilleValide( tab,grille[2] ,grille[1]);

  if(valide==1){
    printf("la grille est bonne\n");
  }else{
    printf("la grille n'est pas valide\n");
  }
  return 0;
}
