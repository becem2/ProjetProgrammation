#include "Fonction.c"

void AllocationStation(STATION** station);
void AllocationClients(CLIENT** clients, int n);
void AllocationChargeurs(CHARGEUR** chargeurs, int n);
void AllocationPaiements(PAIEMENT** paiements, int n);
void LibereMemoire(STATION* station);
STATION RemplirStation();
CLIENT RemplirClient(int j);
CHARGEUR RemplirChargeur(int j);
PAIEMENT RemplirPaiement(int j);
void ChargerFichier(STATION** station, const char* filename);
void SauvegarderFichier(STATION* station, const char* filename);
void TempsRestantClient(STATION* station, int clientCode);
void ChargeursDisponibles(STATION* station);
float TotalPaiement(STATION* station);