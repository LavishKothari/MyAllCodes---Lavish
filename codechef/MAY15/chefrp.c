#include<stdio.h>

int main()
{
	int t,n,temp,min,flag,sum;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		flag=sum=0;
		min=2147483647;
		while(n--)
		{
			scanf("%d",&temp);
			if(temp<2)
				flag=1;
			else    
				sum+=temp;
			if(min>temp)
			    min=temp;
		}
		if(flag==0)
		{
		    if(sum==min)
		        printf("2\n");
		    else printf("%d\n",sum-min+2);
		}
		else printf("-1\n");
	}
	return 0;
}
