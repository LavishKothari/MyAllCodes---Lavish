#include<stdio.h>
#include<string>
using namespace std;
int main()
{
	int t;
	char str[10001];
	scanf("%d",&t);
	while(t--)
	{
		scanf(" %[^\n]s",str);
		string s(str);
		if(s.size()<10)
			printf("-1\n");
		else
		{
			int a=s.find("hackerrank");
			int b=s.find("hackerrank",s.size()-10);
			if(a==0 && b==s.size()-10)
				printf("0\n");
			else if(a==0)
				printf("1\n");
			else if(b==s.size()-10)
				printf("2\n");
			else printf("-1\n");
		}
		
	}
	return 0;
}
