#include <Arduino.h>

#define nullZone 10

#define CH1_pin 2
#define CH1_min 100
#define CH1_max 190
#define CH1_neutral 150

unsigned long CH1_measure;
unsigned long CH1_output;

#define CH2_pin 3
#define CH2_min 100
#define CH2_max 190
unsigned long CH2_measure;
unsigned long CH2_output;

#define CH3_pin 4
#define CH3_min 100
#define CH3_max 190
unsigned long CH3_measure;
unsigned long CH3_output;


void setup() {
  Serial.begin(115200);
  pinMode(CH1_pin, INPUT);
  pinMode(CH2_pin, INPUT);
  pinMode(CH3_pin, INPUT);
}

void loop() {
  CH1_measure = 0;
  CH2_measure = 0;
  CH3_measure = 0;
   
  CH1_measure = (pulseIn (CH1_pin, HIGH, 100000))/10;
  //Serial.print(CH1_measure);
  //Serial.print(", ");
  CH1_measure = map(CH1_measure, CH1_min, CH1_max, 0, 100);
  Serial.print(100+CH1_measure);
  Serial.print(", ");
  CH1_output = (CH3_measure*CH1_measure)/100;
  
  CH2_measure = (pulseIn (CH2_pin, HIGH, 100000))/10;
  //Serial.print(CH2_measure);
  //Serial.print(", ");
  CH2_measure = map(CH2_measure, CH2_min, CH2_max, 0, 100);
  Serial.print(200+CH2_measure);
  Serial.print(", ");
  CH2_output = (CH3_measure*CH2_measure)/100;

  CH3_measure = (pulseIn (CH3_pin, HIGH, 100000))/10;
  //Serial.print(CH3_measure);
  //Serial.print(", ");
  CH3_measure = map(CH3_measure, CH3_min, CH3_max, 0, 100);
  Serial.print(300+CH3_measure);
  Serial.print("\n");
  CH3_output = CH3_measure;

}