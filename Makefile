MAINSOURCE=src/ruinas.inf
INCLUDES=+lib,includes
COMPILEROPTS=+language_name=Portugues $(INCLUDES)

all: zcode

zcode:
	mkdir -p build
	inform $(COMPILEROPTS) $(MAINSOURCE)
	mv *.z5 build

run:
	fizmo-ncursesw -lm 1 -rm 1 -dh -xt build/ruinas.z5

clean:
	rm -rf build

