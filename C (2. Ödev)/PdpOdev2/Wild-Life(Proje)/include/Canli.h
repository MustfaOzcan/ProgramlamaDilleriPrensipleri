#ifndef CANLI_H
#define CANLI_H

#include "stdio.h"
#include "stdlib.h" //malloc fonks. heap

struct CANLI{
char *isim;
int  sayi;
//fonks gostericisi :
char* (*gorunum) ();
void (*deletecanli) (struct CANLI*);
};
typedef struct CANLI* Canli; //Canlı dedigim her yerde CANLI struct turunde pointer vardir.

Canli newCanli(char*,int);//constructer

void deleteCanli(Canli);


#endif