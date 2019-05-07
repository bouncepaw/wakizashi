#ifndef MOD_H
#define MOD_H

/* Code related to modificators */
namespace Mod {
  enum mod {
            ctrl = 1,
            shift = 2,
            altl = 4,
            super = 8,
            altgr = 16
  };
  uint8_t val[5] = {KEY_LEFT_CTRL,
                    KEY_LEFT_SHIFT,
                    KEY_LEFT_ALT,
                    KEY_LEFT_GUI,
                    KEY_RIGHT_ALT};

  /* Press modificators specified by modmask. */
  void register_mods(uint16_t modmask) {
    /* j is an index of a modificator from Mod::val[5] */
    uint8_t j = 0;

    while (j < 5) {
      /* If modificator bit is set */
      if (modmask & 1) {
        Keyboard.press(Mod::val[j]);
#ifdef DEBUGGING
        Serial.print("Send modificator ");
        Serial.println(Mod::val[j]);
#endif
      }
      /* Move to next bit of modmask*/
      modmask >>= 1;
      /* Move to next element of Mod::val[5] */
      j++;
    }
  }

  bool is_mod_on_now = false;
  Layer::layer layer_before_start = Layer::latin;

  /* Start modificator mode with modificators specified by modmask bitmask.
     Construct modmask with enum Mod::mod. */
  void start(uint16_t modmask, Layer::layer layer_val, Layer::layer &layer_var) {
    layer_before_start = layer_val;
    layer_var = Layer::latin;

    register_mods(modmask);

    is_mod_on_now = true;
  }

  /* Check chord currc and, if needed, stop modificator mode. */
  void stop_maybe(chord currc, Layer::layer &layer_var) {
    /* If function thumb is released*/
    if (!(currc & 1) && is_mod_on_now) {
      layer_var = layer_before_start;
      Keyboard.releaseAll();
      
      #ifdef DEBUGGING
      Serial.print("End modificator mode.");
      #endif
      
      is_mod_on_now = false;
    }
  }
}

#endif
