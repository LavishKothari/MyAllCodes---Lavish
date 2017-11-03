#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int>arr(n);
		vector<int>count(1000001,0);
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			count[arr[i]]++;
		}
		int ma=INT_MIN;
		int mi=INT_MAX;
		for(int i=0;i<count.size();i++)
		{
			if(count[i]!=0 && count[i]<mi)
				mi=count[i];
			if(count[i]!=0 && count[i]>ma)
				ma=count[i];
		}
		if(ma!=mi)
			cout<<ma-mi<<endl;
		else cout<<"-1\n";
	}
	return 0;
}
