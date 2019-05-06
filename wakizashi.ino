#include <Keyboard.h>
#include <avr/io.h>

#define RELEASED_A_KEY chord_read_now > chord_in_build
#define PRESSED_A_KEY chord_read_now < chord_in_build

typedef uint16_t chord;
// configuration
#define COL_PIN PINF
#define COL_PORT PORTF
#define COLS 0xf0

#define ROW_PORT PORTB
#define ROW_DDR DDRB
#define ROW0 _BV(3)
#define ROW1 _BV(2)
#define ROW2 _BV(1)

#define DEBUGGING 1

enum mod {
          Mctrl = 1,
          Mshift = 2,
          Maltl = 4,
          Msuper = 8,
          Maltgr = 16
};

uint8_t modval[5] = {KEY_LEFT_CTRL,
                     KEY_LEFT_SHIFT,
                     KEY_LEFT_ALT,
                     KEY_LEFT_GUI,
                     KEY_RIGHT_ALT};

enum layer {
            Llatin,
            Lcyrillic,
            Lmodificator,
} currl = Llatin, prevl = Llatin;

namespace Layer {
  void enter(layer newl) {
    prevl = currl;
    currl = newl;
#ifdef DEBUGGING
    Serial.print("Enter layer ");
    Serial.print(currl);
    Serial.print(" from layer ");
    Serial.print(prevl);
#endif
  }

  uint16_t prevmodmask = 0;

  void enter_mod(uint16_t modmask) {
    prevmodmask = modmask;
    uint8_t j = 0;
    for (uint16_t i = 1; i <= 16; i *= 2) {
      if (modmask & i) {
        Keyboard.press(modval[j]);
        Serial.print("Send modificator ");
        Serial.println(modval[j]);
      }
      j++;
    }
  }

  void back() {

  }
}

void setup() {
  Keyboard.begin();
  Serial.begin(9600);
  Serial.println("Waki init!");
  COL_PORT |= COLS; // enabling pullup on column pins
  ROW_DDR |= ROW0 | ROW1 | ROW2; // enabling output on row pins
}

/* Print a chord `c` with rows separated by space. */
void debug_print(chord c) {
#ifdef DEBUGGING
  Serial.print((c & 0b11110000000) >> 7, BIN); Serial.print(" ");
  Serial.print((c & 0b1111000) >> 3, BIN); Serial.print(" ");
  Serial.print(c % 0b1000, BIN); Serial.println("");
#endif
}


#include "layout.h"

/* Read a row. */
chord read_row(uint8_t leftshift, uint8_t outmask, uint8_t readvalmask = 0xf0) {
  // Write HIGH only to needed row pins. The left third pin is LOW.
  ROW_PORT = (ROW_PORT & 0b11110001) | outmask;

  // Read columns and rightshift by 4 (the lowest nibble is unneeded). readvalmask is needed when
  // reading the thumb row, because there are only 3 buttons.
  chord c = (COL_PIN & readvalmask) >> 4;

  // Reverse the chord because of hardware design fault
  return (
           (bitRead(c, 0) << 3) |
           (bitRead(c, 1) << 2) |
           (bitRead(c, 2) << 1) |
           bitRead(c, 3)
         ) << leftshift;
}

/* Read all rows together. */
chord read_rows() {
  return
    read_row(7, ROW1 | ROW2) |
    read_row(3, ROW0 | ROW2) |
    read_row(0, ROW0 | ROW1, 0xe0);
}

/* Read all rows together and debounce the result. */
chord read_keeb() {
  return read_rows() & (delay(10), read_rows());
}

enum State { WAIT_KEYPRESS, WAIT_RELEASE } state = WAIT_KEYPRESS;
chord chord_read_now = 0, chord_in_build = 0, chordbuf;
void loop() {
  // ignoring same results
  while ((chord_read_now = read_keeb()) == chord_in_build) {}

  //debug_print(chord_read_now);

  if (state == WAIT_RELEASE) {
    if (RELEASED_A_KEY) {
      exec_chord(chord_in_build);
      state = WAIT_KEYPRESS;
    }
    chord_in_build = chord_read_now;
  }
  else if (state == WAIT_KEYPRESS) {
    if (PRESSED_A_KEY) {
      state = WAIT_RELEASE;
    }
    chord_in_build = chord_read_now;
  }


}
