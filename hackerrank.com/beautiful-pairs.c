#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int min(int a,int b)
{
	return a<b?a:b;
}
int main() {

	int n,answer,flag1,flag2,m,i,a[1001],b[1001],counta[1001],countb[1001];
	scanf("%d",&n);
	for(i=0;i<1001;i++)
		counta[i]=countb[i]=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",a+i);
		counta[a[i]]++;
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",b+i);
		countb[b[i]]++;
	}
	answer=0;
	for(i=0;i<1001;i++)
	{
		if(counta[i]!=0 && countb[i]!=0)
		{
			m=min(counta[i],countb[i]);
			answer+=m;
			counta[i]-=m;
			countb[i]-=m;
		}
	}
	flag1=0;flag2=0;
	for(i=0;i<1001;i++)
		if(counta[i]!=0)
			flag1=1;
	
    for(i=0;i<1001;i++)
		if(countb[i]!=0)
			flag2=1;
			
	if(flag1==0 && flag2==0)
		printf("%d\n",answer-1);
	else if(flag1==0)
		printf("%d\n",answer);
	else if(flag1 && flag2)
		printf("%d\n",answer+1);
    return 0;
}

