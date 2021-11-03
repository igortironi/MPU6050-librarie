/*
 * Exemple code wrote By Igor Tironi.
 * 23/08/2018.
 * library version 1.0
*/
#include <MPU6050.h>

MPU6050 gyroscope;  //declaring object "gyroscope".

void setup() {
  gyroscope.begin();            //initializing the gyroscope.   //setting a 5Hz low pass filter.
  gyroscope.config_filter(6);
  gyroscope.config_gyro(3);     //setting a full 2000°/s scale.
  gyroscope.config_accel(3);    //setting a full 16g scale.
  gyroscope.convert_value(true);  //tuning on value convertion.
   
  Serial.begin(115200);         //initializing the serial communication;
}

void loop() {
  static int count = 0;
  //Serial.print("x_accel: ");            //from here we are acquiring the axes values and sending to the computer via serial communication.
  long timeri = micros();
  float x_value = gyroscope.x_accel();
  float z_value = gyroscope.z_accel();
  long timerf = micros();
  
  float teta = atan(x_value/z_value)*180/PI;

  if(count >= 100){Serial.println("ok");count = 0;}
  else if(teta <= 0) count++;
  else count = 0;
  
  
  //Serial.print(teta);
  //Serial.println("");
  //Serial.print(timerf - timeri);
  //Serial.println("");
  
}
//end;
