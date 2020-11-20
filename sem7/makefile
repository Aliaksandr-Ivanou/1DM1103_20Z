DEPS=zad5.o studenci.o dziekanat.o
p7_3: $(DEPS)
	cc $(DEPS) -o $@ -Wall --pedantic

%.o:%.c
	cc -c $^ -o $@
clean:
	rm -f p7_3
	rm -f *.o