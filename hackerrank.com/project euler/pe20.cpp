#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define N 1001
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
string convertToString(int n)
{
	string result;
	while(n)
	{
		result.push_back(n%10+'0');
		n/=10;
	}
	reverse(result.begin(),result.end());
	return result;
}
ll sumDigits(string &a)
{	 
	ll answer=0;
	for(int i=0;i<a.size();i++)
		answer = answer + a[i]-'0';
	return answer;
}
void populateAnswer(vector<ll>&answer)
{
	vector<string>factorial(N);
	factorial[0]=factorial[1]="1";
	for(int i=2;i<N;i++)
	{
		string istring = convertToString(i);
		factorial[i]=multiply(factorial[i-1],istring);
	}

	for(int i=0;i<N;i++)
		answer[i] = sumDigits(factorial[i]);
}
int main()
{
	vector<ll>answer(N,0);
	populateAnswer(answer);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		cin>>n;
		cout<<answer[n]<<endl;
	}
	return 0;
}
