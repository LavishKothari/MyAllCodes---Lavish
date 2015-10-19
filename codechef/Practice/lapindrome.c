#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

void is_equal(char*,char*,int);
void is_lapindrome(char*);

void main()
{
	int t,i;
	char**str;
	clrscr();
	scanf("%d",&t);

	str=(char**)malloc(sizeof(char*)*t);

	for(i=0;i<t;i++)
	{
		fflush(stdin);
		gets(str[i]);

	}

	for(i=0;i<t;i++)
		is_lapindrome(str[i]);

	getch();
}

void is_lapindrome(char*str)
{
	int length,i,j;
	char *str1,*str2;
	length=strlen(str);


	for(i=0;i<=length/2-1;i++)
		str1[i]=str[i];
	str1[i]='\0';

	if(length%2==0)
		i=length/2;
	else
		i=length/2 + 1;

	for(j=0;i<length;i++,j++)
		str2[j]=str[i];
	str2[i]='\0';

	is_equal(str1,str2,length/2);
}

void is_equal(char*a,char*b,int length)
{
	int i,counter=0,j;
	char tmp;
	for(i=0;i<length;i++)
	{
		for(j=i;j<length;j++)
		{
			if(a[i]==b[j])
			{
				counter++;
				tmp=b[j];
				b[j]=b[i];
				b[i]=tmp;
				break;
			}
		}
	}
	if(counter==length)
		printf("YES\n");
	else
		printf("NO\n");
}
