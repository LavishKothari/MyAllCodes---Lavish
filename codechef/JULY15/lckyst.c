#include<stdio.h>
#include<math.h>
int main()
{
	long long int n,t,max=0,num,min,count,i,j,count10;
	long long int *table;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		count=0;
		count10=0;
		scanf("%lld",&num);
		while(num%10==0)
		{
			count10++;
			num/=10;
		}
		t=num;
		while(t%5==0)
		{
			count++;
			t/=5;
		}
		if(count>0)
		{
			if(count%2==0)
				printf("%lld",t);
			else
				printf("%lld",2*t);
		}
		else
			printf("%lld",num);
		
		for(j=0;j<count;j++)
			printf("0");
		
		for(j=0;j<count10;j++)
			printf("0");
		printf("\n");
	}
	return 0;
}
