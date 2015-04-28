#include<stdio.h>
#include<stdlib.h>
int main()
{
	int t,n,m,k,*a,*b,*flaga,*flagb,ans1,ans2,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&k);
		a=(int*)malloc(sizeof(int)*m);
		b=(int*)malloc(sizeof(int)*k);
		flaga=(int*)malloc(sizeof(int)*101);
		flagb=(int*)malloc(sizeof(int)*101);
		for(i=0;i<=100;i++)
			flaga[i]=flagb[i]=0;
		for(i=0;i<m;i++)
		{
			scanf("%d",&a[i]);
			flaga[a[i]]++;
		}
		for(i=0;i<k;i++)
		{
			scanf("%d",&b[i]);
			flagb[b[i]]++;
		}
		ans1=ans2=0;
		for(i=1;i<=n;i++)
		{
			if(flaga[i]==flagb[i] && flaga[i]==1)
				ans1++;
			if(flagb[i]==flaga[i] && flaga[i]==0)
				ans2++;
		}
		printf("%d %d\n",ans1,ans2);
	}
	return 0;
}
