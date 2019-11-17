//#include <ir_Lego_PF_BitStreamEncoder.h>
//#include <boarddefs.h>
//#include <IRremoteInt.h>
//#include <IRremote.h>

#include <Adafruit_MotorShield.h>
Adafruit_MotorShield AFMS = Adafruit_MotorShield();

// The DC motor connected to M1
Adafruit_DCMotor *leftMotor = AFMS.getMotor(1);

// The DC motor connected to M2
Adafruit_DCMotor *rightMotor = AFMS.getMotor(2);

const int RECV_PIN = 4;
//IRrecv irrecv (RECV_PIN);
//decode_results results;

void setup() {

  Serial.begin(19200);
  AFMS.begin();
  leftMotor->setSpeed(150);
  rightMotor->setSpeed(150);
  
  Serial.println("Startup");
 // irrecv.enableIRIn(); // Start the receiver
}

void forward() {
  Serial.print("Moving forward...");
  leftMotor->run(FORWARD);
  rightMotor->run(FORWARD);
  delay(1000);
  leftMotor->run(RELEASE);
  rightMotor->run(RELEASE);
  Serial.println("Stopped");
}

void backward() {
  Serial.print("Moving forward...");
  leftMotor->run(BACKWARD);
  rightMotor->run(BACKWARD);
  delay(1000);
  leftMotor->run(RELEASE);
  rightMotor->run(RELEASE);
  Serial.println("Stopped");
}

void loop() {

  char c = Serial.read();

  if (c == 'f') {
    forward();
  }

  if (c == 'b') {
    backward();
  }
  //if (irrecv.decode(&results)){
    // Serial.println(results.value, HEX);
     //switch (results.decode_type){
     // case SAMSUNG:
    // Serial.println ("SAMSUNG");
    // break;
   // }
  //irrecv.resume(); // Receive the next value
   // }
}

