#include <stdio.h>
#include <stdlib.h>
/* Implementação de Arvore Binaria */

typedef int Tipo_Dado;

typedef struct bloco_ab
        {
           Tipo_Dado          Dado;
           struct bloco_ab    *FilhoEsq, *FilhoDir;
           struct bloco_ab    *Pai;  /* adicionalmente foi incluido o ponteiro para pai */
        }  Nodo_AB;

FILE *saida;



int inicializa_arvbin  	(Nodo_AB **AB);
int insere_ord_arvbin   (Nodo_AB **AB, Tipo_Dado Dado);
int remove_dado_arvbin 	(Nodo_AB **AB, Tipo_Dado Dado);
int exibe_ab_infixado  	(Nodo_AB  *AB);
int exibe_ab_prefixado 	(Nodo_AB  *AB);
int exibe_ab_posfixado 	(Nodo_AB  *AB);

// EXERCICIOS
int maior_arvbin        (Nodo_AB  *AB); //*
int menor_arvbin        (Nodo_AB  *AB); //*

// EXERCICIO int apaga_arvbin       	(Nodo_AB **AB); -- apaga toda a arvore
// EXERCICIO int conta_nodos_arvbin  	(Nodo_AB  *AB); -- conta quant. de nós na arvore
// EXERCICIO int pesquisa_arvbin     	(Nodo_AB  *AB, Tipo_Dado Dado, int *resp); -- procura por dado na árvore
// *EXERCICIO int menor_arvbin        	(Nodo_AB   *AB, Tipo_Dado Dado, Tipo_Dado *menor); /* -- obtem o primeira menor que 
// *EXERCICIO int maior_arvbin       	(Nodo_AB   *AB, Tipo_Dado Dado, Tipo_Dado *maior); /* -- obtem o primeira maior que 
// **EXERCICIO int sucessor_arvbin     	(Nodo_AB  *AB, Tipo_Dado Dado_in, Tipo_Dado *Dado_out); -- obtem filho direito de
// **EXERCICIO int predecessor_arvbin  	(Nodo_AB  *AB, Tipo_Dado Dado_in, Tipo_Dado *Dado_out); -- obtem pai de



/* -----------------------------------------------------------------------------
FUNCOES AUXILIARES
------------------------------------------------------------------------------*/
// GERA DADOS ALEATORIOS =============================
int gera_dado(int min, int max)
{
    int k;
    double d;
    d = (double) rand () / ((double) RAND_MAX + 1);
    k = d * (max - min + 1);
    return min + k;
}

// IMPRIME NA TELA E NO ARQ ==========================
void imprimeNo(int d, int p, int b) {
    int i;
    // em tela
    for (i = 0; i < b; i++) printf("|------");
    printf("%d(%d)\n", d,p);
    // em arquivo
    for (i = 0; i < b; i++) fprintf(saida,"|------");
    fprintf(saida,"%d(%d)\n", d,p);
}

/* -----------------------------------------------------------------------------
INICIALIZA
------------------------------------------------------------------------------*/
int  inicializa_arvbin (Nodo_AB **AB)
{
  *AB = NULL;
  return 0;
}

/* -----------------------------------------------------------------------------
INSERE ordenadamente
------------------------------------------------------------------------------*/
int insere_ord_arvbin (Nodo_AB **AB, Tipo_Dado Dado)
{
   /* Arvore binaria onde os nós sao inseridos de maneira ordenada:   */
   /* - Os nós a esquerda de um nó pai sao sempre menores que ele   */
   /* - Os nós a direita de um nó pai sao sempre maiores que ele    */

   Nodo_AB *novo,  *aux, *temp;

   novo = (Nodo_AB *) malloc (sizeof (Nodo_AB));
   if ( novo == NULL ) return 1;

   novo -> Dado = Dado;
   novo -> FilhoEsq = NULL;
   novo -> FilhoDir = NULL;
   aux = *AB;

   while ( aux != NULL )     /* Acha o ponto onde vai inserir */
   {
      temp = aux; // guarda sempre 1 nivel antes (pai)
      if (Dado == (aux -> Dado))
        return 1;  // inserção nao realizada - dado já existe na árvore
      if ( Dado > (aux -> Dado))
         aux = aux -> FilhoDir;                         /*  insere_ord_arvbin (aux -> FilhoDir, Dado)  */
      else
         aux = aux -> FilhoEsq;                         /*  insere_ord_arvbin (aux -> FilhoEsq, Dado)  */
   }

   if ( aux == *AB) 		/* Insercao - Arvore vazia */
   {
      novo -> Pai = NULL;
      *AB = novo;
   }
   else
   {
      novo -> Pai = temp;
      if (Dado > temp->Dado)
          temp -> FilhoDir = novo;
      else
          temp -> FilhoEsq = novo;
   }
   // chamar verifica balanceamento
   // chamar balacear
   return 0 ;  // inserção realizada
}

/* -----------------------------------------------------------------------------
EXIBIR
------------------------------------------------------------------------------*/
void mostraArvore(Nodo_AB *Pai, Nodo_AB *AB, int b)
{
    if (AB == NULL) {
        //imprimeNo(0, Pai->Dado, b);  // não mostra os filhos nulos
        return;
    }
    mostraArvore(AB,AB->FilhoDir, b+1);
    if ((AB->Pai)!= NULL) // se estive nao esta na raiz
        imprimeNo(AB->Dado, (AB->Pai)->Dado, b);
    else
        imprimeNo(AB->Dado, 0, b);
    mostraArvore(AB,AB->FilhoEsq, b+1);
}
// ==========================================
int maior_arvbin (Nodo_AB *AB, Tipo_Dado *maior_dado)
{
	Nodo_AB *aux;
	aux = AB;
	
	if(AB == NULL)
	{
		return 1; // Arvore vazia
	}
	
	while (aux->FilhoDir != NULL)
	{
		aux = aux->FilhoDir;	
	}
	(*maior_dado) = aux->Dado;
}
// ==========================================
int menor_arvbin(Nodo_AB *AB, Tipo_Dado *menor_dado)
{
	Nodo_AB *aux;
	aux = AB;
	
	if(AB == NULL)
	{
		return 1; // Arvore vazia
	}
	
	while (aux->FilhoEsq != NULL)
	{
		aux = aux->FilhoEsq;	
	}
	(*menor_dado) = aux->Dado;
}

// ==========================================
int exibe_ab_infixado (Nodo_AB *AB)
{
   if ( AB != NULL )
   {
      exibe_ab_infixado ( AB -> FilhoEsq); //1
      printf ("%d ", AB -> Dado);          //2
      exibe_ab_infixado ( AB -> FilhoDir); //3
   }
}

// ==========================================
int exibe_ab_prefixado (Nodo_AB *AB)
{
   if ( AB != NULL )
   {
      printf ("%d ", AB -> Dado);
      exibe_ab_prefixado ( AB -> FilhoEsq);
      exibe_ab_prefixado ( AB -> FilhoDir);
   }
}

// ==========================================
int exibe_ab_posfixado (Nodo_AB *AB)
{
   if ( AB != NULL )
   {
      exibe_ab_posfixado ( AB -> FilhoEsq);
      exibe_ab_posfixado ( AB -> FilhoDir);
      printf ("%d ", AB -> Dado);
   }
}

// ==========================================
void exibe_maiores (Nodo_AB *AB, int x, int *total)
{
   if ( AB != NULL )
   {
      exibe_maiores ( AB -> FilhoEsq, x, total);
      exibe_maiores ( AB -> FilhoDir, x, total);
      if (AB -> Dado > x )
         (*total)++;
   }
}

// ==========================================
void exibe_maiores_menores_que (Nodo_AB *AB, int x, int y, int *total)
{
   if ( AB != NULL )
   {
      exibe_maiores_menores_que ( AB -> FilhoEsq, x, y, total);
      exibe_maiores_menores_que ( AB -> FilhoDir, x, y, total);
      if ((AB -> Dado > x ) && (AB -> Dado < y))
         (*total)++;
   }
}

/* -----------------------------------------------------------------------------
BALANCEAMENTO - Altura, Largura
------------------------------------------------------------------------------*/
void ver_balanc (Nodo_AB *AB, int *resp, int *alt)
{
    int resp_e, resp_d;
    int alt_e, alt_d;
   if ( AB != NULL )
   {
     ver_balanc ( AB -> FilhoEsq, &resp_e, &alt_e );
     ver_balanc ( AB -> FilhoDir, &resp_d, &alt_d );

     /* Calculando a altura do nível */
     if (alt_e >= alt_d)
        *alt = alt_e+1;
     else
        *alt = alt_d+1;

     /* Calculando o balenceamento */
     if (((alt_e == alt_d)||(alt_e == alt_d+1)||(alt_e+1 == alt_d))&&(resp_e==1)&&(resp_d==1))
        *resp = 1; /* sim - balanceado */
     else
        *resp = 0; /* não balanceado */
   }
   else
   {
       *resp = 1; /* sim - balanceado */
       *alt = 0;
   }
}
	
	/* Calculando a largura */ 
/* NAO faz parte da funcao "balanceamento" */
void calc_largura(Nodo_AB *AB, int *larg)
{
    if (AB->FilhoEsq != NULL)
    {
        calc_largura(AB->FilhoEsq, larg);
        (*larg)++;
    }
    if (AB->FilhoDir != NULL)
    {
        calc_largura(AB->FilhoDir, larg);
        (*larg)++;
    }
}

/* -----------------------------------------------------------------------------
SOMA de nós de um nivel
------------------------------------------------------------------------------*/
int Soma (Nodo_AB *AB, int *total)
{		
	if (AB != NULL)
	{
		Soma (AB->FilhoEsq, total);
		Soma (AB->FilhoDir, total);
		(*total) += AB->Dado;		
	}
}

/* -----------------------------------------------------------------------------
PRINCIPAL
------------------------------------------------------------------------------*/
int main ()
{
	
  int i, q, quant, min, max, dado, erro, larg=1 ;
  Nodo_AB *Arvore;
  inicializa_arvbin (&Arvore);
  int resp, alt;
  int x, y, total;
  
  int maior_dado, menor_dado, sucessor, predecessor;

do {
	    system("cls");
        printf("Arvore Binaria de Busca\n\n");
		printf("\n\nOpcoes: \n\n");
        printf("0 -> Inicializa\n");
		printf("1 -> Insere quant. de dados aleatorios\n");
		printf("2 -> Insere um unico dado\n");
		printf("3 -> Mostra Arvore em forma hierarquica\n");
		printf("4 -> Mostra Dados da Arvore em Ordem\n");
		printf("5 -> Mostra Dados da Arvore em Pre-Ordem\n");
		printf("6 -> Mostra Dados da Arvore em Pos-Ordem\n");
		printf("7 -> Verifica balanceamento, altura e largura\n");
		printf("8 -> Exibe total de maiores que um dado\n");
		printf("9 -> Exibe maior dado da arvore\n");
		printf("10 -> Exibe menor dado da arvore\n");
		printf("11 -> Exibe total maiores que X e menores que Y\n");
		printf("12 -> Soma do nivel 2\n");
		printf("13 -> Sair \n:");
		scanf("%d", &q);     /* Ler a opcao do usuario */
		switch(q) {
            case 0: /* Inicializa a arvore */
					inicializa_arvbin (&Arvore);
                    break;
                    
			case 1: /* inserção de dados aleatorios para teste */
                    printf("Quantidade de Dados desejados: ");
                    scanf("%d",&quant);
                    printf("Valor MINIMO no intervalo de geracao do inteiro aleatorio: ");
                    scanf("%d",&min);
                    printf("Valor MAXIMO no intervalo de geracao do inteiro aleatorio: ");
                    scanf("%d",&max);
                    // sugestoes
                    //quant = 20
                    //min = 6;
                    //max = 500;

                    dado = gera_dado(min, max);  // desprezando o primeiro gerado

                    for (i=1; i<=quant; i++)
                    {
                        dado = gera_dado(min, max);
                        printf("dado = %d\n",dado);
                        insere_ord_arvbin(&Arvore, dado);
                    }
                    system("pause");
					break;

			case 2: /* insere um dado */
			        printf("Dado = ");
			        scanf("%d",&dado);
                    erro = insere_ord_arvbin(&Arvore, dado);
                    if (erro==1) printf("Insercao nao realizada - Dado ja existente\n\n");
                    else printf("Insercao realizada com sucesso\n\n");
			        system("pause");
			        break;

            case 3: /* mostra arvore em forma de árvore*/
                    // preparando arquivo
                    saida = fopen("saida.txt", "wt");
                    if(saida == NULL)
                    {
                        printf("\nImpossivel abrir arquivo de saida.\n");
                        system("pause");
                    }
                    fprintf(saida,"\nMostra Arvore Ordenada\n\n\n");
                    printf("\nMostra Arvore Binaria Ordenada\n");
                    mostraArvore(NULL,Arvore, 1);
                    printf("\n\n");
                    fclose(saida);
                    system("pause");
                    break;

			case 4: /* mostra dados em ordem */
			        printf("\nMostra Arvore: modo infixado (ordem)\n");
                    exibe_ab_infixado(Arvore);
                    printf("\n\n");
                    system("pause");
					break;

			case 5: /* mostra dados em pre-ordem */
			        printf("\n\nMostra Arvore: modo prefixado (pre-ordem)\n");
                    exibe_ab_prefixado(Arvore);
                    printf("\n\n");
                    system("pause");
					break;

			case 6: /* mostra dados em pos-ordem */
			        printf("\n\nMostra Arvore: modo posfixado (pos-ordem)\n");
                    exibe_ab_posfixado(Arvore);
                    printf("\n\n");
                    system("pause");
					break;
					
			case 7: /* verifica balanceamento e altura */
                    ver_balanc (Arvore, &resp, &alt);
                    calc_largura(Arvore, &larg);
                    printf("Balanceado (0-nao 1-sim) : %d\n",resp);
                    printf("Altura da Arvore : %d\n",alt);
                    printf("Largura da Arvore: %d\n",larg);
                    system("pause");
					break;

            case 8: /* exibe maiores que um dado */
            		total = 0;
                    printf("Digite dado: ");
                    scanf("%d",&x);
                    exibe_maiores (Arvore, x, &total);
                    printf("Total de Dados maiores que %d : %d\n\n",x,total);
                    system("pause");
					break;
					
			case 9: /* exibe maior dado da arvore */
					erro=maior_arvbin(Arvore, &maior_dado);
					if (erro==1) printf("\n\nArvore Vazia\nImpossivel mostrar maior dado!\n");
					else printf("Maior dado da arvore eh: %d\n", maior_dado);
					system("pause");
					break;
				
			case 10: /* exibe menor dado da arvore */
					erro=menor_arvbin(Arvore, &menor_dado);
					if (erro==1) printf("\n\nArvore Vazia\nImpossivel mostrar menor dado!\n");
					else printf("Menor dado da arvore eh: %d\n", menor_dado);
					system("pause");
					break;
					
			case 11: /* TESTE - Maior que e menor que... "X" */
					total = 0;
                    printf("Digite dado(x): ");
                    scanf("%d",&x);
                    printf("Digite dado(y): ");
                    scanf("%d",&y);
                    exibe_maiores_menores_que (Arvore, x, y, &total);
                    printf("Total de Dados maiores que %d e menores que %d : %d\n\n", x, y, total);
                    system("pause");
					break;	
			
			case 12: /* Soma do nivel 2 */
					total = 0;
					Soma (Arvore, &total);
					printf("A soma dos elementos da arvore eh: %d\n", total);	
					system("pause");
					break;		
					
			case 13: break;
			default: printf("\n\n Opcao nao valida");
		}
		getchar();    /* Limpa o buffer de entrada */
	} while ((q != 13) );
  system("pause");
}
