/*
	Name - Lavish Kothari
		Computer Science and Engineering - Information Security
		NITK
	print the nth digit of the sequence 12345678910111213141516171819202122.....9899100101102....
*/
#include<stdio.h>
/*********/
long count_digits(long);
long count_digits_upto(long);
int d(long);
int ith(long,long);
long getNumber(long n);

int d(long n) // find nth number of the given sequence
{
	int ans;
	long i,tmp;
	i=getNumber(n);
	tmp=count_digits_upto(i-1);
	ans=ith(n-tmp,i);
	return ans;
}

int ith(long i,long n) // returns the ith digit of a number
{
	int digits,j;
	digits=count_digits(n);
	for(j=0;j<digits-i;j++)
		n/=10;
	return n%10;
}
long count_digits_upto(long n)
{
	long counter=0,i;
	for(i=1;i<=n;i++)
		counter+=count_digits(i);
	return counter;
}

long getNumber(long n)
{
	long i,counter=0,product;
	for(i=1;i<=n;i++)
	{
		counter+=count_digits(i);
		if(counter>=n)
			break;	
	}
	return i;
}

long count_digits(long i) //counts the number of digits in the number i
{
	int counter=0;
	while(i)
	{
		counter++;
		i/=10;
	}
	return counter;
}
/*********/
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
	a=digits-a;
	while(a>0)
	{
		num/=10;
		a--;
	}
	return num%10;
}
int findAnswer(int n)
{
	int num,cn;
	int i;
	long long int counter;
	counter=0;
	if(n<=9 && n>=0)
		return n;
	for(i=1;;i++)
	{
		counter+=findNumbers(i)*i;
		if(counter>n)
			break;
	}
	//printf("this is a check %d\n",i);
	counter-=findNumbers(i)*i;
	i--;
	if(i==0)
		return n;
	// now the number is i digits long
	// counter digits are skipped
	cn=n;
	n=n-counter;
	num=power(10,i)-1+n/(i+1);
	if(n%(i+1)!=0)
		num++;
	if(n==0)
		return extract(num,)
	return extract(num,(n-1)%(i+1)+1);
}
int main()
{
	int n;
	for(n=1;n<2895;n++)
		printf("%d = %d %d\n",n,findAnswer(n),d(n));
	return 0;
}
