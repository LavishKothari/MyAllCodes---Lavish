#include <bits/stdc++.h>
using namespace std;

int main()
{
	int test;
	cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		vector<int>arr(n);
		for(int i=0;i<n;i++)
			cin>>arr[i];
		int x;
		cin>>x;
		int ele=arr[x-1];
		sort(arr.begin(),arr.end());
		int index = lower_bound(arr.begin(),arr.end(),ele)-arr.begin();
		cout<<index+1<<endl;		
	}
	return 0;
}
