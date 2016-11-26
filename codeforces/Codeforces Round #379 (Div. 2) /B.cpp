#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
	ll a,b,c,d;
	cin>>a>>b>>c>>d;

	ll answer=0;
	answer=min(min(a,c),d)*256;
	a=a-answer/256;
	c=c-answer/256;
	d=d-answer/256;

	answer=answer+min(a,b)*32;
	cout<<answer<<endl;

	return 0;
}