#include <bits/stdc++.h>
using namespace std;

#define N 30001
#define A 1000001
#define BS 548 // this is block size approx sqrt(N)

struct Query
{
	int L,R,index;
};

bool comp(struct Query x,struct Query y)
{
	if(x.L/BS != y.L/BS)
		return x.L<y.L;
	return x.R<y.R;
}

int add(int* arr,int *count,int &answer,int index)
{
	count[arr[index]]++;
	if(count[arr[index]]==1)
		answer++;
}
int remove(int*arr,int *count,int &answer,int index)
{
	count[arr[index]]--;
	if(count[arr[index]]==0)
		answer--;
}

int main()
{
	int n;
	scanf("%d",&n);
	int*arr;
	arr=new int[n];
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);

	int count[A]={0};


	int m;
	scanf("%d",&m);
	struct Query*query;
	query=new struct Query[m];
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&query[i].L,&query[i].R);
		query[i].L--;
		query[i].R--;
		query[i].index=i;
	}

	sort(query,query+m,comp);
	int *ans=new int[m];
	int currentL,currentR,answer;
	currentL=currentR=answer=0;
	answer=1;
	count[arr[0]]=1;
	for(int i=0;i<m;i++)
	{
		int L,R;
		L=query[i].L;
		R=query[i].R;
		while(currentL < L)
		{
			remove(arr,count,answer,currentL);
			currentL++;
		}
		while(currentL > L)
		{
			add(arr,count,answer,currentL-1);
			currentL--;
		}
		while(currentR < R)
		{
			add(arr,count,answer,currentR+1);
			currentR++;
		}
		while(currentR > R)
		{
			remove(arr,count,answer,currentR);
			currentR--;
		}
		ans[query[i].index]=answer;
	}
	for(int i=0;i<m;i++)
		printf("%d\n",ans[i]);
	free(ans);
	free(query);
	free(arr);

	return 0;
}
