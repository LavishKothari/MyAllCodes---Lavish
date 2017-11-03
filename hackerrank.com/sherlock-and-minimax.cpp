#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int p,q,n;
	cin>>n;
	vector<int>v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	cin>>p>>q;

	sort(v.begin(),v.end());

	vector<int>::iterator it1,it2,it;
	it1=lower_bound(v.begin(),v.end(),p);
	it2=upper_bound(v.begin(),v.end(),q);
	int x=2147483647,y=2147483647;
	int answer,answer1,answer2;
	if(it1!=v.begin())
	{
		int r=(*it1+*(it1-1))/2;
		if(r>=p && r<=q)
		{
			answer1=r;
			x=min(*it1-r,r-*(it1-1));
		}
		else
		{
			answer1=p;
			x=min(*it1-p,p-*(it1-1));
		}
	}
	else
	{
		answer1=p;
		x=*it1-p;
	}

	if(it2!=v.end())
	{
		int r=(*it2+*(it2-1))/2;
		if(r>=p && r<=q)
		{
			answer2=r;
			y=min(*it2-r,r-*(it2-1));
		}
		else
		{
			answer2=q;
			y=min(*it2-q,q-*(it2-1));
		}

	}
	else 
	{
		answer2=q;
		y=q-*(it2-1);
	}
	int ma=0;
	for(it=it1;it+1!=it2;it++)
	{
		int r=(*it+*(it+1))/2;
		int z=min(r-*it,*(it+1)-r);
		if(z>ma)
		{
			answer=r;
			ma=z;
		}
	}
	int maa=max(max(ma,x),y);

	int fa=2147483647;
	//cout<<ma<<" "<<x<<" "<<y<<" "<<maa<<"  "<<endl;
	if(maa==ma && fa>answer)
		fa=answer;
	if(maa==x && fa>answer1)
		fa=answer1;
	if(maa==y && fa>answer2)
		fa=answer2;

	cout<<fa<<endl;
	return 0;
}
