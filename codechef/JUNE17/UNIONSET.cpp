#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
bool isfine(vector<bool>&a,vector<bool>&b)
{
	for(int i=1;i<a.size();i++)
		if(!a[i] && !b[i])
			return false;
	return true;
}
void sol(vector<vector<bool> >&v,int k)
{
	int n=v.size();
	int answer=0;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			if(isfine(v[i],v[j]))
				answer++;
	printf("%d\n",answer);
}

int main() 
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		vector<vector<bool> >v(n,vector<bool>(k+1,false));
		for(int i=0;i<n;i++)
		{
			int size;
			scanf("%d",&size);
			for(int j=0;j<size;j++)
			{
				int temp;
				scanf("%d",&temp);
				v[i][temp]=true;
			}
		}
		sol(v,k);
	}
	return 0;
}
