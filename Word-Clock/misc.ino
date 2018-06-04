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
