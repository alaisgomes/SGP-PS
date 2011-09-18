/*Header contendo escopo de fuções, estruturas, defines ... referentes a usuários*/

#include "modulo_pedidos.h"
#include <stdio.h>
#include <stdlib.h>

/*#######################################################*/
/*#########Struct para manipulação de Usuários###########*/
/*#######################################################*/

typedef struct estrutura_usuario{

	int CPF;		/*Variável responsável por identificar o usuário de maneira
	 	 	 	 	 única*/
	int tipo_acesso;/*Variável responsável por informar quais os privilégios
					 de acesso determinado usuário possui.*/
	int senha[5];	/*Variável responsável por armazenar a senha de acesso do
	 	 	 	 	 usuário.*/
	char nome[50];

	/*----------------------------------------------------*/
	/*Para o armazenamento dos usuários deverá ser utilizada uma lista encadeada
	 * simples.*/

	struct estrutura_usuario *proximo_usuario; /*Variável que aponta para a próxima
	 	 	 	 	 struct "usuário" da lista.*/

	/*----------------------------------------------------*/
	/*Cada usuário possuirá uma lista de pedidos.*/

	pedido *pedidos;	/*Variável para armazenar a lista de pedidos que o usuário possui.*/


}usuario;

int tarefaUsuarios (int tipo_usuario, usuario *posicao_usuario);

int FazerLogin (char *cpf,  char *nome, char *senha);

void cadastrarUsuario ();

