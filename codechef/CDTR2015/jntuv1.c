#include<stdio.h>
int containsonly34(int n)
{
	while(n)
	{
		if(n%10!=3 && n%10!=4)
			return 0;
		n/=10;
	}
	return 1;
}
int main()
{
	int n,arr[101],i=1,counter=1;
	while(1)
	{
		i++;
		if(containsonly34(i))
		{
			arr[counter]=i;
			counter++;
		}
		if(counter==101)
			break;
	}
	scanf("%d",&n);
	printf("%d",arr[n]);
	return 0;
}
