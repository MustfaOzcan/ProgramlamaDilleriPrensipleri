#ifndef HABITAT_H
#define HABITAT_H

#include "Canli.h"
#include "Bitki.h"
#include "Bocek.h"
#include "Sinek.h"
#include "Pire.h"

struct HABITAT {
    
    
    Bitki bitki;
    Bocek bocek;
    Sinek sinek;
    Pire pire;

   
    
    
    //fonks. gostericisi:
    void (*deletehabitat)(struct HABITAT*);
    struct HABITAT** (*matrisolustur)(int, int);    
};
typedef struct HABITAT* Habitat;

Habitat newHabitat(Bitki, Bocek, Sinek, Pire);
Habitat** matrisOlustur(int, int);    
void deleteHabitat(Habitat);

#endif
