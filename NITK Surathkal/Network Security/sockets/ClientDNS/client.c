#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<netdb.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
char *lookUpLocally(char *host_name)
{
	char *ip;
	FILE*fp;
	char host[1000],temp[1000];
	ip=(char*)malloc(sizeof(char)*1000);
	fp=fopen("dns.txt","r");
	if(fp)
	{
		printf("File operation successful\n");
		while(!feof(fp))
		{
			fscanf(fp,"%s",host);
			if(strcmp(host,host_name)==0)
			{
				fscanf(fp,"%s",ip);
				return ip;
			}
			fgets(temp,1000,fp);
		}
	}
	else 
	{
		printf("File operation not successful\n");
		return NULL;
	}
	return NULL;
}
void paddr(unsigned char *a)
{
	printf("%d.%d.%d.%d\n",a[0],a[1],a[2],a[3]);
}
int main()
{	
	int i;
	struct hostent*he;
	char host_name[1000],*local;
	local=(char*)malloc(sizeof(char)*1000);
	printf("Enter the host name : ");
	scanf("%s",host_name);
	local=lookUpLocally(host_name);
	if(local)
		printf("\n\nThese are the Entries from local dns : %s\n",local);
	he=gethostbyname(host_name);
	if(he==NULL)
	{
		printf("There was some error in getting the host name\n");
	}
	else
	{
		printf("\n\nThese are the enteries for dns server\n");
		printf("The official name is : %s\n",he->h_name);
		printf("IP Addresses are :\n");
		for(i=0;he->h_addr_list[i];i++)
			paddr((unsigned char*)he->h_addr_list[i]);
	}	
	return 0;
}
