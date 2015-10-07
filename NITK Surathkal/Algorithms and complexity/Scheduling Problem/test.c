#include<stdlib.h>
#include<stdio.h>
#include"header.h"

#define MAX_N 100000
#define MAX_PROFIT 10000
#define MAX_DEADLINE MAX_N/10
int main1()
{
	FILE *fp;
	int profit,deadline,i;
	fp=fopen("./test.txt","w");
	if(fp)
	{
		fprintf(fp,"%d\n",MAX_N);
		srand((unsigned)time(NULL));
		
		for(i=0;i<MAX_N;i++)
		{
			//srand((unsigned)time(NULL));
			profit=rand()%MAX_PROFIT;
			
			deadline=rand()%MAX_DEADLINE;
			while(deadline==0)
				deadline=rand()%MAX_DEADLINE;

			fprintf(fp,"%d %d\n",profit,deadline);
		}
		fclose(fp);
	}
	else
		printf("There was some error in opening the file\n");
	return 0;
}
