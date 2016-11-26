#include <bits/stdc++.h>

using namespace std;


int main()
{
	string str;
	int k;

	cin>>str>>k;

	vector<string>arr(str.size());
	for(int i=0;i<str.size();i++)
	{
		arr[i]=str.substr(i);
	}
	sort(arr.begin(),arr.end());
	cout<<arr[k-1]<<endl;

	return 0;
}