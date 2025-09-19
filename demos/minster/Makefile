all : minster.z8

minster.z8 : minster.inf prologue.inf first.inf library.inf edward.inf gardens.inf second.inf alchemy.inf endgame.inf help.inf
	inform -v8 -xr minster minster.z8

run: minster.z8
	if [ -n "$(DISPLAY)" ]; then \
		gargoyle-free minster.z8 ; \
	else \
		fizmo-ncursesw -lm 1 -rm 1 -dh -xt minster.z8 ; \
	fi

clean:
	rm *.z8

