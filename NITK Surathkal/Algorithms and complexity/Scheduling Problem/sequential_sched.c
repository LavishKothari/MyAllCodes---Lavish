/*
	implementation of Scheduling Algorithm
*/
#include"header.h"
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
struct Job
{
	int deadline,number,profit;
};

int cmpfunc(const void*a,const void*b)
{
	return (*((struct Job*)b)).profit-(*((struct Job*)a)).profit;
}
long long int findMaximumProfit(struct Job *jobs,int n)
{
	int *time,d,answer=0,i;
	long long int maxProfit=0,maxDeadline;
	for(i=0;i<n;i++)
		if(i==0)
			maxDeadline=jobs[i].deadline;
		else if(maxDeadline<jobs[i].deadline)
			maxDeadline=jobs[i].deadline;
	time=(int*)malloc(sizeof(int)*(maxDeadline+1));
	for(i=0;i<maxDeadline+1;i++)
		time[i]=-1;
	qsort(jobs,n,sizeof(struct Job),cmpfunc); // sorting the jobs according to profit in descending order
	
	//printf("\nThe list of jobs that are executed for maximum overall profit is :\n");
	for(i=0;i<n;i++)
	{
		d=jobs[i].deadline;
		while(d>0 && time[d]!=-1)
			d--;
		if(d>0)
		{
			time[d]=i;
			//printf("%d ",jobs[i].number+1);
			answer++;
			maxProfit+=jobs[i].profit;
		}
	}
	printf("\n\nThe total number of jobs executed are : %d\n",answer);
	return maxProfit;
}
int main()
{
	clock_t begin,end;
	struct Job *jobs;
	int n,i;
	long long int maxProfit=0;
	FILE*fp;
	main1();
	fp=fopen("test.txt","r");
	fscanf(fp,"%d",&n);
	jobs=(struct Job*)malloc(sizeof(struct Job)*n);
	for(i=0;i<n;i++)
	{
		jobs[i].number=i;
		fscanf(fp,"%d%d",&jobs[i].profit,&jobs[i].deadline);
	}
	fclose(fp);
	begin=clock();
	maxProfit=findMaximumProfit(jobs,n);
	end=clock();
	printf("The maximum profit is : %lld\n",maxProfit);
	printf("The execution time for the program is : %lf\n\n",(double)(end-begin)/CLOCKS_PER_SEC);
	return 0;
}
