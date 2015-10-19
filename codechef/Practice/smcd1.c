#include<stdio.h>
int main()
{
	int t,i,counter;
	char str[100001];
	scanf("%d",&t);
	//while(t--)
	{
		counter=0;
		scanf("%s",str);
		for(i=0;str[i];i++)
			if(str[i]=='.')
				counter++;
		printf("%d\n",counter);
	}
	return 0;
}
