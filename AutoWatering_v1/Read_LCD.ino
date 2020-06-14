//=================================================================================================
//                   НАЧАЛО ВЫВОДА ПРИВЕТСТВИЯ НА ЭКРАН ПРИ ВКЛЮЧЕНИИ
void privetstvie() 
{    
  Serial.print("SKETCH/VERSION: ");
  Serial.print("AutoWatering");
  Serial.print(" v");
  Serial.println(version);
  Serial.print("DATE/TIME: ");
  Serial.print(rtc.getDOWStr());         // Отправка дня недели
  Serial.print(" ");
  Serial.print(rtc.getDateStr());        // Отправка даты
  Serial.print(" -- ");                           
  t = rtc.getTime();
  Serial.print(t.hour, DEC); Serial.print(":"); Serial.print(t.min, DEC); Serial.print(":"); Serial.println(t.sec, DEC); // Отправка времени системы.
  Serial.print("ALARM#1: "); time1 = EEPROM.read(101); Serial.print(time1); Serial.print(":"); time2 = EEPROM.read(102); Serial.println(time2);
  Serial.print("ALARM#2: "); time3 = EEPROM.read(103); Serial.print(time3); Serial.print(":"); time4 = EEPROM.read(104); Serial.println(time4);
  Serial.print("ALARM#3: "); time5 = EEPROM.read(105); Serial.print(time5); Serial.print(":"); time6 = EEPROM.read(106); Serial.println(time6);
  Serial.print("ALARM#4: "); time7 = EEPROM.read(107); Serial.print(time7); Serial.print(":"); time8 = EEPROM.read(108); Serial.println(time8);
  Serial.print("FreeMemory: ");          //Отчет о количестве оставшейся памяти
  Serial.println(freeRam());            // в байтах. (1Кбайт=1024байт) 
   
   lcd.setCursor(0, 0);
   lcd.print("---AutoWarmFloor---");     // ---AutoWatering----
   lcd.setCursor(0, 1);                  // *DATE: 08.08.1976*
   lcd.print("DATE: ");                  // *TIME: 22:08:54  *
   lcd.print(rtc.getDateStr()); 
   lcd.setCursor(0, 2);         
   lcd.print("TIME: ");         
   lcd.print(rtc.getTimeStr());
   lcd.setCursor(0, 3);  
   lcd.print("T1:"); lcd.setCursor(5, 0); lcd.print(ds18()); 
   lcd.setCursor(16, 3);         
   lcd.print("v");
   lcd.setCursor(17, 3); 
   lcd.print(version, 1);
   delay (3000);
   lcd.clear();


} 
//                   КОНЕЦ ВЫВОДА ПРИВЕТСТВИЯ НА ЭКРАН ПРИ ВКЛЮЧЕНИИ
//=================================================================================================

//=================================================================================================
//                   НАЧАЛО ОБРАБОТКИ ВЫБОРА ОТОБРАЖАЕМОГО ЭКРАНА В ЗАВИСИМОСТИ ОТ ПЕРЕМЕННОЙ "m"   
void Ekran()
   {
   if (m==0){ ekran = 0; }         // экран 0 - отображение текущей температуры датчиков Т1...Т4, отображение времени/даты.
   if (m==1){ ekran = 1; }         // экран 1 - установка времени срабатывания(часы,минуты) будильника ALARM1 с сохранением в EEPROM
   if (m==2){ ekran = 2; }         // экран 2 - установка времени срабатывания(часы,минуты) будильника ALARM2 с сохранением в EEPROM
   if (m==3){ ekran = 3; }         // экран 3 - установка времени срабатывания(часы,минуты) будильника ALARM3 с сохранением в EEPROM
   if (m==4){ ekran = 4; }         // экран 4 - установка времени срабатывания(часы,минуты) будильника ALARM4 с сохранением в EEPROM
   if (m==5){ ekran = 5; }
   if (m==6){ ekran = 6; }
   if (m==7){ ekran = 7; }
   if (m==8){ ekran = 8; }
   if (m==9){ ekran = 9; }
   if (m==10){ ekran = 10; }
   if (m==11){ ekran = 11; }
   if (m==12){ ekran = 12; }
   if (m==13){ ekran = 13; }        // экран 13 - отображение экрана о СОХРАНЕНИИ данных в EEPROM
   
} //                   КОНЕЦ ОБРАБОТКИ ВЫБОРА ОТОБРАЖАЕМОГО ЭКРАНА В ЗАВИСИМОСТИ ОТ ПЕРЕМЕННОЙ "m"
//=================================================================================================

//=================================================================================================
//                   НАЧАЛО ОТОБРАЖЕНИЯ ИНФОРМАЦИИ НА ЭКРАНАХ      
void Read_ekran(){

if (ekran==0){                 //переменная ekran=0 (+), главный экран.                               
   lcd.setCursor(0, 0);  lcd.print("T1:"); lcd.setCursor(5, 0); lcd.print(ds18()); lcd.setCursor(8, 0); lcd.print("t3:"); lcd.setCursor(12, 0); lcd.print(ds18());
   lcd.setCursor(0, 1);  lcd.print("T2:"); lcd.setCursor(5, 1); lcd.print(ds18()); lcd.setCursor(8, 1); lcd.print("t4:"); lcd.setCursor(12, 1); lcd.print(ds18());
   lcd.setCursor(12, 2); lcd.print(rtc.getTimeStr());
   lcd.setCursor(10, 3); lcd.print(rtc.getDateStr()); 
   } 
  
else if (ekran==1){
  lcd.setCursor(0, 0);  lcd.print("ALARM1:"); lcd.setCursor(15, 0); if (i == 1) {lcd.print(time1);} if (i == 0){ lcd.print("  ");} lcd.setCursor(17, 0); lcd.print(":"); lcd.setCursor(18, 0); if (i == 1) {lcd.print(time2);} if (i == 0){ lcd.print("  ");}
  lcd.setCursor(0, 1);  lcd.print("1/3-change HOURS");
  lcd.setCursor(0, 2);  lcd.print("7/9-change MINUTES");
  lcd.setCursor(0, 3);  lcd.print("5-save TIME ALARM1");   
   }

else if (ekran==2){
  lcd.setCursor(0, 0);  lcd.print("ALARM2:"); lcd.setCursor(15, 0); if (i == 1) {lcd.print(time3);} if (i == 0){ lcd.print("  ");} lcd.setCursor(17, 0); lcd.print(":"); lcd.setCursor(18, 0); if (i == 1) {lcd.print(time4);} if (i == 0){ lcd.print("  ");}
  lcd.setCursor(0, 1);  lcd.print("1/3-change HOURS");
  lcd.setCursor(0, 2);  lcd.print("7/9-change MINUTES");
  lcd.setCursor(0, 3);  lcd.print("5-save TIME ALARM2"); 
   }
   
else if (ekran==3){
  lcd.setCursor(0, 0);  lcd.print("ALARM3:"); lcd.setCursor(15, 0); if (i == 1) {lcd.print(time5);} if (i == 0){ lcd.print("  ");} lcd.setCursor(17, 0); lcd.print(":"); lcd.setCursor(18, 0); if (i == 1) {lcd.print(time6);} if (i == 0){ lcd.print("  ");}
  lcd.setCursor(0, 1);  lcd.print("1/3-change HOURS");
  lcd.setCursor(0, 2);  lcd.print("7/9-change MINUTES");
  lcd.setCursor(0, 3);  lcd.print("5-save TIME ALARM3");   
   }

else if (ekran==4){
  lcd.setCursor(0, 0);  lcd.print("ALARM4:"); lcd.setCursor(15, 0); if (i == 1) {lcd.print(time7);} if (i == 0){ lcd.print("  ");} lcd.setCursor(17, 0); lcd.print(":"); lcd.setCursor(18, 0); if (i == 1) {lcd.print(time8);} if (i == 0){ lcd.print("  ");}
  lcd.setCursor(0, 1);  lcd.print("1/3-change HOURS");
  lcd.setCursor(0, 2);  lcd.print("7/9-change MINUTES");
  lcd.setCursor(0, 3);  lcd.print("5-save TIME ALARM4");  
   }   

else if (ekran==5){                               
   lcd.setCursor(0, 0);  lcd.print("WaterSolenoid: "); lcd.setCursor(15, 0); if (s == 1) {lcd.print("OPEN ");} if (s == 0){ lcd.print("CLOSE");}
   lcd.setCursor(0, 1);  lcd.print("SensorVolume:"); lcd.setCursor(17, 1); lcd.print(sensorVolume);
   lcd.setCursor(0, 2);  lcd.print("SensorVolumePerc:"); lcd.setCursor(17, 2); lcd.print(sensorVolumePercent);
   lcd.setCursor(0, 3);  lcd.print("s:"); lcd.setCursor(17, 3); lcd.print(s);
   }
   
else if (ekran==6){
   lcd.setCursor(0, 0);  lcd.print("SetVolumePercent"); lcd.setCursor(16, 0); if (i == 1) {lcd.print(SetVolumePercent);} if (i == 0){ lcd.print("   ");} lcd.setCursor(19, 0); lcd.print("%");
   lcd.setCursor(0, 1);  
   lcd.setCursor(0, 2); 
   lcd.setCursor(0, 3);
   }
   
else if (ekran==7){ 
   }   

else if (ekran==8){  
   }

else if (ekran==9){ 
   }

else if (ekran==10){ 
   }
   
else if (ekran==11){
    }

else if (ekran==12){ 
    }
   
else if (ekran==13){
  lcd.setCursor(0, 1);  lcd.print(" SAVE TO EEPROM OK");
    }   
   
} //                  КОНЕЦ ОТОБРАЖЕНИЯ ИНФОРМАЦИИ НА ЭКРАНАХ  
//=================================================================================================
