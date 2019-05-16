#ifndef LAYER_H
#define LAYER_H
namespace Layer {
  enum layer {
              latin,
              cyrillic,
              modificator
  } curr = latin, prev = latin;

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

  void back() {
    layer buf = prev;
    prev = curr;
    curr = buf;
#ifdef DEBUGGING
    Serial.println("Go back by layer.");
#endif

  }
}

#endif
