NAME=Wakizashi Default Bilingual

gen:
	@ruby genlayout.rb start "${NAME}"
	@ruby -Ku make_layer.rb latin.csv
	@ruby -Ku make_layer.rb cyrillic.csv
	@ruby genlayout.rb end

save:
	@ruby genlayout.rb start "${NAME}" > layout.h
	@ruby -Ku make_layer.rb latin.csv >> layout.h
	@ruby -Ku make_layer.rb cyrillic.csv >> layout.h
	@ruby genlayout.rb end >> layout.h
