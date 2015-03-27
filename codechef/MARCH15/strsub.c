#include<stdio.h>
int**arr;
int main()
{
	int t,n,k,q,l,r,i,j,flag0,flag1;
	long long int answer,notValid;
	char str[100001];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&k,&q);
		arr=(int**)malloc(sizeof(int*)*n);
		for(i=0;i<n;i++)
			arr[i]=(int*)malloc(sizeof(int)*n);
		scanf(" %s",str);
		for(i=0;i<n;i++)
		{
			for(j=i;j<n;j++)
			{
				if(j==i)
				{
					arr[i][j]=0;
				}
				else
				{
					arr[i][j]=arr[i][j-1];
					
				}
			}
		}
		while(q--)
		{
			scanf("%d%d",&l,&r);
			l--;r--;notValid=0;
			for(i=l;i<=r;i++)
			{
				flag0=flag1=0;
				for(j=i;j<=r;j++)
				{
					if(str[j]=='0')
						flag0++;
					else flag1++;
					if(flag0>k || flag1>k)
						break;
				}
				if(flag0>k || flag1>k)
					notValid+=r-j+1;
			}
			answer=((r-l+2)*((long long int)r-l+1))/2-notValid;
			printf("%lld\n",answer);
		}
	}
	return 0;
}
