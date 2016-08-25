#include<stdio.h>
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
int main()
{
	int n,q;string str;
	scanf("%d",&n);
	map<string,int>m;
	while(n--){
		cin>>str;
		if(m.end()==m.find(str))
			m[str]=1;
		else m[str]++;
	}
	scanf("%d",&q);
	while(q--)
	{
		cin>>str;
		printf("%d\n",m[str]);
	}
	return 0;
}
