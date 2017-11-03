#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
unsigned long long s[2];
unsigned long long xorshift128plus() {
	unsigned long long x = s[0];
	const unsigned long long y = s[1];
	x ^= x << 23;
	s[1] = x ^ y ^ (x >> 17) ^ (y >> 26);
	return s[0] = y;
}

const int MX = 1000;

int C[MX][MX];
int H[MX][MX];

void populate(int n,int Cmax,int Hmax,vector<ll>&s0,vector<ll>&s1) {
	int T=1;
	int counter=0;
	for (int t = 0; t < T; t++) {
		for (int i = 0; i < n; i++) {
			C[i][i] = 0;
//			scanf("%llu %llu", &s[0], &s[1]);
			s[0]=s0[counter];
			s[1]=s1[counter];
			counter++;
			for (int j = i + 1; j < n; j++) {
				C[i][j] = C[j][i] = xorshift128plus() % (Cmax + 1);
			}
		}

		for (int i = 0; i < n; i++) {
//			scanf("%llu %llu", &s[0], &s[1]);
			s[0]=s0[counter];
			s[1]=s1[counter];
			counter++;
			for (int j = 0; j < n; j++) {
				H[i][j] = xorshift128plus() % (Hmax + 1);
			}
		}

		// solve here
	}
}
vector<int>parent(1000,-1);
vector<int>size(1000,1);
bool isConnected(vector<vector<bool>>&graph)
{
	//return size[parent[0]]==graph.size();
	int flag=parent[0];
	for(int i=0;i<graph.size();i++)
		if(parent[i]!=flag)
			return false;
	return true;
}
int find(int n)
{
	if(n==parent[n])
		return n;
	return parent[n]=find(parent[n]);
}
void merge(int a,int b)
{
	int pa=find(a),pb=find(b);
	if(pa!=pb)
	{
		if(size[pa]>size[pb])
		{
			parent[pb]=pa;
			size[pa]+=size[pb];
		}
		else
		{
			parent[pa]=pb;
			size[pb]+=size[pa];
		}
	}
}
ll calCost(vector<vector<bool>>&graph)
{
	int n=graph.size();
	ll cost=0;
	for(int i=0;i<n;i++)
	{
		int count=0;
		for(int j=0;j<i;j++)
		{
			if(graph[i][j])
			{
				cost+=C[i][j];
				count++;
			}
		}
		cost+=H[i][count];
	}
	return cost;
}
void solve(int n)
{
	int cost=INT_MAX;
	vector<vector<bool>>resultGraph;
	clock_t start=clock();
	clock_t end=clock();
	while(((double)end-start)/CLOCKS_PER_SEC < 0.90)// something
	{
		for(int i=0;i<1000;i++)
			parent[i]=i;
		vector<vector<bool>>graph(n,vector<bool>(n,false));
		while(!isConnected(graph))
		{
			int a,b;
			a=rand()%n;
			for(int i=0;i<n;i++)
			{
				if(find(a)!=find(i) && a!=i)
				{
					b=i;
					break;
				}
			}
			int pa=find(a),pb=find(b);
			if(pa==pb)	
				continue;
			else 
			{
				merge(a,b);
				graph[a][b]=1;
				graph[b][a]=1;
			}

		}
		ll currentCost=calCost(graph);
		if(currentCost<cost)
		{
			resultGraph=std::move(graph);
			cost=currentCost;
		}
		end=clock();
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<(int)resultGraph[i][j];
		cout<<endl;
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n, Cmax, Hmax;
		scanf("%d %d %d", &n, &Cmax, &Hmax);
		vector<ll>s1(2*n),s2(2*n);
		for(int i=0;i<2*n;i++)
			scanf("%lld%lld",&s1[i],&s2[i]);
		populate(n,Cmax,Hmax,s1,s2);

		solve(n);


	}
	return 0;
}
