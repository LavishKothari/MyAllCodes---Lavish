#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#define MAX_SIZE 1000
int main()
{
	int fd,addr_size,i,b,s;
	char buffer[MAX_SIZE];
	struct sockaddr_in clientAddr,servAddr;
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
		servAddr.sin_addr.s_addr=htonl(INADDR_ANY);
		b=bind(fd,(struct sockaddr*)&servAddr,sizeof(servAddr));
		if(b<0)
		{
			printf("there was some problem in Binding\n");
			return 0;
		}
		else
		{
			printf("Binding successful\n");
			while(1)
			{
				recvfrom(fd,buffer,MAX_SIZE,0,(struct sockaddr*)&clientAddr,&addr_size);
				printf("Client sent : %s\n",buffer);
				for(i=0;buffer[i];i++)
					if(buffer[i]>='a' && buffer[i]<='z')
						buffer[i]=buffer[i]-('a'-'A');
				printf("At server after capitalization : %s\n",buffer);
				printf("the lenght of the string is : %d\n",strlen(buffer));
				s=sendto(fd,buffer,strlen(buffer)+1,0,(struct sockaddr*)&clientAddr,addr_size);
				if(s<0) printf("there is some serious issue\n");
			}
		}
	}
	close(fd);
	return 0;
}
