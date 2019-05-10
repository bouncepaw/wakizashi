NAME=Wakizashi Default Bilingual

gen:
	@ruby genlayout.rb start "${NAME}"
	@ruby make_layer.rb latin.csv
	@ruby genlayout.rb end

save:
	@ruby genlayout.rb start "${NAME}" > layout.h
	@ruby make_layer.rb latin.csv >> layout.h
	@ruby genlayout.rb end >> layout.h
