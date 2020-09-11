/*---------------------------------------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <string.h>
/*--------------------------------------------------------------------------- */
#define tamanho 10  /* tamanho maximo da pilha */
/* -----------------------------------------------------------------------------
Estrutura PILHA ESTATICA
------------------------------------------------------------------------------*/

typedef struct pilha{
        int topo;
        int item [tamanho] ;
} T_PILHA;



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
int inicializa (T_PILHA *p)
{
  (*p).topo = -1 ;
  return 0;
}

/* ---------------------------------------------------------------------------- */
int estado(T_PILHA p)
{
    if(p.topo == -1 )
       return 0;  /* pilha vazia */
    else {
       if (p.topo == tamanho-1 )
          return 1;   /* pilha cheia */
       else
          return 2;  /* pilha não vazia com capacidade de armazenamento */
    }
}

/* ---------------------------------------------------------------------------- */
int empilha(T_PILHA *p, int x) /* PUSH */
{

    int erro = estado (*p);
    if ((erro == 0) || (erro == 2))
    {
       (*p).topo++;
       (*p).item[(*p).topo]=x;/* empilhamento efetuado */
       return 0;
    }
    else
       return 1; /* impossivel empilhar. overflow */
}

/* ---------------------------------------------------------------------------- */
int desempilha(T_PILHA *p)   /* POP */
{
    int erro = estado (*p);
    if (erro != 0)
    {
      (*p).topo--;  /* desempilhamento efetuado */
       return 0;
    }
    else
       return 1; /* impossivel desempilhar. Underflow */
}

/* ---------------------------------------------------------------------------- */
int listar(T_PILHA p)
{  int i,erro;
    erro = estado (p);
    if ((erro == 1) || (erro ==2))
    {
       for (i=0; i<=p.topo; i++)
           printf("%d\\ ",p.item[i]);
       printf(" (Topo)\n");
       return 0;
    }
    else return 1;  /* nao possivel listar pois a pilha vazia */
}


/* ---------------------------------------------------------------------------- */
int obter_topo(T_PILHA p, int *dado)
{  int i;
    if(p.topo == -1 )
       return 1;   /* pilha vazia */
    else {
       *dado =  p.item[p.topo];
       return 0;
    }
}
/* ---------------------------------------------------------------------------- */

int transfere(T_PILHA p, T_PILHA *p2)
{
    int dado;
    T_PILHA paux;
    inicializa (&paux);

    /* transferir para pilha auxiliar */
    while (estado(p)!=0)
    {
      obter_topo(p, &dado);
      desempilha (&p);
      empilha (&paux, dado);
    }

    printf("\nLista da pilha auxiliar\n");
    listar (paux);
    printf("\n");

    /* transferir para pilha destino */
     while (estado(paux)!=0)
    {
      obter_topo(paux, &dado);
      desempilha (&paux);
      empilha (p2, dado);
    }
    return (0);
}

int main(void)
{

	int info;
	int erro; /* valor de erro retornado pelas funcoes */
	T_PILHA s, s2;
	inicializa (&s2);
	int q;  /* receber a opcao do usuario */
	do {
	    system("cls");
	    gotoxy (20,1); printf("PILHA - LIFO");
		gotoxy(0,0); printf("\n\nOpcoes: \n\n");
		gotoxy(0,7);
		printf("1 -> Inicializa \n");
		printf("2 -> Insere\n");
		printf("3 -> Remove\n");
		printf("4 -> Verifica Estado de Vazio\n");
		printf("5 -> Lista \n");
		printf("6 -> Obter Topo \n");
		printf("7 -> Transferir para outra pilha \n");
		printf("8 -> Sair \n:");
		scanf("%d", &q);     /* Ler a opcao do usuario */
		switch(q) {
			case 1: erro=inicializa (&s);
                    printf("\nInicializacao realizada com sucesso !\n");
                    printf("\nPilha VAZIA \n");
                    system("pause");
					break;
			case 2: printf("Dado para insercao: ");
                    scanf("%d",&info);
                    erro=empilha(&s,info);
                    if (erro==1)
                       printf("\nPilha cheia. Overflow\n");
                    system("pause");
			        break;
            case 3: erro=desempilha(&s);
                    if (erro==1)
                       printf("\nPilha Vazia. Underflow\n");
                    system("pause");
                    break;
			case 4: erro=estado(s);
                    if (erro == 0)
			           printf("\nA pilha esta vazia.\n");
                    if (erro == 2)
			           printf("\nA pilha esta em condicoes de uso\n");
                    if (erro == 1)
			           printf("\nA pilha esta cheia.\n");
                    system("pause");
					break;
			case 5: erro= listar(s);
			        if (erro == 1)
			           printf("\nA pilha esta vazia.\n");
			        system("pause");
					break;
			case 6: erro= obter_topo(s, &info);
		        	if (erro == 0)
                    {
                       printf("Dado no topo: %d\n", info);
                    }
                    else
                       printf("Pilha vazia. Sem topo\n");
                    system("pause");
					break;
			case 7: erro= transfere(s, &s2);
		        	if (erro == 0)
                    {
                       printf("Transferencia realizada\n");
                       listar(s2);
                    }
                    else
                       printf("erro na transferencia");
                    system("pause");
					break;
			case 8: break;
			default: printf("\n\n Opcao nao valida");
		}
		getchar();    /* Limpa o buffer de entrada */
	} while ((q != 8) );
}
