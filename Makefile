MAINSOURCE=src/ruinas.inf
INCLUDES=+lib,includes
COMPILEROPTS=+language_name=Portugues $(INCLUDES)
ZCODE2JS=python tools/zcode2js.py

all: zcode

zcode:
	mkdir -p build
	inform $(COMPILEROPTS) $(MAINSOURCE)
	python tools/zcode2js.py ruinas.z5 > ruinas.z5.js
	mv *.z5 build
	mv *.js build
	cp -rv template/* build

run:
	fizmo-ncursesw -lm 1 -rm 1 -dh -xt build/ruinas.z5

webrun:
	firefox build/index.html &

clean:
	rm -rf build

