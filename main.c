#include "arvoreBST.h"

int main(){
    Apontador no;
    Inicializa(&no);
    int i;
    long vetor[]={5,9,77,4,8,65,12,1,7,45,0,3,54,14,15};
    long x;
    for(i=0; i<15; i++){
        Insercao(&no, vetor[i]);
    }
    /*printf("Ordem: ");
    Percurso_Ordem(&no);
    printf("\n");
    printf("Pré-Ordem: ");
    Percurso_Pre_Ordem(&no);
    printf("\n");
    printf("Pós-Ordem: ");
    Percurso_Pos_Ordem(&no);
    printf("\n");
    printf("A altura da árvore é: %d\n", Altura_Arvore(no));
    printf("Digite o item que deseja encontrar: ");
    scanf("%ld", &x);
    Pesquisa_Binaria(no, x);*/
    Percurso_Ordem(&no);
    printf("\n");
    printf("Digite o item que deseja retirar: ");
    scanf("%ld", &x);
    Retirada_Arvore(&no, x);
    Percurso_Ordem(&no);
    printf("\n");
    return 0;
}