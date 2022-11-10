# include  < stdio.h >
# include  < string.h >

 estrutura typedef {
	char titulo[ 30 ];
	char autor[ 15 ];
	em ano;
	int prateleira;
}tlivro;

int qtd = 0 ;
// --------------------------------------------

void  salvaArquivo (tlivro liv[])
{
	ARQUIVO *arq;
	int = 0 ;
	arq = fopen ( " dadosLivros.txt " , " wb " );
	fwrite (&liv[i], sizeof (tlivro), qtd, arq);
	printf ( " Dados salvos com sucesso. \n " );
	fclose (arq);
}
// --------------------------------------------

void  carregaArquivo (tlivro liv[]){
	ARQUIVO *arq;
	arq = fopen ( " dadosLivros.txt " , " rb " );
	if (arq == NULL ){
		printf ( " Arquivo de livros nao encontrado! \n " );
		retorno ;
	}
	while ( fread (&liv[qtd], sizeof (tlivro), 1 , arq) > 0 )
		qtd++;
	printf ( " Dados carregados com sucesso! \n " );
	fclose (arq);
}
// --------------------------------------------
void  addLivro (tlivro liv[])
{
	printf ( " Título do livro: " );
	fflush (stdin);
	obtém (liv[qtd]. titulo );
	
	printf ( " Nome do autor: " );
	fflush (stdin);
	obtém (liv[qtd]. autor );
	
	printf ( " Ano de publicacao: " );
	fflush (stdin);
	scanf ( " %d " , &liv[qtd]. ano );
	
	printf ( " Prateleira: " );
	fflush (stdin);
	scanf ( " %d " , &liv[qtd]. prateleira );
	
	qtd++;
}
// --------------------------------------------

void  listaLivros (tlivro liv[])
{
	
	for ( int i = 0 ; i < qtd; i++)
	{
		printf ( " ***Livro %d *** \n " ,i+ 1 );
		printf ( " Titulo: %s \n " , liv[i]. titulo );
		printf ( " Nome do autor: %s \n " , liv[i]. autor );
		printf ( " Ano de publicacao: %d \n " , liv[i]. ano );
		printf ( " Prateleira: %d \n " , liv[i]. prateleira );
		printf ( " ------------------------ \n " );
	}
	
}
// --------------------------------------------

int  filtraTitulo (tlivro liv[], char tituloConsulta[ 30 ])
{
	char tituloAux[ 40 ];
	int res = - 1 ;
	
	for ( int i = 0 ; i < qtd; i++)
	{
		strcpy (tituloAux, liv[i]. titulo ); // copiando do vetor para aux
		strupr (tituloAux); // maiúsculas
		if ( strcmp (tituloConsulta, tituloAux) == 0 )
		{
			printf ( " ***Livro %d *** \n " ,i+ 1 );
			printf ( " Titulo: %s \n " , liv[i]. titulo );
			printf ( " Nome do autor: %s \n " , liv[i]. autor );
			printf ( " Ano de publicacao: %d \n " , liv[i]. ano );
			printf ( " Prateleira: %d \n " , liv[i]. prateleira );
			printf ( " ------------------------ \n " );
			res = 0 ;
		}
	}
	
	retorno res;
	
}
// --------------------------------------------
int  filtraAno (tlivro liv[], int anoCons)
{
	int res = - 1 ;
	
	for ( int i = 0 ; i < qtd; i++)
	{
		if (liv[i]. ano >= anoCons)
		{
			printf ( " ***Livro %d *** \n " ,i+ 1 );
			printf ( " Titulo: %s \n " , liv[i]. titulo );
			printf ( " Nome do autor: %s \n " , liv[i]. autor );
			printf ( " Ano de publicacao: %d \n " , liv[i]. ano );
			printf ( " Prateleira: %d \n " , liv[i]. prateleira );
			printf ( " ------------------------ \n " );
			res = 0 ;
		}
	}
	
	retorno res;
}
// --------------------------------------------
int  menu ()
{
	int opcao;
	
	printf ( " *** Estrutura da Livraria *** \n " );
	printf ( " 1 - Cadastrar livro \n " );
	printf ( " 2 - Listar livros \n " );
	printf ( " 3 - Procurar por titulo \n " );
	printf ( " 4 - Filtrar por ano de publicacao \n " );
	printf ( " 0 - Sair \n " );
	printf ( " Opcao: " );
	scanf ( " %d " , &opcao);
	printf ( " \n " );
	retornar opcao;
}
// --------------------------------------------
int  principal ()
{
	tlivro livros[ 100 ];
	int op, res, busca;
	char tituloBusca[ 30 ];
	
	carrega Arquivo (livros);
	
	Faz
	{
		op = cardápio ();
		interruptor (op)
		{
			caso  1 :
				addLivro (livros);
				quebrar ;
			caso  2 :
				listaLivros (livros);
				quebrar ;
			caso  3 :
				printf ( " Título para pesquisa: " );
				fflush (stdin);
				recebe (tituloBusca);
				strupr (titulo Busca);
				res = filtraTitulo (livros, tituloBusca);
				if (res == - 1 )
				{
					printf ( " Livro nao encontrado! " );
				}
				quebrar ;
			caso  4 :
				printf ( " Insira o ano minimo para publicacao: " );
				scanf ( " %d " , &busca);
				res = filtraAno (livros, busca);
				if (res == - 1 )
				{
					printf ( " Nao ha livros publicados a partir desse ano! " );
				}
				quebrar ;
			caso  0 :
				printf ( " Saindo... \n " );
				salvaArquivo (livros);
				quebrar ;
			padrão :
				printf ( " Opcao invalida!!! \n " );
				quebrar ;
		}
		pegar ();
		sistema ( " cls " );
	} while (op != 0 );
}
