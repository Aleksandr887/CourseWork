.PHONY: all run test clean

all: bin/main bin-test/test-kurs

bin/main: build/main.o build/func.o
	gcc -Wall -o bin/main build/main.o build/func.o

bin-test/test-kurs: build-test/main.o build-test/test-kurs.o build/func.o
	gcc -Wall -o bin-test/test-kurs build-test/main.o build-test/test-kurs.o build/func.o

build-test/main.o: test/main.c src/func.h thirdparty/ctest.h
	gcc -Wall -I thirdparty -c test/main.c -o build-test/main.o

build-test/test-kurs.o: test/test-kurs.c src/func.h thirdparty/ctest.h
	gcc -Wall -I thirdparty -I src -c test/test-kurs.c -o build-test/test-kurs.o

build/func.o: src/func.c src/func.h
	gcc -Wall -c src/func.c -o build/func.o

build/main.o: src/main.c src/func.h
	gcc -Wall -c src/main.c -o build/main.o

run:
	cd bin && clear && ./main

test:
	cd bin-test && clear && ./test-kurs

clean:
	rm -rf build/main.o bin/main build/func.o build-test/test-kurs.o build-test/main.o bin-test/test-kurs
