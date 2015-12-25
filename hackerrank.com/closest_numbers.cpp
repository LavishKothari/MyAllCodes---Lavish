#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	vector<int>arr(n);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	sort(arr.begin(),arr.end());
	int min=1<<30;
	vector<int>a,b;
	for(int i=1;i<n;i++)
	{
		if(arr[i]-arr[i-1]<=min)
		{
			min=arr[i]-arr[i-1];
		}
	}
	for(int i=1;i<n;i++)
	{
		if(arr[i]-arr[i-1]==min)
		{
			a.push_back(i-1);
			b.push_back(i);
		}
	}
	for(int i=0;i<a.size();i++)
		printf("%d %d ",arr[a[i]],arr[b[i]]);
	return 0;
}
