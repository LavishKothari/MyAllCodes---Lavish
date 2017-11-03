#include<stdio.h>
char p[1001][1001],q[1001][1001];
int a,b,c,d;		
bool findAnswer()
{
	for(int i=0;i<a;i++)
	{
		for(int j=0;j<b;j++)
		{
			int ci,cj,l,k;
			ci=i;
			for(k=0;k<c && ci<a;k++,ci++)
			{
				cj=j;
				for(l=0;l<d && cj<b;l++,cj++)
				{
					if(p[ci][cj]!=q[k][l])
						goto lavish;
				}
			}
			//printf("ci and cj = %d %d\n",ci,cj);
			if(ci<=a && cj<=b && k==c && l==d)
				return true;
lavish:;
		}
	}
	return false;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&a,&b);

		for(int i=0;i<a;i++)
			scanf(" %s",p[i]);
		scanf("%d%d",&c,&d);

		for(int i=0;i<c;i++)
			scanf(" %s",q[i]);
		bool ans=findAnswer();
		if(ans) printf("YES\n");
		else printf("NO\n");


	}
	return 0;
}
