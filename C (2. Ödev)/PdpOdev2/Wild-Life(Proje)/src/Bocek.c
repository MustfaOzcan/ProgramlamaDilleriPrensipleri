#include "Bocek.h"


Bocek newBocek(char*isim,int sayi){
    Bocek this;
    this=(Bocek)malloc(sizeof(struct BOCEK)); //bocek olustur ve bellek ata

     this->canli=newCanli(isim,sayi); //üst siniftan canli olustur.
    //fonks gostericisi ataması :
    this->deletebocek=&deleteBocek;
    this->getsayibocek=&getSayiBocek;
    this->canli->gorunum=&bocekGorunum;
    return this;
}
char* bocekGorunum(){
    return "C";
}
int  getSayiBocek(const Bocek this){
    return this->canli->sayi;
}
void deleteBocek(const Bocek this){
    if(this==NULL) return;
    this->canli->deletecanli(this->canli);//canliyi yok et
    free(this);//bocegi yok et

}