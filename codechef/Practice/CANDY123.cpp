#include<bits/stdc++.h>
using namespace std;
int sol(int a,int b)
{	
	int eat=1;
	int flag=0;
	while(true)
	{
		if(flag==0)
		{
			if(a<eat)
				return 2;
			a-=eat;
		}
		else
		{
			if(b<eat)
				return 1;
			b-=eat;
		}
		eat++;
		flag=(!flag);
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(sol(a,b)==1)
			printf("Limak\n");
		else printf("Bob\n");
	}
	return 0;

}
