#include <stdio.h>
#include <stdlib.h>
#include "exo1.h"

int main() {
	HEURE HeureDebut = { 12, 30 };
	HEURE HeureFin;
	HEURE Duree = { 00, 45 };

	HeureFin.heure = HeureDebut.heure + Duree.heure + (int)((HeureDebut.minute + Duree.minute) / 60);
	HeureFin.minute = (HeureDebut.minute + Duree.minute) % 60;
	printf("HeureDebut = %d:%d\n", HeureDebut.heure, HeureDebut.minute);
	printf("HeureFin = %d:%d\n", HeureFin.heure, HeureFin.minute);
	printf("Duree = %d:%d\n", Duree.heure, Duree.minute);



}