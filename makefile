ALLEGRO=-I/usr/include -L/usr/lib/x86_64-linux-gnu -lalleg
all: JogoDaVelha
JogoDaVelha: bin/libfunc.o bin/main.o
	gcc bin/libfunc.o bin/main.o -o JogoDaVelha $(ALLEGRO) 
bin/libfunc.o: lib/libfunc.c
	gcc -o bin/libfunc.o -c lib/libfunc.c 
bin/main.o: main.c
	gcc -o bin/main.o -c main.c $(ALLEGRO)
clean:
	rm -rf bin/*.o
mrproper: clean
	rm -rf JogoDaVelha
