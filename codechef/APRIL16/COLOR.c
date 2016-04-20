#include<stdio.h>
int max(int a,int b,int c)
{
	return a>b?(a>c?a:c):(b>c?b:c);
}
int main()
{
	char s[100001];
	int t,r,g,b,n,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%s",s);
		r=b=g=0;
		for(i=0;s[i];i++)
		{
			if(s[i]=='R') r++;
			if(s[i]=='G') g++;
			if(s[i]=='B') b++;
		}
		printf("%d\n",n-max(r,g,b));
	}
	return 0;
}
