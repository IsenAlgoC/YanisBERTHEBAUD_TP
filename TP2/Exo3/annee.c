#include <stdio.h>
#include <stdlib.h>

int main() {
	int a = 0;
	printf("entrez une ann�e inf�rieure � 10000\n");
	scanf_s("%d", &a);

	if (a % 100 == 0) {
		if (a % 400 == 0) {
			printf("C'est une ann�e bissextile");
		}
		else {
			printf("Ce n'est pas une ann�e bissextiles");
		}
	}
	else if (a % 4 == 0) {
		printf("C'est une ann�e bissextile");
	}
	else {
		printf("Ce n'est pas une ann�e bissextiles");
	}

	if (((a % 100 == 0) & (a % 400 == 0)) | (a % 4 == 0)) {
		printf("C'est une ann�e bissextile");

	}
	else {
		printf("Ce n'est pas une ann�e bissextiles");
	}
}