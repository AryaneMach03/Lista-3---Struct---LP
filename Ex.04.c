# include  < stdio.h >
# include  < string.h >

 estrutura typedef
{
	char nome[ 50 ];
	pot�ncia flutuante ;
	tempo de flutua��o ;	
}tel�tros;

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
	printf ( " Nome do eletrodom�stico: " );
	fflush (stdin);
	obt�m (el[qtd]. nome );
	
	printf ( " Potencia do eletro (em kW): " );
	fflush (stdin);
	scanf ( " %f " , &el[qtd]. pot�ncia ) ;

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
		strupr (nomeAux); // mai�sculas
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
	custo de flutua��o ;
	
	for ( int i = 0 ; i < qtd; i++)
	{
		custo = el[i]. pot�ncia * el[i]. ritmo ;
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
		preco += el[i]. pot�ncia * el[i]. ritmo ;
		consumo += el[i]. pot�ncia ;
	}
	
	printf ( " Consumo di�rio: %.2f kW \n " , consumo);
	printf ( " Consumo mensal: %.2f kW \n " , consumo * 30,0 );
	printf ( " \n " );
	printf ( " Custo diario: R$ %.2f \n " , preco);
	printf ( " Custo mensal: R$ %.2f \n " , pre�o * 30,0 );
	
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
	custo de flutua��o ;
	int op, res;
	
	Faz
	{
		op = card�pio ();
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
				obt�m (nomeBusca);
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
			padr�o :
				printf ( " Opcao invalida!!! \n " );
				quebrar ;
		}
		pegar ();
		sistema ( " cls " );
	} while (op != 0 );
	
}
