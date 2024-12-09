#include "Fonction.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>





int main() {
    STATION* station = NULL;
    const char* filename = "stations.bin";

    printf("*-----------------------------*\n");

    if (fopen(filename, "rb") != NULL) {
        printf("Le fichier existe deja. Chargement des donnees...\n");
        ChargerFichier(&station, filename);
    } else {
        printf("Le fichier n'existe pas. Creation et remplissage...\n");
        AllocationStation(&station);
        *station = RemplirStation();
        SauvegarderFichier(station, filename);
    }

    // Menu
    int choixMenu;
    do {
        printf("\n*-------------- Menu -------------*\n");
        printf("1. Total des paiements\n");
        printf("2. Temps restant pour charger une voiture\n");
        printf("3. Chargeurs disponibles\n");
        printf("4. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choixMenu);

        switch (choixMenu) {
        case 1:
            printf("Total des paiements : %.2f\n", TotalPaiement(station));
            break;
        case 2: {
            int clientCode;
            printf("Saisir le code client : ");
            scanf("%d", &clientCode);
            TempsRestantClient(station, clientCode);
            break;
        }
        case 3:
            ChargeursDisponibles(station);
            break;
        case 4:
            printf("Goodbye!\n");
            break;
        default:
            printf("Choix invalide.\n");
        }
    } while (choixMenu != 4);

    LibereMemoire(station);
    return 0;
}