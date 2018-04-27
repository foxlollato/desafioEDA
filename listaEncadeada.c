#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.h"

typedef struct tipoNo{
    struct elemento dado;
    struct tipoNo *prox;
}noLista;

struct nodo{
    noLista *head;
    noLista *tail;
};

//typedef struct tipoNo noLista; //tipoNo == noLista neste arquivo
// o typedef anterior tbm pode ser definido da seguinte forma (sem especificar o nome, apenas o sin�nimo = noLista):
/*typedef struct{
    struct elemento dado;
    struct tipoNo *prox;
}noLista;*/

Lista* criaLista(){
    Lista *list = (Lista*) malloc(sizeof(Lista));
						//reserva espa�o para o primeiro n� da lista
						// list == ponteiro para estrutura com 2 campos (Lista)
    if(list != NULL)//criou corretamente
        list->head = NULL; //ponteiro list est� vazio - aponta para NULL
        list->tail = NULL;
    return list;
}

int tamLista(Lista* inicio){
    if(inicio == NULL)
        return 0;
    int cont = 0;
    noLista* no = inicio->head;  //cria no aux (no),
							//que apontar�, inicialmente,
							//para onde inicio aponta
    						//na sequ�ncia, correr� por
							//todos os elementos do encadeamento (prox)
							//at� encontrar NULL.
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int listaCheia(Lista* inicio){
    return 0;
}

int listaVazia(Lista* inicio){
    if(inicio == NULL)//verifica se a cabe�a existe (lista v�lida)
        return 1;
    if(inicio->head == NULL)//verifica se o conte�do dela (p/ quem aponta) � NULL
        return 1;
    return 0;
}

int consultaPosicao(Lista* inicio, int pos, struct elemento *aluno){
    if(inicio == NULL || pos <= 0)
        return 0;
    noLista *no = inicio;
    int i = 1;
    while(no != NULL && i < pos){
        no = no->prox;
        i++;
    }
    if(no == NULL)
        return 0;
    else{
        *aluno = no->dado;
        return 1;
    }
}

int consultaMatricula(Lista* inicio, int mat, struct elemento *aluno){
    if(inicio == NULL)
        return 0;
    noLista *no = inicio;
    while(no != NULL && no->dado.valor != mat){
        no = no->prox;
    }
    if(no == NULL)
        return 0;
    else{
        *aluno = no->dado;
        return 1;
    }
}

int insereFinal(Lista* inicio, struct elemento aluno){

    if(inicio == NULL)
        return 0;

    noLista *no; //define ponteiro no do tipo noLista
    no = (noLista*) malloc(sizeof(noLista));
    if(no == NULL)
        return 0;
    no->dado = aluno;
    no->prox = NULL;

    if(inicio->head == NULL){//lista vazia: insere in�cio
        inicio->head = no;
    }else{
        noLista *aux;
        aux = inicio->head;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
        inicio->tail = no;


    }
    return 1;
}

int insereInicio(Lista* inicio, struct elemento aluno){

    if(inicio == NULL)
        return 0;
    noLista* no;
    no = (noLista*) malloc(sizeof(noLista));
    if(no == NULL)
        return 0;
    no->dado = aluno;
    no->prox = inicio;

    if(listaVazia(inicio)){
        inicio->tail = no;
    }
    inicio->head = no;
    return 1;
}

int insereOrdenada(Lista* inicio, struct elemento aluno){
    if(inicio == NULL)
        return 0;
    noLista *no = (noLista*) malloc(sizeof(noLista));
    if(no == NULL)
        return 0;
    no->dado = aluno;

    if(inicio == NULL){//lista vazia: insere in�cio
        no->prox = NULL;
        inicio->head = no;
        inicio->tail = no;
        return 1;
    }
    else{
        noLista *ant, *atual = inicio->head;
        //precisa comparar o atual != NULL antes, pois do contr�rio, ele vai
        //tentar comparar o campo matr�culo dentro do atual que � NULL (n�o tem matr�cula)
        //da� dar� erro. Ent�o, preciso ter na condi��o do while (atual!=NULL) antes do &&
		while(atual != NULL && atual->dado.valor < aluno.valor){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == inicio->head){//insere in�cio
            no->prox = inicio->head;
            inicio->head = no;
        }else{
            no->prox = atual;
            ant->prox = no;
        }
        if(atual->prox == NULL)
            inicio->tail=atual;

        return 1;
    }
}

int removeMatricula(Lista* inicio, int mat){
    if(inicio == NULL)
        return 0;
    if((inicio) == NULL)//lista vazia
        return 0;
    noLista *ant, *no = inicio->head;
    while(no != NULL && no->dado.valor != mat){
        ant = no;
        no = no->prox;
    }
    if(no == NULL)//n�o encontrado
        return 0;

    if(no == inicio->head)//remover o primeiro?
        inicio->head = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    return 1;
}

int removeInicio(Lista* inicio){
    if(inicio == NULL)
        return 0;
    if((inicio->head) == NULL)//lista vazia
        return 0;

    noLista *no = inicio->head;
    inicio->head = no->prox;
    free(no);
    return 1;
}

int removeFinal(Lista* inicio){
    if(inicio == NULL)
        return 0;
    if((inicio->tail) == NULL)//lista vazia
        return 0;

    noLista *ant, *no = inicio->tail;

    if(no == (inicio->head))//remover o primeiro?
        inicio->head = no->prox;
    else
        ant->prox = no->prox;
        inicio->tail = ant;
    free(no);
    return 1;
}

void imprimeLista(Lista* inicio){
    if(inicio == NULL)
        return;
    noLista* no = inicio->head;
    while(no != NULL){
        printf("\Valor: %d\n",no->dado.valor);
        printf("-------------------------------\n");
        no = no->prox;
    }
}


void apagaLista(Lista* inicio){
    if(inicio != NULL){
        noLista* no;
        while(inicio->head != NULL){ 		 //retira cada n� at� encontrar fim da lista (NULL)
            no = inicio->head;		//no aux recebe o in�cio da lista ("1�..." elemento)
            inicio->head = no->prox;//in�cio da lista passa a apontar p/ "2�..." elemento
            free(no); 				  //libero mem�ria do "1�..." elemento da lista
        }
        free(inicio); //libero cabe�a da lista
    }
}

int subLista(Lista *l1, Lista *l2, int inicio, int fim){
    if(l1==NULL || l2 == NULL || fim>tamLista(l1) || inicio>tamLista(l1)){
        return 0;
    }
    int i;
    noLista *aux1, *aux2, *ant;
    if(inicio>=fim){
        
	while(inicio>=fim){
		i=fim;
        	aux1 = l1->head;
		
		while(i != inicio+1){
            		ant=aux1;
			aux1=aux1->prox;
			i++;
        	}			
            	insereFinal(l2, ant->dado);
		inicio--;
    	}
    }else{
        i=inicio;
        aux1 = l1->head;
        while(i != inicio+1){
            	ant = aux1;
		aux1 = aux1->prox;
           	 i++;
        }
        aux2=ant;

        while(i <= fim+1){
            insereFinal(l2, aux2->dado);
            aux2 = aux2->prox;
            i++;
        }
    }
return 1;
}
