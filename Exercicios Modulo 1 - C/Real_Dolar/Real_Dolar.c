#include <stdio.h>
#include <stdlib.h>

int main() {

	float real;
	float cotacao;
	float total;

	printf("Informe o valor em BRL: ");
		scanf("%f", &real);
	printf("\nInforme a cotacao do USD em BRL: ");
		scanf("%f", &cotacao);

	total = real/cotacao;
	printf ("\Em USD: %.2f\n", total);

	return 0;
}
