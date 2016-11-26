#include <bits/stdc++.h>

using namespace std;
int main()
{
	int s,n,m;
	cin>>s>>n>>m;
	vector<int>key(n);
	vector<int>usb(m);

	for(int i=0;i<n;i++)
		cin>>key[i];
	for(int i=0;i<m;i++)
		cin>>usb[i];
	
	int spend=INT_MIN;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(key[i]<=s && usb[j]<=s && key[i]+usb[j]<=s)
				spend=max(spend,key[i]+usb[j]);
	if(spend==INT_MIN)
		cout<<"-1"<<endl;
	else cout<<spend<<endl;

	return 0;
} 