#include <LiquidCrystal.h>
#include <Pushbutton.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int besTL=0;int onTL=0;int yirmiTL=0;int elliTL=0;int yuzTL=0;
int pin = A0;       // define push button input pins
int input4Pin = A1;
int input3Pin = A2;
int input2Pin = A3;
int input1Pin = A4;
int input13=13;
int input10=10;
int input9=9;
int input8=8;
int input7=7;
int input1=1;
int yesil=6;
int kirmizi=A5;
  Pushbutton buton1(input1Pin);
  Pushbutton buton2(input2Pin);
  Pushbutton buton3(input3Pin);
  Pushbutton buton4(input4Pin);
  Pushbutton buton5(pin);
  Pushbutton buton10(input10);
  Pushbutton buton9(input9);
  Pushbutton buton8(input8);
  Pushbutton buton7(input7);
  Pushbutton butonn1(input1);
  Pushbutton buton13(input13);
  
void setup() {
 
  pinMode(pin, INPUT); // declare push button inputs
  pinMode(input4Pin, INPUT);
  pinMode(input3Pin, INPUT);
  pinMode(input2Pin, INPUT);
  pinMode(input1Pin, INPUT);
  pinMode(input13, INPUT);
  pinMode(input10, INPUT);
  pinMode(input9, INPUT);
  pinMode(input8, INPUT);
  pinMode(input7, INPUT);
  pinMode(input1, INPUT);
  pinMode(kirmizi, OUTPUT);
  pinMode(yesil, OUTPUT);
  lcd.begin(20, 4);
  
  lcd.print("Hosgeldiniz!");
}
int y_para=0;int kontrol=0;
int kopuk_sayac=0;int yikama_sayac=0;int kuru_sayac=0;int cila_sayac=0;
int kopukAdet=30;int yikamaAdet=50;int kuruAdet=100;int cilaAdet=20;
int kopukFiyat=15;int yikamaFiyat=10;int kuruFiyat=5;int cilaFiyat=50;
//int besAdet=20;int onAdet=20;int yirmiAdet=10;int elliAdet=30;int yuzAdet=5;
int besAdet=0;int onAdet=0;int yirmiAdet=0;int elliAdet=1;int yuzAdet=0;
int para=0;int b_kontrol=0;
void loop() {
  if (buton1.getSingleDebouncedPress() && kontrol==1 && para>=15){
     lcd.clear();kopuk_sayac++;para-=15;
     lcd.print("Kopukleme: ");lcd.print(kopuk_sayac);lcd.setCursor(0,1);
     lcd.print("Yikama: ");lcd.print(yikama_sayac);lcd.setCursor(0,2);
     lcd.print("Kurulama: ");lcd.print(kuru_sayac);lcd.setCursor(0,3); 
     lcd.print("Cilalama: ");lcd.print(cila_sayac);
  }
  else if (buton2.getSingleDebouncedPress()&& kontrol==1 && para>=10){
     lcd.clear();yikama_sayac++;para-=10;
     lcd.print("Kopukleme: ");lcd.print(kopuk_sayac);lcd.setCursor(0,1);
     lcd.print("Yikama: ");lcd.print(yikama_sayac);lcd.setCursor(0,2);
     lcd.print("Kurulama: ");lcd.print(kuru_sayac);lcd.setCursor(0,3); 
     lcd.print("Cilalama: ");lcd.print(cila_sayac);
  }
  else if (buton3.getSingleDebouncedPress()&& kontrol==1 && para>=5){
     lcd.clear();kuru_sayac++;para-=5;
     lcd.print("Kopukleme: ");lcd.print(kopuk_sayac);lcd.setCursor(0,1);
     lcd.print("Yikama: ");lcd.print(yikama_sayac);lcd.setCursor(0,2);
     lcd.print("Kurulama: ");lcd.print(kuru_sayac);lcd.setCursor(0,3); 
     lcd.print("Cilalama: ");lcd.print(cila_sayac);
  }
  else if (buton4.getSingleDebouncedPress()&& kontrol==1 && para>=50){
   
     lcd.clear();cila_sayac++;para-=50;
     lcd.print("Kopukleme: ");lcd.print(kopuk_sayac);lcd.setCursor(0,1);
     lcd.print("Yikama: ");lcd.print(yikama_sayac);lcd.setCursor(0,2);
     lcd.print("Kurulama: ");lcd.print(kuru_sayac);lcd.setCursor(0,3); 
     lcd.print("Cilalama: ");lcd.print(cila_sayac);
   
  }
  else if (buton5.getSingleDebouncedPress()&& kontrol==1){
    
    int randomm=random(1,5);
    lcd.clear();
    if(randomm==2){
      lcd.print("Para takildi");
      digitalWrite(kirmizi,HIGH);
    }
     else {
      digitalWrite(yesil,HIGH);
   //  lcd.print("Hizmet Kontrol Butonu");
     int tutar=kopuk_sayac*kopukFiyat+yikama_sayac*yikamaFiyat+kuru_sayac*kuruFiyat+cila_sayac*cilaFiyat;
     int kasaPara=besAdet*5+ onAdet*10+yirmiAdet*20+elliAdet*50+yuzAdet*100;
     int paraUstu=y_para-tutar;
    if(paraUstu<=kasaPara){
    int matris[5][3];
    matris[0][0]=100;matris[1][0]=50;matris[2][0]=20;matris[3][0]=10;matris[4][0]=5;
    matris[0][1]=yuzAdet;matris[1][1]=elliAdet;matris[2][1]=yirmiAdet;matris[3][1]=onAdet;matris[4][1]=besAdet;
    for(int i=0;i<5;i++){
       matris[i][2]=paraUstu/matris[i][0];
       if(matris[i][2]>=matris[i][1]){
            matris[i][2]=matris[i][1];
           // printf("%d x %d \n",matris[i][0],matris[i][2]);
            paraUstu-=matris[i][2]*matris[i][0];
            //printf("dfg");
        }
        else{
            paraUstu%=matris[i][0];
        }
        
    }
    yuzAdet-=matris[0][2];
    elliAdet-=matris[1][2];
    yirmiAdet-=matris[2][2];
    onAdet-=matris[3][2];
    besAdet-=matris[4][2];
    int sayac=0;
    int kontroll=0;
    for(int i=0;i<5;i++){
       if((matris[i][2]!=0 && tutar!=y_para)){
        lcd.setCursor(0,sayac);
        lcd.print(matris[i][0]);lcd.print(" x ");lcd.print(matris[i][2]);
        sayac++;
       }
       else if((matris[i][2]==0 && tutar==y_para)){
        lcd.clear();
        lcd.print("para ustu yoktur.");
       }
       else{
        kontroll++;
       }
    }
    if(kontroll==5){
      lcd.clear();
      lcd.print(y_para);
      lcd.print(" iade edildi.");
    }
     }
     else {
      lcd.print("Kasada yeterli para yoktur.");
     }
  }
  }
  else if (buton13.getSingleDebouncedPress()){
     lcd.clear();
     y_para+=5;
     lcd.print(y_para);
     lcd.print(" TL para attiniz.");
     
  }
  else if (buton10.getSingleDebouncedPress()){
     lcd.clear();y_para+=10;
     lcd.print(y_para);
     lcd.print(" TL para attiniz.");
     
  }
  else if (buton9.getSingleDebouncedPress()){
     lcd.clear();y_para+=20;
     lcd.print(y_para);
     lcd.print(" TL para attiniz.");
     
  }
  else if (buton8.getSingleDebouncedPress()){
     lcd.clear();y_para+=50;
     lcd.print(y_para);
     lcd.print(" TL para attiniz.");
     
  }
  else if (buton7.getSingleDebouncedPress()){
     lcd.clear();y_para+=100;
     lcd.print(y_para);
     lcd.print(" TL para attiniz.");
     
  }
  else if (butonn1.getSingleDebouncedPress()){
    if(b_kontrol==0){
     lcd.clear();
     para=y_para;
     lcd.print("Hizmetleri giriniz.");
     b_kontrol=1;
     }
     else{
      lcd.clear();
      lcd.print(yuzAdet);lcd.print("x 100");
      lcd.setCursor(0,1);
      lcd.print(elliAdet);lcd.print("x 50");
      lcd.setCursor(0,2);
      lcd.print(yirmiAdet);lcd.print("x 20");
      lcd.setCursor(0,3);
      lcd.print(onAdet);lcd.print("x 10");
  
      lcd.print(" ");lcd.print(besAdet);lcd.print("x 5");
      b_kontrol=0;
     }
     
    kontrol=1;
  }
  

}
