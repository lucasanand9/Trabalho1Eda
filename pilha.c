#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

multipilha *criaPilhas(int tam){
    multipilha *mult = NULL;
    if(tam >0){
        mult = malloc(sizeof(multipilha));
        mult->tamVet = tam;
        mult->topo1 = -1;
        mult->topo2 = tam;
        mult->vet = malloc(sizeof(int)*tam);
    }
    return mult;
}

void destroiPilhas( multipilha *mult){
    free(mult->vet);
    free(mult);
}

void reiniciaPilha(int pilha ,multipilha *mult){
    switch(pilha){
        case 1:
            mult->topo1 = -1;
        break;
        case 2:
            mult-> topo2 = mult->tamVet;
        break;
    }
}


int empilha(int obj, int pilha,  multipilha *mult){
    if(testeCheia(mult)){
        return 0; 
    }

    switch(pilha){
        case 1:
            mult->topo1++;
            mult->vet[mult->topo1] = obj;
            return 1;
        break;

        case 2:
            mult->topo2--;
            mult->vet[mult->topo2] = obj;
            return 1;
        break;
    }
}

int desempilha(int pilha,  multipilha *mult){
    switch(pilha){
        case 1:
            if (testeVazio(1, mult)){
                return NULL;
            }
            int obj = mult->vet[mult->topo1];
            mult->topo1--;
            return obj;
        break;
        case 2:
        if (testeVazio(2, mult)){
                return NULL;
            }
            int obj = mult->vet[mult->topo2];
            mult->topo2++;            
            return obj;
        break;
    }
}


int testeCheia(multipilha *mult){
     return(mult->topo1)+1 == mult->topo2 || mult->topo1 == (mult->topo2)-1; 
}

int testeVazio(int pilha ,multipilha *mult){
    switch(pilha){
        case 1:
            return (mult->topo1 == -1);
        break;
        case 2:
            return (mult->topo2 == mult->tamVet);
        break;
    }
}

int buscaTopo(int pilha,  multipilha *mult){
    switch(pilha){
        case 1:
            return mult->vet[mult->topo1];
        break;
        case 2:
            return mult->vet[mult->topo2];
        break;
    }
}

int tamanhoPilha(int pilha ,multipilha *mult){
    int cont = 0;
    switch(pilha){
        case 1:
            return mult->topo1 + 1;
        break;
        case 2:
            return mult->tamVet - mult->topo2;
        break;
    }
}
