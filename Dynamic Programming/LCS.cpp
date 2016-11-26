#include<bits/stdc++.h>
using namespace std;
void printLCS(string &x,string &y,int**table,int i,int j)
{
	if(i<=0 || j<=0)
		return ;
	if(x[i-1]==y[j-1])
	{
		printLCS(x,y,table,i-1,j-1);
		cout<<x[i-1];
	}
	else
	{
		if(table[i-1][j]>table[i][j-1])
			printLCS(x,y,table,i-1,j);
		else printLCS(x,y,table,i,j-1);
	}
}
int LCS(string &x,string &y) // using a 2-D table for storing solutions to subproblems
{
	int**table;
	table=new int*[x.size()+1];
	for(int i=0;i<=x.size();i++)
		table[i]=new int[y.size()+1];

	for(int i=0;i<=x.size();i++)
		table[i][0]=0;
	for(int i=0;i<=y.size();i++)
		table[0][i]=0;

	for(int i=1;i<=x.size();i++)
	{
		for(int j=1;j<=y.size();j++)
		{
			if(x[i-1]==y[j-1])
				table[i][j]=table[i-1][j-1]+1;
			else
				table[i][j]=max(table[i-1][j],table[i][j-1]);
		}
	}
	printLCS(x,y,table,x.size(),y.size());
	cout<<endl;
	int answer=table[x.size()][y.size()];
	
	for(int i=0;i<=x.size();i++)
		delete table[i];
	delete table;
	return answer;
}

// just swapping the pointers of the array
int LCSOptimized1(string &x,string &y) // using two 1-D arrays to store the solutions to subproblems
{
	int *table1,*table2;
	table1=new int[y.size()+1];
	table2=new int[y.size()+1];

	for(int i=0;i<=y.size();i++)
		table1[i]=0;

	for(int i=1;i<=x.size();i++)
	{
		for(int j=1;j<=y.size();j++)
		{
			if(x[i-1]==y[j-1])
				table2[j]=1+table1[j-1];
			else table2[j]=max(table2[j-1],table1[j]);
		}
		int *temp;
		temp=table1;
		table1=table2;
		table2=temp;
	}
	return max(table1[y.size()],table2[y.size()]);
}

// a more tricy solution that uses two 1-D arrays.
int LCSOptimized2(string &x,string &y)
{
	int **table;
	table=new int*[2];
	table[0]=new int[y.size()+1];
	table[1]=new int[y.size()+1];

	for(int i=0;i<=y.size();i++)
		table[0][i]=0;

	int index=0;
	for(int i=1;i<=x.size();i++)
	{
		for(int j=1;j<=y.size();j++)
		{
			if(x[i-1]==y[j-1])
				table[index^1][j]=table[index][j-1]+1;
			else
			{
				table[index^1][j]=max(table[index^1][j-1],table[index][j]);
			}
		}
		index=(index^1);
	}
	int answer=table[index][y.size()]; // answer=max(table[0][y.size()],table[1][y.size()]);
	delete table[0];
	delete table[1];
	return answer; 	
}
int main()
{
	string x,y;
	cin>>x>>y;
	cout<<"Length of LCS is : "<<LCS(x,y)<<endl;
	return 0;
}