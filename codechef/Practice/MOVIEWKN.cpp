#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
class movie
{
	public :
		int l,r,lr,index;
		movie(int l,int r,int index)
		{
			this->index=index;
			this->r=r;
			this->l=l;
			this->lr=l*r;
		}
};
bool cmpfunc1(const movie&m1,const movie&m2)
{
	return m1.r>m2.r;
}
bool cmpfunc2(const movie&m1,const movie&m2)
{
	return m1.lr>m2.lr;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		vector<movie>m;
		int *l=new int[n];
		int *r=new int[n];
		for(int i=0;i<n;i++)
			scanf("%d",&l[i]);
		for(int i=0;i<n;i++)
			scanf("%d",&r[i]);
		for(int i=0;i<n;i++)
			m.push_back(movie(l[i],r[i],i+1));
		stable_sort(m.begin(),m.end(),cmpfunc1);
		stable_sort(m.begin(),m.end(),cmpfunc2);
		/*
		for(int i=0;i<n;i++)
			printf("%d %d %d\n",m[i].index,m[i].l,m[i].r);
		*/
		printf("%d\n",m[0].index);
		delete []l;
		delete []r;
	}
}
