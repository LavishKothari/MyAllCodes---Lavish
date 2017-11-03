#include <time.h>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll maxS=INT_MIN;
vector<pair<int,int> >sv;

ll aishSum=INT_MIN;
vector<int>finalBV;

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

void myswap(vector<vector<ll> >&A,vector<vector<ll> >&B,vector<int>&bv)
{
	int n=A.size();
	for(int i=0;i<bv.size();i++) // time complexity O(n*n)
	{
		if(bv[i])
		{
			int x=i/n;
			int y=i%n;
			swap(A[x][y],B[x][y]);
		}
	}
}

int getSum(vector<ll>&c,vector<ll>&r)
{
	int sum=0;
	for(int i=0;i<c.size();i++)
		sum+=c[i]*r[i];
	return sum;
}

void sol1(vector<vector<ll> >A,vector<vector<ll> >B,int k)
{
	vector<ll>c,r;
	//getCR(A,B,c,r);
	int n=A.size();

	vector<int>bv(n*n,0);
	for(int i=0;i<k;i++)
		bv[n*n-1-i]=1;

	vector<vector<ll> >cA,cB;
	cA=A;cB=B;

	do{
		A=cA;
		B=cB;

		myswap(A,B,bv);
		getCR(A,B,c,r);
		int sum = getSum(c,r);
		if(sum>aishSum)
		{
			aishSum=sum;
			finalBV=bv;
		}
	}while(next_permutation(bv.begin(),bv.end()));
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
		sv=temp;
	}
}
int main()
{
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

	//if(n<=5 && k<=12 && k<=n*n) ////////////////////////////////////////////
	{
		int x;int flag=0;
		for(x=0;x<=k;x++)
		{
			clock_t end_time=clock();
			double current_time = (double)(end_time - start_time)/CLOCKS_PER_SEC;
			if(current_time>0.5)
			{
				flag=1;
				break;
			}
			sol1(A,B,x);
		}
		if(!flag)
		{
			int count=0;
			for(int i=0;i<finalBV.size();i++)
				if(finalBV[i])
					count++;
			cout<<count<<endl;

			for(int i=0;i<finalBV.size();i++)
				if(finalBV[i])
				{
					int x=i/n + 1;
					int y=i%n + 1;
					cout<<x<<" "<<y<<endl;
				}

			return 0;
		}
	}


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

	for(int x=0;x<=k;x++)
		sol(A,B,c,r,x,S);

	cout<<sv.size()<<endl;
	for(int i=0;i<sv.size();i++)
		cout<<sv[i].first<<" "<<sv[i].second<<endl;

	return 0;
}
