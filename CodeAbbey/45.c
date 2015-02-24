#include<stdio.h>

int main()
{
	int i,arr[52],flag[52],a,b,temp;
	char suit[]={'C','D','H','S'};
	char rank[]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
	for(i=0;i<52;i++)
	{
		flag[i]=i;
		scanf("%d",&arr[i]);
		arr[i]%=52;
	}
	for(i=0;i<52;i++)
	{
		temp=flag[i];
		flag[i]=flag[arr[i]];
		flag[arr[i]]=temp;
	}
	for(i=0;i<52;i++)
	{
		a=flag[i]/13;
		b=flag[i]%13;
		printf("%c%c ",suit[a],rank[b]);
	}
	return 0;
}
