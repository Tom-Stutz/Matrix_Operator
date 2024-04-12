CFLAGS = -I. -MMD

all: main

test: all
	./main < test.txt

main: main.o matrix.o
	@echo "Linking the object files for main"
	gcc main.o matrix.o -o main

%.o: %.c
	@echo "Compiling $^ for $@"
	gcc $(CFLAGS) -c $^ 

clean:
	rm main.o matrix.o main *.d

-include *.d

