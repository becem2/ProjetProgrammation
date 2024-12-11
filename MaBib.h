struct resultat{

};typedef struct resultat RESULTAT;
struct voiture {
    int NbSerie;
    char Marque[100];
    char Model[100];
    float Pourcentage;
    int TypeChargeur;
};
typedef struct voiture VOITURE;

struct date {
    int jour;
    int mois;
    int annee;
};
typedef struct date DATE;

struct paiement {
    DATE date;
    int prix;
};
typedef struct paiement PAIEMENT;

struct client {
    int NbVoiture;
    VOITURE* voiture;
    int NbPaiement;
    PAIEMENT* paiement;
};
typedef struct client CLIENT;

struct chargeur {
    int EtatUtilisation;
    int TypeChargeur;
};
typedef struct chargeur CHARGEUR;

struct station {
    int NbChargeur;
    int NbClient;
    CLIENT* client;
    CHARGEUR* chargeur;
};
typedef struct station STATION;