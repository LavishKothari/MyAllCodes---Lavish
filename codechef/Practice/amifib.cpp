#include<stdio.h>
#include<vector>

using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	vector<long long int>fib;
	fib.push_back(0);
	fib.push_back(1);
	while(*(fib.end()-1)<=1000)
	{
		fib.push_back((*(fib.end()-1))+(*(fib.end()-2)));
	}
	for(vector<long long int>::iterator it=fib.begin();it!=fib.end();it++)
		printf("%lld ",*it);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		if(lower_bound(fib.begin(),fib.end(),n)!=fib.end())
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
	
}
