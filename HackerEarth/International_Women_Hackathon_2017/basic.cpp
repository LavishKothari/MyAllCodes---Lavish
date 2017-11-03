#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

////////////////////////////////////////////////////////////////////////////////////////////////////////////

string multiply(string &a,string &b)
{
	{ // removing trailing zeros
		int counter;
		for(counter=0;counter<a.size() && a[counter]=='0';counter++);
		if(counter==a.size())
			a="0";
		else a=a.substr(counter);

		for(counter=0;counter<b.size() && b[counter]=='0';counter++);
		if(counter==b.size())
			b="0";
		else b=b.substr(counter);
	}
	int m=a.size(),n=b.size();
	string result(m*n+10,'0');
	int carry=0;
	int initk=result.size();
	for(int i=m-1;i>=0;i--) // for a
	{
		int k=initk=initk-1;
		for(int j=n-1;j>=0;j--,k--) // for b
		{
			int x = (a[i]-'0')*(b[j]-'0')+carry+result[k]-'0';
			carry=x/10;
			x%=10;
			result[k] = x+'0';
		}
		while(carry)
		{
			int x=carry+result[k]-'0';
			carry=x/10;
			x%=10;
			result[k]=x+'0';
			k--;
		}
	}
	int x=0;
	for(;x<result.size() && result[x]=='0';x++);
	if(x==result.size())
		return "0";
	return result.substr(x);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

string add(string &a,string &b)
{
	{ // removing the leading zeros
		int x;
		for(x=0;x<a.size() && a[x]=='0';x++);
		if(x==a.size())
			a="0";
		else a=a.substr(x);

		for(x=0;x<b.size() && b[x]=='0';x++);
		if(x==b.size())
			b="0";
		else b=b.substr(x);
	}
	int m=a.size(),n=b.size();
	string result(max(m,n)+1,'0');
	int k=result.size()-1;
	int carry=0;
	for(int i=m-1,j=n-1;i>=0 || j>=0 || carry;i--,j--)
	{
		int x=carry;
		if(i>=0) x+=a[i]-'0';
		if(j>=0) x+=b[j]-'0';
		carry=x/10;
		result[k--]=(x%10)+'0';
	}
	{ // removing leading zeros of result
		int x;
		for(x=0;x<result.size() && result[x]=='0';x++);
		if(x==result.size())
			result="0";
		else result=result.substr(x);
	}
	return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define MAX 1000001
bitset<MAX> isPrime;
void populatePrime()  // seive of eratosthenes
{
	isPrime.reset();
	isPrime.flip();
	isPrime[0] = isPrime[1] = 0;
	for(int i=2; i*i<=MAX; i++) 
		if(isPrime[i]) 
			for(int j=i*i; j<MAX; j = j+i) 
				isPrime[j] = 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

ll power(ll a,ll b,ll c)  // returns (a**b) % c
{
	if(b==0)	
		return 1;
	ll temp=power(a,b/2,c);
	if(b&1)
		return (((temp*temp)%c)*a)%c;
	return (temp*temp)%c;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

ll gcd(ll a,ll b)
{
	if(!b)
		return a;
	return gcd(b,a%b);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

ll modinv(ll a,ll mod) // mod should be prime and a and mod should be coprime
{
	return power(a,mod-2,mod);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

// this function returns inverse of a mod b
ll extended_euclidean(ll a,ll b) // a and b should be coprime, b need not to be prime.
{
	ll temp,q,remainder,quotient,px,py,ca,cb,x,y;
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
	// a 		stores			GCD
	// x 		stores			modular inverse of a with respect to b (a and b are arguments passed)
	return (x+cb)%cb;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

void populateFact(vector<ll>&fact,int max,ll mod)
{
	fact=vector<ll>(max+1);
	fact[0]=fact[1]=1;
	for(int i=2;i<=max;i++)
		fact[i]=(fact[i-1]*i)%mod;
}

ll nck(ll n,ll k,ll mod,vector<ll>&fact) // fact represents the factorial array
{
	return ((fact[n]*modinv(fact[k],mod))%mod*modinv(fact[n-k],mod))%mod;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	vector<ll>fact;
	int n=301,k=150,mod=1000000007;
	populateFact(fact,4000,mod);
	cout<<nck(n,k,mod,fact)<<endl;
	return 0;
}
