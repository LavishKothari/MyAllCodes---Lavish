#include<stdlib.h>
#include<stdio.h>
int findEquivalent(char c)
{
	switch(c)
	{
		case 'm':
			return 1000;
		case 'c':
			return 100;
		case 'x':
			return 10;
		case 'i':
			return 1;
	}
}
int findValue(char *s)
{
	int i,answer=0;
	for(i=0;s[i];i++)
	{
		if(s[i]>='2' && s[i]<='9')
		{
			answer+=findEquivalent(s[i+1])*(s[i]-'0');
			i++;
		}else answer+=findEquivalent(s[i]);
	}
	return answer;
}
char returnChar(int n)
{
	switch(n)
	{
		case 4:
			return 'm';
		case 3:
			return 'c';
		case 2:
			return 'x';
		case 1:
			return 'i';	
	}
}
int power(int a,int b)
{
	int i,po=1;
	for(i=0;i<b;i++)
		po=po*a;
	return po;
}
void printString(int n)
{
	char temp2;
	int digits=0,i,cn,counter=0,temp1;
	char *s;
	s=(char*)malloc(sizeof(int)*10);
	cn=n;
	while(cn)
	{
		digits++;
		cn/=10;
	}
	while(digits)
	{
		temp1=n/power(10,digits-1);
		temp2=returnChar(digits);
		if(temp1==1)
		{
			s[counter++]=temp2;
		}
		else if(temp1==0){}
		else 
		{
			s[counter++]=temp1+'0';
			s[counter++]=temp2;
		}
		if(temp1!=0)n%=power(10,digits-1);
		digits--;
	}
	s[counter]='\0';
	printf("%s\n",s);
	free(s);
}
int main()
{
	char s1[10],s2[10];
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s%s",s1,s2);
		printString(findValue(s1)+findValue(s2));
	}
	return 0;
}
