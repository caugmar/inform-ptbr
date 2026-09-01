MAINSOURCE=src/ruinas.inf
INCLUDES=+lib,includes
COMPILEROPTS=-Cu +language_name=Portugues $(INCLUDES)

all: ruinas.z5 parchment-site/ruinas.z5

ruinas.z5: $(MAINSOURCE) $(wildcard includes/*.h) $(wildcard lib/*.h)
	inform $(COMPILEROPTS) $(MAINSOURCE)

run: ruinas.z5
	if [ -n "$(DISPLAY)" ]; then \
		gargoyle-free ruinas.z5 ; \
	else \
		fizmo-ncursesw -lm 1 -rm 1 -dh -xt ruinas.z5 ; \
	fi

replay: ruinas.z5
	@tmp=$$(mktemp); \
	trap 'rm -f "$$tmp"' EXIT HUP INT TERM; \
	{ printf ' \n'; while IFS= read -r command; do printf '%s\n' "$$command"; done < "transcrição-vitoria-replay.txt"; } | dfrotz -m -p -q ruinas.z5 > "$$tmp"; \
	status=$$?; \
	cat "$$tmp"; \
	if [ "$$status" -ne 0 ]; then exit "$$status"; fi; \
	if ! grep -Fq 'Nesse jogo você marcou 30 de um total de 30' "$$tmp"; then \
		printf '%s\n' 'Replay não atingiu a pontuação final esperada.' >&2; \
		exit 1; \
	fi

parchment: parchment-site/ruinas.z5
	python3 -m http.server --directory parchment-site

parchment-site/ruinas.z5: ruinas.z5
	cp ruinas.z5 parchment-site/

clean:
	rm -f ruinas.z5
