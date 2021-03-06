#include<fstream>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int pseudoMedian(vector<int>arr)
{
	if(arr.size()==1)
		return arr[0];
	vector<int>median;
	if(arr.size()<5)
	{
		int remaining=arr.size();
		if(remaining>0)
		{
			std::sort(arr.begin(),arr.begin()+remaining);
			if(remaining%2==0)
				median.push_back((arr[remaining/2]+arr[remaining/2-1])/2);
			else
				median.push_back(arr[remaining/2]);
		}
		return median[0];
	}
	int i;
	for(i=0;i<arr.size();i+=5)
	{
		int remaining=arr.size()-i;
		if(remaining<5)
		{
			i+=5;
			break;
		}
		std::sort(arr.begin()+i,arr.begin()+i+5);
		median.push_back(arr[i+2]);
	}
	int remaining=arr.size()%5;
	if(remaining>0)
	{
		std::sort(arr.begin()+i-5,arr.begin()+i-5+remaining);
		if(remaining%2==0)
			median.push_back((arr[i-5+remaining/2]+arr[i-5+remaining/2-1])/2);
		else
			median.push_back(arr[i-5+remaining/2]);
	}
	return pseudoMedian(median);
}
int select(vector<int>arr,int r)
{
	int m=pseudoMedian(arr);
	vector<int> u,v,w;
	for(int i=0;i<arr.size();i++)
	{
		if(arr[i]<m)
			u.push_back(arr[i]);
		else if(arr[i]==m)
			v.push_back(arr[i]);
		else 
			w.push_back(arr[i]);
	}

	if(r<=u.size())
		return select(u,r);
	else if(r<=u.size()+v.size())
		return m;
	return select(w,r-u.size()-v.size());
}
int select1(vector<int>arr,int r)
{
	int m=pseudoMedian(arr);
	vector<int> u,v,w;
	for(int i=0;i<arr.size();i++)
	{
		if(arr[i]>m)
			u.push_back(arr[i]);
		else if(arr[i]==m)
			v.push_back(arr[i]);
		else 
			w.push_back(arr[i]);
	}

	if(r<=u.size())
		return select1(u,r);
	else if(r<=u.size()+v.size())
		return m;
	return select1(w,r-u.size()-v.size());
}
int main()
{
	int n,r,i,t,k;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		vector<int>arr(n,0);
		for(i=0;i<n;i++)
			cin>>arr[i];
		//cout<<select(arr,k)<<endl<<select1(arr,k)<<endl;
		cout<<(select1(arr,k)-select(arr,k))<<endl;
	}
	return 0;
}
