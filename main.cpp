#include <Arduino.h>
//"I Mouaiad Hejazi,001220081 certify that this material is my original work. No other person's work has been used without due acknowledgement. I have not made my work available to anyone else."


//declaring a variable called `lightStatus` and setting it to false.
bool lightStatus = false;
//declaring a variable called `lightPin` and setting it to false.
bool buttonPressed = false; //


/**
 * Configure the USB serial monitor, configure pin D5 as an analog input, configure pin D4 as a digital
 * output, and set the default PWM range
 */
void setup() {
  // configure the USB serial monitor
  Serial.begin(115200);
  // configure pin D5 as an analog input - this is the pushbutton
  pinMode(D5, INPUT_PULLUP);
  // configure pin D4 as a digital output - this is the LED
  pinMode(D4, OUTPUT);
  // set default PWM range
  analogWriteRange(1023);
}


/**
 * If the button is pressed, toggle the light status. If the light status is on, set the brightness of
 * the light to the value of the potentiometer. If the light status is off, set the brightness of the
 * light to full
 */
void loop() {
  
  /* This is checking if the button is pressed and if it is, it sets the buttonPressed variable to true
  and toggles the lightStatus variable. If the button is not pressed, it sets the buttonPressed
  variable to false. */
  if (buttonPressed == false && digitalRead(D5) == 0)
  {
    buttonPressed = true;//button pressed 
    lightStatus = !lightStatus; //toggle light status
  }
  else if (digitalRead(D5) == 1) { 
    buttonPressed = false;//button not pressed
  }
  

  /* This is checking if the lightStatus variable is true. If it is, it sets the brightness of the LED
  to the value of the potentiometer. If it is not, it sets the brightness of the LED to full. */
  if (lightStatus)
  {
    analogWrite(D4, analogRead(A0));//set brightness of LED to potentiometer value
  }
  else {
    analogWrite(D4, 1023);//set brightness of LED to full
  }
}