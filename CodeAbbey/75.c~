#include<stdio.h>
int cmpfunc(const void*a, const void*b)
{
	return *(int*)a-*(int*)b;
}
int isBigStraight(int*arr)
{
	if(arr[0]==2 && arr[1]==3 && arr[2]==4 && arr[3]==5 && arr[4]==6)
		return 1;
	return 0;
}
int isSmallStraight(int*arr)
{
	if(arr[0]==1 && arr[1]==2 && arr[2]==3 && arr[3]==4 && arr[4]==5)
		return 1;
	return 0;	
}
int isFullHouse(int*arr)
{
	if(arr[0]==arr[1] && arr[2]==arr[3] && arr[4]==arr[3])
		return 1;
	if(arr[0]==arr[1] && arr[1]==arr[2] && arr[4]==arr[3])
		return 1;
	return 0;
}
int isTwoPairs(int*arr)
{
	if(arr[0]==arr[1] && arr[2]==arr[3])
		return 1;
	if(arr[0]==arr[1] && arr[4]==arr[3])
		return 1;
	if(arr[2]==arr[1] && arr[4]==arr[3])
		return 1;
	return 0;
}
int isYatch(int*arr)
{
	if(arr[0]==arr[1] && arr[1]==arr[2] && arr[2]==arr[3] && arr[3]==arr[4])
		return 1;
	return 0;
}
int isFour(int*arr)
{
	if(arr[0]==arr[1] && arr[1]==arr[2] && arr[2]==arr[3])
		return 1;
	if(arr[3]==arr[4] && arr[1]==arr[2] && arr[2]==arr[3])
		return 1;
	return 0;
}
int isThree(int*arr)
{
	if(arr[0]==arr[1] && arr[1]==arr[2])
		return 1;
	if(arr[2]==arr[1] && arr[3]==arr[2])
		return 1;
	if(arr[4]==arr[3] && arr[3]==arr[2])
		return 1;
	return 0;
}
int isPair(int*arr)
{
	if(arr[0]==arr[1])
		return 1;
	if(arr[2]==arr[1])
		return 1;
	if(arr[2]==arr[3])
		return 1;
	if(arr[4]==arr[3])
		return 1;
	return 0;
}

int main()
{
	int t,arr[5],i;
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<5;i++)
			scanf("%d",&arr[i]);
		qsort(arr,5,sizeof(int),cmpfunc);
		if(isBigStraight(arr))
			printf("big-straight ");
		else if(isSmallStraight(arr))
			printf("small-straight ");
		else if(isYatch(arr))
			printf("yacht ");
		else if(isFour(arr))
			printf("four ");
		else if(isFullHouse(arr))
			printf("full-house ");
		else if(isTwoPairs(arr))
			printf("two-pairs ");
		else if(isThree(arr))
			printf("three ");
		else if(isPair(arr))
			printf("pair ");
		else 
			printf("none");
	}
	return 0;
}


/*
two-pairs two-pairs pair pair pair two-pairs big-straight small-straight three two-pairs small-straight pair small-straight two-pairs pair pair pair three pair three two-pairs small-straight pair small-straight big-straight pair three two-pairs big-straight big-straight two-pairs

two-pairs big-straight small-straight small-straight three pair small-straight big-straight big-straight small-straight small-straight big-straight three small-straight two-pairs big-straight pair full-house pair small-straight three pair small-straight big-straight yatch

two-pairs big-straight small-straight small-straight three pair small-straight big-straight big-straight small-straight small-straight big-straight three small-straight two-pairs big-straight pair full-house pair small-straight three pair small-straight big-straight yacht

*/
