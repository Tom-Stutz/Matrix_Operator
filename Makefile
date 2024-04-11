CFLAGS = -I /

all: main

main: main.o matrix.o
	@echo "Linking the object files for main"
	gcc $(CFLAGS) main.o matrix.o -o main

main.o: main.c
	@echo "Compiling main.c"
	gcc $(CFLAGS) -c main.c 

matrix.o: matrix.c
	@echo "Compiling matrix.c"
	gcc $(CFLAGS) -c matrix.c

clean:
	rm main.o matrix.o main
