/*
-------------------------------------------------------
Project: Password Protected Access System
Author: Shubh Jashan Singh
Date: 28-06-2026
-------------------------------------------------------
*/

#include <Keypad.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

//---------------- Keypad ----------------
const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS]={
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}
};

byte rowPins[ROWS]={A0,A1,A2,A3};
byte colPins[COLS]={A4,A5,6,7};

Keypad keypad=Keypad(makeKeymap(keys),rowPins,colPins,ROWS,COLS);

//----------------------------------------

const int greenLED=8;
const int redLED=9;
const int buzzer=10;

String password="1234";
String input="";

int attempts=0;

void showPrompt();
void checkPassword();

void setup(){

lcd.begin(16,2);

pinMode(greenLED,OUTPUT);
pinMode(redLED,OUTPUT);
pinMode(buzzer,OUTPUT);

showPrompt();

}

void loop(){

char key=keypad.getKey();

if(key){

if(key>='0' && key<='9'){

lcd.setCursor(input.length(),1);
lcd.print("*");

input+=key;

}

if(input.length()==4){

checkPassword();

}

}

}

void showPrompt(){

lcd.clear();

lcd.print("ENTER PIN:");

lcd.setCursor(0,1);

input="";

}

void checkPassword(){

if(input==password){

lcd.clear();

lcd.print("ACCESS");

lcd.setCursor(0,1);
lcd.print("GRANTED");

digitalWrite(greenLED,HIGH);

delay(3000);

digitalWrite(greenLED,LOW);

attempts=0;

}

else{

attempts++;

lcd.clear();

lcd.print("ACCESS");

lcd.setCursor(0,1);

lcd.print("DENIED");

digitalWrite(redLED,HIGH);

tone(buzzer,1000,500);

delay(1000);

digitalWrite(redLED,LOW);

if(attempts>=3){

lcd.clear();

lcd.print("LOCKED");

lcd.setCursor(0,1);

lcd.print("10 SECONDS");

delay(10000);

attempts=0;

}

}

showPrompt();

}
