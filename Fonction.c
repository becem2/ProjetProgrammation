#include "MaBib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void AllocationStation(STATION** station) {
    *station = (STATION*)malloc(sizeof(STATION));
    if (!(*station)) {
        printf("Erreur d'allocation memoire pour la station.");
        exit(-1);
    }
}

void AllocationClients(CLIENT** clients, int n) {
    *clients = (CLIENT*)malloc(n * sizeof(CLIENT));
    if (!(*clients)) {
        printf("Erreur d'allocation memoire pour les clients.");
        exit(-2);
    }
}

void AllocationChargeurs(CHARGEUR** chargeurs, int n) {
    *chargeurs = (CHARGEUR*)malloc(n * sizeof(CHARGEUR));
    if (!(*chargeurs)) {
        printf("Erreur d'allocation memoire pour les chargeurs.");
        exit(-3);
    }
}

void AllocationPaiements(PAIEMENT** paiements, int n) {
    *paiements = (PAIEMENT*)malloc(n * sizeof(PAIEMENT));
    if (!(*paiements)) {
        printf("Erreur d'allocation memoire pour les paiements.");
        exit(-4);
    }
}

void LibereMemoire(STATION* station) {
    if (!station) return;
    for (int i = 0; i < station->NbClient; i++) {
        free(station->client[i].paiement);
    }
    free(station->client);
    free(station->chargeur);
    free(station);
}

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

void ChargerFichier(STATION** station, const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        printf("Erreur d'ouverture du fichier.");
        exit(-5);
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
        printf("Erreur d'ouverture du fichier.");
        exit(-6);
    }

    fwrite(station, sizeof(STATION), 1, file);
    fwrite(station->client, sizeof(CLIENT), station->NbClient, file);
    fwrite(station->chargeur, sizeof(CHARGEUR), station->NbChargeur, file);

    fclose(file);
}

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

void AjouterClient(STATION* station) {
    if (station == NULL) {
        printf("Erreur : station est NULL.\n");
        return;
    }

    station->client = realloc(station->client, (station->NbClient + 1) * sizeof(CLIENT));
    if (station->client == NULL) {
        printf("Erreur de reallocation de memoire.\n");
        return;
    }

    CLIENT* newClient = &station->client[station->NbClient];

    printf("Saisir le code client : ");
    scanf("%d", &newClient->CodeClient);
    printf("Saisir le Numero du serie de la voiture du client : ");
    scanf("%d", newClient->voiture.NbSerie);
    printf("Saisir la Marque de la voiture du client : ");
    scanf("%s", newClient->voiture.Marque);
    printf("Saisir le Model de la voiture du client : ");
    scanf("%s", newClient->voiture.Model);
    printf("Saisir le Pourcentage de la voiture du client : ");
    scanf("%f", &newClient->Pourcentage);
    newClient->TempsRestant = (100-newClient->Pourcentage)*2;
    printf("Saisir le Nombre de paiement du client : ");
    scanf("%f", &newClient->NbPaiement);
    for (int i = 0;i<newClient->NbPaiement;i++){
        newClient->paiement[i] = RemplirPaiement(i);
    }

    station->NbClient++;

    printf("Client ajouté avec succès !\n");
}
