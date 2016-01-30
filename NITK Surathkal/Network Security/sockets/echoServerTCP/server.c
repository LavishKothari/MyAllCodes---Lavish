/*
	This program demonstrate the concurrent server
	using multiplexing select system call.
	
	the 0th argument will be executable file's name
	First argument : Timeout
	all other following arguments will be the port numbers on which server is serving.
*/
#include<sys/socket.h>
#include<stdio.h>
#include<netinet/in.h>
#include<string.h>
int main(int argc,char*argv[])
{
	long long int timeout;
	int number_of_ports;
	if(argc<3)
	{
		printf("Not sufficient number of arguments.\n");
		return 1;
	}
	timeout=atoi(argv[1]);
	number_of_ports=argc-2;
	return 0;
}
