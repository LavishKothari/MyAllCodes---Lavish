#include<stdio.h>
#include<math.h>
int max(int*a,int*b)
{
	return *a>*b?*a:*b;
}
int main()
{
	int a,b;
	printf("Enter two numbers : ");
	scanf("%d %d",&a,&b);
	printf("max = %d\n",max(&a,&b));	
	return 0;
}
