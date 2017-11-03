#include<bits/stdc++.h>
using namespace std;
char lowerCase(char a)
{
	if(a>='A' && a<='Z')
		return a+('a'-'A');
	else return a;
}
char upperCase(char a)
{
	if(a>='a' && a<='z')
		return a-('a'-'A');
	else return a;
}
string extract(char *str,int start)
{
	string result1,result2;
	int n=strlen(str);
	for(int i=start;i<n;i++)
	{
		if(str[i]==' ')
			return result1;
		else 
		{
			if(i==start)
			{
				result1.push_back(upperCase(str[i]));
				result1.push_back('.');
				result1.push_back(' ');
				result2.push_back(upperCase(str[i]));
			}
			else
				result2.push_back(lowerCase(str[i]));
		}
	}
	return result2;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char str[100];
		scanf(" %[^\n]s",str);
		int n=strlen(str);
		int prev=0;
		string result;
		for(int i=0;i<n;i++)
		{
			if(str[i]==' ' || !str[i+1])
			{
				result = result+extract(str,prev);
				prev=i+1;
			}
		}
		cout<<result<<endl;
	}
	return 0;
}
