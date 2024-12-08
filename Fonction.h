#include "Fonction.c"

int Saisir();
void CreationFichierStation(FILE**f);
int FichierExiste(const char*f);
void AllocationStations(STATION**stations, int n);
void AllocationClients(CLIENT**clients, int n);
void AllocationChargeurs(CHARGEUR**chargeurs, int n);
void AllocationPaiements(PAIEMENT**paiements, int n);
PAIEMENT RemplirPaiement(int j);
CLIENT RemplirClient(int j);
CHARGEUR RemplirChargeur(int j);
STATION RemplirStation(int i);
void RemplissageTableauStation(STATION**stations,int n);
void RemplissageFichier(STATION*stations, int n,FILE**fs);
void LibereMemoire(STATION*stations,int n);