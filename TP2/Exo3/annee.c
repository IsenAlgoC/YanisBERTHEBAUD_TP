#include <stdio.h>
#include <stdlib.h>

int main() {
	int a = 0;
	printf("entrez une année inférieure à 10000\n");
	scanf_s("%d", &a);

	if (a % 100 == 0) {
		if (a % 400 == 0) {
			printf("C'est une année bissextile");
		}
		else {
			printf("Ce n'est pas une année bissextiles");
		}
	}
	else if (a % 4 == 0) {
		printf("C'est une année bissextile");
	}
	else {
		printf("Ce n'est pas une année bissextiles");
	}

	if (((a % 100 == 0) & (a % 400 == 0)) | (a % 4 == 0)) {
		printf("C'est une année bissextile");

	}
	else {
		printf("Ce n'est pas une année bissextiles");
	}
}