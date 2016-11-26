#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,x;
	cin>>n>>x;

	int req = (1<<n) - 1;
	if(x>=req)
	{
		cout<<x-req;
	}
	else 
	{
		cout<<req-x;
	}
	cout<<endl;
	return 0;

}
