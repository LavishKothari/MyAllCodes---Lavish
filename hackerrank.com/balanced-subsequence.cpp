#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		string str;
		cin>>str;
		int counter=0,answer=0;
		for(int i=0;i<str.size();i++)
		{
			if(str[i]=='(')
				counter++;
			else 
			{
				if(counter==0)
					continue;
				else 
				{
					answer++;
					counter--;
				}
			}
		}
		cout<<answer*2<<endl;
	}
	return 0;
}
