#include<bits/stdc++.h>
using namespace std;
int main()
{
	int s,t,a,b,m,n;
	scanf("%d%d%d%d%d%d",&s,&t,&a,&b,&m,&n);
	int apples=0,oranges=0;
	int d;
	for(int i=0;i<m;i++)
	{	
		scanf("%d",&d);
		if(a+d>=s && a+d<=t)	
			apples++;
	}
	for(int i=0;i<n;i++)
	{	
		scanf("%d",&d);
		if(b+d>=s && b+d<=t)	
			oranges++;
	}
	printf("%d\n%d\n",apples,oranges);		
	return 0;
}
