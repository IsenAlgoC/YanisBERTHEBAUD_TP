#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TAILLEINITIALE 100

typedef struct Tableau {
	int* elt; // le tableau d�entiers
	int size; // la taille de ce tableau d�entiers
	int eltsCount; // le nombre d��l�ments dans le tableau
} TABLEAU;

TABLEAU newArray() {
	TABLEAU tab;
	tab.size = TAILLEINITIALE;     //on initialise la taille
	tab.elt = (int*)malloc(tab.size * sizeof(int));   //on alloue la m�moire n�cessaire
	if (tab.elt == NULL) return tab;   //on v�rifie que la m�moire s'est bien allou�e
	for (int i = 0; i < tab.size; i++) {   //on initialise � 0 le tableau
		*(tab.elt + i) = 0;
	}
	tab.eltsCount = 0;
	return tab;
}

int incrementArraySize(TABLEAU* tab, int incrementValue) {
	if (((*tab).elt == NULL) || (incrementValue <= 0)) return -1;   //on v�rifie que tout est valide pour faire l'incr�mentation
	int* tmp = (*tab).elt;     //vatiable temporaire au cas ou la m�moire n'est pas allou�e
	(*tab).elt = (int*)realloc((*tab).elt, ((*tab).size + incrementValue) * sizeof(int)); //on alloue la nouvelle m�moire
	if ((*tab).elt == NULL) { //on v�rifie que la m�moire est bien allou�e
		(*tab).elt = tmp;
		return -1;
	}
	for (int i = (*tab).size; i < (*tab).size + incrementValue - 1; i++) {  //on met � 0 toutes les nouvelles valeurs
		(*tab).elt[i] = 0;
	}
	(*tab).size += incrementValue;  //on augmente la taille du tableau
	return (*tab).size;
}

int setElement(TABLEAU* tab, int pos, int element) {
	if (((*tab).elt == NULL) || (pos < 1)) return 0;  //on v�rifie que tout est valide
	if (pos - 1 < (*tab).size) {    //premier cas si on ne d�passe pas la m�moire allou�e
		(*tab).elt[pos - 1] = element;  //on incruste l'�lement
		return 0;
	}
	else {

		if (incrementArraySize(tab, pos - (*tab).size) == -1) return 0;  //si on d�passe la m�moire, on l'augmente
		(*tab).elt[pos - 1] = element;  //on ajoute l'�lement
		return pos;

	}
}

int displayElements(TABLEAU* tab, int startPos, int endPos) {
	int temp;
	if (((*tab).elt == NULL) || (startPos < 1) || (endPos > (*tab).size) || (endPos < 1) || (startPos > (*tab).size)) return -1; //on v�rifie que tout est valide
	if (startPos > endPos) {  //si start est > � end, on les �changes
		temp = startPos;
		startPos = endPos;
		endPos = temp;
	}
	if (startPos == endPos) { //s'ils sont �gaux, on ne display qu'un �l�ment
		printf("pos %d : %d\n", startPos, (*tab).elt[startPos - 1]);
		return 0;
	}
	for (int i = startPos - 1; i < endPos; i++) {  //sinon on display tout entre start et end
		printf("%d ", (*tab).elt[i]);
	}
	return 0;
}

int deleteElements(TABLEAU* tab, int startPos, int endPos) {
	int* tmp; //variable pour enregistrer le tableau
	int temp; //variable pour �changer start et end
	if (((*tab).elt == NULL) || (startPos < 1) || (endPos > (*tab).size)) return -1; //on v�rifie que tout est valide
	if (startPos > endPos) { //�change si start > end
		temp = startPos;
		startPos = endPos;
		endPos = temp;
	}
	if (startPos == endPos) {  //on supprime un seul �l�ment, et on d�cale tout les �l�ments apr�s celui supprim� vers la gauche
		for (int i = startPos - 1; i < (*tab).size - 1; i++) {
			(*tab).elt[i] = (*tab).elt[i + 1];
		}
		tmp = (*tab).elt;
		(*tab).elt = (int*)realloc((*tab).elt, ((*tab).size - 1) * sizeof(int)); // on enm�ve 1 m�moire comme on supprime 1 �l�ment
		if ((*tab).elt == NULL) { //on v�rifie que la m�moire s'est bien r�allou�e
			(*tab).elt = tmp;
			return -1;
		}
		return (*tab).size;
	}
	for (int i = startPos - 1; i < (*tab).size - (endPos - startPos + 1); i++) {  // cas ou on supprime plusieurs �l�ments
		(*tab).elt[i] = (*tab).elt[i + endPos - startPos + 1]; //on d�cale tout ce qu'il y a apr�s end vers start (d�calage de "n" vers la gauche)
	}
	tmp = (*tab).elt;
	(*tab).elt = (int*)realloc((*tab).elt, ((*tab).size - (endPos - startPos + 1)) * sizeof(int)); //on r�alloue la m�moire 
	if ((*tab).elt == NULL) { //on v�rifie qu'on a bien allou�
		(*tab).elt = tmp;
		return -1;
	}
	return (*tab).size;
}

int main() {
	TABLEAU tab = newArray();
	setElement(&tab, 1, 1);     //test: on met un �l�ment en pos 1 et pos 4, on display, puis on supprime la pos 2 et 3 pour voir si le delete fonctionne
	setElement(&tab, 4, 4);
	displayElements(&tab, 1, 4);
	deleteElements(&tab, 2, 3);
	printf("\n");
	displayElements(&tab, 1, 4);

	return EXIT_SUCCESS;
}