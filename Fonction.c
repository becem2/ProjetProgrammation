#include "MaBib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int Saisir(){
    int n;
    printf("Ecrire le Nombre de station : ");
    scanf("%d",&n);
    return n;
}

void CreationFichierStation(FILE** f){
    *f = fopen("C:\\Users\\becem\\Desktop\\c\\ProjetProgrammation\\Test.bin" , "wb+");
    if(!(*f)) exit(-1);
    fclose(*f);
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
    char x[5];
    if (j == 0) strcpy(x, "ere");
    else strcpy(x, "eme");

    printf("Tapez le Code Paiement du %d%s Paiement (int) : ", j+1,x);
    scanf("%d",&(paiement.CodePaiement));

    printf("Tapez le Date du %d%s Paiement (int) : ", j+1,x);
    scanf("%d",&(paiement.date));

    printf("Tapez le statut paiement du %d%s Paiement (int) : ", j+1,x);
    scanf("%d",&(paiement.StatutPaiement));

    printf("Tapez le prix du %d%s Paiement (float) : ", j+1,x);
    scanf("%f",&(paiement.prix));

    return paiement;
}

CLIENT RemplireClient(int j){
    CLIENT client;
    PAIEMENT *paiement;
    char x[5];

    if (j == 0) strcpy(x, "ere");
    else strcpy(x, "eme");

    printf("Tapez le Code Client du %d%s client (int) : ", j+1,x);
    scanf("%d",&(client.CodeClient));

    printf("Tapez le model du voiture du %d%s client (str) : ", j+1,x);
    scanf("%s",&(client.Model));

    printf("Tapez le pourcentage du %d%s client (float) : ", j+1,x);
    scanf("%f",&(client.Pourcentage));
    
    printf("Tapez le temps restant du %d%s client (float) : ", j+1,x);
    scanf("%f",&(client.TempsRestant));

    printf("Tapez le Nombre de paiement du %d%s client (int) : ", j+1,x);
    scanf("%d",&(client.NbPaiement));

    Allocation3(&paiement,client.NbPaiement,j);

    for(int k = 0;k<client.NbPaiement;k++ ){
        client.paiement[k] = RemplirePaiement(k);
    }
    return client;
}

CHARGEUR RemplireChargeur(int j) {
    CHARGEUR chargeur;
    char x[5];

    if (j == 0) strcpy(x, "ere");
    else strcpy(x, "eme");

    printf("Tapez le Code Client du %d%s chargeur (int) : ",j+1,x);
    scanf("%d",&(chargeur.CodeClient));

    printf("Tapez le Type du %d%s chargeur (int) : ",j+1,x);
    scanf("%d",&(chargeur.Type));

    printf("Tapez l'Etat d'utilisation du %d%s chargeur (1 = 'Utiliser' ou 2 = 'Non utiliser') (int) : ",j+1,x);
    scanf("%d",&(chargeur.EtatUtilisation));

    printf("Tapez l'Etat de maintenance du %d%s chargeur (1 = 'bon etat' ou 2 = 'maintenance') (int) : ",j+1,x);
    scanf("%d",&(chargeur.EtatMaintenance));

    return chargeur;
}


STATION RemplireStation(int i) {
    STATION station;
    CHARGEUR chargeur;
    CLIENT client;
    char x[5];

    if (i == 0) strcpy(x, "ere");
    else strcpy(x, "eme");


    // Code de la station
    printf("Tapez le Code Station du %d%s station (int) : ", i+1,x);
    scanf("%d", &(station.codeStation));

    // Adresse
    printf("Tapez l'adresse du %d%s station (str) : ", i+1,x);
    scanf("%999s", station.adresse);

    // Nombre de chargeurs
    printf("Tapez le nombre de chargeurs du %d%s station (int) : ", i+1,x);
    scanf("%d", &(station.NbChargeur));

    // Allocation du tableaux Chargeur
    Allocation1(&(station.chargeur), station.NbChargeur,i);

    // Remplir les données pour chaque chargeur
    for (int j = 0;j<station.NbChargeur;j++) {
        station.chargeur[j] = RemplireChargeur(j);
    }

    // Nombre de clients
    printf("Tapez le nombre de clients du %d%s station (int) : ", i+1,x);
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
    char x[5];
    for (int i = 0;i<n;i++){
        if (i == 0) strcpy(x, "ere");
        else strcpy(x, "eme");
        printf("********************************\n");
        printf("Remplissage du %d%s station \n",i+1,x);
        (*station)[i] = RemplireStation(i);
    }
}

void RemplissageFichier(STATION* station, int n , FILE** fs){
    int sizeP,sizeC,sizeCL,sizeS;
    sizeP = sizeof(PAIEMENT);
    sizeC = sizeof(CHARGEUR);
    sizeCL = 2*sizeof(int) + 40*sizeof(char) +2 * sizeof(float) + sizeP;
    sizeS = sizeC + sizeCL + 3*sizeof(int) + 1000*sizeof(char);
    
    *fs = fopen("C:\\Users\\becem\\Desktop\\c\\ProjetProgrammation\\Test.bin", "wb");
    for (int i = 0;i<n;i++){
        fwrite(station+i, sizeS, 1 , *fs);
    }


    fclose(*fs);

}
    
