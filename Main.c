#include "Fonction.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>





int main(){
    STATION *station;
    FILE* fs;
    int NbrStation;

    NbrStation = Saisir();
    CreationFichierStation(&fs);
    Allocation(&station,NbrStation);
    /*RemplissageTableauStation(&station, NbrStation);
    RemplissageFichier(&station, NbrStation, &fs);*/


    return 0;
}