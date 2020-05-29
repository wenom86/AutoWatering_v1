

//=================================================================================================
//                     НАЧАЛО ОБРАБОТКИ НАЖАТИЯ КЛАВИШ     
void NajatieUpDownLeftRight() {

unsigned long currentMillis = millis();
KB.read();                   //считываем нажатие кнопок клавиатуры ВВЕРХ/ВНИЗ.  
if (KB.justPressed()) {
    if (KB.getNum==8){m++; lcd.clear(); if (m>2) {m=2;}                                      //увеличиваем переменную m, если достигнут предел, то оставляем на пределе.
    previousMillisLCDbrightness = currentMillis;  digitalWrite(LCDbright, HIGH);             //сбрасываем таймер подсветки экрана, включаем подсветку.
    }
    if (KB.getNum==2){m--; lcd.clear(); if (m<0) {m=0;}                                      //уменьшаем переменную m, если достигнут предел, то оставляем на пределе.
    previousMillisLCDbrightness = currentMillis;  digitalWrite(LCDbright, HIGH);            //сбрасываем таймер подсветки экрана, включаем подсветку.
    }



}


if (KB.isHold()) {
    if (ekran==10&&KB.getNum==5){        }


  } 





}
//                    КОНЕЦ ОБРАБОТКИ НАЖАТИЯ КЛАВИШ ВВЕРХ/ВНИЗ.
//=================================================================================================
   
