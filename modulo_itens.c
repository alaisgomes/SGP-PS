/*Arquivo destinado à implementação das funções referentes à manipulação de itens.*/

void InsereListaItens(item **p_itens, item novo_item){
	item *p1;

	p1 = malloc (sizeof (item));
	strcpy (p1->descricao, novo_item.descricao);
	p1->preco = novo_item.preco;
	p1->quantidade= novo_item.quantidade;
	p1->codigo = novo_usuario.codigo;
	p1->categoria = novo_usuario.categoria;


	if (*p_itens == NULL) {
		*p_itens = p1;
		p1->prox_item = NULL;
	} else {
	      p1->prox_item = *p_itens;
	      *p_itens = p1;
	}
	p1 = NULL;
}

