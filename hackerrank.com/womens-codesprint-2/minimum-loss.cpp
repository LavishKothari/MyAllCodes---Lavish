#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
class Element
{
	public:
		ll value;int index;
};

bool cmp(const Element&a,const Element&b)
{
	return a.value<b.value;
}
int main()
{
	int n;
	cin>>n;
	vector<Element>elements(n);
	for(int i=0;i<n;i++)
	{
		cin>>elements[i].value;
		elements[i].index=i;
	}
	sort(elements.begin(),elements.end(),cmp);
	ll answer=LLONG_MIN ;
	for(int i=0;i<n-1;i++)
	{
		if(elements[i].index>elements[i+1].index)
			answer=max(elements[i].value - elements[i+1].value,answer);
	}
	cout<<abs(answer)<<endl;
	return 0;
} 
