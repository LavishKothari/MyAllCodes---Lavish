all: hello
hello: graph.o main.o
	gcc graph.o main.o -o hello
main.o: main.c
	gcc -c main.c
graph.o: graph.c
	gcc -c graph.c
