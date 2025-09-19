
all : house.z5

house.z5 : *.inf
	inform house.inf

run: house.z5
	if [ -n "$(DISPLAY)" ]; then \
		gargoyle-free house.z5 ; \
	else \
		fizmo-ncursesw -lm 1 -rm 1 -dh -xt house.z5 ; \
	fi

clean:
	rm *.z5
