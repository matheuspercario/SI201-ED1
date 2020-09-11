/*PASSAGEM POR VALORES*/
#include <stdio.h>

//FUNÇÃO f1

int f1 (int b) 
{
	b++;
	printf ("%d\n", b);
	return 0;
}


int main () 
{
	int a;
	a = 2;
	
	f1 (a);
	
	printf ("%d\n", a);
	
return 0;
}

