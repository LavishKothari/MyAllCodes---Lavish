#include<stdio.h>
#include<string.h>
#define MAX 1000010
char a[MAX],b[MAX];
int max(int x,int y)
{
	return x>y?x:y;
}
int findAnswer()
{
	int i,answer;
	int f0=0,f1=0,c0=0,c1=0;
	for(i=0;a[i];i++)
	{
		if(a[i]=='0') c0++;
		else c1++;
		if(a[i]!=b[i] && a[i]=='0') f0++;
		if(a[i]!=b[i] && a[i]=='1') f1++;
	}
	if(f0==0 && f1==0) return 0;
	if(f0==f1) return f0;
		
	answer=max(f0,f1);
	if(answer==f0 && c1!=0) return answer;
	if(answer==f1 && c0!=0) return answer;
	return -1;
}

int main()
{
	int t,answer;
	scanf("%d",&t);
	while(t--)
	{
		scanf(" %s%s",a,b);
		answer=findAnswer();
		if(answer!=-1)
			printf("Lucky Chef\n%d\n",answer);
		else printf("Unlucky Chef\n");
	}
	return 0;
}

