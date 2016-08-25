#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b)
{	
	return *(int*)a-*(int*)b;
}
int main()
{
	int n,k,im[1001],nim[1001],sum=0,counter1=0,counter2=0,temp1,temp2,i;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&temp1,&temp2);
		sum+=temp1;
		if(temp2==1)
			im[counter1++]=temp1;
		else nim[counter2++]=temp1;
	}
	qsort(im,counter1,sizeof(int),cmp);
	for(i=0;i<counter1-k;i++)
		sum-=2*im[i];
	printf("%d\n",sum);
	return 0;
}
