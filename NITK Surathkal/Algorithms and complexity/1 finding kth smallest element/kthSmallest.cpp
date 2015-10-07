#include<fstream>
#include<iostream>
#include<vector>
#include<algorithm>
#include"header.h"
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
	//printf("Pseudo median is %d\n",m);
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
int selectUsingSort(vector<int>arr,int r)
{
	int counter=1,i;
	// sorting the elements of the vector.
	std::sort(arr.begin(),arr.begin()+arr.size());
	for(i=0;i<arr.size();i++)
	{
		if(counter==r)
			return arr[i];
		counter++;
		/*
		while(i+1<arr.size() && arr[i]==arr[i+1])
			i++;
		*/
	}
}
int main()
{
	int n,r,i;
	ifstream infile;
	infile.open("test.txt");
	main1(); // generate a new set of test cases.
	/*cout<<"Enter the number of Elements : ";
	cin>>n;
	*/
	infile>>n;
	vector<int>arr(n,0);
	//cout<<"Enter the data : \n";
	for(i=0;i<n;i++)
		infile>>arr[i];
	cout<<"Enter the value of r for finding the rth smallest number in the array (between 1 to "<<n<<"): ";
	cin>>r;
	
	clock_t begin=clock();
	cout<<"the "<<r<<" smallest element is "<<select(arr,r)<<endl;
	clock_t end=clock();
	cout<<"The execution time is "<<(double)(end-begin)/CLOCKS_PER_SEC<<endl;
	
	cout<<endl<<endl;
	
	printf("Result using the naive Sorting algorithm of time complexity O(nlog(n))\n");
	begin=clock();
	cout<<"the "<<r<<" smallest element is "<<selectUsingSort(arr,r)<<endl;
	end=clock();
	cout<<"The execution time is "<<(double)(end-begin)/CLOCKS_PER_SEC<<endl;
	
	return 0;
}
