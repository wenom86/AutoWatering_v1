//=============================================================
// НАЗВАНИЕ ПРОГРАММЫ: AutoWatering
// ВЕРСИЯ ПРОГРАММЫ: 0.1 (29.05.2020г)
// ВЕРСИЯ ARDUINO IDE: 1.8.11
//=============================================================
#include <AmperkaKB.h>          // + библ. работы с клавиатурой 1х4,4х3,4х4.
#include <OneWire.h>            // + для термодатчика 18b20
#include <LiquidCrystal.h>      // + библ. LCD-экрана.
#include <DS3231.h>             // + библ. работы с модулем часов.
#include <EEPROM.h>             // + библ. работы с EEPROM
float version = 0.2;            // ВЕРСИЯ ПРОГРАММЫ

#define INIT_ADDR 1023              // номер резервной ячейки EEPROM, в которую записывается значение переменной "первого запуска"
#define INIT_KEY 52                 // ключ первого запуска EEPROM. 0-254, на выбор. Если значение в записываемой ячейке отличается от значения ключа "первого запуска", то происходит запись начальных данных во все ячейки EEPROM.
AmperkaKB KB(42, 43, 44, 45, 46, 47, 48, 49); //номера пинов ардуино, подключенные к шлейфу клавиатуры (нумерация слева-направо)
OneWire ds(7);                  // линия 1-Wire (DS18b20 и т.д) будет на pin 7
LiquidCrystal lcd(22, 28, 23, 24, 25, 26, 27);   // для МЕГИ 2560. (A=5v/K=GND)(VSS=GND/VDD=5v/RS=pin22/RW=pin28/E=pin23/D4=pin24/D5=pin25/D6=pin26/D7=pin27).
DS3231  rtc(20, 21);            //шина, на которую подключены часы (для ардуино нано на 328 чипе, это пины A4/A5)(для меги - пины 20/21).
Time  t;                        //переменная для структуры данных часов (t.hour, t.min, t.sec, t.date, t.year). месяц вызывается функцией rtc.getMonthStr()
int sensorVolume = 1023;        //переменная для датчика уровня воды в баке.
int sensorVolumePercent = 100;  //переменная для датчика уровня воды в баке (в процентах)
int SetVolumePercent = 100;
int s,s1,s2 = 0;                //переменная для соленоида наполнения воды в бак(s), переменные для открытия клапанов на полив (s1,s2.....)
long previousMillisLCDbrightness = 0; //счетчик прошедшего времени для Автовыключения подсветки LCD
unsigned long IntervalReadSensorDS = 5000;                // интервал считывания показаний с DS18b20.
unsigned long ValueMillisPreviousReadSensorDS = 0;
long intervalLCDbrightness = 30000;  //задержка Автовыключения подсветки LCD (по умолчанию 300000 = 5 минут)
#define LCDbright 31            // управление вкл/выкл подсветки экрана на 31 пине. 
#define Relay1 11               // пин на реле1
int T1,T2,t3,t4;                // инициализируем переменные для значений температуры..... (T1-подача в теплый пол, T2-обратка из теплого пола, t3-желаемая темп. в помещении, t4-фактическая темп. в помещении)
#define LedPin 13              //Свободная переменная для тестирования во время отладок и т.д.
int ekran;                      //переменная для выбора экрана меню.
int m=0;                        //переменная для экранов меню.
int time1,time2,time3,time4,time5,time6,time7,time8; //переменные для "будильников" ALARM1,2....

int freeRam () {                // функция определения оставшейся памяти в контроллере.
extern int __heap_start, *__brkval; 
int v; 
return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval); }

long previousMillisTimeSW = 0; //счетчик прошедшего времени для мигания изменяемых значений.
long intervalTimeSW = 500;     //интервал мигания изменяемых значений.
int i;

void setup() {
if (EEPROM.read(INIT_ADDR) != INIT_KEY) { // сравнение значения в резервной ячейке со хначением, записанным в EEPROM. Если они не равны, запускается процедура записи значений во все необходимые ячейки.
    EEPROM.write(INIT_ADDR, INIT_KEY);    // записали ключ, ниже записываем данные в ячейки со структурой: EEPROM.put(address, data) EEPROM.put(0, LEDbright);
    EEPROM.write(101, 23); EEPROM.write(102, 40); // будильник 1. Заданное время сработки 23:40
    EEPROM.write(103, 23); EEPROM.write(104, 45); // будильник 2. Заданное время сработки 23:45
    EEPROM.write(105, 23); EEPROM.write(106, 50); // будильник 3. Заданное время сработки 23:50
    EEPROM.write(107, 23); EEPROM.write(108, 55); // будильник 4. Заданное время сработки 23:55
    EEPROM.write(201, 85);                        // установка максимального процента наполнения ёмкости водой.
  }

KB.begin(KB4x4, 3000); // инициализация клавиатуры. значение 3000 - время длительного нажатия кнопки.  
delay(500);            // ожидание
Serial.begin(9600);    // инициализация сериал-порта 0, для вывода служебной инф-ии в монитор порта.
delay(500);            // ожидание  
lcd.begin(20, 4);      // инициализация экрана (20 символов в 4 строках).
delay(500);            // ожидание

rtc.begin();           // инициализация часов на DS3231.
delay(500);            // ожидание
   // Функции установки даты и времени вручную (раскомментировать соответствующую строку вручную и после заливки скетча закомментировать)
   //rtc.setDOW(WEDNESDAY);     // Set Day-of-Week to SUNDAY
   //rtc.setTime(9, 24, 0);     // Set the time to 12:00:00 (24hr format)
   //rtc.setDate(14, 6, 2020);   // Set the date to 14/6/2020

pinMode(LCDbright, OUTPUT);        //выводы устанавливаюся в режим выхода
digitalWrite(LCDbright, HIGH);        //на выходе высокий уровень
pinMode(Relay1, OUTPUT);        //выводы устанавливаюся в режим выхода
digitalWrite(Relay1, HIGH);        //на выходе ВЫСОКИЙ уровень (при высоком уровне реле ВЫКЛЮЧЕНО, и наоборот)
pinMode(LedPin, OUTPUT);           //выводы устанавливаюся в режим выхода
digitalWrite(LedPin, LOW);           //на выходе низкий уровень
privetstvie();         // Выводим приветствие на экран при включении питания(название, версия, часы и т.д.) (вкладка Read_LCD)

SetVolumePercent = EEPROM.read(201);

}
void loop() {

t = rtc.getTime();                                                                                     //присваивание переменной структуры данных часов.                                                               
unsigned long currentMillis = millis();                                                                //Присваивание значения общей переменной отсчета времени.                                                                

if(currentMillis - previousMillisLCDbrightness > intervalLCDbrightness)                                //Если счетчик достиг интервала. 
{previousMillisLCDbrightness = currentMillis;  digitalWrite(LCDbright, LOW); Serial.println("LCDbright OFF");}  //выключаем подсветку LCD, сообщаем в serial.
if(currentMillis - ValueMillisPreviousReadSensorDS > IntervalReadSensorDS)                             //Если счетчик превысил интервал, то:
{ ds18(); sensorVolume; ValueMillisPreviousReadSensorDS = currentMillis; Serial.print(t.hour, DEC); Serial.print(":"); Serial.print(t.min, DEC); Serial.print(":"); Serial.print(t.sec, DEC); Serial.print(" | 18b20: "); Serial.print(ds18()); Serial.print(" | SensorVolume: "); Serial.print(sensorVolume); Serial.print(" | SensorVolumePercent: "); Serial.print(sensorVolumePercent); Serial.print(" | SetVolumePercent: "); Serial.print(SetVolumePercent); Serial.print(" | s: "); Serial.println(s); }  //Cчитываем показания DS18b20 и других датчиков, сообщаем в serial вместе со временем системы.
if(currentMillis - previousMillisTimeSW >= intervalTimeSW)                                             //Если счетчик превысил интервал, (мигание изменяемых величин)
  { i = !i; previousMillisTimeSW = previousMillisTimeSW+intervalTimeSW; }                              //меняем значение переменной i, добавляем к переменной время интервала.


NajatieUpDownLeftRight();    // Обрабатываем нажатие клавиш Вверх/Вниз. (вкладка Read_KEYBOARD)
Ekran();                     // Отображение экрана в зависимости от переменной m (вкладка Read_LCD)
Read_ekran();                // Отображаем содержимое выбранного экрана (вкладка Read_LCD)
WaterSensorVolume();         // Работа с датчиком уровня воды в баке (вкладка Read_SENSOR)



if (sensorVolumePercent<SetVolumePercent){s=1;} if (sensorVolumePercent>SetVolumePercent){s=0;}                                    //..........................
if (time1 == t.hour && time2 == t.min && s == 1){ digitalWrite(Relay1, LOW); }     //..........................
if (s == 0){ digitalWrite(Relay1, HIGH); }
   



}
