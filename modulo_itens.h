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
}item;
