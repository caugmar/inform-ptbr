MAINSOURCE=src/ruinas.inf
INCLUDES=+lib,includes
COMPILEROPTS=-Cu +language_name=Portugues $(INCLUDES)
INFORM ?= inform
DFROTZ ?= dfrotz
PYTHON ?= python3
GARGOYLE ?= gargoyle-free
FIZMO ?= fizmo-ncursesw
PARCHMENT_URL ?= http://0.0.0.0:8000

.PHONY: all run replay parchment test clean

all: ruinas.z5 parchment-site/ruinas.z5

ruinas.z5: $(MAINSOURCE) $(wildcard includes/*.h) $(wildcard lib/*.h)
	$(INFORM) $(COMPILEROPTS) $(MAINSOURCE)

run: ruinas.z5
	if [ -n "$(DISPLAY)" ] && command -v "$(GARGOYLE)" >/dev/null 2>&1; then \
		$(GARGOYLE) ruinas.z5 ; \
	else \
		$(FIZMO) -lm 1 -rm 1 -dh -xt ruinas.z5 ; \
	fi

replay: ruinas.z5
	@tmp=$$(mktemp); \
	trap 'rm -f "$$tmp"' EXIT HUP INT TERM; \
	{ printf ' \n'; while IFS= read -r command; do printf '%s\n' "$$command"; done < "transcrição-vitoria-replay.txt"; } | $(DFROTZ) -m -p -q ruinas.z5 > "$$tmp"; \
	status=$$?; \
	cat "$$tmp"; \
	if [ "$$status" -ne 0 ]; then exit "$$status"; fi; \
	if ! grep -Fq 'Nesse jogo você marcou 30 de um total de 30' "$$tmp"; then \
		printf '%s\n' 'Replay não atingiu a pontuação final esperada.' >&2; \
		exit 1; \
	fi

parchment: parchment-site/ruinas.z5
	$(PYTHON) -m http.server --directory parchment-site & \
	server_pid=$$!; \
	sleep 1; \
	if command -v xdg-open >/dev/null 2>&1; then \
		xdg-open "$(PARCHMENT_URL)" >/dev/null 2>&1 & \
	elif command -v open >/dev/null 2>&1; then \
		open "$(PARCHMENT_URL)" >/dev/null 2>&1 & \
	fi; \
	wait $$server_pid

parchment-site/ruinas.z5: ruinas.z5
	cp ruinas.z5 parchment-site/

test: replay
	@tmp=$$(mktemp); \
	trap 'rm -f "$$tmp"' EXIT HUP INT TERM; \
	{ printf ' \n'; while IFS= read -r command; do printf '%s\n' "$$command"; done < "tests/score-regression.txt"; } | $(DFROTZ) -m -p -q ruinas.z5 > "$$tmp"; \
	status=$$?; \
	cat "$$tmp"; \
	if [ "$$status" -ne 0 ]; then exit "$$status"; fi; \
	if ! grep -Fq 'Você marcou até agora 5 de um total de 30' "$$tmp"; then \
		printf '%s\n' 'Teste de regressão da pontuação falhou.' >&2; \
		exit 1; \
	fi; \
	if grep -Fq 'Nesse jogo você marcou 30 de um total de 30' "$$tmp"; then \
		printf '%s\n' 'Teste de regressão permitiu vitória com um único artefato.' >&2; \
		exit 1; \
	fi

clean:
	rm -f ruinas.z5
