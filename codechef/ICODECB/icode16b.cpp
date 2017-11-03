#include<stdio.h>
#include<algorithm>
using namespace std;
char a[100001],b[100001];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf(" %s%s",a,b);
		int counter=0;
		int f[26]={0},h[26]={0},g[26]={0};
		int len=0;
		for(int i=0;a[i];++i,++len)
		{
			if(a[i]==b[i])
			{
				g[a[i]-'a']++;
				counter++;
			}
			++f[a[i]-'a'];
			++h[b[i]-'a'];
		}
		int sum=0;
		for(int i=0;i<26;i++)
		{
			f[i]=f[i]-g[i];
			h[i]=h[i]-g[i];

			sum+=min(f[i],h[i]);
		}
		printf("%dN%dJ%dS\n",counter,sum,len-counter-sum);
	}
	return 0;
}
