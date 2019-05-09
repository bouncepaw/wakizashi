#ifndef MOD_H
#define MOD_H
#define DEBUGGING 1
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
  bool in_ctrl;
  Layer::layer layer_before_start;
  Layer::layer layer_before_start_ctrl;
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
    #ifdef DEBUGGING
    Serial.print("Start modificator mode ");
    Serial.println(modmask);
    #endif
  }

  void start_ctrl_maybe(Layer::layer &layer_var, chord &currc) {
    if ((currc & 0b110) == 0b110) {
      layer_before_start_ctrl = layer_var;
      layer_var = Layer::latin;
      currc &=~ 0b110;

      Keyboard.press(KEY_LEFT_CTRL);
      #ifdef DEBUGGING
      Serial.println("This chord will be sent with left ctrl.");
      #endif
      in_ctrl = true;
    }
  }

  void stop_ctrl_maybe(Layer::layer &layer_var) {
    if (in_ctrl) {
      layer_var = layer_before_start_ctrl;
      Keyboard.release(KEY_LEFT_CTRL);
      in_ctrl = false;
    }
  }
};
#endif
