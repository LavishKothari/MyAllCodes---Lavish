#include<iostream>

using namespace std;

int cutoff(string &s,int n)
{
	int count=0;
	for(int i=n;i<s.size();i++)
	{
		if(s[i]=='U')
			count++;
		else count--;
		if(count==0)
			return i+1;
	}
	return -1;
}
int cutoff1(string &s,int n)
{
	int count=0;
	for(int i=n;i<s.size();i++)
	{
		if(s[i]=='D')
			count++;
		else count--;
		if(count==0)
			return i+1;
	}
	return -1;
}
int findAnswer(string &s,int n)
{
	int answer=0;
	for(int i=0;i<s.size();)
	{
		if(s[i]=='U')
		{
			int x=cutoff(s,i);
			if(x==-1)
				i=s.size();
			else i=x;
		}
		else
		{
			int x=cutoff1(s,i);
			if(x==-1)
			{
				i=s.size();
			}
			else
			{
				i=x; 
				answer++;
			}
		}
	}
	return answer;
}
int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	cout<<findAnswer(s,n)<<endl;
	return 0;
}
