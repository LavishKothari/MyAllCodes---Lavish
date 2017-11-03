#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<vector>
#include<set>
#include<map>
typedef long long int ll;
#define MOD 1000000007
using namespace std;
int*ax,*bx,m,n,*arr,*factorial;
void populatefactorial()
{
	factorial=new int[100009];
	factorial[0]=1;
	for(int i=1;i<100009;i++)
		factorial[i]=(i*(ll)factorial[i-1])%MOD;
}
int findBlocks(vector<int>x,vector<int>y) // this function finds the number of blocks
{
	map<int,set<int> >graph;
	for(int i=0;i<x.size();i++)
	{
		graph[x[i]].insert(y[i]);
		graph[y[i]].insert(x[i]);
	}
	int degree1=0,degree2=0;
	for(map<int,set<int> >::iterator it=graph.begin();it!=graph.end();it++)
	{
		if((it->second).size()==1)
			degree1++;
		else if((it->second).size()==2)
			degree2++;
		else if((it->second).size()>2)
			return -1;
	}
	int blocks=0;
	while(true)
	{
		map<int,set<int> >::iterator it;
		for(it=graph.begin();graph.size()!=0 && it!=graph.end();it++)
		{
			if((it->second).size()==1)
				break;
		}
		if(it==graph.end() || graph.size()==0)
			break;
		else
		{
			// here 'it' is the iterator to the vertex of degree 1
			blocks++;
			while(true)
			{

				map<int,set<int> >::iterator nextit=graph.find(*((it->second).begin()));
				if(nextit==graph.end())
					break;
				int key=it->first;
				int temp=*((it->second).begin());
				graph[temp].erase(key);
				graph.erase(it);
				//it=graph.find(temp);
				it=nextit;
			}

		}
	}
	if(blocks==0 || graph.size()!=blocks)
		return -1;
	return blocks;
}
ll findBad(int number)
{
	//printf("\nthis is the starting of findBad .........................%d\n",number);
	set<int>myset;
	vector<int>newax,newbx;
	int i=1;
	while(number)
	{
		if(number&1)
		{
			newax.push_back(ax[m-i]);
			newbx.push_back(bx[m-i]);

			myset.insert(ax[m-i]);
			myset.insert(bx[m-i]);
			//printf("$$$$$$m,i = %d,%d and %d,%d\n",m,i,ax[m-i],bx[m-i]);
		}
		i++;
		number=number>>1;
	}
	if(myset.size()>n)
		return 0;
	int blocks=findBlocks(newax,newbx);
	//if(number==3)
	//printf("number of blocks : %d\n",blocks);
	if(blocks==-1)
		return 0;
	//printf("please %d - %d + %d === %d\n",n,myset.size(),blocks,n-myset.size()+blocks);
	//printf("Returning = %lld\n",((ll)factorial[n-myset.size()+blocks]*(1<<blocks))%MOD);
	return ((ll)factorial[n-myset.size()+blocks]*(1<<blocks))%MOD;
}
int bitsin(int number)
{
	int answer=0;
	while(number)
	{
		if(number&1)
			answer++;
		number=number>>1;
	}
	return answer;
}
ll findAnswer()
{
	ll answer=factorial[n];
	ll p=0;
	for(int i=0;i<(1<<m);i++)
	{
		//printf("hell/******************************************************************/\n");
		int bits=bitsin(i);
		ll fb=findBad(i);
		if(bits&1)
		{
			//printf("findbad(%d) = %lld\n",i,+fb);
			p=(p+fb)%MOD;
		}
		else
		{
			//printf("findbad(%d) = %lld\n",i,-fb);
			p=(p-fb)%MOD;
		}
	}
	answer=(answer-p)%MOD;
	if(answer<0)
		answer+=MOD;
	return answer;
}
	.
int main()
{
	int t;
	scanf("%d",&t);
	populatefactorial();
	while(t--)
	{
		scanf("%d%d",&n,&m);
		ax=new int[m];
		bx=new int[m];
		for(int i=0;i<m;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			ax[i]=min(a,b);
			bx[i]=max(a,b);
			//printf("perfect %d %d\n",ax[i],bx[i]);
		}
		printf("%lld\n",findAnswer());
		delete ax;
		delete bx;
	}
	delete factorial;
	return 0;
}
