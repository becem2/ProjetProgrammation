#include "Fonction.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


int main(){
    STATION station[1];
    printf("\n------------------------------------");
    if (fopen("station.bin","rb")!= NULL){
        printf("\nLe fichier existe deja\nChargement des donnees\n");
        RemplireTableauDuFichier(station);
    }
    else{
        printf("Le fichier n'existe pas\n");
        printf("On va le remplire \n");
        RemplireStation(station);
    }
    int ChoixMenu;
    do
            {
                printf("\n*-------------- Menu Principal -------------*\n");
                printf("1. Modification du fichier\n");
                printf("2. Traitement\n");
                printf("3. Affichage\n");
                printf("9. Quitter\n");
                printf("Votre choix : ");
                scanf("%d", &ChoixMenu);
                switch (ChoixMenu)
                {
                case 1:
                    int ChoixModification;
                    do
                        {
                            printf("\n*-------- Modification du Fichier --------*\n");
                            printf("1. Modifier Client\n");
                            printf("2. Modifier Chargeur\n");
                            printf("3. Modifier Paiement\n");
                            printf("4. Modifier Voiture\n");
                            printf("9. Retour au menu principal\n");
                            printf("Votre choix : ");
                            scanf("%d", &ChoixModification);
                            switch (ChoixModification)
                                {
                                case 1:
                                    int ChoixClient;
                                    do
                                        {
                                            printf("\n*--------Modification du Client-------*\n");
                                            printf("1. Modifier un Client\n");
                                            printf("2. Ajout un Client\n");
                                            printf("3. Supprimer un Client\n");
                                            printf("9. Retour au menu modification\n");
                                            printf("Votre choix : ");
                                            scanf("%d",&ChoixClient);
                                            switch (ChoixClient)
                                            {
                                            case 1:
                                                printf("\n*----------Modifier un client------*\n");
                                                ModifierClient(station);
                                                break;
                                            case 2:
                                                printf("\n*----------Ajout un client------*\n");
                                                AjoutClient(station);
                                                break;
                                            case 3:
                                                printf("\n*----------supprimer un client------*\n");
                                                SupprimerClient(station);
                                                break;
                                            default:
                                                printf("Tapez un Nombre Valide!!");
                                                break;
                                            }
                                        } while (ChoixClient !=9);
                                    break;
                                case 2:
                                    int ChoixChargeur;
                                    do
                                    {
                                        printf("\n*--------Modification du Chargeur-------*\n");
                                        printf("1. Modifier un Chargeur\n");
                                        printf("2. Ajout un Chargeur\n");
                                        printf("3. Supprimer un Chargeur\n");
                                        printf("9. Retour au menu modification\n");
                                        printf("Votre choix : ");
                                        scanf("%d",&ChoixChargeur);
                                        switch (ChoixChargeur)
                                        {
                                            case 1:
                                                printf("\n*----------Modification du Chargeur------*\n");
                                                ModifierChargeur(station);
                                                break;
                                            case 2:
                                                printf("\n*----------Ajout un Chargeur------*\n");
                                                AjoutChargeur(station);
                                                break;
                                            case 3 :
                                                printf("\n*----------Suppression du Chargeur------*\n");
                                                SupprimerChargeur(station);
                                                break;
                                            default:
                                                printf("Tapez un Nombre Valide!!");
                                                break;
                                            }
                                    } while (ChoixChargeur !=9);
                                    break;
                                case 3:
                                    int ChoixPaiement;
                                    do
                                        {
                                            printf("\n*--------Modification du Paiement-------*\n");
                                            printf("1. Modifier un Paiement\n");
                                            printf("2. Ajout un Paiement\n");
                                            printf("3. Supprimer un Paiement\n");
                                            printf("9. Retour au menu Paiement\n");
                                            printf("Votre choix : ");
                                            scanf("%d",&ChoixPaiement);
                                            switch (ChoixPaiement)
                                            {
                                            case 1:
                                                printf("\n*----------Modification du Paiement------*\n");
                                                ModifierPaiement(station);
                                                break;
                                            case 2:
                                                printf("\n*----------Ajout du Paiement------*\n");
                                                AjoutPaiement(station);
                                                break;
                                            case 3:
                                                printf("\n*----------Suppression du Paiement------*\n");
                                                SupprimerPaiement(station);
                                                break;
                                            default:
                                                printf("Tapez un Nombre Valide!!");
                                                break;
                                            }
                                        } while (ChoixPaiement != 9);
                                        break;
                                case 4:
                                    int ChoixVoiture;
                                    do
                                    {
                                        printf("\n*--------Modification du Voiture-------*\n");
                                        printf("1. Modifier un Voiture\n");
                                        printf("2. Ajout un Voiture\n");
                                        printf("3. Supprimer un Voiture\n");
                                        printf("9. Retour au menu Voiture\n");
                                        printf("Votre choix : ");
                                        scanf("%d",&ChoixVoiture);
                                        switch (ChoixVoiture)
                                        {
                                        case 1:
                                            printf("\n*----------Modification du Voiture------*\n");
                                            ModifierVoiture(station);
                                            break;
                                        case 2:
                                            printf("\n*----------Ajout du Voiture------*\n");
                                            AjoutVoiture(station);
                                            break;
                                        case 3 :
                                            printf("\n*----------Suppression du Voiture------*\n");
                                            SupprimerVoiture(station);
                                            break;
                                        
                                        default:
                                            break;
                                        }
                                    } while (ChoixVoiture != 9);
                                    break;
                                default:
                                    printf("Tapez un Nombre Valide!!");
                                    break;
                                }
                        } while (ChoixModification != 9);
                    break;
                case 3:
                int ChoixAffichage;
                do
                {
                    printf("\n*--------Affichage-------*\n");
                    printf("1. Affichage Client\n");
                    printf("2. Affichage Chargeur\n");
                    printf("3. Affichage Voiture\n");
                    printf("4. Affichage Paiement\n");
                    printf("Votre choix : ");
                    scanf("%d",&ChoixAffichage);
                    switch (ChoixAffichage)
                    {
                    case 1:
                        AfficherClient(station);
                        break;
                    case 2:
                        AfficherChargeur(station);
                        break;
                    case 3 :
                        AfficherVoiture(station);
                        break;
                    case 4:
                        AfficherPaiement(station);
                        break;
                    
                    default:
                        printf("Tapez un Nombre Valide!!");
                        break;
                    }

                } while (ChoixAffichage !=9);
                
                default:
                    printf("GoodBye");
                    break;
                }
            } while (ChoixMenu != 9);
    for (int i = 0;i<station->NbChargeur;i++){
        printf("etat : %d\n",station->chargeur[i].EtatUtilisation);
    }
    for (int i = 0;i<station->NbClient;i++){
        for (int j=0;j<station->client[i].NbVoiture;j++){
            printf("%d\n",station->client[i].voiture[j].NbSerie);
            printf("Model : %s\n",station->client[i].voiture[j].Model);
        }
        for (int j = 0;j<station->client[i].NbPaiement;j++){
            printf("%2d/%2d/%4d\n",station->client[i].paiement[j].date.jour,station->client[i].paiement[j].date.mois,station->client[i].paiement[j].date.annee);
        }
    }
    RemplireFichierduTableau(station);
    LibereMemoire(station);
    getch();
    return 0;
}