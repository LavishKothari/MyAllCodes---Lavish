#include <bits/stdc++.h>
using namespace std;

void findAnswer(vector<int>p,vector<vector<int> >&tree)
{
	int n=p.size();

	vector<int>result(n);

	vector<pair<int,int> >pi(n); 
	for(int i=0;i<n;i++)
		pi[i]=make_pair(p[i],i);
	make_heap(pi.begin(),pi.end());


	set<pair<int,int> >tobedeleted;
	set<pair<int,int> >deleted;

	for(int i=0;i<n;i++)
	{
		/*
		   cout<<"******************\n";
		   cout<<"deleting "<<p[i]<<endl;
		 */

		for(set<pair<int,int> >::iterator it=deleted.begin();it!=deleted.end();it++)
		{
			pi.push_back(*it);
			push_heap(pi.begin(),pi.end());		
		}
		//make_heap(pi.begin(),pi.end());
		/*
		   for(int x=0;x<pi.size();x++)
		   cout<<pi[x].first<<","<<pi[x].second<<endl;
		 */
		deleted = set<pair<int,int> >(); 
		tobedeleted = set<pair<int,int> >();

		tobedeleted.insert(make_pair(p[i],i));
		for(int j=0;j<tree[i].size();j++)
			tobedeleted.insert(make_pair(p[tree[i][j]],tree[i][j]));

		while(true)
		{
			pair<int,int>current_pair=pi[0];
			if(tobedeleted.find(current_pair)==tobedeleted.end())
			{
				result[i]=current_pair.second;
				break;
			}
			else
			{
				pop_heap(pi.begin(),pi.end());
				deleted.insert(current_pair);
			}
			pi.pop_back();
		}
		//cout<<"number of deleted = "<<deleted.size()<<endl;
	}
	for(int i=0;i<result.size();i++)
		cout<<result[i]+1<<" ";
	cout<<endl;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		vector<int>p(n);
		vector<vector<int> >tree(n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&p[i]);
			vector<int>v;
			tree[i]=v;
		}
		for(int i=0;i<n-1;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			tree[a-1].push_back(b-1);
			tree[b-1].push_back(a-1);
		}
		findAnswer(p,tree);
	}

	return 0;
}
