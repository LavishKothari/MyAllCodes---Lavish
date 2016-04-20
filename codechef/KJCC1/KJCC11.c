#include<stdio.h>
#include<stdlib.h>

int cmp(const void*a,const void*b)
{
	return *(int*)a-*(int*)b;
}
int binary_search(int*arr,int start,int end,int sval)
{
	int mid;
	if(start>end)
		return -1;
	mid=(start+end)/2;
	if(arr[mid]==sval)
		return 1;
	if(arr[mid]>sval)
		return binary_search(arr,start,mid-1,sval);
	else return binary_search(arr,mid+1,end,sval);
}
int main()
{
	int t,answer1,answer2,answer3,answer4,i,a,b,c,arr[100001],brr[100001],crr[100001];
	scanf("%d",&t);
	while(t--)
	{
		answer1=answer2=answer3=answer4=0;
		scanf("%d%d%d",&a,&b,&c);
		for(i=0;i<a;i++)
			scanf("%d",&arr[i]);
		for(i=0;i<b;i++)
			scanf("%d",&brr[i]); 
		for(i=0;i<c;i++)
			scanf("%d",&crr[i]);
		qsort(arr,a,sizeof(int),cmp);
		qsort(brr,b,sizeof(int),cmp);
		qsort(crr,c,sizeof(int),cmp);
		
		for(i=0;i<a;i++)
			if(binary_search(brr,0,b-1,arr[i])!=-1)
			{
				answer1++;
				if(binary_search(crr,0,c-1,arr[i])!=-1)
					answer4++;
			}
		for(i=0;i<b;i++)
			if(binary_search(crr,0,c-1,brr[i])!=-1)
				answer2++;
		for(i=0;i<a;i++)
			if(binary_search(crr,0,c-1,arr[i])!=-1)
				answer3++;
		if(answer1==0 && answer2==0 && answer3==0 && answer4==0)
			printf("0\n");
		else 
			printf("%d %d %d %d\n",answer1,answer2,answer3,answer4);		
	}
	return 0;
}
