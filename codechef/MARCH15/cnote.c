#include<stdio.h>

int main()
{
	int t,x,y,k,n,p,c,i,flag;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&x,&y,&k,&n);
		flag=0;
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&p,&c);
			if(x-y>0 && x-y<=p && c<=k)
					flag=1;
		}
		if(flag)
			printf("LuckyChef\n");
		else printf("UnluckyChef\n");
	}
	return 0;
}
