MAINSOURCE=src/ruinas.inf
INCLUDES=+lib,includes
COMPILEROPTS=-Cu +language_name=Portugues $(INCLUDES)

all: ruinas.z5

ruinas.z5:
	inform $(COMPILEROPTS) $(MAINSOURCE)

run: ruinas.z5
	# fizmo-ncursesw -lm 1 -rm 1 -dh -xt build/ruinas.z5
	gargoyle-free ruinas.z5

parchment: zcode
	cp ruinas.z5 parchment-site/
	python3 -m http.server 

clean:
	rm -f ruinas.z5

