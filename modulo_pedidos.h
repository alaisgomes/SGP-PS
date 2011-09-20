/*Header contendo escopo de fuções, estruturas, defines ... referentes a pedidos.*/

#include <stdio.h>
#include <stdlib.h>
#include "modulo_itens.h"

/*#######################################################*/
/*#########Structs para manipulação de Pedidos###########*/
/*#######################################################*/
typedef struct estrutura_itens_pedido{

	item *item;
	int quantidade;
	char data_entrada [10];
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

void alterarEstadoPedido (int processar, **posicao_pedido);
void insereListaPedidos (/*rever parametros */);
int consultarEstadoPedido (/*ponteiro usuario*/, /*ponteiro do pedido*/, numero_pedido);
float consultarPrecoItem ( int codigo_item);


void insereListaItensPedidos(itens_pedido **p_itens_pedido, int codigo_item, int quantidade, char *data);
/*vai passar o ponteiro do pedido atual (que ele ta criando na funcao) e vai passar o item e a quantidade e essa funcao
 * vai atualizar o pedido achando o item pelo codigo e atualizando o ponteiro
 */
