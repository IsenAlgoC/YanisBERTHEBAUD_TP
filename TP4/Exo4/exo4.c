#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
	char mot[20];
	int taille;
	int moitie;
	bool pareil = true;
	printf("entrez le mot à tester\n");
	scanf_s("%s", &mot, (unsigned)_countof(mot));
	taille = strlen(mot);
	moitie = (int)(taille / 2);
	for (int i = 1; i <= moitie; i++) {
		if (mot[i - 1] != mot[taille - i]) {
			pareil = false;

		}

	}
	if (pareil == true) {
		printf("%s est un palindrome\n", mot);

	}
	else {
		printf("%s n'est pas un palindrome\n", mot);
	}


}