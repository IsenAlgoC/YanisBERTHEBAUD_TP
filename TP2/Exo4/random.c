#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
	srand(time(NULL));
	int nombre = rand();
	int a = 0;
	int compteur = 0;


	while (a != nombre) {
		printf("Entrez un nombre entre 1 et 100\n");
		scanf_s("%d", &a);
		if (a < nombre) {
			printf("trop petit\n");
			compteur += 1;
		}
		else if (a > nombre) {
			printf("trop grand\n");
			compteur += 1;
		}
		printf("%d\n", nombre);
	}

	printf("Bravo, le nombre etait: %d   score : %d\n", nombre, compteur);
}