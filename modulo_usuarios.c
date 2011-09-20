/*Arquivo destinado à implementação das funções referentes à manipulação de usuários.*/
#include <stdio.h>
#include <string.h>
#include "modulo_arquivos.h"
#include "modulo_interface.h"
#include "modulo_itens.h"
#include "modulo_pedidos.h"

/***
 * IMPORTANTE: ATUALIZAR TODAS AS FUNCOES PARA AS PADRONIZADAS
 * NAO ESQUECER
 *
 ***/

usuario *posicao_usuario;

void InsereListaUsuarios(usuario **epinicio, usuario novo_usuario){
	usuario *p1, *p2;

	p1 = malloc (sizeof (usuario));
	strcpy (p1->CPF, novo_usuario.CPF);
	strcpy (p1->senha, novo_usuario.senha);
	strcpy (p1->nome, novo_usuario.nome);
	p1->tipo_acesso = novo_usuario.tipo_acesso;

	if (*epinicio == NULL) {
		*epinicio = p1;
		p1->prox_usuario = NULL;
	} else {
	      p1->prox_usuario = *epinicio;
	      *epinicio = p1;
	}
	p1 = NULL;
}
void alterarCPF (char *novo_cpf, usuario **pusuario_atual) {
	strcpy (pusuario_atual->CPF, novo_cpf);
}

void alterarNome (char *novo_nome, usuario **pusuario_atual) {
	strcpy (pusuario_atual->nome, novo_nome);
}

void alterarSenha (char *nova_senha, usuario **pusuario_atual) {
	strcpy (pusuario_atual->CPF, nova_senha);
}
void apontaListaUsuarios (usuario **p_usuario_atual, char *cpf_desejado) {
	usuario*p1;

	p1 = *plista_usuarios;
	while ((p1 != NULL) && ((strcmp(plista_usuarios->CPF, cpf_desejado))=! 0 )) {
		p1 = p1->prox_usuario;
	}
	*p_usuario_atual=p1;
}


int verificaTipoUsuario (usuario **atual) {
	int tipo;

	tipo = *atual->tipo_acesso;
	return tipo;
}

int pesquisaListaUsuarios (char *cpf_procura) {
	usuario *p1;

	p1 = *plista_usuarios;
	while ((p1 != NULL) && ((strcmp(p1->CPF, cpf_procura))=! 0 )) {
		p1 = p1->prox_usuario;
	}
	/*se p1 for NULL, chegou no fim da lista e o usuario nem existe, dai retorna 0, se nao, achou ele dai sim retorna 1, que ele existe */
	if (p1 == NULL) {
		return 0;
	} else {
		return 1;
	}
}
void mostrarListaUsuarios (usuario **plista_usuarios) {
	usuario *p1;

	if (*plista_usuarios == NULL)
		printf ("nenhum usuario cadastrado ainda \n");
	else {
		p1 = *plista_usuarios;
    		while (p1 != NULL) {
    			printf("%-11s %-50s\n", p1->CPF, p1->nome);
    			p1 = p1->prox_usuario;
    		}
  	}
}

int procurarSenhaUsuarios (char *senha) {
	usuario *p1;

	p1 = *plista_usuarios;
	while ((p1 != NULL) && ((strcmp(p1->senha, senha))=! 0 )) {
		p1 = p1->prox_usuario;
	}
	/*se p1 for NULL, chegou no fim da lista e o usuario nem existe, dai retorna 0, se nao, achou ele dai sim retorna 1, que ele existe */
	if (p1 == NULL) {
		return 0;
	} else {
		return 1;
	}
}

void deletarListaUsuarios (usuario **p_usuario_atual) {
	usuario *p1, *p2;

	if (*plista_usuarios == NULL)
		printf("lista de usuarios vazia\n");
	else if (*p_usuario_atual == NULL)
		printf("usuario ja deletado anteriormente\n");
	else {
		p1 = *plista_usuarios;
		while (p1 != NULL) {
			if (p1->CPF == (*p_usuario_atual)->CPF) {
				if (*plista_usuarios == p1){
					*plista_usuarios = (*plista_usuarios)->prox_usuario;
					free (p1);
					p1 = *plista_usuarios;
				} else {
					p2->prox_usuario = p1->prox_usuario;
					free (p1);
					p1 = p2->prox_usuario;
				}
      			} else {
        			p2 = p1;
        			p1 = p1->prox_usuario;
      			}
		*p_usuario_atual = NULL; /*vai tipo deixar ele nulo, ja que eh global e tal, pra nao zoar */
    		}
	}
}

}
/*FUNCAO PARA USUARIO REALLIZAR SUAS ATIVIDADES */
int tarefaUsuarios (int tipo_usuario, usuario **posicao_usuario) {
	itens_pedido *p_itens_pedido;
	int operacao, codigo_item, continuar, numero_pedido, estado_pedido, codigo_item, tipoAlteracao;
	int pedido_novo[60], nova_quantidade;
	item novo_item, *p_item;
	float preco_item, novo_preco, preco_total_pedido;
	usuario *p_usuario_atual;
	char novo_cpf[12], novo_nome[50], nova_senha[6], nova_descricao[50];

	/*criar os ponteiros alternativos aqui */
	
	switch (tipo_usuario) {
		case 0: /*comum*/
			do{
				operacao = menuComum ();
				switch (operacao) {
					case 1: /*consltar precos */
						do{
							codigo_item = menuItem ();
							preco_item = consultarPrecoItem (codigo_item);
							mostrarPreco (preco_item);
							continuar = funcaoContinuar ();
						} while (continuar==1);
					break;
					case 2: /*fazer um pedido REVER*/
						do {
							preco_total_pedido = menuInserirPedido(&p_itens_pedido);
							inserirPedido (&p_itens_pedido, preco_total_pedido); /*passo o ponteiro do pedido pra adicionar ele e seu valor total */
							continuar = funcaoContinuar ();

						} while (continuar ==1);
					break;

					case:3 /*consultar estado pedido*/
						do {
							numero_pedido = menuEstadoPedido (usuario **p_usuario_atual, pedido **pedido_usuario_atual);
							estado_pedido = consultarEstadoPedido (/*ponteiro usuario*/, /*ponteiro do pedido*/, numero_pedido);
							mostrarEstadoPedido (estado_pedido);
							continuar = funcaoContinuar ();
						} while (continuar ==1);
					break;
					case 4:
					break;
				}
			} while (operacao != 4); /*se for 4, automaticamente ja vai deslogar */
		break;
		case 1: /*adm*/
			do {
				operacao = menuAdm ();
				switch (operacao);

				case 1: /*consltar precos */
					do{
						codigo_item = menuItem ();
						preco_item = consultarPrecoItem (codigo_item);
						mostrarPreco (preco_item);
						continuar = funcaoContinuar ();
					} while (continuar==1);
				break;
				case 2: /*fazer um pedido REVER*/
					do {
						preco_total_pedido = menuInserirPedido(&p_itens_pedido);
						inserirPedido (&p_itens_pedido, preco_total_pedido); /*passo o ponteiro do pedido pra adicionar ele e seu valor total */
						continuar = funcaoContinuar ();

					} while (continuar ==1);
				break;

				case:3 /*consultar estado pedido*/
					do {
						numero_pedido = menuEstadoPedido (&posicao_usuario, &pedido_usuario_atual);
						estado_pedido = consultarEstadoPedido (posicao_usuario,pedido_usuario_atual, numero_pedido);
						mostrarEstadoPedido (estado_pedido);
						continuar = funcaoContinuar ();
					} while (continuar ==1);
				break;
				case 4: /*alterar usuario */
					do {
						tipoAlteracao = menuAlterarUsuario (&plista_usuarios, &p_usuario_atual);
						if (tipoAlteracao == 1) { /*alterar cpf */
							insereCPF(&novo_cpf);
							alterarCPF (novo_cpf, &p_usuario_atual);
						} else if (tipoAlteracao == 2) {/*slterar senha */
							insereSenha(&nova_senha);
							alterarSenha (nova_senha, &p_usuario_atual);
						} else if (tipoAlteracao ==3 ) { /*alterar nome */
							insereNome(&novo_nome);
							alterarNome (novo_nome, &p_usuario_atual);
						} else if (tipoAlteracao==4) { /*excluir*/
							deletarListaUsuarios (&p_usuario_atual);
						}
						continuar = funcaoContinuar ();
					}while (continuar == 1);
				break;
					
				case 5: /*alterar produtos*/
					do {
						tipoAlteracao = menuAlterarProduto ();
						switch (tipoAlteracao) {
							case 1: /*adicionar novo item */
								novo_item = menuInserirItem ();
								insereListaItens (novo_item); /* */
							break;
								
							case 2: /*mudar preco */
								codigo_item = menuItem ();
								novo_preco = menuAlterarPreco ();
								apontaListaItens (codigo_item, &p_item);
								alterarPrecoItem (novo_preco, &p_item);
							break;
							case 3: /*alrterar descricao */
								codigo_item = menuItem();
								menuAlterarDescricao (&nova_descricao);
								apontaListaItens(codigo_item, &p_item);
								alterarDescricaoitem(nova_descricao, &p_item);
							break;
							case 4: /*alterar qtd de um item no estoque */
								codigo_item = menuItem();
								nova_quantidade = menuAlterarQtd ();
								apontaListaItens(codigo_item, &p_item);
								alterarQtdItem (nova_quantidade, &p_item);
							break;
						}
					} while (tipoAlteracao!=5);

					break;
			
					case: 6 /*pedidos */
						do{
							processar = processarPedido (&posicao_usuario, &posicao_pedido);
							alterarEstadoPedido(processar, &posicao_pedido);
							continuar = funcaoContinuar();
						} while (continuar== 1);
					break;

			} while (operacao != 7); /*diferente da opcao de deslogar */
		break;
	}
	return 0;
}
	
	
/*FUNCAO DE LOGIN DE USUARIO */
int FazerLogin (char *cpf,  char *nome, char *senha) {
	int senha_correta;
	int usuario_existe, tipo_usuario;
	

	apontaListaUsuario(&posicao_usuario);
	usuario_existe = pesquisaListaUsuarios (cpf);
	senha_correta = procurarSenhaUsuario (*senha, &posicao_usuario);
	if ((senha_correta==1)&&(usuario_existe==1)){
		tipo_usuario = verificarTipoUsuario (posicao_usuario);
		return (tipo_usuario); /*login ok, retorna tipo usuario fez tudo o que tinha que fazer e depois saiu */
	} else {
		return (-1); /*retornar -1 pra caso a senha esteja errada e a interface tomar as  decisoes adequadas */
	}
}

/*FUNCAO PARA CADASTRAR UM USUARIO
 * FUNCAO OK
 * */

void cadastrarUsuario () {
	usuario cadastro_usuario;
	
	insereCPF (&cadastro_usuario.CPF);
	insereNome(&cadastro_usuario.nome);
	insereSenha(&cadastro_usuario.senha);
	cadastro_usuario.tipo_acesso = escolheUsuario(); /*0 comum 1 adm*/

	insereListaUsuarios(&cadastro_usuario);
}

