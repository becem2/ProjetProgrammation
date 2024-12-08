#include "Fonction.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>





int main(){
    //Testez si la fichier existe ou non
    printf("*-----------------------------*\n");


    FILE *fs;
    char *f = "stations.bin";

    if (FichierExiste(f)) {
        printf("Le fichier existe deja.\n");
    } else {
        printf("Le fichier n'existe pas. Creation du fichier...\nRemplissage du fichier en cours ...\n");
        CreationFichierStation(&fs);
        int nbrStations = Saisir();
        STATION *stations;
        AllocationStations(&stations, nbrStations);
        RemplissageTableauStation(&stations, nbrStations);
        RemplissageFichier(stations, nbrStations, &fs);
        LibereMemoire(stations, nbrStations);
        printf("Les donnees ont ete enregistrees avec succes.\n");
    }

    //Menu

    int choixMenu;
    printf("\n*-------------- Menu -------------*\n");
    printf("1. Faire du traitement\n");
    printf("2. Quitter\n");
    printf("Votre choix : ");
    scanf("%d", &choixMenu);
    switch (choixMenu)
    {

    case 1:
        int traitement;
        printf("*------------Traitement-----------*\n");
        printf("1. Totale des paiement\n");
        printf("2. Combient de KWH sont charge dans une voiture\n");
        printf("3. Temps restant pour charger une voiture\n");
        printf("4. Client du mois\n");
        printf("5. Chargeur disponible\n");
        printf("6. Statistique\n");
        printf("Votre choix : ");
        scanf("%d", &traitement);

        switch (traitement)
        {
            case 1:
                float Total;
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            default:
                printf("Erreur\n");
                break;

        }
        getch();
        break;

    case 2 :
        printf("Good Bye\n");
        break;

    default:
        printf("Erreur\n");
        break;
    }

    return 0;
}