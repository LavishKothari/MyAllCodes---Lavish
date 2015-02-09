#include<stdio.h>
int main()	
{
	
	int i,t;
	long long int a,b;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%lld%lld",&a,&b);
		if(a%2==0 && b%2==0)
			printf("A\n");
		else if(a%2!=0 && b%2!=0)
			printf("B\n");
		else if((a%2==0 && b%2!=0)||(a%2!=0 && b%2==0))
			printf("A\n");		
	}
	return 0;
}
