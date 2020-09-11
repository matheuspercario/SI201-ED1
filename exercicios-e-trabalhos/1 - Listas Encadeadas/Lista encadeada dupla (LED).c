//---------------------------------------------------------------------------
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
//---------------------------------------------------------------------------

/* -----------------------------------------------------------------------------
Estrutura LISTA ENCADEADA DUPLA
------------------------------------------------------------------------------*/

typedef struct no_ld {
	int dado;
	struct no_ld *prox, *ant;
}  Tno_ld;

// Tabela de código de erros
// 0 - sem erro
// 1 - ...
// 2 - ...


/* -----------------------------------------------------------------------------
Prototipos das funções
------------------------------------------------------------------------------*/
int Inicializar_LD          (Tno_ld **inicio);
int Inicializar2_LD         (Tno_ld **inicio);
int Inserir_inicio_LD       (Tno_ld **inicio, int info);
int Inserir_fim_LD          (Tno_ld **inicio, int info);
int Inserir_meio_LD         (Tno_ld **inicio, int info, int pos);
int Remover_inicio_LD       (Tno_ld **inicio);
int Remover_meio_LD         (Tno_ld **inicio, int pos);
int Remover_fim_LD 			(Tno_ld **inicio);
int Listar_LD               (Tno_ld *inicio);
int Listar_Invertido_LD     (Tno_ld *inicio);
int Obter_dado_LD  			(Tno_ld *inicio, int pos, int *dado);
int Obter_pos_LD            (Tno_ld *inicio, int dado, int *pos);
int Obter_Tamanho_LD        (Tno_ld *inicio, int *tam);
int Inverter_LD             (Tno_ld **inicio);

/* Variaveis global */


/* ----------------------------------------------------------------------------
Fun��es de apoio
-----------------------------------------------------------------------------*/
void gotoxy( int x, int y )
{
COORD coord;
coord.X = (short)x;
coord.Y = (short)y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

/* -----------------------------------------------------------------------------
PRINCIPAL
------------------------------------------------------------------------------*/
int main(void)
{

	int info;
	int erro, pos; /* valor de erro retornado pelas funcoes */
	Tno_ld *ini;
	int q;  /* receber a opcao do usuario */
	erro=Inicializar_LD (&ini);
	do {
	    system("cls");
	    //gotoxy (20,18); printf("TAMANHO: %d",sizeof(int));
	    gotoxy (20,1); printf("LISTA ENCADEADA DUPLA - LED");
		gotoxy(0,0); printf("\n\nOpcoes: \n\n");
		gotoxy(0,7);
		printf("1 -> Inserir no inicio \n");
		printf("2 -> Inserir no meio \n");
		printf("3 -> Inserir no final\n");
		printf("4 -> Remover no inicio\n");
		printf("5 -> Remover no meio\n");
		printf("6 -> Remover no fim\n");
		printf("7 -> Mostrar toda a lista \n");
		printf("8 -> Inicializar a lista (versao 2)\n");
		printf("9 -> Inverter a lista\n");
		printf("10 -> Obter dado\n");
		printf("11 -> Sair \n:");
		scanf("%d", &q);     /* Ler a opcao do usuario */
		switch(q) {
			case 1: printf("Dado para insercao na lista: ");
                    scanf("%d",&info);
                    erro=Inserir_inicio_LD (&ini, info);
                    if (erro == 0) printf("Insercao realizada com sucesso\n");
                    system("pause");
					break;
			case 2: printf("Dado para insercao na lista: ");
                    scanf("%d",&info);
                    printf("Posicao de insercao: ");
                    scanf("%d",&pos);
                    erro=Inserir_meio_LD (&ini, info, pos);
                    if (erro == 0) printf("\nInsercao realizada com sucesso\n");
                    else printf("\nERROR: Posicao invalida para insercao\n");
                    system("pause");
					break;
			case 3: printf("Dado para insercao na lista: ");
                    scanf("%d",&info);
                    Inserir_fim_LD (&ini, info);
			        break;
            case 4: erro = Remover_inicio_LD (&ini);
                    if (erro==1)
                    {
                        printf("\nLista vazia. Impossivel remover");
                    }
                    system("pause");
                    break;
            case 5: printf("Posicao de remocao: ");
                    scanf("%d",&pos);
                    erro=Remover_meio_LD (&ini, pos);
                    if (erro == 0) printf("\nRemocao realizada com sucesso\n");
                    else printf("\nERROR: Posicao invalida para remocao\n");
                    system("pause");
					break;
			case 6: erro = Remover_fim_LD (&ini);
                    if (erro==1)
                    {
                        printf("\nLista vazia. Impossivel remover");
                    }
                    system("pause");
                    break;
			case 7: erro=Listar_LD (ini);
                    if (erro==1)
                    {
                        printf("\nLista vazia. Impossivel listar");
                    }
                    system("pause");
					break;
			case 8: erro=Inicializar2_LD (&ini);
                    printf("\nInicializacao realizada com sucesso !\n");
                    printf("\nLISTA VAZIA !\n");
                    system("pause");
					break;
			case 9: erro=Inverter_LD (&ini);
                    printf("\nInversao realizada !\n");
                    system("pause");
					break;
			case 10: printf("Posicao do dado desejado: ");
					scanf("%d", &pos);
					erro=Obter_dado_LD (ini, pos, &info);
					if (erro==1) printf("\nLista vazia. Impossivel obter dado !\n\n");	
					if (erro==2) printf("\nPosicao invalida para obtencao do dado\n\n");
					system("pause");
					break;			
			case 11: break;
			default: printf("\n\n Opcao nao valida");
		}
		getchar();    /* Limpa o buffer de entrada */
	} while ((q != 11) );

}


/* ------------------------------------------------------------------------------------
LISTAR todos os elementos presentes na lista encadeada
--------------------------------------------------------------------------------------*/
int Listar_LD (Tno_ld *inicio)
{
	int i;
	if (inicio == NULL)
	{
        return 1;  /* lista vazia */
	}
    printf("LISTA ::  ");
	while (inicio != NULL) {
		   printf("%d  ",inicio->dado);
		   inicio = inicio->prox;
    }
    printf("\n");
	return 0; /* sem erro */
} /* Fim da fun��o de MOSTRAR */

/* ------------------------------------------------------------------------------------
LISTAR todos os elementos presentes na lista encadeada na ordem inversa
--------------------------------------------------------------------------------------*/
int Listar_Invertido_LD (Tno_ld *inicio)
{
	int i;
	if (inicio == NULL)
	{
        return 1;  /* lista vazia */
	}
    printf("LISTA ::  ");

	while (inicio->prox != NULL) // ir ate a ultima posicao
    {
		inicio = inicio->prox;
    }

    while (inicio != NULL) // ir alem da primeira posicao imprimindo
    {
        printf("%d  ",inicio->dado);
	    inicio = inicio->ant;
    }
    printf("\n");
	return 0; /* sem erro */
} /* Fim da fun��o de MOSTRAR */


/* ------------------------------------------------------------------------------------
INICIALIZAR
--------------------------------------------------------------------------------------*/
int Inicializar_LD (Tno_ld **inicio)
{
	*inicio= NULL;
	return 0; /* sem erro */
} /* Fim da fun��o de INICIALIZAR */

// =================================================
int Inicializar2_LD(Tno_ld **inicio)
{
    Tno_ld *percorre, *aux;
	if(*inicio != NULL)
	{
       percorre = *inicio;
	   while (percorre != NULL)
	   {
             aux = percorre;
	         percorre = percorre -> prox;
	         free(aux);
	   }
	   *inicio = NULL;
	   return 1; // inicializa apagando tudo da listsa
	}
	else
	{
	   Inicializar_LD(inicio); // inicializa
	   return 0;
	}
}


// =================================================
int Obter_Tamanho_LD(Tno_ld *inicio, int *tam)
{
    Tno_ld *percorre;
    *tam = 0;
	if(inicio != NULL)
	{
       percorre = inicio;
	   while (percorre != NULL)
	   {
         (*tam)++;
         percorre = percorre -> prox;
	   }
     }
    else
    {
         *tam = 0;
    }
}

/* -------------------------------------------------------------------------------------
INSER��O
---------------------------------------------------------------------------------------*/
int Inserir_inicio_LD (Tno_ld **inicio, int info)
{
    Tno_ld *no_novo;

    /* Criacao do novo no - Aloca��o de memoria */
    no_novo = (Tno_ld *) malloc(sizeof(Tno_ld));
    no_novo -> dado = info;

	if (*inicio==NULL)
	{    // insercao em lista vazia
	    no_novo -> prox = NULL;
	    *inicio = no_novo;
	    no_novo -> ant = NULL;
	}
	else { // insercao em lista nao vazia
	    no_novo -> prox = *inicio;
	    no_novo -> ant = NULL;
	    (*inicio)->ant = no_novo;// anterior do 1o. aponta para o novo
	    *inicio = no_novo; // atualizo o 1o., que passa a ser o novo

	}
    return 0;
}

// ------------------------------------------------------------------
int Inserir_meio_LD (Tno_ld **inicio, int info, int pos)
{
    int tam;
    Tno_ld *no_novo, *percorre;

    // Tratamento de erros =======================================
    if (pos<= 0)
       return 1;  // posicao invalida para insercao

    Obter_Tamanho_LD(*inicio, &tam);
    if (pos > tam+1)
       return 2;   // posicao invalida. Acima do tamanho da lista
    // ===========================================================

    // Alocacao do novo no
    no_novo = (Tno_ld *)malloc(sizeof(Tno_ld));
    no_novo -> dado = info;

    // procura pela posicao de insercao
    if (pos==1)
    {   // insercao no inicio
        Inserir_inicio_LD (inicio, info);
    }
    else
    {   if (pos == tam+1)
        {
            Inserir_fim_LD (inicio, info);
        }
        else {
                int pos_aux=1;
                percorre = *inicio;
                while (pos_aux!=pos-1) // parar uma posicao antes
                {
                   percorre = percorre -> prox;
                   pos_aux++;
                }
                no_novo -> prox = percorre -> prox; // D
                percorre -> prox = no_novo;         // B
                no_novo -> ant = percorre;          // A
                (no_novo->prox)->ant = no_novo;     // C

        }
    }
    return 0;
}

//----------------------------------------------------------------
int Inserir_fim_LD (Tno_ld **inicio, int info)
{
    Tno_ld *no_novo, *percorre;

    /* Criacao do novo no - Aloca��o de memoria */
    no_novo = (Tno_ld *) malloc(sizeof(Tno_ld));
    no_novo -> dado = info;
    no_novo -> prox = NULL;
	if (*inicio==NULL)
	{ // lista vazia.
	    *inicio = no_novo;
	    no_novo -> ant = NULL;
	}
	else { // lista nao vazia
	     percorre = *inicio;
	     while (percorre->prox != NULL) // ate o ultimo
	     {
	         percorre = percorre -> prox;
	     }
	    percorre->prox = no_novo;  // liga��o do ultimo com o novo
	    no_novo -> ant = percorre; // liga o novo ultimo ao anterior
	}
	return 0;
}
//----------------------------------------------------------------
int Obter_Pos_LD (Tno_ld *inicio, int valor, int *pos)
{
  *pos = 0;
  while (inicio != NULL)
  {
     (*pos)++;
     if (valor == inicio->dado)
       return 0;     // dado encontrado
     inicio = inicio -> prox;
  }
  return 1;  // dado nao encontrado
}

/* -------------------------------------------------------------------------------------
OBTER Dado
---------------------------------------------------------------------------------------*/
int Obter_dado_LD (Tno_ld *inicio, int pos, int *dado)
{
	int tam;
	int pos_aux;
	Tno_ld *percorre;
	
	// Tratamento de erros ===============================
	if (inicio == NULL)
    {
         printf("\nLISTA VAZIA ! \nRemocao Impossivel\n");
        return 1;  /* lista vazia, impossivel remover primeiro */
    }
    
    Obter_Tamanho_LD(inicio, &tam);
    if ((pos <= 0) || (pos > tam)) 
	{
    	return 2; /* Posicao invalida para obtencao do dado */
	}
	//====================================================
	else {
		
		percorre = inicio;
		pos_aux = 1;
		
		while (pos_aux != pos)
		{
			percorre = percorre->prox;
			pos_aux++;
		}
		printf ("Dado obtido: %d\n", percorre->dado);
		system("pause");
	}
	return 0;
}

/* -------------------------------------------------------------------------
REMOCAO
-------------------------------------------------------------------------*/
int Remover_inicio_LD (Tno_ld **inicio)
{
    Tno_ld *aux;
    if (*inicio == NULL)
    {
         printf("\nLISTA VAZIA ! \nRemocao Impossivel\n");
        return 1;  /* lista vazia, impossivel remover primeiro */
    }
    else {
        aux = *inicio;
        *inicio = (*inicio)->prox;
        (*inicio)->ant = NULL;
        free(aux);
        return 0;
    }
}
//----------------------------------------------------------------
int Remover_meio_LD (Tno_ld **inicio, int pos)
{
    Tno_ld *percorre;
    int pos_aux;
    int tam;
    // Tratamento de erros =======================================
    if (*inicio == NULL)
    {   printf("\nLISTA VAZIA ! \nRemocao Impossivel\n");
        return 1;  // lista vazia, impossivel remover primeiro
    }
    if (pos<=0)
        return 2;  // posicao invalida para remocao
    Obter_Tamanho_LD(*inicio, &tam);
    if (pos > tam)
        return 3;  // posicao invalida. Acima do tamanho da lista
    // ===========================================================
    percorre = *inicio;
    pos_aux = 1;
    while (pos_aux != pos) // encontrar o no para remocao
    {
       percorre = percorre->prox;
       pos_aux++;
    }
    // ligar o vizinho anterior com o vizinho proximo
    (percorre -> ant)->prox = percorre->prox;
    // ligar o vizinho proximo com o vizinho anterior
    (percorre -> prox) ->ant = percorre->ant;

    free(percorre);

}
//----------------------------------------------------------------
int Remover_fim_LD (Tno_ld **inicio)
{
	Tno_ld *aux, *percorre;
	int tam;
	// Tratamento de erros ===============================
    if (*inicio == NULL)
    {
        printf("\nLISTA VAZIA ! \nRemocao Impossivel\n");
        return 1;  /* lista vazia, impossivel remover ultimo */
    }
	if (percorre->prox = NULL)
	{
		Remover_inicio_LD (inicio);
	}
	//====================================================
	else {
		
		percorre = *inicio;
		while (percorre->prox != NULL)
		{
			aux = percorre;
			percorre = percorre->prox;
		}
		aux->prox = NULL;
		free(percorre);
	}
	return 0;
}

/* -------------------------------------------------------------------------
INVERTER LISTA
-------------------------------------------------------------------------*/
int Inverter_LD (Tno_ld **inicio)
{
    Tno_ld *percorre,*aux1, *aux2;
    percorre=*inicio;
    if(percorre==NULL)
    {
        return 1;//Caso a lista esteja vazia.
    }
    else if(percorre->prox==NULL)
    {
        return 0;//Caso a lista tenha apenas um n�.
    }
    else
    {
        while (percorre != NULL) // ate o ultimo
	     {
             // Troca do ant pelo prox e vice-versa em cada no
             aux1 = percorre->prox;
             percorre->prox = percorre->ant;
             percorre->ant = aux1;

             if (aux1 == NULL) // o percorre esta no ultimo no
                *inicio = percorre; // define novo inicio
             // Avan�ar para o proximo no de inversao
             percorre = percorre -> ant;
    	 }
    }
    return 0;
}
