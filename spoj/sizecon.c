#include<stdio.h>
int main()
{
	int t,s=0,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(n>0) s+=n;
	}
	printf("%d",s);
	return 0;
}
