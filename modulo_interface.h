

int funcaoContinuar (); /*retorna 1 pra sim e 0 para nao */

void insereNome(char **nome);

void insereSenha(char **senha);

void insereCPF(char **cpf);

int escolheUsuario();

int Logar();

int caso1ComecarLogin();

int menuItem();

void mostrarPreco(int preco_item);

int menuComum(); /*menu de opcoes para um usuario comum */

item menuInserirItem (); /*retorna struct do novo item a ser adicionado */

int menuAlterarProduto (); /*retorna a opcao de alteracao*/

void deletarUsuario (usuario *plista_usuarios, char **cpf_usuario_deletado);

int menuAlterarUsuario (usuario **plista_usuarios, usuario **p_usuario_atual); /*retorna o CPF do usuario a ser alterado */

void mostrarEstadoPedido (int estado_pedido);

int menuEstadoPedido (usuario **p_usuario_atual, pedido **pedido_usuario_atual); /*retorna o numero do pedido para analisar estado */

void menuAlterarPreco (float **novo_preco); /*mostra lista de itens, pede pra digitar codigo do item e depois o novo preço. R
etorna o novo preço */

void menuAlterarQtd (int *nova_quantidade);

void menuAlterarDescricao (char **nova_descricao);

 int processarPedido (usuario **posicao_usuario, int **cod_pedido);
 /*chama a funcao mostraListaPedidos passando o ponteiro do usuario e pede pro usuario digitar o cod do pedido a ser alterado
  * dai você pergunta se ele quer ou nao processar o pedido e retorna 1 para sim e 0 para nao!
  */
