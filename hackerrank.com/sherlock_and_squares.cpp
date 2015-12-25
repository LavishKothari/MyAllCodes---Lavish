#include<stdio.h>
#include<math.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		int sa=(int)sqrt(a);
		int sb=(int)sqrt(b);
		printf("%d\n",sb-sa+(sa*sa==a?1:0));
	}
	return 0;
}
