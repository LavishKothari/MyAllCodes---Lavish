
#include<bits/stdc++.h>
using namespace std;
#define MAX 1024
typedef long long int ll;
ll tree[MAX][MAX] = {0};  // To store segment tree
ll lazy[MAX][MAX] = {0};  // To store pending updates

void updateRangeUtil(int index, int si, int ss, int se, int us,
		int ue, int diff)
{
	if (lazy[index][si] != 0)
	{
		tree[index][si] += (se-ss+1)*lazy[index][si];

		if (ss != se)
		{
			lazy[index][si*2 + 1]   += lazy[index][si];
			lazy[index][si*2 + 2]   += lazy[index][si];
		}
		lazy[index][si] = 0;
	}

	if (ss>se || ss>ue || se<us)
		return ;

	if (ss>=us && se<=ue)
	{
		tree[index][si] += (se-ss+1)*diff;

		if (ss != se)
		{
			lazy[index][si*2 + 1]   += diff;
			lazy[index][si*2 + 2]   += diff;
		}
		return;
	}

	int mid = (ss+se)/2;
	updateRangeUtil(index,si*2+1, ss, mid, us, ue, diff);
	updateRangeUtil(index,si*2+2, mid+1, se, us, ue, diff);

	tree[index][si] = tree[index][si*2+1] + tree[index][si*2+2];
}

void updateRange(int index, int n, int us, int ue, int diff)
{
	updateRangeUtil(index,0, 0, n-1, us, ue, diff);
}

ll getSumUtil(int index,int ss, int se, int qs, int qe, int si)
{
	if (lazy[index][si] != 0)
	{
		tree[index][si] += (se-ss+1)*lazy[index][si];

		if (ss != se)
		{
			lazy[index][si*2+1] += lazy[index][si];
			lazy[index][si*2+2] += lazy[index][si];
		}

		lazy[index][si] = 0;
	}

	if (ss>se || ss>qe || se<qs)
		return 0;

	if (ss>=qs && se<=qe)
		return tree[index][si];

	int mid = (ss + se)/2;
	return getSumUtil(index,ss, mid, qs, qe, 2*si+1) +
		getSumUtil(index,mid+1, se, qs, qe, 2*si+2);
}

int getSum(int index,int n, int qs, int qe)
{
	if (qs < 0 || qe > n-1 || qs > qe)
	{
		//printf("Invalid Input");
		return -1;
	}

	return getSumUtil(index,0, n-1, qs, qe, 0);
}

void constructSTUtil(int index,int arr[], int ss, int se, int si)
{
	if (ss > se)
		return ;
	if (ss == se)
	{
		tree[index][si] = arr[ss];
		return;
	}
	int mid = (ss + se)/2;
	constructSTUtil(index,arr, ss, mid, si*2+1);
	constructSTUtil(index,arr, mid+1, se, si*2+2);

	tree[index][si] = tree[index][si*2 + 1] + tree[index][si*2 + 2];
}
void constructST(int index,int arr[], int n)
{
	constructSTUtil(index,arr, 0, n-1, 0);
}


int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	int matrix[MAX][MAX];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&matrix[i][j]);

	for(int i=0; i<n; i++)
		constructST(i, matrix[i], m);


	while(k--) {
		int l,r;
		int row,col,s,value;
		scanf("%d%d%d%d",&row,&col,&s,&value);
		row--;
		col--;
		l=col;
		r=min(col+s,m);
		for(int i=row;i<row+s && i<n;i++)
		{
			updateRange(i, m, l, r-1, value);
		}
	}


	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++)
			cout<<getSum(i,m,j,j)<<" ";
		cout<<endl;
	}
	return 0;
}
