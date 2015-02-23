#include<stdio.h>

int main()
{
	int t,a,c,m,xcur,n,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d%d",&a,&c,&m,&xcur,&n);
		for(i=0;i<n;i++)
			xcur=(a*xcur+c)%m;
		printf("%d ",xcur);
	}
	return 0;
}
