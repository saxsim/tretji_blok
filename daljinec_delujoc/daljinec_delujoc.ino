
//inicializacija komunikacijskega protokola
#include <EasyTransfer.h>
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

//definicija LCDja preko I2C
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR    0x27
#define En_pin  2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7
#define BACKLIGHT_PIN     3

LiquidCrystal_I2C	lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);

//definicija tipk
const int S1 = 2;
const int S2 = 3;
const int S3 = 4;
const int S4 = 5;
const int S5 = 6;
const int S6 = 7;
const int S7 = 12;
const int S8 = 13;
//definicija LED diod
const int L1 = 14;
const int L2 = 15;
const int L3 = 16;
const int L4 = 17;
//definicija spremenljivk
int bon = 0;
int megla = 0;
int grelec = 0; //klecno stikalo
int kljuc = 0;  //klecno stikalo

int grelecprvr = 0;
int kljucprvr = -1;
unsigned short hlajenje = 0;
unsigned short hlajenjeprvr = 0;
unsigned short hlajenjemenu = 0;

int tipka1 = 0;
int tipka2 = 0;
int tipka3 = 0;
int tipka4 = 0;

int gumb;
int gumbprvr = 0;
unsigned int st_bonov = 0;
unsigned long pretok = 20;
unsigned long pretokprvr = 20;
unsigned long pretoknprvr;
unsigned long pretokn = pretok;
int st_bonovprvr = -1;
unsigned short st_bonov1prvr = 0;

int menu = 0;
int menuprvr = 1;

void setup() {
  Serial.begin(9600);
  ETin.begin(details(rxdata), &Serial);
  ETout.begin(details(txdata), &Serial);
 
  lcd.begin (16,2); // 
  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
  lcd.setBacklight(HIGH);// Switch on the backlight
  lcd.home (); // go home

   
  pinMode(S1, INPUT);      
  pinMode(S2, INPUT);
  pinMode(S3, INPUT); 
  pinMode(S4, INPUT);
  pinMode(S5, INPUT);
  pinMode(S6, INPUT);
  pinMode(S7, INPUT);
  pinMode(S8, INPUT);
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT); 
  pinMode(L4, OUTPUT);
}

void loop(){
  GUI();  // read the state of the pushbutton value:
  SYNCB();
  bon = digitalRead(S5);
  delay(100);
  megla = digitalRead(S6);
  delay(5);
  kljuc = digitalRead(S8);
  delay(5);
  grelec = digitalRead(S7);
  delay(5);
  tipka1 = digitalRead(S1);
  delay(15);
  tipka2 = digitalRead(S2);
  delay(15);
  tipka3 = digitalRead(S3);
  delay(15);
  tipka4 = digitalRead(S4);
  delay(15);
  
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (bon == HIGH) {     
    st_bonov++;// dodaj bon: 
    st_bonov1prvr = st_bonov;   
    txdata.boni = st_bonov;
    gumb = 5; 
    ETout.sendData();
  } 

  if (megla == HIGH && grelec != 0) {     
    // megla:
    //Serial.print("M");
    txdata.ukaz = 2;
    digitalWrite(L1, HIGH);
    gumb = 6;
    ETout.sendData();    
  } 
  else {
    digitalWrite(L1, LOW);
    txdata.ukaz = 100;
    ETout.sendData();
  }
  
  if (kljuc == HIGH && kljucprvr != kljuc) {
    kljucprvr = kljuc;
    //Serial.print("O");
    txdata.ukaz = 1;
    ETout.sendData(); 
    digitalWrite(L3, HIGH);
    digitalWrite(L4, LOW);
     }
  else if (kljuc == LOW && kljucprvr != kljuc) {
    kljucprvr = kljuc;
    //Serial.print("Z");
    txdata.ukaz = 0;
    ETout.sendData(); 
    digitalWrite(L4, HIGH);
    digitalWrite(L3, LOW);
  }
  if (grelec == HIGH && grelecprvr != grelec) {
    grelecprvr = grelec;
    txdata.ukaz = 3;
    ETout.sendData(); 
    //Serial.print("G");
    digitalWrite(L2, HIGH);
  }
  else if (grelec == LOW && grelecprvr != grelec) {
    grelecprvr = grelec;
    txdata.ukaz = 4;
    ETout.sendData(); 
    //Serial.print("g");
    digitalWrite(L2, LOW);
    
    }
  if (tipka1 == HIGH) {     
    // dodaj cas:    
    //Serial.print("A");
    gumb = 1;
  }
  if (tipka2 == HIGH) {     
    // dodaj cas:    
    //Serial.print("A");
    gumb = 2;
  }
  if (tipka3 == HIGH) {     
    // dodaj cas:    
    //Serial.print("A");
    gumb = 3;
  }
  if (tipka4 == HIGH){
    //Serial.print("C");
    gumb = 4;
  }
  if (tipka1 == HIGH && tipka2 == HIGH && tipka3 == HIGH && tipka4 == HIGH){
    lcd.clear();
  }
  if (hlajenje != hlajenjeprvr){
    switch (hlajenje) {
      case 1 : txdata.ukaz = 5;hlajenjeprvr = hlajenje;ETout.sendData();break;
      case 0 : txdata.ukaz = 6;hlajenjeprvr = hlajenje;ETout.sendData();break;
    }
  }
  if (st_bonov != st_bonov1prvr){
    st_bonov = 0;
    txdata.boni = 0;
    st_bonov1prvr = st_bonov;
  }
 
  if (pretok != pretokprvr){
    txdata.pretokrmt = pretok;
    ETout.sendData();
    pretokprvr = pretok;
  }
 
 /*if (receive != receiveprvr){
 if (receive == 'B'){
   Serial.println(receive);
   
 } 
}*/
}
