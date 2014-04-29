void SYNCB()
{
  //ETin.receiveData();  
  //if (st_bonov != rxdata.st_bonovrmt && st_bonov == st_bonovprvr){
      //st_bonov = rxdata.st_bonovrmt;
  //}
  if (st_bonov != st_bonovprvr && menu == 0){
    lcd.setCursor(14,0);
    lcd.print(st_bonov);
    if(st_bonov < 10 && st_bonovprvr >= 10)
    {
      lcd.clear();
      lcd.print("Stevilo bonov:");
      lcd.setCursor(14,0);
      lcd.print(st_bonov);
      lcd.setCursor(0,1);
      lcd.print("Tocim:0,");
      lcd.setCursor(8,1);
      lcd.print(pretok);
      lcd.setCursor(11,1);
      lcd.print("L");
    }
    st_bonovprvr = st_bonov;
    txdata.boni = st_bonov;
    ETout.sendData();
  }
  
}
      
