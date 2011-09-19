/*Arquivo destinado à implementação das funções referentes à manipulação de itens.*/
#include <stdio.h>
#include "modulo_itens.h"

void InsereListaItens(item **p_itens, item novo_item){
	item *p1;

	p1 = malloc (sizeof (item));
	strcpy (p1->descricao, novo_item.descricao);
	p1->preco = novo_item.preco;
	p1->quantidade= novo_item.quantidade;
	p1->codigo = novo_item.codigo;
	p1->categoria = novo_item.categoria;


	if (*p_itens == NULL) {
		*p_itens = p1;
		p1->prox_item = NULL;
	} else {
	      p1->prox_item = *p_itens;
	      *p_itens = p1;
	}
	p1 = NULL;
}

void apontaListaItens (char *codigo_item, item **p_item_desejado) {
	item *p1;

	p1 = *p_item_desejado;
	while ((p1 != NULL) && (codigo_item != (*plista_itens)->codigo)) {
		p1 = p1->prox_item;
	}
	*p_item_desejado=p1;
}

int pesquisaListaItens (int cod_procura) {
	item *p1;

	p1 = *plista_itens;
	while ((p1 != NULL) && (cod_procura != (*plista_itens)->codigo)) {
		p1 = p1->prox_item;
	}
	/*se p1 for NULL, chegou no fim da lista e o usuario nem existe, dai retorna 0, se nao, achou ele dai sim retorna 1, que ele existe */
	if (p1 == NULL) {
		return 0;
	} else {
		return 1;
	}
}

void mostrarListaItens (item **plista_itens) {
	item *p1;

	if (*plista_itens == NULL)
		printf ("nenhum item cadastrado ainda \n");
	else {
		p1 = *plista_itens;
			printf ("Preco \t categoria \t quantidade \t descricao\n");
    		while (p1 != NULL) {
    			printf("%.2f \t %d \t %d \t %s\n", p1->preco, p1->categoria, p1->quantidade, p1->descricao);
    			p1 = p1->prox_item;
    		}
  	}
}
