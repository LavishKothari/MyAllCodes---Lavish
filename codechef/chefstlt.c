#include<stdio.h>

int main()
{
	char a[101],b[101];
	int t,i,min=0,max=0;
	scanf("%d",&t);
	while(t--)
	{
		min=max=0;
		scanf(" %s %s",a,b);
		for(i=0;a[i];i++)
		{
			if(a[i]=='?' || b[i]=='?' || a[i]!=b[i])
				max++;
			if(a[i]!='?' && b[i]!='?' && a[i]!=b[i])
				min++;
		}
		printf("%d %d\n",min,max);
	}
	return 0;
}
