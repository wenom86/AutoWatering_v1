

//=================================================================================================
//                     НАЧАЛО ОБРАБОТКИ НАЖАТИЯ КЛАВИШ     
void NajatieUpDownLeftRight() {

unsigned long currentMillis = millis();
KB.read();                   //считываем нажатие кнопок клавиатуры ВВЕРХ/ВНИЗ.  
if (KB.justPressed()) {
  if (KB.getNum==8){m++; lcd.clear(); if (m>13) {m=13;}                                      //увеличиваем переменную m, если достигнут предел, то оставляем на пределе.
    previousMillisLCDbrightness = currentMillis;  digitalWrite(LCDbright, HIGH);             //сбрасываем таймер подсветки экрана, включаем подсветку.
    }
  if (KB.getNum==2){m--; lcd.clear(); if (m<0) {m=0;}                                        //уменьшаем переменную m, если достигнут предел, то оставляем на пределе.
    previousMillisLCDbrightness = currentMillis;  digitalWrite(LCDbright, HIGH);             //сбрасываем таймер подсветки экрана, включаем подсветку.
    }
  if (KB.getNum==5 && ekran==13){lcd.clear(); m=0;}                                          //
    previousMillisLCDbrightness = currentMillis;  digitalWrite(LCDbright, HIGH);             //

    
//=======================================================================================
//                                 ОПЕРАЦИИ НА ЭКРАНЕ 1  
  if (KB.getNum==3 && ekran==1){time1++; lcd.clear(); if (time1>23) {time1=23;}              //увеличиваем переменную ..., если достигнут предел, то оставляем на пределе.
    previousMillisLCDbrightness = currentMillis;  digitalWrite(LCDbright, HIGH);            //сбрасываем таймер подсветки экрана, включаем подсветку.
    }
  if (KB.getNum==1 && ekran==1){time1--; lcd.clear(); if (time1<0) {time1=0;}                   //уменьшаем переменную ..., если достигнут предел, то оставляем на пределе.
    previousMillisLCDbrightness = currentMillis;  digitalWrite(LCDbright, HIGH);            //сбрасываем таймер подсветки экрана, включаем подсветку.
    }
  if (KB.getNum==9 && ekran==1){time2++; lcd.clear(); if (time2>59) {time2=59;}              //увеличиваем переменную ..., если достигнут предел, то оставляем на пределе.
    previousMillisLCDbrightness = currentMillis;  digitalWrite(LCDbright, HIGH);            //сбрасываем таймер подсветки экрана, включаем подсветку.
    }
  if (KB.getNum==7 && ekran==1){time2--; lcd.clear(); if (time2<0) {time2=0;}               //уменьшаем переменную ..., если достигнут предел, то оставляем на пределе.
    previousMillisLCDbrightness = currentMillis;  digitalWrite(LCDbright, HIGH);            //сбрасываем таймер подсветки экрана, включаем подсветку.
    }
  if (KB.getNum==5 && ekran==1){EEPROM.write(101, time1); EEPROM.write(102, time2); lcd.clear(); m=13;                   
    previousMillisLCDbrightness = currentMillis;  digitalWrite(LCDbright, HIGH);            
    } 
//                                 ОПЕРАЦИИ НА ЭКРАНЕ 1
//======================================================================================= 
//=======================================================================================
//                                 ОПЕРАЦИИ НА ЭКРАНЕ 2  
  if (KB.getNum==3 && ekran==2){time3++; lcd.clear(); if (time3>23) {time3=23;}              //увеличиваем переменную ..., если достигнут предел, то оставляем на пределе.
    previousMillisLCDbrightness = currentMillis;  digitalWrite(LCDbright, HIGH);            //сбрасываем таймер подсветки экрана, включаем подсветку.
    }
  if (KB.getNum==1 && ekran==2){time3--; lcd.clear(); if (time3<0) {time3=0;}                   //уменьшаем переменную ..., если достигнут предел, то оставляем на пределе.
    previousMillisLCDbrightness = currentMillis;  digitalWrite(LCDbright, HIGH);            //сбрасываем таймер подсветки экрана, включаем подсветку.
    }
  if (KB.getNum==9 && ekran==2){time4++; lcd.clear(); if (time4>59) {time4=59;}              //увеличиваем переменную ..., если достигнут предел, то оставляем на пределе.
    previousMillisLCDbrightness = currentMillis;  digitalWrite(LCDbright, HIGH);            //сбрасываем таймер подсветки экрана, включаем подсветку.
    }
  if (KB.getNum==7 && ekran==2){time4--; lcd.clear(); if (time4<0) {time4=0;}               //уменьшаем переменную ..., если достигнут предел, то оставляем на пределе.
    previousMillisLCDbrightness = currentMillis;  digitalWrite(LCDbright, HIGH);            //сбрасываем таймер подсветки экрана, включаем подсветку.
    }
  if (KB.getNum==5 && ekran==2){EEPROM.write(103, time3); EEPROM.write(104, time4); lcd.clear(); m=13;                   
    previousMillisLCDbrightness = currentMillis;  digitalWrite(LCDbright, HIGH);            
    } 
//                                 ОПЕРАЦИИ НА ЭКРАНЕ 2
//======================================================================================= 
//=======================================================================================
//                                 ОПЕРАЦИИ НА ЭКРАНЕ 3  
  if (KB.getNum==3 && ekran==3){time5++; lcd.clear(); if (time5>23) {time5=23;}              //увеличиваем переменную ..., если достигнут предел, то оставляем на пределе.
    previousMillisLCDbrightness = currentMillis;  digitalWrite(LCDbright, HIGH);            //сбрасываем таймер подсветки экрана, включаем подсветку.
    }
  if (KB.getNum==1 && ekran==3){time5--; lcd.clear(); if (time5<0) {time5=0;}                   //уменьшаем переменную ..., если достигнут предел, то оставляем на пределе.
    previousMillisLCDbrightness = currentMillis;  digitalWrite(LCDbright, HIGH);            //сбрасываем таймер подсветки экрана, включаем подсветку.
    }
  if (KB.getNum==9 && ekran==3){time6++; lcd.clear(); if (time6>59) {time6=59;}              //увеличиваем переменную ..., если достигнут предел, то оставляем на пределе.
    previousMillisLCDbrightness = currentMillis;  digitalWrite(LCDbright, HIGH);            //сбрасываем таймер подсветки экрана, включаем подсветку.
    }
  if (KB.getNum==7 && ekran==3){time6--; lcd.clear(); if (time6<0) {time6=0;}               //уменьшаем переменную ..., если достигнут предел, то оставляем на пределе.
    previousMillisLCDbrightness = currentMillis;  digitalWrite(LCDbright, HIGH);            //сбрасываем таймер подсветки экрана, включаем подсветку.
    }
  if (KB.getNum==5 && ekran==3){EEPROM.write(105, time5); EEPROM.write(106, time6); lcd.clear(); m=13;                   
    previousMillisLCDbrightness = currentMillis;  digitalWrite(LCDbright, HIGH);            
    } 
//                                 ОПЕРАЦИИ НА ЭКРАНЕ 3
//=======================================================================================
//=======================================================================================
//                                 ОПЕРАЦИИ НА ЭКРАНЕ 4  
  if (KB.getNum==3 && ekran==4){time7++; lcd.clear(); if (time7>23) {time7=23;}              //увеличиваем переменную ..., если достигнут предел, то оставляем на пределе.
    previousMillisLCDbrightness = currentMillis;  digitalWrite(LCDbright, HIGH);            //сбрасываем таймер подсветки экрана, включаем подсветку.
    }
  if (KB.getNum==1 && ekran==4){time7--; lcd.clear(); if (time7<0) {time7=0;}                   //уменьшаем переменную ..., если достигнут предел, то оставляем на пределе.
    previousMillisLCDbrightness = currentMillis;  digitalWrite(LCDbright, HIGH);            //сбрасываем таймер подсветки экрана, включаем подсветку.
    }
  if (KB.getNum==9 && ekran==4){time8++; lcd.clear(); if (time8>59) {time8=59;}              //увеличиваем переменную ..., если достигнут предел, то оставляем на пределе.
    previousMillisLCDbrightness = currentMillis;  digitalWrite(LCDbright, HIGH);            //сбрасываем таймер подсветки экрана, включаем подсветку.
    }
  if (KB.getNum==7 && ekran==4){time8--; lcd.clear(); if (time8<0) {time8=0;}               //уменьшаем переменную ..., если достигнут предел, то оставляем на пределе.
    previousMillisLCDbrightness = currentMillis;  digitalWrite(LCDbright, HIGH);            //сбрасываем таймер подсветки экрана, включаем подсветку.
    }
  if (KB.getNum==5 && ekran==4){EEPROM.write(107, time7); EEPROM.write(108, time8); lcd.clear(); m=13;                   
    previousMillisLCDbrightness = currentMillis;  digitalWrite(LCDbright, HIGH);            
    } 
//                                 ОПЕРАЦИИ НА ЭКРАНЕ 4
//=======================================================================================  
//=======================================================================================
//                                 ОПЕРАЦИИ НА ЭКРАНЕ 6  
  if (KB.getNum==3 && ekran==6){SetVolumePercent++; lcd.clear(); if (SetVolumePercent>100) {SetVolumePercent=100;}              //увеличиваем переменную ..., если достигнут предел, то оставляем на пределе.
    previousMillisLCDbrightness = currentMillis;  digitalWrite(LCDbright, HIGH);            //сбрасываем таймер подсветки экрана, включаем подсветку.
    }
  if (KB.getNum==1 && ekran==6){SetVolumePercent--; lcd.clear(); if (SetVolumePercent<1) {SetVolumePercent=1;}                   //уменьшаем переменную ..., если достигнут предел, то оставляем на пределе.
    previousMillisLCDbrightness = currentMillis;  digitalWrite(LCDbright, HIGH);            //сбрасываем таймер подсветки экрана, включаем подсветку.
    }
  if (KB.getNum==5 && ekran==6){EEPROM.write(201, SetVolumePercent); lcd.clear(); m=13;                   
    previousMillisLCDbrightness = currentMillis;  digitalWrite(LCDbright, HIGH);            
    } 
//                                 ОПЕРАЦИИ НА ЭКРАНЕ 6
//=======================================================================================




if (KB.isHold()) {
    if (ekran==10&&KB.getNum==5){        }

  } 
}



} //                    КОНЕЦ ОБРАБОТКИ НАЖАТИЯ КЛАВИШ ВВЕРХ/ВНИЗ.
//=================================================================================================
   
