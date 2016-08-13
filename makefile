all: JogoDaVelha
JogoDaVelha: bin/libfunc.o bin/main.o
	gcc bin/libfunc.o bin/main.o -o JogoDaVelha -I/usr/include -L/usr/lib/x86_64-linux-gnu -lalleg 
bin/libfunc.o: lib/libfunc.c
	gcc -o bin/libfunc.o -c lib/libfunc.c 
bin/main.o: main.c
	gcc -o bin/main.o -c main.c $(allegro)
clean:
	rm -rf bin/*.o
mrproper: clean
	rm -rf JogoDaVelha
