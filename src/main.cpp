#include <Arduino.h>
#include <SoftwareSerial.h>
#include "RadioChannel.h"

#define ITERATION_DELAY 1

#define nullZone 10
#define CH1_pin 2
#define CH1_min 100
#define CH1_max 190
#define CH1_neutral 150

String HANDSHAKE = "3000\n";
String HARD_STOP = "3003\n";
String SET_SPEED = "1000,";

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

int statusLedPin = 13;

const byte rxPin = 9;
const byte txPin = 10;
SoftwareSerial softwareDebug (rxPin, txPin);

#define FAIL 100
#define SUCCESS 200

void sendHandshakeToMCU() {
  String handshakeResponse = "";
  softwareDebug.println("Trying to connect to MCU");
  Serial.print("3000\n"); 
  while(Serial.available() == 0) {}
  handshakeResponse = Serial.readString();
  if(handshakeResponse != "5000\r\n") {
    softwareDebug.println("Failed to connect to MCU. Restart GCU.");
    while(true) {
      digitalWrite(statusLedPin, HIGH);
      delay(100);
      digitalWrite(statusLedPin, LOW);
      delay(100);
    }
  } else {
    softwareDebug.println("Successfully Connected to MCU!");
    digitalWrite(statusLedPin, HIGH);
    delay(500);
  }
}

void setupChannelPins() {
  
  pinMode(CH2_pin, INPUT);
  pinMode(CH3_pin, INPUT);
}

RadioChannel CH3 = RadioChannel(4);

void setup() {
  delay(1000);
  pinMode(statusLedPin, OUTPUT);
  digitalWrite(statusLedPin, LOW);
  Serial.begin(115200);
  Serial.setTimeout(1);
  softwareDebug.begin(115200);

  softwareDebug.println("Initializing GCU");
  sendHandshakeToMCU();
  CH3.setInputValues(100,190,10);
  CH3.setOutputValues(-500,500);

}

void loop() {
  CH3.process();
  Serial.print("1000,"); 
  Serial.print(CH3.getOutput()); Serial.print(",");
  Serial.print(CH3.getOutput()); Serial.print("\n");
  delay(ITERATION_DELAY);
}