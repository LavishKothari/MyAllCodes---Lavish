#include<bits/stdc++.h>
using namespace std;
int count6(vector<int>&type)
{
	int m=INT_MAX,nonzero=0;
	for(int i=0;i<type.size();i++)
	{
		if(type[i]!=0 && m>type[i])
			m=type[i];
		if(type[i]!=0)
			nonzero++;
	}
	if(nonzero!=6)
		return 0;
	for(int i=0;i<type.size();i++)
		if(type[i]>=m)
			type[i]-=m;
	return m;
}
int count5(vector<int>&type)
{
	int m=INT_MAX,nonzero=0;
	for(int i=0;i<type.size();i++)
	{
		if(type[i]!=0 && m>type[i])
			m=type[i];
		if(type[i]!=0)
			nonzero++;
	}
	if(nonzero!=5)
		return 0;
	for(int i=0;i<type.size();i++)
		if(type[i]>=m)
			type[i]-=m;
	return m;
}

int count4(vector<int>&type)
{
	int m=INT_MAX,nonzero=0;
	for(int i=0;i<type.size();i++)
	{
		if(type[i]!=0 && m>type[i])
			m=type[i];
		if(type[i]!=0)
			nonzero++;
	}
	if(nonzero!=4)
		return 0;
	for(int i=0;i<type.size();i++)
		if(type[i]>=m)
			type[i]-=m;
	return m;
}

int calScore(vector<int>&v,vector<int>&type)
{
	int temp;
	int answer=0;
	
	answer=answer+count6(type)*4;
	answer=answer+count5(type)*2;
	answer=answer+count4(type)*1;

	return answer;
}
int findWinner(vector<int>&score)
{
	int m_index=max_element(score.begin(),score.end())-score.begin();
	int m_value=score[m_index];
	for(int i=0;i<score.size();i++)
		if(i!=m_index && score[i]==m_value)
			return -1;
	return m_index;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		cin>>n;
		vector< vector<int> >v(n);
		vector<int>score(n);
		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			score[i]=x;
			vector<int>type(6,0);
			for(int j=0;j<x;j++)
			{
				int temp;
				cin>>temp;
				v[i].push_back(temp);
				type[temp-1]++;
			}
			score[i]+=calScore(v[i],type);
		}
		int winner=findWinner(score);
		if(winner==0)
			cout<<"chef\n";
		else if(winner==-1)
			cout<<"tie\n";
		else cout<<winner+1<<endl;
	}
}
