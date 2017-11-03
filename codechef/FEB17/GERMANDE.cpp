#include<bits/stdc++.h>
using namespace std;
int gs(vector<int>&c,int i,int j,int a,int b)
{
	int n=a*b;
	i%=n;j%=n;
	if(i==0)
		return c[j];
	if(i<=j)
		return c[j]-c[i-1];
	return c[j]+c[n-1]-c[i-1];
}
bool sol(vector<int>&v,int a,int b)
{
	vector<int>c(a*b,0);
	c[0]=v[0];
	for(int i=1;i<a*b;i++)
		c[i]=c[i-1]+v[i];
	for(int i=0;i<b;i++)
	{
		int count=0;
		for(int j=i;j<a*b;j+=b)
			if(gs(c,j,j+b-1,a,b)>b/2)
				count++;
		if(count>a/2)
			return true;
	}
	return false;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b;	
		scanf("%d%d",&a,&b);
		vector<int>v(a*b);
		for(int i=0;i<a*b;i++)
			scanf("%d",&v[i]);
		if(sol(v,a,b))
			printf("1\n");
		else printf("0\n");
	}
	return 0;
}
