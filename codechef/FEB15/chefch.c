#include<stdio.h>

int countChanges(char str[],char a,char b)
{
	int answer=0,i;
	for(i=0;str[i];i++)
		if((i&1) && str[i]!=b) // for odd place
			answer++;
		else if((!(i&1)) && str[i]!=a)// for even place
			answer++;
	return answer;
}

int main()
{
	char str[100001];
	int test,a,b;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%s",str);
		a=countChanges(str,'+','-');
		b=countChanges(str,'-','+');
		printf("%d\n",(a<b?a:b));
	}
	return 0;
}
