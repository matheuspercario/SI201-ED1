//---------------------------------------------------------------------------
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <string.h>
//---------------------------------------------------------------------------
#define tamanho 10  // tamanho maximo da FILA
/* -----------------------------------------------------------------------------
Estrutura FILA ESTATICA
------------------------------------------------------------------------------*/

typedef struct fila{
        int item [tamanho] ;  
        int inicio, fim;
} T_FILA;  



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



// ==================================================================
int  inicializa (T_FILA *f) 
{  
  (*f).inicio = -1 ;
  (*f).fim = -1; 
  return 0;
}  

// ==================================================================
int estado(T_FILA f)
{  
    if ((f.inicio == -1 ) || (f.inicio == tamanho) || (f.inicio == f.fim+1))
       return 0;  // fila vazia
    else {
       if (f.fim == tamanho-1 ) 
          return 1;   // fila cheia
       else
          return 2;  // fila não vazia com capacidade de armazenamento
    }
}  

// ==================================================================
int insere(T_FILA *f, int x)
{  
    
    int erro = estado (*f);
    if ((erro == 0) || (erro == 2))
    {
       (*f).fim++;
       (*f).item[(*f).fim]=x;// inserção efetuada
       if ((*f).inicio == -1)
          (*f).inicio = 0;
       return 0;   
    }
    else
       return 1; // impossivel inserção. overflow
}  

// ==================================================================
int remove(T_FILA *f) 
{  
    int erro = estado (*f);
    if (erro != 0)
    {
      (*f).inicio++;  // remocao efetuada
       printf("INIcio: %d",(*f).inicio);
       system("pause");
       return 0;   
    }
    else
       return 1; // impossivel remover. Underflow
}  

// ==================================================================
int listar(T_FILA f)
{  int i,erro;
    erro = estado (f);
    if ((erro == 1) || (erro ==2))
    {
       for (i=f.inicio; i<=f.fim; i++)
           printf("%d - ",f.item[i]);
       printf("\n");
       return 0;
    }
    else return 1;  // nao possivel listar pois a fila esta vazia
}


// ==================================================================
int obter_primeiro(T_FILA f, int *dado)
{  int i;
    if ((f.inicio == -1 ) || (f.inicio == tamanho) || (f.inicio == f.fim+1))
       return 1;   // fila vazia
    else {
       *dado =  f.item[f.inicio];
       return 0;
    }
}
// ==================================================================
// ==================================================================

int main(void)
{

	int info;
	int erro; /* valor de erro retornado pelas funcoes */
	T_FILA s;
	
	
	int q;  /* receber a opcao do usuario */
	do {
	    system("cls");
	    gotoxy (20,1); printf("FILA Estatica");
		gotoxy(0,0); printf("\n\nOpcoes: \n\n");
		gotoxy(0,7);
		printf("1 -> Inicializa \n");
		printf("2 -> Insere\n");
		printf("3 -> Remove\n");
		printf("4 -> Verifica Estado de Vazio\n");
		printf("5 -> Lista \n");
		printf("6 -> Obter Primeiro \n");
		printf("7 -> \n");
		printf("8 -> Sair \n:");
		scanf("%d", &q);     /* Ler a opcao do usuario */
		switch(q) {
			case 1: erro=inicializa (&s);  
                    printf("\nInicializacao realizada com sucesso !\n");
                    printf("\nFila VAZIA \n");
                    system("pause");
					break;
			case 2: printf("Dado para insercao: ");
                    scanf("%d",&info);
                    erro=insere(&s,info); 
                    if (erro==1)
                       printf("\nFila cheia. Overflow\n"); 
                    system("pause");
			        break;
            case 3: erro=remove(&s);
                    if (erro==1)
                       printf("\nFila Vazia. Underflow\n"); 
                    system("pause");
                    break;
			case 4: erro=estado(s);
                    if (erro == 0)
			           printf("\nA fila esta vazia.\n");
                    if (erro == 2)
			           printf("\nA fila esta em condicoes de uso\n");
                    if (erro == 1)
			           printf("\nA fila esta cheia.\n");
                    system("pause");
					break;
			case 5: erro= listar(s);
			        if (erro == 1)
			           printf("\nA fila esta vazia.\n");
			        system("pause");
					break;
			case 6: erro= obter_primeiro(s, &info);
		        	if (erro == 0)
                    {
                       printf("Dado no inicio: %d\n", info);
                    }
                    else 
                       printf("fila vazia. Sem primeiro\n");
                    system("pause");
					break;
			case 7: 
					break;
			case 8: break;
			default: printf("\n\n Opcao nao valida");
		}
		getchar();    /* Limpa o buffer de entrada */
	} while ((q != 8) );
}
