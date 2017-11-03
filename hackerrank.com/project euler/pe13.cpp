#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
string add(string &a,string &b)
{
	{ // removing the leading zeros
		int x;
		for(x=0;x<a.size() && a[x]=='0';x++);
		if(x==a.size())
			a="0";
		else a=a.substr(x);

		for(x=0;x<b.size() && b[x]=='0';x++);
		if(x==b.size())
			b="0";
		else b=b.substr(x);
	}
	int m=a.size(),n=b.size();
	string result(max(m,n)+1,'0');
	int k=result.size()-1;
	int carry=0;
	for(int i=m-1,j=n-1;i>=0 || j>=0 || carry;i--,j--)
	{
		int x=carry;
		if(i>=0) x+=a[i]-'0';
		if(j>=0) x+=b[j]-'0';
		carry=x/10;
		result[k--]=(x%10)+'0';
	}
	{ // removing leading zeros of result
		int x;
		for(x=0;x<result.size() && result[x]=='0';x++);
		if(x==result.size())
			result="0";
		else result=result.substr(x);
	}
	return result;
}
int main()
{
	int n;
	scanf("%d",&n);
	string sum="0";
	for(int i=0;i<n;i++)
	{
		string temp;
		cin>>temp;
		sum = add(sum,temp);
	}
	for(int i=0;i<10;i++)
		cout<<sum[i];
	cout<<endl;
	return 0;
}
