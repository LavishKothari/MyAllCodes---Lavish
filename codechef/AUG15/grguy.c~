#include<stdio.h>

int main()
{
	int t,counter,lane,i;
	char a[200001],b[200001];
	scanf("%d",&t);
	while(t--)
	{
		scanf(" %s %s",a,b);
		lane=1;
		counter=0;
		if(a[0]=='#')
			lane=2;
		for(i=0;a[i];i++)
		{
			if(a[i]=='#')
			{
				lane=2;
				break;
			}
			else if(b[i]=='#')
			{
				lane=1;
				break;
			}
		}
		for(i=0;a[i];i++)
		{
			if(a[i]==b[i] && b[i]=='#')
			{
				printf("No\n");
				break;
			}
			else
			{
				if(lane==1 && a[i]=='#')
				{
					lane=2;
					counter++;
				}
				if(lane==2 && b[i]=='#')
				{
					lane=1;
					counter++;
				}
			}
		}
		if(!a[i])
			printf("Yes\n%d\n",counter);
	}
	return 0;
}
