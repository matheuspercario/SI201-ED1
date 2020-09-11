/*DIFERENÇA - Não há mais primeiro e ultimo
O "ultimo" nó recebe o endereço do primeiro*/

/*Todos whiles vão mudar e sempre tem que existir a verificação: "se houver apenas 1 elemento na lista" "*/


/*---------------------------------------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
/*---------------------------------------------------------------------------*/

/* -----------------------------------------------------------------------------
Estrutura LISTA ENCADEADA SIMPLES Circular
------------------------------------------------------------------------------*/

struct no_ls_c {
	int dado;
	struct no_ls_c *prox;
};

typedef struct no_ls_c Tno_ls_c;



/* Tabela de codigo de erros
// 0 - sem erro
// 1 - ...
// 2 - ...
*/

/* -----------------------------------------------------------------------------
Prototipos das funcoes
------------------------------------------------------------------------------*/
int Inicializar_LS_C     (Tno_ls_c **inicio);
int Inicializar2_LS_C    (Tno_ls_c **inicio);
int Inserir_inicio_LS_C  (Tno_ls_c **inicio, int info);
int Inserir_fim_LS_C     (Tno_ls_c **inicio, int info);
int Inserir_meio_LS_C    (Tno_ls_c **inicio, int info, int pos);
int Remover_inicio_LS_C  (Tno_ls_c **inicio);
int Listar_LS_C          (Tno_ls_c *inicio);
//int Obter_pos_LS_C       (Tno_ls_c *inicio, int dado, int *pos);
int Obter_Tamanho_LS_C   (Tno_ls_c *inicio, int *tam);
//int Inverte_LS_C         (Tno_ls_c **inicio);
//int Inverte_LS_2_C       (Tno_ls_c **inicio);






/* Variaveis global */


/* ----------------------------------------------------------------------------
Funções de apoio
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

	int info, pos;
	int resp;
	int erro; /* valor de erro retornado pelas funcoes */
	Tno_ls_c *ini;
	int q;  /* receber a opcao do usuario */
	erro=Inicializar_LS_C (&ini);
	//printf("Tamanho do no: %d",sizeof(Tno_ls));
	//system("pause");
	do {
	    system("cls");
	    /*gotoxy (20,18); printf("TAMANHO: %d",sizeof(int)); */
	    gotoxy (20,1); printf("LISTA ENCADEADA SIMPLES Circular - LESC");
		gotoxy(0,0); printf("\n\nOpcoes: \n\n");
		gotoxy(0,7);
		printf("1 -> Inserir no inicio \n");
        printf("2 -> Inserir no meio \n");
		printf("3 -> Inserir no final\n");
		printf("4 -> Remover no inicio\n");
		printf("5 -> Mostrar toda a lista \n");
		printf("6 -> Inicializar a lista (versao 2)\n");
		printf("9 -> Sair \n:");
		scanf("%d", &q);     /* Ler a opcao do usuario */
		switch(q) {
			case 1: printf("Dado para insercao na lista: ");
                    scanf("%d",&info);
                    erro=Inserir_inicio_LS_C (&ini, info);
                    if (erro == 0) printf("Insercao realizada com sucesso\n");
                    system("pause");
					break;
            case 2: printf("Dado para insercao na lista: ");
                    scanf("%d",&info);
                    printf("Posicao para insercao na lista: ");
                    scanf("%d",&pos);
                    Inserir_meio_LS_C (&ini, info, pos);
			        break;
            case 3: printf("Dado para insercao na lista: ");
                    scanf("%d",&info);
                    Inserir_fim_LS_C (&ini, info);
			        break;
            case 4: erro = Remover_inicio_LS_C (&ini);
                    if (erro==1)
                    {
                        printf("\nLista vazia. Impossivel remover\n");
                    }
                    system("pause");
                    break;
			case 5: erro=Listar_LS_C (ini);
                    if (erro==1)
                    {
                        printf("\nLista vazia. Impossivel listar\n");
                    }
                    system("pause");
					break;
			case 6: erro=Inicializar2_LS_C (&ini);
                    printf("\nInicializacao realizada com sucesso !\n");
                    printf("\nLISTA VAZIA !\n");
                    system("pause");
					break;
			case 9: break;
			default: printf("\n\n Opcao nao valida");
		}
		getchar();    /* Limpa o buffer de entrada */
	} while ((q != 9) );

}


 /* ------------------------------------------------------------------------------------
LISTAR todos os elementos presentes na lista encadeada
--------------------------------------------------------------------------------------*/
int Listar_LS_C (Tno_ls_c *inicio)
{
    Tno_ls_c *aux;
    aux = inicio;
	if (inicio == NULL)
	{
        return 1;  /* lista vazia */
	}
    printf("LISTA ::  ");
    // mostra o primeiro
    printf("%d  ",aux->dado);
    aux = aux->prox;

	while (inicio != aux) {
		   printf("%d  ",aux->dado);
		   aux = aux->prox;
    }
    printf("\n");
	return 0; /* sem erro */
} /* Fim da função de MOSTRAR */



/* ------------------------------------------------------------------------------------
INICIALIZAR
--------------------------------------------------------------------------------------*/
int Inicializar_LS_C (Tno_ls_c **inicio)
{
	*inicio= NULL;
	return 0; /* sem erro */
} /* Fim da função de INICIALIZAR */
/* ================================================= */

int Inicializar2_LS_C(Tno_ls_c **inicio)
{
    Tno_ls_c *percorre, *aux;
	if(*inicio != NULL)
	{
       percorre = *inicio;
       // apaga o primeiro
       aux = percorre;
       percorre = percorre -> prox;
       free(aux);

	   while (percorre != *inicio)
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


/* ================================================= */
int Obter_Tamanho_LS_C(Tno_ls_c *inicio, int *tam)
{
    Tno_ls_c *percorre;

    *tam = 0;
	if(inicio != NULL)
	{
       percorre = inicio;
       (*tam)++;
       percorre = percorre -> prox;
	   while (percorre != inicio)
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
INSERÇÃO
---------------------------------------------------------------------------------------*/
int Inserir_inicio_LS_C (Tno_ls_c **inicio, int info)
{
    Tno_ls_c *no_novo, *aux;

    /* Criacao do novo no - Alocação de memoria */
    no_novo = (Tno_ls_c *) malloc(sizeof(Tno_ls_c));
    no_novo -> dado = info;

	if (*inicio==NULL)
	{    /* insercao em lista vazia */
	    no_novo -> prox = no_novo;
	    *inicio = no_novo;
	}
	else { /* insercao em lista nao vazia */
	    no_novo -> prox = *inicio;

	    // procurar o ultimo
	    aux = *inicio;
	    while (aux->prox != *inicio)
            aux = aux->prox;
        aux->prox = no_novo;
        *inicio = no_novo;
	}
    return 0;
}

/* ================================================= */
int Inserir_meio_LS_C (Tno_ls_c **inicio, int info, int pos)
{
    int tam;
    Tno_ls_c *no_novo, *percorre;

    /* Tratamento de erros ======================================= */
    if (pos<= 0)
       return 1;  /*) posicao invalida para insercao */

    Obter_Tamanho_LS_C(*inicio, &tam);
    if (pos > tam+1)
       return 2;   /* posicao invalida. Acima do tamanho da lista */
    /* ================================================= */

    /* Alocacao do novo no */
    no_novo = (Tno_ls_c *)malloc(sizeof(Tno_ls_c));
    no_novo -> dado = info;

    /* procura pela posicao de insercao */
    if (pos==1)
    {   /* insercao no inicio */
        Inserir_inicio_LS_C (inicio, info);
    }
    else
    {   if (pos == tam+1)
        {
            Inserir_fim_LS_C (inicio, info);
        }
        else {
                int pos_aux=1;
                percorre = *inicio;
                while (pos_aux!=pos-1) /* parar uma posicao antes */
                {
                   percorre = percorre -> prox;
                   pos_aux++;
                }
                no_novo -> prox = percorre -> prox;
                percorre -> prox = no_novo;
        }
    }
    return 0;
}

/* ---------------------------------------------------------------------------------------

------------------------------------------------------------------------------------------*/
int Inserir_fim_LS_C (Tno_ls_c **inicio, int info)
{
    Tno_ls_c *no_novo, *percorre;

    /* Criacao do novo no - Alocação de memoria */
    no_novo = (Tno_ls_c *) malloc(sizeof(Tno_ls_c));
    no_novo -> dado = info;
    no_novo -> prox = *inicio;

    if (*inicio==NULL)
	{ /* lista vazia. */
	    *inicio = no_novo;
	}
	else { /* lista nao vazia */
	     percorre = *inicio;
	     while (percorre->prox != *inicio)
	     {
	         percorre = percorre -> prox;
	     }
	    percorre->prox = no_novo;
	}
	return 0;
}


/* -------------------------------------------------------------------------
REMOCAO
-------------------------------------------------------------------------*/
int Remover_inicio_LS_C (Tno_ls_c **inicio)
{
    Tno_ls_c *aux, *aux_r;
    if (*inicio == NULL)
    {
         printf("\nLISTA VAZIA ! \nRemocao Impossivel\n");
        return 1;  /* lista vazia, impossivel remover primeiro */
    }
    else {
        aux_r = *inicio;

        // procurar o ultimo
	    aux = *inicio;
	    while (aux->prox != *inicio)
            aux = aux->prox;
        aux->prox = (*inicio)->prox;

        *inicio = (*inicio)->prox;
        free(aux_r);

        return 0;
    }
}
