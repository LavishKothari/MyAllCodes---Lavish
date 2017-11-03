#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
double dist(int a,int b,int c,int d)
{
	return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}
class C
{
	public:
		string name;
		int x,y;

		C(string name,int x,int y)
		{
			this->name=name;
			this->x=x;
			this->y=y;
		}
};
double findTarget(vector<C>&v,vector<int>&perm)
{
	double answer=0.0;
	for(int i=0;i<perm.size();i+=2)
	{
		int a=perm[i];
		int b=perm[i+1];
		answer+=dist(v[a].x,v[a].y,v[b].x,v[b].y);
	}
	return answer;
}
void solve(vector<C>&v)
{
	int n=v.size();
	vector<int>perm(n);
	for(int i=0;i<perm.size();i++)
		perm[i]=i;
	double answer=DBL_MAX;
	do
	{
		/*		for(int i=0;i<perm.size();i++)
				cout<<perm[i]<<" ";
				cout<<endl;
		 */		double distance = findTarget(v,perm);
		answer = min(answer,distance);
	}while(next_permutation(perm.begin(),perm.end()));
	printf("%0.2f\n",answer);
}
int main()
{
	while(true)
	{
		int n;
		scanf("%d",&n);
		if(n==0)
			break;
		vector<C>v;
		for(int i=0;i<n*2;i++)
		{
			string name;int x,y;
			cin>>name;
			scanf("%d%d",&x,&y);
			v.push_back(C(name,x,y));
		}
		solve(v);
	}
	return 0;
}
