
INFORM ?= inform
INCLUDES ?= +./ ++../../lib ++../../includes
COMPILEROPTS ?= -Cu +language_name=Portugues $(INCLUDES)

.PHONY: all run clean

all: curses.z8

curses.z8: curses.inf $(wildcard *.inf) ../../includes/Portugues.h ../../includes/PortuguesG.h $(wildcard ../../lib/*.h)
	$(INFORM) -v8 -xr $(COMPILEROPTS) curses.inf curses.z8

run: curses.z8
	if [ -n "$(DISPLAY)" ] && command -v gargoyle-free >/dev/null 2>&1; then \
		gargoyle-free curses.z8 ; \
	else \
		fizmo-ncursesw -lm 1 -rm 1 -dh -xt curses.z8 ; \
	fi

clean:
	rm -f *.z8
