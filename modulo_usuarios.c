/*Arquivo destinado à implementação das funções referentes à manipulação de usuários.*/
#include <stdio.h>
#include <string.h>

/***
 * IMPORTANTE: ATUALIZAR TODAS AS FUNCOES PARA AS PADRONIZADAS
 * NAO ESQUECER
 *
 ***/


/*FUNCAO PARA USUARIO REALLIZAR SUAS ATIVIDADES */
int tarefaUsuarios (int tipo_usuario, usuario *posicao_usuario) {

	int operacao, codigo_item, continuar, numero_pedido, estado_pedido, codigo_item, tipo, tipoAlteracao;
	float preco_item;
	/*criar os ponteiros alternativos aqui */
	
	switch (tipo_usuario) {
		case 0: /*comum*/
			do{
				operacao = menuComum (); /* funcao de login _USUARIO */
				switch (operacao) {
					case 1: /*consltar precos */
						do{
							codigo_item = menuItem (); /*mostra itens e retorna  o codigo do item desejado_interface*/
							preco_item = consultarPrecoItem (codigo_item); /*procura na lista de itens o preco dele _ITENS*/
							continuar = mostrarPreco (preco_item); /*mostra o preco do item _INTERFACE*/
						} while (continuar==1);
					break;
					case 2: /*fazer um pedido*/
						do {
							menuInserirPedido (itens_pedido *p_itens_pedidos); /*passa pra inserir todos os itens desejados*/
							continuar = funcaoContinuar();
						} while (continuar ==1);
					break;
					case:3 /*consultar estado pedido*/
					do {
						numero_pedido = menuPedido (/*o ponteiro do usuario */, /*ponteirov do pedido*/); /*retorna o numero do pedido _INTERFACE*/
						estado_pedido = consultarEstadoPedido (/*ponteiro usuario*/, /*ponteiro do pedido*/, numero_pedido); 
						mostrarEstadoPedido (estado_pedido); /*Mostrar pro usuario o estado do pedido dele e se ele desenja continuar a fazer isso */
					} while (continuar ==1);
					break;
			} while (operacao != 4); /*se for 4, automaticamente ja vai deslogar */		
			break;
		case 1: /*adm*/
			do {
				operacao = menuAdm ();
				switch (operacao);
				
				
				/*quando fizer essas alteracoes do usuario eu faco aqui tbm 
				 * ****************          ***************           ***************** */
					case 1: /*consltar precos */
						do{
							codigo_item = menuItem (); /*mostra itens e retorna  o codigo do item desejado_interface*/
							preco_item = consultarPrecoItem (codigo_item); /*procura na lista de itens o preco dele _ITENS*/
							mostrarPreco (preco_item); /*mostra o preco do item _INTERFACE*/
							continuar = funcaoContinuar ();
						} while (continuar==1);
					break;
					case 2: /*fazer um pedido*/
						do {
							menuInserirPedido (/*dados a serem repassados para inserir no novo pedido _INTERFACE */);
							inserirPedido (/*lista de itens aserem inseridos no pedido*/, /*ponteiro do usuario para insetir os pedidos*/); /*passa pra inserir todos os itens desejados_INTERFACE*/
							continuar = funcaoContinuar ();
							
						} while (continuar ==1);
					break;
					
					case:3 /*consultar estado pedido*/
					do {
						numero_pedido = menuPedido (/*o ponteiro do usuario */, /*ponteirov do pedido*/); /*retorna o numero do pedido _INTERFACE*/
						estado_pedido = consultarEstadoPedido (/*ponteiro usuario*/, /*ponteiro do pedido*/, numero_pedido); 
						mostrarEstadoPedido (estado_pedido); /*_INTERFACE Mostrar pro usuario o estado do pedido dele e se ele desenja continuar a fazer isso */
						continuar = funcaoContinuar ();
					} while (continuar ==1);
					break;
					/*                                    ***************                      */
					
					
					case 4: /*alterar usuario */
						do {
							tipoAlteracao = menuAlterarUsuario (/*lista de usuarios*/ , /*ponteiro do usuario que se deseja alterar _INTEFACE*/);
							if (tipoAlteracao == 1) { /*alterar cpf */
								mudarCPF (/*passar a string do novo CPF _INTERFACE*/);
								alterarCPF (/*string novo CPF*/, /*ponteiro do usuario que se quer alterar _USUARIO */);
							} else if (tipoAlteracao == 2) {/*slterar senha */
								mudarSenha(/*string nova senha INTERFACE*/);
								alterarSenha (/*string nova senha*/, /*ponteiro ddo usuario que se quer alterar*/);
							} else if (tipoAlteracao ==3 ) { /*alterar nome */
								mudarNome (/*string do novo nome */);
								alterarNome (/*ponteiro do usuario*/, /*string novo nome*/);
							} else if (tipoAlteracao==4) { /*excluir*/
								deletarUsuario (/*ponteiro usuario*/, /*ponteiro da lista de usuarios*/);
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
									inserirNovoItem (novo_item, /*ponteiro da lista de itens*/); /* */
								break;
								
								case 2: /*mudar preco */
									codigo_item = menuAlterarPreco ();
					break;
			
					case: 6 /*pedidos */
						
				} while (operacao != 7); /*diferente da opcao de deslogar */
		break;
		return 0;
		
	}
	
	
/*FUNCAO DE LOGIN DE USUARIO */
int FazerLogin (char *cpf,  char *nome, char *senha) {
	int senha_correta;
	int tipo_usuario;
	int tentar_login;
	
	tipo_usuario = procurarUsuario (*cpf,posicao_usuario); /*chama funcao de procurar usuario passandoo o cpf e ao encontrar o cpf returna o ponteiro da posicao do usuario */
	senha_correta = procurarSenha (*senha, **posicao_usuario); /*vai entrar na posicao do usuario e procurar na struct do usuario se a senha bate e retorna se sim ou se nao*/
	if ((senha_correta==1)&&((tipo_usuario==1)||(tipo_usuario==0))){
		/*tarefasUsuario (tipo_usuario); senha OK = chama funcao pra realizar tarefas*/
		
		return (tipo_usuario); /*login ok, retorna tipo usuario fez tudo o que tinha que fazer e depois saiu */
	} else {
		return (-1); /*retornar -1m ppra caso a senha esteja errada e a interface tomar as  decisoes adequadas */
	}
}

/*FUNCAO PARA CADASTRAR UM USUARIO */

void cadastrarUsuario () {
	char cpf[11], nome[50], senha [6];
	int tipoUsuario;
	usuario cadastro_usuario;
	
	insereCPF (cadastro_usuario.CPF);
	insereNome(cadastro_usuario.nome);
	insereSenha(cadastro_usuario.senha);
	cadastro_usuario.tipo_acesso = escolheUsuario(); /*0 comum 1 adm*/

	inserirUsuarioLista(&cadastro_usuario, &p_usuario);
}

