#include<stdio.h>

int main()
{	
	char x[11],y[11];
	int t,i,flag;
	scanf("%d",&t);
	while(t--)
	{
		flag=0;
		scanf(" %s %s",x,y);
		for(i=0;x[i];i++)
		{
			if(x[i]=='?' || y[i]=='?')
				continue;
			if(x[i]==y[i])
				continue;
			flag=1;
			break;
		}
		if(flag==1)
			printf("No\n");
		else 
			printf("Yes\n");
	}
	return 0;
}
