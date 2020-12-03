#include <stdio.h>
#include <stdlib.h>

int main() {
	int sum = 0;
	int i = 1;
	int n = 1;

	//for avec la demande de n
	scanf_s("%d", &n);

	while (n > 361) {
		printf("\nEntrer une valeur valable de n pour la boucle FOR (nombre entier inferieur a 361!) : ");
		scanf_s("%d", &n);
	}

	for (i = 1; i <= n; i++) {
		sum += i;
	}
	printf("La somme des entiers allant de 1 à %d  (boucle for) est %d\n", n, sum);

	int sum2 = 0;
	int j = 0;
	while (j < 100) {
		j += 1;
		sum2 += j;


	}
	printf("La somme des entiers allant de 1 à 100  (boucle while) est %d\n", sum2);

	int k = 0;
	int sum3 = 0;
	do {
		k += 1;
		sum3 += k;

	} while (k < 100);
	printf("La somme des entiers allant de 1 à 100  (boucle do) est %d\n", sum3);

	// 2 eme point 

	int sum4 = 0;
	int l = 0;
	int m = 1;
	printf("entrez m\n, le nombre max est %d\n", USHRT_MAX);
	scanf_s("%d", &m);
	while ((l < m) & ((USHRT_MAX - sum4) >= l)) {
		l += 1;
		sum4 += l;
	}
	printf("la somme est égale à %d et la valeur de m est %d\n", sum4, l);

	//la valeur max  de m est 361, et la somme vaut 65341

}