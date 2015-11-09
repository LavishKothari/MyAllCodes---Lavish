#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
unsigned long long int findn(unsigned long long int n)
{
	unsigned long long int m=n%9;
	if(m==0)
		return 9;
	return m;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		unsigned long long int a,d,l,r;
		scanf("%llu%llu%llu%llu",&a,&d,&l,&r);
		unsigned long long int answer=0;
		vector<unsigned long long int>coll;
		unsigned long long int divsum=0;
		for(unsigned long long int i=l;i<=r;i++)
		{
			unsigned long long int f=findn(a%9+((i-1)%9)*(d%9));
			if(find(coll.begin(),coll.end(),f)==coll.end())
			{
				divsum+=f;
				coll.push_back(f);
			}
			else
				break;
		}
		answer+=((r-l+1)/coll.size())*divsum;
		for(int i=0;i<(r-l+1)%(coll.size());i++)
			answer+=coll[i];
		coll.clear();
		printf("%llu\n",answer);
	}
	return 0;
}
