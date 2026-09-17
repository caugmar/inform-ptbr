INFORM ?= inform
INCLUDES ?= +./ ++../../lib ++../../includes
COMPILEROPTS ?= -Cu +language_name=Portugues $(INCLUDES)

.PHONY: all run clean

all: minster.z8

minster.z8: minster.inf $(wildcard *.inf) ../../includes/Portugues.h ../../includes/PortuguesG.h $(wildcard ../../lib/*.h)
	$(INFORM) -v8 -xr $(COMPILEROPTS) minster.inf minster.z8

run: minster.z8
	if [ -n "$(DISPLAY)" ] && command -v gargoyle-free >/dev/null 2>&1; then \
		gargoyle-free minster.z8 ; \
	else \
		fizmo-ncursesw -lm 1 -rm 1 -dh -xt minster.z8 ; \
	fi

clean:
	rm -f *.z8
