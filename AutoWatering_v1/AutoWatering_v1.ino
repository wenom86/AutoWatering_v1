//=============================================================
// НАЗВАНИЕ ПРОГРАММЫ: AutoWatering
// ВЕРСИЯ ПРОГРАММЫ: 0.1 (29.05.2020г)
// ВЕРСИЯ ARDUINO IDE: 1.8.11
//=============================================================
#include <AmperkaKB.h>          // + библ. работы с клавиатурой 1х4,4х3,4х4.
#include <OneWire.h>            // + для термодатчика 18b20
#include <LiquidCrystal.h>      // + библ. LCD-экрана.
#include <DS3231.h>             // + библ. работы с модулем часов.
float version = 0.2;            // ВЕРСИЯ ПРОГРАММЫ

AmperkaKB KB(42, 43, 44, 45, 46, 47, 48, 49); //номера пинов ардуино, подключенные к шлейфу клавиатуры (нумерация слева-направо)
OneWire ds(7);                  // линия 1-Wire (DS18b20 и т.д) будет на pin 7
LiquidCrystal lcd(22, 28, 23, 24, 25, 26, 27);   // для МЕГИ 2560. (A=5v/K=GND)(VSS=GND/VDD=5v/RS=pin22/RW=pin28/E=pin23/D4=pin24/D5=pin25/D6=pin26/D7=pin27).
DS3231  rtc(20, 21);            //шина, на которую подключены часы (для ардуино нано на 328 чипе, это пины A4/A5)(для меги - пины 20/21).
long previousMillisLCDbrightness = 0; //счетчик прошедшего времени для Автовылючения подсветки LCD
unsigned long IntervalReadSensorDS = 5000;                // интервал считывания показаний с DS18b20.
unsigned long ValueMillisPreviousReadSensorDS = 0;
long intervalLCDbrightness = 30000;  //задержка Автовыключения подсветки LCD (по умолчанию 300000 = 5 минут)
#define LCDbright 31            // управление вкл/выкл подсветки экрана на 31 пине. 
int T1,T2,t3,t4;                // инициализируем переменные для значений температуры..... (T1-подача в теплый пол, T2-обратка из теплого пола, t3-желаемая темп. в помещении, t4-фактическая темп. в помещении)
int ekran;                      //переменная для выбора экрана меню.
int m=0;                        //переменная для экранов меню.


void setup() {
KB.begin(KB4x4, 3000); // инициализация клавиатуры. значение 3000 - время длительного нажатия кнопки.  
delay(500);            // ожидание
Serial.begin(9600);    // инициализация сериал-порта 0, для вывода служебной инф-ии в монитор порта.
delay(500);            // ожидание  
lcd.begin(20, 4);      // инициализация экрана (20 символов в 4 строках).
delay(500);            // ожидание
rtc.begin();           // инициализация часов на DS3231.
delay(500);            // ожидание
pinMode(LCDbright, OUTPUT);           //выводы устанавливаюся в режим выхода
digitalWrite(LCDbright, HIGH);        //на выходе высокий уровень
privetstvie();         // Выводим приветствие на экран при включении питания(название, версия, часы и т.д.) (вкладка Read_LCD)


}
void loop() {

unsigned long currentMillis = millis();                                                                //Присваивание значения общей переменной отсчета времени.                                                                

if(currentMillis - previousMillisLCDbrightness > intervalLCDbrightness)                                //Если счетчик достиг интервала. 
{previousMillisLCDbrightness = currentMillis;  digitalWrite(LCDbright, LOW); Serial.println("LCDbright OFF");}  //выключаем подсветку LCD, сообщаем в serial.
if(currentMillis - ValueMillisPreviousReadSensorDS > IntervalReadSensorDS)                             //Если счетчик превысил интервал, то:
{ ds18(); ValueMillisPreviousReadSensorDS = currentMillis; Serial.print("18b20: "); Serial.println(ds18()); }  //Cчитываем показания DS18b20, сообщаем в serial.



NajatieUpDownLeftRight();    // Обрабатываем нажатие клавиш Вверх/Вниз. (вкладка Read_KEYBOARD)
Ekran();                     // Отображение экрана в зависимости от переменной m (вкладка Read_LCD)
Read_ekran();                // Отображаем содержимое выбранного экрана (вкладка Read_LCD)
                                                       

}
