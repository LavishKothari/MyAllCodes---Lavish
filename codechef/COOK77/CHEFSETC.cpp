#include <bits/stdc++.h>

using namespace std;

bool isPossible(int a,int b,int c,int d)
{
	if(!a || !b || !c || !d)
		return true;
	if(!(a+b) || !(a+c) || !(a+d) || !(c+b) || !(d+b) || !(c+d))
		return true;
	if(!(a+b+c) || !(a+b+d) || !(a+d+c) || !(d+b+c))
		return true;
	if(!(a+b+c+d))
		return true;
	return false;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		if(isPossible(a,b,c,d))
			cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
