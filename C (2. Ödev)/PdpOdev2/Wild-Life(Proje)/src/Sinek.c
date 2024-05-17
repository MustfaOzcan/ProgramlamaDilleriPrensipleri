#include "Sinek.h"

Sinek newSinek(char*isim,int sayi){
    Sinek this;
    this=(Sinek)malloc(sizeof(struct SINEK));//sinek olustur ve bellek ata
   
    this->bocek=newBocek(isim,sayi);//ust siniftan bocek olustur ust sinif zaten canli olusturuyor
    //fonks gostericisi atamasi : 
    this->deletesinek=&deleteSinek;
    this->getsayisinek=&getSayiSinek;
    this->bocek->canli->gorunum=&sinekGorunum;
  
    return this;
}
char* sinekGorunum(){//toString
    return "S";

}
int  getSayiSinek(const Sinek this){//sayi degerini al
    return this->bocek->canli->sayi;
}

void deleteSinek(const Sinek this){
    if(this==NULL) return;
    this->bocek->deletebocek(this->bocek);//bocegi sil zaten bu fonksiyon canliyi siliyor.
    free(this);  //sinegi sil 
}
