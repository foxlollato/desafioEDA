#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.h"

#define qtde 5

main(){
    struct elemento vetAlunos[qtde] = {
			{1},
                        {3},
                        {5},
                        {7},
                        {9}
	};
    struct elemento vetAlunos2[qtde] = {
			{2},
                        {4},
                        {6},
                        {8},
                        {10}
	};

    	Lista *inicio = criaLista(); //cria ponteiro especial (inicio**) que aponta
	Lista *l2 = criaLista();							//para outro ponteiro (Lista*), que é ponteiro para struct com 2 campos (tipoNo)
								//desta forma, o "início" da lista é ponteiro para ponteiro
    int i;


    for(i=0; i < qtde; i++){
        insereFinal(inicio, vetAlunos[i]);
	insereFinal(l2, vetAlunos2[i]);
	}
	
	imprimeLista(inicio);
        printf("\n --> Tamanho atual da lista1: %d\n\n\n",tamLista(inicio));

	imprimeLista(l2);
        printf("\n --> Tamanho atual da lista2: %d\n\n\n",tamLista(l2));



	subLista(inicio,l2,1,3);

   	imprimeLista(l2);
    	printf(" --> Tamanho atual da lista: %d\n", tamLista(l2));

	apagaLista(inicio);

}

