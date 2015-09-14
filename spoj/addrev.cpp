#include<iostream>
using namespace std;
int reverse(int n)
{
	int rev=0;
	while(n)
	{
		rev=rev*10+n%10;
		n/=10;
	}
	return rev;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a,b;
		cin>>a>>b;
		cout<<reverse(reverse(a)+reverse(b))<<endl;
	}
	return 0;
}
