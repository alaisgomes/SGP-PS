/*Header contendo escopo de fuções, estruturas, defines ... referentes a pedidos.*/

#include "modulo_item.h"
#include <stdio.h>
#include <stdlib.h>

/*#######################################################*/
/*#########Structs para manipulação de Pedidos###########*/
/*#######################################################*/
typedef struct estrutura_itens_pedido{

	item *item;
	int quantidade;

	struct estrutura_itens_pedido *proximo;

}itens_pedido;

/*--------------------------------------------------------*/
typedef struct estrutura_pedido{

	int dono_pedido;		/*Variável contendo o CPF do
	 	 	 	 	 	 	 dono do pedido.*/
	int estado;				/*Variável para armazenar o
	 	 	 	 	 	 	 *estado de um pedido:
	 	 	 	 	 	 	 * 0-Em espera.
	 	 	 	 	 	 	 * 1-Processado*/
	char data_entrada[10], data_processamento[10] /*dd/mm/aaaa*/;

	/*---------------------------------------------------*/
	/*Os pedidos possuem uma lista dos itens */

	itens_pedido *intens_no_pedido;/*Variável para armazenar
	 	 	 	 	 	 	 a lista de itens do pedido.*/
	float valor_total;		/*Valor total do pedido.*/

}pedido;