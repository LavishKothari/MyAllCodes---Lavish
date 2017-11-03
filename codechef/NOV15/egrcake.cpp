#include<stdio.h>
#include<stdlib.h>
#include<set>
using namespace std;
long long int gcd(long long int a,long long int b)
{
	if(b==0)
		return a;	
	return gcd(b,a%b);
}
long long int findAnswer1(long long int n,long long int m)
{
	if(m==0)
		return 1;	// this is perfectly fine
	if(m==1)
		return n;
	long long int g=gcd(m,n);
	if(g==1)
		return n;
	else return n/g;
	set<int>covered;
	long long int start=0;
	long long int answer=0;
	for(int i=0;i<n;i++)
	{
		start=(start+m)%n;
		if(covered.find(start)==covered.end())
		{
			covered.insert(start);
			answer++;
		}
		else break;
	}
	return answer;
}
long long int findAnswer(long long int n,long long int m) // this is wrong.
{
	if(m==0)
		return 1;	// this is perfectly fine

	if((n&1) && m%4==0)
		return n;
	else if((n&1) && m%2==0 && m%4!=0)
		return (2*n)/m;
	else if(n&1) return n;
	else
	{
		if(m&1)
		{
			if(m==n/2)
				return 2;
			else return n;
		}
		else
		{
			if(m==n/2)
				return 2;
			else return n/2;
		}
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int m,n;
		scanf("%lld%lld",&n,&m);
		/*
		   long long int answer=findAnswer(n,m);
		   if(answer==n)
		   printf("Yes ");
		   else
		   printf("No %lld ",answer);
		 */
		//for(int i=0;i<n;i++)
		{
			long long int answer1=findAnswer1(n,m);
			//printf("m = %d answer = ",i);
			if(answer1==n)
				printf("Yes\n");
			else
				printf("No %lld\n",answer1);
		}			
	}
	return 0;
}
