#include <bits/stdc++.h>
using namespace std;
map<int,string>p_2;
string multiply(string &a,string &b)
{
	{ // removing trailing zeros
		int counter;
		for(counter=0;counter<a.size() && a[counter]=='0';counter++);
		if(counter==a.size())
			a="0";
		else a=a.substr(counter);

		for(counter=0;counter<b.size() && b[counter]=='0';counter++);
		if(counter==b.size())
			b="0";
		else b=b.substr(counter);
	}
	int m=a.size(),n=b.size();
	string result(m*n+10,'0');
	int carry=0;
	int initk=result.size();
	for(int i=m-1;i>=0;i--) // for a
	{
		int k=initk=initk-1;
		for(int j=n-1;j>=0;j--,k--) // for b
		{
			int x = (a[i]-'0')*(b[j]-'0')+carry+result[k]-'0';
			carry=x/10;
			x%=10;
			result[k] = x+'0';
		}
		while(carry)
		{
			int x=carry+result[k]-'0';
			carry=x/10;
			x%=10;
			result[k]=x+'0';
			k--;
		}
	}
	int x=0;
	for(;x<result.size() && result[x]=='0';x++);
	if(x==result.size())
		return "0";
	return result.substr(x);
}
string power2(int n) // with complexity of O(logn)
{
	if(p_2[n]!="")
		return p_2[n];
	if(n==0)
	{
		p_2[n]="1";
		return "1";
	}
	if(n==1)
	{
		p_2[n]="2";
		return "2";
	}
	string temp = power2(n/2);
	string pro="2";
	
	string temp1=multiply(temp,temp);
	if(n&1)
		p_2[n]=multiply(temp1,pro);
	else p_2[n]=temp1;
	return p_2[n];
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		cin>>n;
		string p2 = power2(n); 
		int answer=-p2.size()*'0';
		for(int i=0;i<p2.size();i++)
			answer+=p2[i];
		cout<<answer<<endl;
	}
	return 0;
}
