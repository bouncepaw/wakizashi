CONFIG=config.yml
LAYOUT_BUILDER=ruby waki_gen.rb
LAYOUT_H=layout.h
show_config:
	cat ${CONFIG}

build_layout:
	${LAYOUT_BUILDER} ${CONFIG} > ${LAYOUT_H}
