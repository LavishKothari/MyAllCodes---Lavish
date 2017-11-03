#include <bits/stdc++.h>
typedef long long int ll;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll c,d,l;
		scanf("%lld%lld%lld",&c,&d,&l);
		ll sc=(l-4*d)/4;
		if(l%4==0 && l>=d*4 && l<=(c+d)*4 && c-sc<=2*d)
			printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
