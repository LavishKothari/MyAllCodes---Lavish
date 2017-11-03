#include<stdio.h>
#include<set>
#include<iostream>
#include<string>
using namespace std;
void draw(int n)
{
	for(int i=0;i<(3*n-1)/2;i++)
	{
		for(int j=0;j<(3*n-1)/2;j++)
		{
			if(i==0 && j<n)
			{
				printf("#");
				continue;
			}
			if(j==0 && i<n)
			{
				printf("#");
				continue;
			}
			if(j==n-1 && i<n)
			{
				printf("#");
				continue;
			}
			if(i==n-1 && j<n)
			{
				printf("#");
				continue;
			}
			if(i==n/2 && j>=n/2)
			{
				printf("#");
				continue;
			}
			if(j==n/2 && i>=n/2)
			{
				printf("#");
				continue;
			}
			if(i==(3*n-1)/2-1 && j>=n/2)
			{
				printf("#");
				continue;
			}
			if(i>=n/2 && j==(3*n-1)/2-1)
			{
				printf("#");
				continue;
			}

			printf(" ");

		}
		printf("\n");
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		printf("Case %d:\n",i+1);
		int n;
		scanf("%d",&n);
		draw(n);
	}
	return 0;
}
