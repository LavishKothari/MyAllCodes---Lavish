#include<stdio.h>
#include<math.h>
int sum(int*a,int*b)
{
	return *a+*b;
}
int difference(int *a,int*b)
{
	return abs(*a-*b);
}
int main()
{
	int a,b;
	printf("Enter two numbers : ");
	scanf("%d %d",&a,&b);
	printf("sum = %d\n",sum(&a,&b));
	printf("difference = %d\n",difference(&a,&b));
	
	return 0;
}
