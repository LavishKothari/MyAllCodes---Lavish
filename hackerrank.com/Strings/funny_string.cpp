#include<stdio.h>
#include<cmath>
#include<string.h>
using namespace std;
#define MAX 10000
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char str[MAX+1];
		char rstr[MAX+1];
		scanf(" %[^\n]s",str);
		int len=strlen(str);
		for(int i=0;i<len;i++)
			rstr[len-i-1]=str[i];
		rstr[len]='\0';
		int i;
		for(i=1;i<len;i++)
		{
			if(abs(str[i]-str[i-1])!=abs(rstr[i]-rstr[i-1]))
				break;
		}
		if(i!=len)
			printf("Not Funny\n");
		else printf("Funny\n");
	}
	return 0;
}

