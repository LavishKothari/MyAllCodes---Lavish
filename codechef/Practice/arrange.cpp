#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<map>
using namespace std;
map<int,int>g;
void populateG(int k)
{
	g.erase(g.begin(),g.end());
	for(int i=0;i<(1<<k);i++)
	{
		int rev=0;
		int ci=i;
		int counter=0;
		while(ci)
		{
			if(ci&1)
				rev=rev|(1<<(k-counter-1));
			ci=(ci>>1);
			counter++;
		}
		g[i]=rev;
	}
}
void myswap(char *str,int a,int b)
{
	char temp;
	temp=str[a];
	str[a]=str[b];
	str[b]=temp;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char str[1<<16];
		int k;
		scanf("%d %s",&k,str);
		populateG(k);
		int*flag=(int*)malloc(sizeof(int)*strlen(str));
		for(int i=0;str[i];i++)
			flag[i]=0;
		for(int i=0;str[i];i++)
		{
			if(flag[i]==0)
			{
				flag[i]=flag[g[i]]=1;
				myswap(str,i,g[i]);
			}
		}
		printf("%s\n",str);
	}
	return 0;
}
