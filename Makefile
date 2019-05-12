NAME=Wakizashi Default Bilingual
ARDUINO=/Applications/Arduino.app/Contents/MacOS/Arduino

flash: layout
	${ARDUINO} --upload wakizashi.ino

layout:
	ruby genlayout.rb start "${NAME}" > layout.h
	ruby -Ku make_layer.rb latin.csv >> layout.h
	ruby -Ku make_layer.rb cyrillic.csv >> layout.h
	ruby genlayout.rb end >> layout.h
