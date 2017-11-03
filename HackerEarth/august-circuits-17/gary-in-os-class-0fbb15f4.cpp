#include<bits/stdc++.h>
#include<ctime>
#include<chrono>
using namespace std;
typedef long long int ll;
class Block
{
	public:
		int size;
		vector<int>file_list;
		Block()
		{	
			size=0;
		}
		Block(int size)
		{
			this->size=size;
		}
};

ll globalMin=INT_MAX;
int globalK;
vector<Block>globalBlocks;
vector<pair<int,int> >files;
int flag=0;
void solve(vector<int>&v,int n,int m)
{
	if(!flag)
	{
		for(int i=0;i<v.size();i++)
		{
			pair<int,int>p=make_pair(v[i],i+1);

			files.push_back(p);
		}
		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
		shuffle (files.begin(), files.end(), std::default_random_engine(seed));
		flag=1;
		sort(files.begin(),files.end());
		reverse(files.begin(),files.end());
	}
	int k=rand()%(m-1)+1;// block size
	vector<Block>blocks(m/k,Block(k));
	set<int>s;
	int r=0;
	for(int i=0,j=0;j<2*v.size();j++,i=(i+1)%v.size()) // picking a file and trying to insert it into a random block
	{
		if(s.find(i)!=s.end())
			continue;
		//r=rand()%blocks.size(); // choosing a random block
		r=(r+1)%m/k;
		if(blocks[r].size>=files[i].first)
		{
			s.insert(i);
			blocks[r].file_list.push_back(files[i].second);
			blocks[r].size-=files[i].first;
		}
	}
	int f=m%k;
	for(int i=0;i<blocks.size();i++)
		f+=blocks[i].size;
	if(f*f+k*k < globalMin)
	{
		globalMin=f*f+k*k;
		globalK = k;
		globalBlocks=blocks;
	}
}
int main()
{
	srand(time(NULL));
	int n,m;
	scanf("%d%d",&n,&m);
	vector<int>v(n);
	for(int i=0;i<n;i++)
		scanf("%d",&v[i]);

	time_t timer1;
	time(&timer1);
	time_t  timer2;
	double second;

	for(;;) 
	{
		solve(v,n,m);

		time(&timer2);
		second = difftime(timer2,timer1);
		if(second > 3.5)
			break;
	}
	printf("%d\n",globalK);
	for(int i=0;i<globalBlocks.size();i++)
	{
		printf("%d ",globalBlocks[i].file_list.size());
		for(int j=0;j<globalBlocks[i].file_list.size();j++)
			printf("%d ",globalBlocks[i].file_list[j]);
		printf("\n");
	}
	return 0;
}
