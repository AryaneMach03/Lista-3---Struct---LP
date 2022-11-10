# include  <stdio.h>
# include <string.h>
 estrutura typedef; {
	char nome[ 40 ];
	char genero[ 40 ];
	int ocupantes;
	classificação interna ;
}tbanda;
int qtd= 0 ; // controla a posição de cadastro no vetor
// --------------
void  addBanda (tbanda b[]){
	printf ( " Nome da banda: " );
	fflush (stdin); // limpa o buffer do teclado
	obtém (b[qtd]. nome );
	
	printf ( " Gênero da banda: " );
	fflush (stdin); // limpa o buffer do teclado
	obtém (b[qtd]. genero );
	
	printf ( " Quantidade de inquilinos: " );
	scanf ( " %d " ,&b[qtd]. integrantes );
	printf ( " Ranking da banda: " );
	scanf ( " %d " ,&b[qtd]. ranking );
	
	qtd++;
}
// --------------
void  listaBandas (tbanda b[])
	{
		int ;
		for (i= 0 ;i<qtd;i++){
			printf ( " *** Banda %d *** \n " ,i+ 1 );
			printf ( " Nome: %s \n " ,b[i] .nome );
			printf ( " Gênero: %s \n " ,b[i]. genero );
			printf ( " Integrantes: %d \n " ,b[i]. integrantes );
			printf ( " Classificação: %d \n " ,b[i]. classificação );
			printf ( " ------------------------ \n " );
	} // fim para
}
// -----------------------------
void  listaRanking (tbanda b[], int busca){
	int ;
	for (i= 0 ;i<qtd;i++){
		if (busca==b[i]. classificação ){
			printf ( " *** Banda %d *** \n " ,i+ 1 );
			printf ( " Nome: %s \n " ,b[i] .nome );
			printf ( " Gênero: %s \n " ,b[i]. genero );
			printf ( " Integrantes: %d \n " ,b[i]. integrantes );
			printf ( " Classificação: %d \n " ,b[i]. classificação );
			printf ( " ------------------------ \n " );
		} // fim se
	} // fim para
}
// --------------------------
void  listaGenero (tbanda b[], char generoBusca[ 40 ]){
	int ;
	char generoAux[ 40 ];
	for (i= 0 ;i<qtd;i++){
		strcpy (generoAux,b[i] .gênero ); // copiando do vetor para aux
		strupr (generoAux); // maiúsculas
		if ( strcmp (generoBusca,generoAux)== 0 ){
			printf ( " *** Banda %d *** \n " ,i+ 1 );
			printf ( " Nome: %s \n " ,b[i] .nome );
			printf ( " Gênero: %s \n " ,b[i]. genero );
			printf ( " Integrantes: %d \n " ,b[i]. integrantes );
			printf ( " Classificação: %d \n " ,b[i]. classificação );
			printf ( " ------------------------ \n " );
		} // fim se
	} // fim para
}
// --------------------------
int  listaNome (tbanda b[], char nomeBusca[ 40 ]){
	int ;
	char nomeAux[ 40 ];
	for (i= 0 ;i<qtd;i++){
		strcpy (nomeAux,b[i].nome ) ; // copiando do vetor para aux
		strupr (nomeAux); // maiúsculas
		if ( strcmp (nomeBusca,nomeAux)== 0 ){
			printf ( " *** Banda %d *** \n " ,i+ 1 );
			printf ( " Nome: %s \n " ,b[i] .nome );
			printf ( " Gênero: %s \n " ,b[i]. genero );
			printf ( " Integrantes: %d \n " ,b[i]. integrantes );
			printf ( " Classificação: %d \n " ,b[i]. classificação );
			printf ( " ------------------------ \n " );
				retorno eu; // retornando o índice
		} // fim se
	
	} // fim para
	retorno - 1 ; // não existe
}
// --------------------------
void  removeBanda (tbanda b[], char nomeBanda[ 40 ]){
	int posição, resp;
	posição = listaNome (b,nomeBanda);
	if (posicao == 1 ){
		printf ( " Banda nao encontrada! " );
		retorno ;
	} // fim se
	printf ( " Tem certeza que deseja remover a banda? [1-Sim | 2-Nao] " );
	scanf ( " %d " , &resp);
	if (resp== 1 ){
	b[posicao] = b[qtd- 1 ]; // sobrepondo a ultima banda
	qtd--;
} // fim se
senão 
printf ( " Operação morta " );
}
// --------------------------
void  alteraBanda (tbanda b[], int qtd){
	
	printf ( " Nome da banda: " );
	fflush (stdin);
	obtém (b[qtd]. nome );
	
	printf ( " Gênero da banda: " );
	fflush (stdin);
	obtém (b[qtd]. genero );
	
	printf ( " Qtde de inquilinos: " );
	fflush (stdin);
	scanf ( " %d " , &b[qtd]. integrantes );
	
	printf ( " Ranking da banda: " );
	fflush (stdin);
	scanf ( " %d " , &b[qtd]. ranking );
	
}
// --------------------------
void  salvaArquivo (tbanda bandas[]){
	ARQUIVO *arq;
	int = 0 ;
	arq= fopen ( " dadosBandas.txt " , " wb " );
	fwrite (&bandas[i], sizeof (tbanda),qtd,arq);
	printf ( " Dados salvos com sucesso \n " );
	fclose (arq);
}
// -----------------------------
void  carregaArquivo (tbanda bandas[]){
	ARQUIVO *arq;
	arq= fopen ( " dadosBandas.txt " , " rb " );
	if (arq== NULL ){
	  printf ( " Arquivo nao encontrado:( \n " );
	  retorno ;
	  } // fim se
	 while ( fread (&bandas[qtd], sizeof (tbanda), 1 ,arq) > 0 )
	      qtd++;  
	 printf ( " Dados carregados com sucesso ! \n " );
	fclose (arq);
}
int  menu (){
	int opcao;
	printf ( " ***Sistema de Cadastro Rock4You*** \n " );
	printf ( " 1- Cadastrar \n " );
	printf ( " 2- Listar \n " );
	printf ( " 3- Filtro por ranking \n " );
	printf ( " 4- Filtro por genero \n " );
	printf ( " 5- Filtro por nome \n " );
	printf ( " 6- Excluir banda \n " );
	printf ( " 7-Alterar banda \n " );
	printf ( " 0 - Sair \n " );
	scanf ( " %d " ,&opcao);
	retornar opcao;
} // fim do menu
// ------------------
int  main (){
	tbanda bandas[ 100 ];
	int opcao, busca;
	char generoBusca[ 40 ], nomeBusca[ 40 ];
	carrega Arquivo (bandas);
	fazer {
		opcao= menu ();
		switch (opcao){
			caso  1 : addBanda (bandas);
			 quebrar ;
			caso  2 : listaBandas (bandas);
			 quebrar ;
			case  3 : printf ( " Filtrar pelo ranking: " );
					scanf ( " %d " ,&busca);
					listaRanking (bandas,busca);
			 quebrar ;
			case  4 : printf ( " Filtro por gênero: " );
					fflush (stdin); // limpa buffer
					recebe (generoBusca);
					strupr (generoBusca); // maiúsculas
					listaGenero (bandas,generoBusca);
			 quebrar ;	
			case  5 : printf ( " Filtro por nome: " );
					fflush (stdin); // limpa buffer
					obtém (nomeBusca);
					strupr (nomeBusca); // maiúsculas
						if ( listaNome (bandas, nomeBusca)==- 1 )
						printf ( " Banda nao encontrada! \n " );
						
			 quebrar ;	
			case  6 : printf ( " Nome da banda: " );
					fflush (stdin); // limpa buffer
					obtém (nomeBusca);
					strupr (nomeBusca); // maiúsculas
					removeBanda (bandas, nomeBusca);
					printf ( " Banda excluida com sucesso! " );
			 quebrar ;	
			case  7 : printf ( " Codigo da banda para alteração: " );
					scanf ( " %d " , &busca);
					alteraBanda (bandas, (busca - 1 ));
			 quebrar ;
			case  0 : printf ( " Saindo... \n " );
					salvaArquivo (bandas);
			 quebrar ;
			default : printf ( " Opcao invalida!!! \n " );  
		} // troca de fim
	  pegar (); // pausa
	  sistema ( " cls " ); // limpa tela	
	} while (opcao!= 0 );
	retorna  0 ;
	
} // fim principal
