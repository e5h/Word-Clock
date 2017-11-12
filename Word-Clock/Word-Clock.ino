#include <Adafruit_NeoPixel.h>
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

//Initialize the LED grid.
Adafruit_NeoPixel grid = Adafruit_NeoPixel(LENGTH, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  grid.begin();
  grid.show();
}

void loop() {
  //wipe();
  //display_time();
  //grid.show();
  snake(grid.Color(0, 255, 255), 5);
  test_letters(grid.Color(0, 255, 255), 750);

  snake(grid.Color(0, 0, 255), 5);
  test_letters(grid.Color(0, 0, 255), 100);

  snake(grid.Color(255, 0, 255), 5);
  test_letters(grid.Color(255, 0, 255), 75);

  snake(grid.Color(255, 0, 0), 5);
  test_letters(grid.Color(255, 0, 0), 50);

  snake(grid.Color(255, 128, 0), 5);
  test_letters(grid.Color(255, 128, 0), 25);

  snake(grid.Color(255, 255, 0), 5);
  test_letters(grid.Color(255, 255, 0), 15);

  snake(grid.Color(0, 255, 0), 5);
  test_letters(grid.Color(0, 255, 0), 10);
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

//Overloaded. Shows current display for 't' ms, and wipes again.
void wipe(int t){
  grid.show();
  delay(t);
  wipe();
}

//Interfaces with the RTC to determine what to display.
void display_time(){
  happy(grid.Color(0, 255, 255));
}

//For fun.
void snake(uint32_t c, int t){
  wipe();
  for(int i = 0; i < LENGTH; i++){
    grid.setPixelColor(i, c);
    wipe(t);
  }
}

//Testing each word.
void test_letters(uint32_t c, int t){
  it(c);
  wipe(t);
  
  is(c);
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

//----------------------------------------------------------------------------------------------
//WORD FUNCTIONS
//TEMPORARY, MOVE TO HEADER

void it(uint32_t c){
  grid.setPixelColor(90, c);
  grid.setPixelColor(89, c);
}

void is(uint32_t c){
  grid.setPixelColor(69, c);
  grid.setPixelColor(50, c);
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

