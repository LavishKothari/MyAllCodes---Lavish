// this program uses greedy approach and segment trees.
#include<bits/stdc++.h>
#define N 100001
using namespace std;
typedef long long int ll;
class Trainer
{
	public:
		int d,t,s,index;
		Trainer(){}
		Trainer(int d,int t,int s)
		{
			this->d=d;
			this->t=t;
			this->s=s;
		}
};
bool cmp(const Trainer&a,const Trainer&b)
{
	pair<int,int>p1=make_pair(a.d,-a.s);
	pair<int,int>p2=make_pair(b.d,-b.s);
	return p1<p2;
}
bool cmpupper(const int &a,const Trainer&b)
{
	return a<b.d;
}
bool cmplower(const Trainer&a,const int &b)
{
	return a.d<b;
}
int findMaxIndex(vector<Trainer>&v,int start,int end)
{
	if(start>=end)
		return -1;
	int maxValue=0;
	int maxIndex=-1;
	for(int i=start;i<end;i++)
	{
		if(v[i].t && maxValue<v[i].s)
		{
			maxIndex=i;
			maxValue=v[i].s;
		}
	}
	return maxIndex;
}
int query(int l,int r,vector<Trainer*>&seg,int n)
{
	if(l>=r)
		return -1;
	int maxValue=0,maxIndex=-1;
	for(l+=n,r+=n;l<r;l>>=1,r>>=1)
	{
		if(l&1)
		{
			if(seg[l]->s && seg[l]->t && maxValue < seg[l]->s)
			{
				maxValue=seg[l]->s;
				maxIndex = seg[l]->index;
			}
			l++;
		}
		if(r&1)
		{
			r--;
			if(seg[r]->s && seg[r]->t && maxValue<seg[r]->s)
			{
				maxValue=seg[r]->s;
				maxIndex = seg[r]->index;
			}
		}
	}
	return maxIndex;
}
void update(int index,int value,vector<Trainer*>&seg,int n)
{
	for(seg[index+=n]->s=value;index>1;index>>=1)
	{
		//seg[index>>1]  is to be assigned
		if(seg[index]->s > seg[index^1]->s)
			seg[index>>1] = seg[index];
		else seg[index>>1] = seg[index^1];
	}
}
void build(vector<Trainer>&v,vector<Trainer*>&seg) // building the segment tree for max of s
{
	int n=v.size();
	for(int i=0;i<n;i++)
		seg[i+n]=&v[i];
	for(int i=2*n;i<seg.size();i++)
		seg[i]=new Trainer(0,0,0);	
	for(int i=n-1;i>0;i--)
	{
		if(seg[i<<1]->s > seg[i<<1|1]->s)
			seg[i]=seg[i<<1];
		else seg[i]=seg[i<<1|1];
	}
}
void printSegTree(vector<Trainer*>&seg)
{
	cout<<"_________________________________________________________________"<<endl;
	for(int i=1;i<seg.size();i++)
	{
		cout<<"index = "<<i<<"   =>   "<<seg[i]->d<<" "<<seg[i]->t<<" "<<seg[i]->s<<" "<<seg[i]->index<<endl; 
	}
	cout<<"_________________________________________________________________"<<endl;
}

ll solve1(int n,int d,vector<Trainer>v,vector<Trainer*>&seg) // Naive bruteforce.
{
	ll sum=0;
	for(int i=0;i<v.size();i++)
		sum+=v[i].t;
	if(sum<=n)
		return 0;

	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<v.size();i++)
		v[i].index=i;
	build(v,seg);
	//printSegTree(seg);
	int next0=1;
	for(int i=1;i<=d;i++)
	{
		int start;
		//start = lower_bound(v.begin(),v.end(),next0,cmplower)-v.begin();
		start=0;
		int end = upper_bound(v.begin(),v.end(),i,cmpupper)-v.begin();
		if(start>v.size())
			break;
		int current;
		current = findMaxIndex(v,start,end); // not calling this function, complexity O(n)
		//current=query(start,end,seg,n); // segment tree query, complexity O(log n)
		if(v[current].t==0 || v[current].s==0 || current==-1)
			continue;
		else 
		{
			v[current].t--;
			if(v[current].t==0)
				update(current,0,seg,n);
		}
	}
	ll answer=0;
	for(int i=0;i<v.size();i++)
		answer=answer+(ll)v[i].s*(ll)v[i].t;
	return answer;
}
ll solve(int n,int d,vector<Trainer>v,vector<Trainer*>&seg)// using segment tree
{
	ll sum=0;
	for(int i=0;i<v.size();i++)
		sum+=v[i].t;
	if(sum<=n)
		return 0;

	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<v.size();i++)
		v[i].index=i;
	build(v,seg);
	//printSegTree(seg);
	int next0=1;
	for(int i=1;i<=d;i++)
	{
		int start;
		//start = lower_bound(v.begin(),v.end(),next0,cmplower)-v.begin();
		start=0;
		int end = upper_bound(v.begin(),v.end(),i,cmpupper)-v.begin();
		if(start>=end)
			continue;
		if(start>v.size())
			break;
		int current;
		//current = findMaxIndex(v,start,end); // not calling this function, complexity O(n)
		current=query(start,end,seg,n); // segment tree query, complexity O(log n)
		if(v[current].t==0 || v[current].s==0 || current==-1)
			continue;
		v[current].t--;
		if(v[current].t<=0)
			update(current,0,seg,n);
	}
	ll answer=0;
	for(int i=0;i<v.size();i++)
		answer=answer+(ll)v[i].s*(ll)v[i].t;
	return answer;
}
int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,d;
		scanf("%d%d",&n,&d);
		vector<Trainer>v(n);
		vector<Trainer*>seg(2*n+10);
		for(int i=0;i<n;i++)
			scanf("%d%d%d",&v[i].d,&v[i].t,&v[i].s);
		printf("%lld\n",solve(n,d,v,seg)); // my answer
		//printf("%lld\n",solve1(n,d,v,seg)); // correct answer
	}
	return 0;
}
