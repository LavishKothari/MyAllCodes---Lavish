#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<long long int >sum;
vector<long long int >left;
vector<long long int >right;
long long int power(long long int a,long long int b)
{
	if(b==0) return 1;
	if(b==1) return a;
	long long int t=power(a,b/2);
	if(b&1)
		return t*t*a;
	else return t*t;
}

void findSol(int pan,long long int x)
{
	//printf("finding solution for (%d,%lld)\n",pan,x);
	if(x==0) return ;

	int it=lower_bound(sum.begin(),sum.end(),x)-sum.begin();
	/*
	   if(sum[it]==x && pan==1)
	   {
	   right.push_back(power(3,it));
	   return;
	   }		
	   else if (sum[it]==x && pan==2)
	   {
	   left.push_back(power(3,it));
	   return;
	   }
	   else*/
	{
		if(pan==1)
		{
			right.push_back(power(3,it));
			//findSol(2,power(3,it)-x);
		}
		else if(pan==2)
		{
			left.push_back(power(3,it));
			//findSol(1,power(3,it)-x);
		}
		if(power(3,it)-x<=0 && pan==1)
			findSol(1,x-power(3,it));
		else if(power(3,it)-x<=0 && pan==2)
			findSol(2,x-power(3,it));
		else if(power(3,it)-x>0 && pan==1)
			findSol(2,power(3,it)-x);
		else if(power(3,it)-x>0 && pan==2)
			findSol(1,power(3,it)-x);
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	long long int pro=1;
	sum.push_back(1);
	for(int i=1;sum[i-1]<10000000000;i++)
	{
		pro*=3;
		sum.push_back(sum[i-1]+pro);
	}
	while(t--)
	{
		long long int x;
		scanf("%lld",&x);
		left.erase(left.begin(),left.end());
		right.erase(right.begin(),right.end());
		findSol(1,x);
		printf("left pan: ");
		for(int i=0;i<left.size();i++)
			printf("%lld ",left[i]);		
		printf("\nright pan: ");
		for(int i=0;i<right.size();i++)
			printf("%lld ",right[i]);
		printf("\n\n");
	}
}
