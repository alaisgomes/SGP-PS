/*Arquivo destinado à implementação das funções referentes à manipulação da interface.*/
/*Arquivo destinado à implementação das funções referentes à manipulação da interface.*/
#include <stdio.h>
#include <string.h>

void insereCPF(char *cpf){
        int aux = 0;
        do{
            if(aux==1)
            printf("\nCPF Invalido");
            printf("\nInsira seu CPF: ");
            scanf(" %s[^\n]",cpf);
            getchar();
            aux = 1;
        }
        while(cpf[11] != '\0' && cpf[11] != '#');
}

void insereNome(char *nome){
            printf("Insira seu nome: ");
            scanf(" %50[^\n]",nome);
            getchar();
}

void insereSenha(char *senha){
            printf("Insira sua senha\n(so serao lidos os primeiros 5 caracteres): ");
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
    insereCPF(cpf);
    insereNome(nome);
    insereSenha(senha);
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
    mostrarListaDeItens(); /*estara no modulo_itens*/
    do{
        printf("Insira o codigo do item que você deseja");
        scanf("%d",cod_item);
        achou = procuraListaDeItens(cod_item); /*estara na modulo_itens*/
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
            return 1;
        if(opcao == 2)
            return 0;
        else
            printf("Selecione uma opcao valida");
    }while (opcao < 1 || opcao > 2);
}

void mostrarPreco(int preco_item){
    printf("O preco do item requisitado e: ",preco_item);
}


menuPedido(/*ponteiro usuario*/ /*ponteiro pedido*/){

}

item menuInserirItem( /*lista de usuarios*/ , /*ponteiro do usuario que se deseja alterar _INTEFACE*/){

}

menuAlterarUsuario(){

}

mudarCPF(){

}

mudarNome(){

}

deletarUsuario(){

}

menuAlterarProduto(){

}

void menuInserirPedido(/*ponteiro da lista de pedidos*/){
    int precoItens=0, qtdItens, i, itensPedido[30];

    mostrarListaDeItens();
    do{
        do{
            printf("Selecione a quantidade de itens que você deseja adicionar o pedido (maximo de 30): ");
            scanf("%d",&qtdItens);
            if (qtdItens > 30 || qtdItens<1)
                printf("\nInsira uma quantidade valida de itens");
        }
        while (qtdItens < 30 && qtdItens > 1);
        for(i=0;i<(qtdItens-1);i++){
            printf("Entre com o codigo do %do produto que voce deseja\n", (i+1));
            scanf("%d",&itensPedido[i]);
            precoItens = precoItens + consultarPrecoItem(itensPedido[i]);
            getchar();
        }
        if (precoItens > 2500)
    }       printf("Atencao, seus pedidos excederam o valor maximo de 2500 reais, selecione novamente a quantidade de itens que voce deseja adicionar\n");
    while(precoItens > 2500);
}
/*Terminar!*/

void mostrarEstadoPedido(int estado_pedido){
    if (estado_pedido)
        printf("Pedido processado");
    else
        printf("Pedido nao-processado");
}

int ComecarLogin(){
    int retornoLogin, tipo_usuario, opcaoPrincipal=0, opcaoErro=0, opcaoCadastro=0,aux=0;
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
        }
        case 4:
            return(0);
        break;
        while (deslogar == 0);
    }
    while (deslogar == 0)
}
