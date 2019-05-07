#ifndef LAYER_H
#define LAYER_H
namespace Layer {
  enum layer {
              latin,
              cyrillic,
              modificator
  } curr = latin, prev = latin;

  bool should_

  void enter(layer newl) {
    prev = curr;
    curr = newl;

#ifdef DEBUGGING
    Serial.print("Enter layer ");
    Serial.print(curr);
    Serial.print(" from layer ");
    Serial.print(prev);
#endif
  }

  uint16_t prevmodmask;

  void enter_mod(const uint16_t modmask) {
    prevmodmask = modmask;
    uint8_t j = 0;

    for (uint16_t i = 1; i <= 16; i *= 2) {
      if (modmask & i) {
        Keyboard.press(Mod::val[j]);
#ifdef DEBUGGING
        Serial.print("Send modificator ");
        Serial.println(Mod::val[j]);
#endif
      }
      j++;
    }

    prev = curr;
    curr = modificator;
  }

  void back() {
    Keyboard.releaseAll();
    layer buf = prev;
    prev = curr;
    curr = buf;
#ifdef DEBUGGING
    Serial.println("Go back by layer.");
#endif

  }
}

#endif
