#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll>getNextGreaterVector(vector<ll>&v)
{	
	int n=v.size();
	vector<ll>result(n,-1);
	if(n==0)
		return result;
	stack<pair<int,ll> > s;// index and element
	s.push(make_pair(0,v[0]));
	
	for(int i=1;i<n;i++)
	{
		while(!s.empty() && s.top().second<v[i])
		{
			result[s.top().first]=i;
			s.pop();
		}
		s.push(make_pair(i,v[i]));
	}
	return result;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,q;
		scanf("%d%d",&n,&q);
		vector<ll>v(n);
		for(int i=0;i<n;i++)
			scanf("%lld",&v[i]);
		vector<ll>ngee=getNextGreaterVector(v);
//		cout<<"Next grater element array is : ";
//		for(int i=0;i<ngee.size();i++)
//			cout<<ngee[i]<<" ";
//		cout<<endl;
		while(q--)
		{
			char ch;
			scanf(" %c",&ch);
			if(ch=='?')
			{
				int startx,l,r;
				scanf("%d%d%d",&startx,&l,&r);
				int uh=l+r-2,lh=l-1;	
//				cout<<"lh and uh are "<<lh<<" "<<uh<<endl;
				int newfound=-1;
				int count=0;
				for(int i=startx-1;i<n;i++)
					if(v[i]>lh)
					{
						newfound=i;
						break;
					}
//				cout<<"new found = "<<newfound<<endl;
				if(newfound==-1)
					printf("0\n");
				else
				{
					int prevHeight=-1;
					while(count<r-l+1 && newfound>=0 && v[newfound]>lh && v[newfound]>prevHeight)
					{
//						cout<<"counter = "<<counter<<endl;
						count++;
//						cout<<"adding 1 for "<<newfound<<endl;
						prevHeight = v[newfound];
						newfound=ngee[newfound];
//						cout<<"and changing to "<<newfound<<endl;
					}
				}
				cout<<count<<endl;
			}
		}
	}
	return 0;
}
