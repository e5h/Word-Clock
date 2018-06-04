#include <Adafruit_NeoPixel.h>
#include <Wire.h>
#include "RTClib.h"

//Preliminary definitions.
#define PIN 6
#define LENGTH 100
#define BUTTON_DELAY 50
#define HOLD_DELAY 1000
#define RAINBOW_DELAY 150
RTC_DS3231 rtc;

//Initialize the LED grid.
Adafruit_NeoPixel grid = Adafruit_NeoPixel(LENGTH, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  Wire.begin();
  grid.begin();
  grid.show();
  //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  //rtc.adjust(DateTime(2017, 7, 30, 7, 35, 0)); //manual adjustment

  pinMode(8, INPUT);
  pinMode(9, INPUT);
}

void loop() {
  static byte state = 0; // Keeps track of the current clock state.

  wipe();
  switch(state){
    case 0: // Regular clock display
      display_time(grid.Color(0, 255, 255), grid.Color(0, 255, 0));
      display_bday();
      check_buttons(&state);
      break;
    case 1: // Second menu state
      S(grid.Color(255, 0, 0));
      check_buttons(&state);
      break;
    case 2: // Minute menu state
      M(grid.Color(255, 0, 0));
      check_buttons(&state);
      break;
    case 3: // Hour menu state
      H(grid.Color(255, 0, 0));
      check_buttons(&state);
      break;
    case 4: // Numerical time display
      display_ms(grid.Color(255, 255, 255), rainbow());
      break;
    case 11: // Clock edit - seconds
      display_ms(grid.Color(255, 255, 255), flash_color(grid.Color(255, 255, 255), grid.Color(255, 0, 0), 100));
      check_buttons(&state);
      break;
    case 12: // Clock edit - minutes
      display_ms(flash_color(grid.Color(255, 255, 255), grid.Color(255, 0, 0), 100), grid.Color(255, 255, 255));
      check_buttons(&state);
      break;
    case 13: // Clock edit - hours
      display_hm(flash_color(grid.Color(255, 255, 255), grid.Color(255, 0, 0), 100), grid.Color(255, 255, 255));
      check_buttons(&state);
      break;
      
  }
  grid.show();
}
