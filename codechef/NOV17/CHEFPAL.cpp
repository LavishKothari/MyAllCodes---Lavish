#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string &str,int start,int end)
{
	for(int i=start,j=end;i<j;i++,j--)	
		if(str[i]!=str[j])
			return false;
	return true;
}
int lps(string &str,int start=0,int end=-1)
{
	if(end==-1)
		end = str.size();
	int answer=1;
	for(int i=start;i<end;i++)
	{
		for(int j=i+1;j<str.size();j++)
			if(isPalindrome(str,i,j))
				answer = max(answer,j-i+1);
	}
	return answer;
}
string getString(int n,int length)
{
	string s;

	for(int i=0;i<length;i++)
	{
		if(n&1)
			s+="a";
		else s+="b";
		n/=2;
	}
	return s;
}
vector<string>getAll(int length)
{
	vector<string>strings;
	for(int i=0;i<(1<<length);i++)
		strings.push_back(getString(i,length));
	return strings;
}
void solve1(int length)
{
	int m=INT_MAX;
	vector<string>all = getAll(length);
	for(int i=0;i<all.size();i++)	
	{
		int x = lps(all[i]);
		m=min(x,m);
	}
	cout<<"length and lps = "<<length<<" "<<m<<endl;
	for(int i=0;i<all.size();i++)
	{
		if(lps(all[i])==m)
			cout<<all[i]<<endl;
	}
}

void solveForShort(int n)
{
	if(n==1)
		printf("1 a\n");
	else if(n==2)
		printf("1 ab\n");
	else if(n==3)
		printf("2 aab\n");
	else if(n==4)
		printf("2 aabb\n");
	else if(n==5)
		printf("3 aaabb\n");
	else if(n==6)
		printf("3 aaabbb\n");
	else if(n==7)
		printf("3 aaababb\n");
	else if(n==8)
		printf("3 aaababbb\n");
}
string global;
int maxLen;
void getBig()
{
	string str(maxLen,'a');
	str[0]=str[2]='b';
	str[1]=str[3]='a';
	str[4]='a';
	for(int i=5;i<str.size();i++)
	{
		if(isPalindrome(str,i-3,i-1))
		{
			if(str[i-4]=='a') str[i]='b';
			else str[i]='a';
		}
		else if(isPalindrome(str,i-4,i-1))
		{
			if(str[i-5]=='a') str[i]='b';
			else str[i]='a';
		}
		else
		{
			if(str[i-1]=='a') str[i]='b';
			else str[i]='a';
		}
	}
	global=str;
}
void solve(int n,int a)
{	
	if(a==1)
	{
		string s(n,'a');
		printf("%d %s\n",n,s.c_str());
	}
	else if(a!=2)
	{
		printf("1 ");
		for(int i=0;i<n;i++)
			printf("%c",'a'+(i%a));
		printf("\n");
	}
	else{
		if(n<=8)
			solveForShort(n);
		else
		{
			printf("4 ");
			//			assert(lps(global,0,n-1)==4);
			for(int i=0;i<n;i++)				
				printf("%c",global[i]);
			printf("\n");
		}
	}
}
int main()
{
	maxLen=100000;
	getBig();
	//	int x;
	////	while(1)
	////	{
	////		cin>>x;
	////		string str=getBig(x);
	////		cout<<str<<endl;
	////		cout<<"checking = "<<lps(str)<<endl;
	////	}
	//
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,a;
		scanf("%d%d",&n,&a);
		solve(n,a);
	}
	return 0;
}
