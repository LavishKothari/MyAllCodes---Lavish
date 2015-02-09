#include<stdio.h>

int main()
{
	char str[100001];
	int test,count0,count1,i,start,end,answer;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%s",str);
		for(i=0;str[i] && str[i]=='1';i++);
		count0=count1=0;
		start=end=i;
		while(str[i])
		{
			while(str[i] && str[i]=='0')
			{
				count0++;
				i++;
			}
			end=i;
			while(str[i] && str[i]=='1')
			{
				count1++;
				i++;
			}
			if(count1>count0 && str[i])
			{
				count0=count1=0;
				start=end=i;
			}
		}
		printf("end=%d\n",end);
		printf("start=%d\n",start);
		answer=0;
		for(i=0;str[i];i++)
		{
			if(i>=start && i<end)
			{
				if(str[i]=='0')
					answer++;
			}
			else
			{
				if(str[i]=='1')
					answer++;
			}
		}
		printf("%d\n",answer);
	}
	return 0;
}
