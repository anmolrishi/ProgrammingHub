#include <stdio.h>

/*	The  tetranacci numbers are a generalization of the fibonacci
 *	sequence, which starts with four predetermined terms. Each 
 *	succeeding term is the sum of its four preceding terms.
 */

int tetranacci(int n);

int main()
{
	int term;

	printf("Insert a positive integer: ");
	scanf("%d", &term);
	printf("The term %d from tetranacci is  %d.\n", term, tetranacci(term));

	return 0;
}

int tetranacci(int n)
{
	if (n == 0)
		return 0;
	if ( n == 1 || n == 2)
		return 1;	
	if (n == 3)
		return 2;
	else
		return tetranacci(n-4) + tetranacci(n-3) + tetranacci(n-2) + tetranacci(n-1);
}
