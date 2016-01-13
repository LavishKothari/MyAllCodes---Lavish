/*
	evaluate 1/1! + 1/3! + 1/5! + 1/7! + ... + 1/N! recursively.
*/
#include<stdio.h>
typedef long long int ll;
ll factorial(int n)
{
	if(n==1)
		return 1;
	return factorial(n-1)*n;
}
double evaluate(int n)
{
	if(n<=1) return 1;
	return 1/(double)factorial(n)+evaluate(n-2);
}
int main()
{
	int n;
	printf("Enter the value of n (n should be odd) : ");
	scanf("%d",&n);
	if(n&1) printf("the answer is : %g\n",evaluate(n));
	else printf("The number you entered is not odd...\n");
	return 0;
}
