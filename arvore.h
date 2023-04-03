#include <stdio.h>
#include <stdlib.h>


typedef struct TipoNo * Apontador;

typedef struct TipoNo{
    long item;
    Apontador Esq, Dir;
} TipoNo;

void Inicializa(Apontador* no);
void Insercao(Apontador* no, long valor);
void Percurso_Ordem(Apontador* no);
void Percurso_Pre_Ordem(Apontador* no);
void Percurso_Pos_Ordem(Apontador* no);
int Altura_Arvore(Apontador no);
void Pesquisa_Binaria(Apontador no, long x);
void Retirada_Arvore(Apontador* no, long x);
void Antecessor(Apontador no, Apontador* sub_esq);