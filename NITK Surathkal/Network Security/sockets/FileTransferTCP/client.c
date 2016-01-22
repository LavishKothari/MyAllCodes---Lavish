#include<sys/socket.h>
#include<stdio.h>
#include<netinet/in.h>
#include<string.h>
#define MAX_SIZE 100000
int main()
{
	char buffer[MAX_SIZE];
	struct sockaddr_in mysock,servsock;int b,c;
	FILE*fp;
	memset(&mysock,'0',sizeof(mysock));
	memset(&servsock,'0',sizeof(servsock));
	
	int fd=socket(AF_INET,SOCK_STREAM,0);
	if(fd<0)
		printf("socket not created successfully\n");
	else
	{
		printf("socket created successfully\n");
		printf("Bind system call executed successfully\n");
		servsock.sin_family=AF_INET;
		servsock.sin_addr.s_addr=inet_addr("127.0.0.1"); // there is some doubt here
		servsock.sin_port=htons(5900);
		c=connect(fd,(struct sockaddr*)&servsock,sizeof(servsock));
		
		if(c<0)
			printf("There was some problem in connecting to the server.\n");
		else
		{
			printf("Connecting to the server was successful\n");
			printf("Enter the command : ");
			scanf(" %[^\n]s",buffer);
			printf("On the client side you entered : %s\n",buffer);
			// sending the command to the server
			write(fd,buffer,strlen(buffer)+1);
			
			// reading the output of commnad from the server
			read(fd,buffer,MAX_SIZE);
			printf("Output of the command is : \n%s\n",buffer);
			
			printf("Enter the file that you want to copy from server : ");
			scanf("%s",buffer);
			write(fd,buffer,strlen(buffer)+1);
			
			read(fd,buffer,MAX_SIZE);
			printf("The contents of file are  : \n%s",buffer);
			
			fp=fopen("received_file.txt","w");
			fprintf(fp,"%s",buffer);
			fclose(fp);
		}
		close(fd);
	}
	return 0;
}
