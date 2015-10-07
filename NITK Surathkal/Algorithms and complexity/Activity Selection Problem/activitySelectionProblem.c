/*
	implementation of activity selection problem.
*/
#include<stdlib.h>
#include<stdio.h>
struct Job
{
	int s,f,number;
};

int cmpfunc(const void*a,const void*b)
{
	return (*((struct Job*)a)).f-(*((struct Job*)b)).f;
}

int main()
{
	struct Job *jobs;
	int n,i,answer=0,prevf;
	printf("Enter the number of jobs : ");
	scanf("%d",&n);
	jobs=(struct Job*)malloc(sizeof(struct Job)*n);
	printf("Enter the starting and finishing time for n Jobs : \n");
	for(i=0;i<n;i++)
	{
		jobs[i].number=i;
		scanf("%d%d",&jobs[i].s,&jobs[i].f);
	}
	qsort(jobs,n,sizeof(struct Job),cmpfunc);
	answer++;
	printf("%d ",jobs[0].number);
	prevf=jobs[0].f;
	for(i=1;i<n;i++)
	{
		if(jobs[i].s>=prevf)
		{
			answer++;
			printf("%d ",jobs[i].number);
			prevf=jobs[i].f;
		}
	}
	printf("\nThe maximum number of jobs that can be executed without overlapping is : %d\n\n",answer);
	return 0;
}
