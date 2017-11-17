#include <Adafruit_NeoPixel.h>
#include <Wire.h>
#include "RTClib.h"

/* -------------------9-
 * --n---n---n---n---n--
 *  I T U I S H A P P Y
 *  T W E N T Y H A L F
 *  K B D A Y H F I V E
 *  T E N Q U A R T E R
 *  T O P A S T P A P A
 *  E T E N S E V E N T
 *  I Y F I V E S I X H
 *  G R A N N Y F O U R
 *  H E L E V E N O N E
 *  T W E L V E T W O E
 * ----u---u---u---u----
 * 99-----------------0-
 */

//Preliminary definitions.
#define PIN 6
#define LENGTH 100
RTC_DS1307 rtc;

//Initialize the LED grid.
Adafruit_NeoPixel grid = Adafruit_NeoPixel(LENGTH, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Wire.begin();  
  grid.begin();
  grid.show();
}

void loop() {
  wipe();
  display_time(grid.Color(0, 255, 255), grid.Color(0, 255, 0));
  grid.show();  
}

//----------------------------------------------------------------------------------------------
//UTILITY FUNCTIONS
//TEMPORARY, MOVE TO HEADER

//Turns all pixels off
void wipe(){
  for(int i = 0; i < LENGTH; i++){
    grid.setPixelColor(i, grid.Color(0, 0, 0));
  }
}

//Returns integer value of the minute.
int get_min(void){
  int m;
  m = (int)rtc.now().minute();
  return m;
}

//Returns integer value of the hour.
int get_hour(void){
  int h;
  h = (int)rtc.now().hour();
  return h;
}

//Interfaces with the RTC to determine what to display based on current time.
//Five minute intervals, with different hour depending on the "half" of the current hour.
void display_time(uint32_t c, uint32_t hc){
  it(c);
  is(c);
  
  if(get_min() >= 0 && get_min() < 5){
    display_hour(get_hour(), hc);
  }

  if(get_min() >= 5 && get_min() < 10){
    five_t(c);
    past(c);
    display_hour(get_hour(), hc);
  }

  if(get_min() >= 10 && get_min() < 15){
    ten_t(c);
    past(c);
    display_hour(get_hour(), hc);
  }

  if(get_min() >= 15 && get_min() < 20){
    a(c);
    quarter(c);
    past(c);
    display_hour(get_hour(), hc);
  }

  if(get_min() >= 20 && get_min() < 25){
    twenty(c);
    past(c);
    display_hour(get_hour(), hc);
  }

  if(get_min() >= 25 && get_min() < 30){
    twenty(c);
    five_t(c);
    past(c);
    display_hour(get_hour(), hc);
  }

  if(get_min() >= 30 && get_min() < 35){
    half(c);
    past(c);
    display_hour(get_hour(), hc);
  }

  if(get_min() >= 35 && get_min() < 40){
    twenty(c);
    five_t(c);
    to(c);
    display_hour(get_hour() + 1, hc);
  }

  if(get_min() >= 40 && get_min() < 45){
    twenty(c);
    to(c);
    display_hour(get_hour() + 1, hc);
  }

  if(get_min() >= 45 && get_min() < 50){
    a(c);
    quarter(c);
    to(c);
    display_hour(get_hour() + 1, hc);
  }

  if(get_min() >= 50 && get_min() < 55){
    ten_t(c);
    to(c);
    display_hour(get_hour() + 1, hc);
  }

  if(get_min() >= 55 && get_min() < 60){
    five_t(c);
    to(c);
    display_hour(get_hour() + 1, hc);
  }
  
}

//Takes a numeric hour, and displays the corresponding word.
void display_hour(int h, uint32_t c){
  if(h > 12)
    h -= 12;
  
  if(h == 1){
    one(c);
  }
  if(h == 2){
    two(c);
  }
  if(h == 3){
    three(c);
  }
  if(h == 4){
    four(c);
  }
  if(h == 5){
    five_b(c);
  }
  if(h == 6){
    six(c);
  }
  if(h == 7){
    seven(c);
  }
  if(h == 8){
    eight(c);
  }
  if(h == 9){
    nine(c);
  }
  if(h == 10){
    ten_b(c);
  }
  if(h == 11){
    eleven(c);
  }
  if(h == 12){
    twelve(c);
  }
}

//----------------------------------------------------------------------------------------------
//INDIVIDUAL WORD FUNCTIONS
//TEMPORARY, MOVE TO HEADER

void it(uint32_t c){
  grid.setPixelColor(90, c);
  grid.setPixelColor(89, c);
}

void is(uint32_t c){
  grid.setPixelColor(69, c);
  grid.setPixelColor(50, c);
}

void a(uint32_t c){
  grid.setPixelColor(28, c);
}

void happy(uint32_t c){
  grid.setPixelColor(49, c);
  grid.setPixelColor(30, c);
  grid.setPixelColor(29, c);
  grid.setPixelColor(10, c);
  grid.setPixelColor(9, c);
}

void twenty(uint32_t c){
  grid.setPixelColor(91, c);
  grid.setPixelColor(88, c);
  grid.setPixelColor(71, c);
  grid.setPixelColor(68, c);
  grid.setPixelColor(51, c);
  grid.setPixelColor(48, c);
}

void half(uint32_t c){
  grid.setPixelColor(31, c);
  grid.setPixelColor(28, c);
  grid.setPixelColor(11, c);
  grid.setPixelColor(8, c);
}

void bday(uint32_t c){
  grid.setPixelColor(87, c);
  grid.setPixelColor(72, c);
  grid.setPixelColor(67, c);
  grid.setPixelColor(52, c);
}

void five_t(uint32_t c){
  grid.setPixelColor(32, c);
  grid.setPixelColor(27, c);
  grid.setPixelColor(12, c);
  grid.setPixelColor(7, c);
}

void ten_t(uint32_t c){
  grid.setPixelColor(93, c);
  grid.setPixelColor(86, c);
  grid.setPixelColor(73, c);
}

void quarter(uint32_t c){
  grid.setPixelColor(66, c);
  grid.setPixelColor(53, c);
  grid.setPixelColor(46, c);
  grid.setPixelColor(33, c);
  grid.setPixelColor(26, c);
  grid.setPixelColor(13, c);
  grid.setPixelColor(6, c);
}

void to(uint32_t c){
  grid.setPixelColor(94, c);
  grid.setPixelColor(85, c);
}

void past(uint32_t c){
  grid.setPixelColor(74, c);
  grid.setPixelColor(65, c);
  grid.setPixelColor(54, c);
  grid.setPixelColor(45, c);
}

void papa(uint32_t c){
  grid.setPixelColor(34, c);
  grid.setPixelColor(25, c);
  grid.setPixelColor(14, c);
  grid.setPixelColor(5, c);
}

void granny(uint32_t c){
  grid.setPixelColor(97, c);
  grid.setPixelColor(82, c);
  grid.setPixelColor(77, c);
  grid.setPixelColor(62, c);
  grid.setPixelColor(57, c);
  grid.setPixelColor(42, c);
}

void one(uint32_t c){
  grid.setPixelColor(21, c);
  grid.setPixelColor(18, c);
  grid.setPixelColor(1, c);
}

void two(uint32_t c){
  grid.setPixelColor(39, c);
  grid.setPixelColor(20, c);
  grid.setPixelColor(19, c);
}

void three(uint32_t c){
  grid.setPixelColor(4, c);
  grid.setPixelColor(3, c);
  grid.setPixelColor(2, c);
  grid.setPixelColor(1, c);
  grid.setPixelColor(0, c);
}

void four(uint32_t c){
  grid.setPixelColor(37, c);
  grid.setPixelColor(22, c);
  grid.setPixelColor(17, c);
  grid.setPixelColor(2, c);
}

void five_b(uint32_t c){
  grid.setPixelColor(76, c);
  grid.setPixelColor(63, c);
  grid.setPixelColor(56, c);
  grid.setPixelColor(43, c);
}

void six(uint32_t c){
  grid.setPixelColor(36, c);
  grid.setPixelColor(23, c);
  grid.setPixelColor(16, c);
}

void seven(uint32_t c){
  grid.setPixelColor(55, c);
  grid.setPixelColor(44, c);
  grid.setPixelColor(35, c);
  grid.setPixelColor(24, c);
  grid.setPixelColor(15, c);
}

void eight(uint32_t c){
  grid.setPixelColor(95, c);
  grid.setPixelColor(96, c);
  grid.setPixelColor(97, c);
  grid.setPixelColor(98, c);
  grid.setPixelColor(99, c);
}

void nine(uint32_t c){
  grid.setPixelColor(64, c);
  grid.setPixelColor(63, c);
  grid.setPixelColor(62, c);
  grid.setPixelColor(61, c);
}

void ten_b(uint32_t c){
  grid.setPixelColor(84, c);
  grid.setPixelColor(75, c);
  grid.setPixelColor(64, c);
}

void eleven(uint32_t c){
  grid.setPixelColor(81, c);
  grid.setPixelColor(78, c);
  grid.setPixelColor(61, c);
  grid.setPixelColor(58, c);
  grid.setPixelColor(41, c);
  grid.setPixelColor(38, c);
}

void twelve(uint32_t c){
  grid.setPixelColor(99, c);
  grid.setPixelColor(80, c);
  grid.setPixelColor(79, c);
  grid.setPixelColor(60, c);
  grid.setPixelColor(59, c);
  grid.setPixelColor(40, c);
}

//----------------------------------------------------------------------------------------------
//FOR FUN / TESTING

//For fun.
void snake(uint32_t c, int t){
  wipe();
  for(int i = 0; i < LENGTH; i++){
    grid.setPixelColor(i, c);
    wipe(t);
  }
}

//Overloaded. Shows current display for 't' ms, and wipes again.
void wipe(int t){
  grid.show();
  delay(t);
  wipe();
}

//Tests each word, using a color "c" and a time delay of "t" ms between each.
void test_words(uint32_t c, int t){
  it(c);
  wipe(t);
  
  is(c);
  wipe(t);

  a(c);
  wipe(t);
  
  happy(c);
  wipe(t);
  
  twenty(c);
  wipe(t);
  
  half(c);
  wipe(t);
  
  bday(c);
  wipe(t);
  
  five_t(c);
  wipe(t);
  
  ten_t(c);
  wipe(t);
  
  quarter(c);
  wipe(t);
  
  to(c);
  wipe(t);
  
  past(c);
  wipe(t);
  
  papa(c);
  wipe(t);

  granny(c);
  wipe(t);
  
  one(c);
  wipe(t);
  
  two(c);
  wipe(t);
  
  three(c);
  wipe(t);
  
  four(c);
  wipe(t);
  
  five_b(c);
  wipe(t);
  
  six(c);
  wipe(t);
  
  seven(c);
  wipe(t);
  
  eight(c);
  wipe(t);
  
  nine(c);
  wipe(t);
  
  ten_b(c);
  wipe(t);
  
  eleven(c);
  wipe(t);
  
  twelve(c);
  wipe(t);
  
}
