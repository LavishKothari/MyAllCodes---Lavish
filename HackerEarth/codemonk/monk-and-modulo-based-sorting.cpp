#include <bits/stdc++.h>

using namespace std;

int k;


struct element
{
	int e,copy;
};
bool cmp(const struct element&a,const struct element&b)
{
	return a.copy < b.copy;
}


int main()
{
	int n;
	cin>>n>>k;
	vector<struct element>arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i].e;
		arr[i].copy=arr[i].e%k;
	}
	stable_sort(arr.begin(),arr.end(),cmp);
	for(int i=0;i<n;i++)
		cout<<arr[i].e<<" ";
	cout<<endl;
	return 0;
}