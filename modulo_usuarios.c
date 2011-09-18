/*Arquivo destinado à implementação das funções referentes à manipulação de usuários.*/
#include <stdio.h>
#include <string.h>

/***
 * IMPORTANTE: ATUALIZAR TODAS AS FUNCOES PARA AS PADRONIZADAS
 * NAO ESQUECER
 *
 ***/

usuario *posicao_usuario;

/*FUNCAO PARA USUARIO REALLIZAR SUAS ATIVIDADES */
int tarefaUsuarios (int tipo_usuario, usuario *posicao_usuario) {

	int operacao, codigo_item, continuar, numero_pedido, estado_pedido, codigo_item, tipoAlteracao;
	int pedido_novo[60];
	item novo_item, *p_item;
	float preco_item, novo_preco;
	usuario *p_usuario_atual;
	char novo_cpf[12], novo_nome[50], nova_senha[6];

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
							menuInserirPedido (&novo_pedido);
							/*inserirPedido (lista de itens aserem inseridos no pedido , ponteiro do usuario para insetir os pedidos); */
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
						menuInserirPedido (&novo_pedido);
						/*inserirPedido (lista de itens aserem inseridos no pedido, ponteiro do usuario para insetir os pedidos); */
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
							deletarListaUsuarios (&p_usuario_atual, /&plista_usuarios);
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
								menuAlterarQtd (&nova_quantidade);
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
	usuario_existe = pesquisaListaUsuarios (&cpf);
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

