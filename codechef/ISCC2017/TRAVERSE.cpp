#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void solve(int m)
{
	int x,y;
	if(m%3==0)
	{
		x=m/3;
		y=m/3*2;
	}
	else if(m%3==1)
	{
		y=m/3*2;
		x=m/3+1;
	}
	else if(m%3==2)
	{
		x=m/3+1;
		y=m/3*2+1;
	}
	printf("%d %d\n",x,y);
}

int main()
{
	int m,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&m);
		solve(m);
	}
	return 0;
}
