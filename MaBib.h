// Struct Definitions
typedef struct voiture {
    int NbSerie;
    char Marque[100];
    char Model[100];
} VOITURE;

typedef struct date {
    int jour;
    int mois;
    int annee;
} DATE;

typedef struct paiement {
    int CodePaiement;
    DATE date;
    int StatutPaiement;
    float prix;
} PAIEMENT;

typedef struct client {
    int CodeClient;
    VOITURE voiture;
    float Pourcentage;
    float TempsRestant;
    int NbPaiement;
    PAIEMENT* paiement;
} CLIENT;

typedef struct chargeur {
    int CodeClient;
    int Type;
    int EtatUtilisation;
    char EtatMaintenance[1000];
} CHARGEUR;

typedef struct station {
    int codeStation;
    char adresse[1000];
    int NbChargeur;
    int NbClient;
    CLIENT* client;
    CHARGEUR* chargeur;
} STATION;