#include <time.h>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll maxS=INT_MIN;
vector<pair<int,int> >sv,xsv;
void getCR(vector<vector<ll> >&A,vector<vector<ll> >&B,vector<ll>&c,vector<ll>&r)
{
	int n=A.size();
	c=vector<ll>(n,0);
	r=vector<ll>(n,0);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			c[i]+=A[j][i];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			r[i]+=B[i][j];
}
int getSum(vector<ll>&c,vector<ll>&r)
{
	int sum=0;
	for(int i=0;i<c.size();i++)
		sum+=c[i]*r[i];
	return sum;
}
int solaish(vector<vector<ll> >&A,vector<vector<ll> >&B,vector<ll>&c,vector<ll>&r,ll k,ll S)
{
	int n=A.size();
	int mx=INT_MIN;int flag=-1;
	int i,j;
	for(int x=0;x<n;x++)
	{
		for(int y=0;y<n;y++)
		{
			if(A[x][y]>mx)
			{
				flag=0;i=x;j=y;
				mx=A[x][y];
			}
			if(B[x][y]>mx)
			{
				flag=1;i=x;j=y;
				mx=B[x][y];
			}
		}
	}

	if(flag==0)
	{
		int col=j;
		for(int x=0;x<n;x++)
			if(A[x][col]<B[x][col])
			{
				if(x==i && col==j)
					continue;
				swap(A[x][col],B[x][col]);
				sv.push_back(make_pair(x+1,col+1));
			}
		int row=j;
		for(int y=0;y<n;y++)
			if(A[row][y]>B[row][y])
			{
				if(row==i && y==j)
					continue;
				swap(A[row][y],B[row][y]);
				sv.push_back(make_pair(row+1,y+1));
			}
	}
	else
	{
		int row=i;
		for(int y=0;y<n;y++)
			if(A[row][y]>B[row][y])
			{
				if(row==i && y==j)
					continue;
				swap(A[row][y],B[row][y]);
				sv.push_back(make_pair(row+1,y+1));
				// print
			}

		int col=i;
		for(int x=0;x<n;x++)
			if(A[x][col]<B[x][col])
			{
				if(x==i && col==j)
					continue;
				swap(A[x][col],B[x][col]);
				sv.push_back(make_pair(x+1,col+1));
			}
	}
	int t=min((ll)sv.size(),k);
	return t;
}


void sol(vector<vector<ll> >&A,vector<vector<ll> >&B,vector<ll>c,vector<ll>r,ll k,ll S)
{
	int n=A.size();
	vector<pair<int,int> >temp;
	for(int x=0;x<k;x++)
	{
		ll tempS=S;
		ll maxTempS=LLONG_MIN;
		ll finalI=-1,finalJ=-1;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				tempS=S;
				if(find(temp.begin(),temp.end(),make_pair(i+1,j+1))!=temp.end())
					continue;
				if(i==j)
				{
					tempS=tempS-c[i]*r[i];
					tempS=tempS+(c[j]-A[i][j]+B[i][j])*(r[i]-B[i][j]+A[i][j]);
				}
				else
				{
					tempS=tempS-c[i]*r[i]-c[j]*r[j];
					tempS=tempS+(c[j]-A[i][j]+B[i][j])*(r[j])+(c[i])*(r[i]-B[i][j]+A[i][j]);
				}
				if(maxTempS<tempS)
				{
					finalI=i;finalJ=j;
					maxTempS=tempS;
				}
			}
		}
		if(finalI==-1 || finalJ==-1)
			break;

		if(finalI==finalJ)
		{
			c[finalI] = c[finalI]-A[finalI][finalI]+B[finalI][finalI];
			r[finalI] = r[finalI]-B[finalI][finalI]+A[finalI][finalI];
		}
		else
		{
			c[finalJ] = c[finalJ]-A[finalI][finalJ]+B[finalI][finalJ];
			r[finalI] = r[finalI]-B[finalI][finalJ]+A[finalI][finalJ];
		}

		S=maxTempS;
		temp.push_back(make_pair(finalI+1,finalJ+1));
	}
	if(maxS<S)
	{
		maxS=S;
		//cout<<"sum "<<maxS<<endl;
		xsv=temp;
		//for(int i=0;i<temp.size();i++)
		//	finalsv.push_back(temp[i]);
	}
}

int main()
{
	srand(time(NULL));
	int n,k;
	scanf("%d%d",&n,&k);
	vector<vector<ll> >A(n,vector<ll>(n));
	vector<vector<ll> >B(n,vector<ll>(n));
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>A[i][j];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>B[i][j];

	clock_t start_time=clock();


	vector<ll>c(n,0);
	vector<ll>r(n,0);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			c[i]+=A[j][i];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			r[i]+=B[i][j];

	ll S=0;
	for(int i=0;i<n;i++)
		S+=c[i]*r[i];

	int te=solaish(A,B,c,r,k,S);



	for(int i=0;i<te;i++)
	{
		int x=sv[i].first-1;
		int y=sv[i].second-1;

		swap(A[x][y],B[x][y]);

	}
	getCR(A,B,c,r);
	S=getSum(c,r);

	for(int x=0;x<k-te;x++)
		sol(A,B,c,r,x,S);

	for(int i=0;i<xsv.size();i++)
		sv.push_back(xsv[i]);


	int count=min((int)sv.size(),(int)k);
	cout<<count<<endl;
	for(int i=0;i<count;i++)
		cout<<sv[i].first<<" "<<sv[i].second<<endl;

	return 0;
}
