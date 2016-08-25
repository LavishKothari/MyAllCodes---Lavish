#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b)
{	
	return *(int*)b-*(int*)a;
}
int main()
{
	int n,k,im[1001],nim[1001],sum=0,counter1,counter2;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%d",&temp1,&temp2);
		sum+=temp1;
		if(temp2==1)
			im[counter1++]=temp1;
		else nim[counter2++]=temp1;
	}
	qsort(im,counter,sizeof(int),cmp);
	for(i=0;i<k;i++)
		sum-=im[i];
	printf("%d\n",sum);
	return 0;
}
