#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct NO{
	int dado;
	struct NO *prox;
	}NO;
	
typedef struct PILHA{
	NO *topo;
}PILHA;

void inicializaPilha(PILHA *p){
	p->topo = NULL;
	}
	
void empilha(int dado, PILHA *p){	
	NO *ptr = (NO*) malloc(sizeof(NO));
	if(ptr == NULL){
		printf("erro de alocação de nó.\n");
		return;
	} else {
		ptr->dado = dado;
		ptr->prox = p->topo;
		p->topo = ptr;
	}
}		

int desempilha(PILHA *p){
	NO* ptr = p->topo;
	int dado;
	if(ptr == NULL){
		printf("Pilha vazia.\n");
		return(0);
	} else {
		p->topo = p->topo->prox;
		ptr->prox =NULL;
		dado = ptr->dado;
		free(ptr);
		return dado;
	}	
}

void imprimePilha(PILHA *p){
	NO *ptr = p->topo;
	if(ptr == NULL){
		printf("Pilha vazia.\n");
		return;
	} else {
		while(ptr != NULL){
			printf("%d", ptr->dado);
			ptr = ptr->prox;
		}
		printf("\n");
	}
}

int main(){
	PILHA *p1 = (PILHA*) malloc(sizeof(PILHA));
	if(p1 == NULL){
		printf("erro de alocação de nó.\n");
		exit(0);
	} else {
		inicializaPilha(p1);
		
		empilha (10, p1);
		empilha (20, p1);
		empilha (30, p1);
		
		imprimePilha(p1);
		
		printf("tentando desempilhar - resultado:%d\n", desempilha(p1));
		imprimePilha(p1);
		
		printf("tentando desempilhar - resultado:%d\n", desempilha(p1));
		imprimePilha(p1);
		
		printf("tentando desempilhar - resultado:%d\n", desempilha(p1));
		imprimePilha(p1);
	}
	
	
	
}	
