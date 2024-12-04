#include "MaBib.h"
#include <stdio.h>
#include <stdlib.h>

int Saisir(){
    int n;
    printf("Ecrire le Nombre de station : ");
    scanf("%d",&n);
    return n;
}

void CreationFichierStation(FILE** f){
    *f = fopen("C:\\Users\\becem\\Desktop\\c\\Project C\\test.bin" , "wb+");
    if(!(*f)) exit(-1);
}

void Allocation(STATION** s, int n){
    *s = (STATION*)malloc(n*sizeof(STATION));
    if (!s) exit(-2);
}
    
