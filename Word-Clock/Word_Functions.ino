//----------------------------------------------------------------------------------------------
//INDIVIDUAL WORD FUNCTIONS

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

// Helper functions
/*
 * These two functions are used to convert the snake-like
 * coordinate system above into a virtual system, which
 * uses a 2 digit number as a [x][y] offset in the negative
 * direction for x.
 * ORIGIN - virtual
 */

// Turns virtual -> actual coordinate.
byte point_unmirror(byte vpoint){
  byte column = vpoint/10;
  byte row = vpoint%10;
  if(column%2 != 0){
    row = 9 - row;
  }
  return (10*column) + row;
}

// This function will automatically take a
// virtual origin, and make sure it fits
byte origin_fit(byte vpoint){
  byte column = vpoint/10;
  byte row = vpoint%10;
  if(column > 6){
    column = 6;
  }
  if(row > 5){
    row = 5;
  }
  return (10*column) + row;
}

// Big Letters / Numbers:

void S(uint32_t c){
  grid.setPixelColor(50, c);
  grid.setPixelColor(69, c);
  grid.setPixelColor(70, c);
  grid.setPixelColor(89, c);
  grid.setPixelColor(90, c);
  grid.setPixelColor(91, c);
  grid.setPixelColor(92, c);
  grid.setPixelColor(87, c);
  grid.setPixelColor(72, c);
  grid.setPixelColor(67, c);
  grid.setPixelColor(52, c);
  grid.setPixelColor(53, c);
  grid.setPixelColor(54, c);
  grid.setPixelColor(65, c);
  grid.setPixelColor(74, c);
  grid.setPixelColor(85, c);
  grid.setPixelColor(94, c);
}

void M(uint32_t c){
  grid.setPixelColor(45, c);
  grid.setPixelColor(46, c);
  grid.setPixelColor(47, c);
  grid.setPixelColor(48, c);
  grid.setPixelColor(49, c);
  grid.setPixelColor(31, c);
  grid.setPixelColor(27, c);
  grid.setPixelColor(11, c);
  grid.setPixelColor(9, c);
  grid.setPixelColor(8, c);
  grid.setPixelColor(7, c);
  grid.setPixelColor(6, c);
  grid.setPixelColor(5, c);
}

void H(uint32_t c){
  grid.setPixelColor(95, c);
  grid.setPixelColor(96, c);
  grid.setPixelColor(97, c);
  grid.setPixelColor(98, c);
  grid.setPixelColor(99, c);
  grid.setPixelColor(82, c);
  grid.setPixelColor(77, c);
  grid.setPixelColor(62, c);
  grid.setPixelColor(55, c);
  grid.setPixelColor(56, c);
  grid.setPixelColor(57, c);
  grid.setPixelColor(58, c);
  grid.setPixelColor(59, c);
}

void little_C(uint32_t c){
  grid.setPixelColor(18, c);
  grid.setPixelColor(21, c);
  grid.setPixelColor(38, c);
  grid.setPixelColor(37, c);
  grid.setPixelColor(36, c);
  grid.setPixelColor(23, c);
  grid.setPixelColor(16, c);
}

// 5x5 pixel numbers (require bottom right origin point):
/*
 * The math for these number is very stupid due to the orientation
 * of the RGB pixel grid. The helper functions above are used to 
 * create a virtual coordinate system which is easier to plan around.
 */

void n_0(uint32_t c, byte origin){
  origin = origin_fit(origin);
  grid.setPixelColor(point_unmirror(origin+01), c);
  grid.setPixelColor(point_unmirror(origin+02), c);
  grid.setPixelColor(point_unmirror(origin+03), c);
  grid.setPixelColor(point_unmirror(origin+10), c);
  grid.setPixelColor(point_unmirror(origin+20), c);
  grid.setPixelColor(point_unmirror(origin+14), c);
  grid.setPixelColor(point_unmirror(origin+24), c);
  grid.setPixelColor(point_unmirror(origin+31), c);
  grid.setPixelColor(point_unmirror(origin+32), c);
  grid.setPixelColor(point_unmirror(origin+33), c);
}

void n_1(uint32_t c, byte origin){
  origin = origin_fit(origin);
  grid.setPixelColor(point_unmirror(origin+00), c);
  grid.setPixelColor(point_unmirror(origin+10), c);
  grid.setPixelColor(point_unmirror(origin+20), c);
  grid.setPixelColor(point_unmirror(origin+30), c);
  grid.setPixelColor(point_unmirror(origin+11), c);
  grid.setPixelColor(point_unmirror(origin+12), c);
  grid.setPixelColor(point_unmirror(origin+13), c);
  grid.setPixelColor(point_unmirror(origin+14), c);
  grid.setPixelColor(point_unmirror(origin+24), c);
  //grid.setPixelColor(point_unmirror(origin+34), c);
}

void n_2(uint32_t c, byte origin){
  origin = origin_fit(origin);
  grid.setPixelColor(point_unmirror(origin), c);
  grid.setPixelColor(point_unmirror(origin+10), c);
  grid.setPixelColor(point_unmirror(origin+20), c);
  grid.setPixelColor(point_unmirror(origin+30), c);
  grid.setPixelColor(point_unmirror(origin+31), c);
  grid.setPixelColor(point_unmirror(origin+22), c);
  grid.setPixelColor(point_unmirror(origin+12), c);
  grid.setPixelColor(point_unmirror(origin+02), c);
  grid.setPixelColor(point_unmirror(origin+03), c);
  grid.setPixelColor(point_unmirror(origin+14), c);
  grid.setPixelColor(point_unmirror(origin+24), c);
  grid.setPixelColor(point_unmirror(origin+34), c);
}

void n_3(uint32_t c, byte origin){
  origin = origin_fit(origin);
  //grid.setPixelColor(point_unmirror(origin), c);
  grid.setPixelColor(point_unmirror(origin+10), c);
  grid.setPixelColor(point_unmirror(origin+20), c);
  grid.setPixelColor(point_unmirror(origin+30), c);
  grid.setPixelColor(point_unmirror(origin+01), c);
  //grid.setPixelColor(point_unmirror(origin+02), c);
  grid.setPixelColor(point_unmirror(origin+03), c);
  //grid.setPixelColor(point_unmirror(origin+04), c);
  grid.setPixelColor(point_unmirror(origin+12), c);
  grid.setPixelColor(point_unmirror(origin+22), c);
  grid.setPixelColor(point_unmirror(origin+32), c);
  grid.setPixelColor(point_unmirror(origin+14), c);
  grid.setPixelColor(point_unmirror(origin+24), c);
  grid.setPixelColor(point_unmirror(origin+34), c);
}

void n_4(uint32_t c, byte origin){
  origin = origin_fit(origin);
  grid.setPixelColor(point_unmirror(origin+02), c);
  grid.setPixelColor(point_unmirror(origin+10), c);
  grid.setPixelColor(point_unmirror(origin+11), c);
  grid.setPixelColor(point_unmirror(origin+12), c);
  grid.setPixelColor(point_unmirror(origin+13), c);
  grid.setPixelColor(point_unmirror(origin+14), c);
  grid.setPixelColor(point_unmirror(origin+12), c);
  grid.setPixelColor(point_unmirror(origin+22), c);
  grid.setPixelColor(point_unmirror(origin+32), c);
  grid.setPixelColor(point_unmirror(origin+33), c);
  grid.setPixelColor(point_unmirror(origin+34), c);
}

void n_5(uint32_t c, byte origin){
  origin = origin_fit(origin);
  grid.setPixelColor(point_unmirror(origin+10), c);
  grid.setPixelColor(point_unmirror(origin+20), c);
  grid.setPixelColor(point_unmirror(origin+30), c);
  grid.setPixelColor(point_unmirror(origin+01), c);
  grid.setPixelColor(point_unmirror(origin+12), c);
  grid.setPixelColor(point_unmirror(origin+22), c);
  grid.setPixelColor(point_unmirror(origin+32), c);
  grid.setPixelColor(point_unmirror(origin+33), c);
  grid.setPixelColor(point_unmirror(origin+34), c);
  grid.setPixelColor(point_unmirror(origin+24), c);
  grid.setPixelColor(point_unmirror(origin+14), c);
  grid.setPixelColor(point_unmirror(origin+04), c);
}

void n_6(uint32_t c, byte origin){
  origin = origin_fit(origin);
  grid.setPixelColor(point_unmirror(origin+10), c);
  grid.setPixelColor(point_unmirror(origin+20), c);
  grid.setPixelColor(point_unmirror(origin+01), c);
  grid.setPixelColor(point_unmirror(origin+31), c);
  grid.setPixelColor(point_unmirror(origin+12), c);
  grid.setPixelColor(point_unmirror(origin+22), c);
  grid.setPixelColor(point_unmirror(origin+32), c);
  grid.setPixelColor(point_unmirror(origin+33), c);
  grid.setPixelColor(point_unmirror(origin+24), c);
  grid.setPixelColor(point_unmirror(origin+14), c);
}

void n_7(uint32_t c, byte origin){
  origin = origin_fit(origin);
  grid.setPixelColor(point_unmirror(origin+10), c);
  grid.setPixelColor(point_unmirror(origin+11), c);
  grid.setPixelColor(point_unmirror(origin+12), c);
  grid.setPixelColor(point_unmirror(origin+03), c);
  grid.setPixelColor(point_unmirror(origin+04), c);
  grid.setPixelColor(point_unmirror(origin+14), c);
  grid.setPixelColor(point_unmirror(origin+24), c);
  grid.setPixelColor(point_unmirror(origin+34), c);
}

void n_8(uint32_t c, byte origin){
  origin = origin_fit(origin);
  grid.setPixelColor(point_unmirror(origin+10), c);
  grid.setPixelColor(point_unmirror(origin+20), c);
  grid.setPixelColor(point_unmirror(origin+01), c);
  grid.setPixelColor(point_unmirror(origin+31), c);
  grid.setPixelColor(point_unmirror(origin+12), c);
  grid.setPixelColor(point_unmirror(origin+22), c);
  grid.setPixelColor(point_unmirror(origin+03), c);
  grid.setPixelColor(point_unmirror(origin+33), c);
  grid.setPixelColor(point_unmirror(origin+14), c);
  grid.setPixelColor(point_unmirror(origin+24), c);
  //grid.setPixelColor(point_unmirror(origin+00), c);
  //grid.setPixelColor(point_unmirror(origin+30), c);
  //grid.setPixelColor(point_unmirror(origin+02), c);
  //grid.setPixelColor(point_unmirror(origin+32), c);
  //grid.setPixelColor(point_unmirror(origin+04), c);
  //grid.setPixelColor(point_unmirror(origin+34), c);
}

void n_9(uint32_t c, byte origin){
  origin = origin_fit(origin);
  grid.setPixelColor(point_unmirror(origin+10), c);
  grid.setPixelColor(point_unmirror(origin+20), c);
  grid.setPixelColor(point_unmirror(origin+01), c);
  grid.setPixelColor(point_unmirror(origin+02), c);
  grid.setPixelColor(point_unmirror(origin+03), c);
  grid.setPixelColor(point_unmirror(origin+12), c);
  grid.setPixelColor(point_unmirror(origin+22), c);
  grid.setPixelColor(point_unmirror(origin+33), c);
  grid.setPixelColor(point_unmirror(origin+24), c);
  grid.setPixelColor(point_unmirror(origin+14), c);
}

// Words:

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
