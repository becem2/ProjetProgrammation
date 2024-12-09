#include "Fonction.h"
#include <stdio.h>
#include <stdlib.h>
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

    // Main menu
    int choixMenu;
    do {
        printf("\n*-------------- Menu Principal -------------*\n");
        printf("1. Modification du fichier\n");
        printf("2. Traitement\n");
        printf("3. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choixMenu);

        switch (choixMenu) {
        case 1: {
            // Submenu for file modification
            int choixModification;
            do {
                printf("\n*-------- Modification du Fichier --------*\n");
                printf("1. Ajouter un client\n");
                printf("2. Modifier un client\n");
                printf("3. Supprimer un client\n");
                printf("4. Retour au menu principal\n");
                printf("Votre choix : ");
                scanf("%d", &choixModification);

                switch (choixModification) {
                case 1:
                    printf("Ajout de client (fonctionnalité à implémenter).\n");
                    // Add function calls for adding a client
                    break;
                case 2:
                    printf("Modification de client (fonctionnalité à implémenter).\n");
                    // Add function calls for modifying a client
                    break;
                case 3:
                    printf("Suppression de client (fonctionnalité à implémenter).\n");
                    // Add function calls for deleting a client
                    break;
                case 4:
                    printf("Retour au menu principal.\n");
                    break;
                default:
                    printf("Choix invalide.\n");
                }
            } while (choixModification != 4);
            break;
        }
        case 2: {
            // Submenu for traitement
            int choixTraitement;
            do {
                printf("\n*------------ Traitement -----------*\n");
                printf("1. Total des paiements\n");
                printf("2. Temps restant pour charger une voiture\n");
                printf("3. Chargeurs disponibles\n");
                printf("4. Retour au menu principal\n");
                printf("Votre choix : ");
                scanf("%d", &choixTraitement);

                switch (choixTraitement) {
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
                    printf("Retour au menu principal.\n");
                    break;
                default:
                    printf("Choix invalide.\n");
                }
            } while (choixTraitement != 4);
            break;
        }
        case 3:
            printf("Goodbye!\n");
            break;
        default:
            printf("Choix invalide.\n");
        }
    } while (choixMenu != 3);

    LibereMemoire(station);
    return 0;
}
