CC=gcc
AS=nasm
OBJ=hello hook.so

.PHONY: all clean

all: $(OBJ)

hello: hello.c
	$(CC) -o hello hello.c

hook.so: hook.c
	$(CC) -o hook.so -fPIC -shared -D_GNU_SOURCE hook.c -ldl

clean:
	rm -f $(OBJ)

