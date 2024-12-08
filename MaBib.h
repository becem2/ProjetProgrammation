//Structure paiement : 
struct paiement
{
    int CodePaiement;
    char date[20];
    int StatutPaiement;
    float prix;
};
typedef struct paiement PAIEMENT;

//structure client :
struct client
{
    int CodeClient;
    char Model[20];
    float Pourcentage;
    float TempsRestant;
    int NbPaiement;
    PAIEMENT* paiement;
};
typedef struct client CLIENT;


//Structure chargeur :
struct chargeur
{
    int CodeClient;
    int Type;
    int EtatUtilisation;
    char EtatMaintenance[1000];
};
typedef struct chargeur CHARGEUR;


//Structure station :
struct station
{
    int codeStation;
    char adresse[1000];
    int NbChargeur;
    int NbClient;
    CLIENT* client;
    CHARGEUR* chargeur;
};
typedef struct station STATION;


//structure Partenaire : 
struct partenaire
{
    int CodePartenaire;
    char NomPartenaire[20];
    int TypePartenaire;
    char Feedback[2000];
};
typedef struct partenaire PARTENAIRE;
