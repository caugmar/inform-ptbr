
all : curses.z8

curses.z8 : *.inf
	inform -v8 -xr curses.inf curses.z8

run: curses.z8
	if [ -n "$(DISPLAY)" ]; then \
		gargoyle-free curses.z8 ; \
	else \
		fizmo-ncursesw -lm 1 -rm 1 -dh -xt curses.z8 ; \
	fi

clean:
	rm *.z8
