#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 5000001
void populate(vector<int>&a)
{
	vector<int>len(N,0);
	len[1]=1;
	for(int i=2;i<N;i++)
	{
		ll num=i;
		int count=1;
		while(num!=1LL)
		{
			if(num<a.size() && len[num])
			{
				count+=len[num]-1;
				break;
			}
			if(num&1) num = num*3+1;
			else num>>=1;
			count++;
			//cout<<"hello\n";
		}
		len[i]=count;
		a[i]=len[a[i-1]]>count?a[i-1]:i;
	}
}
int main()
{
	vector<int>a(N,0);
	populate(a);
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<a[n]<<endl;
	}
	return 0;
}
