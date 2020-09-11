#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

/* -----------------------------------------------------------------------------
ESTRUTURA DA MATRIZ ESPARSA
------------------------------------------------------------------------------*/
typedef struct no_matriz {
	int dado;
	int poslinha, poscoluna;   /* posicao do nó em relação aos vetores */
	struct no_matriz *dir, *esq, *acima, *abaixo;
} Tipo_no_matriz;

typedef struct vetor {
	int pos;
	struct no_matriz *pont; // inicio da lista
} Vetor_de_matriz;

Vetor_de_matriz vlinha[10], vcoluna[10];

/* ----------------------------------------------------------------------------
Funcoes de apoio
-----------------------------------------------------------------------------*/
void gotoxy( int x, int y )
{
COORD coord;
coord.X = (short)x;
coord.Y = (short)y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

/* -----------------------------------------------------------------------------
Prototipos das funcoes
------------------------------------------------------------------------------*/
int Listar		();
int Listar2 	();
int Inicializar ();
int ver 		(int linha, int coluna);
int Inserir 	(int info, int linha, int coluna);
//int Remover 	(int linha, int coluna); 

/* ------------------------------------------------------------------------------------
FUNCAO PRINCIPAL
--------------------------------------------------------------------------------------*/
int main(void)
{
	int info, linha, coluna;
	int q, erro;
	
	do {
		fflush(stdin);
		system("cls");
		printf(" Opcao: \n");
		printf("1. Inicializar \n");
		printf("2. Inserir \n");
		printf("3. Remover \n");
		printf("4. Listar \n");
		printf("5. Sair \n:");
		
		scanf ("%d",&q);
		switch(q) {
		
			case 1: Inicializar();
					system("pause");
					break;
					
			case 2: printf(" Dados= ");
					scanf ("%d", &info);
					printf(" Linha= ");
					scanf ("%d", &linha);
					printf(" Coluna= ");
					scanf ("%d", &coluna);
					erro = Inserir (info, linha, coluna);
					if (erro!=0) printf("Insercao impossivel.\n");
					system("pause");
					break;
				
			case 3: printf(" Linha= ");
					scanf ("%d", &linha);
					printf(" Coluna= ");
					scanf ("%d", &coluna);
					erro = Remover (linha, coluna);
					if (erro!=0) printf("Remocao impossivel.\n");
					system("pause");
					break;
			
			case 4:	Listar2();
					break;
		
			case 5: break;
		
		default: printf ("\n\n Opcao nao valida!\n");
				system ("pause");
		}
		getchar();
	} while ((q != 5));	
}
	
/* ------------------------------------------------------------------------------------
LISTAR 
--------------------------------------------------------------------------------------*/
int Listar ()
{
	Tipo_no_matriz *percorre;
	int i;
	for (i=1;i<=9;i++)
	{
		printf("Linha [%d] ",i);
		percorre = vlinha[i].pont;
		while (percorre != NULL) 
		{
			printf(" (%d.%d,%d) ",percorre->dado, percorre->poslinha, percorre->poscoluna);
			percorre = percorre->dir;
		}
	printf("\n");
	}
	getchar();
	return 0;
}

/*----------------------------------------------------------------------------------*/
int Listar2 ()
{
	Tipo_no_matriz *percorre;
	int i,j,x;
	x=1;
	for (j=0; j<81; j+=9)
	{
		gotoxy(j,6);
		printf("[%d]",x);
		x++;
	}

	printf("\n");
	for (i=1;i<=9;i++)
	{
		percorre = vlinha[i].pont;
		while (percorre != NULL)
		{
			gotoxy((percorre->poscoluna-1)*9, percorre->poslinha+7+i);
			printf("(%d)",percorre->dado);
			percorre = percorre->dir;
		}
	}
	printf("\n");
	getchar();
	return 0;
}

/* ------------------------------------------------------------------------------------
INICIALIZAR 
--------------------------------------------------------------------------------------*/
int Inicializar ()
{
	int i;
	for (i=1;i<=9;i++)
	{
		vcoluna[i].pont = NULL;	
		vlinha[i].pont = NULL;
    	vcoluna[i].pos= i;
		vlinha[i].pos=i;
	}
	return 0;
}

/* ------------------------------------------------------------------------------------
VERIFICAR se já existe elemento 
--------------------------------------------------------------------------------------*/
int ver (int linha, int coluna)
{
   Tipo_no_matriz *percorre;
   percorre = vlinha[linha].pont;
   while ((percorre != NULL)
         && ((percorre->poscoluna!=coluna)
         || (percorre->poslinha!=linha)))
    {
        percorre = percorre->dir;
	}
	if (percorre == NULL)
	    return 0;          // celula nao usada
    else
        return 1;          // celula ja existe
}

/* ------------------------------------------------------------------------------------
INSERIR 
--------------------------------------------------------------------------------------*/
int Inserir(int info, int linha, int coluna)
{
   int erro;
  /* Verifica se celula já está ocupada */
  erro = ver (linha, coluna);
  if (erro == 1) return 1;

  Tipo_no_matriz *percorre, *percorreantes, *no_novo;

  /* criar novo no */
  no_novo = (Tipo_no_matriz *) malloc (sizeof(Tipo_no_matriz));
  no_novo -> dado = info;
  no_novo -> dir = NULL;
  no_novo -> esq = NULL;
  no_novo -> acima = NULL;
  no_novo -> abaixo = NULL;
  no_novo -> poslinha = linha;
  no_novo -> poscoluna = coluna;


/* -------------------------------------------------------------------------------- */
/* VETOR LINHA */
 
 if (vlinha[linha].pont == NULL) /* linha vazia */
 {
   vlinha[linha].pont = no_novo;
 }
 
 else {
	percorre = vlinha[linha].pont;
	percorreantes = NULL;
	while ((percorre != NULL) && (percorre->poscoluna < coluna)) 
	{
	    percorreantes = percorre;
	    percorre = percorre -> dir;
	}
	
	if (percorre == NULL)
	{
	  /* insercao no final */
	  percorreantes->dir = no_novo;
	  no_novo -> esq = percorreantes;
	}
	
	else
	{ /* insercao no inicio */
	  if (percorreantes== NULL)
	  {
	    vlinha[linha].pont = no_novo;
	    no_novo -> dir = percorre;
	    percorre -> esq = no_novo;
	  }
	  else
	  {
	    /* insercao no meio */
	    percorreantes -> dir = no_novo;
	    no_novo -> esq = percorreantes;
	    percorre -> esq = no_novo;
	    no_novo -> dir = percorre;
	  }
	}
 }
 
 /* -------------------------------------------------------------------------------- */
 /* VETOR COLUNA */
 
 if (vcoluna[coluna].pont == NULL) /* coluna vazia */
 {
   vcoluna[coluna].pont = no_novo;
 }
 else {
	percorre = vcoluna[coluna].pont;
	percorreantes = NULL;
	while ((percorre != NULL) && (percorre->poslinha < linha)) 
	{
	    percorreantes = percorre;
	    percorre = percorre -> abaixo;
	}
	
	if (percorre == NULL)
	{
	  /* insercao no final */
	  percorreantes->abaixo = no_novo;
	  no_novo -> acima = percorreantes;
	}
	
	else
	{ /* insercao no inicio */
	  if (percorreantes == NULL)
	  {
	    vcoluna[coluna].pont = no_novo;
	    no_novo -> abaixo = percorre;
	    percorre -> acima = no_novo;
	  }
	  else
	  {
	    /* insercao no meio */
	    percorreantes -> abaixo = no_novo;
	    no_novo -> acima = percorreantes;
	    percorre -> acima = no_novo;
	    no_novo -> abaixo = percorre;
	  }
	}
 }
 
return 0;
}

/* ------------------------------------------------------------------------------------
REMOVER
--------------------------------------------------------------------------------------*/
int Remover (int linha, int coluna)
{
	int erro;
	/* Verifica se celula está ocupada */
	erro = ver (linha, coluna);
	if (erro == 0) return 1;
	
	Tipo_no_matriz *percorre, *percorreantes;
	
/* -------------------------------------------------------------------------------- */
/* VETOR LINHA */

	if (vlinha[linha].pont != NULL) /* linha NAO vazia */
	{
		percorre = vlinha[linha].pont;
		percorreantes = NULL;
		
		while ((percorre != NULL) && (percorre->poscoluna < (coluna+1))) 
		{
	    	percorreantes = percorre;
	    	percorre = percorre -> dir;
		}
		
		if(percorreantes == NULL)
		{ /* remocao no inicio */
			vlinha[linha].pont = percorre->dir;
			free(percorre);
		}
		
		else
		{
			if (percorre->dir == NULL)
			{ /* remocao no fim */
				percorreantes->dir = NULL;
				free(percorre);
			}
			else
			{ 
				if (percorre->dir != NULL)
				{ /* remocao no meio */
					percorreantes->dir = percorre->dir;
					(percorre->dir)->esq = percorreantes;	
				}
			}
		}
	}
	
	else
	{
		return 1;
	}
	
	
/* -------------------------------------------------------------------------------- */
/* VETOR COLUNA */	
	
	if (vcoluna[coluna].pont != NULL) /* coluna NAO vazia */
	{
		percorre = vcoluna[coluna].pont;
		percorreantes = NULL;
		
		while ((percorre != NULL) && (percorreantes->poslinha < (linha+1))) 
		{
	    	percorreantes = percorre;
	    	percorre = percorre -> abaixo;
		}
		
			if(percorreantes == NULL)
		{ /* remocao no inicio */
			vlinha[linha].pont = percorre->abaixo;
			free(percorre);
		}
		
		else
		{
			if (percorre->abaixo == NULL)
			{ /* remocao no fim */
				percorreantes->abaixo = NULL;
				free(percorre);
			}
			else
			{ 
				if (percorre->abaixo != NULL)
				{ /* remocao no meio */
					percorreantes->abaixo = percorre->abaixo;
					(percorre->abaixo)->acima = percorreantes;	
				}
			}
		}
	}
	else 
	{
		return 1;
	}
	return 0;	
}

