#include<bits/stdc++.h>
using namespace std;
int cal(string &str,int mid)
{
	int n=str.size();
	int ans1=0,ans2=0;
	int i,j;
	for(i=mid-1,j=mid+1;i>=0 && j<n;i--,j++)
	{
		if(str[i]!=str[j])
			ans1++;
	}
	ans1+=i+1;

	for(i=mid-1,j=mid;i>=0 && j<n;i--,j++)
		if(str[i]!=str[j])
			ans2++;
	ans2+=i+1;
	return min(ans1,ans2);
}
int bad(string &str)
{
	int n=str.size();
	int answer=0;
	for(int i=0,j=n-1;i<j;i++,j--)
		if(str[i]!=str[j])
			answer++;
	return answer;
}
void solve(string &str)
{
	int n=str.size();
	int mid,answer=INT_MAX; 
	if(n&1) 
	{ 
		mid=n/2+1;
		answer=bad(str); // str will always be of odd length
	}
	else
	{
		mid=n/2;
	}

	for(int i=mid;i<n;i++)
		answer=min(answer,cal(str,i));
	cout<<answer<<"\n";
}
int main()
{
	string str;
	cin>>str;
	solve(str);
	return 0;
}
