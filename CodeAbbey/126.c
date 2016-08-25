#include<stdio.h>
typedef long long int ll;
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		printf("%lld ",(ll)i*(ll)i);
	return 0;
}
