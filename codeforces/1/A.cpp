#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int m,n,a,answer,flag=0;
	cin>>m>>n>>a;
	answer=(m/a)*(n/a);

	if(m%a!=0)
	{
		flag++;
		answer+=n/a;
	}
	if(n%a!=0)
	{
		flag++;
		answer+=m/a;
	}
	if(flag==2)
		answer++;
	cout<<answer<<endl;
	return 0;
}
