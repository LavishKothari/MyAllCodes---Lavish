#include<stdio.h>
#include<math.h>
int main()
{
	double diff,hangle,mangle;
	int t,a,b;
	char str[6];
	scanf("%d",&t);
	while(t--)
	{
		scanf(" %s",str);
		a=(str[0]-'0')*10+(str[1]-'0');
		b=(str[3]-'0')*10+(str[4]-'0');
		hangle=a*30+b/2.0;
		mangle=b*6;
		diff=fabs(hangle-mangle);
		if(diff>=180)
			diff=diff-180;
		if(diff-(int)diff==0 && ((int)diff)%5==0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
