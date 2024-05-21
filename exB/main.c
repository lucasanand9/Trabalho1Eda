#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include "arq.h"

int main(int argc, char *argv[]){
     if (argc < 2) {
        printf("[ E ]: Forneca o caminho completo do arquivo por meio do parametro. \n");
        return 0;
    }

    FILE *arquivo = fopen(argv[1], "r");

    if (arquivo == NULL) {
        printf("[ E ]: Arquivo nao encontrado. \n");
        return 0;
    }
    pilha *html = cria();
    char atual[50];
    info base;
    
    while (strcmp(atual, "</html>")){
        strcpy(base.palavra, "\0");
        // printf("%i\n", strcmp(atual, "</html>"));
    
        fscanf(arquivo, "%s", atual);
        char a = atual[0];
        char b = atual[1];

        int i = 0;
        while (!(atual[i] == '>' || atual[i] == '\0')){
            i++;
        }

        printf("%i\n", i);


        info excecao = base;
        int j = 0;
        for(j = 1; j<i;j++){
            excecao.palavra[j-1] = atual[j];
        }
        excecao.palavra[j] = '\0';
        
        if(strcmp(excecao.palavra, "meta") == 0 || strcmp(excecao.palavra, "br@") == 0 || strcmp(excecao.palavra, "img") == 0 || strcmp(excecao.palavra, "input") == 0 || strcmp(excecao.palavra, "frame") == 0 || strcmp(excecao.palavra, "!DOCTYPE") == 0 ){
            continue;
        }

        if(a == '<' && b != '/' ){
            printf("primeiro if\n");
            info temp = base;
            for(j = 1; j < i; j++ ){
                temp.palavra[j-1] = atual[j];
                printf("%s\n", temp.palavra);
            }
            temp.palavra[j] = '\0';
            printf("%s\n", temp.palavra);
            empilha(&temp, html);
        }

        if(a == '<' && b == '/' ){
            printf("segundo if\n");
               
            
            info temp1 = base;
            info aux = base;
            for(int j = 2; j < i; j++ ){
                temp1.palavra[j-2] = atual[j];
                printf("%s\n", temp1.palavra);
            }
            temp1.palavra[j-1] = '\0';
            printf("%s\n", temp1.palavra);


            busca(&aux, html);
            printf("temp1: %s\naux: %s\n", temp1.palavra, aux.palavra);
            if(strcmp(temp1.palavra, aux.palavra) == 0){
                printf("desempilhando\n");
                desempilha(&aux, html);
            }else{
                printf("ERRO: esperado %s, recebido %s\n", aux.palavra, temp1.palavra);
                return 0;
            }
        }

    }
    printf("Certo\n");
    

    return 0;
}