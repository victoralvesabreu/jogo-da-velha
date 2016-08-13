ALLEGRO=-I/usr/include -L/usr/lib/x86_64-linux-gnu -lalleg
all: JogoDaVelha
JogoDaVelha: bin/libfunc.o bin/main.o
	gcc bin/libfunc.o bin/main.o -o JogoDaVelha $(ALLEGRO)
bin/libfunc.o: lib/libfunc.c
	gcc -o bin/libfunc.o -c lib/libfunc.c $(ALLEGRO)
bin/main.o: main.c
	gcc -o bin/main.o -c main.c $(ALLEGRO)
#bin/libfunch.o: lib/libfunc.h
#	gcc -o bin/libfunch.o -c lib/libfunc.h $(ALLEGRO)
clean:
	rm -rf bin/*.o
mrproper: clean
	rm -rf JogoDaVelha
