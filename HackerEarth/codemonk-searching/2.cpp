#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	vector<int>arr(n);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);

	sort(arr.begin(),arr.end());

	int q;
	scanf("%d",&q);
	while(q--)
	{
		int type,x;
		scanf("%d%d",&type,&x);
		if(type==0)
		{
			int index=lower_bound(arr.begin(),arr.end(),x)-arr.begin();
			printf("%d\n",n-index);
		}
		else
		{
			int index=upper_bound(arr.begin(),arr.end(),x)-arr.begin();
			printf("%d\n",n-index);		
		}
	}
	return 0;
}
