#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	int n,m,i,temp;long long int answer=0;
	vector<int>arr;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%d",&temp);
		arr.push_back(temp);
	}
	sort(arr.begin(),arr.end());
	for(i=0;i<n && arr[i]<=m;i++)
	{
		int index=lower_bound(arr.begin()+i+1,arr.end(),m-arr[i])-arr.begin();
		if(index-i-1>0)
			answer+=(index-i-1);
	}
	printf("%lld\n",answer);
	return 0;
}
