#include<iostream>
using namespace std;
long long int x,y;
long long int GCD(long long int a,long long int b)
{
	long long int temp,q,remainder,quotient,px,py,ca,cb;
	py=x=0;
	ca=a;
	cb=b;
	px=y=1;
	while(b!=0)
	{
		quotient=a/b;
		remainder=a%b;
		
		
		a=b;
		b=remainder;
		if(remainder==0)
			break;
		
		temp=x;
		x=px-x*quotient;
		px=temp;
		
		temp=y;
		y=py-y*quotient;
		py=temp;
		//printf("%lld = %lld * %lld + %lld * %lld\n",remainder,x,ca,y,cb);
		
	}
	return a;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long int m,a,b;
		cin>>m>>a>>b;
		long long int gcd=GCD(a,m);
		if(gcd!=1)
			cout<<-1<<" "<<endl;
		else
		{
			long long int answer=(-b*x)%m;
			if(answer<0)
				answer+=m;
			cout<<answer<<endl;
		} 
	}
	return 0;
}
