#ifndef LAYOUT_H
#define LAYOUT_H
/* Wakizashi Default Latin+Cyrillic
 * generated by Timur Ismagilov's waki_gen.rb
 * on 2019-05-09 21:29:19 +0500
 *
 * https://github.com/bouncepaw/wakizashi
 */
Modif modif;
void exec_chord(chord currc) {
  currc = ~currc % (1 << 11);
  Serial.print("Execute chord ");
  debug_print(currc);

  modif.start_ctrl_maybe(Layer::curr, currc);
  switch (Layer::curr) {
    case Layer::latin: {
      switch (currc) {
        case 0b10000000000: {
            Keyboard.press('o');
            Keyboard.release('o');
            break;
        }
        case 0b01000000000: {
            Keyboard.press('a');
            Keyboard.release('a');
            break;
        }
        case 0b00100000000: {
            Keyboard.press('p');
            Keyboard.release('p');
            break;
        }
        case 0b00010000000: {
            Keyboard.press('e');
            Keyboard.release('e');
            break;
        }
        case 0b00001000000: {
            Keyboard.press('h');
            Keyboard.release('h');
            break;
        }
        case 0b00000100000: {
            Keyboard.press('s');
            Keyboard.release('s');
            break;
        }
        case 0b00000010000: {
            Keyboard.press('n');
            Keyboard.release('n');
            break;
        }
        case 0b00000001000: {
            Keyboard.press('i');
            Keyboard.release('i');
            break;
        }
        case 0b00000000100: {
            Keyboard.press(' ');
            Keyboard.release(' ');
            break;
        }
        case 0b00000000010: {
            Keyboard.press(',');
            Keyboard.release(',');
            break;
        }
        case 0b00000000001: {
            Keyboard.press('.');
            Keyboard.release('.');
            break;
        }
        case 0b10000000100: {
            Keyboard.press('O');
            Keyboard.release('O');
            break;
        }
        case 0b01000000100: {
            Keyboard.press('A');
            Keyboard.release('A');
            break;
        }
        case 0b00100000100: {
            Keyboard.press('P');
            Keyboard.release('P');
            break;
        }
        case 0b00010000100: {
            Keyboard.press('E');
            Keyboard.release('E');
            break;
        }
        case 0b00001000100: {
            Keyboard.press('H');
            Keyboard.release('H');
            break;
        }
        case 0b00000100100: {
            Keyboard.press('S');
            Keyboard.release('S');
            break;
        }
        case 0b00000010100: {
            Keyboard.press('N');
            Keyboard.release('N');
            break;
        }
        case 0b00000001100: {
            Keyboard.press('I');
            Keyboard.release('I');
            break;
        }
        case 0b10000000010: {
            Keyboard.press('8');
            Keyboard.release('8');
            break;
        }
        case 0b01000000010: {
            Keyboard.press('4');
            Keyboard.release('4');
            break;
        }
        case 0b00100000010: {
            Keyboard.press('2');
            Keyboard.release('2');
            break;
        }
        case 0b00010000010: {
            Keyboard.press('1');
            Keyboard.release('1');
            break;
        }
        case 0b00001000010: {
            Keyboard.press(':');
            Keyboard.release(':');
            break;
        }
        case 0b00000100010: {
            Keyboard.press('"');
            Keyboard.release('"');
            break;
        }
        case 0b00000010010: {
            Keyboard.press('\'');
            Keyboard.release('\'');
            break;
        }
        case 0b00000001010: {
            Keyboard.press(';');
            Keyboard.release(';');
            break;
        }
        case 0b10000000001: {
            modif.start_mode(Mod::ctrl, Layer::curr);
            break;
        }
        case 0b01000000001: {
            modif.start_mode(Mod::altl, Layer::curr);
            break;
        }
        case 0b00100000001: {
            modif.start_mode(Mod::shift, Layer::curr);
            break;
        }
        case 0b00010000001: {
            modif.start_mode(Mod::super, Layer::curr);
            break;
        }
        case 0b00001000001: {
            Keyboard.press(KEY_LEFT_ARROW);
            Keyboard.release(KEY_LEFT_ARROW);
            break;
        }
        case 0b00000100001: {
            Keyboard.press(KEY_DOWN_ARROW);
            Keyboard.release(KEY_DOWN_ARROW);
            break;
        }
        case 0b00000010001: {
            Keyboard.press(KEY_UP_ARROW);
            Keyboard.release(KEY_UP_ARROW);
            break;
        }
        case 0b00000001001: {
            Keyboard.press(KEY_RIGHT_ARROW);
            Keyboard.release(KEY_RIGHT_ARROW);
            break;
        }
        case 0b00001000011: {
            Keyboard.print("a ");
            break;
        }
        case 0b00000100011: {
            Keyboard.print("in ");
            break;
        }
        case 0b00000010011: {
            Keyboard.print("that ");
            break;
        }
        case 0b00000001011: {
            Keyboard.print("be ");
            break;
        }
        case 0b10001000000: {
            Keyboard.press('r');
            Keyboard.release('r');
            break;
        }
        case 0b01000100000: {
            Keyboard.press('l');
            Keyboard.release('l');
            break;
        }
        case 0b00100010000: {
            Keyboard.press('d');
            Keyboard.release('d');
            break;
        }
        case 0b00010001000: {
            Keyboard.press('u');
            Keyboard.release('u');
            break;
        }
        case 0b10001000100: {
            Keyboard.press('R');
            Keyboard.release('R');
            break;
        }
        case 0b01000100100: {
            Keyboard.press('L');
            Keyboard.release('L');
            break;
        }
        case 0b00100010100: {
            Keyboard.press('D');
            Keyboard.release('D');
            break;
        }
        case 0b00010001100: {
            Keyboard.press('U');
            Keyboard.release('U');
            break;
        }
        case 0b10001000010: {
            Keyboard.press('-');
            Keyboard.release('-');
            break;
        }
        case 0b00100010010: {
            Keyboard.press('(');
            Keyboard.release('(');
            break;
        }
        case 0b00010001010: {
            Keyboard.press(')');
            Keyboard.release(')');
            break;
        }
        case 0b10001000001: {
            Keyboard.press(KEY_PAGE_DOWN);
            Keyboard.release(KEY_PAGE_DOWN);
            break;
        }
        case 0b01000100001: {
            Keyboard.press(KEY_PAGE_UP);
            Keyboard.release(KEY_PAGE_UP);
            break;
        }
        case 0b00100010001: {
            Keyboard.press(KEY_TAB);
            Keyboard.release(KEY_TAB);
            break;
        }
        case 0b00010001001: {
            Keyboard.press(KEY_ESC);
            Keyboard.release(KEY_ESC);
            break;
        }


        case 0b11000000000: {
            Keyboard.print("th");
            break;
        }
        case 0b01100000000: {
            Keyboard.press('c');
            Keyboard.release('c');
            break;
        }
        case 0b00110000000: {
            Keyboard.press('m');
            Keyboard.release('m');
            break;
        }
        case 0b10010000000: {
            Keyboard.press('w');
            Keyboard.release('w');
            break;
        }
        case 0b10100000000: {
            Keyboard.press('[');
            Keyboard.release('[');
            break;
        }
        case 0b01010000000: {
            Keyboard.press(']');
            Keyboard.release(']');
            break;
        }
        case 0b00001100000: {
            Keyboard.press('y');
            Keyboard.release('y');
            break;
        }
        case 0b00000110000: {
            Keyboard.press('f');
            Keyboard.release('f');
            break;
        }
        case 0b00000011000: {
            Keyboard.press('g');
            Keyboard.release('g');
            break;
        }
        case 0b00001001000: {
            Keyboard.press('t');
            Keyboard.release('t');
            break;
        }
        case 0b00001010000: {
            Keyboard.press('{');
            Keyboard.release('{');
            break;
        }
        case 0b00000101000: {
            Keyboard.press('}');
            Keyboard.release('}');
            break;
        }
        case 0b11000000100: {
            Keyboard.print("Th");
            break;
        }
        case 0b01100000100: {
            Keyboard.press('C');
            Keyboard.release('C');
            break;
        }
        case 0b00110000100: {
            Keyboard.press('M');
            Keyboard.release('M');
            break;
        }
        case 0b10010000100: {
            Keyboard.press('W');
            Keyboard.release('W');
            break;
        }
        case 0b10100000100: {
            Keyboard.press('<');
            Keyboard.release('<');
            break;
        }
        case 0b01010000100: {
            Keyboard.press('>');
            Keyboard.release('>');
            break;
        }
        case 0b00001100100: {
            Keyboard.press('Y');
            Keyboard.release('Y');
            break;
        }
        case 0b00000110100: {
            Keyboard.press('F');
            Keyboard.release('F');
            break;
        }
        case 0b00000011100: {
            Keyboard.press('G');
            Keyboard.release('G');
            break;
        }
        case 0b00001001100: {
            Keyboard.press('T');
            Keyboard.release('T');
            break;
        }
        case 0b00001010100: {
            Keyboard.press('~');
            Keyboard.release('~');
            break;
        }
        case 0b00000101100: {
            Keyboard.press('`');
            Keyboard.release('`');
            break;
        }
        case 0b11000000010: {
            Keyboard.press('!');
            Keyboard.release('!');
            break;
        }
        case 0b01100000010: {
            Keyboard.press('6');
            Keyboard.release('6');
            break;
        }
        case 0b00110000010: {
            Keyboard.press('3');
            Keyboard.release('3');
            break;
        }
        case 0b10010000010: {
            Keyboard.press('9');
            Keyboard.release('9');
            break;
        }
        case 0b10100000010: {
            Keyboard.press('+');
            Keyboard.release('+');
            break;
        }
        case 0b01010000010: {
            Keyboard.press('0');
            Keyboard.release('0');
            break;
        }
        case 0b00001100010: {
            Keyboard.press('{');
            Keyboard.release('{');
            break;
        }
        case 0b00000110010: {
            Keyboard.press('}');
            Keyboard.release('}');
            break;
        }
        case 0b00000011010: {
            Keyboard.press('/');
            Keyboard.release('/');
            break;
        }
        case 0b00001001010: {
            Keyboard.press('\\');
            Keyboard.release('\\');
            break;
        }
        case 0b00001010010: {
            Keyboard.press('*');
            Keyboard.release('*');
            break;
        }
        case 0b11000000011: {
            Keyboard.print("the ");
            break;
        }
        case 0b01100000011: {
            Keyboard.print("you ");
            break;
        }
        case 0b00110000011: {
            Keyboard.print("we ");
            break;
        }
        case 0b10010000011: {
            Keyboard.print("they ");
            break;
        }
        case 0b10100000011: {
            Keyboard.print("he");
            break;
        }
        case 0b01010000011: {
            Keyboard.print("she");
            break;
        }
        case 0b00001100011: {
            Keyboard.print("I ");
            break;
        }
        case 0b00000110011: {
            Keyboard.print("are ");
            break;
        }
        case 0b00000011011: {
            Keyboard.print("is ");
            break;
        }
        case 0b00001001011: {
            Keyboard.print("it ");
            break;
        }
        case 0b00001010011: {
            Keyboard.print("an ");
            break;
        }
        case 0b00000101011: {
            Keyboard.print("a ");
            break;
        }
        case 0b11100000000: {
            Keyboard.press('b');
            Keyboard.release('b');
            break;
        }
        case 0b11010000000: {
            Keyboard.press('v');
            Keyboard.release('v');
            break;
        }
        case 0b01110000000: {
            Keyboard.press('k');
            Keyboard.release('k');
            break;
        }
        case 0b10110000000: {
            Keyboard.press('j');
            Keyboard.release('j');
            break;
        }
        case 0b00001110000: {
            Keyboard.press('x');
            Keyboard.release('x');
            break;
        }
        case 0b00001101000: {
            Keyboard.press('q');
            Keyboard.release('q');
            break;
        }
        case 0b00000111000: {
            Keyboard.press('z');
            Keyboard.release('z');
            break;
        }
        case 0b11100000100: {
            Keyboard.press('B');
            Keyboard.release('B');
            break;
        }
        case 0b11010000100: {
            Keyboard.press('V');
            Keyboard.release('V');
            break;
        }
        case 0b01110000100: {
            Keyboard.press('K');
            Keyboard.release('K');
            break;
        }
        case 0b10110000100: {
            Keyboard.press('J');
            Keyboard.release('J');
            break;
        }
        case 0b00001110100: {
            Keyboard.press('X');
            Keyboard.release('X');
            break;
        }
        case 0b00001101100: {
            Keyboard.press('Q');
            Keyboard.release('Q');
            break;
        }
        case 0b00000111100: {
            Keyboard.press('Z');
            Keyboard.release('Z');
            break;
        }
        case 0b11100000010: {
            Keyboard.press('#');
            Keyboard.release('#');
            break;
        }
        case 0b11010000010: {
            Keyboard.press('|');
            Keyboard.release('|');
            break;
        }
        case 0b01110000010: {
            Keyboard.press('?');
            Keyboard.release('?');
            break;
        }
        case 0b10110000010: {
            Keyboard.press('=');
            Keyboard.release('=');
            break;
        }
        case 0b11110000000: {
            modif.stop(Layer::curr);
            break;
        }
        case 0b11001100000: {
            Keyboard.press('^');
            Keyboard.release('^');
            break;
        }
        case 0b01100110000: {
            Keyboard.press('%');
            Keyboard.release('%');
            break;
        }
        case 0b00110011000: {
            Keyboard.press('&');
            Keyboard.release('&');
            break;
        }
        case 0b10011001000: {
            Keyboard.press('@');
            Keyboard.release('@');
            break;
        }
      }

      break;
    }
  }

  modif.stop_ctrl_maybe(Layer::curr);
}
#endif
