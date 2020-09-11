
//---------------------------------------------------------------------------
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#define clrscr system("cls")
//---------------------------------------------------------------------------

/* -----------------------------------------------------------------------------
Estrutura LISTA ENCADEADA SIMPLES
------------------------------------------------------------------------------*/

typedef struct no_ls {
	int dado;
	struct no_ls *prox;
}  Tno_ls;

/* -----------------------------------------------------------------------------
Prototipos das funcoes
------------------------------------------------------------------------------*/
int Inicializar_LS (Tno_ls **inicio);
int Inserir_inicio_LS (Tno_ls **inicio, int info);
int Inserir_fim_LS (Tno_ls **inicio, int info);
int Inserir_meio_LS (Tno_ls **inicio, int info);
int Remover_inicio_LS (Tno_ls **inicio);
int Remover_meio_LS (Tno_ls **inicio, int pos);
int Remover_fim_LS (Tno_ls **inicio);
int Listar_LS (Tno_ls *inicio);
int Obter_dado_LS (Tno_ls *inicio, int pos, int *dado);
int Obter_pos_LS (Tno_ls *inicio, int dado, int *pos);
int Gravar (Tno_ls *inicio);
int Recuperar (Tno_ls **inicio);


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

/* Variaveis globais*/

int quant=0; /* quantidade de dados na lista */
FILE *arquivo;

/* -----------------------------------------------------------------------------
PRINCIPAL
------------------------------------------------------------------------------*/
int main(void)
{


	int info;
	int erro; /* valor de erro retornado pelas funcoes */
	Tno_ls *ini;
	int q;  /* receber a opcao do usuario */
	Inicializar_LS (&ini);
	do {
	    clrscr;
	    gotoxy (20,1); printf("LISTA ENCADEADA SIMPLES - LES");
		gotoxy(0,0); printf("\n\nOpcoes: \n\n");
		gotoxy(0,7);
		printf("1 -> Inserir no inicio \n");
		printf("2 -> Inserir no final\n");
		printf("3 -> Remover no inicio\n");
		printf("4 -> Mostrar toda a lista \n");
		printf("5 -> Inicializar a lista \n");
        printf("6 -> Gravar  da Lista no Arquivo \n");
		printf("7 -> Recuperar Arquivo para a Lista\n");
		printf("8 -> Sair \n:");
		scanf("%d", &q);     /* Le a opcao do usuario */
		switch(q) {
			case 1: printf("Dado para insercao na lista: ");
                    scanf("%d",&info);
                    Inserir_inicio_LS (&ini, info);
					break;
			case 2: printf("Dado para insercao na lista: ");
                    scanf("%d",&info);
                    Inserir_fim_LS (&ini, info);
			        break;
            case 3: Remover_inicio_LS (&ini);
                    break;
			case 4: erro=Listar_LS (ini);
                    if (erro==1)
                    {
                        printf("\nLista vazia");
                    }
                    getchar();
					break;
			case 5: erro=Inicializar_LS (&ini);
                    printf("\nInicializacao realizada com sucesso !\n");
                    printf("\nLISTA VAZIA !\n");
                    system("pause");
					break;
			case 6:
                    erro= Gravar (ini);
                    if (erro==1) { printf("\nErro de gravacao do arquivo !\n"); }
                    else { printf("\nSucesso na gravacao do arquivo !\n"); }
                    system("pause");
					break;
			case 7:
                    erro= Recuperar (&ini);
                    if (erro==1) { printf("\nErro de recuperacao do arquivo !\n"); }
                    else { printf("\nSucesso na recuperacao do arquivo !\n"); }
                    getchar();
					break;
			case 8 :break;
			default: printf("\n\n Opcao nao valida");
		}
		getchar();    /* Limpa o buffer de entrada */
	} while ((q != 8) );

}


 /* ------------------------------------------------------------------------------------
LISTAR todos os elementos presentes na lista encadeada
--------------------------------------------------------------------------------------*/
int Listar_LS (Tno_ls *inicio)
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
} /* Fim da função de MOSTRAR */



/* ------------------------------------------------------------------------------------
INICIALIZAR
--------------------------------------------------------------------------------------*/
int Inicializar_LS (Tno_ls **inicio)
{
	*inicio= NULL;
	quant = 0;
	return 0; /* sem erro */
} /* Fim da função de INICIALIZAR */




/* -------------------------------------------------------------------------------------
INSERIR INICIO
---------------------------------------------------------------------------------------*/
int Inserir_inicio_LS (Tno_ls **inicio, int info)
{
    Tno_ls *no_novo;

    /* Criacao do novo no - Alocação de memoria */
    no_novo = (Tno_ls *) malloc(sizeof(Tno_ls));
    no_novo -> dado = info;

	if (*inicio==NULL)
	{
	    no_novo -> prox = NULL;
	    *inicio = no_novo;
	}
	else {
	     no_novo -> prox = *inicio;
	    *inicio = no_novo;
	}
	quant++;
    return 0;

}

/* ----------------------------------------------------------------------------------------
INSERIR FIM
------------------------------------------------------------------------------------------*/
int Inserir_fim_LS (Tno_ls **inicio, int info)
{
    Tno_ls *no_novo, *percorre;

    /* Criacao do novo no - Alocação de memoria */
    no_novo = (Tno_ls *) malloc(sizeof(Tno_ls));
    no_novo -> dado = info;
    no_novo -> prox = NULL;
	if (*inicio==NULL)
	{

	    *inicio = no_novo;
	}
	else {
	     percorre = *inicio;
	     while (percorre->prox != NULL)
	     {
	         percorre = percorre -> prox;
	     }
	    percorre->prox = no_novo;
	}
	quant++;
	return 0;
}

/* -------------------------------------------------------------------------
REMOVER
-------------------------------------------------------------------------*/
int Remover_inicio_LS (Tno_ls **inicio)
{
    Tno_ls *aux;
    if (*inicio == NULL)
    {
         printf("\nLISTA VAZIA ! \nRemocao Impossivel\n");
        return 1;  /* lista vazia, impossivel remover primeiro */
    }
    else {
        aux = *inicio;
        *inicio = (*inicio)->prox;
        free(aux);
        quant--;
        return 0;

    }
}

/* -----------------------------------------------------------------------
GRAVAR 2
------------------------------------------------------------------------*/
int Gravar2 (Tno_ls *inicio)
{

    
}
/* -----------------------------------------------------------------------
GRAVAR
------------------------------------------------------------------------*/
int Gravar (Tno_ls *inicio)
{
        Tno_ls *percorre;
        // ATENÇÃO PARA O CAMINHO
        arquivo = fopen("dados.bin","wb");
        if (arquivo== NULL)
        { return 1; /*CAMINHO nao encontrado */ }
        else {
            fwrite(&quant, sizeof(int), 1, arquivo);
            percorre = inicio;
            while (percorre != NULL)
            {
                int aux = percorre->dado;
                fwrite(&aux, sizeof(int), 1, arquivo);
                percorre = percorre -> prox;
            }
            fclose(arquivo);
            return 0;
        }
}

/* -----------------------------------------------------------------------
RECUPERAR
------------------------------------------------------------------------*/
int Recuperar (Tno_ls **inicio)
{
        Tno_ls *percorre;

        int cont = 0, aux, quantidade;
        // ATENÇÃO PARA O CAMINHO
        arquivo = fopen("dados.bin","rb");
        if (arquivo== NULL)
        { return 1; /*CAMINHO nao encontrado */ }
        else {
            Inicializar_LS (inicio);
            fread(&quantidade, sizeof(int), 1, arquivo);
            while (cont != quantidade )
            {
                fread(&aux, sizeof(int), 1, arquivo);
                Inserir_fim_LS (inicio, aux);
                cont++;
            }
            fclose(arquivo);
            return 0;
        }
}
