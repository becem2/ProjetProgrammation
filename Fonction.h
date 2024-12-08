#include "Fonction.c"

int Saisir();
void CreationFichierStation(FILE**);
void Allocation(STATION**,int);
void Allocation1(CHARGEUR** ,int,int);
void Allocation2(CLIENT**, int,int);
STATION RemplireStation(int);
CHARGEUR RemplireChargeur(int);
CLIENT RemplireClient(int);
PAIEMENT RemplirePaiement(int);
void RemplissageTableauStation(STATION**, int);
void RemplissageFichier(STATION*, int, FILE**);
int FichierExiste(const char*);