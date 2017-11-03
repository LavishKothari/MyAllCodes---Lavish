#include<iostream>
using namespace std;
void fun(char ac,char bc,string &result,int a,int b,int x,int y)
{
	int blocks = a/x-(a%x==0); // number of blocks of b's that are to be inserted.

	int remblocks=blocks;
	while(true) {
		if(b==0 || a==0)
			break;
		for(int i=0;a && i<x;i++) {
			result+=ac;
			a--;
		}
		remblocks = remblocks-1;
		if(b && b-remblocks<=0)
			result+="*";
		for(int i=0;b && i<min(b-remblocks,y);i++) {
			result+=bc;
			b--;
		}
	}
	while(a) {
		for(int i=0;a && i<x;i++) {
			result+=ac;
			a--;
		}
		if(a)
			result+="*";
	}

	string temp="";
	for(int i=0;i<y;i++)
		temp+=bc;
	string toBeInserted="";
	for(int i=0;i+1<result.size();i+=toBeInserted.size()+1)
	{
		toBeInserted="";
		if(result[i]==ac && result[i+1]==ac) {
			if(b>=y)
				toBeInserted = temp;
			else toBeInserted = temp.substr(0,b);
			result.insert(i+1,toBeInserted);

			b-=toBeInserted.size();
		}
	}

	while(b) {
		for(int i=0;b && i<y;i++) { 
			result+=bc;	
			b--;
		}
		if(b)
			result+="*";
	}

	cout<<result<<endl;
}
void solve(string &s,int x,int y)
{
	int a=0,b=0;
	for(int i=0;i<s.size();i++)
		if(s[i]=='a') a++;
		else b++;
	string result="";
	a>b?fun('a','b',result,a,b,x,y):fun('b','a',result,b,a,y,x);
}
int main()
{
	int t,x,y;
	string s;
	scanf("%d",&t);
	while(t--)
	{
		cin>>s;cin>>x>>y;
		solve(s,x,y);
	}
	return 0;
}
