#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;

int findAnswer(string*str,int row,int col)
{
	bool flag=true;
	int p,q;
	for(p=0;p<row;p++)
	{
		for(q=0;q<col;q++)
		{
			if(str[p][q]=='*')
			{
				flag=false;
				break;
			}
		}
		if(!flag)
			break;
	}
	if(p==row && q==col)
		return 0;
	int a1=0,a2=0,b1=0,b2=0,c1=row-1,c2=row-1,d1=col-1,d2=col-1,a,b,c,d,x,y;
	flag=true;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(str[i][j]=='*')
			{
				a1=i;b1=j;
				flag=false;
				break;
			}
		}
		if(!flag)
			break;
	}
	flag=true;
	for(int i=0;i<col;i++)
	{
		for(int j=0;j<row;j++)
		{
			if(str[j][i]=='*')
			{
				a2=j;b2=i;
				flag=false;
				break;
			}
		}
		if(!flag)
			break;
	}
	a=min(a1,a2);b=min(b1,b2);
	/***********************/
	flag=true;
	for(int i=row-1;i>=0;i--)
	{
		for(int j=col-1;j>=0;j--)
		{
			if(str[i][j]=='*')
			{
				c1=i;d1=j;
				flag=false;
				break;
			}
		}
		if(!flag)
			break;
	}
	flag=true;
	for(int i=col-1;i>=0;i--)
	{
		for(int j=row-1;j>=0;j--)
		{
			if(str[j][i]=='*')
			{
				c2=j;d2=i;
				flag=false;
				break;
			}
		}
		if(!flag)
			break;
	}
	c=max(c1,c2);d=max(d1,d2);
	//printf("(%d,%d)(%d,%d)\n",a,b,c,d);
	x=c-a+1;y=d-b+1;
	return max(x/2+1,y/2+1);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int r,c;
		cin>>r>>c;
		string *str=new string[r];
		for(int i=0;i<r;i++)
			cin>>str[i];
		printf("%d\n",findAnswer(str,r,c));
		/*
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
				cout<<str[i][j];
			cout<<endl;
		}
		*/
	}
	return 0;
}
