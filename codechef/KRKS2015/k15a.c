#include<stdio.h>
#include<stdlib.h>
int main()
{
	int t,temp,arr[1000],n,i,answer;
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<1001;i++)
			arr[i]=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&temp);
			arr[temp]++;
		}
		answer=0;
		for(i=0;i<1001;i++)
			if(arr[i]>1)
				answer++;
		printf("%d\n",answer);
	}
	return 0;
}
