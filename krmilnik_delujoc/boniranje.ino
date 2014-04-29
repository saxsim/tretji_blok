void boniranje()
{
  
  

 
   if (stevec > 0 && stanje_tipke == HIGH && kljucavnica == LOW) {
     
     Serial.println(stevec);
    stevec--;
    digitalWrite(ventil, HIGH);
     digitalWrite(crpalka, HIGH);
    stanje_ventila = HIGH;
    delay(2500);
    digitalWrite(ventil, LOW);
         digitalWrite(crpalka, LOW);

    //txdata.st_bonovrmt = stevec;
    stanje_ventila = LOW;
    ETout.sendData();
    
  }
  
  
}
