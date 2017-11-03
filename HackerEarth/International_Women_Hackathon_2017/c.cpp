#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void construct_Segment_Tree1(int current_row,int node, int a, int b) {
	if(a > b) return; 

	if(a == b) { 
		tree[current_row][node] = matrix_for_use[current_row][a]; 
		return;
	}
	construct_Segment_Tree(current_row,node*2, a, (a+b)/2); 
	construct_Segment_Tree(current_row,node*2+1, 1+(a+b)/2, b);
	tree[current_row][node] = (tree[current_row][node*2]+tree[current_row][node*2+1]);
}
int get_Sum1(int current_row,int current_item, int a, int b, int i, int j) {
	if(b < i || a > b || a > j) 
		return -INT_MAX; 

	if(derived_Array[current_row][current_item] != 0) { 
		tree[current_row][current_item] += derived_Array[current_row][current_item]; 
		if(a != b) {
			derived_Array[current_row][current_item*2] += derived_Array[current_row][current_item];
			derived_Array[current_row][current_item*2+1] += derived_Array[current_row][current_item]; 
		}
		derived_Array[current_row][current_item] = 0;
	}

	if(a >= i && b <= j) 
		return tree[current_row][current_item];

	int x1 = get_Sum(current_row,current_item*2, a, (a+b)/2, i, j); 
	int x2 = get_Sum(current_row,1+current_item*2, 1+(a+b)/2, b, i, j);
	return (x1>x2)?x1:x2;
}
void update_tree1(int current_row,int current_item, int a, int b, int i, int j, int item) {
	if(derived_Array[current_row][current_item] != 0) { 
		tree[current_row][current_item] += derived_Array[current_row][current_item]; 
		if(a != b) {
			derived_Array[current_row][current_item*2] += derived_Array[current_row][current_item];
			derived_Array[current_row][current_item*2+1] += derived_Array[current_row][current_item];
		}
		derived_Array[current_row][current_item] = 0; 
	}
	if(a > b || a > j || b < i)
		return;
	if(a >= i && b <= j) { 
		tree[current_row][current_item] += item;
		if(a != b) { 
			derived_Array[current_row][current_item*2] += item;
			derived_Array[current_row][current_item*2+1] += item;
		}
		return;
	}
	update_tree(current_row,current_item*2, a, (a+b)/2, i, j, item); 
	update_tree(current_row,1+current_item*2, 1+(a+b)/2, b, i, j, item); 
	tree[current_row][current_item] = (tree[current_row][current_item*2]+ tree[current_row][current_item*2+1]); 
}

void buildST(vector<int>&st,vector<int>&v)
{
	int n=v.size();
	for(int i=0;i<n;i++)
		st[i+n]=v[i];
	for(int i=n-1;i>0;i--)
		st[i]=st[i<<1]+st[i<<1|1];
}

void modify(vector<int>&t,int l, int r, int value) 
{
	int n=t.size()/2;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l&1) t[l++] += value;
		if (r&1) t[--r] += value;
	}
}
/*
   int query(vector<int>&t,int p) 
   {
   int n=t.size()/2;
   int res = 0;
   for (p += n; p > 0; p >>= 1) 
   res += t[p];
   return res;
   }
 */
int query(vector<int>&t, int l, int r) {  // sum on interval [l, r)
	int res = 0;
	int n=t.size()/2;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l&1) res += t[l++];
		if (r&1) res += t[--r];
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
		buildST(st[i],matrix[i]);

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
			cout<<query(st[i],j,j+1)<<" ";
		cout<<endl;
	}

	return 0;
}
