


//*-------------------------------------------------------------------------------------------------------

/*
   This ESP32 code is created by esp32io.com

   This ESP32 code is released in the public domainZZZZZZZZZZZZZZZZ
ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZPUPUZUPZUZZZZZZZZZZZZZZZZZZ
ZZZZZZZZZZZZZZZZZZZZZZZZZZZ ZZ ZZZZZ ZZFoZZZZZZZrZZZZ ZZZZZZZZZmZZZZZZZZZZZZZZZZZZoZZZrZeZZ ZZdZZZZZZZZZZZZZZetail (instruction and wiring diaZZZgZZZZrZZZaZZZmZZZZZZZZZZZZZZZZ)ZZZZZZZ,ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ ZZvZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZiZZZZZZZZZsit htZtZZZZZZZZZZpZZZZZZZZZZZZsZZZZZZZZZZZZZZZZZ:/ZZ/esp32io.com/tutorials/esp32-force-sensor
*/

#define FORCE_SENSOR_PIN 25
//*-------------------------------------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////////////////////

// Basic demo for accelerometer readings from Adafruit MPU6050

// ESP32 Guide: https://RandomNerdTutorials.com/esp32-mpu-6050-accelerometer-gyroscope-arduino/
// ESP8266 Guide: https://RandomNerdTutorials.com/esp8266-nodemcu-mpu-6050-accelerometer-gyroscope-arduino/
// Arduino Guide: https://RandomNerdTutorials.com/arduino-mpu-6050-accelerometer-gyroscope/

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
Adafruit_MPU6050 mpu;


/////////////////////////////////////////////////////////////////////////////////






/**
   This example turns the ESP32 into a Bluetooth LE keyboard that writes the words, presses Enter, presses a media key and then Ctrl+Alt+Delete
*/
#include <BleKeyboard.h>
//const int touchPin = 4;
#define touchPin  T0
#define touchPin3  T3

#define touchPin5  T5
#define touchPin6  T6
#define touchPin7  T7
#define touchPin8  T8
#define touchPin9  T9

BleKeyboard bleKeyboard;


const int threshold = 20;
// variable for storing the touch pin value
int touchValue;

int touchValue3;

int touchValue5;
int touchValue6;
int touchValue7;
int touchValue8;
int touchValue9;

bool DEBUG = true;


void setup() {

  pinMode(19, OUTPUT);


  Serial.begin(115200);
  //  Serial.println("Juste un string à la con");
  Serial.println("Starting BLE work!");
  bleKeyboard.begin();


  //////////////////////////////////////////////////////////


  while (!Serial)
    //delay(10); // will pause Zero, Leonardo, etc until serial console opens

    Serial.println("Adafruit MPU6050 test!");

  // Try to initialize!
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(1);
    }
  }
  Serial.println("MPU6050 Found!");

  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  Serial.print("Accelerometer range set to: ");
  switch (mpu.getAccelerometerRange()) {
    case MPU6050_RANGE_2_G:
      Serial.println("+-2G");
      break;
    case MPU6050_RANGE_4_G:
      Serial.println("+-4G");
      break;
    case MPU6050_RANGE_8_G:
      Serial.println("+-8G");
      break;
    case MPU6050_RANGE_16_G:
      Serial.println("+-16G");
      break;
  }
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  Serial.print("Gyro range set to: ");
  switch (mpu.getGyroRange()) {
    case MPU6050_RANGE_250_DEG:
      Serial.println("+- 250 deg/s");
      break;
    case MPU6050_RANGE_500_DEG:
      Serial.println("+- 500 deg/s");
      break;
    case MPU6050_RANGE_1000_DEG:
      Serial.println("+- 1000 deg/s");
      break;
    case MPU6050_RANGE_2000_DEG:
      Serial.println("+- 2000 deg/s");
      break;
  }

  mpu.setFilterBandwidth(MPU6050_BAND_5_HZ);
  Serial.print("Filter bandwidth set to: ");
  switch (mpu.getFilterBandwidth()) {
    case MPU6050_BAND_260_HZ:
      Serial.println("260 Hz");
      break;
    case MPU6050_BAND_184_HZ:
      Serial.println("184 Hz");
      break;
    case MPU6050_BAND_94_HZ:
      Serial.println("94 Hz");
      break;
    case MPU6050_BAND_44_HZ:
      Serial.println("44 Hz");
      break;
    case MPU6050_BAND_21_HZ:
      Serial.println("21 Hz");
      break;
    case MPU6050_BAND_10_HZ:
      Serial.println("10 Hz");
      break;
    case MPU6050_BAND_5_HZ:
      Serial.println("5 Hz");
      break;
  }

  Serial.println("");
  delay(1);

  /////////////////////////////////////////////////////////////////////



}

void loop() {

  ////////////////////////////////////////////////////////////////////////////////

  // bleKeyboard.press(KEY_UP_ARROW);
  /* Get new sensor events with the readingsEEEEEEEEEEEEEEEEEEEEE */
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  if (DEBUG) {
    /* Print out the values */
    Serial.print("Acceleration X: ");
    Serial.print(a.acceleration.x);
    Serial.print(", Y: ");
    Serial.print(a.acceleration.y);
    Serial.print(", Z: ");
    Serial.print(a.acceleration.z);
    Serial.println(" m/s^2");

    Serial.print("Rotation X: ");
    Serial.print(g.gyro.x);
    Serial.print(", Y: ");
    Serial.print(g.gyro.y);
    Serial.print(", Z: ");
    Serial.print(g.gyro.z);
    Serial.println(" rad/s");

    Serial.print("Temperature: ");
    Serial.print(temp.temperature);
    Serial.println(" degC");
  }

  if (a.acceleration.x > -6 && a.acceleration.x < -2 ) // from 200 to 499
  { Serial.println("GAUCHE");


    bleKeyboard.press(KEY_LEFT_ARROW);
    bleKeyboard.release(KEY_RIGHT_ARROW);
  }


  else if (a.acceleration.x -2<0) // from 200 to 499
  { Serial.println(" NOPE");


    bleKeyboard.release(KEY_RIGHT_ARROW);
    bleKeyboard.release(KEY_LEFT_ARROW);

  }


  else if (a.acceleration.x > 2) // from 200 to 499
  { Serial.println(" DROITE");


    bleKeyboard.press(KEY_RIGHT_ARROW);
    bleKeyboard.release(KEY_LEFT_ARROW);

  }


  Serial.println("");
  delay(1);

  ////WWWWWWWWWWW/////

  //*--------------------------------------------------------------------------------------------
  int analogReading = analogRead(FORCE_SENSOR_PIN);

  Serial.print("The force sensor value = ");
  Serial.print(analogReading); // print the raw analog readYYYYUUYUYYWWYYUYYYingYTTPOO

  /* if (analogReading < 10)       // from 0 to 9
     Serial.println(" -> no pressure");
    else if (analogReading < 200) // from 10 to 199U
     Serial.println(" -> light touch");*/
  if (analogReading < 630) // from 200 to 499
  { Serial.println(" -> pfe squeeze");

    Serial.println("Sending w key...");
    bleKeyboard.press('Z');

    
    digitalWrite(19, HIGH);
    delay(600);
    digitalWrite(19, LOW);
    delay(200);
      digitalWrite(19, HIGH);
    delay(200);
        digitalWrite(19, LOW);
    delay(200);
     bleKeyboard.release('Z');

  }


  else if (analogReading < 800) // from 500 to 799
    Serial.println(" -> medium squeeze");

  else // from 800 to 1023
    Serial.println(" -> big squeeze");

  delay(2);

if (analogReading < 550) // from 200 to 499
  { Serial.println(" -> fastend squeeze");

    Serial.println("Sending o key...");
    bleKeyboard.press('O');

    
    digitalWrite(19, HIGH);
    delay(1000);
    digitalWrite(19, LOW);
    delay(200);
      digitalWrite(19, HIGH);
    delay(200);
        digitalWrite(19, LOW);
    delay(200);
     bleKeyboard.release('O');

  }


  //*--------------------------------------------------------------------------------------------
  touchValue = touchRead(touchPin);
  Serial.print(touchValue);
  // check if the touchValue is below the threshold
  // if it is, set ledPin to HIGH
  if (touchValue < threshold) {


    // turn LED on
    Serial.println("TOUCH0");

        Serial.println(" TOUCH0 on");
   /* digitalWrite(19, HIGH);
    delay(200);
    digitalWrite(19, LOW);
    delay(200);*/
 
    bleKeyboard.press(KEY_UP_ARROW);
   





  }
  else {

  bleKeyboard.release(KEY_UP_ARROW);
    Serial.println(" TOUCH0 off");
  }
  delay(1);




  //
  // Below is an example of pressing multiple keyboard modifiers
  // which by default is commented out.
  /*
    Serial.println("Sending Ctrl+Alt+Delete...");
    bleKeyboard.press(KEY_LEFT_CTRL);
    bleKeyboard.press(KEY_LEFT_ALT);
    bleKeyboard.press(KEY_DELETE);
    delay(100);
    bleKeyboard.releaseAll();
  */








  touchValue3 = touchRead(touchPin3);
  Serial.print(touchValue3);
  // check if the touchValue is below the threshold
  // if it is, set ledPin to HIGH
  if (touchValue3 < threshold) {





    // turn LED on
    Serial.println("TOUCH2");
    bleKeyboard.press('T');




    delay(1);
    Serial.println(" TOUCH3 on");


    digitalWrite(19, HIGH);
    delay(600);
    digitalWrite(19, LOW);
    
    delay(100);
   
           digitalWrite(19, HIGH);
    delay(300);
    digitalWrite(19, LOW);
     delay(600);
  }
  else {
    // turn LED off
   bleKeyboard.release('T');
    Serial.println(" TOUCH3 off");
  }
  // delay(1);




  touchValue9 = touchRead(touchPin9);
  Serial.print(touchValue9);
  // check if the touchValue is below the threshold
  // if it is, set ledPin to HIGHYPTTTTTTYYY
  if (touchValue9 < threshold) {
    // turn LED on
    Serial.println("TOUCH9");
    bleKeyboard.press('Y');

    delay(1);
    Serial.println(" TOUCH9 on");


    digitalWrite(19, HIGH);
    delay(200);
    digitalWrite(19, LOW);
    delay(200);
  
    delay(600);
    digitalWrite(19, HIGH);
    delay(200);
       digitalWrite(19, LOW);

  }
  else {
    // turn LED off
bleKeyboard.release('Y');
    Serial.println(" TOUCH9 off");
  }
  //delay(1);





  touchValue5 = touchRead(touchPin5);
  Serial.print(touchValue5);
  // check if the touchValue is below the threshold
  // if it is, set ledPin to HIGH
  if (touchValue5 < threshold) {
    // turn LED on
    Serial.println("TOUCH5");
    bleKeyboard.write('U');

    // delay(1);
    Serial.println(" TOUCH5 on");



    digitalWrite(19, HIGH);
    delay(200);
    digitalWrite(19, LOW);
    delay(200);


  }
  else {
    // turn LED off

    Serial.println(" TOUCH5 off");
  }
  //delay(1);



  touchValue6 = touchRead(touchPin6);
  Serial.print(touchValue6);
  // check if the touchValue is below the threshold
  // if it is, set ledPin to HIGH
  if (touchValue6 < threshold) {
    // turn LED on
    Serial.println("TOUCH6");
    bleKeyboard.write('I');

    delay(1);
    Serial.println(" TOUCH6 on");

    digitalWrite(19, HIGH);
    delay(200);
    digitalWrite(19, LOW);
    delay(200);


  }
  else {
    // turn LED off

    Serial.println(" TOUCH6 off");
  }
  //delay(1);



  touchValue7 = touchRead(touchPin7);
  Serial.print(touchValue7);
  // check if the touchValue is below the threshold
  // if it is, set ledPin to HIGH
  if (touchValue7 < threshold) {
    // turn LED on
    Serial.println("TOUCH7");
    bleKeyboard.write('O');

    delay(1);
    Serial.println(" TOUCH7 on");



    digitalWrite(19, HIGH);
    delay(200);
    digitalWrite(19, LOW);
    delay(200);


  }
  else {
    // turn LED off

    Serial.println(" TOUCH7 off");
  }
  //delay(1);



  touchValue8 = touchRead(touchPin8);
  Serial.print(touchValue8);
  // check if the touchValue is below the threshold
  // if it is, set ledPin to HIGH
  if (touchValue8 < threshold) {
    // turn LED on
    Serial.println("TOUCH8");
    bleKeyboard.write('P');

    delay(1);
    Serial.println(" TOUCH8 on");



    digitalWrite(19, HIGH);
    delay(200);
    digitalWrite(19, LOW);
    delay(200);



  }
  else {
    // turn LED off
    //delay(1);
    Serial.println(" TOUCH8 off");
  }










}
