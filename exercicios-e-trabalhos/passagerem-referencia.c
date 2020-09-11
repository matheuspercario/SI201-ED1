/*PASSAGEM POR REFERENCIA*/
#include <stdio.h>

//FUNCAO f1

int f1 (int *b) 
{
	(*b)++;
	printf ("\'b'\ recebe endereço de \'a'\, entao \'b'\ eh: %d\n", *b);
	return 0;
}


int main () 
{
	int a;

	a = 2;
	printf ("\'a\' antes da chamada da funcao: %d\n", a);
	
	f1 (&a);
	
	printf ("\'a'\ depois da chamada da funcao: %d\n ", a);
	
return 0;
	
}
