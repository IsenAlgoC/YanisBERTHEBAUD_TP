#include <stdio.h>
#include <stdlib.h>

void echanger(float* val1, float* val2) {
	float tmp;
	tmp = *val1;
	*val1 = *val2;
	*val2 = tmp;

}


int main() {
	// on entre longueur, largeur et épaisseur
	int boucle = 1;
	while (boucle == 1) {
		float a = 0;
		float b = 0;
		float c = 0;

		while (((a < 1) | (a > 150)) | ((b < 1) | (b > 150)) | ((c < 1) | (c > 150))) {
			printf("Entrez les dimensions comprise entre 1cm et 150cm sans excéder 55x35x25\n");
			scanf_s("%f", &a);
			scanf_s("%f", &b);
			scanf_s("%f", &c);


		}

		//on trie du plus petit au plus grand
		if (a > b) {
			echanger(&a, &b);
		}
		if (a > c) {
			echanger(&a, &c);
		}
		if (b > c) {
			echanger(&b, &c);
		}


		if ((a <= 25) & (b <= 35) & (c <= 55)) {
			printf("valide\n");
		}
		else
			printf("non valide\n");
	}
}