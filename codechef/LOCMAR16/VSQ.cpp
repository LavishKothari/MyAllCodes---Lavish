#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>v;
int find(int a,int b)
{
	int x,y;
	return upper_bound(v.begin(),v.end(),b)-lower_bound(v.begin(),v.end(),a);
}
int main()
{
	int n,a,b,q,temp,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&temp);
		v.push_back(temp);
	}
	sort(v.begin(),v.end());
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",find(a,b));
	}
	return 0;
}
