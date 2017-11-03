#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define N 100001
int main()
{
	int n;
	scanf("%d",&n);
	vector<int>a(n);
	vector<int>cnt(N,0);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);

	sort(a.begin(),a.end());

	for(int i=0;i<n;)
	{
		int ci=i;
		while(ci<n && a[i]==a[ci])
			ci++;
		int freq=ci-i;
		for(int j=a[i];j<N;j+=a[i])
			cnt[j]+=freq;
		i=ci;
	}
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int number,k;
		scanf("%d%d",&number,&k);
		//cout<<cnt[number]<<endl;
		if(cnt[number]>=k)
			printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
