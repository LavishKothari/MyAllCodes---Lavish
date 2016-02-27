#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,q;
		scanf("%d%d",&n,&q);
		vector<double>x(n);
		for(int i=0;i<n;i++)
			scanf("%lf",&x[i]);
		sort(x.begin(),x.end());
		while(q--)
		{
			double k;
			scanf("%lf",&k);
			int i=upper_bound(x.begin(),x.end(),k)-x.begin();
			if(i==n)
				printf("0\n");
			else printf("%d\n",n-i);
		}
	}
	return 0;
}
