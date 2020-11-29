DEPS=zad8.o norm.o wczytaj.o wypisz.o zapisz.o zwolniej.o
zad: $(DEPS)
	cc $(DEPS) -o $@ -Wall --pedantic

%.o:%.c
	cc -c $^ -o $@
clean:
	rm -f zad
	rm -f *.o