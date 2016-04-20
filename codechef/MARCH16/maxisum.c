#include<stdio.h>
typedef long long int ll;
int main()
{
	int t,aish,n,k,a[100001],b[100001],i;
	ll sum,tempsum,max;
	scanf("%d",&t);
	while(t--)
	{
		sum=0;
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<n;i++)
		{
			scanf("%d",&b[i]);
			sum+=(ll)a[i]*b[i];
		}
		max=-9223372036854775807;
	
		for(i=0;i<n;i++)
		{
			tempsum=sum-(ll)a[i]*b[i]+((ll)a[i]+k)*(ll)b[i];
			if(tempsum>max)
			{
				aish=i;
				max=tempsum;
			}
			tempsum=sum-(ll)a[i]*b[i]+((ll)a[i]-k)*(ll)b[i];
			if(tempsum>max)
			{
				aish=i;
				max=tempsum;
			}
		}
		printf("%lld\n%d\n",max,aish);
	}
	return 0;
}
