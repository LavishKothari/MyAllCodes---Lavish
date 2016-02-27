#include<sys/socket.h>
#include<netinet/in.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define PORT 5900
#define MAX_SIZE 1000
int main()
{
	int fd,a,len=0,i;
	char buffer[MAX_SIZE];
	struct sockaddr_in servaddr,clientaddr;
	memset(&servaddr,0,sizeof(servaddr));
	memset(&clientaddr,0,sizeof(clientaddr));
	fd=socket(AF_INET,SOCK_STREAM,0);
	if(fd<0)
		printf("There was a problem in creating the socket\n");
	else
	{
		printf("Socket Created Successfully\n");
		servaddr.sin_family=AF_INET;
		servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
		servaddr.sin_port=htons(PORT);
		if(bind(fd,(struct sockaddr*)&servaddr,sizeof(servaddr))<0)
			printf("There was some problem in binding\n");
		else
		{
			printf("Binding successful\n");
			if(listen(fd,10)<0)
				printf("There was some problem in listen system call\n");
			else
			{
				printf("Listen successful\n");
				while(1)
				{
					a=accept(fd,(struct sockaddr*)&clientaddr,&len);
					if(a<0)
						printf("There was some error in accepting the client\n");
					else
					{
						read(a,buffer,MAX_SIZE);
						for(i=0;buffer[i];i++)
							if(buffer[i]>='a' && buffer[i]<='z')
								buffer[i]=buffer[i]-'a'+'A';
						printf("Writing on the client : %s\n",buffer);
						write(a,buffer,i);
					}
				}
			}
		}
	}
	return 0;
}
