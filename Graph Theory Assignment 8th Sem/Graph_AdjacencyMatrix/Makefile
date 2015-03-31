all: hello
hello: one_D_bit_array.o two_D_bit_array.o Graph_AdjacencyMatrix.o main.o
	gcc one_D_bit_array.o two_D_bit_array.o Graph_AdjacencyMatrix.o main.o -o hello
one_D_bit_array.o: one_D_bit_array.c
	gcc -c one_D_bit_array.c
two_D_bit_array.o: two_D_bit_array.c
	gcc -c two_D_bit_array.c
main.o: main.c
	gcc -c main.c
graph.o: Graph_AdjacencyMatrix.c
	gcc -c Graph_AdjacencyMatrix.c
