#include<bits/stdc++.h>
using namespace std;
int sol(int a)
{
	if(a<38 || a%5==0)
		return a;
	int nm = (a/5+1)*5;
	if(nm-a<3)
		return nm;
	return a;
}
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int t;
		scanf("%d",&t);
		printf("%d\n",sol(t));
	}
	return 0;
}
