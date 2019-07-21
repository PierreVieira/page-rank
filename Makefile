CFLAGS=-Wall -g

main: src/graph.o src/arrays.o

clean: 
	rm -f main src/*.o