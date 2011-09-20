/*Arquivo destinado à implementação das funções referentes à manipulação da interface.*/
#include <stdio.h>
#include <string.h>
#include "modulo_interface.h"
#include "modulo_itens.h"
#include "modulo_usuarios.h"

void insereCPF(char **cpf){
        int aux = 0;
        do{
            if(aux==1)
            printf("\nCPF Invalido");
            printf("\nInsira o CPF: ");
        		scanf(" %s[^\n]",cpf);
            getchar();
            aux = 1;
        }
        while(cpf[11] != '\0' && cpf[11] != '#');
}

void insereNome(char **nome){
            printf("Insira o nome: ");
            scanf(" %50[^\n]",nome);
            getchar();
}

void insereSenha(char **senha){
            printf("Insira a senha\n(so serao lidos os primeiros 5 caracteres): ");
            scanf(" %5[^\n]",senha);
}

int escolheUsuario(){
	int opcao;
	do{
	printf("Voce deseja ser\n1. Usuario comum\n2. Administrador");
	scanf("%d",&opcao);
	}
	while (opcao < 1 || opcao >  2);
	if (opcao == 1)
		return 0;
	else
		return 1;
}

int Logar(){
	char cpf[11]="###########";
    char nome[50], senha[6];
	insereCPF(&cpf);
    insereNome(&nome);
    insereSenha(&senha);
	return(fazerLogin(cpf, nome, senha));
}

int caso1ComecarLogin(){
	int aux=0, opcaoErro=0, retornoLogin;
		do{
			if (aux == 1){
				do{
				printf("Voce inseriu um dado incorreto. Deseja\nOpcao 1: Tentar novamente\nOpcao 2: Recuperar senha\n\nInsira a opcao: ");
				scanf("%d",&opcaoErro);
					if (opcaoErro == 2)
						recuperacao();
					}
					while(opcaoErro < 1 || opcaoErro > 2);
				}
				retornoLogin = Logar();
				aux = 1;
				}
			while (retornoLogin == -1);
		return(retornoLogin);
	}

int menuComum(){
	int opcao;
	do{
	printf("O que voce deseja fazer?\n1. Consultar Preço\n2.Fazer um pedido\n3. Consultar estado de um pedido\n4. Deslogar\n\nInsira a opcao: ");
	scanf("%d",&opcao);
	}
	while(opcao > 4 || opcao < 1);
	return(opcao);
}

int menuItem(){

	int cod_item, achou, opcao=0;
	mostrarListaItens(); /*estara no modulo_itens*/
	do{
		printf("Insira o codigo do item que você deseja");
		scanf("%d",cod_item);

		achou = procuraListaItens(cod_item); /*estara na modulo_itens_modifiquei pro padrao*/

		if (!achou){
			printf("O item que voce selecionou não existe. Deseja fazer nova consulta?\n1. Sim\n2. Não\n\nInsira sua opção: "); 
			scanf("%d", &opcao);
		}
		else
			return(cod_item);
	}
	while (opcao==1);
}

int funcaoContinuar(){

	int opcao;
	do{
		printf("Deseja continuar realizando a operacao atual?n1. Sim\n2. Não\n\nInsira sua opção: ");
		scanf("%d",&opcao);
		if(opcao == 1)
			return (1);
		else if(opcao == 2)
			return 0;
		else
			printf("Selecione uma opcao valida");
	}while (opcao < 1 || opcao > 2);
}

void mostrarPreco(int preco_item){
	printf("O preco do item requisitado e: ",preco_item);
}

item menuInserirItem(){
	item novo_item, achou;
	do{
		printf("Insira a categoria do novo item: ");
		scanf(" %[^\n]s",&novo_item.categoria);
		getchar();
		if(novo_item.categoria < 0)
			printf("Insira uma categoria valida");
	} while(novo_item.categoria < 0);
	do{
		printf("Insira o codigo do novo item: ");
		scanf("%d",&novo_item.codigo);
		getchar();
		achou = pesquisaListaItens(novo_item.codigo);
		if (achou){
			printf("Voce precisa inserir um codigo unico (que nao seja de nenhum dos outros produtos");
		}
	} while (achou);

	do{
		printf("Insira o preco do novo item (maximo de 5000 reais):");
		scanf("%f",&novo_item.preco);
		getchar();
		if(novo_item.preco > 5000 || novo_item.preco < 0)
			printf("Insira um preco valido");
	}
	while(novo_item.preco > 5000 || novo_item.preco < 0);
	do{
		printf("Insira a quantidade do item que você deseja: ");
		scanf("%d", &novo_item.quantidade);
	} while(novo_item.quantidade < 0);
	getchar();
	return(novo_item);
}

int menuAlterarUsuario(usuario **plista_usuarios, usuario **p_usuario_atual){
	int achou, opcao;
	char cpf[11];

	do{
		mostrarListaUsuarios(&plista_usuarios);
		printf("Digite o CPF do usuario que voce deseja alterar: ");
		scanf(" %[^\n]s",cpf);
		getchar();
		if (!achou){
			printf("Insira um CPF de um usuario valido");
		}
	}
	while (!achou);
	do{
		printf("Selecione o que voce deseja fazer com o usuario.\n1. Alterar CPF\n2.Alterar Senha\n3.Alterar Nome\n4. Excluir usuario\n\nSelecione a opcao: ");
		scanf("%d",&opcao);
		if (opcao < 1 || opcao > 4)
			printf("\nInsira uma opcao valida.\n");
	}
	while (opcao < 1 || opcao > 4);
	apontarListaUsuarios(&p_usuario_atual, &cpf);
	return(opcao);
}

int menuAlterarProduto(){
	int opcao;
	do{
		printf("\nSelecione o que voce deseja fazer com os itens.\n1. Inserir novo item\n2.Alterar preco de item existente\n3.Alterar descricao de item\n4. Quantidade de itens no estoque\n5. Sair\n\nSelecione a opcao: ");
		scanf("%d",opcao);
		if (opcao < 1 || opcao > 5)
			printf("Insira uma opcao valida\n")

	} while(opcao < 1 || opcao > 5);
	return (opcao);
}

int menuEstadoPedido(usuario **p_usuario_atual, pedido **pedido_usuario_atual){
	int cod_pedido, achou;
	do{
		mostrarListaPedidos(&p_usuario_atual);
		printf("Insira o codigo do pedido que voce deseja saber o estado: ");
		scanf("%d",cod_pedido);
		achou = procuraPedidos(cod_pedido);
		if (!achou){
			printf("\nInsira um codigo de pedido valido");
		}
	}
	while(!achou);
	return(cod_pedido);
}

/*
 * REVER ESSA FUNÇÃO
 */

float menuInserirPedido(itens_pedido **pedido_atual){
	int precoItens=0, qtdItens, codigo_item, cont=0, continuar;
	char data[10];
	mostrarListaDeItens();
	do{
		cont++;
		if (cont>30)
			printf ("ATENCAO: nao eh possivel adidionar mais itens a esse pedido. Caso queira adicionar mais itens, faca  um novo pedido\n")

		printf ("Digite o codigo do item a ser inserido no pedido: ");
		scanf ("%d", &codigo_item);
		printf ("Qual a quantidade desse item voce deseja pedir? ");
		scanf ("%d",&qtdItens);
		printf ("Entre com a data de hoje: (dd/mm/aaaa)  exemplo: 11/03/1990\n")
		getchar();
		scanf ("%s", data);
		precoItens = precoItens + consultarPrecoItem (codigo_item);
		if (precoItens > 25000) {
			printf("ATENCAO: seu pedido excedeu o preco maximo de 2500 reais. O ultimo sera retirado.\nCaso deseja pedir outros itens, fazer um novo pedido\n");
			precoItens = precoItens - consultarPrecoItem (codigo_item);
		} else
		insereListaItensPedidos (&pedido_atual, codigo_item, qtdItens, &data);
		/*
		 * a cada chamada dessa funcao, vai ter um novo item de pedido prra esse pedido contendo apenas:
		 * ponteiro pro item requerido e a quantidade desse item requerida, saca?
		 * dai quando retornar pra mim, eu vou inserir esse pedido na lista de pedidos do usuario :P
		 */
		continuar = fucaoContinuar ();
	} while((precoItens <= 25000)&&(continuar==1)&&(cont<=30));
	return precoItens;
} 


void mostrarEstadoPedido(int estado_pedido){
	if (estado_pedido)
		printf("Pedido processado");
	else
		printf("Pedido nao-processado");
}

int ComecarLogin(){
    int retornoLogin, tipo_usuario, opcaoPrincipal=0, opcaoErro=0, opcaoCadastro=0,aux=0, deslogar;
	do{
		do{
			printf("**********Menu Principal**********\n\nOpcao 1: Logar\nOpcao 2: Cadastrar\nOpcao 3: Recuperar senha\nOpcao 4: Sair do programa\n\nInsira a opcao: ");
			scanf("%d",&opcaoPrincipal);
		}
		while(opcaoPrincipal > 3 || opcaoPrincipal < 1);
		getchar();
		switch(opcaoPrincipal){
			case 1:
				tipo_usuario = caso1ComecarLogin(); /*O retorno da função será o tipo do usuário que conseguiu logar*/
				deslogar = tarefasUsuario(tipo_usuario);
				getchar();
			break;

			case 2:
				cadastrarUsuario();
				printf("Cadastro realizado com sucesso!");
				printf("\nDeseja logar?\n1. Sim\n2. Nao\n\nInsira sua opcao: ");
				scanf("%d",opcaoCadastro);
				if (opcaoCadastro == 1)
					caso1ComecarLogin();
				else
					deslogar = 0;
			break;

			case 3:

			break;

			case 4:
				return(0);
			break;
		}
	}
	while (deslogar == 0);
}

float menuAlterarPreco (){
	float preco;
	do{
		printf("Insira o preco: ");
		scanf("%f",&preco);
		if (preco > 5000 || preco < 0)
			printf("Atencao: Insira um preco valido.");
	}
	while (preco > 5000 || preco < 0);
	return (preco);

}

void menuAlterarDescricao(char **nova_descricao){
	printf("Insira a nova descircao");
	scanf(" %[^\n]s",nova_descricao);
}

int menuAlterarQuantidade(){
	int qtd;
<<<<<<< HEAD

=======
	
>>>>>>> f4401ebcc2f090615bd281eb07822bee3434983a
	do{
		printf("Insira a quantidade: ");
		scanf("%d",&qtd);
		if(qtd < 0)
			printf("A quantidade tem de ser maior que zero!");
	}
	while(qtd < 0);
	return (qtd);
}

<<<<<<< HEAD
int processarPedido (usuario **posicao_usuario, int **cod_pedido){
	mostraListaPedidos(&posicao_usuario);
	int opcao;
=======
void processarPedido (usuario **posicao_usuario, int **cod_pedido){
	mostraListaPedidos(&posicao_usuario);
>>>>>>> f4401ebcc2f090615bd281eb07822bee3434983a
	do{
		printf("Insira o codigo do produto que voce deseja processar o pedido: ");
		scanf("%d",&cod_pedido);
		if (cod_pedido < 0)
			printf("Insira um codigo valido");
		}
	while (cod_pedido < 0);
	do{
		printf("Voce deseja realmente processar esse pedido? Digite\n1. para Sim\n2 para Nao\n\nInsira sua opcao: ");
		scanf("%d",&opcao);
		if (opcao == 1){
			return 1;
		}
		if (opcao == 2){
			return 0;
		}
<<<<<<< HEAD
		else
=======
		else 
>>>>>>> f4401ebcc2f090615bd281eb07822bee3434983a
			printf("Favor digitar 1 ou 2!");
		}
	while (opcao != 1 || opcao != 2);
}
