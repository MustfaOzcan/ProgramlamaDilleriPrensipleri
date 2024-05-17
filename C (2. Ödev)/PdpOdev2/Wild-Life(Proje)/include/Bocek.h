#ifndef BOCEK_H
#define BOCEK_H

#include "Canli.h"

struct BOCEK{
    Canli canli;//üst sinifa erisim
    
    //fonks gosterici:
    void (*deletebocek)(struct BOCEK*);
    int  (*getsayibocek)(struct BOCEK*);
    
};
typedef struct BOCEK* Bocek; 

Bocek newBocek(char*,int);//constructer
char* bocekGorunum();//toString
int  getSayiBocek(const Bocek);//sayi degerini al
void deleteBocek(const Bocek);


#endif