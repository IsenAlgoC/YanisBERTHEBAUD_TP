#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

	int tab[100];
	int MAX = 20;
	int MIN = 1;
	int valeur;
	srand(time(NULL));
	for (int i = 0; i < 100; i++) {
		tab[i] = (rand() % (MAX - MIN + 1)) + MIN;
	}
	int* MyPtr = &tab[0];
	for (int j = 0; j < 100; j = j + 10) {
		printf("| %d | %d | %d | %d | %d | %d | %d | %d | %d | %d |\n", tab[j], tab[j + 1], tab[j + 2], tab[j + 3], tab[j + 4], tab[j + 5], tab[j + 6], tab[j + 7], tab[j + 8], tab[j + 9]);
	}
	printf("Quelle valeur voulez vous trouver ?\n");
	scanf_s("%d", &valeur);
	for (int i = 0; i < 100; i++) {
		if (*MyPtr == valeur) {

			printf("%d est en position %d\n", valeur, i);
		}
		MyPtr++;
	}




}