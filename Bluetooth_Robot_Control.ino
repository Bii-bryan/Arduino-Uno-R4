void setup() {
  // put your setup code here, to run once:

}#include <AFMotor.h>

// create motor objects
AF_DCMotor motor1(1); // left motor
AF_DCMotor motor2(2); // right motor

// define bluetooth serial port
#define BTSerial Serial

void setup() {
  // set motors speed to 200
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  
  // initialize bluetooth serial port at 9600 baud rate
  BTSerial.begin(9600);
}

void loop() {
  // check if there is data available from bluetooth module
  if (BTSerial.available()) {
    // read the incoming byte
    char data = BTSerial.read();
    
    // execute commands based on data value
    switch (data) {
      case 'F': // move forward
        motor1.run(FORWARD);
        motor2.run(FORWARD);
        break;
      case 'B': // move backward
        motor1.run(BACKWARD);
        motor2.run(BACKWARD);
        break;
      case 'L': // turn left
        motor1.run(BACKWARD);
        motor2.run(FORWARD);
        break;
      case 'R': // turn right
        motor1.run(FORWARD);
        motor2.run(BACKWARD);
        break;
      case 'S': // stop
        motor1.run(RELEASE);
        motor2.run(RELEASE);
        break;
      default: // do nothing
        break;
    }
  }
}


void loop() {
  // put your main code here, to run repeatedly:

}
