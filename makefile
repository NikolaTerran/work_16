all: main.c
	gcc main.c

clean:
	rm *.o

run:
	./a.out
