//----------------------------------------------------------------------------------------------
//FUNCTIONS THAT MODIFY AND ACCESS TIME

// Adds a second to the RTC time.
void add_sec(){
  rtc.adjust(DateTime(rtc.now().unixtime() + 1));
    Serial.print(rtc.now().hour(), DEC);
    Serial.print(':');
    Serial.print(rtc.now().minute(), DEC);
    Serial.print(':');
    Serial.print(rtc.now().second(), DEC);
    Serial.println();
}

//Subtracts a second from the RTC time.
void sub_sec(){
  rtc.adjust(DateTime(rtc.now().unixtime() - 1));
    Serial.print(rtc.now().hour(), DEC);
    Serial.print(':');
    Serial.print(rtc.now().minute(), DEC);
    Serial.print(':');
    Serial.print(rtc.now().second(), DEC);
    Serial.println();
}

// Adds a minute to the RTC time.
void add_min(){
  rtc.adjust(DateTime(rtc.now().unixtime() + 60));
    Serial.print(rtc.now().hour(), DEC);
    Serial.print(':');
    Serial.print(rtc.now().minute(), DEC);
    Serial.print(':');
    Serial.print(rtc.now().second(), DEC);
    Serial.println();
}

//Subtracts a minute from the RTC time.
void sub_min(){
  rtc.adjust(DateTime(rtc.now().unixtime() - 60));
    Serial.print(rtc.now().hour(), DEC);
    Serial.print(':');
    Serial.print(rtc.now().minute(), DEC);
    Serial.print(':');
    Serial.print(rtc.now().second(), DEC);
    Serial.println();
}

// Adds an hour to the RTC time.
void add_hour(){
  rtc.adjust(DateTime(rtc.now().unixtime() + 3600));
    Serial.print(rtc.now().hour(), DEC);
    Serial.print(':');
    Serial.print(rtc.now().minute(), DEC);
    Serial.print(':');
    Serial.print(rtc.now().second(), DEC);
    Serial.println();
}

//Subtracts an hour from the RTC time.
void sub_hour(){
  rtc.adjust(DateTime(rtc.now().unixtime() - 3600));
    Serial.print(rtc.now().hour(), DEC);
    Serial.print(':');
    Serial.print(rtc.now().minute(), DEC);
    Serial.print(':');
    Serial.print(rtc.now().second(), DEC);
    Serial.println();
}

//Returns integer value of the second.
int get_sec(void){
  int s;
  s = (int)rtc.now().second();
  return s;
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
