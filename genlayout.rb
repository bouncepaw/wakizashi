if ARGV[0] == 'start'
  puts <<-EOK
#ifndef LAYOUT_H
#define LAYOUT_H
/* #{ARGV[1]}
 * generated by Timur Ismagilov's waki_gen.rb
 * on #{Time.now}
 *
 * https://github.com/bouncepaw/wakizashi
 */
Modif modif;
void exec_chord(chord currc) {
  currc = ~currc % (1 << 11);
  Serial.print("Execute chord ");
  debug_print(currc);

  modif.start_ctrl_maybe(currc);
  modif.check_1();
  switch (Layer::curr) {
EOK
else
  puts <<-EOK
  }

  modif.stop_ctrl_maybe();
  modif.stop_1_maybe();
}
#endif
EOK
end
