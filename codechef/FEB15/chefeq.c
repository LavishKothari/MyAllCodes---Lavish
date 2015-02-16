#include<stdio.h>
int main()
{
	 int test,arr[100001],i,temp,max,n;
	 scanf("%d",&test);
	 while(test--)
	 {
	 	for(i=0;i<100001;i++)
	 		arr[i]=0;
	 	scanf("%d",&n);
	 	for(i=0;i<n;i++)
	 	{
	 		scanf("%d",&temp);
	 		arr[temp]++;
	 	}
	 	max=0;
	 	for(i=0;i<100001;i++)
	 	{
	 		if(arr[i]>max)
	 			max=arr[i];
	 	}
	 	printf("%d\n",(n-max));
	 }
	return 0;
}
