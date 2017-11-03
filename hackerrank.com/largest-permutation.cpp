#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class number
{
	public:
		int index,value;
		number(){}
		number(int index,int value)
		{
			this->index=index;
			this->value=value;
		}
};
bool cmp(const number&a,const number&b)
{
	return a.value>b.value;
}
bool cc(const number&a,const int x)
{
	return a.value>x;
}
int main()
{
	int n,value,k;
	cin>>n>>k;
	vector<number>a(n),b(n);
	for(int i=0;i<n;i++)
	{
		cin>>value;
		a[i]=number(i,value);
		b[i]=number(i,value);
	}
	sort(b.begin(),b.end(),cmp);
	/*
	   for(int i=0;i<n;i++)
	   cout<<b[i].index<<" ******* "<<b[i].value<<endl;
	 */
	int s=0;
	for(int i=0;i<n;i++)
	{
		if(a[i].value==b[i].value)
			continue;
		int i1=a[i].index;
		int i2=b[i].index;

		number temp=a[i1];
		a[i1]=a[i2];
		a[i2]=temp;

		a[i1].index=i2;
		a[i2].index=i1;

		int v=a[i1].value;
		vector<number>::iterator ite=lower_bound(b.begin(),b.end(),v,cc);
		ite->index=i2;
		b[i].index=i1;


		s++;
		//cout<<"this is the value of s : "<<s<<endl;
		if(s==k)
			break;
	}	
	for(int i=0;i<n;i++)
		cout<<a[i].value<<" ";
	return 0;
}
