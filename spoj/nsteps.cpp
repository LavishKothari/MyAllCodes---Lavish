#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int x,y;
		cin>>x>>y;
		if(x==y)
		{
			if(x%2==0)
			{
				cout<<x*2<<endl;
			}
			else
			{
				cout<<x*2-1<<endl;
			}
		}
		else if(x-y==2)
		{
			x-=2;
			if(x%2==0)
			{
				cout<<x*2+2<<endl;
			}
			else
			{
				cout<<x*2+1<<endl;
			}
		}
		else
			cout<<"No Number"<<endl;
	}
	return 0;
}
