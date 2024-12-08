#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure paiement
struct paiement {
    int CodePaiement;
    char date[20];
    int StatutPaiement;
    float prix;
};
typedef struct paiement PAIEMENT;

// Structure client
struct client {
    int CodeClient;
    char Model[20];
    float Pourcentage;
    float TempsRestant;
    int NbPaiement;
    PAIEMENT *paiement;
};
typedef struct client CLIENT;

// Structure chargeur
struct chargeur {
    int CodeClient;
    int Type;
    int EtatUtilisation;
    char EtatMaintenance[100];
};
typedef struct chargeur CHARGEUR;

// Structure station
struct station {
    int codeStation;
    char adresse[1000];
    int NbChargeur;
    int NbClient;
    CLIENT *client;
    CHARGEUR *chargeur;
};
typedef struct station STATION;

// Function declarations
int Saisir();
void CreationFichierStation(FILE **f);
int FichierExiste(const char *f);
void AllocationStations(STATION **stations, int n);
void AllocationClients(CLIENT **clients, int n);
void AllocationChargeurs(CHARGEUR **chargeurs, int n);
void AllocationPaiements(PAIEMENT **paiements, int n);

PAIEMENT RemplirPaiement(int j);
CLIENT RemplirClient(int j);
CHARGEUR RemplirChargeur(int j);
STATION RemplirStation(int i);

void RemplissageTableauStation(STATION **stations, int n);
void RemplissageFichier(STATION *stations, int n, FILE **fs);
void LibereMemoire(STATION *stations, int n);

// Main function
int main() {
    FILE *fs;
    char *f = "stations.bin";

    if (FichierExiste(f)) {
        printf("Le fichier existe déjà.\n");
    } else {
        printf("Le fichier n'existe pas. Création du fichier...\n");
        CreationFichierStation(&fs);
    }

    // Menu
    int choixMenu;
    printf("\n*-------------- Menu -------------*\n");
    printf("1. Ajouter une station\n");
    printf("2. Quitter\n");
    printf("Votre choix : ");
    scanf("%d", &choixMenu);

    if (choixMenu == 1) {
        int nbrStations = Saisir();
        STATION *stations;
        AllocationStations(&stations, nbrStations);
        RemplissageTableauStation(&stations, nbrStations);
        RemplissageFichier(stations, nbrStations, &fs);
        LibereMemoire(stations, nbrStations);
        printf("Les données ont été enregistrées avec succès.\n");
    } else {
        printf("Au revoir!\n");
    }

    return 0;
}

// Function definitions
int Saisir() {
    int n;
    printf("Saisir le nombre de stations : ");
    scanf("%d", &n);
    return n;
}

void CreationFichierStation(FILE **f) {
    *f = fopen("stations.bin", "wb+");
    if (!(*f)) {
        perror("Erreur lors de la création du fichier.");
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
        perror("Erreur d'allocation mémoire pour les stations.");
        exit(EXIT_FAILURE);
    }
}

void AllocationClients(CLIENT **clients, int n) {
    *clients = (CLIENT *)malloc(n * sizeof(CLIENT));
    if (!(*clients)) {
        perror("Erreur d'allocation mémoire pour les clients.");
        exit(EXIT_FAILURE);
    }
}

void AllocationChargeurs(CHARGEUR **chargeurs, int n) {
    *chargeurs = (CHARGEUR *)malloc(n * sizeof(CHARGEUR));
    if (!(*chargeurs)) {
        perror("Erreur d'allocation mémoire pour les chargeurs.");
        exit(EXIT_FAILURE);
    }
}

void AllocationPaiements(PAIEMENT **paiements, int n) {
    *paiements = (PAIEMENT *)malloc(n * sizeof(PAIEMENT));
    if (!(*paiements)) {
        perror("Erreur d'allocation mémoire pour les paiements.");
        exit(EXIT_FAILURE);
    }
}

PAIEMENT RemplirPaiement(int j) {
    PAIEMENT paiement;
    printf("Saisir le code du paiement %d : ", j + 1);
    scanf("%d", &paiement.CodePaiement);
    printf("Saisir la date du paiement %d (AAAA-MM-JJ) : ", j + 1);
    scanf("%s", paiement.date);
    printf("Saisir le statut du paiement %d (0 ou 1) : ", j + 1);
    scanf("%d", &paiement.StatutPaiement);
    printf("Saisir le montant du paiement %d : ", j + 1);
    scanf("%f", &paiement.prix);
    return paiement;
}

CLIENT RemplirClient(int j) {
    CLIENT client;
    printf("Saisir le code du client %d : ", j + 1);
    scanf("%d", &client.CodeClient);
    printf("Saisir le modèle de voiture du client %d : ", j + 1);
    scanf("%s", client.Model);
    printf("Saisir le pourcentage de charge du client %d : ", j + 1);
    scanf("%f", &client.Pourcentage);
    printf("Saisir le temps restant (en heures) du client %d : ", j + 1);
    scanf("%f", &client.TempsRestant);
    printf("Saisir le nombre de paiements pour le client %d : ", j + 1);
    scanf("%d", &client.NbPaiement);

    AllocationPaiements(&client.paiement, client.NbPaiement);
    for (int i = 0; i < client.NbPaiement; i++) {
        client.paiement[i] = RemplirPaiement(i);
    }
    return client;
}

CHARGEUR RemplirChargeur(int j) {
    CHARGEUR chargeur;
    printf("Saisir le code client du chargeur %d : ", j + 1);
    scanf("%d", &chargeur.CodeClient);
    printf("Saisir le type du chargeur %d : ", j + 1);
    scanf("%d", &chargeur.Type);
    printf("Saisir l'état d'utilisation du chargeur %d (0 = Non utilisé, 1 = Utilisé) : ", j + 1);
    scanf("%d", &chargeur.EtatUtilisation);
    printf("Saisir l'état de maintenance du chargeur %d : ", j + 1);
    scanf("%s", chargeur.EtatMaintenance);
    return chargeur;
}

STATION RemplirStation(int i) {
    STATION station;
    printf("Saisir le code de la station %d : ", i + 1);
    scanf("%d", &station.codeStation);
    printf("Saisir l'adresse de la station %d : ", i + 1);
    scanf("%999s", station.adresse); // Read a full line with spaces
    printf("Saisir le nombre de chargeurs pour la station %d : ", i + 1);
    scanf("%d", &station.NbChargeur);

    AllocationChargeurs(&station.chargeur, station.NbChargeur);
    for (int j = 0; j < station.NbChargeur; j++) {
        station.chargeur[j] = RemplirChargeur(j);
    }

    printf("Saisir le nombre de clients pour la station %d : ", i + 1);
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
        perror("Erreur d'ouverture du fichier pour l'écriture.");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++) {
        fwrite(&stations[i].codeStation, sizeof(int), 1, *fs);
        fwrite(stations[i].adresse, sizeof(char), 1000, *fs);
        fwrite(&stations[i].NbChargeur, sizeof(int), 1, *fs);
        fwrite(&stations[i].NbClient, sizeof(int), 1, *fs);

        for (int j = 0; j < stations[i].NbChargeur; j++) {
            fwrite(&stations[i].chargeur[j], sizeof(CHARGEUR), 1, *fs);
        }

        for (int j = 0; j < stations[i].NbClient; j++) {
            fwrite(&stations[i].client[j], sizeof(CLIENT), 1, *fs);
            for (int k = 0; k < stations[i].client[j].NbPaiement; k++) {
                fwrite(&stations[i].client[j].paiement[k], sizeof(PAIEMENT), 1, *fs);
            }
        }
    }

    fclose(*fs);
}

void LibereMemoire(STATION *stations, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < stations[i].NbClient; j++) {
            free(stations[i].client[j].paiement);
        }
        free(stations[i].client);
        free(stations[i].chargeur);
    }
    free(stations);
}
