//=================================================================================================
//                   НАЧАЛО ВЫВОДА ПРИВЕТСТВИЯ НА ЭКРАН ПРИ ВКЛЮЧЕНИИ
void privetstvie() 
{     
   lcd.setCursor(0, 0);
   lcd.print("----AutoWatering----");    // ---AutoWatering----
   lcd.setCursor(0, 1);                  // *DATE: 08.08.1976*
   lcd.print("DATE: ");                  // *TIME: 22:08:54  *
   lcd.print(rtc.getDateStr()); 
   lcd.setCursor(0, 2);         
   lcd.print("TIME: ");         
   lcd.print(rtc.getTimeStr());
   lcd.setCursor(16, 3);         
   lcd.print("v");
   lcd.setCursor(17, 3); 
   lcd.print(version, 1);
   delay (5000);
   lcd.clear();
   
   
} //                   КОНЕЦ ВЫВОДА ПРИВЕТСТВИЯ НА ЭКРАН ПРИ ВКЛЮЧЕНИИ
//=================================================================================================
