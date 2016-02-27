#include<stdio.h>
#include<set>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b,n;
		scanf("%d%d%d",&n,&a,&b);
		set<int>s;
		for(int i=0;i<n;i++)
		{
			s.insert(i*a+(n-i-1)*b);
		}
		for(set<int>::iterator it=s.begin();it!=s.end();it++)
			printf("%d ",(*it));
		printf("\n");
	}
	return 0;
}
