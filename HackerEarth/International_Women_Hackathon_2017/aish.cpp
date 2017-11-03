
#include <time.h>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll maxS=INT_MIN;
vector<pair<int,int> >sv;

ll aishSum=INT_MIN;
vector<int>finalBV;

void solaish(vector<vector<ll> >&A,vector<vector<ll> >&B,vector<ll>&c,vector<ll>&r,ll k,ll S)
{
	int n=A.size();
	vector<pair<int,int> >temp;
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
	//cout<<"max ix "<<mx<<" "<<i<<" "<<j<<endl;
	vector<pair<int,int> >sv;
	if(flag==0)
	{
		int col=j;
		for(int x=0;x<n;x++)
			if(A[x][col]<B[x][col])
			{
				if(x==i && col==j)
					continue;
				swap(A[x][col],B[x][col]);
				sv.push_back(make_pair(x,col));
			}
		int row=j;
		for(int y=0;y<n;y++)
			if(A[row][y]>B[row][y])
			{
				if(row==i && y==j)
					continue;
				swap(A[row][y],B[row][y]);
				sv.push_back(make_pair(row,y));
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
				sv.push_back(make_pair(row,y));
				// print
			}

		int col=i;
		for(int x=0;x<n;x++)
			if(A[x][col]<B[x][col])
			{
				if(x==i && col==j)
					continue;
				swap(A[x][col],B[x][col]);
				sv.push_back(make_pair(x,col));
			}
	}
	int t=min((ll)sv.size(),k);

	vector<pair<int,int> >vp(t);
	cout<<t<<endl;
	for(int i=0;i<t;i++)
		cout<<sv[i].first+1<<" "<<sv[i].second+1<<endl;
}


int countOn(vector<int>&bv)
{
	int count=0;
	for(int i=0;i<bv.size();i++)
		if(bv[i])
			count++;
	return count;
}
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

	//if(n<=5 && k<=12 && k<=n*n) ////////////////////////////////////////////
	if(1==2)
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

	{// executing sol2
		sol2(A,B,k);
		int count=countOn(finalBV);
		if(count<=k && aishSum>maxS)
		{
			//cout<<"you found something"<<endl;
			cout<<count<<endl;
			for(int i=0;i<finalBV.size();i++)
				if(finalBV[i])
				{
					int x=i/n + 1;
					int y=i%n + 1;
					cout<<x<<" "<<y<<endl;
				}
			//cout<<"you won"<<endl;
			return 0;
		}
	}

	/// sol 3
	while(sv.size()<k)
	{
		vector<vector<ll> >cA,cB;
		cA=A;cB=B;
		vector<int>bv(n*n,0);
		for(int i=0;i<sv.size();i++)
		{
			int i1,i2;
			i1=sv[i].first-1;
			i2=sv[i].second-1;
			bv[i1*n+i2]=1;
		}
		myswap(cA,cB,bv);
		vector<ll>c,r;
		getCR(cA,cB,c,r);

		for(int i=0;i<c.size();i++)
		{
			if(c[i]==0 && r[i]>0)
			{
				for(int x=0;x<n;x++)
				{
					int row=x,col=i;
					pair<int,int>p=(make_pair(row,col));
					if(find(sv.begin(),sv.end(),p)==sv.end())
					{
						swap(cA[row][col],cB[row][col]);
						vector<ll>rr,cc;
						getCR(A,B,cc,rr);
						int ssum=getSum(r,c);
						if(ssum>aishSum)
						{
							p.first++;p.second++;
							if(sv.size()<k)
								sv.push_back(p);
						}
					}
				}
				//cout<<"this is what was needed"<<endl;
			}
			else if(r[i]==0 && c[i]>0)
			{
				for(int x=0;x<n;x++)
				{
					int row=i,col=x;
					pair<int,int>p=(make_pair(row,col));
					if(find(sv.begin(),sv.end(),p)==sv.end())
					{
						swap(cA[row][col],cB[row][col]);
						vector<ll>rr,cc;
						getCR(A,B,cc,rr);
						int ssum=getSum(r,c);
						if(ssum>aishSum)
						{
							p.first++;p.second++;
							if(sv.size()<k)
								sv.push_back(p);
						}
					}
				}
				//cout<<"this is what was needed"<<endl;
			}else goto aishwarya;
		}
	}
aishwarya:;
		  cout<<sv.size()<<endl;
		  for(int i=0;i<sv.size();i++)
			  cout<<sv[i].first<<" "<<sv[i].second<<endl;

		  return 0;
}
