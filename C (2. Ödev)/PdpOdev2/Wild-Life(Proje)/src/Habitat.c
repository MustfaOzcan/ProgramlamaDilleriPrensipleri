#include "Habitat.h"

Habitat newHabitat(Bitki bitki, Bocek bocek, Sinek sinek, Pire pire){
    Habitat this;
    this=(Habitat)malloc(sizeof(struct HABITAT));
    if(this==NULL) exit(EXIT_FAILURE);

    this->bitki=bitki;
    this->bocek=bocek;
    this->sinek=sinek;
    this->pire=pire;
    
    //fonsk gostericisi atamasi :
    this->deletehabitat=&deleteHabitat;
   
    return this;
}


void deleteHabitat(Habitat this){
    if(this==NULL) exit(EXIT_FAILURE);

    if(this->bitki!=NULL){//bitki sil
        this->bitki->deletebitki(this->bitki);
    }
    if(this->bocek!=NULL){//bocek sil
        this->bocek->deletebocek(this->bocek);
    }
    if(this->sinek!=NULL){//sinek sil
        this->sinek->deletesinek(this->sinek);
    }
    if(this->pire!=NULL){//pire sil 
        this->pire->deletepire(this->pire);
    }

    free(this);//habitati sil 
}