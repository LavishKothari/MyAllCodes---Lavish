#include<stdio.h>

int main()
{
	int t,n,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(n%2==1)
			printf("0\n");
		else
		{
			printf("9");
			for(i=0;i<n/2-1;i++)
				printf("0");
			printf("\n");
		}		
	}
	return 0;
}
