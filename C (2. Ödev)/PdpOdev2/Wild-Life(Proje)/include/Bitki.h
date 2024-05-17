#ifndef BITKI_H
#define BITKI_H

#include "Canli.h"

struct BITKI{
    Canli canli;//üst sinifa erisim
    //fonks gosterici:
   
     int  (*getsayibitki)(struct BITKI*);//bitki sayi degeri 
     void (*deletebitki)(struct BITKI*);

};
typedef struct BITKI* Bitki; 

Bitki newBitki(char*,int);//constructer
char* bitkiGorunum();//toString
int  getSayiBitki(const Bitki);//sayi degerini al
void deleteBitki(const Bitki);//destructor 

#endif