#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

struct element
{
	ll e;
	int wt;
};
bool cmp(const struct element&a,const struct element&b)
{
	return a.wt < b.wt;
}
ll power(int a,int b)
{
	ll p=1;
	for(int i=0;i<b;i++)
		p=p*a;
	return p;
}
int extract(ll n,int start ,int end)
{
	ll x=power(10,start-1);
	ll y=power(10,5);
	n=n/x;
	return n%y;
}
int main()
{
	int n;
	//cin>>n;
	scanf("%d",&n);
	vector<ll>arr(n);
	for(int i=0;i<n;i++)
		scanf("%lld",&arr[i]);
		//cin>>arr[i];

	int i=1;
	while(true)
	{
		int start,end;
		end=i*5;
		start=5*(i-1)+1;

		vector<struct element>ele(n);
		int counter=0;
		for(int j=0;j<n;j++)
		{
			ele[j].e = arr[j];
			ele[j].wt = extract(arr[j],start,end);
			if(ele[j].wt == 0)
				counter++;
		}
		if(counter==n)
		{
			/*
			for(int j=0;j<n;j++)
				cout<<ele[j].e<<" ";
			cout<<endl;
			*/
			break;
		}
		stable_sort(ele.begin(),ele.end(),cmp);
		for(int j=0;j<n;j++)
		{
			//cout<<ele[j].e<<" ";
			printf("%lld ",ele[j].e);
			arr[j]=ele[j].e;
		}
		printf("\n");
		//cout<<endl;
		i++;
	}
	return 0;
}