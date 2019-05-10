# coding: utf-8
require 'csv'
require 'pp'

def read_config()
  File.read(ARGV[0])
end

def remove_comments(file)
  file.gsub(/\/\/.*$/, '')
end

def parse_csv(file)
  CSV.parse(file,
            quote_char: "",
            col_sep: "\t",
            skip_blanks: true)
end

def complete_rows(table)
  table.map do |l|
    (l + Array.new(6 - l.length)).map do |el|
      if el == "    " then nil else el end
    end
  end
end

def but_first(table)
  table.drop 1
end

def group_by_two(ary)
  collecting_first = true
  buf = []
  subbuf = [nil, nil]
  ary.each do |l|
    if collecting_first
      buf << [l]
    else
      buf[-1] << l
    end
    collecting_first = !collecting_first
  end
  buf
end

def expand_pairs(table)
  buf = []
  table.each do |pair|
    if pair[1][0] == nil
      buf << [pair[0][0] + "0000"] + pair[0][1..-1] <<
        ["0000" + pair[0][0]] + pair[1][1..-1]
    else
      buf << [pair[0][0] + pair[1][0]] + pair[0][1..-1]
    end
  end
  buf
end

def convert_to_actions(table)
  def type(str)
    "  Keyboard.press(#{str});\n" +
      "  Keyboard.release(#{str});"
  end
  table.map do |line|
    [line[0]] + line[1..-1].map do |val|
      if val == nil
        val
      elsif val == 'mod_stop'
        "  modif.stop(Layer::curr);"
      elsif val.start_with? 'mod_'
        "  modif.start_mode(" +
          val.
            split('_')[1..-1].
            map { |mod| "Mod::" + mod }.
            join(' | ') +
          ", Layer::curr);"
      elsif val == '_'
        type "'_'"
      elsif val.start_with? '_'
        "  Keyboard.press(KEY#{val.upcase});\n" +
          "  Keyboard.release(KEY#{val.upcase});"
      elsif val == '\\'
        type "'\\'"
      elsif val == "'"
        type "'\\''"
      elsif val.length == 1
        type "'#{val}'"
      else
        "  Keyboard.print(\"#{val}\");"
      end
    end
  end
end

def wrap_in_case(table)
  def cage(action, thumb)
    if action == nil
      nil
    else
      "#{thumb}: {\n#{action}\n  break;\n}"
    end
  end
  table.map do |line|
    [line[0],
     cage(line[1], "000"),
     cage(line[2], "100"),
     cage(line[3], "010"),
     cage(line[4], "001"),
     cage(line[5], "011")]
  end
end

def apply_fingers(table)
  def apply_finger(finger, rest)
    if rest == nil
      nil
    else
      "case 0b" + finger + rest
    end
  end
  table.map do |line|
    line[1..-1].map do |el|
      apply_finger line[0], el
    end
  end
end

puts "case Layer::#{File.basename ARGV[0], '.csv'}: {"
puts "  switch (currc) {"
puts (apply_fingers \
        wrap_in_case \
        convert_to_actions \
        expand_pairs \
        group_by_two \
        but_first \
        complete_rows \
        parse_csv \
        remove_comments \
        read_config).join("\n")
puts "  }"
puts "}"
