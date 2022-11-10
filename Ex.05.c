# inclui  < stdio.h >
# inclui  < string.h >

 estrutura typedef
{
	char nomePessoa[ 30 ];
	char dados[ 20 ];
	char emprestado;
}tdados;

 estrutura typedef
{
	char titulo[ 30 ];
	char console[ 15 ];
	em ano;
	classificação interna ;
	tdata emprestimo;
}tjogo;

int qtd = 0 ;

// --------------------------------------------

void  addJogo (tjogo jg[]){
	printf ( " Título do jogo: " );
	fflush (stdin);
	obtém (jg[qtd]. titulo );
	
	printf ( " Console: " );
	fflush (stdin);
	obtém (jg[qtd]. console );
	
	printf ( " Ano de Lançamento: " );
	fflush (stdin);
	scanf ( " %d " , &jg[qtd]. ano );
	
	printf ( " Classificação: " );
	fflush (stdin);
	scanf ( " %d " , &jg[qtd]. ranking );
	
	jg[qtd]. emprestimo . emprestado = ' N ' ;
	
	qtd++;
}
// --------------------------------------------
void  listaJogos (tjogo jg[])
{
	
	for ( int i = 0 ; i < qtd; i++)
	{
		printf ( " *** Jogo %d *** \n " , i+ 1 );
		printf ( " Titulo: %s \n " , jg[i]. titulo );
		printf ( " Console: %s \n " , jg[i]. console );
		printf ( " Ano de Publicacao: %d \n " , jg[i]. ano );
		printf ( " Classificação: %d \n " , jg[i]. classificação );
		printf ( " Emprestado: %c \n " , jg[i]. emprestimo . prolongado );
		printf ( " ------------------------ \n " );
	}
	
}
// --------------------------------------------
void  fazEmprestimo (tjogo jg[], int cod)
{
	printf ( " Nome da pessoa: " );
	fflush (stdin);
	gets (jg[cod - 1 ]. emprestimo . nomePessoa );
	
	printf ( " Dados do Emprestimo: " );
	fflush (stdin);
	obtém (jg[cod - 1 ]. emprestimo . data );
	
	jg[cod - 1 ]. emprestimo . guardado = ' S ' ;	
}
// --------------------------------------------

int  filtraTitulo (tjogo jg[], char titulo[ 30 ])
{
	char tituloAux[ 30 ];
	int res = - 1 ;
	
	for ( int i = 0 ; i < qtd; i++){
		strcpy (tituloAux, jg[i]. titulo ); // copiando do vetor para aux
		strupr (tituloAux); // maiúsculas
		if ( strcmp (titulo, tituloAux) == 0 )
		{
			printf ( " ***Jogo %d *** \n " , i+ 1 );
			printf ( " Titulo: %s \n " , jg[i]. titulo );
			printf ( " Console: %s \n " , jg[i]. console );
			printf ( " Ano de Publicacao: %d \n " , jg[i]. ano );
			printf ( " Classificação: %d \n " , jg[i]. classificação );
			printf ( " Emprestado: %c \n " , jg[i]. emprestimo . prolongado );
			printf ( " ------------------------ \n " );
			res = 0 ;
		}
	}
	
	retorno res;
	
}
// --------------------------------------------
int  filtraConsole (tjogo jg[], char console[ 15 ])
{
	char consAux[ 15 ];
	int res = - 1 ;
	
	for ( int i = 0 ; i < qtd; i++){
		strcpy (consAux, jg[i]. console ); // copiando do vetor para aux
		strupr (consAux); // maiúsculas
		if ( strcmp (console, consAux) == 0 )
		{
			printf ( " ***Jogo %d *** \n " , i+ 1 );
			printf ( " Titulo: %s \n " , jg[i]. titulo );
			printf ( " Console: %s \n " , jg[i]. console );
			printf ( " Ano de Publicacao: %d \n " , jg[i]. ano );
			printf ( " Ranking: %.2f \n " , jg[i]. ranking );
			printf ( " Emprestado: %c \n " , jg[i]. emprestimo . prolongado );
			printf ( " ------------------------ \n " );
			res = 0 ;
		}
	}
	
	retorno res;
	
}
// --------------------------------------------

int  listaEmp (tjogo jg[])
{
	int res = - 1 ;
	
	for ( int i = 0 ; i < qtd; i++){
		if (jg]. emprestimo . ' emprestado == ' S )
		{
			printf ( " Jogo: %s \n " , jg[i]. titulo );
			printf ( " Emprestado para: %s \n " , jg[i]. emprestimo . nomePessoa );
			printf ( " Dados do emprestimo: % s \n " , jg[i] .emprestimo.data ) ;
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
	
	printf ( " ***Biblioteca de Jogos*** \n " );
	printf ( " 1 - Cadastrar o jogo \n " );
	printf ( " 2 - Listar jogos \n " );
	printf ( " 3 - Procurar por titulo \n " );
	printf ( " 4 - Filtrar pelo console \n " );
	printf ( " 5 - Fazer um emprestimo \n " );
	printf ( " 6 - Listar emprestimos \n " );
	printf ( " 0 - Sair \n " );
	printf ( " Opcao: " );
	scanf ( " %d " , &opcao);
	printf ( " \n " );
	retornar opcao;
}
// --------------------------------------------

void  main (){
	
	tjogo jogos[ 100 ];
	char tituloBusca[ 30 ], consoleBusca[ 15 ];
	int emp, op, res;
	
	fazer {
		op = cardápio ();
		mudar (op){
			caso  1 :
				addJogo (jogos);
				quebrar ;
			caso  2 :
				listaJogos (jogos);
				quebrar ;
			caso  3 :
				printf ( " Insira o titulo do jogo: " );
				fflush (stdin);
				recebe (tituloBusca);
				strupr (titulo Busca);
				res = filtraTitulo (jogos, tituloBusca);
				if (res == - 1 )
				{
					printf ( " Jogo nao encontrado! " );
				}
				quebrar ;
			caso  4 :
				printf ( " Insira o nome do console: " );
				fflush (stdin);
				obtém (consoleBusca);
				strupr (console Busca);
				res = filtraConsole (jogos, consoleBusca);
				if (res == - 1 )
				{
					printf ( " Console nao encontrado! " );
				}
				quebrar ;
			caso  5 :
				listaJogos (jogos);
				printf ( " Insira o código do jogo: " );
				scanf ( " %d " , &emp);
				fazEmprestimo (jogos, emp);
				quebrar ;
			caso  6 :
				res = listaEmp (jogos);
				if (res == - 1 )
				{
					printf ( " Não há jogos comprados! " );
				}
				quebrar ;
			caso  0 :
				printf ( " Saindo... \n " );
				quebrar ;
			padrão :
				printf ( " Opcao invalida!!! \n " );
				quebrar ;
		}
		pegar ();
		sistema ( " cls " );
	} while (op != 0 );
	
}
