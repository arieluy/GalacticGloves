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

int btn0_out = 2; 
int btn1_out = 3; 
int btn2_out = 4; 
int btn3_out = 5; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
}

void handle_buttons() {
  int touch_value = 800; 
  btn0_val = analogRead(btn0_in); 
  btn1_val = analogRead(btn1_in);
  btn2_val = analogRead(btn2_in);
  btn3_val = analogRead(btn3_in);

  //Serial.println(btn0_val); 
  //BUTTON 0
  if(!touch_timeout) {
   if(btn0_val <= touch_value) {
      Serial.println("================= touch0"); 
      touch_timeout = true; 
      touch_timeout_start = millis();
      digitalWrite(btn0_out, HIGH);  
    }
    else if(btn1_val <= touch_value) {
      Serial.println("================= touch1"); 
      touch_timeout = true; 
      touch_timeout_start = millis();
      digitalWrite(btn1_out, HIGH);  
    }
    else if(btn2_val <= touch_value) {
      Serial.println("================= touch2"); 
      touch_timeout = true; 
      touch_timeout_start = millis();
      digitalWrite(btn2_out, HIGH);  
    }
    else if(btn3_val <= touch_value) {
      Serial.println("================= touch3"); 
      touch_timeout = true; 
      touch_timeout_start = millis();
      digitalWrite(btn3_out, HIGH);  
    }  
  }
  else {
    if(millis() - touch_timeout_start >= touch_timeout_length) {
      touch_timeout = false;
    }
  }
  
}

void loop() {
  // put your main code here, to run repeatedly:
  handle_buttons(); 

}
