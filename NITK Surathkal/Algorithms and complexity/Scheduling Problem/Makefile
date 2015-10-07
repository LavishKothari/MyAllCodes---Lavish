all : test.o sequential_sched.o
	gcc test.o sequential_sched.o -o executable
test.o : test.c
	gcc -c test.c
sequential_sched.o : sequential_sched.c
	gcc -c sequential_sched.c
clean :
	rm -rf *~ *.o executable
