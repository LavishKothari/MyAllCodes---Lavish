#include<stdio.h>
int n,m;
int findAnswer(int a,int b,int p)
{
	if(a==n && b==m && p==1)
		return 2;
	if(a==n && b==m && p==2)
		return 1;
	
	a=a+(n-1)%4;
	b=b+(m-1)%3;
	
}
int main()
{
	int t;scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		printf("%d",findAnswer(n,m,1));
	}
	return 0;
}
