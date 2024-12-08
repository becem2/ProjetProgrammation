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

void Allocation2(CLIENT** cl, int n,int j){
    *cl = (CLIENT*)malloc(n * sizeof(CLIENT));
    if (!(*cl)) {
        printf("Erreur d'allocation mémoire pour le %d tableaux Client.\n",j+1);
        exit(-4);
    }

}

void Allocation3(PAIEMENT** p,int n,int k){
    *p = (PAIEMENT*)malloc(n*sizeof(PAIEMENT));
    if(!(*p)){
        printf("Erreur d;allocation memoire pour le %d tableaux Paiement \n",k+1);
        exit(-5);
    }

}

PAIEMENT RemplirePaiement(int j){
    PAIEMENT paiement;
    printf("Tapez le Code Paiement pour le Paiement %d : \n", j+1);
    scanf("%d",&(paiement.CodePaiement));

    printf("Tapez le Date pour le Paiement %d : \n", j+1);
    scanf("%d",&(paiement.date));

    printf("Tapez le statut paiement pour le paiement %d : \n", j+1);
    scanf("%d",&(paiement.StatutPaiement));

    printf("Tapez le prix pour le paiement %d : \n", j+1);
    scanf("%f",&(paiement.prix));

    return paiement;
}

CLIENT RemplireClient(int j){
    CLIENT client;
    PAIEMENT *paiement;

    printf("Tapez le Code Client pour le client %d : \n", j+1);
    scanf("%d",&(client.CodeClient));

    printf("Tapez le model du voiture pour le client %d : \n",j+1);
    scanf("%d",&(client.Model));

    printf("Tapez le pourcentage pour le client %d : \n",j+1);
    scanf("%d",&(client.Pourcentage));
    
    printf("Tapez le temps restant pour le client %d : \n",j+1);
    scanf("%d",&(client.TempsRestant));

    printf("Tapez le Nombre de paiement pour le client %d : \n",j+1);
    scanf("%d",&(client.NbPaiement));

    Allocation3(&paiement,client.NbPaiement,j);

    for(int k = 0;k<client.NbPaiement;k++ ){
        client.paiement[k] = RemplirePaiement(k);
    }


    return client;
}

CHARGEUR RemplireChargeur(int j) {
    CHARGEUR chargeur;

    printf("Tapez le Code Client pour le chargeur %d : \n",j+1);
    scanf("%d",&(chargeur.CodeClient));

    printf("Tapez le Type pour le chargeur %d : \n",j+1);
    scanf("%d",&(chargeur.Type));

    printf("Tapez l'Etat d'utilisation pour le chargeur 'Utiliser' ou 'Non utiliser' %d : \n",j+1);
    scanf("%d",&(chargeur.EtatUtilisation));

    printf("Tapez l'Etat de maintenance pour le chargeur %d : \n",j+1);
    scanf("%d",&(chargeur.EtatMaintenance));

    return chargeur;
}


STATION RemplireStation(int i) {
    STATION station;
    CHARGEUR chargeur;
    CLIENT client;

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

    // Nombre de clients
    printf("Tapez le nombre de clients de la station %d : \n",i+1);
    scanf("%d", &(station.NbClient));

    // Allocation du tableaux client
    Allocation2(&(station.client), station.NbClient,i);

    // Remplire du donne pour chaque client
    for (int k = 0;k<station.NbClient;k++){
        station.client[k] = RemplireClient(k);

    }



    return station;
}





void RemplissageTableauStation(STATION**station, int n){
    for (int i = 0;i<n;i++){
        (*station)[i] = RemplireStation(i);
    }
}
    
