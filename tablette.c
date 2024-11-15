// AUTOR : KIWIX_FR (kiwix.shell@gmail.com)

// Objectif : Ne pas obtenir la tablette quand il reste qu'une ligne et qu'une colonne.

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define AI 0
#define PLAYER 1
#define NB_COLONNE 10
#define NB_LIGNE 8

struct utilisateur_s{
	int ligne, colonne; 
};

int partie_perdue(struct utilisateur_s tablette);
void affichage(struct utilisateur_s tablette);
struct utilisateur_s joueur(struct utilisateur_s tablette);
struct utilisateur_s opposant(struct utilisateur_s tablette);

int main(){
	struct utilisateur_s tablette = {NB_LIGNE, NB_COLONNE};
	int fini = partie_perdue(tablette);
	int qui_le_tour = 1;


	while (!fini){
		affichage(tablette); // Affiche la tablette avant chaque tour 

		// Gère le tour du joueur
		if (qui_le_tour % 2 == PLAYER){ 
			tablette = joueur(tablette);
			fini = partie_perdue(tablette);
		}

		// Gère le tour de L'IA
		if (qui_le_tour % 2  == AI){
			tablette = opposant(tablette);
			fini = partie_perdue(tablette);
		}
		qui_le_tour+=1; // Incrémente le compteur
	}

	affichage(tablette); // Affiche la tablette après la fin de la partie.

	// Affichage du résultat 
	if (qui_le_tour % 2 == PLAYER){
		printf("BRAVO VOUS AVEZ GAGNE !\n");
	} else {
		printf("BOOH VOUS AVEZ PERDU !\n");
	}

	return EXIT_SUCCESS;

}

int partie_perdue(struct utilisateur_s tablette){
	// Regarde si la tablette est toujours jouable.

	if (tablette.ligne == 1 && tablette.colonne == 1){
		printf("LA PARTIE EST TERMINEE\n\n");
		return 1;
	} else {
		return 0;
	}
}

void affichage(struct utilisateur_s tablette){
	printf("La tablette comporte :\n%d colonne\n%d lignes\n\n", tablette.colonne, tablette.ligne);
}

struct utilisateur_s joueur(struct utilisateur_s tablette){
	char choix;

	// Demande le choix à l'utilisateur
	printf("Que souhaitez vous faire ? l = retirer ligne, c = retirer colonne\n");
	scanf("%s", &choix);
	printf("\n\n");

	// Gère les opérations à faire sur les attributs de la tablette.
	if (choix == 'l'){
		tablette.ligne-=1;
	} else if (choix == 'c'){
		tablette.colonne-=1;
	}
	return tablette;
}

struct utilisateur_s opposant(struct utilisateur_s tablette){
	srand(time(NULL));
	int choix = 0;

	// Choix d'un nombre aléatoire entre 1 et 2
	choix = rand()%2+1;

	// Gère les déplacements impossible
	if (tablette.colonne == 1){
		choix = 1;
	} else if (tablette.ligne == 1){
		choix = 2;
	}

	// Gère les modifications nécessaire de la tablette
	if (choix == 1){
		tablette.ligne -= 1;
		printf("L'IA a décidé d'enlever une ligne\n\n");
	} else if (choix == 2){
		tablette.colonne -=1;
		printf("L'IA a décidé d'enlever une colonne\n\n");
	}
	return tablette;
}
