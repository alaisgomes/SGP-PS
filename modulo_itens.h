/*Header contendo escopo de funções, estruturas, defines ... referentes a itens.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct estrutura_item{

	float preco;
	int categoria;			/* 0-Livro
	 	 	 	 	 	 	   1-Eletronico
	 	 	 	 	 	 	   2-CD */
	char descricao[50];
	int quantidade; /*Variável que representa a quantidade
	 	 	 	 	 em estoque do item em questão.*/
	int codigo;
	struct estrutura_item *prox_item;

}item;

float consultarPrecoItem (int codigo_item);
void alterarPrecoItem (int novo_preco, item **p_item);
void alterarQtdItem (int nova_quantidade, item **p_item);
void alterarDescricaoitem (char *nova_descricao, item **p_item);

void insereListaItens (item novo_item);
void apontaListaItens (item codigo_item, item **pitem);
int procuraListaItens(int cod_item);
void mostrarListaItens (item **plista_itens);
