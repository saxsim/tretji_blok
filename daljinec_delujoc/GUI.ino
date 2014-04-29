void GUI()
{
lcd.noCursor();
if (0 <= menu && menu < 4 && gumb == 2){
  menu++;
  gumb = 0;
}
if (0 < menu && menu <= 4 && gumb == 1){
  menu--;
  gumb = 0;
}
if (gumb == 3 && menu != 0){
  menu = 0;
}
if (menu == 0 && menu != menuprvr){
  lcd.clear();
  lcd.print("Stevilo bonov:");
  lcd.setCursor(14,0);
  lcd.print(st_bonov);
  lcd.setCursor(0,1);
  lcd.print("Tocim:0,");
    if(pretok < 10){
    lcd.print("0");
    lcd.print(pretok);
    lcd.print("L/bon");
    }
    else {
  lcd.print(pretok);
  lcd.setCursor(11,1);
  lcd.print("L/bon");
    }
  menuprvr = menu;
  lcd.noBlink();
}

if (menu == 1 && menu != menuprvr){
  lcd.clear();
  lcd.print("Nastavi pretok?");
  lcd.setCursor(0,1);
  lcd.print("Trenutni: ");
  lcd.setCursor(10,1);
  lcd.print("0,");
  if(pretok < 10){
    lcd.print("0");
    lcd.print(pretok);
    lcd.print("L");
    }
    else {
  lcd.print(pretok);
  //lcd.setCursor(11,1);
  lcd.print("L");
    }
  menuprvr = menu;
  lcd.noBlink();
}
if (menu == 2 && menu != menuprvr){
  lcd.noBlink();
  lcd.clear();
  lcd.print("Reset stevca?");
  lcd.setCursor(0,1);
  lcd.print("Trenutno st:");
  lcd.setCursor(13,1);
  lcd.print(st_bonov);
  menuprvr = menu;
}
if (menu == 3 && menu != menuprvr){
  lcd.clear();
  lcd.print("Hlajenje");
  lcd.setCursor(0,1);
  lcd.print("Stanje:");
  switch (hlajenje){
    case 0 : lcd.print("OFF");break;
    case 1 : lcd.print("ON ");break;
  }
  menuprvr = menu;
}

if (menu == 1 && gumb == 4){
  menu = 10;
  gumb = 0;
}
if (menu == 2 && gumb == 4){
  menu = 20;
  gumb = 0;
}
if (menu == 3 && gumb == 4){
  menu = 30;
  gumb = 0;
}

if (menu == 10){
  lcd.clear();
  lcd.print("Nov pretok:");
  lcd.setCursor(7,1);
  lcd.print("0,");
  lcd.setCursor(11,1);
  lcd.print("L");
  pretoknprvr = pretok;
    if (pretokn == pretok){
    lcd.setCursor(9,1);
    lcd.print(pretokn);
    lcd.setCursor(9,1);
    }
    if (gumb == 1){
    pretokn++;
    gumb = 0;
    }
    if (gumb == 2){
    pretokn--;
    gumb = 0;
    }
    if (pretokn != pretoknprvr){
      if(pretokn < 10){
        lcd.setCursor(9,1);
        lcd.print("0");
        lcd.print(pretokn);
        pretoknprvr = pretokn;
      } else {
      lcd.setCursor(9,1);
      lcd.print(pretokn);
      lcd.setCursor(9,1),
      pretoknprvr = pretokn;
      }
    }  
    if (pretoknprvr == pretokn && gumb == 4){
      pretok = pretokn;
      menuprvr = menu;
      menu = 1;
      gumb = 0;
    } 
}

if (menu == 20){
  lcd.clear();
  lcd.print("Potrdi reset");
  lcd.blink();
  if(gumb == 4){
    st_bonov = 0;
    menuprvr = menu;
    menu = 2;
    gumb = 0;
  }
}

if (menu == 30){
  lcd.clear();
  lcd.print("Hlajenje:");
  lcd.setCursor(0,1);
  switch (gumb){
    case 1 : hlajenjemenu = 0;gumb = 0;break;
    case 2 : hlajenjemenu = 1;gumb = 0;break;
  }
  switch(hlajenjemenu){
    case 0 : lcd.print("OFF");break;
    case 1 : lcd.print("ON ");break;
  }
  if (gumb == 4){
    hlajenje = hlajenjemenu;
    gumb = 0;
    menuprvr = menu;
    menu = 3;
  }
}
//if (gumb != gumbprvr)
//  {
//    lcd.setCursor (0,1);  
//    lcd.clear();
//  switch (gumb){
//    case 1 :lcd.print("Gor"); break;
//    case 2 :lcd.print("Dol"); break;
//    case 3 :lcd.print("Return"); break;
//    case 4 :lcd.print("Enter"); break;
//    case 5 :lcd.print("Bon"); break;
//    case 6 :lcd.print("Megla"); break;
//  }
//  gumbprvr = gumb;
//  }
}

