#ifndef PIRE_H
#define PIRE_H

#include "Bocek.h"

struct PIRE{
    Bocek bocek;//üst sinifa erisim
    //fonks gosterici:
   
     int  (*getsayipire)(struct PIRE*);//pire sayi degeri 
     void (*deletepire)(struct PIRE*);

};
typedef struct PIRE* Pire; 

Pire newPire(char*,int);//constructer
char* pireGorunum();//toString
int  getSayiPire(const Pire);//sayi degerini al
void deletePire(const Pire);//destructor 

#endif