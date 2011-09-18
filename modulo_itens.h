/*Header contendo escopo de funções, estruturas, defines ... referentes a itens.*/

#include <stdio.h>
#include <stdlib.h>

/*#######################################################*/
/*##########Struct para manipulação de Itens#############*/
/*#######################################################*/
typedef struct estrutura_item{

	float preco;
	int categoria;			/* 0-Livro
	 	 	 	 	 	 	   1-Eletronico
	 	 	 	 	 	 	   2-CD */
	char descricao[50];
	int quantidade; /*Variável que representa a quantidade
	 	 	 	 	 em estoque do item em questão.*/
	int codigo;
}item;
float consultarPrecoItem (int codigo_item);
void insereListaItens (item novo_item);
void alterarPrecoItem (int codigo_item, item *pitem);
void apontaListaItens (item codigo_item, item **pitem);
void alterarDescricaoitem (char *nova_descricao, item **p_item);
void alterarQtdItem (int nova_quantidade, item **p_item);
void alterarPrecoItem (int novo_preco, item **p_item);
