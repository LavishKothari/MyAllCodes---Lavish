#include<stdio.h>

int main()
{
	char str[100001];
	int t,flag[26],i,counter;
	scanf("%d",&t);
	while(t--)
	{
		counter=0;
		for(i=0;i<26;i++)
			flag[i]=0;
		scanf("%s",str);
		for(i=0;str[i];i++)
			flag[str[i]-'a']++;
		for(i=0;i<26;i++)
			if(flag[i]>0)
				counter++;
		if(counter%2==0)
			printf("Terrorist\n");
		else
			printf("Counter Terrorist\n");
	}
	return 0;
}
