// ---------- METADADO = Dado sobre o dado ----------------------------------
// ---------- METADADO = Análise comportamental -----------------------------

//---------------------------------------------------------------------------
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
//---------------------------------------------------------------------------

/* -----------------------------------------------------------------------------
Estrutura LISTA ENCADEADA SIMPLES - COM DESCRITOR
------------------------------------------------------------------------------*/

typedef struct no_ls {
	int dado;
	struct no_ls *prox;
}  Tno_ls;

typedef struct descritor_ls {
//Descreve estatisticas sobre a estrutura
	int tam;
	struct no_ls *prim;
	struct no_ls *ult;
} Tdescritorno_ls;


// Tabela de codigo de erros
// 0 - sem erro
// 1 - ...
// 2 - ...


/* -----------------------------------------------------------------------------
Prototipos das funcoes
------------------------------------------------------------------------------
pdesc --> ponteiro para descritor  (passagem por referencia) //Acesso direto, portanto, usa a "pdesc->tam"
cdesc --> copia do descritor (passagem por valor) //Acesso da copia, portanto, usa o "cdesc.tam"
*/
int Inicializar_LS       (Tdescritorno_ls *pdesc);
int Inicializar2_LS      (Tdescritorno_ls *pdesc);
int Inserir_inicio_LS    (Tdescritorno_ls *pdesc, int info);
int Inserir_fim_LS       (Tdescritorno_ls *pdesc, int info);
int Inserir_meio_LS      (Tdescritorno_ls *pdesc, int info, int pos);
int Remover_inicio_LS    (Tdescritorno_ls *pdesc);
int Remover_meio_LS      (Tdescritorno_ls *pdesc, int pos);
int Remover_fim_LS       (Tdescritorno_ls *pdesc);
int Listar_LS            (Tdescritorno_ls cdesc);
int Obter_dado_LS        (Tdescritorno_ls cdesc, int pos, int *dado);
int Obter_pos_LS         (Tdescritorno_ls cdesc, int dado, int *pos);
int Obter_Tamanho_LS     (Tdescritorno_ls cdesc, int *tam);
int Inverte_LS           (Tdescritorno_ls *pdesc);
int Copia_lista          (Tdescritorno_ls cdesc_orig, Tdescritorno_ls *pdec_cop);

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
	int erro; /* valor de erro retornado pelas funcoes */

	Tdescritorno_ls desc;


	int q;  /* receber a opcao do usuario */
	erro=Inicializar_LS (&desc);

	do {
	    system("cls");
	    //gotoxy (20,18); printf("TAMANHO: %d",sizeof(int));
	    gotoxy (20,1); printf("LISTA ENCADEADA SIMPLES - LES");
		gotoxy(0,0); printf("\n\nOpcoes: \n\n");
		gotoxy(0,7);
		printf("1 -> Inserir no inicio \n");
		printf("2 -> Inserir no meio\n");
		printf("3 -> Inserir no final\n");
		printf("4 -> Remover no inicio\n");
		printf("5 -> Remover no meio\n");
		printf("6 -> Remover no final\n");
		printf("7 -> Mostrar toda a lista \n");
		printf("8 -> Inicializar a lista (versao 2)\n");
		printf("9 -> Sair \n:");
		scanf("%d", &q);     /* Ler a opcao do usuario */
		
		switch(q) {
			case 1: printf("Dado para insercao na lista: ");
                    scanf("%d",&info);
                    erro=Inserir_inicio_LS (&desc, info);
                    if (erro == 0) printf("Insercao realizada com sucesso\n");
                    system("pause");
					break;
			case 2: printf("Dado para insercao na lista: ");
                    scanf("%d",&info);
                    printf("Posicao da insercao na lista: ");
                    scanf("%d",&pos);
                    Inserir_meio_LS (&desc, info, pos);
                    break;
			case 3: printf("Dado para insercao na lista: ");
                    scanf("%d",&info);
                    Inserir_fim_LS (&desc, info);
			        break;
            case 4: erro = Remover_inicio_LS (&desc);
                    if (erro==1)
                    {
                        printf("\nLista vazia. Impossivel remover\n");
                    }
                    system("pause");
                    break;
            case 5: printf("Posicao de remocao: ");
                    scanf("%d",&pos);
					erro = Remover_meio_LS (&desc, pos);
                    if (erro==1) {
                        printf("\nLista vazia. Impossivel remover\n");
                    }
                    if (erro==2){
                    	printf("Posicao invalida para remocao. Tente novamente...\n");
					}
                    system("pause");
                    break;
            case 6: erro = Remover_fim_LS (&desc);
                    if (erro==1) {
                        printf("\nLista vazia. Impossivel remover\n");
                    }
                    system("pause");
                    break;
			case 7: erro=Listar_LS (desc);
                    if (erro==1)
                    {
                        printf("\nLista vazia. Impossivel listar");
                    }
                    system("pause");
					break;
			case 8: erro=Inicializar2_LS (&desc);
                    printf("\nInicializacao realizada com sucesso !\n");
                    printf("\nLISTA VAZIA !\n");
                    system("pause");
					break;
			case 9: break;
			default: printf("\n\n Opcao nao valida");
		}
		getchar();    /* Limpa o buffer de entrada */
	} while ((q != 9));

}


 /* ------------------------------------------------------------------------------------
LISTAR todos os elementos presentes na lista encadeada
--------------------------------------------------------------------------------------*/
int Listar_LS (Tdescritorno_ls cdesc)
{
	int i;
	Tno_ls *percorre;

	if (cdesc.prim == NULL)
	{
        return 1;  /* lista vazia */
	}
    printf("LISTA ::  ");
    percorre = cdesc.prim;
	while (percorre != NULL) {
		   printf("%d  ",percorre->dado);
		   percorre = percorre->prox;
    }
    printf("\n");
	return 0; /* sem erro */
} /* Fim da função de MOSTRAR */



/* ------------------------------------------------------------------------------------
INICIALIZAR
--------------------------------------------------------------------------------------*/
int Inicializar_LS (Tdescritorno_ls *pdesc)
{
	pdesc -> prim = NULL;
	pdesc -> ult = NULL;
	pdesc -> tam = 0;
	return 0; /* sem erro */
} /* Fim da função de INICIALIZAR */



// =================================================
int Inicializar2_LS(Tdescritorno_ls *pdesc)
{
    Tno_ls *percorre, *aux;
	if((pdesc->prim)!= NULL)
	{
       percorre = pdesc->prim;
	   while (percorre != NULL)
	   {
             aux = percorre;
	         percorre = percorre -> prox;
	         free(aux);
	   }
	   pdesc->prim = NULL;
	   pdesc->ult = NULL;
	   pdesc->tam = 0;
	   return 1; // inicializa apagando tudo da listsa
	}
	else
	{
	   return 0;
	}
}



// =================================================
int Obter_Tamanho_LS(Tdescritorno_ls cdesc, int *tam)
{
    if(cdesc.prim != NULL)
	{
       *tam = cdesc.tam;
    }
    else
    {
       *tam = 0;
    }
}

/* -------------------------------------------------------------------------------------
INSERÇÃO
---------------------------------------------------------------------------------------*/
int Inserir_inicio_LS (Tdescritorno_ls *pdesc, int info)
{
    Tno_ls *no_novo;

    /* Criacao do novo no - Alocação de memoria */
    no_novo = (Tno_ls *) malloc(sizeof(Tno_ls));
    no_novo -> dado = info;

	if (pdesc->prim == NULL)
	{    // insercao em lista vazia
	    no_novo -> prox = NULL;
	    pdesc->prim = no_novo;
	    pdesc->ult = no_novo;
	}
	else { // insercao em lista nao vazia
	    no_novo -> prox = pdesc->prim;
	    pdesc->prim = no_novo;
	}
	pdesc->tam = pdesc->tam + 1;
    return 0;
}

// ------------------------------------------------------------------
int Inserir_meio_LS (Tdescritorno_ls *pdesc, int info, int pos)
{
    int tam;
    Tno_ls *no_novo, *percorre;

    // Tratamento de erros =======================================
    if (pos <= 0)
       return 1;  // posicao invalida para insercao

    Obter_Tamanho_LS(*pdesc, &tam);
    if (pos > tam+1)
       return 2;   // posicao invalida. Acima do tamanho da lista
    // ===========================================================

    // Alocacao do novo no
    no_novo = (Tno_ls *)malloc(sizeof(Tno_ls));
    no_novo -> dado = info;

    // procura pela posicao de insercao
    if (pos==1)
    {   // insercao no inicio
        Inserir_inicio_LS (pdesc, info);
    }
    else
    {   if (pos == tam+1)
        {
            Inserir_fim_LS (pdesc, info);
        }
        else {
                int pos_aux=1;
                percorre = pdesc->prim;
                while (pos_aux!=pos-1) // parar uma posicao antes
                {
                   percorre = percorre -> prox;
                   pos_aux++;
                }
                no_novo -> prox = percorre -> prox;
                percorre -> prox = no_novo;
        }
    }
    (pdesc->tam)++;
    return 0;
}

/* ---------------------------------------------------------------------------------------

------------------------------------------------------------------------------------------*/
int Inserir_fim_LS (Tdescritorno_ls *pdesc, int info)
{
    Tno_ls *no_novo, *percorre;

    /* Criacao do novo no - Alocação de memoria */
    no_novo = (Tno_ls *) malloc(sizeof(Tno_ls));
    no_novo -> dado = info;
    no_novo -> prox = NULL;

	if (pdesc->prim==NULL)
	{ // lista vazia.
	    pdesc->prim = no_novo;
	}
	else
    { // lista nao vazia
	    (pdesc->ult)->prox = no_novo;
	}
	pdesc->ult = no_novo;
	(pdesc->tam)++;
	return 0;
}

/* ---------------------------------------------------------------------------------------

------------------------------------------------------------------------------------------*/
int Obter_Pos_LS (Tdescritorno_ls cdesc, int valor, int *pos)
/* obtem o valor armazenado em uma posicao da lista */
{
  Tno_ls *percorre;
  percorre = cdesc.prim;
  *pos = 0;
  while (percorre != NULL)
  {
     (*pos)++;
     if (valor == percorre->dado)
       return 0;     // dado encontrado
     percorre = percorre -> prox;
  }
  return 1;  // dado nao encontrado
}


/* -------------------------------------------------------------------------
REMOCAO
-------------------------------------------------------------------------*/
int Remover_inicio_LS (Tdescritorno_ls *pdesc)
{
    Tno_ls *aux;
    if (pdesc->prim == NULL)
    {
        printf("\nLISTA VAZIA ! \nRemocao Impossivel\n");
        return 1;  /* lista vazia, impossivel remover primeiro */
    }
    else {
        aux = pdesc->prim;
        pdesc->prim = (pdesc->prim)->prox;
        free(aux);
        (pdesc->tam)--;
        return 0;
    }
}
/* ---------------------------------------------------------------------------------------

------------------------------------------------------------------------------------------*/
int Remover_meio_LS (Tdescritorno_ls *pdesc, int pos)
{
	int tam;
	Tno_ls *aux, *percorre;
	Obter_Tamanho_LS(*pdesc, &tam);
	
	// Tratamento de erros ===============================================
	if (pdesc->prim == NULL) {
        printf("\nLISTA VAZIA ! \nRemocao Impossivel\n");
        return 1;  /* lista vazia, impossivel remover */
	}
	if ((pos <= 0) || (pos > tam)) {
    	return 2; /* posicao invalida para remocao */
	}
	if (pdesc->prim == pdesc->ult) {
    	Remover_inicio_LS (pdesc);
	}
	// ===================================================================
	
	else {
		int pos_aux = 1;
		percorre = pdesc->prim;
		while (pos_aux != pos) /* parar na posicao que deseja remover */
		{
			aux = percorre;
			percorre = percorre->prox;
			pos_aux++;
		}
		aux->prox = percorre->prox;
		free(percorre);
		
		return 0;
	}
}

/* ---------------------------------------------------------------------------------------

------------------------------------------------------------------------------------------*/
int Remover_fim_LS (Tdescritorno_ls *pdesc)
{
	Tno_ls *aux, *percorre;
	// Tratamento de erros ===============================================
	if (pdesc->prim == NULL)
    {
        printf("\nLISTA VAZIA ! \nRemocao Impossivel\n");
        return 1;  /* lista vazia, impossivel remover primeiro */
    }
    if(pdesc->prim == pdesc->ult)
    {
    	Remover_inicio_LS (pdesc);
	}
	// ===================================================================
    else {
    	aux = pdesc->ult;
    	percorre = pdesc->prim;
    	while (percorre->prox != aux)
    	{
    		percorre = percorre->prox;
		}
		percorre->prox = aux->prox;
		pdesc->ult = percorre;
		free(aux);
		
    	return 0;
	}
}
