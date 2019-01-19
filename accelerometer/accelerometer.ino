#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
  
Adafruit_BNO055 bno = Adafruit_BNO055(55);
bool timeout = false;
int timeout_start  = 0; 
int timeout_time = 500;  
int pin1 = 12;
int pin2 = 13;
int outputx = 0;
int outputy = 0;



void setup(void) 
{
  Serial.begin(9600);
  Serial.println("Orientation Sensor Test"); Serial.println("");
  
  /* Initialise the sensor */
  if(!bno.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }
  
  delay(1000);
  bno.setExtCrystalUse(true);

  /* Set digital ouput pins */
  pinMode(outputx,OUTPUT);
  pinMode(outputy,OUTPUT);
}

void loop(void) 
{
  /* Get a new sensor event */ 
  /*sensors_event_t event; 
  bno.getEvent(&event);*/
  
  /* Display the floating point data */
  /*Serial.print("X: ");
  Serial.print(event.orientation.x, 4);
  Serial.print("\tY: ");
  Serial.print(event.orientation.y, 4);
  Serial.print("\tZ: ");
  Serial.print(event.orientation.z, 4);
  Serial.println("");*/
  imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
  imu::Vector<3> accel = bno.getVector(Adafruit_BNO055::VECTOR_LINEARACCEL); 
/* Display the floating point data */

Serial.print("X: ");
Serial.print(accel.x());
Serial.print(" Y: ");
Serial.print(accel.y());
Serial.print(" Z: ");
Serial.print(accel.z());
Serial.println("");

if(euler.z() < 40) {
  if(!timeout) {
    if(accel.y() > 2.5) {
       Serial.println("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Left hit");
       timeout = true;
       timeout_start = millis();   
    }
    else if(accel.y() < -2.5) {
       Serial.println(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Right hit"); 
       timeout = true;
       timeout_start = millis();  
    }
  }
  else {
    if(millis() - timeout_start > timeout_time){
      timeout = false; 
    }
    Serial.print("Timeout"); 
  }
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, HIGH);
  Serial.println("up\n"); 
}
else if(euler.z() > 40 && euler.z() < 140) {
  if(!timeout) {
    if(accel.z() > 2.5) {
       Serial.println("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Left hit");
       timeout = true;
       timeout_start = millis();   
    }
    else if(accel.z() < -2.5) {
       Serial.println(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Right hit"); 
       timeout = true;
       timeout_start = millis();  
    }
  }
  else {
    if(millis() - timeout_start > timeout_time){
      timeout = false; 
    }
    Serial.print("Timeout"); 
  }
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
  Serial.println("side\n"); 
}
else if(euler.z() >= 140) {
  if(!timeout) {
    if(accel.z() > 2.5) {
       Serial.println("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Left hit");
       timeout = true;
       timeout_start = millis();   
    }
    else if(accel.z() < -2.5) {
       Serial.println(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Right hit"); 
       timeout = true;
       timeout_start = millis();  
    }
  }
  else {
    if(millis() - timeout_start > timeout_time){
      timeout = false; 
    }
    Serial.print("Timeout"); 
  }
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, LOW);
  Serial.println("down\n");
}
else Serial.println("???");
 
  //Serial.print("Accel: ");
  //Serial.print(sqrt(sq(accel.x()) + sq(accel.y()) + sq(accel.z())));
  //Serial.print("other: ");  
  //Serial.print(accel.z()); 
  //Serial.println(); 
  /*if(!timeout) {
    if(accel.y() > 2.5) {
       Serial.println("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Left hit");
       timeout = true;
       timeout_start = millis();   
    }
    else if(accel.y() < -2.5) {
       Serial.println(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Right hit"); 
       timeout = true;
       timeout_start = millis();  
    }
  }
  else {
    if(millis() - timeout_start > timeout_time){
      timeout = false; 
    }
    Serial.print("Timeout"); 
  }*/
  
  
  delay(100);
}
