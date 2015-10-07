all : test.o kthSmallest.o
	g++ test.o kthSmallest.o -o executable
test.o : test.cpp
	g++ -c test.cpp
kthSmallest.o : kthSmallest.cpp
	g++ -c kthSmallest.cpp
clean :
	rm -rf *~ *.o executable
