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
void display_ms(uint32_t c){
  
}

// Numerically display hours and minutes
void display_hm(uint32_t c){
  
}
