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

// Tests the numerical numbers
void animate_numbers(uint32_t c, byte num, int d){
  if(num >= 1){
    for(byte col = 0; col <= 50; col+=10){
      for(byte row = 0; row <= 5; row++){
        wipe();
        n_0(c, col+row);
        grid.show();
        delay(d);
      }
    }
  }
    if(num >= 2){
    for(byte col = 0; col <= 50; col+=10){
      for(byte row = 0; row <= 5; row++){
        wipe();
        n_1(c, col+row);
        grid.show();
        delay(d);
      }
    }
  }
    if(num >= 3){
    for(byte col = 0; col <= 50; col+=10){
      for(byte row = 0; row <= 5; row++){
        wipe();
        n_2(c, col+row);
        grid.show();
        delay(d);
      }
    }
  }
    if(num >= 4){
    for(byte col = 0; col <= 50; col+=10){
      for(byte row = 0; row <= 5; row++){
        wipe();
        n_3(c, col+row);
        grid.show();
        delay(d);
      }
    }
  }
    if(num >= 5){
    for(byte col = 0; col <= 50; col+=10){
      for(byte row = 0; row <= 5; row++){
        wipe();
        n_4(c, col+row);
        grid.show();
        delay(d);
      }
    }
  }
    if(num >= 6){
    for(byte col = 0; col <= 50; col+=10){
      for(byte row = 0; row <= 5; row++){
        wipe();
        n_5(c, col+row);
        grid.show();
        delay(d);
      }
    }
  }
    if(num >= 7){
    for(byte col = 0; col <= 50; col+=10){
      for(byte row = 0; row <= 5; row++){
        wipe();
        n_6(c, col+row);
        grid.show();
        delay(d);
      }
    }
  }
    if(num >= 8){
    for(byte col = 0; col <= 50; col+=10){
      for(byte row = 0; row <= 5; row++){
        wipe();
        n_7(c, col+row);
        grid.show();
        delay(d);
      }
    }
  }
    if(num >= 9){
    for(byte col = 0; col <= 50; col+=10){
      for(byte row = 0; row <= 5; row++){
        wipe();
        n_8(c, col+row);
        grid.show();
        delay(d);
      }
    }
  }
    if(num >= 10){
    for(byte col = 0; col <= 50; col+=10){
      for(byte row = 0; row <= 5; row++){
        wipe();
        n_9(c, col+row);
        grid.show();
        delay(d);
      }
    }
  }
}

void test_numbers(uint32_t c, byte num, int d){
  if(num >= 1){
    wipe();
    n_0(c, 0);
    grid.show();
    delay(d);
  }
  if(num >= 2){
    wipe();
    n_1(c, 0);
    grid.show();
    delay(d);
  }
  if(num >= 3){
    wipe();
    n_2(c, 0);
    grid.show();
    delay(d);
  }
  if(num >= 4){
    wipe();
    n_3(c, 0);
    grid.show();
    delay(d);
  }
  if(num >= 5){
    wipe();
    n_4(c, 0);
    grid.show();
    delay(d);
  }
  if(num >= 6){
    wipe();
    n_5(c, 0);
    grid.show();
    delay(d);
  }
  if(num >= 7){
    wipe();
    n_6(c, 0);
    grid.show();
    delay(d);
  }
  if(num >= 8){
    wipe();
    n_7(c, 0);
    grid.show();
    delay(d);
  }
  if(num >= 9){
    wipe();
    n_8(c, 0);
    grid.show();
    delay(d);
  }
  if(num >= 10){
    wipe();
    n_9(c, 0);
    grid.show();
    delay(d);
  }
}

