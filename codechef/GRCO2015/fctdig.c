#include<stdio.h>
#include<math.h>
int main()
{
	int t,n,temp,i;
	double arr[100001];
	arr[0]=0;
	arr[1]=1;
	arr[2]=log10(2);
	for(i=3;i<=100000;i++)
	{
		arr[i]=arr[i-1]+log10(i);
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		while(n--)
		{
			scanf("%d",&temp);
			if(temp!=1)
				printf("%d ",(int)arr[temp]+1);
			else
				printf("%d ",(int)arr[temp]);
		}
		printf("\n");
	}
	return 0;
}
