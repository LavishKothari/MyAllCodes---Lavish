#include<stdio.h>
#include<set>
#include<vector>
#include<stdlib.h>
using namespace std;

int containsHash(char**arr,int a,int b)
{
	int i;
	for(i=0;i<b;i++)
		if(arr[a][i]=='#')
			return 1;
	return 0;
}

int main()
{
	int t,i,n,j,favi;
	char **arr;
	arr=(char**)malloc(sizeof(char*)*500);
	for(i=0;i<500;i++)
		arr[i]=(char*)malloc(sizeof(char)*501);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)	
			scanf(" %s",arr[i]);
		set<int>x;
		set<int>y;
		int answer=0;
		for(j=n-1;j>=0;j--)
		{
			int flag=0;
			for(i=n-1;i>=0 && arr[i][j]!='#';i--)
				if(!containsHash(arr,i,j) && x.find(i)==x.end() && y.find(j)==y.end())
					favi=i;
			flag=1;	
			if(flag==1)
			{
				x.insert(favi);
				y.insert(j);
				answer++;
			}
		}
		printf("%d\n",answer);
	}
	return 0;
}
