#include<math.h>
#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a;
		cin>>a;
		int counter=0;
		int i=0;
		while(true)
		{
			i++;
			if(a/(long long int )pow(5,i)==0)
				break;
			counter+=a/(long long int)pow(5,i);
		}
		cout<<counter<<endl;
	}
	return 0;
}
