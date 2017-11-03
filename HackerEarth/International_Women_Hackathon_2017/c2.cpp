#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int n=4;
int d[4];

void apply(int p, int value) {
	t[p] += value;
	if (p < n) d[p] += value;
}

void build(vector<int> &t,int p) {
	while (p > 1) p >>= 1, t[p] = max(t[p<<1], t[p<<1|1]) + d[p];
}

void push(int p) {
	for (int s = h; s > 0; --s) {
		int i = p >> s;
		if (d[i] != 0) {
			apply(i<<1, d[i]);
			apply(i<<1|1, d[i]);
			d[i] = 0;
		}
	}
}

void inc(int l, int r, int value) {
	l += n, r += n;
	int l0 = l, r0 = r;
	for (; l < r; l >>= 1, r >>= 1) {
		if (l&1) apply(l++, value);
		if (r&1) apply(--r, value);
	}
	build(l0);
	build(r0 - 1);
}

int query(vector<int> &t,int l, int r) {
	l += n, r += n;
	push(vector<int> &t,l);
	push(vector<int> &t,r - 1);
	int res = -2e9;
	for (; l < r; l >>= 1, r >>= 1) {
		if (l&1) res = max(res, t[l++]);
		if (r&1) res = max(t[--r], res);
	}
	return res;
}

int main()
{

	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	vector<vector<int> >matrix(n,vector<int>(m));
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>matrix[i][j];

	vector<vector<int> >st(n,vector<int>(2*m));
	for(int i=0;i<n;i++)
		build(st[i],matrix[i]);

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<2*m;j++)
			cout<<st[i][j]<<" ";
		cout<<endl;
	}   
	//return 0;

	while(k--) {
		int l,r;
		int row,col,s,value;
		cin>>row>>col>>s>>value;
		row--;
		col--;
		l=col;
		r=min(col+s,m);
		for(int i=row;row+s<n && i<row+s;i++)
			modify(st[i],l,r,value);
	}
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++)
			cout<<query(st[i],0,j+1)<<" ";
		cout<<endl;
	}

	return 0;
}
