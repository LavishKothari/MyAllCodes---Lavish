#include<stdio.h>
#include<iostream>
#include<map>
using namespace std;

map<string,int>m;

void find(int t,int x)
{
	char c[]={'b','c','d','f','g','h','j','k','l','m','n','p','r','s','t','v','w','x','z'};
	char v[]={'a','e','i','o','u'};
	int i,n;
	int A = 445, C = 700001, M = 2097152;
	while(t--)
	{
		n=6;
		//scanf("%d",&n);
		char str[100];
		int counter=0;
		for(i=1;i<=n;i++)
		{
			x=(A*x+C)%M;
			if((i&1)!=0) // consonant
			{
				str[counter++]=c[x%19];
				//printf("%c",c[x%19]);
			}
			else
			{
				str[counter++]=v[x%5];
				//printf("%c",v[x%5]);
			}
		}
		str[counter]='\0';
		string s(str);
		if(m.find(s)!=m.end())
			m[s]++;
		else m[s]=1;
		//printf(" ");
	}
}

int main()
{
	int seed;
	cin>>seed;
	find(900000,seed);
	int ma=0;
	string s;
	for(map<string,int>::iterator it=m.begin();it!=m.end();it++)
	{
		//cout<<it->first<<endl;
		if(ma<(it->second))
		{
			ma=it->second;
			s=it->first;
		}
	}
	cout<<s<<endl;
	return 0;
}
