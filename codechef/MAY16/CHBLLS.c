#include<stdio.h>

int findAnswer1()
{
	int temp;
	printf("1\n");
	fflush(stdout);	
	printf("3 3 4 5\n");
	fflush(stdout);	
	printf("2 1 2\n");
	fflush(stdout);	
	
	scanf("%d",&temp);
	if(temp==2)
	{
		printf("1\n");
		fflush(stdout);	
		printf("2 3 4\n");
		fflush(stdout);	
		printf("1 5\n");
		fflush(stdout);	
	
		scanf("%d",&temp);
		if(temp==0)
			return 5;
		else 
		{
			printf("1\n");
			fflush(stdout);	
			printf("1 3\n");
			fflush(stdout);	
			printf("1 4\n");
			fflush(stdout);	
	
			scanf("%d",&temp);
			if(temp==1)
				return 3;
			else 
				return 4;
		}
	}
	else if(temp==0)
	{
		printf("1\n");
		fflush(stdout);	
		printf("1 1\n");
		fflush(stdout);	
		printf("1 2\n");
		fflush(stdout);	
	
		scanf("%d",&temp);
		if(temp==1)
			return 1;
		else 
			return 2;
	}
	/************************************/
}
int findAnswer2()
{
	int temp;
	printf("1\n");
	fflush(stdout);	
	printf("2 1 2\n");
	fflush(stdout);	
	printf("2 3 4\n");
	fflush(stdout);	
	
	scanf("%d",&temp);
	if(temp==0)
		return 5;
	else if(temp==1)       
	{
		printf("1\n");
		fflush(stdout);	
		printf("1 1\n");
		fflush(stdout);	
		printf("1 2\n");
		fflush(stdout);	
	
		scanf("%d",&temp);
		if(temp==1)
			return 1;
		else return 2;
	}
	else if(temp==-1)
	{
		printf("1\n");
		fflush(stdout);	
		printf("1 3\n");
		fflush(stdout);	
		printf("1 4\n");
		fflush(stdout);	
	
		scanf("%d",&temp);
		if(temp==1)
			return 3;
		else return 4;
	}
}
int findAnswer3()
{
	int temp;
	printf("1\n");
	fflush(stdout);	
	printf("3 1 2 2\n");
	fflush(stdout);	
	printf("3 3 4 4\n");
	fflush(stdout);	
	
	scanf("%d",&temp);
	if(temp==0)
		return 5;
	else if(temp==1)
		return 1;
	else if(temp==2)
		return 2;
	else if(temp==-1)
		return 3;
	else if(temp==-2)
	 	return 4;
}
int main()
{
	printf("2\n%d\n",findAnswer3());
	return 0;
}
