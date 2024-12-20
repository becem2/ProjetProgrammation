#include "MaBib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void AllocationChargeurs(CHARGEUR** chargeur, int n) {
    *chargeur = (CHARGEUR*)malloc(n * sizeof(CHARGEUR));
    if (!*chargeur) {
        printf("Erreur d'allocation memoire pour les chargeurs.");
        exit(-1);
    }
}
void AllocationClients(CLIENT** client, int n) {
    *client = (CLIENT*)malloc(n * sizeof(CLIENT));
    if (!*client) {
        printf("Erreur d'allocation memoire pour les clients.");
        exit(-2);
    }
}
void AllocationVoitures(VOITURE**voiture,int n){
    *voiture = (VOITURE*)malloc(n * sizeof(VOITURE));
    if (!*voiture) {
        printf("Erreur d'allocation memoire pour les voitures.");
        exit(-3);
    }
}
void AllocationPaiements(PAIEMENT**paiement,int n){
    *paiement = (PAIEMENT*)malloc(n * sizeof(PAIEMENT));
    if (!*paiement) {
        printf("Erreur d'allocation memoire pour les paiements.");
        exit(-4);
    }

}
void RemplireChargeur(STATION**station,int i){
        printf("Saisie l'etat d'utilisation du chargeur (1 = available , 2 = not availabe) : ");
        scanf("%d",&(*station)->chargeur[i].EtatUtilisation);
        printf("Saisire le type du chargeur (1 = american , 2 = francais , 3 = anglais , 4 = african) :");
        scanf("%d",&(*station)->chargeur[i].TypeChargeur);
}
void RemplireClient(STATION**station,int i){
        printf("Tapez le Nombre des voiture : ");
        scanf("%d",&(*station)->client[i].NbVoiture);
        printf("Tapez le Nombre des paiements : ");
        scanf("%d",&(*station)->client[i].NbPaiement);
        AllocationVoitures(&(*station)->client[i].voiture,(*station)->client->NbVoiture);
        AllocationPaiements(&(*station)->client[i].paiement,(*station)->client->NbPaiement);
        for (int j = 0;j<(*station)->client[i].NbVoiture;j++){
            //serie
            printf("Tapez le numero du serie du voiture : ");
            scanf("%d",&(*station)->client[i].voiture[j].NbSerie);
            //model
            printf("Tapez la marque du serie du voiture : ");
            scanf("%99s",&(*station)->client[i].voiture[j].Marque);
            //marque
            printf("Tapez le model du serie du voiture : ");
            scanf("%99s",&(*station)->client[i].voiture[j].Model);
            //pourcentage
            printf("Tapez le pourcentage du serie du voiture : ");
            scanf("%f",&(*station)->client[i].voiture[j].Pourcentage);
            printf("Saisire le type du chargeur (1 = american , 2 = francais , 3 = anglais , 4 = african) :");
            scanf("%d",&(*station)->client[i].voiture[j].TypeChargeur);
        }
        for (int j = 0;j<(*station)->client[i].NbPaiement;j++){
            //date
            printf("Tapez la date du paiements : \n");
            printf("Jour : ");
            scanf("%d",&(*station)->client[i].paiement[j].date.jour);
            printf("Mois : ");
            scanf("%d",&(*station)->client[i].paiement[j].date.mois);
            printf("Annee : ");
            scanf("%d",&(*station)->client[i].paiement[j].date.annee);
            //prix
            printf("Tapez le montant : ");
            scanf("%f",&(*station)->client[i].paiement[j].prix);
        }
}
void RemplireStation(STATION*station){
    printf("Saisire le nombre de chargeurs : ");
    scanf("%d",&station->NbChargeur);
    printf("Saisire le nombre de clients : ");
    scanf("%d",&station->NbClient);
    AllocationChargeurs(&station->chargeur,station->NbChargeur);
    AllocationClients(&station->client,station->NbClient);
    for (int i = 0;i<station->NbChargeur;i++){
        RemplireChargeur(&station,i);
    }
    for (int i = 0;i<station->NbClient;i++){
        RemplireClient(&station,i);
    }
}
void RemplireFichierduTableau(STATION* station){
    FILE *f = fopen("station.bin","wb+");
    fwrite(&(station->NbChargeur),sizeof(int),1,f);
    fwrite(&(station->NbClient),sizeof(int),1,f);
    for (int i = 0;i<station->NbChargeur;i++){
        fwrite(&(station->chargeur[i].EtatUtilisation),sizeof(int),1,f);
        fwrite(&(station->chargeur[i].TypeChargeur),sizeof(int),1,f);
    }
    for (int i =0;i<station->NbClient;i++){
        fwrite(&(station->client[i].NbVoiture),sizeof(int),1,f);
        fwrite(&(station->client[i].NbPaiement),sizeof(int),1,f);
        for (int j=0;j<station->client[i].NbVoiture;j++){
            fwrite(&(station->client[i].voiture[j].NbSerie),sizeof(int),1,f);
            fwrite(&(station->client[i].voiture[j].Marque),sizeof(char),100,f);
            fwrite(&(station->client[i].voiture[j].Model),sizeof(char),100,f);
            fwrite(&(station->client[i].voiture[j].Pourcentage),sizeof(float),1,f);
            fwrite(&(station->client[i].voiture[j].TypeChargeur),sizeof(int),1,f);
        }
        for (int j=0;j<station->client[i].NbPaiement;j++){
            fwrite(&(station->client[i].paiement[j].date.jour),sizeof(int),1,f);
            fwrite(&(station->client[i].paiement[j].date.mois),sizeof(int),1,f);
            fwrite(&(station->client[i].paiement[j].date.annee),sizeof(int),1,f);
            fwrite(&(station->client[i].paiement[j].prix),sizeof(float),1,f);
        }
    }
    fclose(f);
}

void RemplireTableauDuFichier(STATION* station){
    FILE* f = fopen("station.bin","rb");
    fread(&(station->NbChargeur),sizeof(int),1,f);
    fread(&(station->NbClient),sizeof(int),1,f);
    AllocationChargeurs(&station->chargeur,station->NbChargeur);
    AllocationClients(&station->client,station->NbClient);
    for (int i = 0;i<station->NbChargeur;i++){
        fread(&(station->chargeur[i].EtatUtilisation),sizeof(int),1,f);
        fread(&(station->chargeur[i].TypeChargeur),sizeof(int),1,f);
    }
    for (int i =0;i<station->NbClient;i++){
        fread(&(station->client[i].NbVoiture),sizeof(int),1,f);
        fread(&(station->client[i].NbPaiement),sizeof(int),1,f);
        AllocationVoitures(&(station->client[i].voiture),station->client[i].NbVoiture);
        AllocationPaiements(&(station->client[i].paiement),station->client[i].NbPaiement);
        for (int j=0;j<station->client[i].NbVoiture;j++){
            fread(&(station->client[i].voiture[j].NbSerie),sizeof(int),1,f);
            fread(&(station->client[i].voiture[j].Marque),sizeof(char),100,f);
            fread(&(station->client[i].voiture[j].Model),sizeof(char),100,f);
            fread(&(station->client[i].voiture[j].Pourcentage),sizeof(float),1,f);
            fread(&(station->client[i].voiture[j].TypeChargeur),sizeof(int),1,f);
        }
        for (int j=0;j<station->client[i].NbPaiement;j++){
            fread(&(station->client[i].paiement[j].date.jour),sizeof(int),1,f);
            fread(&(station->client[i].paiement[j].date.mois),sizeof(int),1,f);
            fread(&(station->client[i].paiement[j].date.annee),sizeof(int),1,f);
            fread(&(station->client[i].paiement[j].prix),sizeof(float),1,f);
        }
    }
}
void LibereMemoire(STATION*station){
    
    if (!station) return;
    for (int i = 0; i < station->NbClient; i++) {
        free(station->client[i].paiement);
    }
    free(station->client->voiture);
    free(station->client->paiement);
    free(station->client);
    free(station->chargeur);
    free(station);
}

void ModifierClient(STATION*station){
    int ind;
    printf("Saisire le code client : ");
    scanf("%d",&ind);
    ind-=1;
    if (ind < 0 || ind >= station->NbClient) {
        printf("Code client invalide!\n");
        return;
    }
    printf("Saisir le nouveau nombre de voitures pour le client: ");
    scanf("%d", &station->client[ind].NbVoiture);
    printf("Saisir le nouveau nombre de paiements pour le client: ");
    scanf("%d", &station->client[ind].NbPaiement);
    station->client[ind].voiture = (VOITURE*)realloc(station->client[ind].voiture, station->client[ind].NbVoiture*sizeof(VOITURE));
    for (int i = 0; i < station->client[ind].NbVoiture; i++) {
        printf("Nouveau numero de serie (l'ancient est : %d): ",station->client[ind].voiture[i].NbSerie);
        scanf("%d", &station->client[ind].voiture[i].NbSerie);
        printf("Nouveau Marque (l'ancient est : %99s)", station->client[ind].voiture[i].Marque);
        scanf("%99s", station->client[ind].voiture[i].Marque);
        printf("Nouveau Model (l'ancient est : %99s)",station->client[ind].voiture[i].Model);
        scanf("%99s", station->client[ind].voiture[i].Model);
        printf("Nouveau Pourcentage (l'ancient est : %d)",station->client[ind].voiture[i].Pourcentage);
        scanf("%f", &station->client[ind].voiture[i].Pourcentage);
        printf("Nouveau TypeChargeur (l'ancient est : %d)",station->client[ind].voiture[i].TypeChargeur);
        scanf("%f", &station->client[ind].voiture[i].TypeChargeur);
    }
    for (int i = 0; i < station->client[ind].NbPaiement; i++) {
        printf("Saisire la Nouvelle date (l'ancient est : %d/%d/%d) : \n",station->client[ind].paiement[i].date.jour,
        station->client[ind].paiement[i].date.mois,station->client[ind].paiement[i].date.annee);
        printf("Jour : ");
        scanf("%d",&station->client[ind].paiement[i].date.jour);
        printf("Mois : ");
        scanf("%d",&station->client[ind].paiement[i].date.mois);
        printf("Annee : ");
        scanf("%d",&station->client[ind].paiement[i].date.annee);
        printf("Nouveaux prix (l'ancient est : %.2f): ",station->client[ind].paiement[i].prix);
        scanf("%f",&station->client[ind].paiement[i].prix);
    }
    printf("Client Modifie avec succes!!");
}
void ModifierChargeur(STATION*station){
    int ind;
    printf("Saisire le code chargeur : ");
    scanf("%d",&ind);
    ind-=1;
    if (ind < 0 || ind >= station->NbChargeur) {
        printf("Code chargeur invalide!\n");
        return;
    }
    printf("Donner la nouvelle etat d'utilisation (ancienne est : %d) :",station->chargeur[ind].EtatUtilisation);
    scanf("%d",&station->chargeur[ind].EtatUtilisation);
    printf("Donner Nouveaux TypeChargeur (ancienne est : %d) :",station->chargeur[ind].TypeChargeur);
    scanf("%d",&station->chargeur[ind].TypeChargeur);

    printf("Chargeur modifiee avec succes!\n");
}




void ModifierVoiture(STATION*station){
    int indC,indV;
    printf("Saisir le code du client a modifier : ");
    scanf("%d", &indC);
    indC -= 1;
    if (indC < 0 || indC >= station->NbClient) {
        printf("Code client invalide!\n");
        return;
    }
    printf("Saisir le code du voiture a modifier : ");
    scanf("%d", &indV);
    indV -= 1;
    if (indV < 0 || indV >= station->client[indC].NbVoiture) {
        printf("Code Voiture invalide!\n");
        return;
    }
    printf("Donner la nouvelle serie de la voiture (ancienne est : %d) : ",station->client[indC].voiture[indV].NbSerie);
    scanf("%d",&station->client[indC].voiture[indV].NbSerie);
    printf("Donner la nouvelle marque de la voiture (ancienne est : %d) : ",station->client[indC].voiture[indV].Marque);
    scanf("%99s",&station->client[indC].voiture[indV].Marque);
    printf("Donner le nouveaux model de la voiture (ancienne est : %d) : ",station->client[indC].voiture[indV].Model);
    scanf("%99s",&station->client[indC].voiture[indV].Model);
    printf("Donner la nouvelle pourcentage de la voiture (ancienne est : %d) : ",station->client[indC].voiture[indV].Pourcentage);
    scanf("%.2f",&station->client[indC].voiture[indV].Pourcentage);
    printf("Donner le nouveaux typechargeur de la voiture (ancienne est : %d) : ",station->client[indC].voiture[indV].TypeChargeur);
    scanf("%d",&station->client[indC].voiture[indV].TypeChargeur);

    printf("voiture modifiee avec succes!\n");
}
void ModifierPaiement(STATION*station){
    int indC,indP;
    printf("Saisir le code du client a supprimer : ");
    scanf("%d", &indC);
    indC -= 1;
    if (indC < 0 || indC >= station->NbClient) {
        printf("Code client invalide!\n");
        return;
    }
    printf("Saisir le code du paiement a supprimer : ");
    scanf("%d", &indP);
    indP -= 1;
    if (indP < 0 || indP >= station->client[indC].NbPaiement) {
        printf("Code Paiement invalide!\n");
        return;
    }
    printf("Donner Nouvelle Date : (ancienne est : %d/%d/%d) : \n",station->client[indC].paiement[indP].date.jour,
    station->client[indC].paiement[indP].date.mois,station->client[indC].paiement[indP].date.annee);
    printf("Jour : ");
    scanf("%d",&station->client[indC].paiement[indP].date.jour);
    printf("Mois : ");
    scanf("%d",&station->client[indC].paiement[indP].date.mois);
    printf("Annee : ");
    scanf("%d",&station->client[indC].paiement[indP].date.annee);
    printf("Donner Nouveaux prix : (ancien est : %.2f) : \n",station->client[indC].paiement[indP].prix);
    scanf("%f",&station->client[indC].paiement[indP].prix);
}

void AjoutClient(STATION*station){
    station->client = (CLIENT*)realloc(station->client,((station->NbClient)+1)*sizeof(CLIENT));
    RemplireClient(&station,station->NbClient);
    station->NbClient +=1;
}
void AjoutChargeur(STATION*station){
    station->chargeur = (CHARGEUR*)realloc(station->chargeur,((station->NbChargeur)+1)*sizeof(CHARGEUR));
    RemplireChargeur(&station,station->NbChargeur);
    station->NbChargeur +=1;
}
void AjoutVoiture(STATION*station){
    int ind;
    printf("Saisire le code client : ");
    scanf("%d",&ind);
    ind -=1;
    if (ind < 0 || ind >= station->NbClient) {
        printf("Code client invalide!\n");
        return;
    }
    station->client[ind].voiture = (VOITURE*)realloc(station->client[ind].voiture, 
    (station->client[ind].NbVoiture + 1) * sizeof(VOITURE));
    station->client[ind].NbVoiture +=1;
    int n = station->client[ind].NbVoiture-1;

    printf("Tapez le numero du serie du voiture : ");
    scanf("%d",&station->client[ind].voiture[n].NbSerie);
    //model
    printf("Tapez la marque du serie du voiture : ");
    scanf("%99s",&station->client[ind].voiture[n].Marque);
    //marque
    printf("Tapez le model du serie du voiture : ");
    scanf("%99s",&station->client[ind].voiture[n].Model);
    //pourcentage
    printf("Tapez le pourcentage du serie du voiture : ");
    scanf("%f",&station->client[ind].voiture[n].Pourcentage);

}
void AjoutPaiement(STATION*station){
    int ind;
    printf("Saisire le code client : ");
    scanf("%d",&ind);
    ind -=1;
    if (ind < 0 || ind >= station->NbClient) {
        printf("Code client invalide!\n");
        return;
    }
    station->client[ind].paiement = (PAIEMENT*)realloc(station->client[ind].paiement,
     (station->client[ind].NbPaiement + 1) * sizeof(PAIEMENT));
    station->client[ind].NbPaiement +=1;
    int n = station->client[ind].NbPaiement-1;
    printf("Tapez la date du paiements : \n");
    printf("Jour : ");
    scanf("%d",&station->client[ind].paiement[n].date.jour);
    printf("Mois : ");
    scanf("%d",&station->client[ind].paiement[n].date.mois);
    printf("Annee : ");
    scanf("%d",&station->client[ind].paiement[n].date.annee);
    printf("Tapez le montant : ");
    scanf("%f",&station->client[ind].paiement[n].prix);
}
void SupprimerChargeur(STATION*station) {
    int ind;
    printf("Saisir le code du chargeur a supprimer : ");
    scanf("%d", &ind);
    ind -= 1;
    if (ind < 0 || ind >= station->NbChargeur) {
        printf("Code chargeur invalide!\n");
        return;
    }
    for (int i = ind;i <station->NbChargeur -1;i++) {
        station->chargeur[i]=station->chargeur[i+1];
    }

    station->chargeur = (CHARGEUR*)realloc(station->chargeur,(station->NbChargeur-1)*sizeof(CHARGEUR));
    station->NbChargeur -= 1;

    printf("Chargeur supprime avec succes\n");
}
void SupprimerClient(STATION*station){
    int ind;
    printf("Saisir le code du client a supprimer : ");
    scanf("%d", &ind);
    ind -= 1;
    if (ind < 0 || ind >= station->NbClient) {
        printf("Code client invalide!\n");
        return;
    }
    for (int i=ind;i <station->NbClient -1;i++) {
        station->client[i]=station->client[i+1];
    }
    station->client = (CLIENT*)realloc(station->client,(station->NbClient-1)*sizeof(CLIENT));
    station->NbClient -= 1;
    printf("Client supprime avec succes\n");
}
void SupprimerVoiture(STATION*station){
    int indC,indV;
    printf("Saisir le code du client a supprimer : ");
    scanf("%d", &indC);
    indC -= 1;
    if (indC < 0 || indC >= station->NbClient) {
        printf("Code client invalide!\n");
        return;
    }
    printf("Saisir le code du voiture a supprimer : ");
    scanf("%d", &indV);
    indV -= 1;
    if (indV < 0 || indV >= station->client[indC].NbVoiture) {
        printf("Code Voiture invalide!\n");
        return;
    }
    for (int i=indV;i <station->client[i].NbVoiture -1;i++) {
        station->client[indC].voiture[i]=station->client[indC].voiture[i+1];
    }
    station->client[indC].voiture = (VOITURE*)realloc(station->client[indC].voiture,
    (station->client[indC].NbVoiture-1)*sizeof(VOITURE));
    station->client[indC].NbVoiture -= 1;
    printf("Voiture supprime avec succes\n");
}

void SupprimerPaiement(STATION*station){
    int indC,indP;
    printf("Saisir le code du client a supprimer : ");
    scanf("%d", &indC);
    indC -= 1;
    if (indC < 0 || indC >= station->NbClient) {
        printf("Code client invalide!\n");
        return;
    }
    printf("Saisir le code du paiement a supprimer : ");
    scanf("%d", &indP);
    indP -= 1;
    if (indP < 0 || indP >= station->client[indC].NbPaiement) {
        printf("Code Paiement invalide!\n");
        return;
    }
    for (int i=indP;i <station->client[i].NbPaiement -1;i++) {
        station->client[indC].paiement[i]=station->client[indC].paiement[i+1];
    }
    station->client[indC].paiement = (PAIEMENT*)realloc(station->client[indC].paiement,
    (station->client[indC].NbPaiement-1)*sizeof(PAIEMENT));
    station->client[indC].NbPaiement -= 1;
    printf("Paiement supprime avec succes\n");
}

void AfficherClient(STATION*station){
    int ind;
    printf("Saisir le code du client a Afficher : ");
    scanf("%d", &ind);
    ind -= 1;
    if (ind < 0 || ind >= station->NbClient) {
        printf("Code client invalide!\n");
        return;
    }
    printf("Code Client : %d\n",ind+1);
    printf("Nombre Voiture : %d\n",station->client[ind].NbVoiture);
    for (int i =0;i<station->client[ind].NbVoiture;i++){
        printf("Numero de serie de la voiture : %d\n",station->client[ind].voiture[i].NbSerie);
        printf("Marque de la voiture : %99s\n",station->client[ind].voiture[i].Marque);
        printf("Model de la voiture : %99s\n",station->client[ind].voiture[i].Model);
        printf("Pourcentage de la voiture : %.2f\n",station->client[ind].voiture[i].Pourcentage);
        printf("TypeChargeur de la voiture : %d\n",station->client[ind].voiture[i].TypeChargeur);
    }
    
    printf("Nombre Paiement : %d\n",station->client[ind].NbPaiement);
    for(int i = 0;i<station->client[ind].NbPaiement;i++){
        printf("Date du paiement : %2d/%2d/%4d\n",station->client[ind].paiement[i].date.jour,
        station->client[ind].paiement[i].date.mois,station->client[ind].paiement[i].date.annee);
        printf("Montant du paiement : %.2f\n",station->client[ind].paiement[i].prix);
    }

}
void AfficherChargeur(STATION*station){
    int ind;
    printf("Saisir le code du chargeur a Afficher : ");
    scanf("%d", &ind);
    ind -= 1;
    if (ind < 0 || ind >= station->NbChargeur) {
        printf("Code chargeur invalide!\n");
        return;
    }
    printf("Etat utilisation : %d\n",station->chargeur[ind].EtatUtilisation);
    printf("TypeChargeur : %d\n",station->chargeur[ind].TypeChargeur);
    
}
void AfficherVoiture(STATION*station){
    int indC,indV;
    printf("Saisir le code du client a Afficher : ");
    scanf("%d", &indC);
    indC -= 1;
    if (indC < 0 || indC >= station->NbClient) {
        printf("Code client invalide!\n");
        return;
    }
    printf("Saisir le code du voiture a Afficher : ");
    scanf("%d", &indV);
    indV -= 1;
    if (indV < 0 || indV >= station->client[indC].NbVoiture) {
        printf("Code Voiture invalide!\n");
        return;
    }
    printf("Numero Serie de la voiture : %d\n",station->client[indC].voiture[indV].NbSerie);
    printf("Marque de la voiture : %99s\n",station->client[indC].voiture[indV].Marque);
    printf("Model de la voiture : %99s\n",station->client[indC].voiture[indV].Model);
    printf("Pourcentage de la voiture : %.2f\n",station->client[indC].voiture[indV].Pourcentage);
    printf("TypeChargeur de la voiture : %d\n",station->client[indC].voiture[indV].TypeChargeur);
}
void AfficherPaiement(STATION*station){
    int indC,indP;
    printf("Saisir le code du client a Afficher : ");
    scanf("%d", &indC);
    indC -= 1;
    if (indC < 0 || indC >= station->NbClient) {
        printf("Code client invalide!\n");
        return;
    }
    printf("Saisir le code du paiement a Afficher : ");
    scanf("%d", &indP);
    indP -= 1;
    if (indP < 0 || indP >= station->client[indC].NbPaiement) {
        printf("Code Paiement invalide!\n");
        return;
    }
    printf("Date du paiement : %2d/%2d/%4d\n",station->client[indC].paiement[indP].date.jour,
    station->client[indC].paiement[indP].date.mois,station->client[indC].paiement[indP].date.annee);
    printf("Montant du paiement : %.2f \n",station->client[indC].paiement[indP].prix);
    
}
float TotalePaiement(STATION*station){
    float x = 0;
    for (int i = 0;i<station->NbClient;i++){
        for (int j = 0;j<station->client[i].NbPaiement;j++){
            x += station->client[i].paiement[j].prix;
        }
    }
    return x;
}
void TempsRestant(STATION*station){
    int indC,indV;
    printf("Saisir le code du client : ");
    scanf("%d", &indC);
    indC -= 1;
    if (indC < 0 || indC >= station->NbClient) {
        printf("Code client invalide!\n");
        return;
    }
    printf("Saisir le code du voiture : ");
    scanf("%d", &indV);
    indV -= 1;
    if (indV < 0 || indV >= station->client[indC].NbVoiture) {
        printf("Code Voiture invalide!\n");
        return;
    }
    float temp;
    int heure,minute,seconde;
    temp = (100 - station->client[indC].voiture[indV].Pourcentage)*150;
    heure = (int)temp /3600;
    minute = ((int)temp %3600 )/60;
    seconde = (int)temp %60;
    printf("Temps restant est : %d:%d:%d",heure,minute,seconde);
}

void TrouverChargeur(STATION*station){
    int indC,indV;
    printf("Saisir le code du client : ");
    scanf("%d", &indC);
    indC -= 1;
    if (indC < 0 || indC >= station->NbClient) {
        printf("Code client invalide!\n");
        return;
    }
    printf("Saisir le code du voiture : ");
    scanf("%d", &indV);
    indV -= 1;
    if (indV < 0 || indV >= station->client[indC].NbVoiture) {
        printf("Code Voiture invalide!\n");
        return;
    }
    int NbChargeurDisponible= 0;
    int TypeChargeurVoiture = station->client[indC].voiture[indV].TypeChargeur;
    for (int i  = 0;i<station->NbChargeur;i++){
        if (TypeChargeurVoiture == station->chargeur[i].TypeChargeur && station->chargeur[i].EtatUtilisation == 1) 
        NbChargeurDisponible ++;
    }
    if (NbChargeurDisponible>0) printf("Il est %d Chargeur disponible de meme type \n",NbChargeurDisponible);
    else printf("Il n'ya pas de chargeur de meme type disponible \n");

}
void CombienChargeurDisponible(STATION*station){
    int disp;
    for (int i =0;i<station->NbChargeur;i++){
        if(station->chargeur[i].EtatUtilisation == 1) disp++;
    }
    if (disp>0) printf("Il y'a %d Chargeur disponible\n",disp);
    else printf("Il n'ya aucun chargeur disponible\n");
}
void PlusChargeeVoiture(STATION*station){
    float max = 0;
    int indMaxC= 0,indMaxV = 0;

    for (int i = 0;i<station->NbClient;i++){
        for (int j = 0;j<station->client[i].NbVoiture;j++){
            if(max<station->client[i].voiture[j].Pourcentage){
                max = station->client[i].voiture[j].Pourcentage;
                indMaxV = j;
                indMaxC = i;
            }
        }
    }
    printf("La voiture la plus chargee est %s %s du client %d\n",
    station->client[indMaxC].voiture[indMaxV].Marque,station->client[indMaxC].voiture[indMaxV].Model,
    indMaxC+1);
}
void MoinChargeeVoiture(STATION*station){
    float min = 0;
    int indMinC= 0,indMinV = 0;

    for (int i = 0;i<station->NbClient;i++){
        for (int j = 0;j<station->client[i].NbVoiture;j++){
            if(min>station->client[i].voiture[j].Pourcentage){
                min = station->client[i].voiture[j].Pourcentage;
                indMinV = j;
                indMinC = i;
            }
        }
    }
    printf("La voiture la moins chargee est %s %s du client %d\n",
    station->client[indMinC].voiture[indMinV].Marque,station->client[indMinC].voiture[indMinV].Model,
    indMinC+1);

}
void MarqueDeVoiture(STATION*station) {
    char marque[50];
    int DejaProccede = 0;
    const int n = station->NbClient;
    char MatDejaFais[n*50][50];
    for (int i = 0; i < station->NbClient; i++) {
        for (int j = 0; j < station->client[i].NbVoiture; j++) {
            int DejaFais = 0;
            strcpy(marque, station->client[i].voiture[j].Marque);
            for (int p = 0; p < DejaProccede; p++) {
                if (strcmp(MatDejaFais[p], marque) == 0) {
                    DejaFais = 1;
                    break;
                }
            }
            if (DejaFais) {
                continue;
            }
            strcpy(MatDejaFais[DejaProccede], marque);
            DejaProccede++;
            int x = 0;
            for (int k = 0; k < station->NbClient; k++) {
                for (int z = 0; z < station->client[k].NbVoiture; z++) {
                    if (strcmp(station->client[k].voiture[z].Marque, marque) == 0) {
                        x++;
                    }
                }
            }

            printf("La marque %s apparait %d fois.\n", marque, x);
        }
    }
}
float Somme(STATION* station, int i) {
    float s = 0; 
    for (int j = 0; j < station->client[i].NbPaiement; j++) {
        s += station->client[i].paiement[j].prix;
    }
    return s;
}

RESULTAT* MeilleurClient(STATION* station) {
    RESULTAT* resultat = (RESULTAT*)malloc(3 * sizeof(RESULTAT));

    int indTop1 = -1, indTop2 = -1, indTop3 = -1;
    float max1 = 0.0, max2 = 0.0, max3 = 0.0;

    for (int i = 0; i < station->NbClient; i++) {
        float sommePaiements = Somme(station, i);

        if (sommePaiements > max1) {
            max3 = max2;
            indTop3 = indTop2;

            max2 = max1;
            indTop2 = indTop1;

            max1 = sommePaiements;
            indTop1 = i;
        } else if (sommePaiements > max2) {
            max3 = max2;
            indTop3 = indTop2;

            max2 = sommePaiements;
            indTop2 = i;
        } else if (sommePaiements > max3) {
            max3 = sommePaiements;
            indTop3 = i;
        }
    }

    resultat[0].CodeClient = indTop1;
    resultat[0].SommePaiements = max1;

    resultat[1].CodeClient = indTop2;
    resultat[1].SommePaiements = max2;

    resultat[2].CodeClient = indTop3;
    resultat[2].SommePaiements = max3;

    return resultat;
}




