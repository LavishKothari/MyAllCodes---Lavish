#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define MOD 1000000007

ll power(ll a,ll b,ll c)  // returns (a**b) % c
{
	if(b==0)	
		return 1;
	ll temp=power(a,b/2,c);
	if(b&1)
		return (((temp*temp)%c)*a)%c;
	return (temp*temp)%c;
}

int findCWinner(int winner,vector<pair<int,int> >&vp)
{
	for(int i=0;i<vp.size();i++)
		if(vp[i].first==winner)
			return vp[i].second;
		else if(vp[i].second==winner)
			return vp[i].first;
}
vector<vector<pair<int,int> > >getAllVectors(int winner,vector<pair<int,int> >&vp)
{
	int n=vp.size();
	vector<vector<int> >vii(1<<(n/2),vector<int>(n/2));
	for(int i=0;i<1<<(n/2);i++)
	{
		int ci=i;
		int x=0;
		for(x=0;x<n/2;x++)
		{
			if(ci&1)
				vii[i][x]=vp[2*x].first;
			else vii[i][x]=vp[2*x].second;
			ci>>=1;
		}
	}
	for(int i=0;i<vii.size();i++)
	{
		for(int j=0;j<vii[i].size();j++)
		{
			cout<<vii[i][j]<<" ";
		}
		cout<<endl;
	}

	int cwinner=findCWinner(winner,vp);
	//cout<<"cwinner is "<<cwinner<<endl;
	vector<int>e;
	for(int i=0;i<vii.size();i++)
	{
		int flag=0;
		for(int j=0;j<vii[i].size();j++)
		{
			if(vii[i][j]==cwinner)
				flag=1;
		}
		if(flag)
			e.push_back(i);
		//cout<<"pushing this in e = "<<i<<endl;
	}

	vector<vector<int> >cvii;
	for(int i=0;i<vii.size();i++)
	{
		if(find(e.begin(),e.end(),i)!=e.end())
			continue;
		cvii.push_back(vii[i]);
	}

	cout<<"********************************************"<<endl;
	for(int i=0;i<cvii.size();i++)
	{
		for(int j=0;j<cvii[i].size();j++)
		{
			cout<<cvii[i][j]<<" ";
		}
		cout<<endl;
	}
	///////////////////////////////////////////////////////////////////////////////////////
	vector<vector<pair<int,int> > >vvp(cvii.size(),vector<pair<int,int> >(cvii[0].size()));


	for(int i=0;i<cvii.size();i++)
	{
		for(int j=0;j<cvii[i].size();j++)
		{
			int x=cvii[i][j];
			int y=cvii[i][j^1];
			vvp[i][j]=make_pair(x,y);
		}
	}

	cout<<"********************************************"<<endl;
	for(int i=0;i<vvp.size();i++)
	{
		for(int j=0;j<vvp[i].size();j++)
		{
			cout<<"("<<vvp[i][j].first<<","<<vvp[i][j].second<<")"<<" ";
		}
		cout<<endl;
	}


	return vvp;
}

ll sol(ll N,ll N2,vector<vector<int> >&M,int winner,vector<pair<int,int> >vp)
{
	if(vp.size()==2)
	{
		int a,b;
		a=vp[0].first;
		b=vp[0].second;
		if(winner==a)
			return M[a][b];
		else return M[b][a];
	}
	// here you need to find cwinner
	int cwinner=findCWinner(winner,vp);
	ll pro=M[winner][cwinner];
	vector<vector<pair<int,int> > >vvp=getAllVectors(winner,vp);
	ll sum=0;
	for(int i=0;i<vvp.size();i++)
		sum+=sol(N,N2,M,winner,vvp[i]);
	return sum*pro;
}
ll sol(ll N,ll N2,vector<vector<int> >&M)
{
	vector<vector<ll> >pr(M.size(),vector<ll>(N+1));

}
int main()
{
	ll N,N2;
	cin>>N;
	N2=power(2,N,MOD); // number of participants
	vector<vector<int> >M(N2,vector<int>(N2));
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>M[i][j];

	sol(N,N2,M);

	/*
	   for(int i=0;i<N2;i++)
	   {
	   vector<pair<int,int> >vp(N2);
	   for(int j=0;j<N2;j++)
	   vp[j].push_back(make_pair(j,j^1));
	   cout<<sol(N,N2,M,i,vp);
	   }

	   vector<pair<int,int> >vp;
	   vp.push_back(make_pair(0,1));
	   vp.push_back(make_pair(1,0));
	   vp.push_back(make_pair(2,3));
	   vp.push_back(make_pair(3,2));
	   vp.push_back(make_pair(4,5));
	   vp.push_back(make_pair(5,4));
	   vp.push_back(make_pair(6,7));
	   vp.push_back(make_pair(7,6));

	   getAllVectors(3,vp);
	 */
	return 0;
}
