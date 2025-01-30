#include <Servo.h>

char val;
Servo servo;

void setup() {
  pinMode(13, OUTPUT);  // Set pin 13 as an output for the bulb
  pinMode(12, OUTPUT);  // Set pin 12 as an output for the fan
  pinMode(7, INPUT);    // Set pin 4 as an input for the PIR motion sensor
  
  Serial.begin(9600);   // Initialize serial communication
  
  digitalWrite(13, LOW);  // Turn off the bulb initially 
  digitalWrite(12, LOW);  // Turn off the fan initially
  
  servo.attach(8);  // Attach the servo motor to pin 5
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

  // Servo Motor and PIR Sensor
  if(digitalRead(7)==HIGH){
    servo.write(90);
    delay(1000);
  }
  else{
    servo.write(-200);
    }
  
  delay(100);  // Delay for stability
}
//https://cdn.shopify.com/s/files/1/0300/6424/6919/files/Circuit-Diagram-Home-Automation-using-Arduino-Uno.jpg?v=1692865152
//https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQtWDzVEGUFYE1N8TF96M-_84yDDCWrpum-iQ&s
//https://1.bp.blogspot.com/-DHqI1c7Bbio/X-y0JkcwwdI/AAAAAAAAMmo/Rf2N1J9lPsUs9gA8uyusnoveozHnIncjQCLcBGAsYHQ/s16000/automation.png
//https://www.youtube.com/watch?v=_eFW_4HKhys
