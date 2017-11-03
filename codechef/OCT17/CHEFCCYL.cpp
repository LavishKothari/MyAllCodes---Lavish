#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll getSum(vector<ll>&v,int a,int b)// including a and excluding b in cyclic fashion
{
	b=(b-1+v.size())%v.size();
	if(a<=b)
		return a-1>=0?v[b]-v[a-1]:v[b];	
	return  v[v.size()-1]-v[a-1]+v[b];
}

class Cycle
{
	public:
		int n; // number of nodes in the cycle.
		vector<int>edgeWeights;
		vector<ll>sumArray;
		int start,end;
		ll dist;
		Cycle(){}
		Cycle(int n,vector<int>&w)
		{
			this->n = n;
			edgeWeights=std::move(w);
			if(edgeWeights.size()==2)
				edgeWeights[0] = edgeWeights[1] = min(edgeWeights[0],edgeWeights[1]);
			if(n==1)
				edgeWeights=vector<int>();
			sumArray=vector<ll>(edgeWeights.size());
			if(edgeWeights.size())
			{
				sumArray[0]=edgeWeights[0];
				for(int i=1;i<edgeWeights.size();i++)
					sumArray[i]=sumArray[i-1]+edgeWeights[i];
			}
			dist=INT_MAX;
		}
		ll getDistanceBetweenTwo(int a, int b)
		{
			if(a==b) return 0;
			return min(getSum(sumArray,a,b),getSum(sumArray,b,a));
		}
		void calDist()
		{
			dist=getDistanceBetweenTwo(start,end);
		}
};

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,q;
		scanf("%d%d",&n,&q);
		vector<Cycle>cycles(n);
		vector<int>edges(n);
		for(int i=0;i<n;i++)
		{
			int m;
			scanf("%d",&m); // number of vertices in the current cycle
			vector<int>e(m);
			for(int j=0;j<m;j++)
				scanf("%d",&e[j]);
			cycles[i]=std::move(Cycle(m,e));
		}
		for(int i=0;i<n;i++)
		{
			int a,b,w;
			scanf("%d%d%d",&a,&b,&w);
			a--;b--;
			cycles[i].start=a;
			cycles[(i+1)%n].end=b;
			edges[i]=w;
		}

		if(n==2 && cycles[0].start==cycles[0].end && cycles[1].start==cycles[1].end)	
			edges[0]=edges[1]=min(edges[0],edges[1]);

		for(int i=0;i<n;i++)
		{
			if(cycles[i].n==1)
				cycles[i].start=cycles[i].end=cycles[i].dist=0;
			else cycles[i].calDist();
		}

		vector<ll>distsum(cycles.size());
		distsum[0]=cycles[0].dist;
		for(int i=1;i<cycles.size();i++)
			distsum[i]=distsum[i-1]+cycles[i].dist;

		vector<ll>edgesum(edges.size());
		edgesum[0]=edges[0];
		for(int i=1;i<edges.size();i++)
			edgesum[i]=edgesum[i-1]+edges[i];

		while(q--)
		{
			int v1,c1,v2,c2;
			scanf("%d%d%d%d",&v1,&c1,&v2,&c2);
			v1--;v2--;c1--;c2--;
			ll w1=0,w2=0;
			
			w1+=getSum(edgesum,c1,c2);
			if((c1+1)%n!=c2)
				w1+=getSum(distsum,(c1+1)%n,c2);
			w1+=cycles[c1].getDistanceBetweenTwo(v1,cycles[c1].start);
			w1+=cycles[c2].getDistanceBetweenTwo(v2,cycles[c2].end);

			w2+=getSum(edgesum,c2,c1);
			if((c2+1)%n!=c1)
				w2+=getSum(distsum,(c2+1)%n,c1);
			w2+=cycles[c2].getDistanceBetweenTwo(v2,cycles[c2].start);
			w2+=cycles[c1].getDistanceBetweenTwo(v1,cycles[c1].end);

			printf("%lld\n",min(w1,w2));
		}
	}
	return 0;
}
