
all : Balances.z8

Balances.z8 : *.inf
	inform -v8 -xr Balances.inf Balances.z8

run: Balances.z8
	if [ -n "$(DISPLAY)" ]; then \
		gargoyle-free Balances.z8 ; \
	else \
		fizmo-ncursesw -lm 1 -rm 1 -dh -xt Balances.z8 ; \
	fi


clean:
	rm *.z8
