#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct No{
	char* palavra;
	int cont;
	struct No* Prox;
} No;

//Requisito: |Iterativo|
void CriaElem(No**, char*);
void CriarLista(No**);
void InserirLista(No**, char*);
void ExcluirLista(No**);
void Imprimir(No*);


int main(){
	char texto[100000]; char palavraAtual[500];
	No*L; CriarLista(&L);
	fgets(texto, 100000, stdin); //pegar o texto todo;
	int i = 0,j=0;// i->indice do texto, j->indice da palavra;
	while(i<strlen(texto)){
		if (texto[i] != '\n' && texto[i] != '\t' && texto[i] != ' ' &&
            texto[i] != '!' && texto[i] != ';' && texto[i] != ':' &&
            texto[i] != ',' && texto[i] != '-' && texto[i] != '.') {
            	palavraAtual[j] = texto[i];
            	j++;
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
	(*Lista )= NULL;
}

void CriaElem(No** novo, char* termo){
		(*novo)= (No*)malloc(sizeof(No));
		int tamanho = strlen(termo); (*novo)->palavra = (char*)malloc(tamanho+1); //  \0
		strcpy((*novo)->palavra, termo);
		(*novo)->cont = 0; (*novo)->cont++;
}

void InserirLista(No** Lista, char* termo){
	No* aux = (*Lista); No* auxAnt = NULL;
	while(aux != NULL && strcmp(termo, aux->palavra)>0){
		auxAnt = aux;
		aux = aux->Prox;
	} //achar a posição;
	if(aux != NULL && strcmp(termo, aux->palavra)==0){
		aux->cont++;
	} // lista não vazia e mesma palavra;
	else if(aux != NULL && strcmp(termo, aux->palavra)<0){
		if(auxAnt == NULL){
			No* novo; CriaElem(&novo,termo);
			novo->Prox = aux;
			(*Lista) = novo;
		}
		else{
			No* novo; CriaElem(&novo,termo);
			auxAnt->Prox = novo;
			novo->Prox = aux;
		}
		
	} // lista não vazia e palavra diferente;
	else if(aux == NULL){
		No* novo; CriaElem(&novo,termo);
		if(auxAnt == NULL){
			(*Lista) = novo;
			novo->Prox = NULL;
		} // inserir no início a primeira palavra;
		else{
			auxAnt->Prox = novo;
			novo->Prox = NULL;
		} // inserir no final;
		
	}
}

void ExcluirLista(No** Lista) {
    No* aux = (*Lista);
    No* auxDep;

    while (aux != NULL) {
        auxDep = aux->Prox; 
        free(aux->palavra);  
        free(aux);          
        aux = auxDep;        
    }
    (*Lista) = NULL;
}


void Imprimir(No* Lista){
	No* aux = Lista;
	while(aux != NULL){
		printf("%s	-->	%d\n", aux->palavra, aux->cont);
		aux = aux->Prox;
	}
}
