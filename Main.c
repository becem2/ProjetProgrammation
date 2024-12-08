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
        printf("Le fichier existe déjà.\n");
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
        printf("Loading .... \nComing Soon\n");
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