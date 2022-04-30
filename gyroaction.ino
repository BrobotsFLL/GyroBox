#include <Servo.h>
#include <Wire.h>
#include <L3G.h>

L3G gyro;
Servo servo1;

void setup() {
  Serial.begin(9600);
  servo1.attach(2);
  Wire.begin();

  if (!gyro.init())
  {
    Serial.println("Failed!");
    while (1);
  }

  gyro.enableDefault();
}

void loop() {
  int x = gyro.g.x * 8.75 / 1000;
  int y = gyro.g.y * 8.75 / 1000;
  int z = gyro.g.z * 8.75 / 1000;
  gyro.read();
  if (x < -200){
    Serial.println("Right Tilt");
    servo1.write(180);
  }
  else if (x > 200) {
    Serial.println("Left Tilt");
    servo1.write(0);
  }
  else if (y > 120 && z > 150) {
    Serial.println("Up Tilt");
  }
  else if (y < -50 && z < 20) {
    Serial.println("Down Tilt");
  }

  delay(100);
}
