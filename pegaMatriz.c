#include <stdio.h>
#include <stdlib.h>
//#---Funcoes---#
/*-------------------------------------------*/
FILE *openSafe(char arquivo[]);
float **pegaMatriz(FILE *arquivo, int n);
float *pegaVetor(FILE *arquivo,int n);
/*-------------------------------------------*/

int main( int argc, char** argv) {
  
   FILE *arquivo;
   int n;
   float **A; 
   float *b;
   int i;
   int x,y;
  
   arquivo = openSafe(argv[1]);
   fscanf(arquivo,"%d",&n);
   A = pegaMatriz(arquivo, n);
   b = pegaVetor(arquivo, n);

  
   /*Imprime matriz Apenas teste*/
   for(x = 0; x < n; x++) {
   	   for(y = 0; y < n; y ++)
   	   	printf("%f ",A[x][y]);

       printf("\n"); 
   }
   
   printf("\n");
   for(x = 0; x < n; x++)
      printf("%f\n",b[x]);
   
   fclose(arquivo);
   return 0;
}
/*Corpo das funcoes*/

/* openSafe(char arquivo[])
Recebe um ponteiro para FILE e devolve um outro
se não houver arquivo nulo na entrada
*/
FILE *openSafe(char arquivo[]) {
    FILE * f;
    f = fopen(arquivo,"r");  
    if (f == NULL) {
   	  printf("Falha para abrir arquivo\n");
          exit(EXIT_FAILURE); 
  }
   return f;    
}
/*-------------------------------------------*/

/* pegaMatriz(FILE *arquivo, int n)
Recebe um ponteiro para FILE e devolve um ponteiro
para uma matriz nxn tipo float
*/
float **pegaMatriz(FILE *arquivo, int n) {
   int x,y;
   float **A;
   A = malloc( n * sizeof (float *));
   int i;
   for (i = 0; i < n; i++)
      A[i] = malloc( n * sizeof (float));
   
   for (i = 0; i < (n * n); i++){
      fscanf(arquivo,"%d %d",&x,&y);
      fscanf(arquivo,"%f",&A[x][y]);
   }
   return A;
}
/*-------------------------------------------*/

/* pegaVetor(FILE *arquivo,int n)
Recebe um ponteiro para tipo FILE e devolve
um vetor do tipo flaot
*/
float *pegaVetor(FILE *arquivo,int n) {
   float *b; 
   int x,i;
   b = malloc( n * sizeof (float));
   for (i = 0; i < n; i++) { 
      fscanf(arquivo,"%d",&x);
       fscanf(arquivo,"%f",&b[x]);
   }
   return b;
}
/*-------------------------------------------*/
