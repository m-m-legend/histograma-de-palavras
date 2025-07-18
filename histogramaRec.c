#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct No{
	char* palavra;
	int cont;
	struct No* Prox;
} No;

//Requisito: |Recursivo|
void CriarLista(No**);
void InserirLista(No**, char*);
void ExcluirLista(No**);
void ImprimirLista(No*);
void Imprimir(No*);


int main(){
	char texto[100000]; char palavraAtual[500];
	No*L; CriarLista(&L);
	fgets(texto, 100000, stdin);
	int i = 0,j=0;
	while(i<strlen(texto)){
		if (texto[i] != '\n' && texto[i] != '\t' && texto[i] != ' ' &&
            texto[i] != '!' && texto[i] != ';' && texto[i] != ':' &&
            texto[i] != ',' && texto[i] != '-' && texto[i] != '.') {
            	palavraAtual[j++] = texto[i];
    } 	else if(j>0){
    			palavraAtual[j] = '\0';
    			InserirLista(&L, palavraAtual);
    			j = 0;
	}
	i++;
			
}

	Imprimir(L);
	ExcluirLista(&L);
	
	return 0;
}

void CriarLista(No** Lista){
	*Lista = NULL;
}

void InserirLista(No** Lista, char* termo){
	if(*Lista == NULL|| strcmp(termo, (*Lista)->palavra)<0){
		No* novo = (No*)malloc(sizeof(No)); int tamanho = strlen(termo);
		novo->palavra = (char*)malloc(tamanho+1);// \n
		strcpy(novo->palavra, termo);
		novo->cont = 1;
		novo->Prox = *Lista;
		*Lista = novo;
	}
	else if((strcmp(termo, (*Lista)->palavra))==0){
		(*Lista)->cont++;
	}
	else{
		InserirLista(&(*Lista)->Prox, termo);
		
	}
}

void ExcluirLista(No** Lista){
	if((*Lista)){
		ExcluirLista(&((*Lista)->Prox));
		free((*Lista)->palavra);
		free(*Lista);
		*Lista = NULL;
	}
}

void ImprimirLista(No* Lista) {
    if (Lista) {
        printf("[%s: %d] ", Lista->palavra, Lista->cont);
        ImprimirLista(Lista->Prox);
    } else {
        printf("\nFim da Lista\n");
    }
}
void Imprimir(No* Lista){
	if(Lista){
		printf("%s	-->	%d\n", Lista->palavra, Lista->cont);
		Imprimir(Lista->Prox);
	}
}
