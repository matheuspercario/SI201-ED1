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
	int valid;
}  Tno_ls;


/* -----------------------------------------------------------------------------
Prototipos das funcoes
------------------------------------------------------------------------------*/
int Inicializar_LS 		(Tno_ls **inicio);
int Inserir_inicio_LS 	(Tno_ls **inicio, int info);
int Inserir_fim_LS 		(Tno_ls **inicio, int info);
int Inserir_meio_LS    	(Tno_ls **inicio, int info, int pos);
int Remover_inicio_LS	(Tno_ls **inicio);
int Remover_meio_LS 	(Tno_ls **inicio, int pos);
int Remover_fim_LS 		(Tno_ls **inicio);
int Listar_LS 			(Tno_ls *inicio);
int Obter_Tamanho_LS  	(Tno_ls *inicio, int *tam);
int Obter_dado_LS 		(Tno_ls *inicio, int pos, int *dado);
int Obter_pos_LS 		(Tno_ls *inicio, int dado, int *pos);

int Limpeza_LS			(Tno_ls **inicio);

/* Variaveis global */
// OTIMIZACAO DE MANIPULACAO DE MEMORIA
Tno_ls *limpeza = NULL; // lista encadeada de estoque de nós liberados para reutilizacao


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
	Tno_ls *ini;
	Inicializar_LS (&ini);
	int q;  /* receber a opcao do usuario */
	do {
	    clrscr;
	    gotoxy (20,1); printf("LISTA ENCADEADA SIMPLES - LES");
		gotoxy(0,0); printf("\n\nOpcoes: \n\n");
		gotoxy(0,7);
		printf("1 -> Inserir no inicio \n");
		printf("2 -> Inserir no meio \n");
		printf("3 -> Inserir no final\n");
		printf("4 -> Remover no inicio\n");
		printf("5 -> Remover no meio\n");
		printf("6 -> Remover no fim\n");
		printf("7 -> Mostrar toda a lista \n");
		printf("8 -> Inicializar a lista \n");
		printf("9 -> Limpar a lista \n");
		printf("10 -> Sair \n:");
		scanf("%d", &q);     /* Le a opcao do usuario */
		switch(q) {
			case 1: printf("Dado para insercao na lista: ");
                    scanf("%d",&info);
                    erro=Inserir_inicio_LS (&ini, info);
                    if (erro == 0) printf("\nInsercao realizada com sucesso\n");
                    system("pause");
					break;
			case 2: printf("Dado para insercao na lista: ");
                    scanf("%d",&info);
                    printf("Posicao de insercao: ");
                    scanf("%d",&pos);
                    erro=Inserir_meio_LS (&ini, info, pos);
                    if (erro == 0) printf("\nInsercao realizada com sucesso\n");
                    else printf("\nERROR: Posicao invalida para insercao\n");
                    system("pause");
					break;		
			case 3: printf("Dado para insercao na lista: ");
                    scanf("%d",&info);
                    erro=Inserir_fim_LS (&ini, info);
                    if (erro == 0) printf("\nInsercao realizada com sucesso\n");
                    system("pause");
			        break;
            case 4: erro=Remover_inicio_LS (&ini);
            		if (erro == 0) printf("\nRemocao realizada com sucesso\n");
            		system("pause");
                    break;
            case 5: printf("Posicao de remocao: ");
                    scanf("%d",&pos);
                    erro=Remover_meio_LS (&ini, pos);
                    if (erro == 0) printf("\nRemocao realizada com sucesso\n");
                    else printf("\nERROR: Posicao invalida para remocao\n");
                    system("pause");
					break;		
            case 6: erro=Remover_fim_LS (&ini);
            		if (erro == 0) printf("\nRemocao realizada com sucesso\n");
                    if (erro == 1) printf("\nLista vazia. Impossivel remover");
                    system("pause");
                    break;
			case 7: erro=Listar_LS (ini);
                    if (erro==1) printf("\nLista vazia");
                    getchar();
					break;
			case 8: erro=Inicializar_LS (&ini);
                    printf("\nInicializacao realizada com sucesso !\n");
                    printf("\nLISTA VAZIA !\n");
                    getchar();
					break;
			case 9: erro=Limpeza_LS (&ini);
					if (erro==2) printf("\n\nLIMPEZA COMPLETA!\nLISTA INICIALIZADA\n");
					if (erro==1) printf("\n\nImpossivel realizar limpeza!\nLISTA VAZIA!\n");
					if (erro==0) printf("\nLimpeza realizada com sucesso !\n");
					system("pause");
					break;
			case 10: break;
			default: printf("\n\n Opcao nao valida");
		}
		getchar();    /* Limpa o buffer de entrada */
	} while ((q != 10) );

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
	while (inicio != NULL) 
	{
		//if (inicio -> valid == 1) /* Listar somente os "nos" validados com o bit de insercao */
		//{
			printf("%d  ",inicio->dado);
		//}
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
	return 0; /* sem erro */
} /* Fim da função de INICIALIZAR */

/* -------------------------------------------------------------------------------------
OBTER TAMNHO DA LISTA / DADO ESPECIFICO
---------------------------------------------------------------------------------------*/
int Obter_Tamanho_LS(Tno_ls *inicio, int *tam)
{
    Tno_ls *percorre;
    
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
INSERÇÃO NO INICIO da lista com otimização de memoria
---------------------------------------------------------------------------------------*/
int Inserir_inicio_LS (Tno_ls **inicio, int info)
{
    Tno_ls *no_novo;

    no_novo = (Tno_ls *) malloc(sizeof(Tno_ls));
    no_novo -> dado = info;
    no_novo -> valid = 1;
	if (*inicio==NULL)
	{
	    no_novo -> prox = NULL;
	}
	else {
	    no_novo -> prox = *inicio;
	}
	*inicio = no_novo;
    return 0;
}

/* ----------------------------------------------------------------------------------------
INSERÇÃO NO FIM da lista com otimização de memoria
------------------------------------------------------------------------------------------*/
int Inserir_fim_LS (Tno_ls **inicio, int info)
{
    Tno_ls *no_novo, *percorre;
	no_novo = (Tno_ls *) malloc(sizeof(Tno_ls));
    no_novo -> dado = info;
    no_novo -> valid = 1;
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
	return 0;
}

/* ----------------------------------------------------------------------------------------
INSERÇÃO NO MEIO da lista com otimização de memoria
------------------------------------------------------------------------------------------*/
int Inserir_meio_LS (Tno_ls **inicio, int info, int pos)
{
    int tam;
    Tno_ls *no_novo, *percorre;

    /* Tratamento de erros ======================================= */
    if (pos <= 0)
       return 1;  /*) posicao invalida para insercao */

    Obter_Tamanho_LS(*inicio, &tam);
    if (pos > tam+1)
       return 2;   /* posicao invalida. Acima do tamanho da lista */
    /* ================================================= */

    /* Alocacao do novo no */
    no_novo = (Tno_ls *)malloc(sizeof(Tno_ls));
    no_novo -> dado = info;
    no_novo -> valid = 1;

    /* procura pela posicao de insercao */
    if (pos == 1)
    {   /* insercao no inicio */
        Inserir_inicio_LS (inicio, info);
    }
    else
    {   if (pos == tam+1)
        {
            Inserir_fim_LS (inicio, info);
        }
        else {
                int pos_aux=1;
                percorre = *inicio;
                while (pos_aux != pos-1) /* parar uma posicao antes */
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

/* -------------------------------------------------------------------------
REMOCAO INICIO de elementos da lista Com otimização de memoria
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
    	aux -> valid = 0;
    }
    return 0;
}

/* -------------------------------------------------------------------------
REMOCAO FIM de elementos da lista Com otimização de memoria
-------------------------------------------------------------------------*/
int Remover_fim_LS (Tno_ls **inicio)
{
	Tno_ls *aux, *percorre;
	percorre = *inicio;
	
	/* Tratamento de erros ========================= */
    if (*inicio == NULL)
    {
         printf("\nLISTA VAZIA ! \nRemocao Impossivel\n");
        return 1;  /* lista vazia, impossivel remover primeiro */
    }
    
    if (percorre->prox == NULL)
	{
		Remover_inicio_LS (inicio);
	}
	/* ================================================= */
	
	/* Parte de remocao do fim ==========================*/
    else {
    
    	while (percorre->prox != NULL) 
    	{
    		aux = percorre;
    		percorre = percorre->prox;
		}
		percorre -> valid=0;
		return 0;
	}
}

/* -------------------------------------------------------------------------
REMOCAO MEIO de elementos da lista Com otimização de memoria
-------------------------------------------------------------------------*/
int Remover_meio_LS (Tno_ls **inicio, int pos)
{
	int tam;
	Tno_ls *aux, *percorre;
	
	/* Tratamento de erros ============================== */
    if (*inicio == NULL) 
	{
        printf("\nLISTA VAZIA ! \nRemocao Impossivel\n");
        return 1;  /* lista vazia, impossivel remover primeiro */
    }
    
    Obter_Tamanho_LS(*inicio, &tam); 
    if ((pos <= 0) || (pos > tam)) 
	{
    	return 1; /* posicao invalida para insercao */
	}
	/* ================================================= */
	/* procura pela posicao de remocao ================ */
	if (pos == 1) 
	{
		Remover_inicio_LS (inicio);
	}
	else{
		if (pos == tam) 
		{
			Remover_fim_LS (inicio);
		}
		else
		{
				int pos_aux = 1;
           		percorre = *inicio;
           		while (pos_aux != pos)  /* parar na posicao que deseja remover */
           		{
           			aux = percorre;
           			percorre = percorre -> prox;
           			pos_aux++;
				}
				percorre -> valid = 0;
				return 0;	
		}
	}	
}

/* ------------------------------------------------------------------------------------
LIMPEZA
--------------------------------------------------------------------------------------*/
int Limpeza_LS (Tno_ls **inicio)
{
	Tno_ls *percorre, *auxiliar, *aux1, *aux2;
	int contador = 0;
	int tam;
	
	percorre = *inicio;
	if (*inicio == NULL) 
	{
        printf("\nLISTA VAZIA ! \nRemocao Impossivel\n");
        return 1;  /* lista vazia, impossivel remover primeiro */
    }
    
    
    Obter_Tamanho_LS(*inicio, &tam); 
    while (percorre != NULL)
    {
    	if(percorre->valid ==0)
    	{
    		contador++;
		}
		percorre=percorre->prox;/
	}
	
	
	if(tam == contador)
	{
		*inicio = NULL;
	}
    else
	{
		percorre = *inicio;
	    if(percorre->prox == NULL)
	    {
	    	if(percorre->valid==0)
	    	{
	    		*inicio=NULL;
	    		return 2;
			}	
		}	
		   
		if (percorre->valid==0) 
	    {
		    while (percorre->valid==0)
		    {
		  		aux1=percorre;
		   		percorre=percorre->prox;
		   		free(aux1);
			}
			if (percorre==NULL)
			{
				*inicio=NULL;
				return 2;
			}
			else
			{
				(*inicio) = percorre;
			}
		}	
			
		while (percorre != NULL)
		{
			if(percorre->valid==0)
			{
				aux2=percorre;
				percorre=percorre->prox;
				aux1->prox=percorre;
				free(aux2);			
			}
			else
			{	
				aux1=percorre;
				percorre=percorre->prox;
			}	
		}
	}
	return 0;
}
