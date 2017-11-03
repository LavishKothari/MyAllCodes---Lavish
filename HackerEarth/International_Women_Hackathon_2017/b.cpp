#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

set<int>fr,fc;

class element
{
	public:
		ll start,end,wt;
		element(ll s,ll e,ll w)
		{
			start=s;end=e;wt=w;
		}
};
bool cmp(const element&a,const element&b)
{
	return a.wt>b.wt;
}
void sol(vector<vector<ll> >&A,vector<vector<ll> >&B,ll k)
{
	ll n=A.size();
	if(n*n<k)
		k=n*n;
	int count=0;
	vector<pair<int,int> >final;
	while(1)
	{
		count++;
		if(count==n+1)
			break;
		int mx=INT_MIN;int flag=-1;
		int i,j;
		for(int x=0;x<n;x++)
		{
			for(int y=0;y<n;y++)
			{
				if(fr.find(x)==fr.end() && fc.find(y)==fc.end() && A[x][y]>mx)
				{
					flag=0;i=x;j=y;
					mx=A[x][y];
				}
				if(fr.find(x)==fr.end() && fc.find(y)==fc.end() && B[x][y]>mx)
				{
					flag=1;i=x;j=y;
					mx=B[x][y];
				}
			}
		}
		if(mx==INT_MIN)
			break;
		//cout<<i<<" "<<j<<endl;

		vector<element>sv;
		if(flag==0)
		{
			int col=j;
			for(int x=0;x<n;x++)
				if(A[x][col]<B[x][col])
				{
					if((x==i && col==j) || fr.find(x)!=fr.end() || fc.find(col)!=fc.end())
						continue;
					swap(A[x][col],B[x][col]);
					sv.push_back(element(x,col,A[x][col]-B[x][col]));
				}
			int row=j;
			for(int y=0;y<n;y++)
				if(A[row][y]>B[row][y])
				{
					if((row==i && y==j) || fr.find(row)!=fr.end() || fc.find(y)!=fc.end())
						continue;
					swap(A[row][y],B[row][y]);
					sv.push_back(element(row,y,B[row][y]-A[row][y]));
				}
		}
		else
		{

			int row=i;
			for(int y=0;y<n;y++)
				if(A[row][y]>B[row][y])
				{
					if((row==i && y==j) || fr.find(row)!=fr.end() || fc.find(y)!=fc.end())
						continue;
					swap(A[row][y],B[row][y]);
					sv.push_back(element(row,y,B[row][y]-A[row][y]));
				}

			int col=i;
			for(int x=0;x<n;x++)
				if(A[x][col]<B[x][col])
				{
					if((x==i && col==j) || fr.find(x)!=fr.end() || fc.find(col)!=fc.end())
						continue;
					swap(A[x][col],B[x][col]);
					sv.push_back(element(x,col,A[x][col]-B[x][col]));
				}
		}

		sort(sv.begin(),sv.end(),cmp);
		int t=min((ll)sv.size(),k);

		//cout<<t<<endl;
		for(int i=0;i<t;i++)
		{
			final.push_back(make_pair(sv[i].start,sv[i].end));
			//cout<<sv[i].start+1<<" "<<sv[i].end+1<<endl;

		}
		fr.insert(i);
		fc.insert(j);

		if(t==k)
			break;
		else
			k=k-sv.size();
	}
	cout<<min(k,(ll)final.size())<<endl;
	for(int i=0;i<min((ll)final.size(),k);i++)
		cout<<final[i].first+1<<" "<<final[i].second+1<<endl;

}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	vector<vector<ll> >A(n,vector<ll>(n));
	vector<vector<ll> >B(n,vector<ll>(n));
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>A[i][j];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>B[i][j];

	sol(A,B,k);


	return 0;
}
