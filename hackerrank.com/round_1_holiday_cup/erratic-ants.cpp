#include<stdio.h>
#include<vector>
using namespace std;
bool areEqual(pair<int,int>a,pair<int,int>b)
{
	if(a.first==b.first && a.second==b.second)
		return true;
	return false;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		vector<pair<int,int> >path;
		int n;
		scanf("%d",&n);
		path.push_back(make_pair(0,0));
		for(int i=1;i<=n;i++)
		{
			char ch;
			scanf(" %c",&ch);
			//printf("----%c----\n",ch);
			if(ch=='E')
			{
				path.push_back(make_pair(path[i-1].first+1,path[i-1].second));
			}
			else if(ch=='W')
			{
				path.push_back(make_pair(path[i-1].first-1,path[i-1].second));
			}
			else if(ch=='N')
			{
				path.push_back(make_pair(path[i-1].first,path[i-1].second+1));
			}
			else if(ch=='S')
			{
				path.push_back(make_pair(path[i-1].first,path[i-1].second-1));
			}
		}
		/*for(int i=0;i<path.size();i++)
		  {
		  printf("(%d,%d)\n",path[i].first,path[i].second);
		  }*/
		for(int i=0;i<path.size();i++)
		{
			for(int j=i+1;j<path.size();j++)
			{
				if(areEqual(path[i],path[j]))
				{
					//printf("deleting from %d to %d \n",i,j);
					path.erase(i+path.begin(),j+path.begin());
					i=0;j=1;
				}
			}
		}
		printf("%d\n",path.size()-1);
	}
	return 0;
}
