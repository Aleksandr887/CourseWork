bin/kurs: build/kurs.o
	gcc -Wall -o bin/kurs build/kurs.o

build/kurs.o: src/kurs.c
	gcc -Wall -c src/kurs.c -o build/kurs.o

clean:
	rm -rf build/kurs.o bin/kurs