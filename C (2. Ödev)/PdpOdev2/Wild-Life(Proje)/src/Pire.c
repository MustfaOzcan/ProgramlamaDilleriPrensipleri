#include "Pire.h"


Pire newPire(char*isim,int sayi){
    Pire this;
    this=(Pire)malloc(sizeof(struct PIRE));

    this->bocek=newBocek(isim,sayi);
    this->getsayipire=&getSayiPire;
    this->deletepire=&deletePire;
    this->bocek->canli->gorunum=&pireGorunum;
    return this;
}
char* pireGorunum(){
return "P";
}
int  getSayiPire(const Pire this){
    return this->bocek->canli->sayi;
}

void deletePire(const Pire this){
 if(this==NULL) return;
    this->bocek->deletebocek(this->bocek);//bocegi sil zaten bu fonksiyon canliyi siliyor.
    free(this);  //pireyi sil 
}//destructor 