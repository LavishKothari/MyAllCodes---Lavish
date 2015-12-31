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
	int i;
	double sum=0.0;
	for(i=0;i<n;i++)
	{
		sum+=1/(double)factorial(i+1);
	}
	return sum;
}
int main()
{
	int n;
	printf("Enter the value of n : ");
	scanf("%d",&n);
	printf("the answer is : %lf\n",evaluate(n));
	return 0;
	
}
