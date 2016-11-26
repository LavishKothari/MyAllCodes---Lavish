#include <bits/stdc++.h>

using namespace std;


int main()
{
	vector<string>arr;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		string ch;
		cin>>ch;
		arr.push_back(ch);
	}
	for(int i=0;i<n;i++)
	{
		int counter=0;
		for(int j=i-1;j>=0;j--)
			if(arr[j]<arr[i])
				counter++;
		cout<<counter<<endl;
	}
	return 0;
}