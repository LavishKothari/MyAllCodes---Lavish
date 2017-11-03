#include<bits/stdc++.h>
using namespace std;
int findMinIndex(vector<int>&a)
{
	int result=0;
	for(int i=1;i<a.size();i++)
		if(a[result]>a[i])
			result=i;
	return result;
}
int findSecondMinIndex(vector<int>&a)
{
	if(findMinIndex(a)==0 && a.size()>=2)
		swap(a[0],a[1]);
	int mini=0;
	int secmini=-1;
	for(int i=1;i<a.size();i++)
	{
		if(a[mini]>=a[i])
		{
			secmini=mini;
			mini=i;
		}
	}
	return secmini;
}
void sol(vector<int>&a,vector<int>&b)
{
	int x=findMinIndex(a);
	int y=findMinIndex(b);
	if(x!=y){
		printf("%d\n",a[x]+b[y]);
		return;
	}
	int sx=findSecondMinIndex(a);
	int sy=findSecondMinIndex(b);
	int answer1=a[sx]+b[y];
	int answer2=a[x]+b[sy];
	printf("%d\n",answer1<answer2?answer1:answer2);
}
int main()
{
	int n;
	scanf("%d",&n);
	vector<int>a(n);
	vector<int>b(n);

	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&b[i]);
	sol(a,b);
	return 0;
}
