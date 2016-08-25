#include<stdio.h>
typedef long long int ll;
void printRev(int start,int end)
{
	int i;
	for(i=end;i>=start;i--)
		printf("%d ",i);
}
void printAnswer(ll n)
{
	ll sum=0,cn=n,no=0,i,cou,start=1,end=0,pf[100];
	//printSum(n);
	cou=0;
	for(i=2;cn!=1;i++)
	{
		if(cn%i==0)
			no++;
		while(cn%i==0)
		{
			start=end+1;
			end+=i;
			//printf("%lld %lld\n",start,end);
			//printRev(start,end);
			cn/=i;
			sum+=i;
			pf[cou++]=i;
			//printf("%lld ",i);
		}
	}
	if(sum<=100)
	{
		printf("%lld\n",sum);
		end=0;
		for(i=0;i<cou;i++)
		{
			start=end+1;
			end+=pf[i];
			printRev(start,end);
		}
		printf("\n");
	}
}

int main()
{
	ll t,k,i;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&k);
		if(k==1)
			printf("1\n1\n");
		else printAnswer(k);
	}
	return 0;
}
