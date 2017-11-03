#include<bits/stdc++.h>
using namespace std;
void buildST(vector<int>&sta,vector<int>&arr)
{
	int n=arr.size();
	for(int i=n;i<2*n;i++)
		sta[i]=arr[i-n];
	for(int i=n-1;i>0;--i)
		sta[i]=max(sta[i<<1],sta[i<<1|1]);
}
int query(vector<int>&sta,int l,int r)
{
	int n=sta.size()/2,m=INT_MIN;
	for(l+=n,r+=n;l<r;l>>=1,r>>=1)
	{
		if(l&1) m=max(m,sta[l++]);
		if(r&1) m=max(m,sta[--r]);
	}
	return m;
}
void sol(int n,int k,int p,vector<int>&v,string &s)
{
	if(n<k)
	{
		int sum=0;
		for(int i=0;i<v.size();i++)
			sum+=v[i];
		for(int i=0;i<s.size();i++)
			if(s[i]=='?')
				printf("%d\n",sum);
		return;
	}
	vector<int>sum(2*n-1,0);
	int csum=0;
	for(int i=0;i<k;i++)
		csum+=v[i];
	sum[0]=csum;
	for(int i=1;i<2*n-k;i++)
	{
		csum-=v[(i-1)%n];
		csum+=v[(i+k-1)%n];
		sum[i]=csum;
	}
	/*	
		for(int i=0;i<sum.size();i++)
		cout<<sum[i]<<" ";
		cout<<endl;
	//return;
	 */

	vector<int>sta(2*sum.size());
	buildST(sta,sum);


	int ci=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='!')
			ci=(ci-1+n)%n;
		else if(s[i]=='?')
			printf("%d\n",query(sta,ci,ci+n-k+1));
	}

}
int main()
{
	int n,k,p;
	scanf("%d%d%d",&n,&k,&p);
	vector<int>v(n);
	for(int i=0;i<n;i++)
		scanf("%d",&v[i]);
	string s;
	cin>>s;
	sol(n,k,p,v,s);
	/////////////////
	////////////////

	return 0;
}
