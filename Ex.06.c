# inclui  < stdio.h >
# inclui  < string.h >

 estrutura typedef
{
	int mes;
	em ano;
}tnasc;

 estrutura typedef
{
	bacalhau int ;
	int leite;
	int alim;
	tnasc nasc;
	char abate;
}tgado;

int qtd = 0 ;

// --------------------------------------------

void  salvaArquivo (tgado gd[])
{
	ARQUIVO *arq;
	int = 0 ;
	arq = fopen ( " dadosGado.txt " , " wb " );
	fwrite (&gd[i], sizeof (tgado), qtd, arq);
	printf ( " Os dados foram salvos com sucesso! \n " );
	fclose (arq);

}
// --------------------------------------------

void  carregaArquivo (tgado gd[])
{
	ARQUIVO *arq;
	arq = fopen ( " dadosGado.txt " , " rb " );
	if (arq == NULL ){
		printf ( " Arquivo de alunos nao encontrado! \n " );
		retorno ;
	}
	while ( fread (&gd[qtd], sizeof (tgado), 1 , arq) > 0 )
		qtd++;
	printf ( " Os dados foram carregados com sucesso! \n " );
	fclose (arq);
}
// --------------------------------------------

void  addGado (tgado gd[], int mes, int ano){
	printf ( " Codigo da cabeca de gado: " );
	fflush (stdin);
	scanf ( " %d " , &gd[qtd]. cod );
	
	printf ( " Litros de leite p/ semana(em litros): " );
	fflush (stdin);
	scanf ( " %d " , &gd[qtd]. leite );
	
	printf ( " Alimentos ingeridos p/ semana(em quilos): " );
	fflush (stdin);
	scanf ( " %d " , &gd[qtd]. alim );
	
	printf ( " Mensagem de Nascimento: " );
	fflush (stdin);
	scanf ( " %d " , &gd[qtd]. nasc . mes );
	
	printf ( " Ano de Nascimento: " );
	fflush (stdin);
	scanf ( " %d " , &gd[qtd]. nasc . ano );
	
	if (gd[qtd]. nasc . mes >= mes && gd[qtd]. nasc . ano <= ano - 5 )
	{
		gd[qtd]. abater = ' S ' ;
		
	} else  if (gd[qtd]. leite < 40 ){
		gd[qtd]. abater = ' S ' ;
	} senão {
		gd[qtd]. abater = ' N ' ;
	}
	
	qtd++;
}

// --------------------------------------------
void  listaGado (tgado gd[])
{
	
	for ( int i = 0 ; i < qtd; i++)
	{
		printf ( " Código: %d \n " , gd[i]. cod );
		printf ( " Leite p/ semana: %d \n " , gd[i]. leite );
		printf ( " Alim. cons. p/ semana: %d \n " , gd[i]. alim );
		printf ( " Mes de nasc.: %d \n " , gd[i]. nasc . mes );
		printf ( " Ano de nasc.: %d \n " , gd[i]. nasc . ano );
		printf ( " ------------------------ \n " );
	}
	
}
// --------------------------------------------

void  calculaLeite (tgado gd[])
{
	int total Leite = 0 ;
	
	for ( int i = 0 ; i < qtd; i++)
	{
		totalLeite += gd[i]. leite ;
	}
	
	printf ( " Total de leite produzido na semana: %d " , totalLeite);
	
}
// --------------------------------------------

void  calculaAlim (tgado gd[])
{
	int totalAlim = 0 ;
	
	for ( int i = 0 ; i < qtd; i++)
	{
		totalAlim += gd[i]. alim ;
	}
	
	printf ( " Total de alimentos consumidos na semana: %d " , totalAlim);
	
}
// --------------------------------------------

void  listaGadoAbate (tgado gd[])
{
	
	for ( int i = 0 ; i < qtd; i++)
	{
		if (gd[i]. abate == ' S ' )
		{	
		printf ( " Código: %d \n " , gd[i]. cod );
		printf ( " Leite p/ semana: %d \n " , gd[i]. leite );
		printf ( " Alim. cons. p/ semana: %d \n " , gd[i]. alim );
		printf ( " Mes de nasc.: %d \n " , gd[i]. nasc . mes );
		printf ( " Ano de nasc.: %d \n " , gd[i]. nasc . ano );
		printf ( " ------------------------ \n " );
		}
	}
	
}
// --------------------------------------------

int  menu ()
{
	int opcao;
	
	printf ( " *** Controle de gado *** \n " );
	printf ( " 1 - Cadastrar cabeca de gado \n " );
	printf ( " 2 - Listar cabeca de gado \n " );
	printf ( " 3 - Calculadora de leite produzido \n " );
	printf ( " 4 - Calcular alimento consumidor \n " );
	printf ( " 5 - Listar animais aptos para o abate \n " );
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
	gado gado[ 100 ];
	int op, mes, ano;
	
	Faz
	{
		op = cardápio ();
		interruptor (op)
		{
			caso  1 :
				printf ( " Por favor, insira mes e ano de compra do gado: " );
				scanf ( " %d%d " , &mes, &ano);
				printf ( " \n " );
				addGado (gado, mes, ano);
				quebrar ;
			caso  2 :
				listaGado (gado);
				quebrar ;
			caso  3 :
				calcular Leite (gado);
				quebrar ;
			caso  4 :
				calculaAlim (gado);
				quebrar ;
			caso  5 :
				listaGadoAbate (gado);
				quebrar ;
			caso  6 :
				salvaArquivo (gado);
				quebrar ;
			caso  7 :
				carrega Arquivo (gado);
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
