#include "arvore.h"

void Inicializa(Apontador* no){
    *no = NULL;
}

void Insercao(Apontador* no, long valor){
    if(*no == NULL){
        *no = (Apontador)malloc(sizeof(TipoNo));
        (*no)->item = valor;
        (*no)->Dir = NULL;
        (*no)->Esq = NULL;
        return; 
    }
    else{
        if(valor <= (*no)->item){
            Insercao(&(*no)->Esq, valor);
        }
        else if(valor > (*no)->item){
            Insercao(&(*no)->Dir, valor);
        }
    }
}

void Percurso_Ordem(Apontador* no){
    if(*no != NULL){
        Percurso_Ordem(&(*no)->Esq);
        printf("%ld ", (*no)->item);
        Percurso_Ordem(&(*no)->Dir);
    }
}

void Percurso_Pre_Ordem(Apontador* no){
    if(*no != NULL){
        printf("%ld ", (*no)->item);
        Percurso_Pre_Ordem(&(*no)->Esq);
        Percurso_Pre_Ordem(&(*no)->Dir);
    }
}

void Percurso_Pos_Ordem(Apontador* no){
    if(*no != NULL){
        Percurso_Pos_Ordem(&(*no)->Esq);
        Percurso_Pos_Ordem(&(*no)->Dir);
        printf("%ld ", (*no)->item);
    }
}

int Altura_Arvore(Apontador no){
    if(no == NULL) return -1;
    else{
        int he = Altura_Arvore(no->Esq);
        int hd = Altura_Arvore(no->Dir);
        if(he < hd) return hd +1;
        else return he +1;
    }
}

void Pesquisa_Binaria(Apontador no, long x){
    if(no == NULL) printf("Item não encontrado\n");
    else if(x < no->item) Pesquisa_Binaria(no->Esq, x);
    else if(x > no->item) Pesquisa_Binaria(no->Dir, x);
    else if(x == no->item) printf("Item encontrado\n");
}

void Retirada_Arvore(Apontador* no, long x){
    Apontador aux;
    if((*no) == NULL) printf("Item não existe ou a árvore é vazia\n");
    else{
        if(x < (*no)->item) Retirada_Arvore(&(*no)->Esq, x);
        else if(x > (*no)->item) Retirada_Arvore(&(*no)->Dir, x);

        else if((*no)->Dir == NULL && (*no)->Esq != NULL){
            aux = (*no);
            (*no)= (*no)->Esq;
            free(aux);
        }
        else if((*no)->Dir != NULL && (*no)->Esq != NULL){
            Antecessor(*no, &(*no)->Esq);
        }
        else if((*no)->Dir != NULL && (*no)->Esq == NULL){
            aux = (*no);
            (*no) = (*no)->Dir;
            free(aux);
        }
        else (*no) = NULL;
    }
}

void Antecessor(Apontador no, Apontador* r){
    Apontador aux;
    if((*r)->Dir != NULL){
        Antecessor(no, &(*r)->Dir);
        return;
    }
    no->item = (*r)->item;
    aux = *r;
    *r = (*r)->Esq;
    free(aux);
}
