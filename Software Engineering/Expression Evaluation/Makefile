all: hello
hello: main.o solveExpression.o LinkedList.o LinkedListStack.o
	gcc main.o solveExpression.o LinkedList.o LinkedListStack.o -o hello
main.o: main.c
	gcc -c main.c
evaluateExpression.o: solveExpression.c
	gcc -c solveExpression.c
LinkedList.o: LinkedList.c
	gcc -c LinkedList.c
LinkedListStack.o: LinkedListStack.c
	gcc -c LinkedListStack.c
