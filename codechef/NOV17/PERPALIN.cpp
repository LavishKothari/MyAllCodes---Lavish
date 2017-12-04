#include<bits/stdc++.h>
using namespace std;
void solve(int n,int p)
{
	if(p==1 || p==2)
	{
		printf("impossible\n");
		return;
	}
	string s(p,'a');
	if(p&1)
		s[p/2]='b';
	else
		s[p/2]=s[p/2-1]='b';
	
	for(int i=0;i<n/p;i++)
		printf("%s",s.c_str());
	printf("\n");
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,p;
		scanf("%d%d",&n,&p);
		solve(n,p);
	}
	return 0;
}
