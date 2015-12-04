#include<stdio.h>
#include<vector>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	vector <int >x;
	for(int i=0;i<n;i++)
	{
		int t;
		scanf("%d",&t);
		x.push_back(t);
	}
	for(int i=0;i<x.size()-1;i++)
	{
		printf("hello\n");
		if((x[i]+x[i+1])%2==0)
		{
			x.erase(x.begin()+i);
			x.erase(x.begin()+i);
			i=0;
		}
	}
	printf("%d\n",x.size());
	return 0;
}
