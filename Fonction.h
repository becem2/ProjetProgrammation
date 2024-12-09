#include "Fonction.c"

void AllocationStation(STATION** );
void AllocationClients(CLIENT** , int );
void AllocationChargeurs(CHARGEUR** , int );
void AllocationPaiements(PAIEMENT** , int );
void LibereMemoire(STATION* );
STATION RemplirStation();
CLIENT RemplirClient(int );
CHARGEUR RemplirChargeur(int );
PAIEMENT RemplirPaiement(int );
void ChargerFichier(STATION** , const char* );
void SauvegarderFichier(STATION* , const char* );
void TempsRestantClient(STATION* , int );
void ChargeursDisponibles(STATION* );
float TotalPaiement(STATION*);
void AjouterClient(STATION* );
void AjouterChargeur(STATION*);
void AjouterPaiement(STATION* );
