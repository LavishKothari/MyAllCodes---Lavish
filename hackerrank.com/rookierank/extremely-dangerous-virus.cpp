#include<iostream>
using namespace std;
typedef unsigned long long int ull;
#define MOD 1000000007
ull power(ull a,ull b)
{
	if(b==0) return 1;
	if(b==1)
		return a;
	ull temp=power(a,b/2);
	if(b&1)
		return (((temp*temp)%MOD)*a)%MOD;
	else return (temp*temp)%MOD;
}

int main()
{
	long long int a,b,t;
	cin>>a>>b>>t;

	cout<<power((a+b)/2,t)<<endl;

	return 0;
}
