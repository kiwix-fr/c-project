#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct utilisateur_s{
	int jour;
	char mois[150];
	int annee;
};

struct utilisateur_s lire_date();
void affiche_date(struct utilisateur_s date);
void jour_ferie(struct utilisateur_s date);

int main(){
	

	struct utilisateur_s date1 = lire_date();

	affiche_date(date1);
	jour_ferie(date1);

	return EXIT_SUCCESS;
}

struct utilisateur_s lire_date(){
	// Initialise la date dans son struct
	struct utilisateur_s date1;

	printf("Saisir une date : (format : Jour Mois Annee)\n");
	scanf("%d %s %d", &date1.jour, date1.mois, &date1.annee);

	return date1;
}

void affiche_date(struct utilisateur_s date){
	// S'occupe d'afficher la date.
	printf("La date saisie  est : ");
	printf("%d ", date.jour);
	printf("%s ", date.mois);
	printf("%d\n", date.annee);
}

void jour_ferie(struct utilisateur_s date){
	int tab1[11] = {1, 1, 1,  8, 9, 20, 14, 15, 1, 11, 25};
	char tab2[15][11] = {"Janvier", "Avril", "Mai", "Mai", "Mai", "Mai", "Juillet", "Aout", "Novembre", "Novembre", "Decembre"};
	int ferie = 0;

	
	for (int i = 0; i<11; i++){
		if (date.jour == tab1[i] && strcmp(date.mois, tab2[i]) == 0){
			ferie=1;
		}
	}
	
	if (ferie){
		printf("Le %d %s %d est ferie\n", date.jour, date.mois, date.annee);
	} else {
		printf("Le %d %s %d n'est pas ferie\n", date.jour, date.mois, date.annee);
	}

	printf("Ne fonctionne que pour l'année 2024\n");
	
}
