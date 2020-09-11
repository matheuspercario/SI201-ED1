/*---------------------------------------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
/*---------------------------------------------------------------------------*/

/* -----------------------------------------------------------------------------
Estrutura FILA DINAMICA
------------------------------------------------------------------------------*/

typedef struct fila{
		int dado;
        struct fila *prox;
} T_FILA;

/* -----------------------------------------------------------------------------
Prototipos das funcoes
------------------------------------------------------------------------------*/
int Inicializar_FD (T_FILA **inicio);
int Inicializar2_FD (T_FILA **inicio);
int Inserir_fim (T_FILA **inicio, int info);
int Remover_inicio (T_FILA **inicio);
int Obter_primeiro_FD (T_FILA *inicio, int *dado);
int Obter_tamanho_FD (T_FILA *inicio, int *tam);

/* ----------------------------------------------------------------------------
Funções de apoio
   ---------------------------------------------------------------------------- */
void gotoxy( int x, int y )
{
COORD coord;
coord.X = (short)x;
coord.Y = (short)y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

/* ---------------------------------------------------------------------------- */

/* -----------------------------------------------------------------------------
PRINCIPAL
------------------------------------------------------------------------------*/
int main(void)
{

	int info, tam;
	int erro; /* valor de erro retornado pelas funcoes */
	T_FILA *ini;
	int q;  /* receber a opcao do usuario */
	erro = Inicializar_FD (&ini);
	do {
	    system("cls");
	    gotoxy (20,1); printf("FILA DINAMICA - FIFO");
		gotoxy(0,0); printf("\n\nOpcoes: \n\n");
		gotoxy(0,7);
		printf("1 -> Inicializar\n");
		printf("2 -> Inserir (fim)\n");
		printf("3 -> Remover (inicio)\n");
		printf("4 -> Obter primeiro\n");
		printf("5 -> Obtem tamanho\n");
		printf("6 -> Sair \n:");
		
		scanf("%d", &q);  /* Ler a opcao do usuario */
		switch(q) {
			case 1: erro=Inicializar2_FD (&ini);
                    printf("\nInicializacao realizada com sucesso !\n");
                    printf("FILA VAZIA !\n");
                    system("pause");
					break;
					
			case 2: printf("Dado para insercao na fila: ");
                    scanf("%d",&info);
                    erro = Inserir_fim (&ini, info);
                    if (erro == 0) printf("\nDado inserido com sucesso!\n");
                    system("pause");
					break;
								        
            case 3: erro = Remover_inicio (&ini);
                    if (erro == 1) printf("\nFIla vazia. Impossivel remover!");
                    system("pause");
                    break;
					            				
			case 4: erro = Obter_primeiro_FD (ini, &info);
					if (erro==0) printf("Dado contido na primeira posicao da fila: %d\n", ini->dado);
					if (erro==1) printf("\nFila vazia. Impossivel obter dado!\n\n");
					system("pause");
					break;
					
			case 5: erro = Obter_tamanho_FD (ini, &tam);
					printf("Numero de elementos contidos na fila: %d\n", tam);
					system("pause");
					break;
							
			case 6: break;
			
			default: printf("\n\n Opcao nao valida");
					system("pause");
		}
		getchar();    /* Limpa o buffer de entrada */
	} while ((q != 6) );
}

/* ------------------------------------------------------------------------------------
INICIALIZAR PILHA
--------------------------------------------------------------------------------------*/
int Inicializar_FD (T_FILA **inicio)
{
	*inicio= NULL;
	return 0; /* sem erro */
} /* Fim da função de INICIALIZAR */
/* ================================================= */

int Inicializar2_FD (T_FILA **inicio)
{
    T_FILA *percorre, *aux;
    
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
	   return 1; /* inicializa apagando tudo da listsa */
	}
	else
	{
	   return 0;
	}
}

/* ------------------------------------------------------------------------------------
Inserir no final da fila
--------------------------------------------------------------------------------------*/
int Inserir_fim (T_FILA **inicio, int info)
{
    T_FILA *no_novo, *percorre;

    /* Criacao do novo no - Alocação de memoria */
    no_novo = (T_FILA *) malloc(sizeof(T_FILA));
    no_novo -> dado = info;
    no_novo -> prox = NULL;

    if (*inicio==NULL)
	{ /* lista vazia. */
	    *inicio = no_novo;
	}
	else { /* lista nao vazia */
	     percorre = *inicio;
	     while (percorre->prox != NULL)
	     {
	         percorre = percorre -> prox;
	     }
	    percorre->prox = no_novo;
	}
	return 0;
}

/* ------------------------------------------------------------------------------------
Remover no inicio da fila
--------------------------------------------------------------------------------------*/
int Remover_inicio (T_FILA **inicio)
{
    T_FILA *aux;
    if (*inicio == NULL)
    {
         printf("\nFILA VAZIA ! \nRemocao Impossivel\n");
        return 1;  /* lista vazia, impossivel remover primeiro */
    }
    else {
        aux = *inicio;
        *inicio = (*inicio)->prox;
        free(aux);
        return 0;
    }
}

/* ------------------------------------------------------------------------------------
Obter primeiro da fila
--------------------------------------------------------------------------------------*/
int Obter_primeiro_FD (T_FILA *inicio, int *dado)
{
	/* Tratamento de erros =================================== */
	if (inicio == NULL)
    {
         printf("\nFILA VAZIA ! \nObtencao Impossivel\n");
        return 1;  /* lista vazia, impossivel obter dado com lista vazia */
    }
    
	/* ======================================================= */
	else{
		return 0;
	}
}

/* -------------------------------------------------------------------------------------
OBTER tamanho da fila
---------------------------------------------------------------------------------------*/
int Obter_tamanho_FD (T_FILA *inicio, int *tam)
{
    T_FILA *percorre;
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

