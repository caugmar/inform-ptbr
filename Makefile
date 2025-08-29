MAINSOURCE=src/ruinas.inf
INCLUDES=+lib,includes
COMPILEROPTS=-Cu +language_name=Portugues $(INCLUDES)

all: zcode

zcode:
	mkdir -p build
	inform $(COMPILEROPTS) $(MAINSOURCE)
	mv *.z5 build

run:
	# fizmo-ncursesw -lm 1 -rm 1 -dh -xt build/ruinas.z5
	gargoyle-free build/ruinas.z5

parchment: zcode
	cp build/ruinas.z5 parchment-site/
	python3 -m http.server 

clean:
	rm -rf build

