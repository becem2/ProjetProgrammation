#include "MaBib.h"
#include <stdio.h>
#include <stdlib.h>

int Saisir(){
    int n;
    printf("Ecrire le Nombre de station : ");
    scanf("%d",&n);
    return n;
}

void CreationFichierStation(FILE** f){
    *f = fopen("C:\\Users\\becem\\Desktop\\c\\Project C\\ProjetProgrammation\\Test.bin" , "wb+");
    if(!(*f)) exit(-1);
}

void Allocation(STATION** s, int n) {
    *s = (STATION*)malloc(n * sizeof(STATION));
    if (!(*s)) {
        printf("Erreur d'allocation du memoire pour le tableaux station.\n");
        exit(-2);
    }
}

void Allocation1(CHARGEUR** c, int n, int j) {
    *c = (CHARGEUR*)malloc(n * sizeof(CHARGEUR));
    if (!(*c)) {
        printf("Erreur d'allocation mémoire pour le %d tableaux chargeur.\n",j+1);
        exit(-3);
    }
}


int FichierExiste(const char *f) {
    FILE *fichier = fopen(f, "rb"); 
    if (fichier) {
        fclose(fichier); 
        return 1;     
    }
    return 0;
}

CHARGEUR RemplireChargeur(int j) {
    CHARGEUR chargeur;

    printf("Tapez le Code Client pour le chargeur %d : \n",j+1);
    scanf("%d",&(chargeur.CodeClient));

    printf("Tapez le Type pour le chargeur %d : \n",j+1);
    scanf("%d",&(chargeur.Type));

    printf("Tapez l'Etat d'utilisation pour le chargeur %d : \n",j+1);
    scanf("%d",&(chargeur.EtatUtilisation));

    printf("Tapez l'Etat de maintenance pour le chargeur %d : \n",j+1);
    scanf("%d",&(chargeur.EtatMaintenance));

    return chargeur;
}


STATION RemplireStation(int i) {
    STATION station;
    CHARGEUR chargeur;

    // Code de la station
    printf("Tapez le Code de la station %d : \n", i+1);
    scanf("%d", &(station.codeStation));

    // Adresse
    printf("Tapez l'adresse de la station %d : \n",i+1);
    scanf("%999s", station.adresse);

    // Nombre de chargeurs
    printf("Tapez le nombre de chargeurs de la station %d : \n",i+1);
    scanf("%d", &(station.NbChargeur));

    // Allocation du tableaux Chargeur
    Allocation1(&(station.chargeur), station.NbChargeur,i);



    // Remplir les données pour chaque chargeur
    for (int j = 0;j<station.NbChargeur;j++) {
        station.chargeur[j] = RemplireChargeur(j);
    }

    return station;
}





void RemplissageTableauStation(STATION**station, int n){
    for (int i = 0;i<n;i++){
        *(station)[i] = RemplireStation(i);

    }
}
    
