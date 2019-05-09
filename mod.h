#ifndef MOD_H
#define MOD_H

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

}
class Modif {
private:
  bool is_active;
  Layer::layer layer_before_start;
  enum modiftype { tquazi, tmode, tctrl } mtype;
  chord quazi_thumb;
public:
  Modif() {
    is_active = false;
  }


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


  void stop(Layer::layer &layer_var) {
    layer_var = layer_before_start;
    Keyboard.releaseAll();

#ifdef DEBUGGING
    Serial.println("End modificator mode.");
#endif

    is_active = false;
  }


  void start_mode(uint16_t modmask, Layer::layer &layer_var) {
    layer_before_start = layer_var;
    layer_var = Layer::latin;

    register_mods(modmask);

    is_active = true;
    mtype = tmode;
    #ifdef DEBUGGING
    Serial.print("Start modificator mode ");
    Serial.println(modmask);
    #endif
  }

  void start_quazi(uint16_t modmask, Layer::layer &layer_var) {
    layer_before_start = layer_var;
    layer_var = Layer::latin;
    quazi_thumb = 0;

    register_mods(modmask);

    is_active = true;
    mtype = tquazi;
    #ifdef DEBUGGING
    Serial.print("Start modificator quazimode ");
    Serial.println(modmask);
    #endif
  }

  void check_thumb(Layer::layer &layer_var, chord currc) {
    if (!is_active) return;
    if (tquazi == mtype) {
      switch (currc & 0b11) {
      case 0b10: quazi_thumb = 0b10; break;
      case 0b01: quazi_thumb = 0b01; break;
      default: stop(layer_var); break;
      }
    }
  }

  void modify_thumb_maybe(chord &currc) {
    if (!is_active) return;
    if (tquazi == mtype) {
      #ifdef DEBUGGING
      Serial.print("Modify thumb "); Serial.print(currc, BIN);
      #endif

      currc &=~ quazi_thumb;

      #ifdef DEBUGGING
      Serial.print(" to "); Serial.println(currc, BIN);
      #endif
    }
  }

  void stop_maybe(Layer::layer &layer_var, chord currc) {
    if (is_active &&
        (tquazi == mtype && currc & 0b11 == 0)) {
      is_active = false;
      stop(layer_var);
    }
  }
};
#endif
