#include <Adafruit_NeoPixel.h>

//Constants
#define TRANSMITTER_PIN 2 //Transmitter

#define LIGHT_PIN_01 7 //Tail
#define LIGHT_PIN_02 8 //Center
#define LIGHT_PIN_03 9 //Front

#define ARRAY_SIZE 3 //Array size

//Variables
double channel_value;

Adafruit_NeoPixel neopixels[ARRAY_SIZE] = {Adafruit_NeoPixel(1, LIGHT_PIN_01, NEO_GRB + NEO_KHZ800), Adafruit_NeoPixel(1, LIGHT_PIN_02, NEO_GRB + NEO_KHZ800), Adafruit_NeoPixel(1, LIGHT_PIN_03, NEO_GRB + NEO_KHZ800)};

void setup() {
  //Setup serial
  Serial.begin(9600);
  Serial.println("============================================================\n ______       ___  ___   _______  _______  _______  _______ \n|      |     |   ||   | |       ||       ||       ||  _    |\n|  _    |    |   ||   | |    ___||   ____||   ____|| | |   |\n| | |   |    |   ||   | |   |___ |  |____ |  |____ | | |   |\n| |_|   | ___|   ||   | |    ___||_____  ||_____  || |_|   |\n|       ||       ||   | |   |     _____| | _____| ||       |\n|______| |_______||___| |___|    |_______||_______||_______|\n ___      ___  _______  __   __  _______  _______           \n|   |    |   ||       ||  | |  ||       ||       |          \n|   |    |   ||    ___||  |_|  ||_     _||  _____|          \n|   |    |   ||   | __ |       |  |   |  | |_____           \n|   |___ |   ||   ||  ||       |  |   |  |_____  |          \n|       ||   ||   |_| ||   _   |  |   |   _____| |          \n|_______||___||_______||__| |__|  |___|  |_______|          \n\n============================================================\n");

  //Initialize transmitter
  pinMode(TRANSMITTER_PIN, INPUT);
  Serial.println("Transmitter has been initialized");
  Serial.println("");
  
  //Initialize NeoPixels
  for(int i = 0; i < ARRAY_SIZE; i++){
    neopixels[i].begin();
    neopixels[i].show();
    Serial.print("NeoPixel nr. ");
    Serial.print(i);
    Serial.println(" has been initialized");
  }
  Serial.println("");
  SetModeOff();
}

void loop() {
  channel_value = pulseIn(2, HIGH);
  if(channel_value < 1250){
    SetModeOff();
  } else if(channel_value > 1250 && channel_value < 1750){
    SetModePosHold();
  } else if(channel_value > 1750){
    SetModeRTL();
  }
}

void ShowAll() {
  for(int i = 0; i < ARRAY_SIZE; i++){
    neopixels[i].show();
  }
  channel_value = pulseIn(2, HIGH);
}

void SetModeOff(){
  Serial.println("Lights are OFF");
  while(channel_value < 1250){
    for(int i = 0; i < ARRAY_SIZE; i++){
        neopixels[i].setPixelColor(0, 0, 0, 0);
    }
    ShowAll();
  }
}

void SetModePosHold(){
  Serial.println("Mode 2 is selected");
  neopixels[0].setPixelColor(0, 0, 255, 0);
  neopixels[1].setPixelColor(0, 0, 0, 0);
  neopixels[2].setPixelColor(0, 255, 0, 0);
  ShowAll();
  while(channel_value > 1250 && channel_value < 1750){
    delay(1000);
    neopixels[1].setPixelColor(0, 255, 255, 255);
    ShowAll();
    delay(50);
    neopixels[1].setPixelColor(0, 0, 0, 0);
    ShowAll();
    delay(100);
    neopixels[1].setPixelColor(0, 255, 255, 255);
    ShowAll();
    delay(50);
    neopixels[1].setPixelColor(0, 0, 0, 0);
    ShowAll();
  }
}

void SetModeRTL(){
  Serial.println("Mode RTL is selected");
  for(int i = 0; i < ARRAY_SIZE; i++){
      neopixels[i].setPixelColor(0, 0, 0, 0);
  }
  ShowAll();
  while(channel_value > 1750){
    delay(1000);
    for(int i = 0; i < ARRAY_SIZE; i++){
      neopixels[i].setPixelColor(0, 255, 0, 0);
    }
    ShowAll();
    delay(50);
    for(int i = 0; i < ARRAY_SIZE; i++){
      neopixels[i].setPixelColor(0, 0, 0, 0);
    }
    ShowAll();
    delay(100);
    for(int i = 0; i < ARRAY_SIZE; i++){
      neopixels[i].setPixelColor(0, 255, 0, 0);
    }
    ShowAll();
    delay(50);
    for(int i = 0; i < ARRAY_SIZE; i++){
      neopixels[i].setPixelColor(0, 0, 0, 0);
    }
    ShowAll();
  }
}

