#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<vector>
#define N 12
using namespace std;

int fact[12];

int main()
{
	fact[0]=1;
	for(int i=1;i<=11;i++)
		fact[i]=fact[i-1]*i;
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<char>x;
		for(char i='A';i<='L';i++)
			x.push_back(i);
		
		for(int i=N-1;i>=0;i--)
		{
			cout<<x[n/fact[i]];
			x.erase(find(x.begin(),x.end(),x[n/fact[i]]));
			n=n%fact[i];
		}
		cout<<endl;
	}
	return 0;
}
