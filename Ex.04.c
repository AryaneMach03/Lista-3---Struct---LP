# include  < stdio.h >
# include  < string.h >

 estrutura typedef
{
	char nome[ 50 ];
	potência flutuante ;
	tempo de flutuação ;	
}telétros;

int qtd = 0 ;
// --------------------------------------------

void  salvaArquivo (teletros el[])
{
	ARQUIVO *arq;
	int = 0 ;
	arq = fopen ( " dadosEletro.txt " , " wb " );
	fwrite (&el[i], sizeof (teletros), qtd, arq);
	printf ( " Os Dados foram salvos com sucesso! \n " );
	fclose (arq);

}
// --------------------------------------------

void  carregaArquivo (teletros el[])
{
	ARQUIVO *arq;
	arq = fopen ( " dadosEletro.txt " , " rb " );
	if (arq == NULL ){
		printf ( " Arquivo de alunos nao encontrado! \n " );
		retorno ;
	}
	while ( fread (&el[qtd], sizeof (teletros), 1 , arq) > 0 )
		qtd++;
	printf ( " Dados carregados com sucesso! \n " );
	fclose (arq);
}
// --------------------------------------------

void  addEletro (teletros el[])
{
	printf ( " Nome do eletrodoméstico: " );
	fflush (stdin);
	obtém (el[qtd]. nome );
	
	printf ( " Potencia do eletro (em kW): " );
	fflush (stdin);
	scanf ( " %f " , &el[qtd]. potência ) ;

	printf ( " Tempo de uso diario (em horas): " );
	fflush (stdin);
	scanf ( " %f " , &el[qtd]. tempo );
	
	qtd++;
}
// --------------------------------------------

void  listaEletros (teletros el[])
{
	
	for ( int i = 0 ; i < qtd; i++)
	{
		printf ( " *** Eletro %d *** \n " , i + 1 );
		printf ( " Nome: %s \n " , el[i] .nome );
		printf ( " Potencia(kW): %.2f \n " , el[i]. potencia );
		printf ( " Uso diario(horas): %.2f \n " , el[i]. tempo );
		printf ( " ------------------------ \n " );
	}
	
}
// --------------------------------------------

int  filtraNome (teletros el[], char nomeConsulta[ 50 ])
{
	char nomeAux[ 50 ];
	int res = - 1 ;
	
	for ( int i = 0 ; i < qtd; i++)
	{
		strcpy (nomeAux, el[i]. nome ); // copiando do vetor para aux
		strupr (nomeAux); // maiúsculas
		if ( strcmp (nomeConsulta, nomeAux) == 0 )
		{
			printf ( " *** Eletro %d *** \n " , i + 1 );
			printf ( " Nome: %s \n " , el[i] .nome );
			printf ( " Potencia(kW): %.2f \n " , el[i]. potencia );
			printf ( " Uso diario(horas): %.2f \n " , el[i]. tempo );
			printf ( " ------------------------ \n " );
			res = 0 ;
		}
	}
	
	retorno res;	
}
// --------------------------------------------

int  filtraCons (teletros el[], float gasto)
{
	int res = 1 ;
	custo de flutuação ;
	
	for ( int i = 0 ; i < qtd; i++)
	{
		custo = el[i]. potência * el[i]. ritmo ;
		if (gasto <= custo)
		{
			printf ( " *** Eletro %d *** \n " , i + 1 );
			printf ( " Nome: %s \n " , el[i] .nome );
			printf ( " Potencia(kW): %.2f \n " , el[i]. potencia );
			printf ( " Uso diario(horas): %.2f \n " , el[i]. tempo );
			printf ( " ------------------------ \n " );
			res = 0 ;
		}
	}
	
	retorno res;
}
// --------------------------------------------

void  consumoTotal (teletros el[])
{
	float preco = 0.0 ;
	consumo flutuante = 0,0 ;
	
	for ( int i = 0 ; i < qtd; i++)
	{
		preco += el[i]. potência * el[i]. ritmo ;
		consumo += el[i]. potência ;
	}
	
	printf ( " Consumo diário: %.2f kW \n " , consumo);
	printf ( " Consumo mensal: %.2f kW \n " , consumo * 30,0 );
	printf ( " \n " );
	printf ( " Custo diario: R$ %.2f \n " , preco);
	printf ( " Custo mensal: R$ %.2f \n " , preço * 30,0 );
	
}
// --------------------------------------------

int  menu ()
{
	int opcao;
	
	printf ( " *** Sistema de energia *** \n " );
	printf ( " 1 - Cadastrar eletrodomestico \n " );
	printf ( " 2 - Listar eletrodomesticos \n " );
	printf ( " 3 - Procurar por nome \n " );
	printf ( " 4 - Procurar por gasto \n " );
	printf ( " 5 - Calcular gasto diario e mensal \n " );
	printf ( " 6 - Salvar dados \n " );
	printf ( " 7 - Carregar dados \n " );
	printf ( " 0 - Sair \n " );
	printf ( " Opcao: " );
	scanf ( " %d " , &opcao);
	printf ( " \n " );
	retornar opcao;
}
// --------------------------------------------

int  principal ()
{
	teletros eletros[ 100 ];
	char nomeBusca[ 50 ];
	custo de flutuação ;
	int op, res;
	
	Faz
	{
		op = cardápio ();
		interruptor (op)
		{
			caso  1 :
				addEletro (eletros);
				quebrar ;
			caso  2 :
				listaEletros (eletros);
				quebrar ;
			caso  3 :
				printf ( " Insira o nome do eletrodomestico: " );
				fflush (stdin);
				obtém (nomeBusca);
				strupr (nomeBusca);
				res = filtraNome (eletros, nomeBusca);
				if (res == - 1 )
				{
					printf ( " \n Eletro nao encontrado! " );
				}
				quebrar ;
			caso  4 :
				printf ( " Insira o gasto(em R$): " );
				scanf ( " %f " , &custo);
				filtraCons (eletros, custo);
				quebrar ;
			caso  5 :
				consumoTotal (eletros);
				quebrar ;
			caso  6 :
				salvaArquivo (eletros);
				quebrar ;
			caso  7 :
				carrega Arquivo (eletros);
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
