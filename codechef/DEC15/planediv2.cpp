#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
int gcd(int a,int b)
{
	if(a==0)
		return b;
	if(b==0)
		return a;
	return gcd(b,a%b);
}

int p(int x)
{
	if(x>=0)
		return x;
	return -x;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		map < double , set<double> > globalMap;
		set<double>fory;
		globalMap.erase(globalMap.begin(),globalMap.end());
		fory.erase(fory.begin(),fory.end());
		int n;
		scanf("%d",&n);

		for(int i=0;i<n;i++)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			if(x<0)
			{
				x=-x;
				y=-y;
				z=-z;
			}
			else if(x==0)
			{
				if(y<0)
				{
					y=-y;
					z=-z;
				}
			}
			if(y==0)
				fory.insert((double)z/x);
			else
			{
				globalMap[(double)x/y].insert(z/(double)gcd(p(x),p(y)));
				//printf("%lf ->> %d\n",(double)x/y,z/gcd(gcd(p(x),p(y)),p(z)));
			}
		}
		int mmax=0;
		for(map<double , set<double> >::iterator it=globalMap.begin();it!=globalMap.end();it++)
		{
			int tel=(it->second).size();
			//printf("%lf size = %d\n",it->first,(it->second).size());
			if(tel>mmax)
				mmax=tel;
		}

		if(fory.size()>mmax)
			mmax=fory.size();
		printf("%d\n",mmax);
	}
	return 0;
}
