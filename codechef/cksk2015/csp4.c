#include<stdio.h>

int main()
{
	int t,flag[200],i,max;
	char str1[1001],str2[1001],maxchar;
	scanf("%d",&t);
	while(t--)
	{
		scanf(" %s",str1);
		scanf(" %s",str2);
		for(i=0;i<200;i++)
			flag[i]=0;
		for(i=0;str1[i];i++)
			flag[str1[i]]++;
		for(i=0;str2[i];i++)
			flag[str2[i]]++;
		max=0;
		for(i='A';i<='Z';i++)
			if(flag[i]>max)
			{
				maxchar=(char)i;
				max=flag[i];			
			}
		for(i='a';i<='z';i++)
			if(flag[i]>max)
			{
				maxchar=(char)i;
				max=flag[i];			
			}
		printf("%c\n",maxchar);
	}
	return 0;
}
