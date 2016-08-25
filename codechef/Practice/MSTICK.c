#include<stdio.h>

int stmin[200010],stmax[200010],n;
int max(int a,int b,int c)
{
	return a>b?(a>c?a:c):(b>c?b:c);
}
void build_min_max()
{
	int i;
	for(i=n-1;i>=1;i--)
	{
		stmin[i]=stmin[i<<1]<stmin[(i<<1)|1]?stmin[i<<1]:stmin[(i<<1)|1];
		stmax[i]=stmax[i<<1]>stmax[(i<<1)|1]?stmax[i<<1]:stmax[(i<<1)|1];
	}
}
int query_min(int l,int r)
{
	int min=2147483647;
	for(l+=n,r+=n;l<r;l>>=1,r>>=1)
	{
		if(l&1)
		{
			if(stmin[l]<min)
				min=stmin[l];
			l++;
		}
		if(r&1)
		{
			if(stmin[r-1]<min)
				min=stmin[r-1];
			r--;
		}	
	}
	return min;
}

int query_max(int l,int r)
{
	int max=0;
	for(l+=n,r+=n;l<r;l>>=1,r>>=1)
	{
		if(l&1)
		{
			if(stmax[l]>max)
				max=stmax[l];
			l++;
		}
		if(r&1)
		{
			if(stmax[r-1]>max)
				max=stmax[r-1];
			r--;
		}
	}
	return max;
}
int main()
{
	int q,m,max1,max2,max3,i,l,r,min;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&stmin[i+n]);
		stmax[n+i]=stmin[n+i];
	}
	build_min_max();
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&l,&r);
		r++;
		min=query_min(l,r);
		max1=2*query_max(0,l);
		max2=2*query_max(r,n);
		max3=query_max(l,r)-min;
		m=max(max1,max2,max3);
		printf("%0.1lf\n",min+m/2.0);
	}
	return 0;
}
