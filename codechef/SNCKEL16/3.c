#include<stdio.h>
typedef long long int ll;
long long int M,N;
long long int GCD(long long int a,long long int b)
{
	long long int temp,q,remainder,quotient,px,py,ca,cb;
	py=M=0;
	ca=a;
	cb=b;
	px=N=1;
	while(b!=0)
	{
		quotient=a/b;
		remainder=a%b;
		
		
		a=b;
		b=remainder;
		if(remainder==0)
			break;
		
		temp=M;
		M=px-M*quotient;
		px=temp;
		
		temp=N;
		N=py-N*quotient;
		py=temp;
		printf("%lld = %lld * %lld + %lld * %lld\n",remainder,M,ca,N,cb);
		
	}
	return a;
}
int findAnswer(ll n , ll c)
{
	ll p,r,x,k,X,Y;
	ll i,A,B,C,d;
	double G,H,temp;
	if(n==1)
		return 1;
	
	p=2*c/n;
	r=p%(n-1);
	
	
	if(n%2==0 && c%2==1)
		return 0;
	
	if(c<(n*(n+1))/2)
		return 0;
	if(c==(n*(n+1))/2)
		return 1;
	
	if(2*c%n!=0)
		return 0;

	A=2;B=n-1;C=p;
	
	d=GCD(A,B); // YOU GOT M AND N
	
	G=-(double)N*C/B;
	H=(double)M*C/A;
	
	//H-G> && (int)H-(int)G>0
	
	for(i=(G==(int)G?(int)G+1:(int)G);i<(H==(int)H?(int)H+1:(int)H);i++)
		return 1;
	temp=G;
	G=H;
	H=temp;
	for(i=(G==(int)G?(int)G+1:(int)G);i<(H==(int)H?(int)H+1:(int)H);i++)
		return 1;
	return 0;
}

int main()
{
	ll t,n,c;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&c);
		if(findAnswer(n,c))
			printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
