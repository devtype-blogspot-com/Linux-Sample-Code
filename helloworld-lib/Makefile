all: exe

exe:	hello.h main.c lib
	gcc main.c -fPIC -L. -lHello -o hello

lib:	hello.h hello.c
	gcc -shared hello.c -fPIC -o libHello.so

clean:
	-rm hello libHello.so 2>/dev/null

