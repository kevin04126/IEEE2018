
Skip to content
This repository

    Pull requests
    Issues
    Marketplace
    Explore

    @OrangeHoopla

11
1

    3

ufieeehw/IEEE2018
Code
Issues 2
Pull requests 0
Projects 0
Wiki
Insights
Settings
IEEE2018/arduino/IMU
8850341 8 minutes ago
@grimmonkey52 grimmonkey52 Update IMU
69 lines (56 sloc) 1.59 KB
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
#include <math.h>

 
/* This driver reads raw data from the BNO055
   Connections
   ===========
   Connect SCL to analog 5
   Connect SDA to analog 4
   Connect VDD to 3.3V DC
   Connect GROUND to common ground
   History
   =======
   2015/MAR/03  - First release (KTOWN)
*/

/* Set the delay between fresh samples. Wait for serial input to define sample rate. */


Adafruit_BNO055 bno = Adafruit_BNO055();

/*
void setup(void){
   while(!Serial.available()){
      #define BNO055_SAMPLERATE_DELAY_MS (Serial.read())
   }
  //remove the above serial read after testing and timing diagram is established.
  Serial.begin(9600);

  /* Initialise the sensor */
  if(!bno.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.println("ConnectionFail");
    while(1);
  }


  bno.setExtCrystalUse(false);

  Serial.println("Calibration status values: 0=uncalibrated, 3=fully calibrated");

}
void loop(){
  Serial.println(IMU_data());
}
*/

String IMU_data()
{
 String data;
 double angle;
  // Possible vector values can be:
  // - VECTOR_ACCELEROMETER - m/s^2
  // - VECTOR_MAGNETOMETER  - uT
  // - VECTOR_GYROSCOPE     - rad/s
  // - VECTOR_EULER         - degrees
  // - VECTOR_LINEARACCEL   - m/s^2
  // - VECTOR_GRAVITY       - m/s^2
  imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
  angle = atan2(euler.y(),euler.x())
  /* Display the floating point data */
  data = "angle[ " + String(angle) + "] z[ " + String(euler.z() + "]");
  return data;
}

    © 2018 GitHub, Inc.
    Terms
    Privacy
    Security
    Status
    Help

    Contact GitHub
    API
    Training
    Shop
    Blog
    About

Press h to open a hovercard with more details.

