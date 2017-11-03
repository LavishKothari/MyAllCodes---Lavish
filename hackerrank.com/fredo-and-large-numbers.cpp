#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define MAX 1000001
typedef long long int ll;

class element
{
	public:
		int fo,freq;
		ll e;
		element(int fo,ll e,int freq)
		{
			this->fo=fo;
			this->e=e;
			this->freq=freq;
		}
};
bool cmp1(const element&a,const element&b)
{
	return a.fo<b.fo;
}
bool cmp2(const element&a,const element&b)
{
	return a.freq<b.freq;
}
bool cmp3(const element&a,const ll &b)
{
	return a.freq<b;
}

int main()
{
	int n;
	ll arr[MAX];
	map<ll,int>mp;
	scanf("%d",&n);
	vector<ll>type0(MAX,0);
	vector<ll>index0(MAX,MAX);
	map<ll,int>firstOccur;
	/*
	   for(int i=0;i<MAX;i++)
	   index0[i]=MAX;
	 */
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&arr[i]);
		if(firstOccur.find(arr[i])==firstOccur.end())
			firstOccur[arr[i]]=i;
		if(mp.find(arr[i])==mp.end())
			mp[arr[i]]=1;
		else 
			mp[arr[i]]++;
		if(index0[mp[arr[i]]]>firstOccur[arr[i]])
		{
			index0[mp[arr[i]]]=firstOccur[arr[i]];
			type0[mp[arr[i]]]=arr[i];
		}
	}
	vector<element>elevector;
	for(map<ll,int>::iterator it=mp.begin();it!=mp.end();it++)
	{
		ll key=it->first;
		int value=it->second;
		elevector.push_back(element(firstOccur[key],key,value));
	}

	stable_sort(elevector.begin(),elevector.end(),cmp1); // sorting according to fo
	stable_sort(elevector.begin(),elevector.end(),cmp2); // sorting according to frequency

	int q;
	scanf("%d",&q);
	while(q--)
	{
		int type;
		ll f;
		scanf("%d%lld",&type,&f);
		if(f>n)
		{
			printf("0\n");
			continue;
		}
		if(type==0)
		{
			printf("%lld\n",type0[f]);
		}
		else if(type==1)
		{
			vector<element>::iterator it;
			it=lower_bound(elevector.begin(),elevector.end(),f,cmp3);

			if(it==elevector.end() || it->freq != f)
			{
				printf("0\n");
				continue;
			}
			printf("%lld\n",it->e);
		}
	}
	return 0;
}
