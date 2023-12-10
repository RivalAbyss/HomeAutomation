#include <Servo.h>

char val;
Servo servo;

void setup() {
  pinMode(13, OUTPUT);  // Set pin 13 as an output for the bulb
  pinMode(12, OUTPUT);  // Set pin 12 as an output for the fan
  pinMode(7, INPUT);    // Set pin 4 as an input for the PIR motion sensor
  // pinMode(5, OUTPUT);   // Set pin 5 as an output for the first servo motor
  Serial.begin(9600);   // Initialize serial communication
  digitalWrite(13, LOW);  // Turn off the bulb initially
  digitalWrite(12, LOW);  // Turn off the fan initially
  
  servo.attach(8);  // Attach the first servo motor to pin 5
}

void loop() {
  if (Serial.available()) {
    val = Serial.read();  // Read the incoming character from Bluetooth
    Serial.println(val);  // Print the received character to the Serial Monitor
  }

  if (val == '1') {
    digitalWrite(13, LOW);  // Turn on the bulb if '1' is received
  } else if (val == '2') {
    digitalWrite(13, HIGH);  // Turn off the bulb if '2' is received
  } else if (val == '3') {
    digitalWrite(12, LOW);  // Turn on the fan if '3' is received
  } else if (val == '4') {
    digitalWrite(12, HIGH);  // Turn off the fan if '4' is received
  }

  if (digitalRead(7) ==1) {      
    // Check if motion is detected
    servo.write(90);          // Move the servo to a position (90 degrees) representing motion
    delay(1000);                // Wait for servo movement (adjust delay as needed)
    servo.write(0);           // Move the servo to another position (0 degrees) representing no motion
    delay(1000);                // Wait for servo movement (adjust delay as needed)
    servo.detach();
  } 
  else {
    // servo.attach(5);
    servo.write(90);          // Move the servo to a position (90 degrees) representing motion
    delay(1000);                // Wait for servo movement (adjust delay as needed)
    servo.write(0);           // Move the servo to another position (0 degrees) representing no motion
    delay(1000);                // Wait for servo movement (adjust delay as needed)
    servo.detach();
  } 
  // if (digitalRead(4) == HIGH) {
  //   // Motion detected, move the servo
  //   servo.write(90);  // Adjust the angle as needed
  //   delay(1000);      // Wait for servo movement
  //   servo.write(0);   // Reset servo position
  //   delay(1000);
  //   servo.detach();   // Detach the servo to save power (optional)
  //   }

  delay(100);  // Delay for stability
}

// void sm() {
  // if (digitalRead(4) == HIGH) {      
  //   // Check if motion is detected
  //   servo.write(90);          // Move the servo to a position (90 degrees) representing motion
  //   delay(1000);                // Wait for servo movement (adjust delay as needed)
  //   servo.write(0);           // Move the servo to another position (0 degrees) representing no motion
  //   delay(1000);                // Wait for servo movement (adjust delay as needed)
  //   servo.detach();
  // } else {
  //   servo.attach(5);
  // }
  // PIR motion detection 
//   int pirsensor = digitalRead(2);
//   Serial.println(pirsensor);
//   if (pirsensor == 1) 
//   {
//     digitalWrite(13, HIGH);  
//     digitalWrite(4, HIGH);
//   }
//   else
//   {
//     digitalWrite(13,LOW);
//     digitalWrite(4, LOW);
//   }
//   delay(10);
// }
  // if (digitalRead(8) == HIGH) {
  //   // Motion detected, move the servo
  //   servo.write(90);  // Adjust the angle as needed
  //   delay(3000);      // Wait for servo movement
  //   servo.write(-90);   // Reset servo position
  //   delay(1000);
  // int x = digitalRead(4);
  // Serial.println(x);
  // if(x==HIGH){
  //   servo.write(180);
  //   delay(3000);
  // }
  //  else{   
  //   servo.write(-200);
  // } 
// }
