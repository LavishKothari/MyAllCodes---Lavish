#include<stdio.h>
#include<stdlib.h>

int cmpfunc(const void*a,const void*b)
{
	return *(int*)a-*(int*)b;
}
long long int remove1(int*arr,int*flag,int len)
{
	int k,i,j;
	long long int answer=0;
	if(arr[0]!=1)
		return 0;
	for(i=0;i<len;i++)
		if(arr[i]!=1)
			break;
	if(i==len)
	{
		for(i=0;i<len;i++)
			flag[i]=0;
		return len/2;
	}
	for(j=0;j<i;j++)
	{
		flag[j]=0; // dead
		for(k=i;k<len && flag[k]==0;k++);
		if(k<len)
		{
			arr[i]=arr[i]+arr[k]+1;
			flag[k]=0;
		}
		else
		{
			arr[i]=arr[i]+1;
		}
		answer++;
	}
	if(j==i+1)
	{
		return len/2;
	}
	return answer;	
}
int main()
{
	int t,*arr,*flag,i,m,n,count;
	long long int answer=0;
	scanf("%d",&t);
	while(t--)
	{
		answer=0;
		scanf("%d%d",&n,&m);
		arr=(int*)malloc(sizeof(int)*m);
		flag=(int*)malloc(sizeof(int)*m);
		for(i=0;i<m;i++)
			flag[i]=1; // all are alive
		for(i=0;i<m;i++)
			scanf("%d",&arr[i]);
		qsort(arr,m,sizeof(int),cmpfunc);
		answer+=remove1(arr,flag,m);
		count=0;
		for(i=0;i<m;i++)
			if(flag[i])
				count++;
		if(count>0)
			answer+=count-1;
		printf("%lld\n",answer);
	}
	return 0;
}
