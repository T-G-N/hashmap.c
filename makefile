CC = gcc
BIN = hashmap

all: $(BIN)
test: _test clean

_test:
	$(CC) test/main.c -o build/main
	build/main.exe

clean:
	rm build/*.o build/*.exe test/*.exe -f
