#include<bits/stdc++.h>
using namespace std;
void solve(string str)
{
	char current = 'Z';
	int prevfound=-1,answera=0,answerb=0;
	for(int i=0;i<str.size();i++)
	{
		if(prevfound==-1 && str[i]!='.')
		{
			prevfound = i;	
			current = str[i];
		}
		else if(prevfound!=-1 && str[i]==current)
		{
			for(int j=prevfound;j<=i;j++)
				str[j]=current;
			prevfound=i;
		}
		else if(prevfound!=-1 && str[i]!='.' && str[i]!=current)
		{
			prevfound=i;
			current=str[i];
		}

	}
	for(int i=0;i<str.size();i++)
		if(str[i]=='A') answera++;
		else if(str[i]=='B') answerb++;
	printf("%d %d\n",answera,answerb);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		string str;
		cin>>str;
		solve(str);
	}
	return 0;
}
