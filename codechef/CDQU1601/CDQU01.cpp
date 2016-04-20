#include<stdio.h>
#include<map>
#include<iostream>
#include<string>
using namespace std;
int main()
{
	int t,q;
	char name[101],nick[101];
	scanf("%d%d",&t,&q);
	map<string,string>m;
	while(t--)
	{	
		string na;
		string ni;
		cin>>na>>ni;
		m[ni]=na;
	}
	while(q--)
	{
		string ni;
		cin>>ni;
		map<string ,string>::iterator it=m.find(ni);
		if(it==m.end())
			cout<<"Name not found"<<endl;
		else cout<<m[ni]<<endl;
	}
	return 0;
}
