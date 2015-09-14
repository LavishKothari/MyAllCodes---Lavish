#include<stdio.h>
int isLucky(long long int n)
{
	int i,counter=0;
	for(i=2;n!=1;i++)
		if(n%i==0)
		{
			counter++;
			if(counter>=3)
				return 1;
			while(n%i==0)
				n/=i;
		}
	if(counter>=3)
		return 1;
	return 0;
}
void fillArray(int*arr)
{
	int i,counter=0;
	for(i=30;counter!=1001;i++)
		if(isLucky(i))
			arr[counter++]=i;
}
int  main()
{
	int t,n,i;
	int arr[1001];
	fillArray(arr);
	/*
	for(i=0;i<1001;i++)
		printf("%d -> %d      ",i,arr[i]);
	*/
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n",arr[n-1]);
	}
	return 0;
}
