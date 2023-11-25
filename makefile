CC = gcc
BIN = hashmap

all: $(BIN)
test: _test clean

hashmap:
	$(CC) hashmap.c -c -o build/hashmap.o

_test: hashmap
	$(CC) test/main.c -o build/main build/hashmap.o
	build/main.exe

clean:
	rm build/*.o build/*.exe -f
