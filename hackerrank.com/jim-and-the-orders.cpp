#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class fan
{
	public:
	int number,s,d,sum;
	bool isDone;
	fan(){}
	fan(int number,int s,int d)
	{
		isDone=false;
		this->number=number;
		this->s=s;
		this->d=d;
		this->sum=s+d;
	}
};
bool cmp(const fan&a,const fan&b)
{
	return a.sum<b.sum;
}
int main()
{
	int n,s,d;
	cin>>n;
	vector<fan>f(n);
	for(int i=0;i<n;i++)
	{
		cin>>s>>d;
		f[i]=fan(i+1,s,d);
	}
	stable_sort(f.begin(),f.end(),cmp);

	for(int i=0;i<n;i++)
		cout<<f[i].number<<" ";
		
	return 0;
}
