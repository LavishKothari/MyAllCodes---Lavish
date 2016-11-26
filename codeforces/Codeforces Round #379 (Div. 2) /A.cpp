#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	string s;
	cin>>s;
	int a=0,d=0;
	for(int i=0;i<t;i++)
		if(s[i]=='A')
			a++;
		else if(s[i]=='D')
			d++;
	if(a==d)
		cout<<"Friendship"<<endl;
	else if(a>d)
		cout<<"Anton"<<endl;
	else if(a<d)
		cout<<"Danik"<<endl;

	return 0;
}