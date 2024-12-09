struct voiture {
    int NbSerie;
    char Marque[100];
    char Model[100];
};
typedef struct voiture VOITURE;

struct date {
    int jour;
    int mois;
    int annee;
};
typedef struct date DATE;

struct paiement {
    int CodePaiement;
    DATE date;
    int StatutPaiement;
    float prix;
};
typedef struct paiement PAIEMENT;

struct client {
    int CodeClient;
    VOITURE voiture;
    float Pourcentage;
    float TempsRestant;
    int NbPaiement;
    PAIEMENT* paiement;
};
typedef struct client CLIENT;

struct chargeur {
    int CodeChargeur;
    int Type;
    int EtatUtilisation;
    char EtatMaintenance[1000];
};
typedef struct chargeur CHARGEUR;

struct station {
    int codeStation;
    char adresse[1000];
    int NbChargeur;
    int NbClient;
    CLIENT* client;
    CHARGEUR* chargeur;
};
typedef struct station STATION;