/*Header contendo escopo de fuções, estruturas, defines ... referentes a usuários*/

#include "modulo_pedidos.h"
#include <stdio.h>
#include <stdlib.h>

/*#######################################################*/
/*#########Struct para manipulação de Usuários###########*/
/*#######################################################*/

typedef struct estrutura_usuario{
	char CPF[11];
	int tipo_acesso;
	char senha[6];
	char nome[50];

	struct estrutura_usuario *prox_usuario;
	pedido *pedidos; /*sublista de cada usuario com seus pedidos */

}usuario;

void alterarCPF (char *novo_cpf, usuario **p_usuario_atual);
void alterarNome (char *novo_nome, usuario **p_usuario_atual);
void alterarSenha (char *novo_senha, usuario **p_usuario_atual);

void apontaListaUsuarios (usuario **p_usuario, char **cpf);
void insereListaUsuarios(usuario *cadastro_usuario);
int pesquisaListaUsuarios (char *cpf); /*retorna se o usuario existe ou nao */
void mostrarListaUsuarios (usuario **plista_usuarios);

int verificaTipoUsuario (usuario **atual);


int procurarSenhaUsuarios (char *senha); /*retorna se a seha existe ou nao */

void deletarListaUsuarios (usuario *p_usurio_atual); /*deleta usuario da lista de usuarios */

int tarefaUsuarios (int tipo_usuario, usuario *posicao_usuario);

int FazerLogin (char *cpf,  char *nome, char *senha); /*retorna o tipo do usuario ou se o login nao foi possivel ser realizado (-1)*/

void cadastrarUsuario ();



