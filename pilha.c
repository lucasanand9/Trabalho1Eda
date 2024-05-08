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

int empilha(int obj, int pilha,  multipilha *mult);

int desempilha(int pilha,  multipilha *mult);

int testeCheia( multipilha *mult){
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
    
}

int tamanhoPilha(int pilha ,multipilha *mult);
