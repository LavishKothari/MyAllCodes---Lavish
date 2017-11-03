#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void populateD(vector<ll>&d)
{
	int N=d.size();
	for(int i=1;i<=N/2;i++)
		for(int j=2*i;j<N;j+=i)
			d[j]+=i;
}
int main()
{
	vector<ll>d(1000001,0);
	populateD(d);
	int t;cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		ll answer=0;
		for(int i=0;i<N;i++)
			if(i==d[d[i]] && d[i]!=i)
				answer+=i;
		cout<<answer<<endl;
	}
	return 0;
}
