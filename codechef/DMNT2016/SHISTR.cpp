#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long int ll;
class O
{
	public :
		int l,r,k;
		O(int,int,int);
};
O::O(int l,int r,int k)
{
	this->l=l;
	this->r=r;
	this->k=k;
}

bool cm(const O&a,const O&b)
{
	return a.r<b.r;
}
bool cmp(const O&a,int x)
{
	return a.r<x;
}
int main()
{
	ll t;
	char str[5001];
	scanf("%lld",&t);
	while(t--)
	{
		vector<O>v;
		int n,q;
		scanf("%d%d",&n,&q);
		scanf(" %s",str);
		for	(int i=0;i<q;i++)
		{
			int l,r,k;
			scanf("%d%d%d",&l,&r,&k);
			v.push_back(O(l-1,r-1,k));
		}
		/*
		   printf("hello aish\n");		
		   for(int i=0;i<v.size();i++)
		   printf("%d %d %d\n",v[i].l,v[i].r,v[i].k);
		 */
		sort(v.begin(),v.end(),cm);
		/*
		   printf("hello aish\n");		
		   for(int i=0;i<v.size();i++)
		   printf("%d %d %d\n",v[i].l,v[i].r,v[i].k);
		 */
		for(int i=0;i<n;i++)
		{
			vector<O>::iterator it;
			it=lower_bound(v.begin(),v.end(),i,cmp);
			//printf("%d %d %d\n",it->l,it->r,it->k);
			//printf("this is a test %d %d\n",i,it-v.begin());
			while(1)
			{
				O &obj=(*it);
				if(i>=obj.l && i<=obj.r)
				{
					int temp=(str[i]-'a'+obj.k)%26;
					if(temp<0)
						temp+=26;
					str[i]=temp+'a';
				}
				//printf("jell %d %d\n",i,it->l);
				it++;
				if(it-v.begin()>=v.size())
					break;
			}
			//printf("%s\n",str);
		}
		printf("%s\n",str);
	}
	return 0;
}
