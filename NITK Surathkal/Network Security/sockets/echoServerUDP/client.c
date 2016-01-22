#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#define MAX_SIZE 1000
int main()
{
	int fd,clientLen;
	char buffer[MAX_SIZE];
	struct sockaddr_in servAddr,clientAddr;
	memset((char*)&clientAddr,0,sizeof(clientAddr));
	memset((char*)&servAddr,0,sizeof(servAddr));
	
	fd=socket(AF_INET,SOCK_DGRAM,0);
	if(fd<0)
	{
		printf("There was some problem in creating the socket\n");
		return 0;
	}
	else
	{
		printf("Socket created successfully\n");
		servAddr.sin_family=AF_INET;
		servAddr.sin_port=htons(6100);
		servAddr.sin_addr.s_addr=inet_addr("127.0.0.1");
		while(1)
		{
			printf("Enter the string that you want to send to the server : ");
			scanf(" %[^\n]s",buffer);
			if(strcmp(buffer,"EXIT")==0)
				break;
			sendto(fd,buffer,strlen(buffer)+1,0,(struct sockaddr*)&servAddr,sizeof(servAddr));
			printf("Sent successfully : %s\n",buffer);
			recvfrom(fd,buffer,MAX_SIZE,0,(struct sockaddr*)&clientAddr,&clientLen);
			printf("This is the string received from the server : %s\n",buffer);
		}
	}
	return 0;
}
