
all : Balances.z8

Balances.z8 : *.inf
	inform -v8 -xr Balances.inf Balances.z8

run: Balances.z8
	gargoyle-free Balances.z8

clean:
	rm *.z8
