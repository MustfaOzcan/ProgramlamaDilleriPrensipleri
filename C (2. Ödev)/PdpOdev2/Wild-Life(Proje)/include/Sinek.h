#ifndef SINEK_H
#define SINEK_H

#include "Bocek.h"

struct SINEK{
    Bocek bocek;//üst sinifa erisim
    //fonks gosterici:
   
     int  (*getsayisinek)(struct SINEK*);//sinek sayi degeri 
     void (*deletesinek)(struct SINEK*);

};
typedef struct SINEK* Sinek; 

Sinek newSinek(char*,int);//constructer
char* sinekGorunum();//toString
int  getSayiSinek(const Sinek);//sayi degerini al
void deleteSinek(const Sinek);//destructor 

#endif