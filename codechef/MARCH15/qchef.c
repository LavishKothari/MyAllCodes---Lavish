#include<stdlib.h>
#include<stdio.h>
int**table;
int main()
{
	int n,m,k,l,r,*arr,i,*maxArr,*minArr,max;
	/*
	table=(int**)malloc(sizeof(int)*9999);
	for(i=0;i<9999;i++)
		table[i]=(int*)malloc(sizeof(int)*(9999-i));
	*/
	scanf("%d%d%d",&n,&m,&k);
	arr=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	while(k--)
	{
		scanf("%d%d",&l,&r);
		maxArr=(int*)malloc(sizeof(int)*(m+1));
		minArr=(int*)malloc(sizeof(int)*(m+1));
		l--;r--;
		for(i=0;i<=m;i++)
		{
			maxArr[i]=0;
			minArr[i]=m+1;
		}
		for(i=l;i<=r;i++)
		{
			if(maxArr[arr[i]]<i)
				maxArr[arr[i]]=i;
			if(minArr[arr[i]]>i)
				minArr[arr[i]]=i;
		}
		max=0;
		for(i=0;i<=m;i++)
		{
			if(maxArr[i]!=0 && minArr[i]!=m+1)
			{
				if(max<maxArr[i]-minArr[i])
					max=maxArr[i]-minArr[i];
			}
		}
		printf("%d\n",max);
		free(maxArr);free(minArr);
	}
	return 0;
}
