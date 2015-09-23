#include<stdio.h>
#include<string.h>

/*
	front 0
	back 1
	left 2
	right 3
 	top 4
	bottom 5
	
	1 - 0,4,2
	2 - 0,4,3
	3 - 4,1,3
	4 - 4,1,2
	5 - 0,2,5
	6 - 0,3,5
	7 - 5,3,1
	8 - 5,2,1
*/
void printAnswer(int*arr)
{
	if(arr[0]==arr[4] && arr[4]==arr[2])
	{
		printf("YES\n");
		return ;
	}
	if(arr[0]==arr[4] && arr[4]==arr[3])
	{
		printf("YES\n");
		return ;
	}
	if(arr[4]==arr[1] && arr[1]==arr[3])
	{
		printf("YES\n");
		return ;
	}
	if(arr[1]==arr[4] && arr[1]==arr[2])
	{
		printf("YES\n");
		return ;
	}
	if(arr[0]==arr[2] && arr[2]==arr[5])
	{
		printf("YES\n");
		return ;
	}
	if(arr[0]==arr[3] && arr[3]==arr[5])
	{
		printf("YES\n");
		return ;
	}
	if(arr[5]==arr[3] && arr[3]==arr[1])
	{
		printf("YES\n");
		return ;
	}
	if(arr[5]==arr[2] && arr[2]==arr[1])
	{
		printf("YES\n");
		return ;
	}
	printf("NO\n");
}
int main()
{
	int t,arr[6],i;
	char s[10];
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<6;i++)
		{
			scanf(" %s",s);
			if(strcmp(s,"black")==0)
				arr[i]=0;
			else if(strcmp(s,"blue")==0)
				arr[i]=1;
			else if(strcmp(s,"red")==0)
				arr[i]=2;
			else if(strcmp(s,"green")==0)
				arr[i]=3;
			else if(strcmp(s,"yellow")==0)
				arr[i]=4;
			else if(strcmp(s,"orange")==0)
				arr[i]=5;
			//printf("%d \n",arr[i]);
		}
		printAnswer(arr);
	}
	return 0;
}