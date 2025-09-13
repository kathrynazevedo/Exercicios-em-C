#include <stdio.h>
#include <stdlib.h>

int conj[32];
int cont;

void subconjunto(int i, int n){
 int j;
 if (i>n){
  printf("%d subconjunto: ",++cont);
  for(j=1;j<=n;j++)
     if(conj[j]==1){
        printf("%d ",j);
        }
  printf("\n");
 }else{
  conj[i] = 1;
  subconjunto(i+1,n);
  conj[i] = 0;
  subconjunto(i+1,n);
 }
}

int main(){
   int n, posicao;   
   printf("\n\nO algoritmo retornara os subconjntos dos n-primeiros termos [1..n]");
   printf("\nDigite um numero Natural inteiro positivo n: ");
   scanf("%d",&n);
   cont = 0;
   subconjunto(1,n);
 
   printf("\n\n");
   system("PAUSE");  
   return EXIT_SUCCESS;    
 
   return 0;
}
