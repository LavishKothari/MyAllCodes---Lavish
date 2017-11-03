#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100000
int min(int a,int b){return a>b?a:b;}
char flip(char a)
{
	if(a=='A') return 'B';
	else return 'A';
}
int main() 
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int alterationsa=0,alterationsb=0;
		char str[MAX+1];
		scanf("%s",str);
		char a,b;
		if(str[0]=='A') a='B';
		else b='A';
		for(int i=1;str[i];i++)
		{
			if(str[0]=='A')
			{
				if(str[i]==a)
				{
					a=flip(a);
				}
				else
					alterationsa++;
			}
			else
			{
				if(str[i]==b)
					b=flip(b);
				else alterationsb++;
			}
		}
		printf("%d\n",min(alterationsa,alterationsb));
	}
	return 0;
}

