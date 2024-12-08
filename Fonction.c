#include "MaBib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Saisir() {
    int n;
    printf("Saisir le nombre de stations : ");
    scanf("%d", &n);
    return n;
}

void CreationFichierStation(FILE **f) {
    *f = fopen("stations.bin", "wb+");
    if (!(*f)) {
        perror("Erreur lors de la creation du fichier.");
        exit(-1);
    }
    fclose(*f);
}

int FichierExiste(const char *f) {
    FILE *file = fopen(f, "rb");
    if (file) {
        fclose(file);
        return 1;
    }
    return 0;
}

void AllocationStations(STATION **stations, int n) {
    *stations = (STATION *)malloc(n * sizeof(STATION));
    if (!(*stations)) {
        perror("Erreur d'allocation memoire pour les stations.");
        exit(-2);
    }
}

void AllocationClients(CLIENT **clients, int n) {
    *clients = (CLIENT *)malloc(n * sizeof(CLIENT));
    if (!(*clients)) {
        perror("Erreur d'allocation memoire pour les clients.");
        exit(-3);
    }
}

void AllocationChargeurs(CHARGEUR **chargeurs, int n) {
    *chargeurs = (CHARGEUR *)malloc(n * sizeof(CHARGEUR));
    if (!(*chargeurs)) {
        perror("Erreur d'allocation memoire pour les chargeurs.");
        exit(-4);
    }
}

void AllocationPaiements(PAIEMENT **paiements, int n) {
    *paiements = (PAIEMENT *)malloc(n * sizeof(PAIEMENT));
    if (!(*paiements)) {
        perror("Erreur d'allocation memoire pour les paiements.");
        exit(-5);
    }
}

PAIEMENT RemplirPaiement(int j) {
    PAIEMENT paiement;
    char x[5];

    if (j==0) strcpy(x,"ere");
    else strcpy(x,"eme");

    printf("Saisir le code du %d%s paiement : ",j+1,x);
    scanf("%d", &paiement.CodePaiement);
    printf("Saisir la date du %d%s paiement : ",j+1,x);
    scanf("%s", paiement.date);
    printf("Saisir le statut du %d%s paiement : ",j+1,x);
    scanf("%d", &paiement.StatutPaiement);
    printf("Saisir le montant du %d%s paiement : ",j+1,x);
    scanf("%f", &paiement.prix);
    return paiement;
}

CLIENT RemplirClient(int j) {
    CLIENT client;

    char x[5];

    if (j==0) strcpy(x,"ere");
    else strcpy(x,"eme");

    printf("Saisir le code du %d%s client : ",j+1,x);
    scanf("%d", &client.CodeClient);
    printf("Saisir le modèle de voiture du %d%s client : ",j+1,x);
    scanf("%s", client.Model);
    printf("Saisir le pourcentage de charge du %d%s client : ",j+1,x);
    scanf("%f", &client.Pourcentage);
    printf("Saisir le temps restant (en heures) du %d%s client : ",j+1,x);
    scanf("%f", &client.TempsRestant);
    printf("Saisir le nombre de paiements pour le %d%s client : ",j+1,x);
    scanf("%d", &client.NbPaiement);

    AllocationPaiements(&client.paiement, client.NbPaiement);
    for (int i = 0; i < client.NbPaiement; i++) {
        client.paiement[i] = RemplirPaiement(i);
    }
    return client;
}

CHARGEUR RemplirChargeur(int j) {
    CHARGEUR chargeur;
    char x[5];

    if (j==0) strcpy(x,"ere");
    else strcpy(x,"eme");
    
    printf("Saisir le code client du %d%s chargeur : ",j+1,x);
    scanf("%d", &chargeur.CodeClient);
    printf("Saisir le type du %d%s chargeur : ",j+1,x);
    scanf("%d", &chargeur.Type);
    printf("Saisir l'état d'utilisation du %d%s chargeur (0 = 'Non utiliser' , 1 = 'Utiliser') : ",j+1,x);
    scanf("%d", &chargeur.EtatUtilisation);
    printf("Saisir l'état de maintenance du %d%s chargeur (0 = 'Bon etat' , 1 = 'Maintenance') : ",j+1,x);
    scanf("%s", chargeur.EtatMaintenance);
    return chargeur;
}

STATION RemplirStation(int i) {
    STATION station;
    char x[5];

    if (i==0) strcpy(x,"ere");
    else strcpy(x,"eme");

    printf("Saisir le code du %d%s station : ",i+1,x);
    scanf("%d", &station.codeStation);
    printf("Saisir l'adresse du %d%s station : ",i+1,x);
    scanf("%999s", station.adresse); // Read a full line with spaces
    printf("Saisir le nombre de chargeurs pour la %d%s station : ",i+1,x);
    scanf("%d", &station.NbChargeur);

    AllocationChargeurs(&station.chargeur, station.NbChargeur);
    for (int j = 0; j < station.NbChargeur; j++) {
        station.chargeur[j] = RemplirChargeur(j);
    }

    printf("Saisir le nombre de clients pour la %d%s station : ",i+1,x);
    scanf("%d", &station.NbClient);

    AllocationClients(&station.client, station.NbClient);
    for (int j = 0; j < station.NbClient; j++) {
        station.client[j] = RemplirClient(j);
    }
    return station;
}

void RemplissageTableauStation(STATION **stations, int n) {
    for (int i = 0; i < n; i++) {
        (*stations)[i] = RemplirStation(i);
    }
}

void RemplissageFichier(STATION *stations, int n, FILE **fs) {
    *fs = fopen("stations.bin", "wb");
    if (!(*fs)) {
        perror("Erreur d'ouverture du fichier pour l'ecriture.");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i <n; i++) {
        fwrite(&stations[i].codeStation, sizeof(int), 1, *fs);
        fwrite(stations[i].adresse, sizeof(char), 1000, *fs);
        fwrite(&stations[i].NbChargeur, sizeof(int), 1, *fs);
        fwrite(&stations[i].NbClient, sizeof(int), 1, *fs);

        for (int j = 0; j<stations[i].NbChargeur;j++) {
            fwrite(&stations[i].chargeur[j], sizeof(CHARGEUR), 1, *fs);
        }

        for (int j= 0; j< stations[i].NbClient;j++) {
            fwrite(&stations[i].client[j],sizeof(CLIENT), 1, *fs);
            for (int k=0;k <stations[i].client[j].NbPaiement;k++) {
                fwrite(&stations[i].client[j].paiement[k], sizeof(PAIEMENT), 1, *fs);
            }
        }
    }

    fclose(*fs);
}

void LibereMemoire(STATION *stations, int n) {
    for (int i=0;i<n;i++) {
        for (int j=0;j<stations[i].NbClient; j++) {
            free(stations[i].client[j].paiement);
        }
        free(stations[i].client);
        free(stations[i].chargeur);
    }
    free(stations);
}
    
