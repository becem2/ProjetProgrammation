#include "MaBib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void AllocationStation(STATION** station) {
    *station = (STATION*)malloc(sizeof(STATION));
    if (!(*station)) {
        perror("Erreur d'allocation memoire pour la station.");
        exit(EXIT_FAILURE);
    }
}

void AllocationClients(CLIENT** clients, int n) {
    *clients = (CLIENT*)malloc(n * sizeof(CLIENT));
    if (!(*clients)) {
        perror("Erreur d'allocation memoire pour les clients.");
        exit(EXIT_FAILURE);
    }
}

void AllocationChargeurs(CHARGEUR** chargeurs, int n) {
    *chargeurs = (CHARGEUR*)malloc(n * sizeof(CHARGEUR));
    if (!(*chargeurs)) {
        perror("Erreur d'allocation memoire pour les chargeurs.");
        exit(EXIT_FAILURE);
    }
}

void AllocationPaiements(PAIEMENT** paiements, int n) {
    *paiements = (PAIEMENT*)malloc(n * sizeof(PAIEMENT));
    if (!(*paiements)) {
        perror("Erreur d'allocation memoire pour les paiements.");
        exit(EXIT_FAILURE);
    }
}

// Free Memory
void LibereMemoire(STATION* station) {
    if (!station) return;
    for (int i = 0; i < station->NbClient; i++) {
        free(station->client[i].paiement);
    }
    free(station->client);
    free(station->chargeur);
    free(station);
}

// Input Functions
PAIEMENT RemplirPaiement(int j) {
    PAIEMENT paiement;
    printf("Saisir le code du paiement : ");
    scanf("%d", &paiement.CodePaiement);
    printf("Saisir la date (jour mois annee) : ");
    scanf("%d %d %d", &paiement.date.jour, &paiement.date.mois, &paiement.date.annee);
    printf("Saisir le statut du paiement : ");
    scanf("%d", &paiement.StatutPaiement);
    printf("Saisir le montant : ");
    scanf("%f", &paiement.prix);
    return paiement;
}

CLIENT RemplirClient(int j) {
    CLIENT client;
    printf("Saisir le code client : ");
    scanf("%d", &client.CodeClient);
    printf("Saisir le pourcentage de charge : ");
    scanf("%f", &client.Pourcentage);
    client.TempsRestant = (100 - client.Pourcentage)*2;
    printf("Saisir le nombre de paiements : ");
    scanf("%d", &client.NbPaiement);
    AllocationPaiements(&client.paiement, client.NbPaiement);
    for (int i = 0; i < client.NbPaiement; i++) {
        client.paiement[i] = RemplirPaiement(i);
    }
    return client;
}

CHARGEUR RemplirChargeur(int j) {
    CHARGEUR chargeur;
    printf("Saisir le code client du chargeur : ");
    scanf("%d", &chargeur.CodeClient);
    printf("Saisir le type : ");
    scanf("%d", &chargeur.Type);
    printf("Saisir l'etat d'utilisation (0 = Non utilise, 1 = En utilisation) : ");
    scanf("%d", &chargeur.EtatUtilisation);
    printf("Saisir l'etat de maintenance : ");
    scanf("%s", chargeur.EtatMaintenance);
    return chargeur;
}

STATION RemplirStation() {
    STATION station;
    printf("Saisir le code de la station : ");
    scanf("%d", &station.codeStation);
    printf("Saisir l'adresse : ");
    scanf("%s", station.adresse);

    printf("Saisir le nombre de chargeurs : ");
    scanf("%d", &station.NbChargeur);
    AllocationChargeurs(&station.chargeur, station.NbChargeur);
    for (int i = 0; i < station.NbChargeur; i++) {
        station.chargeur[i] = RemplirChargeur(i);
    }

    printf("Saisir le nombre de clients : ");
    scanf("%d", &station.NbClient);
    AllocationClients(&station.client, station.NbClient);
    for (int i = 0; i < station.NbClient; i++) {
        station.client[i] = RemplirClient(i);
    }

    return station;
}

// Charger et Sauvegarder
void ChargerFichier(STATION** station, const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Erreur d'ouverture du fichier.");
        exit(EXIT_FAILURE);
    }

    AllocationStation(station);
    fread(*station, sizeof(STATION), 1, file);

    AllocationClients(&(*station)->client, (*station)->NbClient);
    fread((*station)->client, sizeof(CLIENT), (*station)->NbClient, file);

    AllocationChargeurs(&(*station)->chargeur, (*station)->NbChargeur);
    fread((*station)->chargeur, sizeof(CHARGEUR), (*station)->NbChargeur, file);

    fclose(file);
}

void SauvegarderFichier(STATION* station, const char* filename) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        perror("Erreur d'ouverture du fichier.");
        exit(EXIT_FAILURE);
    }

    fwrite(station, sizeof(STATION), 1, file);
    fwrite(station->client, sizeof(CLIENT), station->NbClient, file);
    fwrite(station->chargeur, sizeof(CHARGEUR), station->NbChargeur, file);

    fclose(file);
}

// Logic Functions
void TempsRestantClient(STATION* station, int clientCode) {
    for (int i = 0; i < station->NbClient; i++) {
        if (station->client[i].CodeClient == clientCode) {
            printf("Temps restant pour le client %d : %.2f minutes\n", clientCode, station->client[i].TempsRestant);
            return;
        }
    }
    printf("Client non trouve.\n");
}

void ChargeursDisponibles(STATION* station) {
    printf("Chargeurs disponibles :\n");
    for (int i = 0; i < station->NbChargeur; i++) {
        if (station->chargeur[i].EtatUtilisation == 0) {
            printf("Chargeur %d : %s\n", station->chargeur[i].CodeClient, station->chargeur[i].EtatMaintenance);
        }
    }
}

float TotalPaiement(STATION* station) {
    float total = 0;
    for (int i = 0; i < station->NbClient; i++) {
        for (int j = 0; j < station->client[i].NbPaiement; j++) {
            total += station->client[i].paiement[j].prix;
        }
    }
    return total;
}
    
