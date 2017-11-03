#include<bits/stdc++.h>
using namespace std;
#define MAX 1024
int matrix_for_use[MAX][MAX];
int tree[MAX][2*MAX];
int derived_Array[MAX][2*MAX];
int get_Sum(int ,int , int , int , int , int );
void update_tree(int ,int , int , int , int , int , int );
void construct_Segment_Tree(int current_row,int node, int a, int b) {
	if(a > b) return; 

	if(a == b) { 
		tree[current_row][node] = matrix_for_use[current_row][a]; 
		return;
	}
	construct_Segment_Tree(current_row,node*2, a, (a+b)/2); 
	construct_Segment_Tree(current_row,node*2+1, 1+(a+b)/2, b);
	tree[current_row][node] = (tree[current_row][node*2]+tree[current_row][node*2+1]);
}
int main() {
	int n,m,k;cin>>n>>m>>k;
	for(int i=0;i<n;i++) 
		for(int j=0;j<m;j++) 
			cin>>matrix_for_use[i][j];
	for(int i=0; i<n; i++) 
		construct_Segment_Tree(i,1,0,m-1);
	for(int x=0; x<k; x++) {
		int left,right,row,col,s,item;cin>>row>>col>>s>>item;
		row--;col--;
		left=col;
		right=min(col+s,m);
		for(int i=row;i<n && i<row+s ;i++)
			update_tree(i,1,0, m-1, left, right-1, item);       
	}
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++)
			cout<<get_Sum(i,1,0,m-1,j,j)<<" ";
		cout<<endl;
	}
	return 0;
}
int get_Sum(int current_row,int current_item, int start, int end, int i, int j) {
	if(end < i || start > end || start > j) 
		return -INT_MAX; 
	if(derived_Array[current_row][current_item] != 0) { 
		tree[current_row][current_item] += derived_Array[current_row][current_item]; 
		if(start != end) {
			derived_Array[current_row][current_item*2] += derived_Array[current_row][current_item];
			derived_Array[current_row][current_item*2+1] += derived_Array[current_row][current_item]; 
		}
		derived_Array[current_row][current_item] = 0;
	}
	if(start >= i && end <= j) 
		return tree[current_row][current_item];
	int x1 = get_Sum(current_row,current_item*2, start, (start+end)/2, i, j); 
	int x2 = get_Sum(current_row,1+current_item*2, 1+(start+end)/2, end, i, j);
	return (x1>x2)?x1:x2;
}
void update_tree(int current_row,int current_item, int start, int end, int i, int j, int item) {
	if(derived_Array[current_row][current_item] != 0) { 
		tree[current_row][current_item] += derived_Array[current_row][current_item]; 
		if(start != end) {
			derived_Array[current_row][current_item*2] += derived_Array[current_row][current_item];
			derived_Array[current_row][current_item*2+1] += derived_Array[current_row][current_item];
		}
		derived_Array[current_row][current_item] = 0; 
	}
	if(start > end || start > j || end < i)
		return;
	if(start >= i && end <= j) { 
		tree[current_row][current_item] += item;
		if(start != end) { 
			derived_Array[current_row][current_item*2] += item;
			derived_Array[current_row][current_item*2+1] += item;
		}
		return;
	}
	update_tree(current_row,current_item*2, start, (start+end)/2, i, j, item); 
	update_tree(current_row,1+current_item*2, 1+(start+end)/2, end, i, j, item); 
	tree[current_row][current_item] = (tree[current_row][current_item*2]+ tree[current_row][current_item*2+1]); 
}
