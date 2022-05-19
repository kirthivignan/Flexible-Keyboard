
#include <BleKeyboard.h>
//Set the name of the bluetooth keyboard (that shows up in the bluetooth menu of your device)
BleKeyboard bleKeyboard("flex keyboard");




char chars[] = " abcdefghijklmnopqrstuvwxyz";


// Potentiometer is connected  
const int in1 = 34;
const int in2 = 35;
const int in3 = 32;
const int in4 = 33;
const int in5 = 26;

// variable for storing the potentiometer value
float inval1 = 0;
float inval2 = 0;
float inval3 = 0;
float inval4 = 0;
float inval5 = 0;

boolean oldPinState1 = LOW;
boolean oldPinState2 = LOW;
boolean oldPinState3 = LOW;
boolean oldPinState4 = LOW;
boolean oldPinState5 = LOW;



boolean PS1;
boolean PS2;
boolean PS3;
boolean PS4;
boolean PS5;


void setup() {
  Serial.begin(115200);
    Serial.println("Starting BLE work!");
  //Begin the BLE keyboard/start advertising the keyboard (so phones can find it)
  bleKeyboard.begin();
  delay(1000);
}

void loop() {
//   Reading potentiometer value

  float inval1 = ((analogRead(in1)*3.3)/4095);
  if(inval1<2.5){ PS1= HIGH;}
  if(inval1>=2.5){PS1= LOW;}
//  Serial.println("voltage1  ");
//Serial.print(inval1);
    float inval2 = ((analogRead(in2)*3.3)/4095);
      if(inval2<2.5){PS2= HIGH;}
      if(inval2>=2.5){PS2= LOW;}
//  Serial.println("voltage2  ");
//  Serial.print(inval2);
    float inval3 = ((analogRead(in3)*3.3)/4095);
      if(inval3<2.5){ PS3= HIGH;}
      if(inval3>=2.5){PS3= LOW;}
//  Serial.println("voltage3  ");
//  Serial.print(inval3);
    float inval4 = ((analogRead(in4)*3.3)/4095);
      if(inval4<2.5){PS4= HIGH;}
      if(inval4>=2.5){PS4= LOW;}
//  Serial.println("voltage4  ");
//  Serial.print(inval4);
    float inval5 = ((analogRead(in5)*3.3)/4095);
      if(inval5<2.5){PS5= HIGH;}
      if(inval5>=2.5){PS5= LOW;}
//  Serial.println("voltage5");
//  Serial.print(inval5);
  
  delay(30);

   if (bleKeyboard.isConnected()) {

    int val =0;
    
    //if the keyboard is connected to a device
    if (PS1==HIGH) {
    
      if (oldPinState1 == LOW) {

        val+=1;
      
      }
      oldPinState1 = HIGH;
    } else {
      oldPinState1 = LOW; 
    }
//   -------------------------
    if (PS2 == HIGH) 
    {
    
      if (oldPinState2 == LOW) 
      {
        val+=2;
      }
      oldPinState2 = HIGH;
    } 
    else 
    {
      oldPinState2 = LOW; 
    }

//   -------------------------

  if (PS3 == HIGH) 
    {
    
      if (oldPinState3 == LOW) 
      {
        val+=4;
      }
      oldPinState3 = HIGH;
    } 
    else 
    {
      oldPinState3 = LOW; 
    }

//    ------------------------------

if (PS4 == HIGH) 
    {
    
      if (oldPinState4 == LOW) 
      {
        val+=8;
      }
      oldPinState4 = HIGH;
    } 
    else 
    {
      oldPinState4 = LOW; 
    }
//    -----------------------------

    if (PS5 == HIGH) 
    {
    
      if (oldPinState5 == LOW) 
      {
        val+=16;
      }
      oldPinState5 = HIGH;
    } 
    else 
    {
      oldPinState5 = LOW; 
    }
if(val>0 && val<27) bleKeyboard.print(chars[val]);
if(val==28) bleKeyboard.print(' ');
  }
  delay(10);
}
