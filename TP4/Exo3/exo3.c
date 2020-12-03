#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include<locale.h>

int main() {
	char nom[20];
	char prenom[20];
	char sexe;
	printf("entrez votre sexe (H ou F)\n");
	sexe = _getch();
	sexe = toupper(sexe);
	printf("entrez votre nom\n");
	scanf_s("%s", &nom, (unsigned)_countof(nom));
	printf("entrez votre prenom\n");
	scanf_s("%s", &prenom, (unsigned)_countof(prenom));


	if (sexe == 'H') {
		printf("Monsieur %s %s\n", prenom, nom);
	}
	else {
		printf("Madame %s %s\n", prenom, nom);
	}


}