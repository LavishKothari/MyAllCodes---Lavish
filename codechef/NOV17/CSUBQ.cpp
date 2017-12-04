#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n; // the number of elements in the array
vector<pair<int,int> >seg;
vector<int>arr;

int q,L,R;
void build()
{
	seg = vector<pair<int,int>>(2*n);
	for(int i=n;i<2*n;i++)
		seg[i] = make_pair(0,i-n);
	arr = vector<int>(n,0);
}
void update(int value,int index)
{
	for(seg[index+=n].first=value;index>1;index>>=1)
		seg[index>>1]=max(seg[index],seg[index^1]);
}
pair<int,int> getMax(int a,int b)
{
	pair<int,int> m=make_pair(0,0);
	for(a+=n,b+=n;a<b;a>>=1,b>>=1)
	{
		if(a&1) 
		{
			m=max(m,seg[a]);
			a++;
		}
		if(b&1)
		{
			b--;
			m=max(m,seg[b]);
		}
	}
	return m;
}

ll rec(int b,int e)
{
	if(b>e)
		return 0;
	if(b==e)
		return arr[b]>=L && arr[b]<=R;
	pair<int,int> p = getMax(b,e+1);
	if(p.first >= L && p.first<=R)
		return (p.second-b+1)*(ll)(e-p.second+1);
	return rec(b,p.second-1)+rec(p.second+1,e);
}
int main()
{
	scanf("%d%d%d%d",&n,&q,&L,&R);

	build();
	while(q--)
	{
		int choice;
		scanf("%d",&choice);
		if(choice==1)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			x--;
			update(y,x);
		}
		else
		{
			int l,r;
			scanf("%d%d",&l,&r);
			printf("%lld\n",rec(l-1,r-1));
		}
	}
	return 0;
}

