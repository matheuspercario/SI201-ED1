/*---------------------------------------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
/*---------------------------------------------------------------------------*/

/* -----------------------------------------------------------------------------
Estrutura LISTA ENCADEADA SIMPLES
------------------------------------------------------------------------------*/

struct no_ls {
	int dado;
	struct no_ls *prox;
};

typedef struct no_ls Tno_ls;



/* Tabela de codigo de erros
// 0 - sem erro
// 1 - ...
// 2 - ...
*/
 
/* -----------------------------------------------------------------------------
Prototipos das funcoes
------------------------------------------------------------------------------*/
int Inicializar_LS     (Tno_ls **inicio);
int Inicializar2_LS    (Tno_ls **inicio);
int Inserir_inicio_LS  (Tno_ls **inicio, int info);
int Inserir_fim_LS     (Tno_ls **inicio, int info);
int Inserir_meio_LS    (Tno_ls **inicio, int info, int pos);
int Remover_inicio_LS  (Tno_ls **inicio);
int Listar_LS          (Tno_ls *inicio);
int Obter_pos_LS       (Tno_ls *inicio, int dado, int *pos);
int Obter_Tamanho_LS   (Tno_ls *inicio, int *tam);
int Inverte_LS         (Tno_ls **inicio);
int Inverte_LS_2       (Tno_ls **inicio);  

/*-------------------------------------------------------------------------------
Funcoes de remocao feitas por mim
-------------------------------------------------------------------------------*/
int Obter_dado_LS      (Tno_ls *inicio, int pos, int *dado);
int Remover_meio_LS    (Tno_ls **inicio, int pos);
int Remover_fim_LS     (Tno_ls **inicio);

/*--------------------------------------------------------------------------------
EXERICICIOS
/* FAZER int Obter_dado_LS      (Tno_ls *inicio, int pos, int *dado); */
/* FAZER int Remover_meio_LS    (Tno_ls **inicio, int pos); */
/* FAZER int Remover_fim_LS     (Tno_ls **inicio); */
/*------------------------------------------------------------------------------*/


int Repete_Dado_LS   (Tno_ls *inicio, int info, int *resp);
/* verifica se o dado esta repetido na estrutura
// resp = 1 - sim
// resp = 0 - nao */


int Maiorque_Dado_LS (Tno_ls *inicio, int info, int *quant);
/* obtem a quantidade de dados maior que info */


int Inverter_LS_2 (Tno_ls **inicio);
/* inverter a lista encadeada usando as rotinas prontas */


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

	int info;
	int resp, pos;
	int erro; /* valor de erro retornado pelas funcoes */
	Tno_ls *ini;
	int q;  /* receber a opcao do usuario */
	erro=Inicializar_LS (&ini);
	//printf("Tamanho do no: %d",sizeof(Tno_ls));
	//system("pause");
	do {
	    system("cls");
	    /*gotoxy (20,18); printf("TAMANHO: %d",sizeof(int)); */
	    gotoxy (20,1); printf("LISTA ENCADEADA SIMPLES - LES");
		gotoxy(0,0); printf("\n\nOpcoes: \n\n");
		gotoxy(0,7);
		printf("1 -> Inicializar a lista (versao 2)\n");
		printf("2 -> Inserir no inicio\n");
		printf("3 -> Inserir no meio\n");
		printf("4 -> Inserir no final\n");
		printf("5 -> Remover no inicio\n");
		printf("6 -> Remover no meio\n");
		printf("7 -> Remover no fim\n");
		printf("8 -> Mostrar toda a lista \n");
		printf("9 -> Inverter a lista\n");
		printf("10 -> Verifica a repeticao de um dado\n");
		printf("11 -> Obter dado\n");
		printf("12 -> Sair \n");
		
		scanf("%d", &q);  /* Ler a opcao do usuario */
		switch(q) {
			case 1: erro=Inicializar2_LS (&ini);
                    printf("\nInicializacao realizada com sucesso !\n");
                    printf("\nLISTA VAZIA !\n");
                    system("pause");
					break;
					
			case 2: printf("Dado para insercao na lista: ");
                    scanf("%d",&info);
                    erro=Inserir_inicio_LS (&ini, info);
                    if (erro == 0) printf("\nInsercao realizada com sucesso\n");
                    system("pause");
					break;
					
        	case 3: printf("Dado para insercao na lista: ");
                    scanf("%d",&info);
                    printf("Posicao de insercao: ");
                    scanf("%d",&pos);
                    erro=Inserir_meio_LS (&ini, info, pos);
                    if (erro == 0) printf("\nInsercao realizada com sucesso\n");
                    else printf("\nERROR: Posicao invalida para insercao\n");
                    system("pause");
					break;
			
			case 4: printf("Dado para insercao na lista: ");
                    scanf("%d",&info);
                    erro=Inserir_fim_LS (&ini, info);
                    if (erro == 0) printf("\nInsercao realizada com sucesso\n");
			        break;
			        
            case 5: erro = Remover_inicio_LS (&ini);
                    if (erro == 1) printf("\nLista vazia. Impossivel remover");
                    system("pause");
                    break;
                    
            case 6: printf("Posicao de remocao: ");
                    scanf("%d",&pos);
                    erro=Remover_meio_LS (&ini, pos);
                    if (erro == 0) printf("\nRemocao realizada com sucesso\n");
                    else printf("\nERROR: Posicao invalida para remocao\n");
                    system("pause");
					break;
					
            case 7: erro=Remover_fim_LS (&ini);
                    if (erro == 1) printf("\nLista vazia. Impossivel remover");
                    system("pause");
                    break;
                     
			case 8: erro=Listar_LS (ini);
                    if (erro == 1) printf("\nLista vazia. Impossivel listar");
                    system("pause");
					break;
					
			case 9: erro=Inverter_LS_2 (&ini);
                    if (erro == 1) printf("\nLista vazia. Inversao nao realizada !\n");
                    else printf("\nInversao realizada !\n");
                    system("pause");
					break;
					
			case 10: printf("Dado para pesquisa na lista: ");
                    scanf("%d",&info);
                    erro=Repete_Dado_LS (ini, info, &resp);
                    if (erro != 0) printf("\nErro na operação");
                    else printf("\nResposta (1:sim, 0:Nao) : %d \n",resp);
                    system("pause");
					break;
					
			case 11: printf("Posicao do dado desejado: ");
					scanf("%d", &pos);
					erro=Obter_dado_LS(ini, pos, &info);
					if (erro==1) printf("\nLista vazia. Impossivel obter dado !\n\n");	
					if (erro==2) printf("\nPosicao invalida para obtencao do dado\n\n");
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
	return 0; /* sem erro */
} /* Fim da função de INICIALIZAR */
/* ================================================= */

int Inicializar2_LS(Tno_ls **inicio)
{
    Tno_ls *percorre, *aux;
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

/* =============================================================================== */
int Obter_dado_LS (Tno_ls *inicio, int pos, int *dado)
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
INSERÇÃO
---------------------------------------------------------------------------------------*/
int Inserir_inicio_LS (Tno_ls **inicio, int info)
{
    Tno_ls *no_novo;

    /* Criacao do novo no - Alocação de memoria */
    no_novo = (Tno_ls *) malloc(sizeof(Tno_ls));
    no_novo -> dado = info;

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

/* ================================================= */
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

/* ---------------------------------------------------------------------------------------

------------------------------------------------------------------------------------------*/
int Inserir_fim_LS (Tno_ls **inicio, int info)
{
    Tno_ls *no_novo, *percorre;

    /* Criacao do novo no - Alocação de memoria */
    no_novo = (Tno_ls *) malloc(sizeof(Tno_ls));
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

/* ================================================= */
int Obter_Pos_LS (Tno_ls *inicio, int valor, int *pos)
{
  *pos = 0;
  while (inicio != NULL)
  {
     (*pos)++;
     if (valor == inicio->dado)
       return 0;     /* dado encontrado */
     inicio = inicio -> prox;
  }
  if (inicio != NULL)
     *pos = 0;
  return 1;  /* dado nao encontrado */
}


/* -----------------------------------------------------------------------------------------
REMOCAO
------------------------------------------------------------------------------------------*/
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
        return 0;
    }
}

/* ==================================================================== */
int Remover_meio_LS (Tno_ls **inicio, int pos)
{
	int tam;
	Tno_ls *aux, *percorre;
	
	/* Tratamento de erros ============================== */
    if (*inicio == NULL) {
         printf("\nLISTA VAZIA ! \nRemocao Impossivel\n");
        return 1;  /* lista vazia, impossivel remover primeiro */
    }
    
    Obter_Tamanho_LS(*inicio, &tam); 
    if ((pos <= 0) || (pos > tam)) {
    	return 1; /* posicao invalida para insercao */
	}
	/* ================================================= */
	
	/* procura pela posicao de insercao ================ */
	if (pos == 1) {
		Remover_inicio_LS (inicio);
	}
	else{
		
		if (pos == tam) {
			Remover_fim_LS (inicio);
		}
		else{
			
				int pos_aux = 1;
           		percorre = *inicio;
           		while (pos_aux != pos)  /* parar na posicao que deseja remover */
           		{
           			aux = percorre;
           			percorre = percorre -> prox;
           			pos_aux++;
				}
				aux -> prox = percorre -> prox;
				free(percorre);
				return 0;	
		}
	}	
}


/* =============================================================== */
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
		aux->prox = NULL;
		free(percorre);
		return 0;
	}
}

/* -------------------------------------------------------------------------
INVERTER LISTA
-------------------------------------------------------------------------*/
int Inverter_LS (Tno_ls **inicio)
{
    Tno_ls *percorre,*aux_1,*aux_2,*aux_3;
    percorre=*inicio;
    if(percorre==NULL)
    {
        return 1;/*Caso a lista esteja vazia. */
    }
    else if(percorre->prox==NULL)
    {
        return 0;/*Caso a lista tenha apenas um nó. */
    }
    else
    {
        aux_1       = *inicio;        /*O ponteiro aux_a aponta para o primeiro nó, uma vez que o ponteiro "ini" passará a apontar para o último. */
        aux_2       = aux_1->prox;    /*O ponteiro aux_p passa a apontar para o segundo nó da lista.*/
        aux_3       = aux_2->prox;    /*O ponteiro aux_v passa a apontar para o terceiro nó da lista.*/
        aux_1->prox = NULL;           /*O primeiro nó da lista passa a ser o último, apontando para NULL.*/
        aux_2->prox = aux_1;          /*O segundo nó da lista passa a apontar para o primeiro, começando a inversão da lista.*/
                                      /*Início - Processo de inversão.*/
        while(aux_3!=NULL)
        {
            aux_1 = aux_2;             /*O ponteiro aux_a pega o valor do nó a sua frente na lista.*/
            aux_2 = aux_3;             /*O ponteiro aux_p pega o valor do nó a sua frente na lista.*/
            aux_3 = aux_3->prox;       /*O ponteiro aux_v pega o valor do nó a sua frente na lista.*/
            aux_2->prox=aux_1;         /*O nó para o qual aux_p está apontado passa a apontar para o nó anterior a ele na lista.*/
        }
                                       /*Fim - Processo de inversão. */
        *inicio = aux_2;               /* atualização do ponteiro de inicio */
    }

    return 0;

}

/* -------------------------------------------------------------------------
INVERTER LISTA
-------------------------------------------------------------------------*/
int Inverter_LS_2 (Tno_ls **inicio)
{
    int i, erro, tam, info;
    Tno_ls *inicio_lista_aux;      /* lista auxiliar */

    erro = Obter_Tamanho_LS(*inicio, &tam);
    if(tam==0)
    {
        return 1;/*Caso a lista esteja vazia.*/
    }
    else if(tam==1)
    {
        return 0;/*Caso a lista tenha apenas um nó.*/
    }
    else
    {
       Inicializar_LS (&inicio_lista_aux);
       for (i = 1; i<=tam; i++)
       {
          info = (*inicio)->dado; /* obtendo o dado do 1o. nó */
          Remover_inicio_LS (inicio);
          Inserir_inicio_LS (&inicio_lista_aux, info);
       }
       *inicio = inicio_lista_aux;
    }
    return 0;
}
/* ----------------------------------------------------------- */

int Repete_Dado_LS   (Tno_ls *inicio, int info, int *resp)
{
    int cont=0;  /* contagem de repeticoes*/
	if (inicio == NULL)
	{
        *resp = 0;  /* Dados nao repete */
        return 1;  /* lista vazia*/
	}
    while (inicio != NULL) {
       if (inicio->dado == info)
          cont++;
       inicio = inicio->prox;
    }
    if (cont > 1)
       *resp = 1;
    else
       *resp = 0;
	return 0; /* sem erro */
}
