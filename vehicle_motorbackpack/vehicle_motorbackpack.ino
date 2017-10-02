#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
#include <ESP8266WiFi.h>
#include <ESPectro.h>
#include <BlynkSimpleEsp8266.h>

#define DEFAULT_BLYNKSERVER_HOST "cloud.makestro.com"
#define DEFAULT_BLYNKSERVER_PORT 8442
#define BLYNK_PRINT Serial

char ssid[] = "DyWare-AP2";// fill with your ssid wifi
char pass[] = "957DaegCen";// fill with your password ssid wifi


char auth[] = "e280b831a3f94352b9d9cf488eb6e65c";// fill with your blynk auth token

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *myMotor2 = AFMS.getMotor(2);
Adafruit_DCMotor *myMotor1 = AFMS.getMotor(1);
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
 Blynk.begin(auth, ssid, pass);
 AFMS.begin(); 
 myMotor2->setSpeed(150);
 myMotor1->setSpeed(150);
 
 
}

void loop() {
  // put your main code here, to run repeatedly:
 Blynk.run();
}

  BLYNK_WRITE(V3){
  int value = param.asInt();
  Serial.printf("Got value from V3: %d\n", value);

  if (value==1) {
  myMotor2->run(BACKWARD);
  myMotor1->run(BACKWARD);
  digitalWrite(15, HIGH);
  }
  else if(value==0){
  digitalWrite(15, LOW);
  myMotor2->run(RELEASE);
  myMotor1->run(RELEASE);
  }
}


BLYNK_WRITE(V2){
  int value = param.asInt();
  Serial.printf("Got value from V2: %d\n", value);

  if (value==1) {
  myMotor2->run(FORWARD);
  myMotor1->run(FORWARD);
  digitalWrite(15, HIGH);
 
  }
  else if (value==0){
  digitalWrite(15, LOW);
  myMotor2->run(RELEASE);
  myMotor1->run(RELEASE);
  }
}

BLYNK_WRITE(V4){
  int value = param.asInt();
  Serial.printf("Got value from V4: %d\n", value);

  if (value==1) {
  myMotor2->setSpeed(150);
  myMotor2->run(FORWARD);
  digitalWrite(15, HIGH);
 
  }
  else if (value==0){
  digitalWrite(15, LOW);
  myMotor2->run(RELEASE);
  
  }
}

BLYNK_WRITE(V5){
  int value = param.asInt();
  Serial.printf("Got value from V5: %d\n", value);

  if (value==1) {
  myMotor1->setSpeed(150);
  myMotor1->run(FORWARD);
  digitalWrite(15, HIGH);
 
  }
  else if (value==0){
  digitalWrite(15, LOW);
  myMotor1->run(RELEASE);
  }
}