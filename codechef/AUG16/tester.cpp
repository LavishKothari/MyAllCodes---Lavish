#include <time.h>
#include <stdlib.h>
#include<stdio.h>
#define T 1
#define MAX 10

FILE*fp;
void print1TestCase()
{
	int n=rand()%MAX;
	fprintf(fp,"%d\n",n);
	while(n--)
	{
		int t=rand()%MAX;
		fprintf(fp,"%d ",t);
	}
	fprintf(fp,"\n");
}
int main()
{
	srand(time(NULL));
	
	fp=fopen("tc.txt","w");
	if(fp)
	{
		fprintf(fp,"%d\n",T);
		for(int i=0;i<T;i++)
			print1TestCase();
	}
	else 
	{
		printf("There was some error in opening the file\n");
	}
	return 0;
}
