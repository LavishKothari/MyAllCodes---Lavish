#include<iostream>

using namespace std;
int main()
{
	int n;
	cin>>n;
	int*arr=new int[n];
	
	int max=0,count=0;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		if(arr[i]>max)
		{
			count=1;
			max=arr[i];
		}
		else if(arr[i]==max)
			count++;
	}
	cout<<count<<endl;
	return 0;
}
