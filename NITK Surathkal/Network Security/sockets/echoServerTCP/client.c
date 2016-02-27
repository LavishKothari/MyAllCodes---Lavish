#include<sys/socket.h>
#include<stdio.h>
#include<netinet/in.h>
#include<string.h>
#define MAX_SIZE 1000
int main(int argc,char*argv[]) // the first argument is ./a.out and the second argument is the port number of the server
{
	char buffer[MAX_SIZE];
	int port_no;
	struct sockaddr_in mysock,servsock;int b,c;
	port_no=atoi(argv[1]);
	memset(&mysock,0,sizeof(mysock));
	memset(&servsock,0,sizeof(servsock));
	
	int fd=socket(AF_INET,SOCK_STREAM,0);
	if(fd<0)
		printf("socket not created successfully\n");
	else
	{
		printf("socket created successfully\n");
		printf("Bind system call executed successfully\n");
		servsock.sin_family=AF_INET;
		servsock.sin_addr.s_addr=inet_addr("127.0.0.1");
		servsock.sin_port=htons(port_no);
		c=connect(fd,(struct sockaddr*)&servsock,sizeof(servsock));
		
		if(c<0)
			printf("There was some problem in connecting to the server.\n");
		else
		{
			printf("Connecting to the server was successful\n");
			printf("Enter a string : ");
			scanf(" %[^\n]s",buffer);
			printf("On the client side you entered : %s\n",buffer);
			write(fd,buffer,strlen(buffer)+1);
			read(fd,buffer,MAX_SIZE);
			printf("the server sent : %s\n",buffer);
		}
		close(fd);
	}
	return 0;
}
