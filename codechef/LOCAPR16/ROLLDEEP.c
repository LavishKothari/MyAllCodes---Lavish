#include<stdio.h>

int main()
{
	int i,counter=0,max=0;
	char str[100001];
	scanf("%[^\n]s",str);
	for(i=0;str[i];i++)
	{
		if(str[i]=='(')
			counter++;
		if(str[i]==')')
			counter--;
		if(counter>max)
			max=counter;
	}
	counter=0;
	for(i=0;str[i];i++)
	{
		if(str[i]=='(')
			counter++;
		if(str[i]==')')
			counter--;
		if(counter==max)
		{
			for(i=i+1;str[i] && str[i]!=')';i++)
				printf("%c",str[i]);
			break;
		}
	}
	
	return 0;
}
