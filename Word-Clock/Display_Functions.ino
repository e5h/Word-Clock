//----------------------------------------------------------------------------------------------
//FUNCTIONS THAT HANDLE THE DISPLAY

//Turns all pixels off
void wipe(){
  for(int i = 0; i < LENGTH; i++){
    grid.setPixelColor(i, grid.Color(0, 0, 0));
  }
}

//Checks to see if birthdays are active, and sets rainbow text if so.
void display_bday(){
  //Nov 29
  if(rtc.now().month() == 11 && rtc.now().day() == 29){
    happy(rainbow());
    bday(rainbow());
    papa(rainbow());
  }
  //July 30
  if(rtc.now().month() == 7 && rtc.now().day() == 30){
    happy(rainbow());
    bday(rainbow());
    granny(rainbow());
  }
}

//Storage for the various colors used in the display
uint32_t colors(byte i){
  static uint32_t c_arr[13]{
    grid.Color(255, 255, 255), // white (default)
    grid.Color(255, 0, 0), // red
    grid.Color(255, 128, 0), // orange
    grid.Color(255, 255, 0), // yellow
    grid.Color(128, 255, 0), // lime
    grid.Color(0, 255, 0), // green
    grid.Color(0, 255, 128), // mint
    grid.Color(0, 255, 255), // turquoise
    grid.Color(0, 128, 255), // light blue
    grid.Color(0, 0, 255), // blue
    grid.Color(128, 0, 255), // purple
    grid.Color(255, 0, 255), // pink
    grid.Color(255, 0, 128), // hot pink
  };
  if(i < 13){
    return c_arr[i];
  }
  else{
    switch(i){
      case 13:
        return rainbow();
    }
  }
}

// Cycles to the next top color
void nextTopColor(){
  top_color++;
  if(top_color > 13 || top_color < 0){
    top_color = 0;
  }
  colors_saved = false;
}

// Cycles to the next bottom color
void nextBottomColor(){
  bottom_color++;
  if(bottom_color > 13 || bottom_color < 0){
    bottom_color = 0;
  }
  colors_saved = false;
}

// Saves the current color scheme
void saveColors(){
  EEPROM.write(0, top_color);
  EEPROM.write(1, bottom_color);
  colors_saved = true;
}

uint32_t flash_color(uint32_t c1, uint32_t c2, int d){
  static unsigned long last_time;
  static byte color = 1;

  if(millis() - last_time > d){ // if timer is reached, designate new color
    last_time = millis();
    if(color == 1){
      color = 2;
      return c2;
    }
    else{
      color = 1;
      return c1;
    }
  }
  else{ // if timer is not reached, return current color
    if(color == 1){
      return c1;
    }
    else{
      return c2;
    }
  }
  
}

//Cycles through RGB values.
uint32_t rainbow(){
  static unsigned long last_time = 0;
  static byte incr = 0;

  if(millis() - last_time > RAINBOW_DELAY){
    if(incr < 255){
      incr++;
    }
    else{
      incr = 0;
    }

    last_time = millis();
  }

  if(incr > 170) {
    return grid.Color((incr - 170) * 3, 0, 255 - (incr - 170) * 3);
  }
  if(incr > 85) {
    return grid.Color(0, 255 - (incr - 85) * 3, (incr - 85) * 3);
  }
  else{
    return grid.Color(255 - incr * 3, incr * 3, 0);
  }
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
  if(h >= 12){
    h -= 12;
  }
  
  if(h == 0){
    twelve(c);
  }
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
}

// Numerically display minutes and seconds
void display_ms(uint32_t tc, uint32_t bc){
  int m = get_min();
  int s = get_sec();
  display_num(tc, (m/10), 65); // top left
  display_num(tc, (m%10), 05); // top right
  display_num(bc, (s/10), 60); // bottom left
  display_num(bc, (s%10), 00); // bottom right
}

// Numerically display hours and minutes
void display_hm(uint32_t tc, uint32_t bc){
  int h = get_hour();
  int m = get_min();
  display_num(tc, (h/10), 65); // top left
  display_num(tc, (h%10), 05); // top right
  display_num(bc, (m/10), 60); // bottom left
  display_num(bc, (m%10), 00); // bottom right
}

//displays the number specified
void display_num(uint32_t c, byte num, byte origin){
  switch (num){
    case 0:
      n_0(c, origin);
      break;
    case 1:
      n_1(c, origin);
      break;
    case 2:
      n_2(c, origin);
      break;
    case 3:
      n_3(c, origin);
      break;
    case 4:
      n_4(c, origin);
      break;
    case 5:
      n_5(c, origin);
      break;
    case 6:
      n_6(c, origin);
      break;
    case 7:
      n_7(c, origin);
      break;
    case 8:
      n_8(c, origin);
      break;
    case 9:
      n_9(c, origin);
      break;
    default:
      Serial.println("Invalid!");
      break;
  }
}

