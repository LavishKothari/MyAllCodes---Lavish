#include<stdio.h>
#include<stdlib.h>
int *arr,n;
char command[10000];
int tape[100000]={0};


void convert(char*str)
{
	int sum=0,i,counter=0;
	n=1;
	for(i=0;str[i];i++)
		if(str[i]==' ')
			n++;	
	arr=(int*)malloc(sizeof(int)*n);
	
	for(i=0;str[i];i++)
	{
		if(str[i]==' ')
		{
			arr[counter++]=sum;
			sum=0;
			continue;
		}
		else
		{
			sum=sum*10+str[i]-'0';
		}
	}
	arr[counter++]=sum;
	/*
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
	*/
}
void printA()
{
	int i;
	for(i=0;i<10;i++)
		printf("%d ",tape[i]);
	printf("\n");
}

int thisisloop(int start,int ci)
{
	int i,end;
	for(i=start;command[i] && command[i]!=']';i++)
	{
		end=i;
	}
	//printf("end = %d\n",end);
	i=start;
	if(!tape[ci])
		return ci;
	while(1)
	{
		//if(ci==i)
		//printf("command[i]=%c tape[ci] = %d %d %d\n",command[i],tape[ci],ci,i);
		//printf("%d ",i);
		//printA();
		
		if(command[i]==':')
			printf("%d ",tape[ci]);
		else if(command[i]=='>')
			ci++;
		else if(command[i]=='<')
			ci--;
		else if(command[i]=='+')
			tape[ci]++;
		else if(command[i]=='-')
			tape[ci]--;
		
		i++;
		if(i==end+1)
		{
			i=start;
			if(!tape[ci])
				break;
		}
	}
	return ci; 
}
void solve()
{
	int i,counter=0;
	int ci=0;
	for(i=0;command[i];i++)
	{
		//printf("** %d %d\n",i,ci);
		if(command[i]==';' || command[i]=='.')
			tape[ci]=arr[counter++];
		else if(command[i]==':')
			printf("%d ",tape[ci]);
		else if(command[i]=='>')
			ci++;
		else if(command[i]=='<')
			ci--;
		else if(command[i]=='+')
			tape[ci]++;
		else if(command[i]=='-')
			tape[ci]--;
		else if(command[i]=='[')
		{
			ci=thisisloop(i+1,ci);
			for(;command[i]!=']';i++);
		}
	}
}

int main()
{
	char integers[10000];
	scanf(" %s",command);
	scanf(" %[^\n]s",integers);
	convert(integers);
	solve();
	return 0;
}
