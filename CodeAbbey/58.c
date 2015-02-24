#include<stdio.h>

int main()
{
	int t,a,b,n;
	char suits[][20]={"Clubs\0","Spades\0","Diamonds\0","Hearts\0"};
	char ranks[][20]={"2\0","3\0","4\0","5\0","6\0","7\0","8\0","9\0","10\0","Jack\0","Queen\0","King\0","Ace\0"};
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		a=n/13;
		b=n%13;
		printf("%s-of-%s ",ranks[b],suits[a]);
	}
	return 0;
}
