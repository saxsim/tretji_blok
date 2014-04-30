#include <EasyTransfer.h>

//inicializacija komunikacijskega protokola
EasyTransfer ETin, ETout;

struct RECEIVE_DATA_STRUCTURE{
  int st_bonovrmt;
  int ukaz;
  int boni;
  int pretokrmt;
};

struct SEND_DATA_STRUCTURE{
  int ukaz;
  int boni;
  int pretokrmt;
  int st_bonovrmt;
 
};
RECEIVE_DATA_STRUCTURE rxdata;
SEND_DATA_STRUCTURE txdata;


const int crpalka = 2;
const int ventil = 3;
const int grelec = 4;
//const int hladilnik = 7;
//const int lucka = 5;
const int tipka = 13;


boolean deluje = false
int stevec = 0;
int stanje_tipke = 0;
int kljucavnica = LOW;
int stanje_crpalke = 0;
int stanje_ventila = 0;
int stanje_kljucavnice = 0;
int stanje_grelca = 0;


void setup() {
  Serial.begin(9600);
  ETin.begin(details(rxdata), &Serial);
  ETout.begin(details(txdata), &Serial);
  pinMode(crpalka, OUTPUT);      
  pinMode(ventil, OUTPUT);
  pinMode(grelec, OUTPUT);
  //pinMode(lucka, OUTPUT);
  pinMode(tipka, INPUT); 
   digitalWrite(grelec, HIGH);


}

void loop(){

  ukazi();
  

  stanje_tipke = !digitalRead(tipka);
  // stanje_kljucavnice=digitalRead(kljucavnica);
  if(stanje_tipke=HIGH){
    digitalWrite(ventil, HIGH);
     digitalWrite(crpalka, HIGH);
  }
  
    if(stanje_tipke=LOW){
    digitalWrite(ventil, LOW);
     digitalWrite(crpalka, LOW);
  }
  
  
  
 // boniranje();
  delay(300);
  for(int i=0; i<5; i++){
    ETin.receiveData();
  }
  ETout.sendData();
  stevec = rxdata.boni;
  
  
  
   
  
 /* if (stevec > 0) {
    digitalWrite(lucka, HIGH);
  }
  else {
    digitalWrite(lucka, LOW);
  }
 */}
