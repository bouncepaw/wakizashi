require 'yaml'
require 'pp'

config = YAML.load(File.read('config.yml'))

class Chord
  attr_reader :thumb
  @fingers = ""
  @thumb = ""
  @action = ""
  def initialize(action)
    @action = action
  end

  def add_thumb(thumb)
    @thumb = thumb
    self
  end

  def add_fingers(fingers)
    @fingers = fingers
    self
  end

  def as_string
    <<-EOK
        case 0b#{@fingers}#{@thumb}: {
            #{@action}
            break;
        }
EOK
  end
end

class EmptyChord
  def initalize
  end

  def add_thumb(_)
    self
  end

  def add_fingers(_)
    self
  end

  def as_string
    ""
  end

  def thumb
    ""
  end
end

def _generic_mod(chords, thumb)
  chords.map { |chord| dochord(chord).add_thumb thumb }
end
def _normal  (chords); _generic_mod chords, "000"; end
def _shift   (chords); _generic_mod chords, "100"; end
def _symbol  (chords); _generic_mod chords, "010"; end
def _function(chords); _generic_mod chords, "001"; end
def _control (chords); _generic_mod chords, "110"; end
def _macro   (chords); _generic_mod chords, "011"; end


def iterate_generic_chord(bindings, init)
  buf = ""
  i = init
  bindings.each do |b|
    buf += yield b, i unless b == '_'
    i -= 1
  end
  buf
end

def to_top(e)
  e.to_s.rjust(4, "0") + "0000"
end

def to_bottom(e)
  "0000" + e.to_s.rjust(4, "0")
end
class String
  def downto8
    if self.length > 8
      self[0..7]
    else
      self
    end
  end

end

def _single(chords)
  iterate_generic_chord(chords, 10) do |c, i|
    if c.thumb == ""
      c.as_string
    elsif c.thumb == "000"
      c.add_thumb("").add_fingers("#{10 ** i}".rjust(11, "0")).as_string
    else
      c.add_fingers("#{10 ** (i - 3)}".rjust(8, "0")).as_string
    end

  end
end

def _vertical(chords)
  iterate_generic_chord(chords, 3) do |c, i|
    c.add_fingers("#{10**i}".rjust(4, "0") * 2).as_string
  end
end

def _double(chords)
  [(chords[0].add_fingers to_top 1100),
   (chords[1].add_fingers to_top 110),
   (chords[2].add_fingers to_top 11),
   (chords[3].add_fingers to_top 1001),
   (chords[4].add_fingers to_top 1010),
   (chords[5].add_fingers to_top 101),

   (chords[6].add_fingers to_bottom 1100),
   (chords[7].add_fingers to_bottom 110),
   (chords[8].add_fingers to_bottom 11),
   (chords[9].add_fingers to_bottom 1001),
   (chords[10].add_fingers to_bottom 1010),
   (chords[11].add_fingers to_bottom 101),
  ].map(&:as_string).join
end

def _triple(chords)
  [(chords[0].add_fingers to_top 1110),
   (chords[1].add_fingers to_top 1101),
   (chords[2].add_fingers to_top 111),
   (chords[3].add_fingers to_top 1011),

   (chords[4].add_fingers to_bottom 1110),
   (chords[5].add_fingers to_bottom 1101),
   (chords[6].add_fingers to_bottom 111),
   (chords[7].add_fingers to_bottom 1011),
  ].map(&:as_string).join
end

def _quadruple(chords)
  [(chords[0].add_fingers to_top 1111),
   (chords[1].add_fingers to_bottom 1111),
   (chords[2].add_fingers '1100' * 2),
   (chords[3].add_fingers '0110' * 2),
   (chords[4].add_fingers '0011' * 2),
   (chords[5].add_fingers '1001' * 2),
  ].map(&:as_string).join
end
def ind(text)
  " "*2 + text
end

def dochord(val)
  val = val.to_s if val.is_a? Numeric
  val = val.join if val.is_a? Array
  if val == '_'
    EmptyChord.new
  elsif val.start_with? 'mod_'
    action = "start_mod(" +
             val.
               split('_')[1..-1].
               map { |mod| mod.upcase }.
               join(' | ') +
             ");"
    Chord.new(action)
  elsif val.start_with? '_'
    action = "Keyboard.press(KEY#{val.upcase});\n" +
             " "*12 + "Keyboard.release(KEY#{val.upcase});"
    Chord.new(action)

  elsif val == '\\\\'
    Chord.new "Keyboard.print('\\\\');"
  elsif val == "'"
    Chord.new "Keyboard.print('\\'');"
  elsif val.length == 1
    Chord.new "Keyboard.print('#{val}');"
  else
    Chord.new "Keyboard.print(\"#{val}\");"
  end
end

puts <<-EOK
#ifndef LAYOUT_H
#define LAYOUT_H
/* #{config['name']}
 * generated by Timur Ismagilov's waki_gen.rb
 * on #{Time.now}
 *
 * https://github.com/bouncepaw/wakizashi
 */
void exec_chord(chord currc) {
  static layer currl = Llatin;
  currc = ~currc % (1 << 11);
  Serial.print("Execute chord ");
  debug_print(currc);

  switch (currl) {
EOK

config['layers'].each do |layer, groups|
  puts ind ind "case L#{layer}: {"
  puts ind ind ind "switch (currc) {"
  groups.each do |group, mods|
    mods.each do |mod, chords|
      puts eval "_#{group}(_#{mod}(#{chords}))"
    end

  end
  puts ind ind ind "}"
  puts ind ind ind "break;"
  puts ind ind "}"
end

puts <<-EOK
  }
}
#endif
EOK