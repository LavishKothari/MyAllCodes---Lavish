#include <bits/stdc++.h>
using namespace std;


int main()
{
	int n,c,m;
	cin>>n>>c>>m;
	bool answer=true;
	for(int i=0;i<n;i++)
	{
		int temp;cin>>temp;
		if(temp>m*c)
			answer=false;
	}
	if(answer)
		cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}
