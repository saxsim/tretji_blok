void ukazi()
{
  ETin.receiveData();
  if(rxdata.ukaz == 2){
   digitalWrite(crpalka, HIGH);
   delay(100); 
   stanje_crpalke = HIGH; 
   //Serial.println("megla");
  }
  else if (rxdata.ukaz == 100) {
    digitalWrite(crpalka, LOW);
  }
 
 if(rxdata.ukaz == 1 && kljucavnica == LOW){
   kljucavnica = HIGH;
   //Serial.println("Tocenje mogoce.");
 }
 else if(rxdata.ukaz == 0 && kljucavnica == HIGH){
   kljucavnica = LOW;
   //Serial.println("Tocenje ni mogoce.");
 }
 
 if(rxdata.ukaz == 3 && stanje_grelca == 0){
   digitalWrite(grelec, HIGH);
   stanje_grelca = 1;
   //Serial.println("Grelec ON.");
 }
 else if(rxdata.ukaz == 4 && stanje_grelca == 1){
   digitalWrite(grelec, LOW);
   stanje_grelca = 0;
   //Serial.println("Grelec OFF");
 }
}
