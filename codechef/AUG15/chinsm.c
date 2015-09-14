#include<stdlib.h>
#include<stdio.h>
long long int find(long long int n)
{
	return (n*(n+1))/2;
}
int main()
{
	long long int answer=0;
	int n,k,*arr,*flag,i,previ;
	scanf("%d%d",&n,&k);
	arr=(int*)malloc(sizeof(int)*n);
	flag=(int*)malloc(sizeof(int)*n);
	previ=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		if(i>0)
		{
			if((arr[i-1]%arr[i])==k)
			{
				answer+=find(i-previ);
				previ=i;
	//			printf("%lld , ",answer);
			}
		}
	}
	
	answer+=find(n-previ);
	if(n!=1)
	{
		if(answer>=n)
			printf("%lld\n",answer);
		else
			printf("%d\n",n);
	}else
		printf("1\n");
	return 0;
}
