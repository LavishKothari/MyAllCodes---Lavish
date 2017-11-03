#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>a,b,c;
int gcd(int a,int b)
{
	b==0?a:gcd(b,a%b);
}
int compare(double aa,double bb)
{
	if(aa-bb>0.0)
		return 1;
	else if(aa-bb<0.0)
		return -1;
	return 0;
}
bool cmpf(double aa,double bb)
{
	if(aa-bb>=0.00000001) return true;
	return false;
}
int maximum2(int x,int y)
{
	x>y?x:y;
}
int maximum3(int x,int y, int z)
{
	return maximum2(maximum2(x,y),z);
}
int findAnswer()
{
	vector<double>slope(a.size());
	for(int i=0;i<a.size();i++)
		slope[i]=-a[i]/(double)b[i];
	sort(slope.begin(),slope.end(),cmpf);

	for(int i=0;i<a.size();i++)
		printf("%lf ",slope[i]);
	printf("\n");

	int start=0,end=0;
	int maxx=1;
	int counter=0;
	for(int i=1;i<a.size();i++)
	{
		if(compare(slope[start],slope[i])==0)
		{
			if(c[start]==c[i] && a[start]==a[i] && b[start]==b[i])
				counter++;
			end=i;
		}
		else
		{
			printf("i = %d\n",i);
			if(maxx<end-start)
				maxx=end-start+1-counter;
			start=i;end=i;
			counter=0;
		}
	}
	if(maxx<end-start)
		maxx=end-start+1;
	return maxx;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		a.erase(a.begin(),a.end());
		b.erase(b.begin(),b.end());
		c.erase(c.begin(),c.end());

		a.reserve(n);
		b.reserve(n);
		c.reserve(n);

		int withx=0,withy=0;

		for(int i=0;i<n;i++)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			if(x==0)
			{
				withx++;continue;
			}
			if(y==0)
			{
				withy++;continue;
			}
			int gc=gcd(gcd(x,y),z);
			a.push_back(x/gc);
			b.push_back(y/gc);
			c.push_back(z/gc);

		}
		printf("this is a test : %d\n",a.size());
		printf("%d\n",maximum3(findAnswer(),withx,withy));
	}

	return 0;
}
