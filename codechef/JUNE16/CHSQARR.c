#include<stdio.h>
#define MAX 1001
int arr[MAX][MAX],n,m;

int seg_max[MAX][2*MAX],seg_sum[MAX][2*MAX];


int max2(int a,int b)
{
	return a<b?b:a;
}

void buildTree()
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=m;j<2*m;j++)
		{
			seg_max[i][j]=seg_sum[i][j]=arr[i][j-m];
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=m-1;j>0;j--)
		{
			seg_sum[i][j]=seg_sum[i][j<<1]+seg_sum[i][(j<<1)|1];
			seg_max[i][j]=max2(seg_max[i][j<<1],seg_max[i][(j<<1)|1]);
		}
	}
}

int query_sum(int i,int l,int r)
{
	int res=0;
	for(l+=m,r+=m;l<r;l>>=1,r>>=1)
	{
		if(l&1) 
			res+=seg_sum[i][l++];
		if(r&1) 
			res+=seg_sum[i][--r];
	}
	return res;
}
int query_max(int i,int l,int r)
{
	int max=0;
	for(l+=m,r+=m;l<r;l>>=1,r>>=1)
	{
		if(l&1)
		{
			if(seg_max[i][l]>max)
				max=seg_max[i][l];
			l++;
		}
		if(r&1)
		{
			if(seg_max[i][r-1]>max)
				max=seg_max[i][r-1];
			r--;
		}	
	}
	return max;
}

int findMax(int startI,int startJ,int a,int b)
{
	int max=0,sum=0,i,j,temp;
	if(n-startI<a || m-startJ<b)
		return -1;
	for(i=startI;i<startI+a;i++)
	{
		temp=query_max(i,startJ,startJ+b);
		sum+=query_sum(i,startJ,startJ+b);
		if(temp>max)
			max=temp;
	}	
	return max*a*b-sum;
}


int findAnswer(int a,int b)
{
	if(a==1 && b==1)
		return 0;
	int i,j,max,min=2147483647,diff;
	for(i=0;i<=n-a;i++)
		for(j=0;j<=m-b;j++)
		{
			diff=findMax(i,j,a,b);
			if(min>diff)
				min=diff;
		}
	return min;
}

int main()
{
	int i,j,q,a,b;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&arr[i][j]);
	
	buildTree();
	
	scanf("%d",&q);
	while(q--)
	{	
		scanf("%d%d",&a,&b);
		printf("%d\n",findAnswer(a,b));
	}
	return 0;
}
