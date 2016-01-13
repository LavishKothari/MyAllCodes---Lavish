#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>pal;
bool isP(int n)
{
	int cn=n,sum=0;
	while(cn)
	{
		sum=sum*10+cn%10;
		cn/=10;
	}
	if(sum==n)
		return true;
	return false;
}
void populate()
{
	int max=101101;
	for(int i=999;i>=100;i--)
	{
		for(int j=999;j>=100;j--)
		{
			if(isP(i*j))
			{
				pal.push_back(i*j);
			}
		}
	}
	sort(pal.begin(),pal.end());
}
int findAnswer(int n)
{
	vector<int>::iterator it=lower_bound(pal.begin(),pal.end(),n);
	for(;;it--)
	{
		if((*it)<n)
			return *it;
	}
}
int main()
{	
	int t;
	populate();
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		printf("%d\n",findAnswer(n));
	}
	return 0;
}
