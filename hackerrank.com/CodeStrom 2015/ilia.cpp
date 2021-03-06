#include<stdio.h>
#include<vector>
#include<iostream>
#include<algorithm>
long long int minimum(long long int a,long long int b){return a<b?a:b;}
long long int maximum(long long int a,long long int b){return a>b?a:b;}
int main()
{
	long long int n;
	std::vector<long long int>arr;
	std::vector<long long int>other;
	long long int t;
	scanf("%lld",&n);
	for(long long int i=0;i<n;++i)
	{	
		scanf("%lld",&t);
		arr.push_back(t*t);
		other.push_back(t);
	}	
	long long int right=0,acute=0,obtuse=0;
	for(long long int i=0;i<n;++i)
	{
		for(long long int j=i+1;j<n;++j)
		{
			std::vector<long long int>::iterator it2=lower_bound(arr.begin()+j,arr.end(),arr[i]+arr[j]);
			long long int it=it2-arr.begin();
			long long int it1=upper_bound(other.begin()+j,other.end(),other[i]+other[j])-other.begin();
			long long int it3=lower_bound(other.begin()+j,other.end(),other[i]+other[j])-other.begin();
			if((*it2)==arr[i]+arr[j])
				right++;
			acute+=minimum(it,it1)-j-1;
			if((*it2)==arr[i]+arr[j])
				it++;
			// j to it1			(nothing inclusive) 
			// it to size-1 	(both inclusive)
			it1=minimum(it1,it3);
			if(it<arr.size() && it1>=it)
				obtuse+=it1-it;
		}
			
	}
	printf("%lld %lld %lld\n",acute,right,obtuse);
	return 0;
}
