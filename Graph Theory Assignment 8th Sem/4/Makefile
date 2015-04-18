all: LinkedList_Generic.o Graph_AdjacencyList.o main.o queue.o
	gcc LinkedList_Generic.o Graph_AdjacencyList.o queue.o main.o -o hello
LinkedList_Generic.o: LinkedList_Generic.c
	gcc -c LinkedList_Generic.c
Graph_AdjacencyList.o: Graph_AdjacencyList.c
	gcc -c Graph_AdjacencyList.c
main.o: main.c
	gcc -c main.c
queue.o: queue.c
	gcc -c queue.c
clean :
	rm -rf *~ *.o hello
