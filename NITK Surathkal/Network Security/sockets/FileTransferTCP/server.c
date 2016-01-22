#include<sys/socket.h>
#include<stdio.h>
#include<netinet/in.h>
#include<string.h>
#define MAX_SIZE 100000
int main()
{
	int i;
	char ch;
	char buffer[MAX_SIZE];
	FILE*fp;
	struct sockaddr_in mysock,servsock,clientsock;int b,c,l,len,request;
	memset(&mysock,'0',sizeof(mysock));
	memset(&servsock,'0',sizeof(servsock));
	memset(&clientsock,'0',sizeof(clientsock));
	
	int fd=socket(AF_INET,SOCK_STREAM,0);
	if(fd<0)
		printf("socket not created successfully\n");
	else
	{
		printf("socket created successfully\n");
		mysock.sin_family=AF_INET;
		mysock.sin_addr.s_addr=htonl(INADDR_ANY);
		mysock.sin_port=htons(5900);
		b=bind(fd,(struct sockaddr*)&mysock,sizeof(mysock));
		if(b<0)
			printf("There was some problem in bind system call\n");
		else
		{
			printf("Bind system call executed successfully\n");
			l=listen(fd,10);
			if(l<0)
				printf("There was some problem in listen system call\n");
			else 
			{
				printf("listen system call was successful\n");
				while(1)
				{
					len=sizeof(clientsock);
					request=accept(fd,(struct sockaddr*)&clientsock,&len);
					read(request,buffer,MAX_SIZE);
					printf("Client sent : %s\n",buffer);
					strcat(buffer," > output.txt");
					system(buffer);
					
					fp=fopen("output.txt","r");
					i=0;
					while((ch=fgetc(fp))!=EOF)
						buffer[i++]=ch;
					buffer[i]='\0';
					fclose(fp);
					
					write(request,buffer,strlen(buffer)+1);
					
					read(request,buffer,MAX_SIZE);
					printf("Client wants this file : %s\n",buffer);
					
					fp=fopen(buffer,"r");
					i=0;
					while((c=fgetc(fp))!=EOF)
						buffer[i++]=c;
					buffer[i]='\0';
					fclose(fp);
					
					write(request,buffer,strlen(buffer)+1);
					
					close(request);
				}
				
			}
		}
		close(fd);
	}
	return 0;
}
