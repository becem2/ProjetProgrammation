#include "Fonction.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>





int main(){
    //Testez si la fichier existe ou non
    printf("*-----------------------------*\n");


    FILE *fs;
    char *f = "C:\\Users\\becem\\Desktop\\c\\Project C\\ProjetProgrammation\\Test.bin";
    if (FichierExiste(f) == 1) {
    printf("Fichier existe\n");
    
    } 
    else {
    printf("Fichier non existe\nOn Va cree la fichier\n");
    CreationFichierStation(&fs);
    }

    //Menu
    int Menu,Menu2,Menu3;
    printf("*--------------Menu-------------*\n");
    printf("Pour ajouter une station Tapez  1\n");
    printf("Pour faire un traitement Tapez  2\n");
    printf("Tapez Votre choix ici : ");
    scanf("%d",&Menu);

    switch (Menu)
    {
    case 1:
        printf("Vous avez choisie l'option 1\n");
        break;
    case 2:
        printf("Vous avez choisie l'option 2\n");
        break;
    
    default:
        printf("Vous devez Tapez un nombre correcte\n");
        break;
    }


    //Programme
    
    STATION *station;
    
    int NbrStation;

    NbrStation = Saisir();

    Allocation(&station,NbrStation);

    RemplissageTableauStation(&station, NbrStation);

    /*RemplissageFichier(&station, NbrStation, &fs);*/


    return 0;
}