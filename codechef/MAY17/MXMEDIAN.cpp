#include<bits/stdc++.h>
using namespace std;
void sol(vector<int>&v)
{
	sort(v.begin(),v.end());
	vector<int>ca(v.size());
	int c=v.size()-1;
	for(int i=0;i<v.size();i+=2)
		ca[i]=v[c--];
	for(int i=1;i<v.size();i+=2)
		ca[i]=v[c--];
	int x=(v.size()/2+v.size()-1)/2;
	printf("%d\n",v[x]);
	for(int i=0;i<ca.size();i++)
		printf("%d ",ca[i]);
	printf("\n");
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		vector<int>v(2*n);
		for(int i=0;i<2*n;i++)
			scanf("%d",&v[i]);
		sol(v);
	}
	return 0;
}
