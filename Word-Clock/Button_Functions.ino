//----------------------------------------------------------------------------------------------
//FUNCTIONS THAT HANDLE THE INPUTS

//Checks the button states.
void check_buttons(byte *state){
  static unsigned long last_time = 0;
  static byte last_state[2] = {0, 0};
  static byte held = 0;
  int up_btn = digitalRead(9);
  int down_btn = digitalRead(8);

  if(millis() - last_time > BUTTON_DELAY){ // Debouncing delay

    // If the up button is pushed
    if(up_btn == 1 && up_btn != last_state[0]){
      last_time = millis(); // Record last time pressed
      held = 0; // Assume the button is not being held
      while(digitalRead(9) == 1){ // Check if the button is being held
        if(millis() - last_time > HOLD_DELAY){
          held = 1;
          last_time = millis();
          break;
        }
      }
      if(held){ // If the button is held
        Serial.println("Up button held!");
        *state = up_held(*state);
      }
      else{ // If the button is tapped
        Serial.println("Up button tapped.");
        *state = up_tapped(*state);
      }
    }

    // If the down button is pushed
    if(down_btn == 1 && down_btn != last_state[1]){
      last_time = millis();
      held = 0;
      while(digitalRead(8) == 1){
        if(millis() - last_time > HOLD_DELAY){
          held = 1;
          last_time = millis();
          break;
        }
      }
      if(held){ // If the button is held
        Serial.println("Down button held!");
        *state = down_held(*state);
      }
      else{ // If the button is tapped
        Serial.println("Down button tapped!");
        *state = down_tapped(*state);
      }
    }
  }

  last_state[0] = up_btn;
  last_state[1] = down_btn;
  
}

/*
 * In the functions below, the real-time button results will
 * be handled. The built in purpose of the functions themselves
 * is to handle state changes based on the current state and
 * type of input.
 */

// If the up button is held
byte up_held(byte state){
  switch(state){
    case 0: // Regular clock functionality
      state = 4; // swap to numbered time
      //code
      break;
    case 1: // Menu - seconds
      saveColors();
      break;
    case 2: // Menu - minutes
      saveColors();
      break;
    case 3: // Menu - hours
      saveColors();
      break;
    case 4: // Numbered time - ms
      state = 0; // return to normal clock
      break;
    case 11: // Edit - seconds
      state = 12; // edit minutes
      break;
    case 12: // Edit - minutes
      state = 13; // edit hours
      break;
    case 13: // Edit - hours
      state = 11; // edit seconds
      break;
  }
  return state;
}

// If the up button is tapped
byte up_tapped(byte state){
  switch(state){
    case 0: // Regular clock functionality
      Serial.println("Top color cycled.");//PLACEHOLDER
      nextTopColor();
      break;
    case 1: // Menu - seconds
      state = 11; // begin editing in seconds
      break;
    case 2: // Menu - minutes
      state = 12; // begin editing in minutes
      break;
    case 3: // Menu - hours
      state = 13; // begin editing in hours
      break;
    case 4: // Numbered time - ms
      nextTopColor();
      break;
    case 11: // Edit - seconds
      add_sec(); // add a second
      break;
    case 12: // Edit - minutes
      add_min(); // add a minute
      break;
    case 13: // Edit - hours
      add_hour(); // add an hour
      break;
  }
  return state;
}

// If the down button is held
byte down_held(byte state){
  switch(state){
    case 0: // Regular clock functionality
      state = 1; // enter into seconds menu
      break;
    case 1: // Menu - seconds
      state = 0; // exit to regular clock
      break;
    case 2: // Menu - minutes
      state = 0; // exit to regular clock
      break;
    case 3: // Menu - hours
      state = 0; // exit to regular clock
      break;
    case 4: // Numbered time - ms
      state = 1; // enter into seconds menu
      break;
    case 11: // Edit - seconds
      state = 1; // exit to seconds menu
      break;
    case 12: // Edit - minutes
      state = 2; // exit to minutes menu
      break;
    case 13: // Edit - hours
      state = 3; // exit to hours menu
      break;
  }
  return state;
}

// If the down button is tapped
byte down_tapped(byte state){
  switch(state){
    case 0: // Regular clock functionality
      Serial.println("Bottom color cycled.");//PLACEHOLDER
      nextBottomColor();
      break;
    case 1: // Menu - seconds
      state = 2; // go to minutes menu
      break;
    case 2: // Menu - minutes
      state = 3; // go to hours menu
      break;
    case 3: // Menu - hours
      state = 1; // go to seconds menu
      break;
    case 4: // Numbered time - ms
      nextBottomColor();
      break;
    case 11: // Edit - seconds
      sub_sec(); // subtract a second
      break;
    case 12: // Edit - minutes
      sub_min(); // subtract a minute
      break;
    case 13: // Edit - hours
      sub_hour(); // subtract an hour
      break;
  }
  return state;
}
