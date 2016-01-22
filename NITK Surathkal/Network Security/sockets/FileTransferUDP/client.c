#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#define MAX_SIZE 100000
int main()
{
	int fd,servLen;
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
			printf("/******************************************************/\n");
			printf("Enter the Command : ");
			scanf(" %[^\n]s",buffer);
			if(strcmp(buffer,"EXIT")==0)
				break;
			// sending the command.
			sendto(fd,buffer,strlen(buffer)+1,0,(struct sockaddr*)&servAddr,sizeof(servAddr));
			recvfrom(fd,buffer,MAX_SIZE,0,(struct sockaddr*)&servAddr,&servLen);
			printf("output of the command  : %s\n",buffer);
			
			printf("Enter a file name : ");
			scanf("%s",buffer);
			printf("You entered this file name %s\n",buffer);
			sendto(fd,buffer,strlen(buffer)+1,0,(struct sockaddr*)&servAddr,sizeof(servAddr));
			recvfrom(fd,buffer,MAX_SIZE,0,(struct sockaddr*)&servAddr,&servLen);
			printf("contents of requested file : \n%s\n",buffer);
		}
	}
	return 0;
}
