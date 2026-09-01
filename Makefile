MAINSOURCE=src/ruinas.inf
INCLUDES=+lib,includes
COMPILEROPTS=-Cu +language_name=Portugues $(INCLUDES)

all: ruinas.z5

ruinas.z5: $(MAINSOURCE) $(wildcard includes/*.h) $(wildcard lib/*.h)
	inform $(COMPILEROPTS) $(MAINSOURCE)

run: ruinas.z5
	if [ -n "$(DISPLAY)" ]; then \
		gargoyle-free ruinas.z5 ; \
	else \
		fizmo-ncursesw -lm 1 -rm 1 -dh -xt ruinas.z5 ; \
	fi

replay: ruinas.z5
	{ printf ' \n'; while IFS= read -r command; do printf '%s\n' "$$command"; done < "transcrição-vitoria-replay.txt"; } | dfrotz -m -p -q ruinas.z5

parchment: parchment-site/ruinas.z5
	python3 -m http.server --directory parchment-site

parchment-site/ruinas.z5: ruinas.z5
	cp ruinas.z5 parchment-site/

clean:
	rm -f ruinas.z5 parchment-site/ruinas.z5
