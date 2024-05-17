#include "stdio.h"
#include "conio.h"

#include "Bitki.h"
#include "Bocek.h"
#include "Sinek.h"
#include "Pire.h"
#include "Habitat.h"
#include "Canli.h"

//ekrani temizle
void clearScreen() {
    system("cls");
}
int _satir_sayisi(const char *dosyaAdi) {
    FILE *dosya = fopen(dosyaAdi, "r");
    int satirSayisi = 1;
    char karakter;

    if (dosya == NULL) {
        printf("Dosya açma hatası!");
        return -1; // Hata durumunda -1 döndür
    }

    // Dosyayı satır satır oku ve her satır okunduğunda satır sayısını artır
    while ((karakter = fgetc(dosya)) != EOF) {
        if (karakter == '\n') {
            satirSayisi++;
        }
    }

    // Dosyayı kapat
    fclose(dosya);
    return satirSayisi;
}
int _sutun_sayisi(const char *dosya_adi) {
    FILE *dosya;
    dosya = fopen(dosya_adi, "r");
    if (dosya == NULL) {
        perror("Dosya acilamadi");
        return -1; // Hata durumunda -1 döndürür
    }

    int max_sutun = 0;
    int suanki_sutun = 0;
    int sayi;

    // Dosyanın her satırını oku
    while (fscanf(dosya, "%d", &sayi) != EOF) {
        suanki_sutun++; // Her sayı bir sütun
        char karakter = fgetc(dosya); // Boşluk ya da satır sonu karakterini oku
        
        if (karakter == '\n' || karakter == EOF) {
            if (suanki_sutun > max_sutun) {
                max_sutun = suanki_sutun;
            }
            suanki_sutun = 0; // Yeni satıra geç
        }
    }

    fclose(dosya);
    
    return max_sutun;
}
void printMatrix(Canli matris[][_sutun_sayisi("Veriler.txt")], int satir, int sutun) {
    for (int i = 0; i < satir; i++) {
        for (int j = 0; j < sutun; j++) {
            printf("%s  ", matris[i][j]->isim); // Canlının görünümünü yazdırma
        }
        printf("\n");
    }
   // printf("\n");
    clearScreen();
   
}
Canli karsilastir(Canli winner, Canli current,int satir,int sutun,Canli matris[][_sutun_sayisi("Veriler.txt")]) {
   
            if (current != NULL && winner != NULL) {
                // Kazananı belirle 
                
                if (winner->isim != current->isim) { // İsimler farklıysa, kazananı belirle
                   
                   
                    if (winner->isim == "B") {
                        
                        if (current->isim == "S" || current->isim == "P") {

                            current->isim = "X";
                           
                            printMatrix(matris,_satir_sayisi("Veriler.txt"),_sutun_sayisi("Veriler.txt"));
                            return winner;
                            
                        }
                        else if(current->isim == "C" )
                        {
                                winner->isim = "X";
                                printMatrix(matris,_satir_sayisi("Veriler.txt"),_sutun_sayisi("Veriler.txt"));
                                return current;
                        } 
                    } else if (winner->isim == "C") {//böcek 
                         
                        if (current->isim == "B" || current->isim == "P") {//bitki pire yer
                            current->isim = "X";
                              
                          printMatrix(matris,_satir_sayisi("Veriler.txt"),_sutun_sayisi("Veriler.txt"));
                            return winner;
                        }
                         else if(current->isim == "S" )
                        {           
                                winner->isim="X";
                              printMatrix(matris,_satir_sayisi("Veriler.txt"),_sutun_sayisi("Veriler.txt"));
                                return current;
                        } 
                    } else if (winner->isim == "S") {//sinek
                         
                        if (current->isim == "C" || current->isim == "P") {//pire ve böcek yer
                            current->isim = "X";
                        
                           printMatrix(matris,_satir_sayisi("Veriler.txt"),_sutun_sayisi("Veriler.txt"));
                            return winner;
                        }
                       else if(current->isim == "B" )
                        {       
                                winner->isim="X";        
                               printMatrix(matris,_satir_sayisi("Veriler.txt"),_sutun_sayisi("Veriler.txt"));
                                return current;
                        } 
                    } else if (winner->isim == "P") {
                        if (current->isim == "B" || current->isim == "S" || current->isim== "C") {
                            winner->isim = "X";
                          
                           printMatrix(matris,_satir_sayisi("Veriler.txt"),_sutun_sayisi("Veriler.txt"));
                            return current;
                             
                        }
                    }
                } else {//winner ve current isimleri aynı 
                    // İsimler aynıysa, sayısal karşılaştırma yap
                    if (winner->sayi != current->sayi) { //winner ve current sayi degerleri farklı
                   
                        if (winner->sayi < current->sayi) {
                            winner->isim = "X";       //winner sayi degeri currentten  küçükse
                                //winner kaybeder  
                           printMatrix(matris,_satir_sayisi("Veriler.txt"),_sutun_sayisi("Veriler.txt"));
                            return current; 
                              
                        } else {
                            current->isim = "X";
                            
                             printMatrix(matris,_satir_sayisi("Veriler.txt"),_sutun_sayisi("Veriler.txt")); 
                            return winner;   

                                       //winner daha büyükse
                        }
                    } else {  //winner ve currernt sayi değerleri aynı ise matris konumlarına bak 
                        // Sayılar eşitse, konum karşılaştırması yap
                      //   printf("isimler ayni sayi degerleri matris uzaklik bak ayni block giris\n"); 
                       int winner_distance_to_end = (satir - 1) + (sutun - 1);
                       int current_distance_to_end = (satir - 1) + (sutun);


                        if (winner_distance_to_end > current_distance_to_end) {
                            winner->isim = "X";
                          
                             printMatrix(matris,_satir_sayisi("Veriler.txt"),_sutun_sayisi("Veriler.txt"));
                            return current;  //winner distance büyük daha uzak 
                           
                        } else {
                            current->isim = "X";
                           
                           printMatrix(matris,_satir_sayisi("Veriler.txt"),_sutun_sayisi("Veriler.txt"));
                            return winner;      //winner distance kücük 
                           
                        }
                    }
                }
                
                // Matrisi  yazdır
                printf("matrisi yadir.\n"); 
                printMatrix(matris,_satir_sayisi("Veriler.txt"),_sutun_sayisi("Veriler.txt"));

            }
            else{
                printf("karsilastir. NULL hatsi");
            }
    
}


int main(){

   // clearScreen();
    FILE *dosya;
    dosya = fopen("Veriler.txt", "r");
    if (dosya == NULL) {
        printf("Dosya açılamadı!");
        exit(1);
    }
    
    
    int sayi;
    
    int satir_sayisi=_satir_sayisi("Veriler.txt");
    int sutun_sayisi=_sutun_sayisi("Veriler.txt");
    Canli matris[satir_sayisi][sutun_sayisi];
    
    int m_i=0;
    int m_j=0;
    while (fscanf(dosya, "%d", &sayi) != EOF) {
        // Her bir sayı için burada işlem yapabiliriz
        // Örneğin ekrana yazdir

        Bitki bitki=NULL;
        Bocek bocek=NULL;
        Sinek sinek=NULL;
        Pire pire=NULL;

        
        if (sayi >= 1 && sayi <= 9) { 
               bitki=newBitki("B",sayi);//bitki olsutur
               matris[m_i][m_j++]= bitki->canli;
              
                
        } else if (sayi >= 10 && sayi <= 20) { // böcek olustur
            bocek=newBocek("C",sayi);
            matris[m_i][m_j++]=bocek->canli;
            
        } else if (sayi >= 21 && sayi <= 50) { // sinek olustur
              sinek=newSinek("S",sayi);
              matris[m_i][m_j++]=sinek->bocek->canli;
        } else if (sayi >= 51 && sayi <= 99) { // pire olustur
               pire=newPire("P",sayi);
               matris[m_i][m_j++]=pire->bocek->canli;

        } else {
            printf("Veriler.txt hatali sayi içeriyor.");
            exit(1);
        }
       
      
  

        if (getc(dosya) == '\n') {
            printf("\n"); // Satır sonu, alt satıra geç
            m_i++;//matris satır 1 arttır 
            m_j=0;//alt satira geçince sutun sifirlandi;
          }

    }
    fclose(dosya);//dosyayi kapat

   //Matris İndis
    int rows=satir_sayisi-1;//matris 0. indis 
    int cols=sutun_sayisi-1;//matris 0. indis
    // Canli Matrisin içeriğini yazdırma
   //Matrisi Ekrana yazdir.
     for ( int i = 0; i <= rows; i++) {
       
        for (int j = 0; j <= cols; j++) {
            printf("%s  ", matris[i][j]->isim); // Canlı ismini yazdırma
        }
        printf("\n");
    }  


   // Canli Matrisin sayideğerini yazdırma Sonra sileriz
  /* for ( int i = 0; i <= rows; i++) {
       
        for (int j = 0; j <= cols; j++) {
            printf("%d  ", matris[i][j]->sayi); // Canlı ismini yazdırma
        }
        printf("\n");
    }  */
    printf("\n");
    
      ///////////////
     ///////////////   SUREC BOLUMU 
    ///////////////
    printf("\n");
    printf("\n");
    //SUREC 
    
    printf("Sureci baslatmak icin herhangi bir tusa basin...");
    getch(); // Kullanıcı herhangi bir tuşa bastığında devam eder
    
    printf("\nSurec basladi!\n");
   
  //  printf("dosya satir sayisi :%d\n",satir_sayisi);//4
  //  printf("dosya col sayisi :%d\n",sutun_sayisi);//5
     printf("\n");
    printf("\n");
     //
    //
   //Karsilastırma İşlemleri:
   //bu kısımda matrisin her bir indisindeki elemanı kazanan ile kıyaslıyoruz 
   //daha basit anlamak için şu şekilde düşünebiliriz kazanan canli yapisi sol elimizde
   //matrisin her bir indisi ise sağ elimizde olsun sol elimdeki canli ile
   //sağ elimdeki canliyi kıyaslıyorum ve kazanani sol elimde tutuyorum.
   // bu mantık ile tüm matrisi tariyorum ve kazanani en son yazdiriyorum.
    Canli winner = NULL;
    int winner_i, winner_j;
    for (int i = 0; i < satir_sayisi; i++) {
        for (int j = 0; j < sutun_sayisi; j++) {
           
            if (!winner) {
                winner = matris[i][j];
                winner_i = i;
                winner_j = j;
            } else {
               // printf(" karsilastir winner a atama yapiyor.\n ");
                winner = karsilastir(winner, matris[i][j], satir_sayisi, sutun_sayisi, matris);
               // printf("%s(main)\n:",winner->isim);
                if (winner == matris[i][j]) {
                    winner_i = i;
                    winner_j = j;
                    // printf(" else içi if\n ");
                }
            }

        }
    }

     for ( int i = 0; i <= rows; i++) {
       
        for (int j = 0; j <= cols; j++) {
            printf("%s  ", matris[i][j]->isim); // Canlı ismini yazdırma
        }
        printf("\n");
    }
     // Kazananı ekrana yazdıralım
    printf("Kazanan: %s\n", winner->isim);
    printf("Kazananin konumu: (%d,%d)\n", winner_i, winner_j);
    
   
   // printMatrix(matris, satir_sayisi, sutun_sayisi);


    // Matris içindeki canlı nesneleri temizleme  
     for (int i = 0; i <= rows; i++) {
        for (int j = 0; j <= cols; j++) {
            matris[i][j]->deletecanli(matris[i][j]);//canlinin icindeki tüm bitki pire sinek alanı bosaltıldı 
        }
    }
    //matris de iade et
    free(matris);
 return 0;
}
