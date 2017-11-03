#include<bits/stdc++.h>
using namespace std;
string findAnswer(int n)
{
	if(n==2)
		return "NO";
	if(n&1)
		return "NO";
	return "YES";
}
int main()
{
	int n;
	cin>>n;
	cout<<findAnswer(n)<<endl;
	return 0;
}
