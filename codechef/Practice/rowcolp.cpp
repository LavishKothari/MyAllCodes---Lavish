#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	int *ar=(int*)malloc(sizeof(int)*n);
	int *ac=(int*)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++)
		ar[i]=ac[i]=0;
		
	while(q--)
	{
		char str[7];
		int a,value;
		scanf(" %s%d%d",str,&a,&value);
		if(str[0]=='R')
			ar[a-1]+=value;
		else
			ac[a-1]+=value;
	}
	int maxr=0;
	int maxc=0;
	
	for(int i=0;i<n;i++)
	{
		if(maxr<ar[i])
			maxr=ar[i];
		if(maxc<ac[i])
			maxc=ac[i];
	}
		
	printf("%d\n",maxr+maxc);
}
