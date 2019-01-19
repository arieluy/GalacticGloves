#include <Wire.h> 
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h> 
#include <utility/imumaths.h>

Adafruit_BNO055 bno = Adafruit_BNO055(55); 

int btn0_val = 0; 
int btn1_val = 0; 
int btn2_val = 0; 
int btn3_val = 0;  
 
bool touch_timeout = false; 
int touch_timeout_start = 0;
int touch_timeout_length = 450; 

int btn0_in = A0; 
int btn1_in = A1;
int btn2_in = A2; 
int btn3_in = A3; 

int current_tilt = -1; 
bool update_tilt = false; 

int button = -1; 
bool update_button = false; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  /* Initialise the sensor */
  if(!bno.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }

  delay(1000);
  bno.setExtCrystalUse(true);

}

void handle_buttons() {
  int touch_value = 600; 
  btn0_val = analogRead(btn0_in); 
  btn1_val = analogRead(btn1_in);
  btn2_val = analogRead(btn2_in);
  btn3_val = analogRead(btn3_in);

   if(btn0_val <= touch_value) {
    if(button != 0) {
      update_button = true; 
      button = 0; 
    }
   }
   else if(btn1_val <= touch_value) {
      if(button != 1) {
        update_button = true; 
        button = 1; 
      }
   }
   else if(btn2_val <= touch_value) {
      if(button != 2) {
        update_button = true; 
        button = 2; 
      }
   }
   else if(btn3_val <= touch_value) {
      if(button !=3) {
        update_button = true; 
        button = 3; 
      }
   }  
   else {
    update_button = false; 
    button = -1; 
   }
  
}

void handle_position() {
  imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);  
  if(euler.z() < 40) {
    if(current_tilt != 1){
      update_tilt = true; 
      current_tilt = 1; 
    }
  }
  else if(euler.z() >= 40 && euler.z() < 140) {
    if(current_tilt != 2) {
      update_tilt = true; 
      current_tilt = 2; 
    }
  }
  else if(euler.z() >=140) {
    if(current_tilt != 3) {
      update_tilt = true; 
      current_tilt = 3; 
    }
  }
}


void loop() {
  // put your main code here, to run repeatedly:
  handle_buttons();  
  //btn0_val = analogRead(btn0_in); 
  //btn1_val = analogRead(btn1_in);
  //btn2_val = analogRead(btn2_in);
  //btn3_val = analogRead(btn3_in);

  //Serial.println(btn0_val); 
  //Serial.println(btn1_val); 
  //Serial.println(btn2_val); 
  //Serial.println(btn3_val); 

  if(update_button) {
    for(int i = 0; i < 15; i++){
      if(button == 0) Serial.print("a"); 
      else if(button == 1) Serial.print("s"); 
      else if(button == 2) Serial.print("d"); 
      else if(button == 3) Serial.print("f");
    }
    update_button = false; 
    button = -1; 
  }
  else {Serial.print("."); }

  /*
  handle_position(); 
  if(update_tilt) {
    for(int i = 0; i < 50; i++){
      if(current_tilt == 1) Serial.print("1"); 
      else if(current_tilt == 2) Serial.print("2"); 
      else if (current_tilt == 3) Serial.print("3"); 
      else Serial.print("0"); 
    }
    update_tilt = false; 
  }
  else {
    //Serial.println("a"); 
  }
  */
}
