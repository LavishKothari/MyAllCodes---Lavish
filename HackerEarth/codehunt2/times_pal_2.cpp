#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
using namespace std;
int isPalindrome(string s)
{
	for(int i=0,j=s.size()-1;i<j;i++,j--)
		if(s.at(i)!=s.at(j))
			return 0;
	return 1;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char s1[10000],s2[10000];
		scanf(" %s %s",s1,s2);
		string a=string(s1);
		string b=string(s2);

		int counter=0;
		for(int i=0;i<=a.size();i++)
		{
			if(isPalindrome(string(a.substr(0,i)+b+a.substr(i,a.size()-i))))
				counter++;
		}
		printf("%d\n",counter);
	}
	return 0;
}
