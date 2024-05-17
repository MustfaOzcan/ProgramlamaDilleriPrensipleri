#include "Bitki.h"
//memory leak checked
Bitki newBitki(char*isim,int sayi)
{  
    Bitki this;
    this=(Bitki)malloc(sizeof(struct BITKI)); //bitki olustur ve bellek ata
	if (this == NULL) {
        printf("Hafıza tahsisi (newBitki) yapılırken hata oluştu\n");
        exit(EXIT_FAILURE);
    }
    this->canli=newCanli(isim,sayi); //üst siniftan canli olustur.
    //fonks gostericisi ataması :
    this->deletebitki=&deleteBitki;
    this->getsayibitki=&getSayiBitki;
    this->canli->gorunum=&bitkiGorunum;
    return this;
}
//checked 
char* bitkiGorunum(){
    
    return "B";
}
//memory leak checked
int getSayiBitki(const Bitki this){
    if(this==NULL) {
        printf("hata getSayiBitki.");
    }
    return this->canli->sayi;
}
//memoryleak checked
void deleteBitki(const Bitki this){
  		if (this == NULL) {
        printf("Hafıza tahsisi (deleteBitki) yapılırken hata oluştu\n");
        exit(EXIT_FAILURE);
        }
    
    this->canli->deletecanli(this->canli); //önce canliyi yok et
    free(this); //sonra bitkiyi yok et
}