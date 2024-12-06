#include "Fonction.c"
int Saisir();
void CreationFichierStation(FILE**);
void Allocation(STATION**,int);
void Allocation1(CHARGEUR** ,int,int);
STATION RemplireStation(int);
CHARGEUR RemplireChargeur(int);
void RemplissageTableauStation(STATION**, int);
void RemplissageFichier(STATION*, int, FILE**);
int FichierExiste(const char*);