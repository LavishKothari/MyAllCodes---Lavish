hello: GraphAdjacencyMatrix.o main.o
	gcc GraphAdjacencyMatrix.o main.o -o hello

GraphAdjacencyMatrix.o : GraphAdjacencyMatrix.c
	gcc -c GraphAdjacencyMatrix.c
	
main.o: main.c
	gcc -c main.c
	
clean:
	rm -rf *.o *~ hello
