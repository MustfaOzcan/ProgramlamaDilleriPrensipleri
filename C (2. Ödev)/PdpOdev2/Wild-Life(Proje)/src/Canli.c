#include "Canli.h"
//memory leak checked
Canli newCanli(char* isim,int sayi){  //constructer

	Canli this; 				//Canli turunden 'this' diye pointer olustur.
	this=(Canli)malloc(sizeof(struct CANLI));//heapde yer ac 
	if (this == NULL) {
        printf("Hafıza tahsisi (newCanli) yapılırken hata oluştu\n");
        exit(EXIT_FAILURE);
    }
	
	this->isim=isim; //sinif  attribute atamalari
	this->sayi=sayi; //

	//fonks. gostericisi atamalari :
	this->deletecanli=&deleteCanli;
	
	return this;
}

//memory leak checked
void deleteCanli(Canli this){
	if (this == NULL) {
        printf("Hafıza tahsisi (deleteCanli) yapılırken hata oluştu\n");
        exit(EXIT_FAILURE);
    }
	free(this);
}

