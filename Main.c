#include "Fonction.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    STATION* station = NULL;
    const char* NomFichier = "stations.bin";

    printf("*-----------------------------*\n");

    if (fopen(NomFichier, "rb") != NULL) {
        printf("Le fichier existe deja. Chargement des donnees...\n");
        ChargerFichier(&station, NomFichier);
    } else {
        printf("Le fichier n'existe pas. Creation et remplissage...\n");
        AllocationStation(&station);
        *station = RemplirStation();
        SauvegarderFichier(station, NomFichier);
    }

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
            int choixModification;
            do {
                printf("\n*-------- Modification du Fichier --------*\n");
                printf("1. Modifier Client\n");
                printf("2. Modifier Chargeur\n");
                printf("3. Modifier Paiement\n");
                printf("4. Modifier Voiture\n");
                printf("5. Retour au menu principal\n");
                printf("Votre choix : ");
                scanf("%d", &choixModification);

                switch (choixModification) {
                case 1:
                    printf("Modifier un client.\n");
                    int choixClient;
                    do{
                        printf("\n*--------Modification du Client-------*\n");
                        printf("1. Modifier un Client");
                        printf("2. Ajout un Client");
                        printf("3. Supprimer un Client");
                        printf("4. Retour au menu modification");
                        printf("Votre choix : ");
                        scanf("%d",&choixClient);
                        switch (choixClient){
                            case 2:
                                printf("\n*----------Ajout du client------*\n");
                                AjouterClient(station);
                                SauvegarderFichier(station, NomFichier);
                                break;
                            case 1:
                                printf("\n*----------Modification du client------*\n");
                                break;
                            case 3:
                                printf("\n*----------Suppression du client------*\n");
                                break;
                            default:
                                printf("Tapez un nombre valide!!");
                                break;
                        }  

                    } while (choixClient != 4 );
                    
                case 2:
                    printf("Modifier un Chargeur.\n");
                    int choixChargeur;
                    do
                    {
                        printf("\n*--------Modification du Chargeur-------*\n");
                        printf("1. Modifier un Chargeur\n");
                        printf("2. Ajout un Chargeur\n");
                        printf("3. Supprimer un Chargeur\n");
                        printf("4. Retour au menu modification\n");
                        printf("Votre choix : ");
                        scanf("%d",&choixChargeur);
                        switch (choixChargeur){
                            case 1:
                                printf("\n*----------Modification du Chargeur------*\n");
                                break;
                            case 2:
                                printf("\n*----------Ajout du Chargeur------*\n");
                                break;
                            case 3:
                                printf("\n*----------Suppression du Chargeur------*\n");
                                break;
                            default:
                                printf("Tapez un nombre valide\n");
                        }
                    } while (choixChargeur != 4);
                    break;
                case 3:
                    printf("Modifier un Paiement.\n");
                        int choixPaiement;
                        do
                        {
                            printf("\n*--------Modification du Paiement-------*\n");
                            printf("1. Modifier un Paiement\n");
                            printf("2. Ajout un Paiement\n");
                            printf("3. Supprimer un Paiement\n");
                            printf("4. Retour au menu Paiement\n");
                            printf("Votre choix : ");
                            scanf("%d",&choixPaiement);
                            switch (choixPaiement){
                                case 1:
                                    printf("\n*----------Modification du Paiement------*\n");
                                    break;
                                case 2:
                                    printf("\n*----------Ajout du Paiement------*\n");
                                    break;
                                case 3:
                                    printf("\n*----------Suppression du Paiement------*\n");
                                    break;
                                default:
                                    printf("Tapez un nombre valide\n");
                            }
                        } while (choixPaiement != 4);
                    break;
                case 4:
                    printf("Modifier un Voiture.\n");
                        int choixVoiture;
                        do
                        {
                            printf("\n*--------Modification du Voiture-------*\n");
                            printf("1. Modifier un Voiture\n");
                            printf("2. Ajout un Voiture\n");
                            printf("3. Supprimer un Voiture\n");
                            printf("4. Retour au menu Voiture\n");
                            printf("Votre choix : ");
                            scanf("%d",&choixVoiture);
                            switch (choixVoiture){
                                case 1:
                                    printf("\n*----------Modification du Voiture------*\n");
                                    break;
                                case 2:
                                    printf("\n*----------Ajout du Voiture------*\n");
                                    break;
                                case 3:
                                    printf("\n*----------Suppression du Voiture------*\n");
                                    break;
                                default:
                                    printf("Tapez un nombre valide\n");
                            }
                        } while (choixVoiture != 4);
                    break;
                case 5:
                    printf("Retour au menu principal.\n");
                    break;
                default:
                    printf("Choix invalide.\n");
                }
            } while (choixModification != 5);
            break;
        }
        case 2: {
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
                    int CodeClient;
                    printf("Saisir le code client : ");
                    scanf("%d", &CodeClient);
                    TempsRestantClient(station, CodeClient);
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
