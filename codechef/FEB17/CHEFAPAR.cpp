#include<bits/stdc++.h>
using namespace std;
int main()
{
	int f,t,te,n,in,count;
	scanf("%d",&t);
	while(t--)
	{
		f=0,in=-1;
		scanf("%d",&n);
		count=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&te);
			count+=te;
			if(te==0 && f==0)
			{	
				in=i;
				f=1;
			}
		}
		if(in==-1)
			printf("%d\n",(n-count)*1000);
		else
			printf("%d\n",(n-count)*1000+(n-in+1)*100);
	}
	return 0;
}
