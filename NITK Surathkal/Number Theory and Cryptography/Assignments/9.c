#include<stdio.h>
long long int power(int a,int b)
{
	int i;
	long long int pro=1;
	for(i=0;i<b;i++)
		pro=pro*a;
	return pro;
}
long long int findNumbers(int n)
{
	int i;
	long long int pro=1;
	if(n==1)
		return 9;
	for(i=0;i<n;i++)
		pro=pro*10;
	return 9*pro/10;
}
int extract(int num,int a)
{
	int cnum,digits=0;
	cnum=num;
	while(cnum)
	{
		digits++;
		cnum/=10;
	}
	a=digits-a-1;
	while(a--)
	{
		num/=10;
	}
	return num%10;
}
int findAnswer(int n)
{
	int num;
	int i;
	long long int counter;
	counter=0;
	for(i=1;;i++)
	{
		counter+=findNumbers(i)*i;
		if(counter>n)
			break;
	}
	//printf("this is a check %d\n",i);
	counter-=findNumbers(i)*i;
	i--;
	printf("counter = %lld  i = %d\n",counter,i);
	// now the number is i digits long
	// counter digits are skipped
	n=n-counter;
	if(i!=0)
	{
		num=power(10,i)-1+n/(i+1);
		if(n%(i+1)!=0)
			num++;
	}
	else
	{
		return n;
	}
	return extract(num,n%i);
}
int main()
{
	int n;
	printf("Enter the value of n\n");
	scanf("%d",&n);
	for(;n<2910;n++)
		printf("The answer is : %d\n",findAnswer(n));
	return 0;
}
