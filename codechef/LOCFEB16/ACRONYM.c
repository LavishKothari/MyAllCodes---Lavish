#include<stdio.h>
int find(char*str)
{
	int i,count=0,c=0;
	for(i=0;str[i];i++)
	{
		c=0;
		for(;str[i] && str[i]>='A' && str[i]<='Z';c++,i++);
		if(c==i && c>1 && (str[i]==' ' || str[i]=='\0'))
			count++;
		else if(c>1 && str[i-c-1]==' ' && (str[i]==' ' || str[i]=='\0'))
			count++;
	}
	return count;
}
int main()
{
	char str[1001];
	scanf("%[^\n]s",str);
	printf("%d\n",find(str));
	return 0;
}
