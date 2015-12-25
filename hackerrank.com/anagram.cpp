#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int findAnswer(char*a,char*b)
{
	int x[26],y[26];
	for(int i=0;i<26;i++)
		x[i]=y[i]=0;
	for(int i=0;a[i];i++)
		x[a[i]-'a']++;
	for(int i=0;b[i];i++)
		y[b[i]-'a']++;
	int answer=0;
	for(int i=0;i<26;i++)
	{
		if(x[i] && x[i]>y[i])
			answer+=x[i]-y[i];
	}
	return answer;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char str[10001];
		scanf("%s",str);
		int len=strlen(str);
		if(len&1)
		{
			printf("-1\n");
		}
		else 
		{
			char *a,*b;
			a=(char*)malloc(sizeof(char )*len/2+1);
			b=(char*)malloc(sizeof(char )*len/2+1);
			int i;
			for(i=0;i<len;i++)
			{
				if(i<len/2)
					a[i]=str[i];
				else b[i-len/2]=str[i];
			}
			a[len/2]='\0';
			b[len/2]='\0';
			printf("%d\n",findAnswer(a,b));
			free(a);
			free(b);
		}
	}
	return 0;
}
