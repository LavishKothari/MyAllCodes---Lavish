#include<stdio.h>
#include<stdlib.h>
struct Judge
{
	int L,R,C;
};
int cmpfunc(const void*a,const void*b)
{
	struct Judge x,y;
	x=*(struct Judge*)a;
	y=*(struct Judge*)b;
	return x.C-y.C;
}
int minimumIfAlive(int *rating,int*flag,int n)
{
	int mini=0,i,min=1000000001;
	for(i=0;i<n;i++)
	{
		if(flag[i]==0 && rating[i]<min)
		{
			mini=i;
			min=rating[i];
		}
	}
	return mini;
}

int main()
{	
	struct Judge *judges;
	long long int sum=0;
	int t,n,k,m,*rating,i,j,*flag,index;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&k,&m);
		rating=(int*)malloc(sizeof(int)*n);
		flag=(int*)malloc(sizeof(int)*n);
		// if flag[i]==0 then ith dish is alive else dead
		// initially all the dishes are alive.
		// so initialising each element of flag array to 0
		for(i=0;i<n;i++)
			flag[i]=0;
			
		judges=(struct Judge*)malloc(sizeof(struct Judge)*m);
		sum=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&rating[i]);
			sum+=rating[i];
		}
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&judges[i].L,&judges[i].R,&judges[i].C);
			(judges[i].R)--;
			(judges[i].L)--;
		}
		// input complete
		qsort(judges,m,sizeof(struct Judge),cmpfunc);
		/*
		for(i=0;i<m;i++)
			printf("%d %d %d\n",judges[i].L,judges[i].R,judges[i].C);
		*/
		for(i=0;i<n && k>0;i++)
		{
			index=minimumIfAlive(rating,flag,n);
			if(rating[index]>0)
				break;
			for(j=0;j<m;j++)
			{
				if(index>=judges[j].L && index<=judges[j].R && k>=judges[j].C)
				{
					flag[index]=1;
					k-=judges[j].C;
					sum=sum-rating[index];
					break;
				}
			}
			if(j==m)
			{
				flag[index]=1;
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
}
