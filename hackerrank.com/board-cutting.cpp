#include<stdlib.h>
#include<stdio.h>
#define MOD 1000000007
typedef long long int ll;
int cmp(const void*a,const void*b)
{
	return *(int*)b-*(int*)a;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int m,n;
		scanf("%d%d",&m,&n);
		int*y=new int[m-1];
		int*x=new int[n-1];
		for(int i=0;i<m-1;i++)
			scanf("%d",&y[i]);
		for(int i=0;i<n-1;i++)
			scanf("%d",&x[i]);
		qsort(y,m-1,sizeof(int),cmp);
		qsort(x,n-1,sizeof(int),cmp);
		int h_s=1,v_s=1;
		int i_x=0,i_y=0;
		ll cost=0;
		for(int i=0;i<m+n-2;i++)
		{
			//printf("%d %d %d %d %lld\n",i_x,i_y,v_s,h_s,cost);
			if(i_x<n-1 && i_y<m-1 && x[i_x]>=y[i_y])
			{
				v_s++;
				cost=(cost+(x[i_x]*(ll)h_s)%MOD)%MOD;
				i_x++;
			}
			else if(i_x<n-1 && i_y<m-1)
			{
				h_s++;
				cost=(cost+(y[i_y]*(ll)v_s)%MOD)%MOD;
				i_y++;
			}
			else if(i_x==n-1)
			{
				h_s++;
				cost=(cost+(y[i_y]*(ll)v_s)%MOD)%MOD;
				i_y++;
			}
			else if(i_y==m-1)
			{
				v_s++;
				cost=(cost+(x[i_x]*(ll)h_s)%MOD)%MOD;
				i_x++;
			}
		}
		printf("%lld\n",cost);
	}
	return 0;
}
