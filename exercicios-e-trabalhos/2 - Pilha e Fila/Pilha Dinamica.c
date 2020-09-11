/*---------------------------------------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
/*---------------------------------------------------------------------------*/

/* -----------------------------------------------------------------------------
Estrutura PILHA DINAMICA
------------------------------------------------------------------------------*/

typedef struct pilha{
        int topo;
        struct pilha *prox;
} T_PILHA;

/* -----------------------------------------------------------------------------
Prototipos das funcoes
------------------------------------------------------------------------------*/
int Inicializar_PD (T_PILHA **inicio);
int Inicializar2_PD (T_PILHA **inicio);
int Push_empilhar (T_PILHA **inicio, int info);
int Pop_desempilhar (T_PILHA **inicio);
int Obter_topo_PD (T_PILHA *inicio, int *dado);
int Obter_tamanho_PD (T_PILHA *inicio, int *tam);

/*ERRO*/
//int Consulta (T_PILHA *inicio, int info);

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

	int info, tam, tam_p, tam_aux;
	int erro; /* valor de erro retornado pelas funcoes */
	T_PILHA *ini;
	int q;  /* receber a opcao do usuario */
	erro=Inicializar_PD (&ini);
	do {
	    system("cls");
	    gotoxy (20,1); printf("PILHA DINAMICA - LIFO");
		gotoxy(0,0); printf("\n\nOpcoes: \n\n");
		gotoxy(0,7);
		printf("1 -> Inicializar a pilha\n");
		printf("2 -> Push - Empilhar\n");
		printf("3 -> Pop - Desempilhar\n");
		printf("4 -> Obtem Topo (dado)\n");
		printf("5 -> Obtem Tamanho\n");
		printf("6 -> Consulta\n");
		printf("7 -> Sair \n:");
		
		scanf("%d", &q);  /* Ler a opcao do usuario */
		switch(q) {
			case 1: erro=Inicializar2_PD (&ini);
                    printf("\nInicializacao realizada com sucesso !\n");
                    printf("PILHA VAZIA !\n");
                    system("pause");
					break;
					
			case 2: printf("Dado para insercao na pilha: ");
                    scanf("%d",&info);
                    erro = Push_empilhar (&ini, info);
                    if (erro == 0) printf("\nDado empilhado com sucesso\n");
                    system("pause");
					break;
								        
            case 3: erro = Pop_desempilhar (&ini);
                    if (erro == 1) printf("\nPilha vazia. Impossivel desempilhar");
                    system("pause");
                    break;
					            				
			case 4: erro = Obter_topo_PD (ini, &info);
					if (erro==0) printf("Dado contido no topo da pilha: %d\n", ini->topo);
					if (erro==1) printf("\nPilha vazia. Impossivel obter topo!\n\n");	
					system("pause");
					break;
					
			case 5: erro = Obter_tamanho_PD (ini, &tam);
					printf("Numero de elementos contidos na pilha: %d\n", tam);
					system("pause");
					break;
					
			/*case 6: printf("Digite o dado que deseja consultar: ");
					scanf("%d", &info);
					Consulta (ini, info);
					if (erro == 1) printf ("\nDado NAO esta na pilha!\n");
					system("pause");
					break;*/
							
			case 7: break;
			
			default: printf("\n\n Opcao nao valida");
					system("pause");
		}
		getchar();    /* Limpa o buffer de entrada */
	} while ((q != 7) );
}


/* ------------------------------------------------------------------------------------
INICIALIZAR PILHA
--------------------------------------------------------------------------------------*/
int Inicializar_PD (T_PILHA **inicio)
{
	*inicio= NULL;
	return 0; /* sem erro */
} /* Fim da função de INICIALIZAR */
/* ================================================= */

int Inicializar2_PD (T_PILHA **inicio)
{
    T_PILHA *percorre, *aux;
    
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

/* -------------------------------------------------------------------------------------
PUSH - Empilhar // Inserir_inicio
---------------------------------------------------------------------------------------*/
int Push_empilhar (T_PILHA **inicio, int info)
{
    T_PILHA *no_novo;

    /* Criacao do novo no - Alocação de memoria */
    no_novo = (T_PILHA *) malloc(sizeof(T_PILHA));
    no_novo -> topo = info;

	if (*inicio==NULL)
	{    /* insercao em lista vazia */
	    no_novo -> prox = NULL;
	    *inicio = no_novo;
	}
	else { /* insercao em lista nao vazia */
	     no_novo -> prox = *inicio;
	    *inicio = no_novo;
	}
    return 0;
}

/* -----------------------------------------------------------------------------------------
POP - Desempilhar // Remover_inicio
------------------------------------------------------------------------------------------*/
int Pop_desempilhar (T_PILHA **inicio)
{
    T_PILHA *aux;
    if (*inicio == NULL)
    {
         printf("\nLISTA VAZIA ! \nRemocao Impossivel\n");
        return 1;  /* lista vazia, impossivel remover primeiro */
    }
    else {
        aux = *inicio;
        *inicio = (*inicio)->prox;
        free(aux);
        return 0;
    }
}

/* -------------------------------------------------------------------------------------
OBTER DADO DA PILHA (TOPO)
---------------------------------------------------------------------------------------*/
int Obter_topo_PD (T_PILHA *inicio, int *topo)
{
	/* Tratamento de erros =================================== */
	if (inicio == NULL)
    {
         printf("\nPILHA VAZIA ! \nObtencao Impossivel\n");
        return 1;  /* lista vazia, impossivel obter dado com lista vazia */
    }
    
	/* ======================================================= */
	
	/* Procura pelo dado ================ */
	else{
		return 0;
	}
		
}

/* -------------------------------------------------------------------------------------
OBTER TAMANHO DA PILHA (ESTADO)
---------------------------------------------------------------------------------------*/
int Obter_tamanho_PD (T_PILHA *inicio, int *tam)
{
    T_PILHA *percorre;
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


