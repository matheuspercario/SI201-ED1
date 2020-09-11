//---------------------------------------------------------------------------
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
//---------------------------------------------------------------------------

/* -----------------------------------------------------------------------------
Estrutura LISTA ENCADEADA SIMPLES
------------------------------------------------------------------------------*/

struct no_ls {
	int dado;
	struct no_ls *prox;
};

typedef struct no_ls Tno_ls;

/* -----------------------------------------------------------------------------
Estrutura LISTA ENCADEADA DUPLA
------------------------------------------------------------------------------*/

typedef struct no_ld {
	int dado;
	struct no_ld *prox, *ant;
}  Tno_ld;


// Tabela de codigo de erros
// 0 - sem erro
// 1 - ...
// 2 - ...

/* -----------------------------------------------------------------------------
Prototipos das funcoes
------------------------------------------------------------------------------*/
// LES ================================================================
int Listar_LS          	(Tno_ls *inicio_ls);
int Inserir_inicio_LS  	(Tno_ls **inicio_ls, int info_ls);
int Inserir_meio_LS    	(Tno_ls **inicio_ls, int info_ls, int pos_ls);
int Inserir_fim_LS     	(Tno_ls **inicio_ls, int info_ls);
int Remover_inicio_LS  	(Tno_ls **inicio_ls);
int Remover_meio_LS    	(Tno_ls **inicio_ls, int pos_ls);
int Remover_fim_LS    	(Tno_ls **inicio_ls);
int Obter_Tamanho_LS  	(Tno_ls *inicio_ls, int *tam_ls);
int Obter_dado_LS		(Tno_ls *inicio_ls, int pos, int *dado);
int Inverte_LS_2       	(Tno_ls **inicio_ls);
int Inicializar_LS     	(Tno_ls **inicio_ls);
int Inicializar2_LS   	(Tno_ls **inicio_ls);
	
// LED ===============================================================
int Inicializar2_LD   	(Tno_ld **inicio_ld);
int Inicializar_LD		(Tno_ld **inicio_ld);
int Inserir_fim_LD 		(Tno_ld **inicio_ld, int info);	
int Listar_LD          	(Tno_ld *inicio_ld);
int Listar_Invertido_LD	(Tno_ld *inicio_ld);
int Obter_Tamanho_LD   	(Tno_ld *inicio_ld, int *tam_ld);

//  Copiar ===========================================================
int Copiar_LS_LD (Tno_ls *inicio_ls, Tno_ld **inicio_ld, int info);


/* Variaveis global */


/* ----------------------------------------------------------------------------
Funções de apoio
-----------------------------------------------------------------------------*/
void gotoxy(int x, int y)
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

	int info_ls, info_ld;
	int erro_ls, erro_ld, pos; /* valor de erro retornado pelas funcoes */
	Tno_ls *ini_ls;
	Tno_ld *ini_ld;
	int q;  /* receber a opcao do usuario */
	erro_ls=Inicializar_LS (&ini_ls);
	erro_ld=Inicializar_LD (&ini_ld);
	
	do {
	    system("cls");
	    //gotoxy (20,18); printf("TAMANHO: %d",sizeof(int));
	    gotoxy (20,1); printf("COPIA PARES - LES para LED");
		gotoxy(0,0); printf("\n\nOpcoes: \n\n");
		gotoxy(0,7);
		printf("LES - Lista Encadeada Simples\n");
		printf("1 -> Inserir no inicio\n");
		printf("2 -> Inserir no meio\n");
		printf("3 -> Inserir no final\n");
		printf("4 -> Remover no inicio\n");
		printf("5 -> Remover no meio\n");
		printf("6 -> Remover no fim\n");
		printf("7 -> Mostrar toda a lista\n");
		printf("8 -> Inverter a lista\n");
		printf("9 -> Obter dado\n\n");
		printf("LED - Lista Encadeada Dupla\n");
		printf("10 -> Mostrar somente pares\n");
		printf("11 -> Copiar da LES para LED\n");
		printf("\n12 -> Sair \n:");
		scanf("%d", &q);     /* Ler a opcao do usuario */	
		switch(q) {
			case 1: printf("Dado para insercao na lista: ");
                	scanf("%d",&info_ls);
                	erro_ls=Inserir_inicio_LS (&ini_ls, info_ls);
                    if (erro_ls == 0) printf("\nInsercao realizada com sucesso\n");
                    system("pause");
					break;
			case 2: printf("Dado para insercao na lista: ");
                    scanf("%d",&info_ls);
                    printf("Posicao de insercao: ");
                    scanf("%d",&pos);
                    erro_ls=Inserir_meio_LS (&ini_ls, info_ls, pos);
                    if (erro_ls == 0) printf("\nInsercao realizada com sucesso\n");
                    else printf("\nERROR: Posicao invalida para insercao\n");
                    system("pause");
					break;
			case 3: printf("Dado para insercao na lista: ");
                    scanf("%d",&info_ls);
                    erro_ls=Inserir_fim_LS (&ini_ls, info_ls);
                    if (erro_ls == 0) printf("\nInsercao realizada com sucesso\n");
                    system("pause");
			        break;
			case 4: erro_ls = Remover_inicio_LS (&ini_ls);
                    if (erro_ls == 1) printf("\nLista vazia. Impossivel remover");
                    system("pause");
                    break;
			case 5: printf("Posicao de remocao: ");
                    scanf("%d",&pos);
                    erro_ls=Remover_meio_LS (&ini_ls, pos);
                    if (erro_ls == 0) printf("\nRemocao realizada com sucesso\n");
                    else printf("\nERROR: Posicao invalida para remocao\n");
                    system("pause");
					break;
			case 6: erro_ls=Remover_fim_LS (&ini_ls);
                    if (erro_ls == 1) printf("\nLista vazia. Impossivel remover");
                    system("pause");
                    break;
			case 7: erro_ls=Listar_LS (ini_ls);
                    if (erro_ls == 1) printf("\nLista vazia. Impossivel listar");
                    system("pause");
					break;
			case 8: erro_ls=Inverter_LS_2 (&ini_ls);
                    if (erro_ls == 1) printf("\nLista vazia. Inversao nao realizada!\n");
                    else printf("\nInversao realizada !\n");
                    system("pause");
					break;
			case 9: printf("Posicao do dado desejado: ");
					scanf("%d", &pos);
					erro_ls=Obter_dado_LS(ini_ls, pos, &info_ls);
					if (erro_ls==1) printf("\nLista vazia. Impossivel obter dado !\n\n");	
					if (erro_ls==2) printf("\nPosicao invalida para obtencao do dado\n\n");
					system("pause");
					break;	
			case 10: erro_ld=Listar_LD (ini_ld);
                    if (erro_ld==1)
                    {
                        printf("\nLista vazia. Impossivel listar");
                    }
                    system("pause");
					break;
			case 11: erro_ld = Copiar_LS_LD (ini_ls, &ini_ld, info_ls);
					if (erro_ld == 0)
					{
						printf("Impossivel Copiar. Lista vazia!\n");
					}
					system("pause");
					break;
					
			case 12: break;
			default: printf("\n\n Opcao nao valida");
					system("pause");
		}
		getchar();    /* Limpa o buffer de entrada */
	} while ((q != 12) );
}

/* ------------------------------------------------------------------------------------
========================== FUNCAO COPIA DA LES PARA LED ==============================
--------------------------------------------------------------------------------------*/
int Copiar_LS_LD (Tno_ls *inicio_ls, Tno_ld **inicio_ld, int info)
{
	Tno_ls *percorre_ls;
	percorre_ls = inicio_ls;
	
	if (inicio_ls == NULL)
	{
		*inicio_ld = NULL;
		return 0;
	}
	

	while (percorre_ls != NULL)
	{
		if (percorre_ls->dado % 2 == 0)
		{
			printf ("%d ", percorre_ls->dado);
			Inserir_fim_LD (**inicio_ld, percorre_ls->dado);
		}
	}	
}


/* ------------------------------------------------------------------------------------
================================== FUNCOES DA LES =====================================
--------------------------------------------------------------------------------------*/
/* -------------------------------------------------------------------------------------
OBTER dado da lista
---------------------------------------------------------------------------------------*/
int Obter_dado_LS (Tno_ls *inicio, int pos, int *info)
{
	int tam;
	Tno_ls *percorre;
	
	/* Tratamento de erros =================================== */
	if (inicio == NULL)
    {
         printf("\nLISTA VAZIA ! \nObtencao Impossivel\n");
        return 1;  /* lista vazia, impossivel obter dado com lista vazia */
    }
    
    Obter_Tamanho_LS(inicio, &tam); 
    if ((pos <= 0) || (pos > tam)) {
    	return 2; /* Posicao invalida para obtencao do dado */
	}
	/* ======================================================= */
	
	/* Procura pela dado ================ */
	int pos_aux = 1;
	percorre = inicio;
	
	while (pos_aux != pos) /* Parar na posicao desejada */
	{
		percorre = percorre->prox;
		pos_aux++;
	}
	printf("Dado obtido: %d\n", percorre->dado);
	return 0;	
}

/* -------------------------------------------------------------------------------------
OBTER tamanho da lista
---------------------------------------------------------------------------------------*/
int Obter_Tamanho_LS (Tno_ls *inicio_ls, int *tam_ls)
{
    Tno_ls *percorre_ls;
    *tam_ls = 0;
	if(inicio_ls != NULL)
	{
       percorre_ls = inicio_ls;
	   while (percorre_ls != NULL)
	   {
         (*tam_ls)++;
         percorre_ls = percorre_ls -> prox;
	   }
     }
    else
    {
         *tam_ls = 0;
    }
}

/* ------------------------------------------------------------------------------------
LISTAR todos os elementos presentes na lista encadeada
--------------------------------------------------------------------------------------*/
int Listar_LS (Tno_ls *inicio_ls)
{
	int i;
	if (inicio_ls == NULL)
	{
        return 1;  /* lista vazia */
	}
    printf("LISTA ::  ");
	while (inicio_ls != NULL) {
		   printf("%d  ",inicio_ls->dado);
		   inicio_ls = inicio_ls->prox;
    }
    printf("\n");
	return 0; /* sem erro */
} /* Fim da função de MOSTRAR */			
	
/* ------------------------------------------------------------------------------------
INICIALIZAR 
--------------------------------------------------------------------------------------*/
int Inicializar_LS (Tno_ls **inicio_ls)
{
	*inicio_ls= NULL;
	return 0; /* sem erro */
} /* Fim da função de INICIALIZAR */

/* ================================================= */
int Inicializar2_LS (Tno_ls **inicio_ls)
{
    Tno_ls *percorre_ls, *aux_ls;
	if(*inicio_ls != NULL)
	{
       percorre_ls = *inicio_ls;
	   while (percorre_ls != NULL)
	   {
             aux_ls = percorre_ls;
	         percorre_ls = percorre_ls -> prox;
	         free(aux_ls);
	   }
	   *inicio_ls = NULL;
	   return 1; /* inicializa apagando tudo da listsa */
	}
	else
	{
	   return 0;
	}
}

/* -------------------------------------------------------------------------------------
INSERCAO
---------------------------------------------------------------------------------------*/
int Inserir_inicio_LS (Tno_ls **inicio_ls, int info_ls)
{
    Tno_ls *no_novo_ls;

    /* Criacao do novo no - Alocação de memoria */
    no_novo_ls = (Tno_ls *) malloc(sizeof(Tno_ls));
    no_novo_ls -> dado = info_ls;

	if (*inicio_ls==NULL)
	{    /* insercao em lista vazia */
	    no_novo_ls -> prox = NULL;
	    *inicio_ls = no_novo_ls;
	}
	else { /* insercao em lista nao vazia */
	     no_novo_ls -> prox = *inicio_ls;
	    *inicio_ls = no_novo_ls;
	}
    return 0;
}

// -------------------------------------------------------------------------------------
int Inserir_meio_LS (Tno_ls **inicio_ls, int info_ls, int pos_ls)
{
    int tam_ls;
    Tno_ls *no_novo_ls, *percorre_ls;

    /* Tratamento de erros ======================================= */
    if (pos_ls <= 0)
       return 1;  /*) posicao invalida para insercao */

    Obter_Tamanho_LS(*inicio_ls, &tam_ls);
    if (pos_ls > tam_ls+1)
       return 2;   /* posicao invalida. Acima do tamanho da lista */
    /* ================================================= */

    /* Alocacao do novo no */
    no_novo_ls = (Tno_ls *)malloc(sizeof(Tno_ls));
    no_novo_ls -> dado = info_ls;

    /* procura pela posicao de insercao */
    if (pos_ls == 1)
    {   /* insercao no inicio */
        Inserir_inicio_LS (inicio_ls, info_ls);
    }
    else
    {   if (pos_ls == tam_ls+1)
        {
            Inserir_fim_LS (inicio_ls, info_ls);
        }
        else {
                int pos_aux_ls=1;
                percorre_ls = *inicio_ls;
                while (pos_aux_ls != pos_ls-1) /* parar uma posicao antes */
                {
                   percorre_ls = percorre_ls -> prox;
                   pos_aux_ls++;
                }
                no_novo_ls -> prox = percorre_ls -> prox;
                percorre_ls -> prox = no_novo_ls;
        }
    }
    return 0;
}

// -------------------------------------------------------------------------------------
int Inserir_fim_LS (Tno_ls **inicio_ls, int info_ls)
{
    Tno_ls *no_novo_ls, *percorre_ls;

    /* Criacao do novo no - Alocação de memoria */
    no_novo_ls = (Tno_ls *) malloc(sizeof(Tno_ls));
    no_novo_ls -> dado = info_ls;
    no_novo_ls -> prox = NULL;

    if (*inicio_ls==NULL)
	{ /* lista vazia. */
	    *inicio_ls = no_novo_ls;
	}
	else { /* lista nao vazia */
	     percorre_ls = *inicio_ls;
	     while (percorre_ls->prox != NULL)
	     {
	         percorre_ls = percorre_ls -> prox;
	     }
	    percorre_ls->prox = no_novo_ls;
	}
	return 0;
}

/* -----------------------------------------------------------------------------------------
REMOCAO
------------------------------------------------------------------------------------------*/
int Remover_inicio_LS (Tno_ls **inicio_ls)
{
    Tno_ls *aux_ls;
    if (*inicio_ls == NULL)
    {
         printf("\nLISTA VAZIA ! \nRemocao Impossivel\n");
        return 1;  /* lista vazia, impossivel remover primeiro */
    }
    else {
        aux_ls = *inicio_ls;
        *inicio_ls = (*inicio_ls)->prox;
        free(aux_ls);
        return 0;
    }
}

// -------------------------------------------------------------------------------------
int Remover_meio_LS (Tno_ls **inicio_ls, int pos_ls)
{
	int tam_ls;
	Tno_ls *aux_ls, *percorre_ls;
	
	/* Tratamento de erros ============================== */
    if (*inicio_ls == NULL) {
         printf("\nLISTA VAZIA ! \nRemocao Impossivel\n");
        return 1;  /* lista vazia, impossivel remover primeiro */
    }
    
    Obter_Tamanho_LS(*inicio_ls, &tam_ls); 
    if ((pos_ls <= 0) || (pos_ls > tam_ls)) {
    	return 1; /* posicao invalida para insercao */
	}
	/* ================================================= */
	
	/* procura pela posicao de insercao ================ */
	if (pos_ls == 1) {
		Remover_inicio_LS (inicio_ls);
	}
	else{
		
		if (pos_ls == tam_ls) {
			Remover_fim_LS (inicio_ls);
		}
		else{
			
				int pos_aux_ls = 1;
           		percorre_ls = *inicio_ls;
           		while (pos_aux_ls != pos_ls)  /* parar na posicao que deseja remover */
           		{
           			aux_ls = percorre_ls;
           			percorre_ls = percorre_ls -> prox;
           			pos_aux_ls++;
				}
				aux_ls -> prox = percorre_ls -> prox;
				free(percorre_ls);
				return 0;	
		}
	}	
}

// -------------------------------------------------------------------------------------
int Remover_fim_LS (Tno_ls **inicio_ls)
{
	Tno_ls *aux_ls, *percorre_ls;
	percorre_ls = *inicio_ls;
	
	/* Tratamento de erros ========================= */
    if (*inicio_ls == NULL)
    {
         printf("\nLISTA VAZIA ! \nRemocao Impossivel\n");
        return 1;  /* lista vazia, impossivel remover primeiro */
    }
    
    if (percorre_ls->prox == NULL)
	{
		Remover_inicio_LS (inicio_ls);
	}
	/* ================================================= */
	
	/* Parte de remocao do fim ==========================*/
    else {
    
    	while (percorre_ls->prox != NULL) 
    	{
    		aux_ls = percorre_ls;
    		percorre_ls = percorre_ls->prox;
		}
		aux_ls->prox = NULL;
		free(percorre_ls);
		return 0;
	}
}

/* -------------------------------------------------------------------------
INVERTER LISTA
-------------------------------------------------------------------------*/
int Inverter_LS_2 (Tno_ls **inicio_ls)
{
    int i, erro_ls, tam_ls, info_ls;
    Tno_ls *inicio_lista_aux_ls;      /* lista auxiliar */

    erro_ls = Obter_Tamanho_LS(*inicio_ls, &tam_ls);
    if(tam_ls==0)
    {
        return 1;/*Caso a lista esteja vazia.*/
    }
    else if(tam_ls==1)
    {
        return 0;/*Caso a lista tenha apenas um nó.*/
    }
    else
    {
       Inicializar_LS (&inicio_lista_aux_ls);
       for (i = 1; i<=tam_ls; i++)
       {
          info_ls = (*inicio_ls)->dado; /* obtendo o dado do 1o. nó */
          Remover_inicio_LS (inicio_ls);
          Inserir_inicio_LS (&inicio_lista_aux_ls, info_ls);
       }
       *inicio_ls = inicio_lista_aux_ls;
    }
    return 0;
}

/* ------------------------------------------------------------------------------------
================================== FUNCOES DA LED =====================================
--------------------------------------------------------------------------------------*/

/* -------------------------------------------------------------------------------------
INSERCAO
---------------------------------------------------------------------------------------*/
int Inserir_fim_LD (Tno_ld **inicio_ld, int info_ld)
{
    Tno_ld *no_novo, *percorre;

    /* Criacao do novo no - Alocação de memoria */
    no_novo = (Tno_ld *) malloc(sizeof(Tno_ld));
    no_novo -> dado = info_ld;
    no_novo -> prox = NULL;
	if (*inicio_ld==NULL)
	{ // lista vazia.
	    *inicio_ld = no_novo;
	    no_novo -> ant = NULL;
	}
	else { // lista nao vazia
	     percorre = *inicio_ld;
	     while (percorre->prox != NULL) // ate o ultimo
	     {
	         percorre = percorre -> prox;
	     }
	    percorre->prox = no_novo;  // ligação do ultimo com o novo
	    no_novo -> ant = percorre; // liga o novo ultimo ao anterior
	}
	return 0;
}

/* -------------------------------------------------------------------------------------
OBTER tamanho da lista
---------------------------------------------------------------------------------------*/
int Obter_Tamanho_LD (Tno_ld *inicio_ld, int *tam_ld)
{
    Tno_ld *percorre_ld;
    *tam_ld = 0;
	if(inicio_ld != NULL)
	{
       percorre_ld = inicio_ld;
	   while (percorre_ld != NULL)
	   {
         (*tam_ld)++;
         percorre_ld = percorre_ld -> prox;
	   }
     }
    else
    {
         *tam_ld = 0;
    }
}

/* ------------------------------------------------------------------------------------
LISTAR todos os elementos presentes na lista encadeada
--------------------------------------------------------------------------------------*/
int Listar_LD (Tno_ld *inicio_ld)
{
	int i;
	int info;
	
	
	if (inicio_ld == NULL)
	{
        return 1;  /* lista vazia */
	}
    printf("LISTA ::  ");
	while (inicio_ld != NULL) {
		   printf("%d  ",inicio_ld->dado);
		   inicio_ld = inicio_ld->prox;
    }
    printf("\n");
	return 0; /* sem erro */
} /* Fim da função de MOSTRAR */

/* ------------------------------------------------------------------------------------
LISTAR todos os elementos presentes na lista encadeada na ordem inversa
--------------------------------------------------------------------------------------*/
int Listar_Invertido_LD (Tno_ld *inicio_ld)
{
	int i;
	if (inicio_ld == NULL)
	{
        return 1;  /* lista vazia */
	}
    printf("LISTA ::  ");

	while (inicio_ld->prox != NULL) // ir ate a ultima posicao
    {
		inicio_ld = inicio_ld->prox;
    }

    while (inicio_ld != NULL) // ir alem da primeira posicao imprimindo
    {
        printf("%d  ",inicio_ld->dado);
	    inicio_ld = inicio_ld->ant;
    }
    printf("\n");
	return 0; /* sem erro */
} /* Fim da função de MOSTRAR */

/* ------------------------------------------------------------------------------------
INICIALIZAR
--------------------------------------------------------------------------------------*/
int Inicializar_LD (Tno_ld **inicio_ld)
{
	*inicio_ld= NULL;
	return 0; /* sem erro */
} /* Fim da função de INICIALIZAR */

// =================================================
int Inicializar2_LD (Tno_ld **inicio_ld)
{
    Tno_ld *percorre_ld, *aux_ld;
	if(*inicio_ld != NULL)
	{
       percorre_ld = *inicio_ld;
	   while (percorre_ld != NULL)
	   {
             aux_ld = percorre_ld;
	         percorre_ld = percorre_ld -> prox;
	         free(aux_ld);
	   }
	   *inicio_ld = NULL;
	   return 1; // inicializa apagando tudo da listsa
	}
	else
	{
	   Inicializar_LD(inicio_ld); // inicializa
	   return 0;
	}
}


