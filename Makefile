MAINSOURCE=src/ruinas.inf
INCLUDES=+lib,includes
COMPILEROPTS=-Cu +language_name=Portugues $(INCLUDES)

all: ruinas.z5

ruinas.z5:
	inform $(COMPILEROPTS) $(MAINSOURCE)

run: ruinas.z5
	if [ -n "$(DISPLAY)" ]; then \
		gargoyle-free ruinas.z5 ; \
	else \
		fizmo-ncursesw -lm 1 -rm 1 -dh -xt ruinas.z5 ; \
	fi

parchment: zcode
	cp ruinas.z5 parchment-site/
	python3 -m http.server 

clean:
	rm -f ruinas.z5

