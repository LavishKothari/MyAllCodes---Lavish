#include<stdio.h>
#include<string.h>
int main()
{
	int t,i;
	char str[101],a,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",str);
		a=str[0];
		b=str[1];
		if(a!=b)
		{
		    for(i=0;str[i];i++)
		    {
			    if(i%2==0 && str[i]==a)
				    continue;
			    else if(str[i]==b)
				    continue;
			    else break;
		    }
		    if(strlen(str)==i)
			    printf("YES\n");
		    else printf("NO\n");
		}
		else printf("NO\n");
	}
	return 0;
}
