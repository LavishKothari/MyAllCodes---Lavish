#include<iostream>
using namespace std;
int main()
{
	int t,s=0,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n>0) s+=n;
	}
	cout<<s;
	return 0;
}
