#include<stdio.h>
int main()
{
	int i,flag;
	char str[60];
	while(gets(str))
	{
		flag=0;
		for(i=0;str[i];i++)
		{
			if(flag==1)
				printf("%c",str[i]);
			else if(str[i] && str[i+1] && str[i]=='/' && str[i+1]=='/')
			{
				flag=1;
				printf("%c",str[i]);
			}
			else if(str[i] && str[i+1] && str[i]=='-' && str[i+1]=='>')
			{
				printf(".");
				i++;
				if(!str[i])
					break;
			}
			else
				printf("%c",str[i]);
		}
		printf("\n");
	}
	
	return 0;
}
