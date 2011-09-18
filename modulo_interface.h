/*Header contendo escopo de funções, estruturas, defines ... referentes à Interface com usuário.*/

item menuInserirItem (); /*retorna struct do novo item a ser adicionado */

int menuAlterarProduto (); /*retorna o codigo do produto a ser alterado */

void deletarUsuario (usuario *plista_usuarios, char **cpf_usuario_deletado);

void mudarNome (char **novo_nome);

void mudarSenha(char **nova_senha);

void mudarCPF (char **novo_CPF);

int menuAlterarUsuario (usuario *plista_usuarios, usuario **p_usuario_atual); /*retorna o CPF do usuario a ser alterado */

void mostrarEstadoPedido (int estado_pedido);

int menuEstadoPedido (usuario **p_usuario_atual, pedido **pedido_usuario_atual); /*retorna o numero do pedido para analisar estado */

int funcaoContinuar (); /*retorna 1 pra sim e 0 para nao */
