bin/main: build/main.o build/func.o
	gcc -Wall -o bin/main build/main.o build/func.o

build/func.o: src/func.c src/func.h
	gcc -Wall -c src/func.c -o build/func.o

build/main.o: src/main.c src/func.h
	gcc -Wall -c src/main.c -o build/main.o

clean:
	rm -rf build/main.o bin/main