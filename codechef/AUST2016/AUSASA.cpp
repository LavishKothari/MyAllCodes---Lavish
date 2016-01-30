#include<stdio.h>
#include<utility>
#include<vector>

using namespace std;
pair<int,int> mini(vector<int>arr,int start,int n,int k)
{
	int m=arr[start],mi=start;
	for(int i=start;i<n && i<=k;i++)
	{
		if(m>arr[i])
		{
			mi=i;
			m=arr[i];
		}
	}
	return make_pair(mi,m);
}
void printAnswer(vector<int>arr,int n,int k)
{
	int start=0;
	while(k>0 && start<n)
	{
		//printf("/////// %d \n",k);
		pair<int,int>p;
		p=mini(arr,0,arr.size(),k);
		printf("%d ",p.second);
		arr.erase(arr.begin()+p.first);
		k=k-p.first;
		start++;
	}
	for(int i=0;i<arr.size();i++)
		printf("%d ",arr[i]);
	printf("\n");
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		vector<int>arr(n);
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);
		printAnswer(arr,n,k);
	}
	return 0;
}
