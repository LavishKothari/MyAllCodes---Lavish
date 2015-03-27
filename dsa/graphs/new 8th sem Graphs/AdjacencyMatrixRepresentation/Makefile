all: hello
hello: queue.o matrix.o graph.o main.o
	gcc queue.o matrix.o graph.o main.o -o hello
queue.o: queue.c
	gcc -c queue.c
matrix.o: matrix.c
	gcc -c matrix.c
main.o: main.c
	gcc -c main.c
graph.o: graph.c
	gcc -c graph.c
