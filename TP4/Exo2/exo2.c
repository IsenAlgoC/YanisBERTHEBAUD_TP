#include <stdio.h>
#include <stdlib.h>
#define SEPARATEUR '/' 
#define TAILLETAB1 20
int main() {
	int MyTab1[TAILLETAB1];


	for (int i = 0; i < TAILLETAB1; i++) {
		MyTab1[i] = i + 1;
		printf("%d %c ", MyTab1[i], SEPARATEUR);
	}
	int* MyPtr = &MyTab1[TAILLETAB1 - 1];
	printf("\n");
	for (int i = 0; i < TAILLETAB1; i++) {
		printf("%d %c ", *MyPtr, SEPARATEUR);
		--MyPtr;



	}





}