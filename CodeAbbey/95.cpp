#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	int start,end;
	cin>>start>>end;
	int t=end-start+1;
	int *x=new int[t];
	int *y=new int[t];
	double sumx=0,sumy=0;
	for(int i=0;i<t;i++)
	{
		string s;int a,b;
		cin>>s>>x[i]>>y[i];
		sumx+=x[i];
		sumy+=y[i];
	}
	
	sumx/=t;sumy/=t;
	
	double N=0,D=0;
	for(int i=0;i<t;i++)
	{
		N+=(x[i]-sumx)*(y[i]-sumy);
		D+=(x[i]-sumx)*(x[i]-sumx);
	}
	
	double K=N/D;
	double B=sumy-K*sumx;
	//cout<<K<<" "<<B<<endl;
	printf("%0.11lf %0.11lf\n",K,B);
	return 0;
}

